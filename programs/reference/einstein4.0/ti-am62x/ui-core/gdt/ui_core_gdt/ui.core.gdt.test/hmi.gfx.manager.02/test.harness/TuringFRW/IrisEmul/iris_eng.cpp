
#include "StdAfx.h"
#include <GL/glew.h>

#include "iris_eng.h"
#include "iris_pixformat.h"

#include <map>
#include <assert.h>

#define CHECK_GL_ERROR assert(glGetError() == GL_NO_ERROR)

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Types



struct TexCache
{
    GLuint fb;
    GLuint tex;
    unsigned w,h;
};

class BufferColorKey
{
public:
    BufferColorKey(void* pBuffer, unsigned color) : mpBuffer(pBuffer), mColor(color) {}

    bool operator== (const BufferColorKey& o) const { return this->mpBuffer == o.mpBuffer && this->mColor == o.mColor; }
    bool operator< (const BufferColorKey& o) const 
    { 
        if(this->mpBuffer == o.mpBuffer)
        {
            return this->mColor < o.mColor;
        }
        else
        {
            return this->mpBuffer < o.mpBuffer;
        }
    };

private:
    void* mpBuffer;
    unsigned mColor;
};


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Consts

static const GLchar* shaderSrc_ColorKeyFrag[] = {
"uniform vec3 colorKey;",
"uniform int  hasColorKey;",
"uniform sampler2D myTexture;",
"uniform float globalAlpha;",
"varying vec2 vTexCoord;",
"void main (void)",
"{",
"   vec4 color = texture2D(myTexture, vTexCoord);",
"   if (hasColorKey == 1)",
"   if (color.rgb == colorKey)",
"       discard;",
"   color.a = color.a * globalAlpha;",
"   gl_FragColor = color;",
"}"
};

static const GLchar* shaderSrc_ColorKeyVert[] = {
"varying vec2 vTexCoord;",
"void main (void)",
"{",
"   vTexCoord = gl_MultiTexCoord0.xy;",
"   gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;",
"}"
};

struct GLState
{
    GLint       viewport[4];
    GLboolean   scicorsTest;
    GLboolean   cullFaces;
    GLboolean   depthTest;
    GLint       frontFace;
};



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Static data

static std::map<void*, IRIS2_Display*> mapDisp;
static std::map<void*, IRIS2_Surface*> mapSurf;
static std::map<void*, IRIS2_Window*>  mapWind;
static std::map<void*, IRIS2_PECtx*>   mapPeCtx;
static std::map<BufferColorKey, PixBufferCache> mapPixBuffers;
static std::map<void*, TexCache>       mapTex;


// Shaders stuff
static GLuint shader_ColorKeyFrag;
static GLuint shader_ColorKeyVert;
static GLuint program_ColorKey;

static GLuint brontesFB;
static GLuint brontesTex;
static GLState brontesState;
static bool   IsBrontesInit = false;
static bool   IsBrontesReleased = false;

static unsigned FramesCnt = 0;  // Shows how many frames been done since the program start


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Implementation

static void DrawWindow(IRIS2_Window* pWindow);
static void ClearUnusedPixBuffers();


static void BitBlt(IRIS2_Surface* pSurf, float x, float y, unsigned int color);
static void DrawBrontes();


void IrisEng_Init(void)
{
    GLint status;
    GLenum err;

    IrisPixFormat_Init();

    err = glewInit();
    assert(err == GLEW_OK);

    shader_ColorKeyFrag = glCreateShader(GL_FRAGMENT_SHADER);CHECK_GL_ERROR;
    glShaderSource(shader_ColorKeyFrag, sizeof(shaderSrc_ColorKeyFrag) / 4, shaderSrc_ColorKeyFrag, 0);CHECK_GL_ERROR;
    glCompileShader(shader_ColorKeyFrag);CHECK_GL_ERROR;
    glGetShaderiv(shader_ColorKeyFrag, GL_COMPILE_STATUS, &status);CHECK_GL_ERROR;
    assert(status != GL_FALSE);

    shader_ColorKeyVert = glCreateShader(GL_VERTEX_SHADER);CHECK_GL_ERROR;
    glShaderSource(shader_ColorKeyVert, sizeof(shaderSrc_ColorKeyVert) / 4, shaderSrc_ColorKeyVert, 0);CHECK_GL_ERROR;
    glCompileShader(shader_ColorKeyVert);CHECK_GL_ERROR;
    glGetShaderiv(shader_ColorKeyVert, GL_COMPILE_STATUS, &status);CHECK_GL_ERROR;
    assert(status != GL_FALSE);

    program_ColorKey = glCreateProgram();CHECK_GL_ERROR;
    glAttachShader(program_ColorKey, shader_ColorKeyFrag);CHECK_GL_ERROR;
    glAttachShader(program_ColorKey, shader_ColorKeyVert);CHECK_GL_ERROR;
    glLinkProgram(program_ColorKey);CHECK_GL_ERROR;
    glGetProgramiv(program_ColorKey, GL_LINK_STATUS, &status);CHECK_GL_ERROR;
    assert(status != GL_FALSE);
}


