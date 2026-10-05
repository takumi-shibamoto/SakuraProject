#pragma once

#include "Window.h"
#include <memory>

namespace SKR {
	class SKR_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	private:
		std::unique_ptr<Window> window;
		bool isRunning = true;
	};

	/// <summary>
	/// To be defined in the client application code. This function is responsible for creating and returning an instance of the Application class.
	/// </summary>
	/// <returns>Pointer to the application instance</returns>
	Application* CreateApplication();
}