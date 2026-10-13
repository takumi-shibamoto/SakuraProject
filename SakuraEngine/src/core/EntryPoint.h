#pragma once

#ifdef SKR_PLATFORM_WINDOWS

/// <summary>
/// External function to create the application instance. This function is expected to be defined in the client application code.
/// </summary>
/// <returns>Pointer to the application instance</returns>
extern SKR::Application* SKR::CreateApplication();

int main(int argc, char** argv)
{
	SKR::Log::Init();
	SKR_CORE_DEBUG("debugging logging");
	int a{ 5 };
	SKR_INFO("Hello! Var={0}", a);

	SKR::Application* app = SKR::CreateApplication();
    app->Run();
    delete app;
}

#else
	#error Sakura Engine only supports Windows
#endif
