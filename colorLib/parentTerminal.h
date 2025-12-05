#ifndef PARENTTERMINAL_H
#define PARENTTERMINAL_H

#include <windows.h>

#define HEX(r,g,b) ((COLORREF)(((BYTE)(r)|((WORD)((BYTE)(g))<<8))|(((DWORD)(BYTE)(b))<<16)))

class ParentTerminal {
public:
    ParentTerminal();
    bool printColor(HANDLE hConsole, COLORREF fg, const char* text, ...);
    bool prettyDisplay(HANDLE hConsole, COLORREF fg, const char* labels[], const char* formats[], const void* values[], int count);
};

#endif // PARENTTERMINAL_H