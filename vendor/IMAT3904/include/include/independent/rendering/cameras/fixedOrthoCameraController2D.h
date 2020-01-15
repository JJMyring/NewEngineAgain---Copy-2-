/** \file fixedOrthocameraController.h
*/
#pragma once

#include "cameraController.h"
#include "orthographicCamera2D.h"

namespace Engine
{
	/** \class FixedOrthoCameraController2D A camera controller on the near clip palne of an orthographic projection whcih does not move */
	class FixedOrthoCameraController2D : public CameraController
	{
	private:
		std::shared_ptr<OrthographicCamera2D> m_camera; //!< A 2D orthographic camera
	public:
		FixedOrthoCameraController2D();
		void init(float left, float top, float width, float height) override;
		std::shared_ptr<Camera> getCamera() override { return m_camera; }
		void onUpdate(float timestep) override {};
		void onEvent(Event& e) override {};
		void onResize(WindowResizeEvent& wre) override {};
	};
}