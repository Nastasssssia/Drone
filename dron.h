#ifndef DRON_H
#define DRON_H

#include <stdio.h>
#include "field.h" // Включаем `field.h`

typedef struct Drone
{
    int x, y;                   // Позиция дрона
    int directionX, directionY; // Направление движения
    struct
    {
        Position positions[MAX_PUMPKINS]; // Позиции собранных тыкв
        int length;                       // Длина тележки
    } cart;                               // "Тележка" дрона
} Drone;

// Функции для работы с дроном
void initDrone(Drone *drone, Field *field);
void displayDrone(Drone *drone);
void updateDronePosition(Drone *drone, int key);

#endif
