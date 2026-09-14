
#include "StdAfx.h"
#include <GL/glew.h>

#include "iris_eng.h"
//#include "iris_pixformat.h"
#include "iris_DrwEng.h"

#include <map>
#include <assert.h>


// -------------- Drawing engine
#include <vector>
#include "mml_gdc_driver_api.h"

//-----------------
// Consts & macros
#define CHECK_GL_ERROR assert(glGetError() == GL_NO_ERROR)

#define cEvalPointNumer    40.0

//----------------
// Types


//----------------- 
// variables
std::vector<tDrwEng_coord> DrwEng_coord;

//-----------------
// Static function definition
//-----------------
static float s16_6_to_float(int in);

template <typename T>
static void DrwEng_AddPoint(IRIS2_PECtx* pCtx, unsigned int numSegments, unsigned char PathSegments, const T* pPathData);

//-----------------
// static functions
//-----------------

template <typename T>
static void DrwEng_AddPoint(IRIS2_PECtx* pCtx, unsigned int numSegments, unsigned char PathSegments, const T* pPathData)
{
  const float* pfCoords = (float*)pPathData;
  tDrwEng_coord tmp_coord;

  for (unsigned int i = 0; i < numSegments; i++)
  {
    //        tmp_coord.cmd = IrisToDrwEng(PathSegments);
    switch (PathSegments)
    {
    case MML_GDC_DE_CLOSE_PATH:
      // Close path -> Equal to MOVE_TO xs, xy
      if (DrwEng_coord.back().cmd == eLine)
      {
        tmp_coord.cmd = eLine;
        tmp_coord.X[0] = DrwEng_coord.back().X[1];
        tmp_coord.Y[0] = DrwEng_coord.back().Y[1];
        tmp_coord.X[1] = DrwEng_coord.front().X[0];
        tmp_coord.Y[1] = DrwEng_coord.front().Y[0];
      }
      else if (DrwEng_coord.back().cmd == eBezierQuad)
      {
        //todo
        tmp_coord.X[0] = DrwEng_coord.back().X[2];
        tmp_coord.Y[0] = DrwEng_coord.back().Y[2];
      }
      else
      {
        // not implemented yet
        assert(0);
      }
      DrwEng_coord.push_back(tmp_coord);
      break;
    case MML_GDC_DE_MOVE_TO_ABS:
      //utDePathMoveTo - Move -> x0, y0 (Start point for next shape)

      tmp_coord.X[0] = pfCoords[0];
      pfCoords++;
      tmp_coord.Y[0] = pfCoords[0];
      pfCoords++;
      tmp_coord.cmd = eInvalidCurve;

      DrwEng_coord.push_back(tmp_coord);
      break;

    case MML_GDC_DE_LINE_TO_ABS:
      //utDePathLineTo - Line -> x0, y0 (End point)

      if ((DrwEng_coord.size() == 1) && (DrwEng_coord[0].cmd == eInvalidCurve))
      {
        DrwEng_coord[0].cmd = eLine;
        DrwEng_coord[0].X[1] = pfCoords[0];
        pfCoords++;
        DrwEng_coord[0].Y[1] = pfCoords[0];
        pfCoords++;
      }
      else
      {
        tmp_coord.cmd = eLine;
        if (DrwEng_coord.back().cmd == eLine)
        {
          tmp_coord.X[0] = DrwEng_coord.back().X[1];
          tmp_coord.Y[0] = DrwEng_coord.back().Y[1];
        }
        else if (DrwEng_coord.back().cmd == eBezierQuad)
        {
          tmp_coord.X[0] = DrwEng_coord.back().X[2];
          tmp_coord.Y[0] = DrwEng_coord.back().Y[2];
        }
        else
        {
          assert(0);
        }
        tmp_coord.X[1] = pfCoords[0];
        pfCoords++;
        tmp_coord.Y[1] = pfCoords[0];
        pfCoords++;
        DrwEng_coord.push_back(tmp_coord);
      }

      break;

    case MML_GDC_DE_QUAD_TO_ABS:
      // utDePathQuadraticBezierTo - Quadratic Bezier-> x0,y0 (Control point), x1,y1 (End point)
      if ((DrwEng_coord.size() == 1) && (DrwEng_coord[0].cmd == eInvalidCurve))
      {

        DrwEng_coord[0].cmd = eBezierQuad;
        DrwEng_coord[0].X[1] = pfCoords[0];
        pfCoords++;
        DrwEng_coord[0].Y[1] = pfCoords[0];
        pfCoords++;
        DrwEng_coord[0].X[2] = pfCoords[0];
        pfCoords++;
        DrwEng_coord[0].Y[2] = pfCoords[0];
        pfCoords++;
      }
      else
      {
        tmp_coord.cmd = eBezierQuad;
        if (DrwEng_coord.back().cmd == eLine)
        {
          tmp_coord.X[0] = DrwEng_coord.back().X[1];
          tmp_coord.Y[0] = DrwEng_coord.back().Y[1];
        }
        else if (DrwEng_coord.back().cmd == eBezierQuad)
        {
          tmp_coord.X[0] = DrwEng_coord.back().X[2];
          tmp_coord.Y[0] = DrwEng_coord.back().Y[2];
        }
        else
        {
          assert(0);
        }

        tmp_coord.X[1] = pfCoords[0];
        pfCoords++;
        tmp_coord.Y[1] = pfCoords[0];
        pfCoords++;
        tmp_coord.X[2] = pfCoords[0];
        pfCoords++;
        tmp_coord.Y[2] = pfCoords[0];
        pfCoords++;
        DrwEng_coord.push_back(tmp_coord);
      }

      break;
    case MML_GDC_DE_MOVE_TO_REL:
    case MML_GDC_DE_LINE_TO_REL:
    case MML_GDC_DE_HLINE_TO_ABS:
    case MML_GDC_DE_HLINE_TO_REL:
    case MML_GDC_DE_VLINE_TO_ABS:
    case MML_GDC_DE_VLINE_TO_REL:

    case MML_GDC_DE_QUAD_TO_REL:
    case MML_GDC_DE_CUBIC_TO_ABS:
    case MML_GDC_DE_CUBIC_TO_REL:
    case MML_GDC_DE_SQUAD_TO_ABS:
    case MML_GDC_DE_SQUAD_TO_REL:
    case MML_GDC_DE_SCUBIC_TO_ABS:
    case MML_GDC_DE_SCUBIC_TO_REL:

      // not implemented yet
      assert(0);
      break;
    }
  }
}

