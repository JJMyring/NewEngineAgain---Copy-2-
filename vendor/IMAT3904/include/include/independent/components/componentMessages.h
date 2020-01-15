/** \file componentMessages.h
*/
#pragma once

#include <any>

namespace Engine
{
	/** \class ComponentMessageType Basic list of component message types
	*/
	enum class ComponentMessageType {
		None = 0, 
		PositionIntegrate, PositionSet, RelativePositionSet,
		VelocityIntegrate, VelocitySetLinear, VelocitySetAngular,
		AccelerationSet,
		KeyPressed, KeyReleased, MouseButton, MouseScroll, MouseMoved,
		UniformSet, TextureSet
	};

	/** \class ComponentMessage A message sent between components
	*/

	class ComponentMessage
	{
	public:
		ComponentMessage(ComponentMessageType type, std::any data) : m_msgType(type), m_msgData(data) {}; //!< Constructor
		ComponentMessageType m_msgType; //!< Message type
		std::any m_msgData; //!< Data associated with the message (could use a void *)
	};

	
}