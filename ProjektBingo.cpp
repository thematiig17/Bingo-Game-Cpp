#include <iostream>
#include <windows.h>
#include "Header.h"

using namespace std;

int main()
{
    //start programu
    setlocale(LC_ALL, "en_US.UTF-8");
    SetConsoleOutputCP(CP_UTF8);
    enableVirtualTerminalProcessing();
    menuGlowne();
    cout << "Zakonczono" << endl;
    system("pause");
}
