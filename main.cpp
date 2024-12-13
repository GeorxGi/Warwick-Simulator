#include <iostream>
#include <windows.h>

#pragma comment(lib, "Winmm.lib")

using namespace std;

void Player(LPCWSTR command) {
    mciSendString(command, NULL, 0, NULL);
}

int main()
{
    cout << "Warwick simulator\nR   - WARWICK TIME\nESC - NOT WARWICK TIME\nDEL - CLOSE APP\n\n";
    while (true) {
        if (GetAsyncKeyState('R') & 0x8000) {
            cout << "Playing\n";
            Player(L"play Animals.mp3");
        }

        else if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
            cout << "Stopping\n";
            Player(L"stop Animals.mp3");
        }

        else if (GetAsyncKeyState(VK_DELETE) & 0x8000) {
            cout << "Clossing\n";
            return 0;
        }
        Sleep(50);
    }
    return 0;
}