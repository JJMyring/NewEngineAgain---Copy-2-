/** \file entryPoint.h

\mainpage

This is the build of the IMAT3904 engine for use in IMAT3905.
You have all the header files and the associated libary file.
No source (.cpp) file have been supplied outside of the sandbox and enginetest projects.
*/
#pragma once

#include "core/application.h"

extern Engine::Application* Engine::startApplication();

int main(int argc, char** argv)
{
	auto application = Engine::startApplication();
	application->run();
	delete application;

	return 0;
}

