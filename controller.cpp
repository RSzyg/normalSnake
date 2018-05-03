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
	printw("    ■ ■ ■      ■           ■          ■          ■       ■    ■ ■ ■ ■ ■  ");
	printw("  ■       ■    ■ ■         ■         ■ ■         ■     ■      ■          ");
	printw("    ■          ■   ■       ■        ■   ■        ■   ■        ■          ");
	printw("      ■        ■     ■     ■       ■ ■ ■ ■       ■ ■          ■ ■ ■ ■ ■  ");
	printw("        ■      ■       ■   ■      ■       ■      ■   ■        ■          ");
	printw("  ■       ■    ■         ■ ■     ■         ■     ■     ■      ■          ");
	printw("    ■ ■ ■      ■           ■    ■           ■    ■       ■    ■ ■ ■ ■ ■  ");
    refresh();
}

void Controller::CreateScene() {
    system("clear");
}

void Controller::Select() {
    system("clear");
    int ch;
    addstr("按任意键继续。。。");
    // system("clear");
    refresh();
    getch();
}

void Controller::Main() {
    setlocale(LC_CTYPE, "");
    initscr();
    HideCursor();

    Start();
    sleep_for(milliseconds(5000));
    while (true) {
        Select();
        CreateScene();
    }

    Point *p1 = new Point(5, 5);
    Point *p2 = new Point(8, 8);
    p1->Block();
    p2->Circle();

    sleep_for(milliseconds(5000));

    ShowCursor();
    system("stty echo");
}