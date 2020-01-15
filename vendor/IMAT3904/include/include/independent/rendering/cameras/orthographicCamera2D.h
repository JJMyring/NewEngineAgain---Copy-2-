/** \file orthographicCamera2D.h
*/
#pragma once

#include "camera.h"

namespace Engine {
	/** \class OrthographicCamera2D A 2D camera which used an orthographic projection */
	class OrthographicCamera2D : public Camera
	{
	private:
		glm::vec2 m_position = glm::vec2(0.f); //!< Cmaera position on the near clip plane
		float m_rotation = 0.f; //!< Cameras orientation
		void updateView() override; //!< Update the view matrix based on position and rotation
	public:
		OrthographicCamera2D(float left, float right, float bottom, float top); //!< Constructor
		void reset(float left, float right, float bottom, float top); //!< Reset the cameras matrices
		inline glm::vec2 getPosition() const { return m_position; } //!< Accessor for position
		inline float getRotation() const { return m_rotation; } //!< Accessor for rotation
		void setPosition(const glm::vec2& position) { m_position = position; updateView(); } //!< Set the camera position and update the view matrix
		void setRotation(float rotation) { m_rotation = rotation; updateView(); } //!< Set the camera orientation and update the view matrix
		void setPositionRotation(const glm::vec2& position, float rotation) { m_position = position; m_rotation = rotation; updateView();} //!< Set the cameras position and orienatation and update the view matrix
	};
}
