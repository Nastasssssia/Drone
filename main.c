#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include "field.h"
#include "dron.h"
#include "autopilot.h"

#ifdef _WIN32
#include <windows.h> // Для использования Sleep на Windows
#else
#include <unistd.h> // Для использования sleep на Unix-подобных системах
#endif

int main()
{
    // Инициализация ncurses
    initscr();
    timeout(100); // 100 миллисекунд на обновление экрана
    cbreak();     // Отключаем буферизацию ввода
    noecho();     // Отключаем отображение ввода

    // Инициализация поля
    Field field;
    initField(&field);

    // Инициализация дронов
    Drone drone;
    initDrone(&drone, &field);

    // Главный игровой цикл
    while (1)
    {
        // Отображение поля и дрона
        displayField(&field);
        displayDrone(&drone);

        // Управление дронов с клавишами
        int ch = getch(); // Получаем ввод
        if (ch == 'q')
            break; // Выход из игры при нажатии 'q'

        // Обновление позиции дрона с учётом новой клавиши
        updateDronePosition(&drone, ch); // Передаем клавишу в функцию обновления позиции

        // Сбор тыкв, если дрон находит тыкву
        collectPumpkins(&drone, &field);

        // Включаем автопилот, если нужно (например, если не нажата клавиша)
        autopilot(&drone, &field);

        // Обновляем экран
        refresh(); // Обновление экрана ncurses

        // Задержка (для имитации времени)
#ifdef _WIN32
        Sleep(100); // Windows, время в миллисекундах
#else
        sleep(1); // Unix-подобные системы, время в секундах
#endif
    }

    // Завершение работы ncurses
    endwin();

    return 0;
}