#include <stdio.h>
#include "dron.h"
#include "field.h"
#include <curses.h>

void initDrone(Drone *drone, Field *field)
{
    drone->x = 0;
    drone->y = 0;
    drone->directionX = 1;
    drone->directionY = 0;
    drone->cart.length = 0; // Изначально тележек нет
}

void displayDrone(Drone *drone)
{
    mvaddch(drone->y, drone->x, 'D'); // 'D' для дрона
}

void updateDronePosition(Drone *drone, int key)
{
    drone->x += drone->directionX;
    drone->y += drone->directionY;
    if (key == 'w')
    { // Вверх
        drone->directionX = 0;
        drone->directionY = -1;
    }
    else if (key == 's')
    { // Вниз
        drone->directionX = 0;
        drone->directionY = 1;
    }
    else if (key == 'a')
    { // Влево
        drone->directionX = -1;
        drone->directionY = 0;
    }
    else if (key == 'd')
    { // Вправо
        drone->directionX = 1;
        drone->directionY = 0;
    }
}

// Функция для увеличения длины цепочки тележек
void addCart(Drone *drone)
{
    drone->cart.length++; // Увеличиваем количество тележек
}

// Функция для вывода текущего уровня собранных тыкв
void printLevel(Drone *drone)
{
    printw("Current cart length: %d\n", drone->cart.length);
}

// Функция для проверки столкновения с хвостом
int isCrash(Drone *drone)
{
   
    return 0;
}
