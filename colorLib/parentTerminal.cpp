#include "parentTerminal.h"
#include <cstdio>

bool ParentTerminal::printColor(HANDLE hConsole, COLORREF fg, const char* text) {
    // Extract RGB values from COLORREF
    int r = GetRValue(fg);
    int g = GetGValue(fg);
    int b = GetBValue(fg);

    // Enable Virtual Terminal Processing for ANSI escape codes
    DWORD mode = 0;
    GetConsoleMode(hConsole, &mode);
    SetConsoleMode(hConsole, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);

    // Print ANSI escape code for true color foreground
    printf("\x1b[38;2;%d;%d;%dm%s\x1b[0m", r, g, b, text);

    return true;
}

