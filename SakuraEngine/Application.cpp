#include "skrpch.h"
#include "Application.h"
#include "logging/Log.h"

namespace SKR {
	Application::Application()
	{
		window = std::unique_ptr<Window>(Window::Create());
		window->SetEventCallback([this](Event& event) { this->OnEvent(event); });
	}

	Application::~Application()
	{

	}

	void Application::OnEvent(Event& event)
	{
		// Create an instance of the event dispatcher.
		EventDispatcher dispatcher{event};

		// Dispatch the event to the window closed event.
		dispatcher.Dispatch<WindowCloseEvent>([this](WindowCloseEvent& event) { return this->OnWindowClose(event); });

		SKR_CORE_DEBUG("{0}", event.ToString());
	}

	bool Application::OnWindowClose(WindowCloseEvent& event)
	{
		isRunning = false;
		return true;
	}

	void Application::Run()
	{
		while (isRunning)
		{
			window->OnUpdate();
		}
	}
}