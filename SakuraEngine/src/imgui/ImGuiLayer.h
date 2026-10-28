#pragma once

#include "core/Core.h"
#include "layer/Layer.h"

namespace SKR {

	class SKR_API ImGuiLayer : public Layer
	{
	public:
		/// <summary>
		/// Constructor. Set the name of the layer to ImGuiLayer.
		/// </summary>
		ImGuiLayer();

		/// <summary>
		/// Destructor.
		/// </summary>
		~ImGuiLayer() override;
		
		/// <summary>
		/// Called when the layer is attached.
		/// Initialize ImGui (Glfw and Opengl for now).
		/// </summary>
		void OnAttached() override;

		/// <summary>
		/// Called when the layer is detached.
		/// Shutdown and Destroy ImGui.
		/// </summary>
		void OnDetached() override;

		/// <summary>
		/// Start a new frame of the ImGui frame.
		/// </summary>
		void Begin();

		/// <summary>
		/// Render ImGui.
		/// </summary>
		void End();

		/// <summary>
		/// Handle the mouse and keyboard event for imgui.
		/// </summary>
		/// <param name="event">event that was handled.</param>
		void OnEvent(Event& event) override;

		/// <summary>
		/// Render the imgui demo window.
		/// </summary>
		void OnImGuiRender() override;
	};

}