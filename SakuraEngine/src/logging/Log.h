#pragma once

#include <memory>

#include "spdlog/spdlog.h"
#include "core/Core.h"

namespace SKR {

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
#define SKR_CORE_TRACE(...) ::SKR::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SKR_CORE_INFO(...)  ::SKR::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SKR_CORE_WARN(...)  ::SKR::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SKR_CORE_ERROR(...) ::SKR::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SKR_CORE_DEBUG(...) ::SKR::Log::GetCoreLogger()->debug(__VA_ARGS__)

// Client log macros
#define SKR_TRACE(...) ::SKR::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SKR_INFO(...)  ::SKR::Log::GetClientLogger()->info(__VA_ARGS__)
#define SKR_WARN(...)  ::SKR::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SKR_ERROR(...) ::SKR::Log::GetClientLogger()->error(__VA_ARGS__)
#define SKR_DEBUG(...) ::SKR::Log::GetClientLogger()->debug(__VA_ARGS__)