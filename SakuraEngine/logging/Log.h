#pragma once

#include <memory>

#include "spdlog/spdlog.h"
#include "core/Core.h"

namespace sakura {

	class SKR_API Log
	{
	public:
		/// <summary>
		/// Initializes the logging system. This function should be called before any logging is performed.
		/// </summary>
		static void Init();

		/// <summary>
		/// Get the core logger instance. This logger is used for logging messages from the engine/core.
		/// </summary>
		/// <returns>Shared pointer to the core logger</returns>
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return sCoreLogger; }

		/// <summary>
		/// Get the client logger instance. This logger is used for logging messages from the client/application.
		/// </summary>
		/// <returns>Shared pointer to the client logger</returns>
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return sClientLogger; }

	private:
		// Instance of the core logger.
		static std::shared_ptr<spdlog::logger> sCoreLogger;

		// Instance of the client logger.
		static std::shared_ptr<spdlog::logger> sClientLogger;
	};

}

// Core log macros
#define SKR_CORE_TRACE(...) ::sakura::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SKR_CORE_INFO(...)  ::sakura::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SKR_CORE_WARN(...)  ::sakura::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SKR_CORE_ERROR(...) ::sakura::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SKR_CORE_DEBUG(...) ::sakura::Log::GetCoreLogger()->debug(__VA_ARGS__)

// Client log macros
#define SKR_TRACE(...) ::sakura::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SKR_INFO(...)  ::sakura::Log::GetClientLogger()->info(__VA_ARGS__)
#define SKR_WARN(...)  ::sakura::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SKR_ERROR(...) ::sakura::Log::GetClientLogger()->error(__VA_ARGS__)
#define SKR_DEBUG(...) ::sakura::Log::GetClientLogger()->debug(__VA_ARGS__)