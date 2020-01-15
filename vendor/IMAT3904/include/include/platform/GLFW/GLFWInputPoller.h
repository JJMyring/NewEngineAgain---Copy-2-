/** \file GLFWInputPolling.h
*/
#pragma once

#include "events/inputPolling.h"

namespace Engine {
	/** \class GLFW API specific input polling
	*/

	class GLFWInputPoller : public InputPoller
	{
	protected:
		bool isKeyPressedImpl(int keycode) override; //!< Windows API specific implementation of key press
		bool isMouseButtonPressedImpl(int button) override; //!< Windows API specific implementation of mouse button press
		glm::vec2 getMousePositionImpl() override; //!< Windows API specific implementation of mous position 
		float getMouseXImpl() override; //!< Windows API specific implementation of mouse x position
		float getMouseYImpl() override; //!< Windows API specific implementation of mouse y position
	};
}