void IrisEng_DeInit(void)
{
    // TODO:
}


void IrisEng_DispCtrl_Draw(void)
{
    int idx=0;
    IrisEng_ReleaseBrontesCtx();

    // Draw on the screen all displays
    glBindFramebuffer(GL_FRAMEBUFFER, 0);CHECK_GL_ERROR;
    GLenum status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
    assert(status == GL_FRAMEBUFFER_COMPLETE);


    for(std::map<void*, IRIS2_Display*>::iterator cit = mapDisp.begin(); cit != mapDisp.end(); cit++)
    {
        IRIS2_Display* pDisp = cit->second;
        IRIS2_Window* pWindow = cit->second->pWindowList;

        glViewport(0, 0, pDisp->width, pDisp->height);CHECK_GL_ERROR;
        glMatrixMode(GL_PROJECTION);CHECK_GL_ERROR;
        glLoadIdentity();CHECK_GL_ERROR;
        glOrtho(0, pDisp->width, 0, pDisp->height, -1, 1);CHECK_GL_ERROR;

        glMatrixMode(GL_MODELVIEW);CHECK_GL_ERROR;
        glLoadIdentity();CHECK_GL_ERROR;

        if(idx==0)
        {
            glClearColor(0, 0, 0, 0);CHECK_GL_ERROR;
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);CHECK_GL_ERROR;
        }
     
        // Draw all windows in the display
        while(0 != pWindow)
        {
            if((0 != pWindow->pSurface || (pWindow->features & (1 << 9))) && !pWindow->isDisabled)
            {

                DrawWindow(pWindow); 
            }

            pWindow = pWindow->pNext;
        }
        idx++;
    }

    glFinish();CHECK_GL_ERROR;

    FramesCnt++;
    ClearUnusedPixBuffers(); // GC the pix buffers cache
}

void IrisEng_PixEng_Fill(IRIS2_PECtx* ctx, int x, int y, unsigned int w, unsigned int h)
{
    MakeActivePECtx(ctx);

    glShadeModel(GL_FLAT);
    glColor4f(ctx->color.r/255.f, ctx->color.g/255.f, ctx->color.b/255.f, ctx->color.a/255.f); CHECK_GL_ERROR;
    glDisable(GL_DEPTH_TEST);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glScalef(1.f, -1.f, 1.f);
    glTranslatef(0.f, -1.f * ctx->pStore->height, 0);

    glBegin(GL_QUADS);
    glVertex3i(x, y, 0);
    glVertex3i(x + w - 1, y, 0);
    glVertex3i(x + w - 1, y + ctx->pStore->height - 1, 0);
    glVertex3i(x, y + ctx->pStore->height - 1, 0);
    glEnd();CHECK_GL_ERROR;


    glDisable(GL_CLIP_PLANE0);CHECK_GL_ERROR;
    glDisable(GL_CLIP_PLANE1);CHECK_GL_ERROR;
    glDisable(GL_CLIP_PLANE2);CHECK_GL_ERROR;
    glDisable(GL_CLIP_PLANE3);CHECK_GL_ERROR;
}

