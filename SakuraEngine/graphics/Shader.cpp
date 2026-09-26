/*****************************************************************//*!
\file   Shader.cpp
\brief  Class to compile and build shaders

\note
	This class is highly based on the Shader class tutorial from LearnOpenGL,
	authored by Joey de Vries.
	License: CC BY-NC 4.0
	Reference: https://learnopengl.com/Getting-started/Shaders
*//******************************************************************/

#include "Shader.h"

#include <glad/glad.h>

namespace sakura
{
	Shader::Shader(const char* vertexPath, const char* fragmentPath)
		: ID{}
	{
		//Retrieve the shader source codes from the file with the given paths.
		std::string vertexCode{};
		std::string fragmentCode{};
		std::ifstream vShaderFile;
		std::ifstream fShaderFile;

		//Ensure ifstream can throw exceptions
		vShaderFile.exceptions(std::fstream::failbit | std::fstream::badbit);
		fShaderFile.exceptions(std::fstream::failbit | std::fstream::badbit);
		try
		{
			//Open the shader source file.
			vShaderFile.open(vertexPath);
			fShaderFile.open(fragmentPath);
			std::stringstream vShaderStream, fShaderStream;

			//Read file's buffer contents into streams
			vShaderStream << vShaderFile.rdbuf();
			fShaderStream << fShaderFile.rdbuf();

			//Close the shader file.
			vShaderFile.close();
			fShaderFile.close();

			//Convert streams into strings.
			vertexCode = vShaderStream.str();
			fragmentCode = fShaderStream.str();
		}
		catch(std::ifstream::failure e)
		{
			std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ" << std::endl;
		}

		//Convert the source code string to C string
		const char* vShaderCode{ vertexCode.c_str() };
		const char* fShaderCode{ fragmentCode.c_str() };

		//Declare the vertex and fragment shader
		unsigned int vertex, fragment;

		//Declare variables for compile and link error checking
		int success;
		char infoLog[512];

		//Create the vertex shader
		vertex = glCreateShader(GL_VERTEX_SHADER);

		//Assign and compile the vertex shader source.
		glShaderSource(vertex, 1, &vShaderCode, NULL);
		glCompileShader(vertex);

		//Check for vertex shader's compile errors
		glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vertex, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		}

		//Create the fragment shader
		fragment = glCreateShader(GL_FRAGMENT_SHADER);

		//Assign and compile the fragment shader source.
		glShaderSource(fragment, 1, &fShaderCode, NULL);
		glCompileShader(fragment);

		//Check for fragment shader's compile errors
		glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fragment, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
		}

		//Create the shader program
		ID = glCreateProgram();

		//Attach the vertex and fragment shader and link them
		glAttachShader(ID, vertex);
		glAttachShader(ID, fragment);
		glLinkProgram(ID);

		//Check for linking errors
		glGetProgramiv(ID, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(ID, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << std::endl;
		}

		//Delete the vertex and fragment shader since it's already linked.
		glDeleteShader(vertex);
		glDeleteShader(fragment);
	}

	Shader::~Shader()
	{
		glDeleteProgram(ID);
	}

	void Shader::Use()
	{
		glUseProgram(ID);
	}

	void Shader::SetBool(const std::string& name, bool value) const
	{
		glUniform1i(glGetUniformLocation(ID, name.c_str()), static_cast<int>(value));
	}

	void Shader::SetInt(const std::string& name, int value) const
	{
		glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
	}

	void Shader::SetFloat(const std::string& name, float value) const
	{
		glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
	}
}