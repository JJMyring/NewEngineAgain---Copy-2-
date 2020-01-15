#pragma once

#include <chrono>

#include "system.h"

namespace Engine
{

	class Timer : public System
	{
	private:
		std::chrono::high_resolution_clock::time_point m_frameStart; //!< Start time of the frame
		std::chrono::high_resolution_clock::time_point m_frameEnd;   //!< End time of the frame
		std::chrono::duration<double> m_elapsedTimeSeconds; // Time elapsed between timed events
		std::chrono::duration<double, std::milli> m_elapsedTimeMilliseconds; // Time elapsed between timed events
		std::chrono::duration<double, std::micro> m_elapsedTimeMicroseconds; // Time elapsed between timed events
		static std::chrono::high_resolution_clock::time_point m_frameDelta; //!< Delta, if requested
	public:
		void start(SystemSignal init = SystemSignal::None, ...) override;
		void stop(SystemSignal close = SystemSignal::None, ...) override {};
		static void markDelta();
		static inline auto getDelta() { return Timer::m_frameDelta; }
		float getFrameTimeMilliseconds();
		float getFrameTimeMicroseconds();
		float getFrameTimeSeconds();
		static float getDeltaMilliseconds();
		static float getDeltaMicroseconds();
		static float getDeltaSeconds();
	};
}