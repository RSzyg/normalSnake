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
#include <stdlib.h>
#include <time.h>
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
	WINDOW *simple;
	WINDOW *hard;
	WINDOW *extreme;

	simple = newwin(1, 8, 12, 24);
	hard = newwin(1, 8, 12, 37);
	extreme = newwin(1, 8, 12, 50);

	mvprintw(8, 36, "请选择难度");

	wbkgd(simple, COLOR_PAIR(2));
	mvwprintw(simple, 0, 2, "简单");
	mvwprintw(hard, 0, 2, "困难");
	mvwprintw(extreme, 0, 2, "极难");

	wrefresh(simple);
	wrefresh(hard);
	wrefresh(extreme);

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
				speed = 200 - choose * 50;
				return;
		}
		switch (choose) {
			case 0:
				wbkgd(simple, COLOR_PAIR(2));
				wbkgd(hard, COLOR_PAIR(1));
				wbkgd(extreme, COLOR_PAIR(1));
				break;
			case 1:
				wbkgd(simple, COLOR_PAIR(1));
				wbkgd(hard, COLOR_PAIR(2));
				wbkgd(extreme, COLOR_PAIR(1));
				break;
			case 2:
				wbkgd(simple, COLOR_PAIR(1));
				wbkgd(hard, COLOR_PAIR(1));
				wbkgd(extreme, COLOR_PAIR(2));
				break;
			default:
				break;
		}
		wrefresh(simple);
		wrefresh(hard);
		wrefresh(extreme);
	}
}

void Controller::Main() {
	srand(time(0));
	HideCursor();
	setlocale(LC_ALL, "");
	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();

	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_WHITE, COLOR_CYAN);
	bkgd(COLOR_PAIR(1));

	Start();
	// while (true) {
		if(has_colors() == FALSE) {
			mvprintw(5, 60, "hhhhhh");
		}
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
	nfood->RandomNum(nsnake);

	while (nsnake->HitEdge() && nsnake->HitSelf()) {
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
		nsnake->Move(*nfood);
		sleep_for(milliseconds(speed));
	}
	delete nsnake;
	delete nfood;
}