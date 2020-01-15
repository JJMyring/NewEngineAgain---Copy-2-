/** \file cameraController.h
*/
#pragma once

#include "camera.h"
#include "events/event.h"
#include "events/windowsEvents.h"
#include <memory>

namespace Engine
{
	/** \class CameraController Interface class for a camera controller */
	class CameraController
	{
	public:
		virtual void init(float, float, float, float) = 0; //!< Initialise the controller
		virtual std::shared_ptr<Camera> getCamera() = 0; //!< Accessor for the camera
		virtual void onUpdate(float timestep) = 0; //!< Update the camera
		virtual void onEvent(Event& e) = 0; //!< handle an event
		virtual void onResize(WindowResizeEvent& wre) = 0; //!< handle a resize event
	};
}