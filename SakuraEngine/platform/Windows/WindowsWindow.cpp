#include "skrpch.h"
#include "WindowsWindow.h"

namespace sakura {

	// Static variable to check if the glfw window has been initialized or not.
	static bool glfwInitialized = false;

	Window* Window::Create(WindowProps const& prop)
	{
		// Create a dynamically alocated window pointer.
		return new WindowsWindow(prop);
	}

	WindowsWindow::WindowsWindow(WindowProps const& prop)
	{
		Init(prop);
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		data.vSync = enabled;
	}

	void WindowsWindow::Init(WindowProps const& prop)
	{
		data.title = prop.title;
		data.width = prop.width;
		data.height = prop.height;
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(window);
	}
}