/** \file physicsComponents.h
*/
#pragma once

#include "component.h"
#include "componentMessages.h"


#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtx/transform.hpp"

#include "glm/gtc/quaternion.hpp"
#include "glm/gtx/quaternion.hpp"

#include <string>

namespace Engine
{
	class PositionComponent : public Component
	{
	private:
		glm::mat4 m_model; //!< Model matrix
		glm::mat4 m_translation; //!< Translation matrix
		glm::mat4 m_rotation; //!< Rotation matrix
		glm::mat4 m_scale; //!< Scale matrix
		glm::vec3 m_transVec; //!< Translation vector
		glm::vec3 m_rotVec; //!< Rotation vector
		glm::vec3 m_scaleVec; //!< Scale vector
		inline void calculateModel() //!< Calculate the mode matrix based on scale,rot dand trans vectors. Matrix will also be updated
		{ 
			m_translation = glm::translate(glm::mat4(1.0f), m_transVec);
			m_rotation = glm::toMat4(glm::quat(m_rotVec));
			m_scale = glm::scale(m_scaleVec);
			m_model = m_translation * m_rotation * m_scale;
		}
	public:
		PositionComponent(glm::vec3 trans, glm::vec3 rot, glm::vec3 scale) :
			m_transVec(trans), m_rotVec(rot), m_scaleVec(scale),
			m_model(glm::mat4(1.0f)) //!< Constructor which take translation, rotation and scaling
		{
			m_rotVec.x = glm::radians(m_rotVec.x);
			m_rotVec.y = glm::radians(m_rotVec.y);
			m_rotVec.z = glm::radians(m_rotVec.z);
			calculateModel();
		};
		inline std::shared_ptr<glm::mat4> getTransform() //!< Return the model transform
		{ return std::make_shared<glm::mat4>(m_model); }
		virtual void receiveMessage(const ComponentMessage& msg) override //!< Receive a message from another component
		{
			switch (msg.m_msgType)
			{
			case ComponentMessageType::PositionSet:
			{
				glm::vec3 pos = std::any_cast<glm::vec3>(msg.m_msgData);
				m_transVec = pos;
				calculateModel();
				return;
			}
			case ComponentMessageType::PositionIntegrate:
			{
				std::pair<glm::vec3, glm::vec3> vel = std::any_cast<std::pair<glm::vec3, glm::vec3>>(msg.m_msgData);

				m_transVec += vel.first;
				m_rotVec.x += glm::radians(vel.second.x);
				m_rotVec.y += glm::radians(vel.second.y);
				m_rotVec.z += glm::radians(vel.second.z);
				calculateModel();
				return;
			}
			}
		}
		virtual void onUpdate(float timestep) override //!< Run every frame
		{
			std::pair<std::string, void*> data("u_model", (void*)&m_model[0][0]);
			ComponentMessage msg(ComponentMessageType::UniformSet,data);
			sendMessage(msg);
		}
		void onAttach(GameObject* owner) override //!< Run when attaching to a game object
		{
			m_owner = owner;
			std::pair<std::string, void*> data("u_model", (void*)&m_model[0][0]);
			ComponentMessage msg(ComponentMessageType::UniformSet, data);
			sendMessage(msg);
		}
	};

	class VelocityComponent : public Component
	{
	private:
		glm::vec3 m_linear; //!< Linear velocity as a vector
		glm::vec3 m_angular; //!< Angular velocity as a vector
	public:
		VelocityComponent(glm::vec3 linear, glm::vec3 angular) : m_linear(linear), m_angular(angular) {} //!< Constructor
		virtual void receiveMessage(const ComponentMessage& msg) override //!< Receive a message from another component 
		{
			switch (msg.m_msgType)
			{
			case ComponentMessageType::VelocitySetLinear:
			{
				glm::vec3 linear = std::any_cast<glm::vec3>(msg.m_msgData);
				m_linear = linear;
				return;
			}
			case ComponentMessageType::VelocitySetAngular:
			{
				glm::vec3 angular = std::any_cast<glm::vec3>(msg.m_msgData);
				m_angular = angular;
				return;
			}
			}
		}
		virtual void onUpdate(float timestep) override //!< Run every frame
		{
			std::pair<glm::vec3, glm::vec3> data(m_linear * timestep, m_angular * timestep);
			sendMessage(ComponentMessage(ComponentMessageType::PositionIntegrate, std::any(data)));
		};
	};
}