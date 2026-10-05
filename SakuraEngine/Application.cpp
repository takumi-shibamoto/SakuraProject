#include "skrpch.h"
#include "Application.h"

namespace SKR {
	Application::Application()
	{
		window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		while (isRunning)
		{
			window->OnUpdate();
		}
	}
}