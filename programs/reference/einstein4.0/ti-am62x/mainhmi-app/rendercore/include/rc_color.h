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
//  Filename    : rc_color.h
//  Description : Color data for script usage
//  Created on  : 31-Jul-2019 by emanoj1@visteon.com
///////////////////////////////////////////////////////////////////////////////
/// @file  rc_color.h
/// \brief Color data for script usage.
#ifndef rc_color_h
#define rc_color_h

namespace rendercore_engine
{
	/// \ingroup Behaviour
	/// @{

	/// color class, conatins all the static colors used by renderer
	/// this is for use within the script when a color to be assigned 
	class Color
	{
	public:
		static const glm::vec4 black;   ///<Solid black.RGBA is(0, 0, 0, 1).
		static const glm::vec4 blue;    ///<Solid blue.RGBA is(0, 0, 1, 1).
		static const glm::vec4 clear;   ///<Completely transparent.RGBA is(0, 0, 0, 0).
		static const glm::vec4 cyan;    ///<Cyan.RGBA is(0, 0, 0, 0).
		static const glm::vec4 gray;    ///<Gray.RGBA is(0.5, 0.5, 0.5, 1).
		static const glm::vec4 green;   ///<Solid green.RGBA is(0, 1, 0, 1).
		static const glm::vec4 grey;    ///<English spelling for gray.RGBA is the same(0.5, 0.5, 0.5, 1).
		static const glm::vec4 magenta; ///<Magenta.RGBA is(1, 0, 1, 1).
		static const glm::vec4 red;     ///<Solid red.RGBA is(1, 0, 0, 1).
		static const glm::vec4 white;   ///<Solid white.RGBA is(1, 1, 1, 1).
		static const glm::vec4 yellow;  ///<Yellow.RGBA is(1, 0.92, 0.016, 1), but the color is nice to look at!
	};

	/// @}
	/// \ingroup Behaviour
	/// @{

	/// Data type for RGBA color
	/// allows conversion from & to a glm::vec4
	/// this is for use within the script when a color to be assigned 
	class gfx3dColor32
	{
	public:
		UCHAR8 r;	///< red 
		UCHAR8 g;	///<green
		UCHAR8 b;	///<blue
		UCHAR8 a;	///<alpha

		/// <summary>
		/// constructor
		/// </summary>
		gfx3dColor32();

		/// <summary>
		/// constructor
		/// <param name="p_r"> red </param>
		/// <param name="p_g">green</param>
		/// <param name="p_b">blue</param>
		/// <param name="p_a">alpha</param>
		/// </summary>
		gfx3dColor32(const UCHAR8 p_r, const UCHAR8 p_g, const UCHAR8 p_b, const UCHAR8 p_a);
		/// <summary>
		/// operator overloading vec4
		/// </summary>
		operator glm::vec4() const;
		/// <summary>
		/// operator overloading for =
		/// <param name="s1">glm::vec4</param>
		/// </summary>
		gfx3dColor32& operator=(const glm::vec4& s1);
	};

	/// @}
}
#endif