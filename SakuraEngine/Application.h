#pragma once
#include "core/Core.h"
namespace sakura {
	class SKR_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};
}