void IrisEng_PixEng_Blit(IRIS2_PECtx* ctx, float x, float y)
{
    MakeActivePECtx(ctx);

    GLenum srcBlend, destBlend;
    unsigned int color;
    float xOfs, yOfs;

    // Configure blending
    assert(ctx->blend.func_blue_dst == ctx->blend.func_green_dst && ctx->blend.func_blue_dst == ctx->blend.func_red_dst);
    assert(ctx->blend.func_blue_src == ctx->blend.func_green_src && ctx->blend.func_blue_src == ctx->blend.func_red_src);
    assert(ctx->blend.mode_alpha == ctx->blend.mode_blue 
        && ctx->blend.mode_green == ctx->blend.mode_red 
        && ctx->blend.mode_green == ctx->blend.mode_alpha);

    if(     ctx->blend.func_blue_src == 0x302U // MML_GDC_PE_BF_GL_SRC_ALPHA 
        &&  ctx->blend.func_blue_dst == 0x303U // MML_GDC_PE_BF_GL_ONE_MINUS_SRC_ALPHA
        &&  ctx->blend.mode_red == 0x8006U     // MML_GDC_PE_BM_GL_FUNC_ADD
      )
    {
        if(     ctx->blend.func_alpha_src == 0x302U    // MML_GDC_PE_BF_GL_SRC_ALPHA
            &&  ctx->blend.func_alpha_dst == 0x303U    // MML_GDC_PE_BF_GL_ONE_MINUS_SRC_ALPHA
          )
        {
            srcBlend = GL_SRC_ALPHA;
            destBlend = GL_ONE_MINUS_SRC_ALPHA;
        }
        else
        if(     ctx->blend.func_alpha_src == 1         // MML_GDC_PE_BF_GL_ONE
            &&  ctx->blend.func_alpha_dst == 0x303U    // MML_GDC_PE_BF_GL_ONE_MINUS_SRC_ALPHA
          )
        {
            srcBlend = GL_SRC_ALPHA;
            destBlend = GL_ONE_MINUS_SRC_ALPHA;
        }
        else if(    ctx->blend.func_alpha_src == 1    // MML_GDC_PE_BF_GL_ONE
                &&  ctx->blend.func_alpha_dst == 1    // MML_GDC_PE_BF_GL_ONE
                )
        {
            srcBlend = GL_SRC_ALPHA;
            destBlend = GL_ONE_MINUS_SRC_ALPHA;

            // TODO: fix alphas
        }
        else
        {
            assert(0);
        }
    }
    else
    {
        assert(0);
    }

    glEnable(GL_BLEND);CHECK_GL_ERROR;
    glBlendFunc(srcBlend, destBlend);CHECK_GL_ERROR;

    // Assume that all coordintas are in ZERO_PT = TOP_LEFT
//    assert(ctx->attributes.ZERO_POINT == 0); // MML_GDC_PE_ATTR_ZERO_TOP_LEFT

    // 0xRRGGBBAA
    color = ctx->surfSrcColor.a | (ctx->surfSrcColor.b << 8) | (ctx->surfSrcColor.g << 16) | (ctx->surfSrcColor.r << 24);

    GLfloat matrix[16];
    bool isMatUsed = ctx->srcMatrix.isActive;
    matrix[0] = ctx->srcMatrix.mat[0][0];
    matrix[1] = ctx->srcMatrix.mat[0][1];
    matrix[2] = 0.f;
    matrix[3] = ctx->srcMatrix.mat[0][2];
    matrix[4] = ctx->srcMatrix.mat[1][0];
    matrix[5] = ctx->srcMatrix.mat[1][1];
    matrix[6] = 0.f;
    matrix[7] = ctx->srcMatrix.mat[1][2];
    matrix[8] = 0;
    matrix[9] = 0;
    matrix[10] = 1.f;
    matrix[11] = 0;
    matrix[12] = ctx->srcMatrix.mat[2][0];
    matrix[13] = ctx->srcMatrix.mat[2][1];
    matrix[14] = 0;
    matrix[15] = ctx->srcMatrix.mat[2][2];

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    if(ctx->attributes.ZERO_POINT == 0)
    {
        glScalef(1.f, -1.f, 1.f);
        glTranslatef(0.f, -1.f * ctx->pStore->height, 0);
    }

    if(ctx->srcSurfAttr.ALPHAMULTI)
    {
        glPixelTransferf(GL_ALPHA_SCALE, ctx->surfSrcColor.a / 255.f);CHECK_GL_ERROR;
    }

    if(isMatUsed)
    {
        glMultMatrixf(matrix);
    }
    BitBlt(ctx->pSrc, 0, 0, color);

    // Restore old GL state
    glDisable(GL_CLIP_PLANE0);CHECK_GL_ERROR;
    glDisable(GL_CLIP_PLANE1);CHECK_GL_ERROR;
    glDisable(GL_CLIP_PLANE2);CHECK_GL_ERROR;
    glDisable(GL_CLIP_PLANE3);CHECK_GL_ERROR;
    glPixelTransferf(GL_ALPHA_SCALE, 1.0);CHECK_GL_ERROR;
    glDisable(GL_BLEND);CHECK_GL_ERROR;
    glDisable(GL_TEXTURE_2D);CHECK_GL_ERROR;
}

