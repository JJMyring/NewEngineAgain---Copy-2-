/** \file perspectiveCamera3D.h
*/
#pragma once

#include "camera.h"

#include <glm/gtc/quaternion.hpp>

namespace Engine
{
	class PerspectiveCamera3D : public Camera
	{
	private:
		glm::vec3 m_position = glm::vec3(0.f); //!< Camera position
		glm::quat m_orientation; //!< Camera orientation
		virtual void updateView() override; //!< Update the cameras view matrix
	public:
		PerspectiveCamera3D(float fov, float aspectRatio, float nearClip, float farClip); //!< Constructor
		void reset(float fov, float aspectRatio, float nearClip, float farClip); //!< reset function
		inline glm::vec3 getPosition() { return m_position; } //!< Return position
		inline glm::quat getOrientation() { return m_orientation; } //!< Returns orientation
		void setView(const glm::mat4& view) { m_view = view; m_viewProjection = m_projection * m_view; } //!< Set the view and recalc
		void setPosition(const glm::vec3& position) { m_position = position; updateView(); } //!< Set the position and recalc
		void setOrientation(const glm::quat& orientation) { m_orientation = orientation; updateView(); } //!< Set the orienatation and recalc
		void setPositionAndOrientation(const glm::vec3& position, const glm::quat& orientation)  //!< Set the position and orienatation and recalc
		{ m_position = position; m_orientation = orientation; updateView(); }
	};
}