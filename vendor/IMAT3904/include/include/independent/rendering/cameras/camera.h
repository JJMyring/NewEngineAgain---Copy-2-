/** \file camera.h
*/
#pragma once

#include <glm/glm.hpp>

namespace Engine
{
	/** \class Camera Abstract base class for a camera*/
	class Camera
	{
	protected:
		glm::mat4 m_projection; //!< Projection matrix
		glm::mat4 m_view; //!< View matric
		glm::mat4 m_viewProjection; //!< View projection matrix
	public:
		virtual void updateView() = 0; //!< Called by a controller to update the view matrix
		const glm::mat4& getProjection() { return m_projection; } //!< Accessor for the projection matrix
		const glm::mat4& getView() { return m_view; } //!< Accessor for the viewmatrix
		const glm::mat4& getViewProjection() { return m_viewProjection; } //!< Accessor for the view projection matrix
	};
}