IRIS2_Display*  IrisEng_CreateDsp(void* Key)
{
    IRIS2_Display* result;
    std::map<void*, IRIS2_Display*>::iterator cit = mapDisp.find(Key);

    if(cit == mapDisp.end())
    {
        result = new IRIS2_Display();
        mapDisp[Key] = result;
    }
    else
    {
        result = cit->second;
    }

    return result;
}

void IrisEng_DestroyDsp(void* Key)
{
    std::map<void*, IRIS2_Display*>::iterator cit = mapDisp.find(Key);
    if(cit != mapDisp.end())
    {
        delete cit->second;
        mapDisp.erase(cit);
    }
}

IRIS2_Window*  IrisEng_CreateWnd(void* Key)
{
    IRIS2_Window* result;
    std::map<void*, IRIS2_Window*>::iterator cit = mapWind.find(Key);

    if(cit == mapWind.end())
    {
        result = new IRIS2_Window();
        mapWind[Key] = result;
    }
    else
    {
        result = cit->second;
    }

    return result;
}

void  IrisEng_DestroyWnd(void* Key)
{
    std::map<void*, IRIS2_Window*>::iterator cit = mapWind.find(Key);
    if(cit != mapWind.end())
    {
        delete cit->second;
        mapWind.erase(cit);
    }
}
    
IRIS2_PECtx*    IrisEng_CreatePeCtx(void* Key)
{
    IRIS2_PECtx* result;
    std::map<void*, IRIS2_PECtx*>::iterator cit = mapPeCtx.find(Key);

    if(cit == mapPeCtx.end())
    {
        result = new IRIS2_PECtx();
        mapPeCtx[Key] = result;
    }
    else
    {
        result = cit->second;
    }

    return result;
}

void   IrisEng_DestroyPeCtx(void* Key)
{
    std::map<void*, IRIS2_PECtx*>::iterator cit = mapPeCtx.find(Key);
    if(cit != mapPeCtx.end())
    {
        delete cit->second;
        mapPeCtx.erase(cit);
    }
}

IRIS2_Surface*  IrisEng_CreateSurf(void* Key)
{
    IRIS2_Surface* result;
    std::map<void*, IRIS2_Surface*>::iterator cit = mapSurf.find(Key);

    if(cit == mapSurf.end())
    {
        result = new IRIS2_Surface();
        mapSurf[Key] = result;
    }
    else
    {
        result = cit->second;
    }

    return result;
}

void IrisEng_DestroySurf(void* Key)
{
    std::map<void*, IRIS2_Surface*>::iterator cit = mapSurf.find(Key);
    if(cit != mapSurf.end())
    {
        delete cit->second;
        mapSurf.erase(cit);
    }
}

void IrisEng_SetBrontesCtx()
{
    GLenum status;

    bool beenInitialized = IsBrontesInit;
    if(!IsBrontesInit) 
    {
        glEnable(GL_TEXTURE_2D);
        glGenTextures(1, &brontesTex);CHECK_GL_ERROR;
        glBindTexture(GL_TEXTURE_2D, brontesTex);CHECK_GL_ERROR;
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);CHECK_GL_ERROR;
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);CHECK_GL_ERROR;
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);CHECK_GL_ERROR;
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);CHECK_GL_ERROR;
        //NULL means reserve texture memory, but texels are undefined
        glPixelStorei(GL_PACK_ALIGNMENT, 1);CHECK_GL_ERROR;
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);CHECK_GL_ERROR;
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 800, 480, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);CHECK_GL_ERROR;
        glGenFramebuffers(1, &brontesFB);CHECK_GL_ERROR;

        glBindFramebuffer(GL_FRAMEBUFFER, brontesFB);CHECK_GL_ERROR;
        glFramebufferTexture2D(GL_DRAW_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, brontesTex, 0);CHECK_GL_ERROR;
        status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
        assert(status == GL_FRAMEBUFFER_COMPLETE);

        IsBrontesInit = true;
    }

    glBindFramebuffer(GL_FRAMEBUFFER, brontesFB);CHECK_GL_ERROR;
    status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
    assert(status == GL_FRAMEBUFFER_COMPLETE);

    if(beenInitialized)
    {
        glViewport(brontesState.viewport[0], brontesState.viewport[1], brontesState.viewport[2], brontesState.viewport[3]);CHECK_GL_ERROR;

        glFrontFace(brontesState.frontFace);

        glMatrixMode(GL_PROJECTION);CHECK_GL_ERROR;
        glPopMatrix();CHECK_GL_ERROR;

        glMatrixMode(GL_MODELVIEW);CHECK_GL_ERROR;
        glPopMatrix();CHECK_GL_ERROR;

        if(brontesState.scicorsTest) glEnable(GL_SCISSOR_TEST); else glDisable(GL_SCISSOR_TEST);CHECK_GL_ERROR;
        if(brontesState.depthTest) glEnable(GL_DEPTH_TEST); else glDisable(GL_DEPTH_TEST);CHECK_GL_ERROR;
        if(brontesState.cullFaces) glEnable(GL_CULL_FACE); else glDisable(GL_CULL_FACE);CHECK_GL_ERROR;

        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_NORMAL_ARRAY);

        glDisable(GL_BLEND);
        glDisable(GL_TEXTURE_2D);
        glShadeModel(GL_SMOOTH);
    }

    IsBrontesReleased = false;
}

