#include <iostream>
#include "controller.h"
#include <stdlib.h>
#include <time.h>
#include <windows.h>
using namespace std;


int main() {
	SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));
    controller run;
    run.execute();
}