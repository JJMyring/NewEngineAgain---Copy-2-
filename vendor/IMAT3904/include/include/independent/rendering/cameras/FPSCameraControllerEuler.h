#pragma once

#include "cameraController.h"
#include "perspectiveCamera3D.h"
#include "events/mouseEvents.h"

namespace Engine
{
	class FPSCameraControllerEuler : public CameraController
	{
	private:
		std::shared_ptr<PerspectiveCamera3D> m_camera; //!< Camera
		glm::mat4 m_view; //!< View matrix
		glm::vec3 m_position; //!< Camera position
		glm::vec3 m_forward; //!< Camera's forward vector
		glm::vec3 m_up; //!< Camera's up vector
		glm::vec3 m_right; //!< Camera's right vector
		glm::vec3 m_worldUp; //!< World up vector
		float m_yaw; //!< Yaw rotation
		float m_pitch; //!< Pitch rotation
		float m_translationSpeed = 2.0f; //!< Speed at which the camera moves
		float m_rotationSpeed = 2.0f; //!< Speed at which the camera rotates
		glm::vec2 m_lastMousePosition; //!< Captured last mouse position for delta calcs
		void updateView(); //!< Update the view of the camera
	public:
		FPSCameraControllerEuler(); //!< Constructor
		virtual void init(float fov = 45.f, float aspectRatio = 4.0f / 3.0f, float nearClip = 0.1f, float farClip = 100.f) override; //!< Init function
		virtual std::shared_ptr<Camera> getCamera() override { return m_camera; } //!< Return the camera
		virtual void onUpdate(float timestep) override; //!< Run every frame
		virtual void onEvent(Event& e) override; //!< Run when a event happens
		virtual void onResize(WindowResizeEvent& wre) override {}; //!< DO nothing when the window resizes
		bool onMouseButton(MouseButtonPressedEvent& e); //!< Run when the mouse button is pressed
	};
}