void IrisEng_ReleaseBrontesCtx()
{
    if(IsBrontesInit && !IsBrontesReleased)
    {
        glGetIntegerv(GL_VIEWPORT, brontesState.viewport);CHECK_GL_ERROR;
        glGetBooleanv(GL_SCISSOR_TEST, &brontesState.scicorsTest);CHECK_GL_ERROR;
        glGetBooleanv(GL_DEPTH_TEST, &brontesState.depthTest);CHECK_GL_ERROR;
        glGetBooleanv(GL_CULL_FACE, &brontesState.cullFaces);CHECK_GL_ERROR;

        glGetIntegerv(GL_FRONT_FACE, &brontesState.frontFace);CHECK_GL_ERROR;

        glMatrixMode(GL_MODELVIEW);CHECK_GL_ERROR;
        glPushMatrix();CHECK_GL_ERROR;

        glMatrixMode(GL_PROJECTION);CHECK_GL_ERROR;
        glPushMatrix();CHECK_GL_ERROR;

        IsBrontesReleased = true;

        glDisableClientState(GL_VERTEX_ARRAY);CHECK_GL_ERROR;
        glDisableClientState(GL_NORMAL_ARRAY);CHECK_GL_ERROR;
        glDisable(GL_SCISSOR_TEST);CHECK_GL_ERROR;
        glDisable(GL_DEPTH_TEST);CHECK_GL_ERROR;
        glDisable(GL_CULL_FACE);CHECK_GL_ERROR;

        glDisable(GL_LIGHTING);
    }
}



