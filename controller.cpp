#include "controller.h"
#include "tools.h"
#include "point.h"
#include "locale.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <ncurses.h>
using std::cout;
using std::cin;
using std::endl;
using std::this_thread::sleep_for;
using std::chrono::milliseconds;

void Controller::Start() {
    system("clear");
	addstr("    ■ ■ ■      ■           ■          ■          ■       ■    ■ ■ ■ ■ ■  \n");
	addstr("  ■       ■    ■ ■         ■         ■ ■         ■     ■      ■          \n");
	addstr("    ■          ■   ■       ■        ■   ■        ■   ■        ■          \n");
	addstr("      ■        ■     ■     ■       ■ ■ ■ ■       ■ ■          ■ ■ ■ ■ ■  \n");
	addstr("        ■      ■       ■   ■      ■       ■      ■   ■        ■          \n");
	addstr("  ■       ■    ■         ■ ■     ■         ■     ■     ■      ■          \n");
	addstr("    ■ ■ ■      ■           ■    ■           ■    ■       ■    ■ ■ ■ ■ ■  \n");
    refresh();
}

void Controller::CreateScene() {
    system("clear");
}

void Controller::Select() {
    system("clear");
}

void Controller::Main() {
    HideCursor();
    setlocale(LC_ALL, "");
    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();

    Start();
    sleep_for(milliseconds(5000));
    // while (true) {
        Select();
        CreateScene();
    // }

    Point *p1 = new Point(5, 10);
    Point *p2 = new Point(8, 16);
    p1->Block();
    p2->Circle();

    sleep_for(milliseconds(5000));

    endwin();

    ShowCursor();
}