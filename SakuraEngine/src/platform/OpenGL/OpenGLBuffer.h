#pragma once

#include "graphics/Buffer.h"

#include <cstdint>

namespace SKR {

	class OpenGLVertexBuffer : public VertexBuffer
	{
	public:
		OpenGLVertexBuffer(float* vertices, uint32_t size);
		~OpenGLVertexBuffer();

		void Bind() override;
		void UnBind() override;

	private:
		uint32_t VBO;
	};

	class OpenGLIndexBuffer : public IndexBuffer
	{
	public:
		OpenGLIndexBuffer(uint32_t* indices, uint32_t count);
		~OpenGLIndexBuffer();

		void Bind() override;
		void UnBind() override;

		inline uint32_t GetCount() const override { return count; }

	private:
		uint32_t IBO;
		uint32_t count;
	};

}