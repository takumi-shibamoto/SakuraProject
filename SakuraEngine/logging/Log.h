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