///////////////////////////////////////////////////////////////////////////////
//
//                     CONFIDENTIAL VISTEON CORPORATION
//
// This is an unpublished work of authorship, which contains trade secrets,
// created in 2018. Visteon Corporation owns all rights to this work and
// intends to maintain it in confidence to preserve its trade secret status.
// Visteon Corporation reserves the right, under the copyright laws of the
// United States or those of any other country that may have jurisdiction,
// to protect this work as an unpublished work, in the event of an
// inadvertent or deliberate unauthorized publication. Visteon Corporation
// also reserves its rights under all copyright laws to protect this work as
// a published work, when appropriate. Those having access to this work may
// not copy it, use it, modify it or disclose the information contained in
// it without the written authorization of Visteon Corporation.
//
//  Filename    : rdf_scg_unity.h
//  Description : types required for binding with unity scripts.
//                TODO : need to combine with rendercore types...
//  Created on  : 02-Jan-2019 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file rdf_scg_unity.h
///	\brief	  types required for binding with unity scripts.
#ifndef rdf_scg_unity_h
#define rdf_scg_unity_h

#if 0
/// mesh renderer class, has material and camera information
class MeshRenderer
{
public:
    rendercore_engine::gfx3d_scg_material * material;	///< contains the material used by the mesh
    rendercore_engine::gfx3d_scg_camera   * camera;		///< camera orientation of the mesh
    GLuint renderingLayerMask;
};

/// game object class, contains mesh renderer object, and camera
class GameObject
{
private:
    MeshRenderer * mr;							///< meshrenderer object
    rendercore_engine::gfx3d_scg_camera camera;	///< camera object
public:
    Transform * transform;						///< transform object
   
	///constructor
	GameObject()
    {
        transform = new Transform(this);
    }

	/// returns the mesh renderer object
	MeshRenderer * GetCompMeshRenderer(void)
    {
        return(mr);
    }

	/// returns the camera object
    rendercore_engine::gfx3d_scg_camera * GetCompCamera(void)
    {
        return(&camera);
    }
};

class Transform
{
public:
    glm::vec3 localPosition;			///< local position
	glm::vec3 localEulerAngles;			///< euler position
	glm::vec3 localScale;				///< local scale
	Transform * parent;					///< local quat angles
	int childCount;						///< transform parent
	std::vector<Transform*> children;	///< chilren
	GameObject * gameObject;			///< game object representing the transform 
		
	/// constructor
	Transform(GameObject * p_game)
    {
        gameObject = p_game;
    }
};
/// Unity dummy binding TODO : need to map it with rendercore SCG later..
class Material
{
public:
	/// return the color in vec4 format
	/// \param string name
    glm::vec4 GetColor(std::string p_uname)
    {
        glm::vec4 color(0.0f);
        return(color);
    }
	/// returns int
	/// \param string name
    int GetInt(std::string p_uname)
    {
        int fl_retVal = 0;
        return(fl_retVal);
    }
	/// returns float
	/// \param string name
	float GetFloat(std::string p_uname)
    {
        float fl_retVal = 0.0f;
        return(fl_retVal);
    }
	/// sets vec4 color
	/// \param string name
	/// \param color
	void SetColor(std::string p_uname, glm::vec4 p_color)
    {
    }
	/// sets int
	/// \param string name
	/// \param val
	void SetInt(std::string p_uname, int p_value)
    {
    }
	/// sets float
	/// \param string name
	/// \param val
	void SetFloat(std::string p_uname, float p_value)
    {
    }
};

enum CameraClearFlags
{
    Skybox,     ///<  Clear with the skybox.
    SolidColor, ///<	Clear with a background color.
    Depth,      ///<	Clear only the depth buffer.
    Nothing     ///<	Don't clear anything.
};

/// opengl camera class
class Camera
{
public:
    bool allowMSAA;							///< allow multi-sample anti aliasing
    bool orthographic;						///< enable orthographic camera
    GLuint cullingMask;						///< sets the culling mode mask
    int targetDisplay;						///< target display object id
    float fieldOfView;						///< fov
    float nearClipPlane;					///< near clip viewing volume plane 
    float farClipPlane;						///< far clip viewing volume plane 
    float aspect;							///< aspect ratio
    glm::mat4 worldToCameraMatrix;			///< world to camera matrix 
    glm::mat4 projectionMatrix;				///< projection matrix
    glm::mat4 cameraToWorldMatrix;			///<  camera to world matrix
    glm::vec4 backgroundColor;				///< background color, this will be used to paint/clear the buffer
    CameraClearFlags clearFlags;			///< clear flags, these will be used to clear opengl buffer
};

/// meshrenderer, having material and camera object
class MeshRenderer
{
public:
    Material * material;
    Camera * camera;
    GLuint renderingLayerMask;
};

class GameObject;

/// transform class 
class Transform
{
public:
    glm::vec3 localPosition;				///< local position
	glm::vec3 localEulerAngles;				///< euler position
	glm::vec3 localScale;					///< local scale
	Transform * parent;						///< local quat angles
	int childCount;							///< transform parent
	Transform ** children;					///< chilren
	GameObject * gameObject;				///< game object representing the transform 
    Transform(GameObject * p_game)
    {
        gameObject = p_game;
    }
};


/// gameobject class 
class GameObject
{
private:
    MeshRenderer mr;
    Camera camera;
public:
    Transform * transform;	///< transform for gameobject
	/// constructor
    GameObject()
    {
        transform = new Transform(this);
    }

	/// return the comp mesh renderer
    MeshRenderer * GetCompMeshRenderer(void)
    {
        return(&mr);
    }

	/// returns the comp mesh camera
    Camera * GetCompCamera(void)
    {
        return(&camera);
    }
};
#endif
#endif


