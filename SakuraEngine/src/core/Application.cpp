#include "skrpch.h"
#include "Application.h"
#include "logging/Log.h"

#include <GLFW/glfw3.h> // Delete when implementing renderer.
#include <glad/glad.h> // Delete when implementing renderer.

namespace SKR {
	Application* Application::instance = nullptr;

	Application::Application()
		: imguiLayer{ nullptr }
	{
		SKR_CORE_ASSERT(!instance, "Applicaiton Already Exists!");
		instance = this;

		window = std::unique_ptr<Window>(Window::Create());
		window->SetEventCallback([this](Event& event) { this->OnEvent(event); });

		imguiLayer = new ImGuiLayer();
		PushOverlay(imguiLayer);
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

		// Handle the event in the order of layers.
		for (std::vector<Layer*>::iterator iter = layerStack.end(); iter != layerStack.begin();)
		{
			(*--iter)->OnEvent(event);
			if (event.IsHandled())
				break;
		}
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
			//specify what color to clear the color buffer
			//Delete after implementing renderer.
			glClearColor(0.2f, 0.3f, 0.3f, 1.f);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : layerStack)
				layer->OnUpdate();

			imguiLayer->Begin();

			for (Layer* layer : layerStack)
				layer->OnImGuiRender();

			imguiLayer->End();

			window->OnUpdate();
		}
	}

	void Application::PushLayer(Layer* layer)
	{
		layerStack.PushLayer(layer);
		layer->OnAttached();
	}

	void Application::PushOverlay(Layer* layer)
	{
		layerStack.PushOverlay(layer);
		layer->OnAttached();
	}
}