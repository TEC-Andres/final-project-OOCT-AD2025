#pragma once
#include <windows.h>
#include "../colorLib/parentTerminal.h"


HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
ParentTerminal terminal;