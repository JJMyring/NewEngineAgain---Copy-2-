/** \file windows.h
*/
#pragma once

#include "systems/system.h"

namespace Engine {

	/**
	\class Windows
	A simple class which performs one time start up/shuttign down of the relevant windowing system.
	Intended to be used polymophically.
	*/

	class WindowsSystem : public System {
	protected:
		bool m_running = false; //!< Status of the windows system
	public:
		virtual void start(SystemSignal sig = SystemSignal::None, ...) = 0; //!< Start the windows systen
		virtual void stop(SystemSignal sig = SystemSignal::None, ...) = 0; //!< Stop the windows system
		inline bool isRunning() { return m_running; } //!< Getter: Is the windows system running?
	};
}