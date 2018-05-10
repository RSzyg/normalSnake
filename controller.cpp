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
        Game();
    // }

    endwin();

    ShowCursor();
}

void Controller::Game() {
    nodelay(stdscr, TRUE);
    Snake *nsnake = new Snake();
    nsnake->Init();
    while (nsnake->Head().getX() < 24 && nsnake->Head().getY() < 44) {
        int ch = getch();
        move(0, 50);
        printw("%d", ch);
        switch (ch) {
            case KEY_UP:
                nsnake->ChangeDirection(ch);
                break;
            case KEY_DOWN:
                nsnake->ChangeDirection(ch);
                break;
            case KEY_RIGHT:
                nsnake->ChangeDirection(ch);
                break;
            case KEY_LEFT:
                nsnake->ChangeDirection(ch);
                break;
            case 27:
                return;
            case ERR:
                break;
        }
        nsnake->Move();
        sleep_for(milliseconds(speed));
    }
    delete nsnake;
}