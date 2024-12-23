#ifndef FIELD_H
#define FIELD_H

#include <stdio.h>

#define MAX_X 20
#define MAX_Y 10
#define MAX_PUMPKINS 10

typedef struct
{
    int x, y; // Координаты
} Position;

// Предварительное объявление структуры Drone
struct Drone;

typedef struct
{
    Position pumpkins[MAX_PUMPKINS]; // Массив тыкв
    int pumpkinCount;                // Количество тыкв
} Field;

// Функции для работы с полем
void initField(Field *field);
void displayField(Field *field);
void collectPumpkins(struct Drone *drone, Field *field); // Теперь корректно

#endif
