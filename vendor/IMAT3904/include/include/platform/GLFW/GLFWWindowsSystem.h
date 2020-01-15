/** \file GLFWWindowsSystem.h
*/

#pragma once

#include "GLFW/glfw3.h"

#include "windows/window.h"
#include "systems/windows.h"
#include "systems/log.h"

namespace Engine {

	/**
	\class GLFWWindowsSystem
	A simple class which performs one time start up/shutting down of GLFW
	*/
	static void GLFWErrorCallback(int error, const char* description)
	{
		ENGINE_ERROR("GLFW Error ({0}): {1}", error, description);
	}

	class GLFWWindowsSystem : public WindowsSystem {
	public:
		void start(SystemSignal sig, ...) override //!< Start the windows system
		{
			int result = glfwInit();
			glfwSetErrorCallback(GLFWErrorCallback);
			m_running = true;
		}
		void stop(SystemSignal sig, ...) override //!< Stop the windows system
		{
			glfwTerminate();
			m_running = false;
		}
	};
}