/** \file assetManager.h
*/
#pragma once

#include <memory>
#include <map>

namespace Engine {

	/**
	\class AssetManager
	A templated class which holds a parameterised type in a map. Will only accept shared pointers to each element.
	*/

	template <class G>
	class AssetManager
	{
	public:
		bool contains(const std::string& key); //!< Is this item in the container already
		void add(const std::string& key, std::shared_ptr<G>& element); //!< Add element to the container
		std::shared_ptr<G> get(const std::string& key); //!< Get a point to an asset. Return nullptr is not found 
	private:
		std::map <std::string, std::shared_ptr<G>> m_container; //!< Data structure to hold assets
	};

	template <class G>
	bool AssetManager<G>::contains(const std::string& key) //!< Does the asset manager have anything at key?
	{
		return m_container.find(key) != m_container.end();
	}

	template <class G>
	void AssetManager<G>::add(const std::string& key, std::shared_ptr<G>& element) //!< Add/replace the element at key
	{
		m_container[key] = element;
	}

	template <class G>
	std::shared_ptr<G> AssetManager<G>::get(const std::string& key) //!< Return the leement at key
	{
		if (contains(key)) return m_container[key];
		else return nullptr;
	}
}
