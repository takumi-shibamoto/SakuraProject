/*****************************************************************//*!
\file   Shader.h
\brief  Class to compile and build shaders

\note
	This class is highly based on the Shader class tutorial from LearnOpenGL,
	authored by Joey de Vries.
	License: CC BY-NC 4.0
	Reference: https://learnopengl.com/Getting-started/Shaders
*//******************************************************************/

#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

namespace sakura 
{
	class Shader
	{
	public:
		/*****************************************************************//*!
		\brief
			Constructor. Create a shader program.
		\param vertexPath
			Path to the vertex shader file.
		\param fragmentPath
			Path to the fragment shader file.
		*//******************************************************************/
		Shader(const char* vertexPath, const char* fragmentPath);

		/*****************************************************************//*!
		\brief
			Destructor. Delete the program.
		*//******************************************************************/
		~Shader();

		/*****************************************************************//*!
		\brief
			Activate the shader program.
		*//******************************************************************/
		void Use();

		/*****************************************************************//*!
		\brief
			Set a boolean value to a boolean uniform variable.
		\param name
			Name of the uniform variable.
		\param value
			Boolean value to set to the uniform variable
		*//******************************************************************/
		void SetBool(const std::string& name, bool value) const;

		/*****************************************************************//*!
		\brief
			Set a integer value to a integer uniform variable.
		\param name
			Name of the uniform variable.
		\param value
			Integer value to set to the uniform variable
		*//******************************************************************/
		void SetInt(const std::string& name, int value) const;

		/*****************************************************************//*!
		\brief
			Set a float value to a float uniform variable.
		\param name
			Name of the uniform variable.
		\param value
			Float value to set to the uniform variable
		*//******************************************************************/
		void SetFloat(const std::string& name, float value) const;

	private:
		//Shader Program ID
		unsigned int ID;
	};
}