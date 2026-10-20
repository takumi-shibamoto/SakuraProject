#include <skrpch.h>
#include "ImGuiLayer.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

namespace SKR {

	ImGuiLayer::ImGuiLayer()
		: Layer("ImGuiLayer") {}

	ImGuiLayer::~ImGuiLayer()
	{

	}

	void ImGuiLayer::OnAttached()
	{
		// Create the context for the imgui. A space for imgui to work.
		ImGui::CreateContext();

		// Get the imgui io. Communication tool for imgui and the engine.
		ImGuiIO& io = ImGui::GetIO();

		// Set the config flags
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
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