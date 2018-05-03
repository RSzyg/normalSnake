#include "tools.h"
#include <cstdio>

void HideCursor() {
    printf("\033[?25l");
}

void ShowCursor() {
    printf("\033[?25h");
}

void SetCursorPos(int x, int y) {
    printf("\033[%d;%dH", (x), (y));
}