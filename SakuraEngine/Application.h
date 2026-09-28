#pragma once
#include "core/Core.h"
namespace SKR {
	class SKR_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	/// <summary>
	/// To be defined in the client application code. This function is responsible for creating and returning an instance of the Application class.
	/// </summary>
	/// <returns>Pointer to the application instance</returns>
	Application* CreateApplication();
}