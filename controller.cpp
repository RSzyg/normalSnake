#include "controller.h"
#include "tools.h"
#include "point.h"
#include "snake.h"
#include "locale.h"
#include "food.h"
#include "map.h"
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

void Controller::CreateScene(Map *nmap) {
	system("clear");
	nmap->PrintMap();
	mvprintw(10, 50, "yeyeye");
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

	delwin(simple);
	delwin(hard);
	delwin(extreme);
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

	Map *nmap = new Map();

	Start();
	// while (true) {
		if(has_colors() == FALSE) {
			mvprintw(5, 60, "hhhhhh");
		}
		Select();
		CreateScene(nmap);
		Game(nmap);
	// }

	endwin();

	ShowCursor();
}

void Controller::Game(Map *nmap) {
	WINDOW* menu;
	menu = newwin(10, 20, 8, 20);

	nodelay(stdscr, TRUE);
	Snake *nsnake = new Snake();
	nsnake->Init();

	Food *nfood = new Food();
	nfood->RandomNum(nsnake);

	while (nsnake->HitEdge() && nsnake->HitSelf()) {
		int ch = getch();
		int temp = 0;
		int count = 0;
		move(1, 50);
		printw("%d", ch);
		refresh();
		while (count < 20) {
			temp = nsnake->ChangeDirection(ch);
			if (temp == 0) {
				Menu(menu);
				CreateScene(nmap);
				nsnake->Init();
				nfood->PrintApple();
				sleep_for(milliseconds(200));
				break;
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

void Controller::Menu(WINDOW *menu) {
	system("clear");
	nodelay(stdscr, FALSE);
	box(menu, 0 , 0);
	mvwprintw(menu, 0, 0, "hahahahaha");
	wrefresh(menu);
	getch();
	delwin(menu);
	nodelay(stdscr, TRUE);
}