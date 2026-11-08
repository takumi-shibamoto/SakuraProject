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

		//Test verticies triangle.
		float vertices[] = {
		    -0.5f, -0.5f, 0.0f, 1.f, 0.f, 0.f,
		        0.5f, -0.5f, 0.0f, 0.f, 1.f, 0.f,
		        0.0f,  0.5f, 0.0f, 0.f, 0.f, 1.f
		};
		
		//Generate the vertex array object
		glGenVertexArrays(1, &VAO);

		//Bind the vertex array object
		glBindVertexArray(VAO);

		vertexBuffer.reset(VertexBuffer::Create(vertices, sizeof(vertices) / sizeof(float)));

		//Specify the vertex attribute and enable them
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		//Specify the color attribute and enable them
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);

		//Unbind VAO and VBO
		vertexBuffer->UnBind();
		glBindVertexArray(0);

		// Create the shader
		shader = std::make_unique<Shader>("assets/shaders/Basic.vert", "assets/shaders/Basic.frag");
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

		// Handle the event in the order of layers.
		for (std::vector<Layer*>::iterator iter = layerStack.end(); iter != layerStack.begin();)
		{
			(*--iter)->OnEvent(event);
			if (event.IsHandled())
				break;
		}
	}

	bool Application::OnWindowClose([[maybe_unused]] WindowCloseEvent& event)
	{
		isRunning = false;
		glDeleteVertexArrays(1, &VAO);
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

			//Activate the shader.
			shader->Use();

			glBindVertexArray(VAO);
			glDrawArrays(GL_TRIANGLES, 0, 3);
			glBindVertexArray(0);

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