/** \file controllerComponents.h
*/
#pragma once
/** \file controllerComponents.h
*/

#include "component.h"
#include "componentMessages.h"
#include "events/codes.h"
#include "events/inputPolling.h"
#include "events/mouseEvents.h"

namespace Engine {
	/** \class ControllerComponent Abstract base class for controller components */
	class ControllerComponent : public Component
	{
	public:
		virtual void receiveMessage(const ComponentMessage& msg) override {}; 
	};

	class OscilateComponent : public ControllerComponent
	{
	public:
		enum state { DOWN = -1, STOPPED = 0, UP = 1 };
	private:
		state m_state = UP;
		float m_timeAccumlated;
	public:
		OscilateComponent(OscilateComponent::state initialState, float timeAccumulated) :
			m_state(initialState), m_timeAccumlated(timeAccumulated) {}
		
		void onAttach(GameObject* owner) override
		{
			m_owner = owner;

			if (m_state == DOWN)
			{
				sendMessage(ComponentMessage(ComponentMessageType::VelocitySetLinear, std::any(glm::vec3(0.f, -0.2f, 0.f))));
			}
			else if (m_state == UP)
			{
				sendMessage(ComponentMessage(ComponentMessageType::VelocitySetLinear, std::any(glm::vec3(0.f, 0.2f, 0.f))));
			}
			sendMessage(ComponentMessage(ComponentMessageType::TextureSet, std::any(m_state)));
		}
		void onUpdate(float timestep) override
		{
			m_timeAccumlated += timestep;
			if (m_timeAccumlated > 20.f)
			{
				if (m_state == DOWN)
				{
					m_state = UP;
					sendMessage(ComponentMessage(ComponentMessageType::VelocitySetLinear, std::any(glm::vec3(0.f, 0.2f,0.f))));
				}
				else if (m_state == UP)
				{
					m_state = DOWN;
					sendMessage(ComponentMessage(ComponentMessageType::VelocitySetLinear, std::any(glm::vec3(0.f,-0.2f,0.f))));
				}
				sendMessage(ComponentMessage(ComponentMessageType::TextureSet, std::any(m_state)));
				m_timeAccumlated = 20.f - m_timeAccumlated;
			}
		}
		void receiveMessage(const ComponentMessage& msg) override {
			switch (msg.m_msgType)
			{
			case ComponentMessageType::KeyPressed:
			{
				int keyCode = std::any_cast<int>(msg.m_msgData);
				if (keyCode == 68) // CHANGE THIS NUMBER
				{
					if (m_state != STOPPED)
					{
						m_state = STOPPED;
						sendMessage(ComponentMessage(ComponentMessageType::VelocitySetLinear, std::any(glm::vec3(0.f, 0.f, 0.f))));
					}
					else
					{
						// Need to get vel?
					}
				}
				return;
			}
			}
		}
	};

	class KeyboardCtrlComponent : public ControllerComponent
	{
	private:
		glm::vec2 m_lastMousePosition;
		bool onMouseButton(MouseButtonPressedEvent& e)
		{
			if (e.getButton() == NG_MOUSE_BUTTON_RIGHT)
				m_lastMousePosition = InputPoller::getMousePosition();
			return true;
		}
	public:
		void onUpdate(float timestep) override
		{
			bool posMoved = false;
			glm::vec3 angularDelta(0.f), linearDelta(0.f);

			if (InputPoller::isKeyPressed(NG_KEY_I)) { linearDelta.z += 1.0f; posMoved = true; }
			if (InputPoller::isKeyPressed(NG_KEY_P)) { linearDelta.z -= 1.0f; posMoved = true; }
			if (InputPoller::isKeyPressed(NG_KEY_J)) { linearDelta.x += 1.0f; posMoved = true; }
			if (InputPoller::isKeyPressed(NG_KEY_L)) { linearDelta.x -= 1.0f; posMoved = true; }
			if (InputPoller::isKeyPressed(NG_KEY_O)) { linearDelta.y += 1.0f; posMoved = true; }
			if (InputPoller::isKeyPressed(NG_KEY_K)) { linearDelta.y -= 1.0f; posMoved = true; }


			if (InputPoller::isMouseButtonPressed(NG_MOUSE_BUTTON_RIGHT))
			{
				posMoved = true;
				glm::vec2 currentMousePosition = InputPoller::getMousePosition();
				glm::vec2 mouseDelta = currentMousePosition - m_lastMousePosition;

				angularDelta.x += mouseDelta.y * 100.f;
				angularDelta.y += mouseDelta.x * 100.f;

				m_lastMousePosition = currentMousePosition;
			}

			if (posMoved)
			{
				std::pair<glm::vec3, glm::vec3> data(linearDelta * timestep, angularDelta * timestep);
				sendMessage(ComponentMessage(ComponentMessageType::PositionIntegrate, std::any(data)));
			}
		}
		void onEvent(Event& e) override
		{
			EventDispatcher dispatcher(e);
			dispatcher.dispatch<MouseButtonPressedEvent>(std::bind(&KeyboardCtrlComponent::onMouseButton, this, std::placeholders::_1));
		}
	};
}