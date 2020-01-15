/** \file component.h
*/

#include <memory>
#include "events/event.h"
#include "componentMessages.h"

#pragma once

namespace Engine
{
	class GameObject; //!< Forward declaration to allow compilation

	/** \class Component Abstract base class for all compotents
	*/
	class Component
	{
	protected:
		GameObject* m_owner = nullptr; //!< Owner of the component, using a raw pointer as their is no ownership
		virtual void sendMessage(const ComponentMessage& msg); //!< Send message to all components attached to this game object
	public:
		virtual void onAttach(GameObject* owner) { m_owner = owner; }; //!< Runs when component is attached to a game object
		virtual void onDetach() {m_owner = nullptr;}; //!< Runs when component is detached from a game object
		virtual void onUpdate(float timestep) {}; //!< Runs on layer onUpdate
		virtual void onEvent(Event& e) {}; //!< Runs when the Layer is given an event ot handle
		virtual void receiveMessage(const ComponentMessage& msg) = 0; //!< Receive a message from another component
	};
}

