#pragma once

#include "core/Core.h"
#include "layer/Layer.h"

namespace SKR {

	class SKR_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() override;
		
		void OnAttached() override;
		void OnDetached() override;

		void Begin();
		void End();
		void OnEvent(Event& event) override;
	};

}