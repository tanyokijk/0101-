#define _CRT_SECURE_NO_WARNINGS 1 // Вимкнути попередження про застарілість

#include <iostream>
#include <windows.h>
#include <chrono>
#include <ctime>
#include <thread>

void updateNotepadWindowTitle(const std::string& newTitle)
{
    HWND notepadWindow = FindWindowA("Notepad", NULL);
    SetWindowTextA(notepadWindow, newTitle.c_str());
}

int main()
{
    system("chcp 1251>nul");
    std::cout << "Для закінчення програми закрийте її вікно";

    auto startTime = std::chrono::high_resolution_clock::now();

    while (true)
    {
        auto now = std::chrono::high_resolution_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - startTime);
        int hours = elapsed.count() / 3600;
        int minutes = (elapsed.count() % 3600) / 60;
        int seconds = elapsed.count() % 60;

        std::string timeString = "Блокнот " + std::to_string(hours) + "г " + std::to_string(minutes) + "хв " + std::to_string(seconds) + "с";
        updateNotepadWindowTitle(timeString);
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