static void DrawWindow(IRIS2_Window* pWin)
{
    unsigned char isBlendEnabled;
    GLenum srcBlend, destBlend;
    GLdouble planeLeft[4] = {1.0, 0, 0, 0};
    GLdouble planeRight[4] = {-1.0, 0, 0, 0};
    GLdouble planeTop[4] = {0, -1.0, 0, 0};
    GLdouble planeBottom[4] = {0, 1.0, 0, 0};

    assert(0 != pWin);

    if(pWin->isDisabled)
    {
        return;
    }

    isBlendEnabled = 0;
    srcBlend = GL_ONE;
    destBlend = GL_ZERO;
    
    glDisable(GL_DEPTH_TEST);CHECK_GL_ERROR;

    // apply blending
    if(pWin->blendMode == 0) //MML_GDC_DISP_BLEND_NONE
    {
    } 
    
    if(pWin->blendMode & 3) // MML_GDC_DISP_BLEND_TRANSPARENCY
    {
        GLint varLoc;
        unsigned char r = (pWin->color >> 24 ) & 0xff;
        unsigned char g = (pWin->color >> 16 ) & 0xff;
        unsigned char b = (pWin->color >> 8) & 0xff;

        // enable colorKey shader
        glUseProgram(program_ColorKey);CHECK_GL_ERROR;

        varLoc = glGetUniformLocation(program_ColorKey, "colorKey");CHECK_GL_ERROR;
        glUniform3f(varLoc, r / 255.0f, g / 255.0f, b / 255.0f);CHECK_GL_ERROR;

        varLoc = glGetUniformLocation(program_ColorKey, "myTexture");CHECK_GL_ERROR;
        glUniform1i(varLoc, 0);CHECK_GL_ERROR;

        if(pWin->blendMode & 1)
        {
            varLoc = glGetUniformLocation(program_ColorKey, "hasColorKey");CHECK_GL_ERROR;
            glUniform1i(varLoc, 1);CHECK_GL_ERROR;
        }
        else
        {
            varLoc = glGetUniformLocation(program_ColorKey, "hasColorKey");CHECK_GL_ERROR;
            glUniform1i(varLoc, 0);CHECK_GL_ERROR;
        }

        if(pWin->blendMode & 2)
        {
            unsigned char gALpha = (pWin->color ) & 0xff;
            varLoc = glGetUniformLocation(program_ColorKey, "globalAlpha");CHECK_GL_ERROR;
            glUniform1f(varLoc, gALpha / 255.f);CHECK_GL_ERROR;
        }
        else
        {
            varLoc = glGetUniformLocation(program_ColorKey, "globalAlpha");CHECK_GL_ERROR;
            glUniform1f(varLoc, 1.f);CHECK_GL_ERROR;
        }
        isBlendEnabled = 1;
        srcBlend = GL_SRC_ALPHA;
        destBlend = GL_ONE_MINUS_SRC_ALPHA;
    }
   

    if(pWin->blendMode & 4) // MML_GDC_DISP_BLEND_SOURCE_ALPHA
    {
        isBlendEnabled = 1;
        destBlend = GL_ONE_MINUS_SRC_ALPHA;
    }

    if(pWin->blendMode & 8) // MML_GDC_DISP_BLEND_EXTERN_ALPHA
    {
        assert(0);
    }

    if(pWin->blendMode & 16) // MML_GDC_DISP_BLEND_SOURCE_MULTIPLY_ALPHA
    {
        isBlendEnabled = 1;
        srcBlend = GL_SRC_ALPHA;
    }

    if(isBlendEnabled)
    {
        glEnable(GL_BLEND);CHECK_GL_ERROR;
        glBlendFunc(srcBlend, destBlend);CHECK_GL_ERROR;
    }
    else
    {
        glDisable(GL_BLEND);CHECK_GL_ERROR;
    }




    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glScalef(1.f, -1.f, 1.f);
    glTranslatef(0.f, -1.f * pWin->pDisplay->height, 0);
    glTranslatef(pWin->x, pWin->y, 0);
 

    if(pWin->features & (1 << 9))
    {
        DrawBrontes();
    }
    else
    {
        BitBlt(pWin->pSurface, 0.f, 0.f, pWin->color);
    }

    // Restore old GL state
    glPixelTransferf(GL_ALPHA_SCALE, 1.0);CHECK_GL_ERROR;
    glDisable(GL_BLEND);CHECK_GL_ERROR;

    glUseProgram(0);CHECK_GL_ERROR;
}

static void ClearUnusedPixBuffers()
{
    bool restart;

    do
    {
        restart = false;
        for(std::map<BufferColorKey, PixBufferCache>::iterator cit = mapPixBuffers.begin(); cit != mapPixBuffers.end(); cit++)
        {
            if(cit->second.isBufferDynamic && (FramesCnt - cit->second.timeStampLastUsed) > 500)
            {
                delete cit->second.pBuffer;
                mapPixBuffers.erase(cit);
                restart = true;
                break;
            }
        }
    }
    while(restart);
}

