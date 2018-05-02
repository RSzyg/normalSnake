#include "controller.h"
#include "tools.h"
#include <iostream>
#include <thread>
#include <chrono>
using std::cout;
using std::cin;
using std::endl;
using std::this_thread::sleep_for;
using std::chrono::milliseconds;

void Controller::Start() {
    system("clear");
	cout << "    ■ ■ ■      ■           ■          ■          ■       ■    ■ ■ ■ ■ ■  " << endl;
	cout << "  ■       ■    ■ ■         ■         ■ ■         ■     ■      ■          " << endl;
	cout << "    ■          ■   ■       ■        ■   ■        ■   ■        ■          " << endl;
	cout << "      ■        ■     ■     ■       ■ ■ ■ ■       ■ ■          ■ ■ ■ ■ ■  " << endl;
	cout << "        ■      ■       ■   ■      ■       ■      ■   ■        ■          " << endl;
	cout << "  ■       ■    ■         ■ ■     ■         ■     ■     ■      ■          " << endl;
	cout << "    ■ ■ ■      ■           ■    ■           ■    ■       ■    ■ ■ ■ ■ ■  " << endl;
}

void Controller::CreateScene() {
    system("clear");
}

void Controller::Select() {
    system("clear");
}

void Controller::Main() {
    system("stty -echo");
    HIDE_CURSOR();

    Start();
    sleep_for(milliseconds(5000));
    // while (true) {
        Select();
        CreateScene();
    // }

    sleep_for(milliseconds(5000));

    SHOW_CURSOR();
    system("stty echo");
}