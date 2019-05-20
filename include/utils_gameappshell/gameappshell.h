#pragma once
#ifndef UTILS_GAMEAPPSHELL_GAMEAPPSHELL_H
#define UTILS_GAMEAPPSHELL_GAMEAPPSHELL_H

#include "al2o3_platform/platform.h"
#include "utils_gameappshell/windowdesc.h"

// lifetime callbacks
typedef void (*GameAppShell_PerFrameUpdateFunc)(double deltaMS);
typedef void (*GameAppShell_PerFrameDrawFunc)(double deltaMS);
typedef bool (*GameAppShell_InitFunc)();
typedef bool (*GameAppShell_DisplayLoadFunc)();
typedef void (*GameAppShell_DisplayUnloadFunc)();
typedef void (*GameAppShell_ExitFunc)();
typedef void (*GameAppShell_AbortFunc)();

// the shell will call these function if not null at various times
// in the lifetime of the app
typedef struct GameAppShell_Shell {

	GameAppShell_InitFunc onInitCallback;
	GameAppShell_DisplayLoadFunc onDisplayLoadCallback;
	GameAppShell_DisplayUnloadFunc onDisplayUnloadCallback;
	GameAppShell_ExitFunc onQuitCallback; 	// intended exit of app
	GameAppShell_AbortFunc onAbortCallback; // emergency exit of app

	GameAppShell_PerFrameUpdateFunc perFrameUpdateCallback;
	GameAppShell_PerFrameDrawFunc perFrameDrawCallback;

	GameAppShell_WindowDesc initialWindowDesc;
} GameAppShell_Shell;


// call GameAppShell_Init() from mainand fill in any callbacks you want to recieve
// then call MainLoop and callbacks will occur, MainLoop will return when the app
// should exit
AL2O3_EXTERN_C GameAppShell_Shell *GameAppShell_Init();
AL2O3_EXTERN_C int GameAppShell_MainLoop(int argc, char const *argv[]);

// if you want to quit the app
AL2O3_EXTERN_C void GameAppShell_Quit();

#endif //UTILS_GAMEAPPSHELL_GAMEAPPSHELL_H