void MakeActivePECtx(IRIS2_PECtx* ctx)
{
    GLuint fb;
    GLuint tex;
    GLenum status;

    IrisEng_ReleaseBrontesCtx();

    std::map<void*, TexCache>::iterator cit = mapTex.find(static_cast<void*>(ctx->pStore->pBuffer));

    if(cit != mapTex.end()) // if texture exist, check the sizes
    {
        if(cit->second.w != ctx->pStore->width || cit->second.h != ctx->pStore->height)
        {
            glBindFramebuffer(GL_FRAMEBUFFER, 0);CHECK_GL_ERROR;
            glDeleteFramebuffers(1, &(cit->second.fb));CHECK_GL_ERROR;
            glDeleteTextures(1, &(cit->second.tex));CHECK_GL_ERROR;
            cit = mapTex.end();
        }
    }

    if(cit == mapTex.end()) // texture still does not exist
    {
        glEnable(GL_TEXTURE_2D);
        glGenTextures(1, &tex);CHECK_GL_ERROR;
        glBindTexture(GL_TEXTURE_2D, tex);CHECK_GL_ERROR;
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);CHECK_GL_ERROR;
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);CHECK_GL_ERROR;
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);CHECK_GL_ERROR;
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);CHECK_GL_ERROR;
        //NULL means reserve texture memory, but texels are undefined
        glPixelStorei(GL_PACK_ALIGNMENT, 1);CHECK_GL_ERROR;
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);CHECK_GL_ERROR;
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, ctx->pStore->width, ctx->pStore->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);CHECK_GL_ERROR;
        glGenFramebuffers(1, &fb);CHECK_GL_ERROR;
        glBindFramebuffer(GL_FRAMEBUFFER, fb);CHECK_GL_ERROR;
        glFramebufferTexture2D(GL_DRAW_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, tex, 0);CHECK_GL_ERROR;
        status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
        assert(status == GL_FRAMEBUFFER_COMPLETE);

        mapTex[static_cast<void*>(ctx->pStore->pBuffer)].fb = fb;
        mapTex[static_cast<void*>(ctx->pStore->pBuffer)].tex = tex;
        mapTex[static_cast<void*>(ctx->pStore->pBuffer)].w = ctx->pStore->width;
        mapTex[static_cast<void*>(ctx->pStore->pBuffer)].h = ctx->pStore->height;

        glClearColor(0, 0, 0, 0);CHECK_GL_ERROR;
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);CHECK_GL_ERROR;
    }
    else
    {
        fb =    cit->second.fb;
        tex =   cit->second.tex;
    }

    glBindFramebuffer(GL_FRAMEBUFFER, fb);CHECK_GL_ERROR;
    status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
    assert(status == GL_FRAMEBUFFER_COMPLETE);

    glViewport(0, 0, ctx->pStore->width, ctx->pStore->height);CHECK_GL_ERROR;
    glMatrixMode(GL_PROJECTION);CHECK_GL_ERROR;
    glLoadIdentity();CHECK_GL_ERROR;
    glOrtho(0, ctx->pStore->width, 0, ctx->pStore->height, -1, 1);CHECK_GL_ERROR;

    if(ctx->storeRectArea.isAcive)
    {
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        GLdouble planeLeft[4] = {1.0, 0, 0, 0};
        GLdouble planeRight[4] = {-1.0, 0, 0, 0};
        GLdouble planeTop[4] = {0, -1.0, 0, 0};
        GLdouble planeBottom[4] = {0, 1.0, 0, 0};

        planeLeft[3] = (double)(-1. * ctx->storeRectArea.x);
        glEnable(GL_CLIP_PLANE0);CHECK_GL_ERROR;
        glClipPlane(GL_CLIP_PLANE0, planeLeft);CHECK_GL_ERROR;

        planeRight[3] = ((float)ctx->storeRectArea.x + ctx->storeRectArea.w);
        glEnable(GL_CLIP_PLANE1);CHECK_GL_ERROR;
        glClipPlane(GL_CLIP_PLANE1, planeRight);CHECK_GL_ERROR;

        planeTop[3] = ((float)ctx->pStore->height - ctx->storeRectArea.y);
        glEnable(GL_CLIP_PLANE2);CHECK_GL_ERROR;
        glClipPlane(GL_CLIP_PLANE2, planeTop);CHECK_GL_ERROR;

        planeBottom[3] = -1. * ((float)ctx->pStore->height - ((float)ctx->storeRectArea.y + ctx->storeRectArea.h - 1) );
        glEnable(GL_CLIP_PLANE3);CHECK_GL_ERROR;
        glClipPlane(GL_CLIP_PLANE3, planeBottom);CHECK_GL_ERROR;
    }
}


