#pragma once

#include "graphics/Context.h"

#include <GLFW/glfw3.h>

namespace SKR {

	/// <summary>
	/// Renderer context for opengl.
	/// </summary>
	class OpenGLContext : public Context
	{
	public:
		/// <summary>
		/// Constructor.
		/// </summary>
		/// <param name="windowHandle">pointer to the window.</param>
		OpenGLContext(GLFWwindow* windowHandle);

		/// <summary>
		/// make the current context and initialize glad.
		/// </summary>
		void Init() override;

		/// <summary>
		/// Swap buffer to update the screen.
		/// </summary>
		void SwapBuffer() override;

	private:
		// Window handle.
		GLFWwindow* window;
	};

}