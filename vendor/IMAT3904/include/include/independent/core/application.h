/** \file application.h
*/
#pragma once

#include "systems/log.h"
#include "systems/timer.h"
#include "systems/windows.h"
#include "systems/layerStack.h"
#include "systems/resourceManager.h"

#include "windows/window.h"

#include "events/event.h"
#include "events/windowsEvents.h"
#include "events/keyEvents.h"
#include "events/codes.h"
#include "events/inputPolling.h"



namespace Engine {

	/**
	\class Application
	Fundemental class of the engine. A singleton which runs the game loop infinitely.
	Provides a logger, timer, windows system, resource manager and a layerstack in which layers or JSOn layer can be added
	*/

	class Application
	{
	protected:
		Application(); //!< Constructor
		// Systems
		std::shared_ptr<Log> m_log; //!< Logging system
		std::shared_ptr<Timer> m_timer; //!< Timing system
		std::shared_ptr<WindowsSystem> m_windows; //!< Windows system
		static std::shared_ptr<ResourceManager> m_resources; //!< Resource management system
		std::shared_ptr<LayerStack> m_layerStack; //!< Layer stack system
		// shared data
		static glm::ivec2 s_screenResolution; //!< Screen res
		std::shared_ptr<Window> m_window; //!< Window (abstract)
		static float s_timestep; //!< last frame timestep
	private:
		static Application* s_instance; //!< Singleton instance of the application
		bool m_running = true; //!< Is the application running?
	public:
		virtual ~Application(); //!< Deconstructor
		inline static Application& getInstance() { return *s_instance; } //!< Instance getter from singleton pattern
		inline static float getTimestep() { return s_timestep; } //!< Returns the last timestep
		inline static glm::vec2 getScreenRes() { return s_screenResolution;  } //!< Returns the screen res
		inline static std::shared_ptr<ResourceManager> getResources() { return m_resources; } //!< Returns the resource manager
		inline std::shared_ptr<Window> getWindow() { return m_window; } //!< Returns the window
		void onEvent(Event& e); //!< Called when an event happens
		bool onClose(WindowCloseEvent& e); //!< On close event
		bool onResize(WindowResizeEvent& e); //!< On resize event
		bool onKeyPressed(KeyPressedEvent& e); //!< On keypress event
		void run(); //!< Main loop
	};

	// To be defined in users code
	Application* startApplication(); //!< Function definition which provides an entry hook

}