static void BitBlt(IRIS2_Surface* pSurf, float x, float y, unsigned int color)
{
    std::map<void*, TexCache>::iterator cit = mapTex.find(static_cast<void*>(pSurf->pBuffer));
    if(cit != mapTex.end()) // The surface is a texture
    {
        // Blit texture

        glDisable(GL_DEPTH_TEST);CHECK_GL_ERROR;
        glActiveTexture(GL_TEXTURE0);CHECK_GL_ERROR;
        glEnable(GL_TEXTURE_2D);CHECK_GL_ERROR;
        glBindTexture(GL_TEXTURE_2D, cit->second.tex); CHECK_GL_ERROR;
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);CHECK_GL_ERROR;


        glBegin(GL_QUADS);
        {
            glTexCoord2f(0.0, 1.0); 
            glVertex3i(x, y, 0);

            glTexCoord2f(1.0, 1.0); 
            glVertex3i(x + pSurf->width - 1, y, 0);

            glTexCoord2f(1.0, 0.0); 
            glVertex3i(x + pSurf->width - 1, y + pSurf->height - 1, 0);

            glTexCoord2f(0, 0.0); 
            glVertex3i(x, y + pSurf->height - 1, 0);
        }
        glEnd();CHECK_GL_ERROR;
        glFlush();CHECK_GL_ERROR;
        glDisable(GL_TEXTURE_2D);CHECK_GL_ERROR;
    }
    else // The surface is usual buffer
    {
        BufferColorKey key(pSurf->pBuffer, color);
        std::map<BufferColorKey, PixBufferCache>::iterator pixCit = mapPixBuffers.find(key);
        PixBufferCache cache;

        if(pixCit != mapPixBuffers.end()) // Buffer already in cache
        {
            cache = pixCit->second;
            pixCit->second.timeStampLastUsed = FramesCnt;
            //if((cache.color != color))//&&(cache.isBufferDynamic==true))
            //{
            //    IrisPixFormat_Convert(pSurf, color, cache.oglFormat, cache.oglType, cache.pBuffer, cache.isBufferDynamic, true);
            //}
        }
        else
        {
            IrisPixFormat_Convert(pSurf, color, &cache, false);
            cache.timeStampLastUsed = FramesCnt;
            key = BufferColorKey (pSurf->pBuffer, color);
            mapPixBuffers[key] = cache;
            cache.color = color;
        }
        
        // Special processing for ALPHA 8
        if(pSurf->bitperpixel == 8 && pSurf->colorbits == 0x00000008 && pSurf->colorshift == 0x00000000)
        { // MML_GDC_SURF_FORMAT_A8
            glPixelTransferf(GL_RED_BIAS,   ((color >> 24) & 0xff) / 255.0f);
            glPixelTransferf(GL_GREEN_BIAS, ((color >> 16) & 0xff) / 255.0f);
            glPixelTransferf(GL_BLUE_BIAS,  ((color >> 8) & 0xff) / 255.0f);
        }

        if(cache.pBuffer != 0)
        {
            GLuint texture;

            glDisable(GL_DEPTH_TEST);
            glActiveTexture(GL_TEXTURE0);CHECK_GL_ERROR;
            glEnable(GL_TEXTURE_2D);CHECK_GL_ERROR;

            glGenTextures(1, &texture); CHECK_GL_ERROR;
            glBindTexture(GL_TEXTURE_2D, texture); CHECK_GL_ERROR;

            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);CHECK_GL_ERROR;
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);CHECK_GL_ERROR;
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);CHECK_GL_ERROR;
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);CHECK_GL_ERROR;

            glTexImage2D(
                GL_TEXTURE_2D,
                0,
                GL_RGBA, 
                pSurf->width,
                pSurf->height,  
                0,       
                cache.oglFormat,
                cache.oglType,  
                cache.pBuffer
                );CHECK_GL_ERROR;

            glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);CHECK_GL_ERROR;

            glPixelTransferf(GL_RED_BIAS, 0);
            glPixelTransferf(GL_GREEN_BIAS, 0);
            glPixelTransferf(GL_BLUE_BIAS, 0);

            glBegin(GL_QUADS);
            {
                glTexCoord2f(0.0, 0.0); 
                glVertex3i(x, y, 0);
            
                glTexCoord2f(1.0, 0.0); 
                glVertex3i(x + pSurf->width, y, 0);
            
                glTexCoord2f(1.0, 1.0); 
                glVertex3i(x + pSurf->width, y + pSurf->height , 0);
            
                glTexCoord2f(0, 1.0); 
                glVertex3i(x, y + pSurf->height, 0);
            }
            glEnd();CHECK_GL_ERROR;

            glFlush();

            glDisable(GL_TEXTURE_2D);
            glDeleteTextures(1, &texture);
            glFlush();
        }
    }
}



static void DrawBrontes()
{
    glDisable(GL_DEPTH_TEST);CHECK_GL_ERROR;
    glActiveTexture(GL_TEXTURE0);CHECK_GL_ERROR;
    glEnable(GL_TEXTURE_2D);CHECK_GL_ERROR;
    glBindTexture(GL_TEXTURE_2D, brontesTex); CHECK_GL_ERROR;
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);CHECK_GL_ERROR;

    glBegin(GL_QUADS);
    {
        glTexCoord2f(0.0, 1.0); 
        glVertex3i(0, 0, 0);
            
        glTexCoord2f(1.0, 1.0); 
        glVertex3i(0 + 800 - 1, 0, 0);
            
        glTexCoord2f(1.0, 0.0); 
        glVertex3i(0 + 800 - 1, 0 + 480 - 1, 0);
            
        glTexCoord2f(0, 0.0); 
        glVertex3i(0, 0 + 480 - 1, 0);
    }
    glEnd();CHECK_GL_ERROR;
    glFlush();CHECK_GL_ERROR;
    glDisable(GL_TEXTURE_2D);CHECK_GL_ERROR;
}

