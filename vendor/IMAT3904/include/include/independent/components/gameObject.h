/** \file gameObject.h
*/
#pragma once

#include <vector>
#include "component.h"
#include "events/event.h"

namespace Engine
{
	/** \class GameObject A composable game obejct to whcih compoents are attached */
	class GameObject
	{
	protected:
		std::string m_name; //!< Name for debug purposes
		std::vector<std::shared_ptr<Component>> m_components; //!< Attached components
	public:
		GameObject(const std::string& name) : m_name(name) {} //!< Constructor
		void onUpdate(float timestep); //!< Runs on layer update
		void onEvent(Event& e); //!< Runs on layer event
		void addComponent(const std::shared_ptr<Component>& comp); //!< Add a component to the game object
		void removeComponent(std::vector<std::shared_ptr<Component>>::iterator iter); //!< Remove a component from the game object
		template<typename G>
		std::vector<std::shared_ptr<Component>>::iterator getComponent() //!< retrieve a component of type G
		{
			auto result = m_components.end();
			for (auto it = m_components.begin(); it != m_components.end(); ++it)
			{
				if (typeid(decltype(*(it->get()))).hash_code() == typeid(G).hash_code()) return it;
			}

			return result;
		}
		
		inline std::vector<std::shared_ptr<Component>>::iterator begin() { return m_components.begin(); } //!< Basic STL iterator
		inline std::vector<std::shared_ptr<Component>>::iterator end() { return m_components.end(); } //!< Basic STL iterator
		inline std::string name() { return m_name; } //!< Accessor for name
	};
}