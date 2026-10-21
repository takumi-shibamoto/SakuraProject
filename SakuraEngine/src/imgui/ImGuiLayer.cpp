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

		// Setup dear imgui style.
		ImGuiStyle& style{ ImGui::GetStyle() };
		ImGui::StyleColorsDark();
		style.FrameRounding = 3.0f;
		style.GrabRounding = 3.0f;


	}

	void ImGuiLayer::OnDetached()
	{

	}

	void ImGuiLayer::OnUpdate()
	{

	}

	void ImGuiLayer::OnEvent(Event& event)
	{

	}
}