static float s16_6_to_float(int in)
{
  int num_frac, num_int;
  float out;
  num_int = in >> 6;
  num_frac = in & (0x40 - 1);
  out = (float)1.0 * num_int + num_frac / (float)64;
  return out;
}

static tDrawInstruction IrisToDrwEng(unsigned char in)
{
  tDrawInstruction ret = eInvalidCurve;

  if (in == MML_GDC_DE_QUAD_TO_ABS)
  {
    ret = eBezierQuad;
  }
  else if (in == MML_GDC_DE_LINE_TO_ABS)
  {
    ret = eLine;
  }
  else
  {
    assert(0);
  }
  return ret;
}


//-----------------
// public functions
//-----------------

template <typename T>
void DrwEng_AddSinglePoint(tSinglePoint pt, const T* pPathData, unsigned char CurveType)
{
  const float* pfCoords = (float*)pPathData;
  tDrwEng_coord tmp_coord;

  switch (pt)
  {
  case eFirstPoint:
    if (DrwEng_coord.back().cmd == eLine)
    {
      tmp_coord.X[0] = DrwEng_coord.back().X[1];
      tmp_coord.Y[0] = DrwEng_coord.back().Y[1];
    }
    else if (DrwEng_coord.back().cmd == eBezierQuad)
    {
      tmp_coord.X[0] = DrwEng_coord.back().X[2];
      tmp_coord.Y[0] = DrwEng_coord.back().Y[2];
    }

    tmp_coord.cmd = IrisToDrwEng(CurveType);
    DrwEng_coord.push_back(tmp_coord);
    break;
  case eNextPoint:
    DrwEng_coord.back().cmd = IrisToDrwEng(CurveType);
    if (DrwEng_coord.back().cmd == eLine)
    {
      assert(0);
    }

    DrwEng_coord.back().X[1] = pfCoords[0];
    pfCoords++;
    DrwEng_coord.back().Y[1] = pfCoords[0];
    pfCoords++;

    break;
  case eLastPoint:
    assert(CurveType != eBezierQuad);
    DrwEng_coord.back().cmd = IrisToDrwEng(CurveType);
    if (DrwEng_coord.back().cmd == eBezierQuad)
    {
      DrwEng_coord.back().X[2] = pfCoords[0];
      pfCoords++;
      DrwEng_coord.back().Y[2] = pfCoords[0];
      pfCoords++;
    }
    else if (DrwEng_coord.back().cmd == eLine)
    {
      DrwEng_coord.back().X[1] = pfCoords[0];
      pfCoords++;
      DrwEng_coord.back().Y[1] = pfCoords[0];
      pfCoords++;
    }
    else
    {
      assert(0);
    }

    break;
  default:
    assert(0);
    break;
  }

}



