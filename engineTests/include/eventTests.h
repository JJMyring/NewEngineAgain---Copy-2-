#pragma once
#include <gtest/gtest.h>

#include "include/independent/events/event.h"
#include "include/independent/events/windowsEvents.h"

const int width = 1024;
const int height = 720;
Engine::WindowResizeEvent re(width, height);
Engine::WindowCloseEvent ce;

bool OnResizeTrue(Engine::WindowResizeEvent& e)
{
	return true;
}

bool OnResizeFalse(Engine::WindowResizeEvent& e)
{
	return false;
}

