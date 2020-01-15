/** \file engineApp.cpp
*/
#include "engineApp.h"

engineApp::engineApp()
{
	m_layerStack->push(std::make_shared<Engine::JSONLayer>(Engine::JSONLayer("assets/levels/cubeLevel.json", "Game Layer")));
	m_layerStack->push(std::make_shared<Engine::JSONLayer>(Engine::JSONLayer("assets/levels/UILayer.json", "UI Layer")));
}

engineApp::~engineApp()
{

}

Engine::Application* Engine::startApplication()
{
	return new engineApp();
}