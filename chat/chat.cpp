#include "chatman.h"
#include "dataman.h"
#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");
    ChatManager(new DataManager).AuthPage();
    return 0;
}
