#include "tools.h"
#include <cstdio>

void HIDE_CURSOR() {
    printf("\033[?25l");
}

void SHOW_CURSOR() {
    printf("\033[?25h");
}