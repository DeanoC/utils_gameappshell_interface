#pragma once
#ifndef UTILS_GAMEAPPSHELL_WINDOW_H
#define UTILS_GAMEAPPSHELL_WINDOW_H

#include "al2o3_platform/platform.h"

typedef void *GameAppShell_IconHandle;

typedef struct GameAppShell_WindowDesc {
  char const* name;
  int32_t width;
  int32_t height;
  uint32_t windowsFlags;
	GameAppShell_IconHandle bigIcon;
	GameAppShell_IconHandle smallIcon;

  bool fullScreen;
  bool iconified;
  bool maximized;
  bool minimized;
  bool visible;

  float dpiBackingScale[2];

} GameAppShell_WindowDesc;

AL2O3_EXTERN_C void GameAppShell_WindowGetCurrentDesc(GameAppShell_WindowDesc* desc);
// HWND or NSWindow* or similar
AL2O3_EXTERN_C void* GameAppShell_GetPlatformWindowPtr();

#endif //UTILS_GAMEAPPSHELL_WINDOW_H
