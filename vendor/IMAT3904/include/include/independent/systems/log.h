/** \file log.h
*/
#pragma once

#include "system.h"

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace Engine {

	/**
	\class Log
	A simple logging class which makes use of spdlog.
	This class is intends to be used by the macros below.
	Provides two loggers, one for Engine code and one for App code
	*/

	class Log : public System
	{
	public:
		~Log(); //!< Deconstructor
		void start(SystemSignal init = SystemSignal::None, ...) override; //!< Start the loggers
		void stop(SystemSignal close = SystemSignal::None, ...) override; //!< Stop the loggers
		inline static std::shared_ptr<spdlog::logger>& getEngineLogger() { return s_engineLogger; } //!< Getter for engine logger
		inline static std::shared_ptr<spdlog::logger>& getAppLogger() { return s_appLogger; } //!< Getter for app logger
		static inline bool isRunning() { return s_running; } //!< Getter for running
	private:
		static bool s_running; //!< Has the logger been started
		static std::shared_ptr<spdlog::logger> s_engineLogger; //!< Engine side logger
		static std::shared_ptr<spdlog::logger> s_appLogger; //!< App side logger
	};
}

//#ifdef NG_DEBUG
// Engine logging macros
#define ENGINE_TRACE(...)    Engine::Log::getEngineLogger()->trace(__VA_ARGS__)
#define ENGINE_INFO(...)     Engine::Log::getEngineLogger()->info(__VA_ARGS__)
#define ENGINE_WARN(...)     Engine::Log::getEngineLogger()->warn(__VA_ARGS__)
#define ENGINE_ERROR(...)    Engine::Log::getEngineLogger()->error(__VA_ARGS__)
#define ENGINE_FATAL(...)    Engine::Log::getEngineLogger()->critical(__VA_ARGS__)

// App logging macros
#define NG_TRACE(...)	     Engine::Log::getAppLogger()->trace(__VA_ARGS__)
#define NG_INFO(...)	     Engine::Log::getAppLogger()->info(__VA_ARGS__)
#define NG_WARN(...)	     Engine::Log::getAppLogger()->warn(__VA_ARGS__)
#define NG_ERROR(...)	     Engine::Log::getAppLogger()->error(__VA_ARGS__)
#define NG_FATAL(...)	     Engine::Log::getAppLogger()->critical(__VA_ARGS__)
/*
#else
// Engine logging macros
#define ENGINE_TRACE(...)    
#define ENGINE_INFO(...)     
#define ENGINE_WARN(...)     
#define ENGINE_ERROR(...)    
#define ENGINE_FATAL(...)    

// App logging macros
#define NG_TRACE(...)	     
#define NG_INFO(...)	     
#define NG_WARN(...)	     
#define NG_ERROR(...)	     
#define NG_FATAL(...)	     

#endif
*/




