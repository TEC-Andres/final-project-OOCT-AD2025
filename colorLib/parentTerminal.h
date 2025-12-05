#ifndef PARENTTERMINAL_H
#define PARENTTERMINAL_H

#include <windows.h>

#define HEX(r,g,b) ((COLORREF)(((BYTE)(r)|((WORD)((BYTE)(g))<<8))|(((DWORD)(BYTE)(b))<<16)))

class ParentTerminal {
public:
    bool printColor(HANDLE hConsole, COLORREF fg, const char* text, ...);
};

#endif // PARENTTERMINAL_H