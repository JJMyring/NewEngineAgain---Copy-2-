/** \file renderingComponents.h
*/
#pragma once

#include "component.h"
#include "ComponentMessages.h"

#include "rendering/material.h"
#include "rendering/texture.h"

#include "glm/glm.hpp"

#include "controllerComponents.h"

#include "systems/log.h"

namespace Engine
{
	class MaterialComponent : public Component
	{
	private:
		std::shared_ptr<Material> m_material; //!< Material
	public:
		MaterialComponent(const std::shared_ptr<Material>& material) : m_material(material) {} //!< Constructor
		inline std::shared_ptr<Material> getMaterial()  //!< Returns the material
		{ return m_material; }
		virtual void receiveMessage(const ComponentMessage& msg) override //!< Receive a message from another component 
		{
			switch (msg.m_msgType)
			{
			case ComponentMessageType::UniformSet:
				std::pair<std::string, void*> dataPair = std::any_cast<std::pair<std::string, void*>>(msg.m_msgData);
				m_material->setDataElement(dataPair.first, dataPair.second);
				return;
			}
		}
	};

	

	
}