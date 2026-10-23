#include <skrpch.h>
#include "ImGuiLayer.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "core/Application.h"

#include <GLFW/glfw3.h>

namespace SKR {

	ImGuiLayer::ImGuiLayer()
		: Layer("ImGuiLayer") {}

	ImGuiLayer::~ImGuiLayer()
	{

	}

	void ImGuiLayer::OnAttached()
	{
		float mainScale = ImGui_ImplGlfw_GetContentScaleForWindow(static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow()));

		// Check if the ImGui version is up to date.
		IMGUI_CHECKVERSION();

		// Create the context for the imgui. A space for imgui to work.
		ImGui::CreateContext();

		// Get the imgui io. Communication tool for imgui and the engine.
		ImGuiIO& io = ImGui::GetIO();

		// Set the config flags
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
		io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

		// Setup dear imgui style.
		ImGuiStyle& style{ ImGui::GetStyle() };
		ImGui::StyleColorsDark();
		style.FrameRounding = 3.0f;
		style.GrabRounding = 3.0f;

		// Set up scaling
		style.ScaleAllSizes(mainScale);
		style.FontScaleDpi = mainScale;
		io.ConfigDpiScaleFonts = true;
		io.ConfigDpiScaleViewports = true;

		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			style.WindowRounding = 0.f;
			style.Colors[ImGuiCol_WindowBg].w = 1.f;
		}

		// Initialize imgui with opengl.
		ImGui_ImplGlfw_InitForOpenGL(static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow()), true);
		ImGui_ImplOpenGL3_Init("#version 410");
	}

	void ImGuiLayer::OnDetached()
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
	}

	void ImGuiLayer::Begin()
	{
		// Start the frame.
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();		
		
		// Show the Demo window.
		bool showDemoWindow{ true };
		ImGui::ShowDemoWindow(&showDemoWindow);
	}

	void ImGuiLayer::End()
	{
		ImGuiIO& io{ ImGui::GetIO() };

		// Rendering
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		// Update and render
		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			GLFWwindow* backupCurrentContext{ static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow()) };
			ImGui::UpdatePlatformWindows();
			ImGui::RenderPlatformWindowsDefault();
			glfwMakeContextCurrent(backupCurrentContext);
		}
	}

	void ImGuiLayer::OnEvent(Event& event)
	{

	}
}