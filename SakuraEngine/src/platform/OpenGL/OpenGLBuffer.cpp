#include "skrpch.h"
#include "OpenGLBuffer.h"

#include <glad/glad.h>

namespace SKR {

	OpenGLVertexBuffer::OpenGLVertexBuffer(float* vertices, size_t size)
	{
		//Generate the vertex buffer object
		glGenBuffers(1, &VBO);

		//Bind the buffer
		glBindBuffer(GL_ARRAY_BUFFER, VBO);

		//Copy the vertex data into the buffer's memory.
		glBufferData(GL_ARRAY_BUFFER, sizeof(float) * size, vertices, GL_STATIC_DRAW);
	}

	OpenGLVertexBuffer::~OpenGLVertexBuffer()
	{
		glDeleteBuffers(1, &VBO);
	}

	void OpenGLVertexBuffer::Bind()
	{
		//Bind the buffer
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
	}

	void OpenGLVertexBuffer::UnBind()
	{
		//Unbind VBO
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

}