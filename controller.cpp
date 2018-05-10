#include "controller.h"
#include "tools.h"
#include "point.h"
#include "snake.h"
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
	printw("    ■ ■ ■      ■           ■          ■          ■       ■    ■ ■ ■ ■ ■  \n");
	printw("  ■       ■    ■ ■         ■         ■ ■         ■     ■      ■          \n");
	printw("    ■          ■   ■       ■        ■   ■        ■   ■        ■          \n");
	printw("      ■        ■     ■     ■       ■ ■ ■ ■       ■ ■          ■ ■ ■ ■ ■  \n");
	printw("        ■      ■       ■   ■      ■       ■      ■   ■        ■          \n");
	printw("  ■       ■    ■         ■ ■     ■         ■     ■     ■      ■          \n");
	printw("    ■ ■ ■      ■           ■    ■           ■    ■       ■    ■ ■ ■ ■ ■  \n");
    printw("按任意键继续。。。");
    refresh();
    getch();
}

void Controller::CreateScene() {
    system("clear");

    for (int i = 0; i < 24; i++) {
        Point *p = new Point(0, i * 2);
        p->Block();
    }
    for (int i = 1; i < 24; i++) {
        Point *p = new Point(i, 0);
        p->Block();
    }
    for (int i = 1; i < 24; i++) {
        Point *p = new Point(23, i * 2);
        p->Block();
    }
    for (int i = 1; i < 23; i++) {
        Point *p = new Point(i, 46);
        p->Block();
    }
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
    // while (true) {
        Select();
        CreateScene();
    // }

    Snake *nsnake = new Snake();
    nsnake->Init();

    sleep_for(milliseconds(5000));

    nsnake->Move();

    sleep_for(milliseconds(5000));

    endwin();

    ShowCursor();
}