void DrwEng_PrepareAddPoint(IRIS2_PECtx* pCtx, unsigned int numSegments, const unsigned char* pPathSegments, const void* pPathData)
{
  if (pPathData == NULL)
  {
    if (pCtx->SinglePoint != eInvalidPoint)
    {
      DrwEng_AddSinglePoint(eFirstPoint, (float*)NULL, *pPathSegments);
    }
    pCtx->SinglePoint = eFirstPoint;
    pCtx->SegmentType = *pPathSegments;
    return;
  }
  else
  {
    if (pPathSegments != NULL)
    {
      assert(numSegments == 1);    // todo
      if (*pPathSegments == MML_GDC_DE_MOVE_TO_ABS)
      {
        pCtx->SegmentType = *pPathSegments;
        pCtx->SinglePoint = eInvalidPoint;
      }
      else
      {
        if (pCtx->SinglePoint == eFirstPoint)
        {
          if (*pPathSegments == MML_GDC_DE_LINE_TO_ABS)
          {
            pCtx->SinglePoint = eLastPoint;
          }
          else
          {
            pCtx->SinglePoint = eNextPoint;
          }

        }
        else if (pCtx->SinglePoint == eInvalidPoint)
        {
          if (*pPathSegments == MML_GDC_DE_LINE_TO_ABS)
          {
            pCtx->SinglePoint = eLastPoint;
          }
          else
          {
            pCtx->SinglePoint = eNextPoint;
          }
        }
        else if (pCtx->SinglePoint == eNextPoint)
        {
          pCtx->SinglePoint = eLastPoint;
        }
        else if (pCtx->SinglePoint == eLastPoint)
        {
          if ((DrwEng_coord.size() != 0) && (DrwEng_coord[0].cmd == eInvalidCurve))
          {
            DrwEng_coord[0].cmd = eInvalidCurve;
          }
          DrwEng_AddSinglePoint(eFirstPoint, (float*)NULL, *pPathSegments);
          if (*pPathSegments == MML_GDC_DE_LINE_TO_ABS)
          {
            pCtx->SinglePoint = eLastPoint;
          }
          else
          {
            pCtx->SinglePoint = eNextPoint;
          }
        }

        pCtx->SegmentType = *pPathSegments;
      }
    }
    else
    {
      if (pCtx->SinglePoint == eFirstPoint)
      {
        pCtx->SinglePoint = eNextPoint;
      }
      else
      {
        pCtx->SinglePoint = eLastPoint;
      }
      assert(numSegments == 2);
    }
  }

  if ((DrwEng_coord.size() != 0) && (DrwEng_coord[0].cmd == eInvalidCurve))
  {
    DrwEng_coord[0].cmd = eInvalidCurve;
  }

  switch (pCtx->epPathDataSize)
  {
  case eMML_GDC_DE_DATA_FORMAT_S16:
  {
    if (pCtx->SinglePoint == eInvalidPoint)
    {
      DrwEng_AddPoint(pCtx, numSegments, pCtx->SegmentType, (short*)pPathData);
    }
    else
    {
      DrwEng_AddSinglePoint(pCtx->SinglePoint, (short*)pPathData, pCtx->SegmentType);
    }
  }
  break;
  case eMML_GDC_DE_DATA_FORMAT_FLOAT:
    if (pCtx->SinglePoint == eInvalidPoint)
    {
      DrwEng_AddPoint(pCtx, numSegments, pCtx->SegmentType, (float*)pPathData);
    }
    else
    {
      DrwEng_AddSinglePoint(pCtx->SinglePoint, (float*)pPathData, pCtx->SegmentType);
    }
    break;
  case eMML_GDC_DE_DATA_FORMAT_S16_6:
  {
    float* flpPathData = new float[numSegments * 2];
    int X, Y;

    for (unsigned int i = 0; i < numSegments * 2; i += 2)
    {
      X = ((int*)pPathData)[i];
      Y = ((int*)pPathData)[i + 1];
      flpPathData[i] = s16_6_to_float(X);
      flpPathData[i + 1] = s16_6_to_float(Y);
    }

    if (pCtx->SinglePoint == eInvalidPoint)
    {
      DrwEng_AddPoint(pCtx, numSegments, pCtx->SegmentType, (float*)flpPathData);
    }
    else
    {
      DrwEng_AddSinglePoint(pCtx->SinglePoint, (float*)flpPathData, pCtx->SegmentType);
    }

    delete flpPathData;
  }
  break;
  case eMML_GDC_DE_DATA_FORMAT_S32:
  case eMML_GDC_DE_DATA_FORMAT_S08:
  default:
    assert(0);
    break;
  }
}



