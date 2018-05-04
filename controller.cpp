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
    refresh();
}

void Controller::CreateScene() {
    system("clear");

    Point *p1 = new Point(1, 1);
    Point *p2 = new Point(1, 3);
    Point *p3 = new Point(1, 5);
    p1->Block();
    p2->Block();
    p3->Block();
}

void Controller::Select() {
    system("clear");

    printw("按任意键继续。。。");
    refresh();
    getch();
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

    Snake *nsnake = new Snake();
    nsnake->Init();

    sleep_for(milliseconds(5000));

    nsnake->Move();

    sleep_for(milliseconds(5000));

    endwin();

    ShowCursor();
}