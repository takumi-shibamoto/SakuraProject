#pragma once

#include "Window.h"
#include "event/WindowEvent.h"
#include <memory>

namespace SKR {
	/// <summary>
	/// Base class of the application.
	/// </summary>
	class SKR_API Application
	{
	public:
		/// <summary>
		/// Constructor. Create the window and set the event callback function.
		/// </summary>
		Application();

		/// <summary>
		/// Destructor.
		/// </summary>
		virtual ~Application();

		/// <summary>
		/// Function that will be called while the application is running.
		/// </summary>
		void Run();

		/// <summary>
		/// Event callback function.
		/// </summary>
		/// <param name="event"></param>
		void OnEvent(Event& event);

	private:
		/// <summary>
		/// Called when the window close event happens.
		/// </summary>
		/// <param name="event">window close event</param>
		/// <returns>Always true.</returns>
		bool OnWindowClose(WindowCloseEvent& event);

		std::unique_ptr<Window> window;
		bool isRunning = true;
	};

	/// <summary>
	/// To be defined in the client application code. This function is responsible for creating and returning an instance of the Application class.
	/// </summary>
	/// <returns>Pointer to the application instance</returns>
	Application* CreateApplication();
}