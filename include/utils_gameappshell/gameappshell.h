#pragma once
#ifndef UTILS_GAMEAPPSHELL_GAMEAPPSHELL_H
#define UTILS_GAMEAPPSHELL_GAMEAPPSHELL_H

#include "al2o3_platform/platform.h"
#include "utils_gameappshell/windowdesc.h"

// lifetime callbacks
typedef void (*GameAppShell_PerFrameUpdateFunc)(double deltaMS);
typedef void (*GameAppShell_PerFrameDrawFunc)(double deltaMS);
typedef bool (*GameAppShell_InitFunc)();
typedef bool (*GameAppShell_DisplayResizeFunc)();
typedef void (*GameAppShell_ExitFunc)();
typedef void (*GameAppShell_AbortFunc)();

// allow the app to respond to platform specific message
// on Windows MSG* from the windows loop
typedef void (*GameAppShell_PlatformProcessMsg)(void* msg);

// the shell will call these function if not null at various times
// in the lifetime of the app
typedef struct GameAppShell_Shell {

	GameAppShell_InitFunc onInitCallback;
	GameAppShell_DisplayResizeFunc onDisplayResizeCallback;
	GameAppShell_ExitFunc onQuitCallback; 	// intended exit of app
	GameAppShell_AbortFunc onAbortCallback; // emergency exit of app

	GameAppShell_PerFrameUpdateFunc perFrameUpdateCallback;
	GameAppShell_PerFrameDrawFunc perFrameDrawCallback;

	GameAppShell_PlatformProcessMsg onMsgCallback;

	GameAppShell_WindowDesc initialWindowDesc;
} GameAppShell_Shell;


// call GameAppShell_Init() from main and fill in any callbacks you want to recieve
// then call MainLoop and callbacks will occur, MainLoop will never return on some
// platforms. Exit callback should be used to set return values etc.
AL2O3_EXTERN_C GameAppShell_Shell *GameAppShell_Init();
AL2O3_EXTERN_C void GameAppShell_MainLoop(int argc, char const *argv[]);

// if you want to quit the app
AL2O3_EXTERN_C void GameAppShell_Quit();

#endif //UTILS_GAMEAPPSHELL_GAMEAPPSHELL_H
