#pragma once
#ifdef SKR_PLATFORM_WINDOWS
	#ifdef SKR_BUILD_DLL
		#define SKR_API __declspec(dllexport)
	#else
		#define SKR_API __declspec(dllimport)
	#endif  
#else
	#error Sakura Engine is only supported for Windows
#endif