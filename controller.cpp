#include "controller.h"
#include "tools.h"
#include "point.h"
#include "snake.h"
#include "locale.h"
#include "food.h"
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

	move(10, 20);
	printw("请选择难度");

	move(12, 16);
	printw("简单");

	move(12, 23);
	printw("困难");

	move(12, 30);
	printw("极难");

	int ch = 0;
	int choose = 0;
	while (ch = getch()) {
		switch (ch) {
			case KEY_RIGHT:
				if (choose < 2) {
					choose++;
				}
				break;
			case KEY_LEFT:
				if (choose > 0) {
					choose--;
				}
				break;
			case '\n':
				speed = 300 - choose * 100;
				return;
		}
	}
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

	Food *nfood = new Food();

	while (nsnake->Head().getX() < 22
		&& nsnake->Head().getX() > 1
		&& nsnake->Head().getY() < 44
		&& nsnake->Head().getY() > 2
	) {
		int ch = getch();
		int count = 0;
		int temp = 0;
		move(1, 50);
		printw("%d", ch);
		refresh();
		while (count < 20) {
			temp = nsnake->ChangeDirection(ch);
			if (temp == 0) {
				return;
			} else if (temp == 1) {
				ch = getch();
			} else{
				flushinp();
				break;
			}
			count++;
		}
		nsnake->Move();
		sleep_for(milliseconds(speed));
	}
	delete nsnake;
}