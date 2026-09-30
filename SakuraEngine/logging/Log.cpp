#include "Log.h"

#include <spdlog/sinks/stdout_color_sinks.h>

namespace sakura {
	std::shared_ptr<spdlog::logger> Log::sCoreLogger;
	std::shared_ptr<spdlog::logger> Log::sClientLogger;

	void Log::Init()
	{
		// Set the pattern for the log messages
		spdlog::set_pattern("%^[%T] %n: %v%$");

		// Create the core logger
		sCoreLogger = spdlog::stdout_color_mt("Core");
		sCoreLogger->set_level(spdlog::level::trace);

		// Create the client logger
		sClientLogger = spdlog::stdout_color_mt("Client");
		sClientLogger->set_level(spdlog::level::trace);
	}
}