void DrwEng_Draw(IRIS2_PECtx* ctx, float x, float y)
{
  int sz = DrwEng_coord.size(), i = 0, j;

  GLfloat ctrlpoints[4][3] = {
      { -4.0, -4.0, 0.0},
      { 331.0,  234.0, 0.0},
      {  331.0, 2344.0, 0.0},
      {  100.0,  104.0, 0.0}
  };

  MakeActivePECtx(ctx);

  IRIS2_Surface* pSurf = ctx->pStore;

  glDisable(GL_TEXTURE_2D); CHECK_GL_ERROR;
  //---------------------

      // reflect the objects
  glMatrixMode(GL_MODELVIEW); CHECK_GL_ERROR;
  glLoadIdentity(); CHECK_GL_ERROR;
  glScalef(1.f, -1.f, 1.f); CHECK_GL_ERROR;
  glTranslatef(0.f, -1.f * ctx->pStore->height, 0); CHECK_GL_ERROR;

  // set preset color
  glColor3ub(ctx->surfSrcColor.r, ctx->surfSrcColor.g, ctx->surfSrcColor.b); CHECK_GL_ERROR;
  for (i = 0; i < sz; i++)
  {
    switch (DrwEng_coord[i].cmd)
    {
    case eLine:
      glBegin(GL_LINES);//GL_POLYGON);
      glVertex3f(DrwEng_coord[i].X[0] + x, DrwEng_coord[i].Y[0] + y, 0);
      glVertex3f(DrwEng_coord[i].X[1] + x, DrwEng_coord[i].Y[1] + y, 0);
      glEnd(); CHECK_GL_ERROR;

      break;

    case eBezierQuad:

      // set the line width and color
      glLineWidth(1); CHECK_GL_ERROR;
      //glColor3f(0.0, 0.0, 1.0);CHECK_GL_ERROR;

      ctrlpoints[0][0] = DrwEng_coord[i].X[0] + x;
      ctrlpoints[0][1] = DrwEng_coord[i].Y[0] + y;

      ctrlpoints[1][0] = DrwEng_coord[i].X[1] + x;
      ctrlpoints[1][1] = DrwEng_coord[i].Y[1] + y;

      ctrlpoints[2][0] = DrwEng_coord[i].X[2] + x;
      ctrlpoints[2][1] = DrwEng_coord[i].Y[2] + y;

      glMap1f(GL_MAP1_VERTEX_3,    // Target
        0.0, 1.0,                // Min/max t values
        3,                        // stride in t direction
        3,                        // Number of control pts, t direction
        &ctrlpoints[0][0]);        //A pointer to the array of control points.
      CHECK_GL_ERROR;
      glEnable(GL_MAP1_VERTEX_3); CHECK_GL_ERROR;

      // draw Bezier curve
      glBegin(GL_LINE_STRIP);

      for (j = 0; j <= cEvalPointNumer; j++)
      {
        glEvalCoord1f((GLfloat)j / cEvalPointNumer);
      }
      glEnd(); CHECK_GL_ERROR;

      break;

    case eBezierCubic:


    default:
      // not implemented
      assert(0);
      break;
    }
  }

  glFlush();//CHECK_GL_ERROR;
  DrwEng_coord.clear();
}

