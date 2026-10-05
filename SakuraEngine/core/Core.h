#pragma once

// Macro for the dll export and import.
#ifdef SKR_PLATFORM_WINDOWS
	#ifdef SKR_BUILD_DLL
		#define SKR_API __declspec(dllexport)
	#else
		#define SKR_API __declspec(dllimport)
	#endif  
#else
	#error Sakura Engine is only supported for Windows
#endif

// Macro for assertion.
# ifdef SKR_ENABLE_ASSERT
	#define SKR_ASSERT(x, ...) { if (!x) { SKR_ERROR("Assertion Failed : {0}", __VA_ARGS__); __debugbreak(); } }
	#define SKR_CORE_ASSERT(x, ...) { if (!x) { SKR_CORE_ERROR("Assertion Failed : {0}", __VA_ARGS__); __debugbreak(); } }
# else
	#define SKR_ASSERT(x, ...)
	#define SKR_CORE_ASSERT(x, ...)
# endif

#define BIT(x) (1 << x)