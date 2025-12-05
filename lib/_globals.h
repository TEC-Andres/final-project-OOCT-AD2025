#pragma once
#include <windows.h>
#include "../colorLib/parentTerminal.h"

// Declare global handles/objects as extern to avoid multiple-definition
extern HANDLE hConsole;
extern ParentTerminal terminal;