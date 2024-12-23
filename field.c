#include <stdlib.h>
#include <stdio.h>
#include "field.h"
#include "dron.h"
#include <curses.h>

// Генерация новой тыквы
void spawnNewPumpkin(Field *field)
{
    if (field->pumpkinCount < MAX_PUMPKINS)
    {
        // Генерация случайной тыквы в пределах поля
        int x = rand() % MAX_X;
        int y = rand() % MAX_Y;

        // Добавляем новую тыкву в список
        field->pumpkins[field->pumpkinCount] = (Position){x, y};
        field->pumpkinCount++;
    }
}

// Инициализация поля с тыквами
void initField(Field *field)
{
    field->pumpkinCount = 5;
    field->pumpkins[0] = (Position){1, 1};
    field->pumpkins[1] = (Position){5, 2};
    field->pumpkins[2] = (Position){7, 6};
    field->pumpkins[3] = (Position){1, 4};
    field->pumpkins[4] = (Position){2, 3};
}

// Отображение поля
void displayField(Field *field)
{
    clear(); // Очистить экран
    for (int y = 0; y < MAX_Y; y++)
    {
        for (int x = 0; x < MAX_X; x++)
        {
            int isPumpkin = 0;
            for (int i = 0; i < field->pumpkinCount; i++)
            {
                if (field->pumpkins[i].x == x && field->pumpkins[i].y == y)
                {
                    isPumpkin = 1;
                    break;
                }
            }
            if (isPumpkin)
            {
                mvaddch(y, x, '*'); // Выводим тыкву
            }
            else
            {
                mvaddch(y, x, '.'); // Пустое место
            }
        }
    }
    refresh(); // Обновляем экран
}

// Сбор тыквы дронов
void collectPumpkins(Drone *drone, Field *field)
{
    for (int i = 0; i < field->pumpkinCount; i++)
    {
        if (field->pumpkins[i].x == drone->x && field->pumpkins[i].y == drone->y)
        {
            // Дрон собрал тыкву
            field->pumpkins[i].x = -1; // Убираем тыкву с поля
            field->pumpkins[i].y = -1;
            drone->cart.positions[drone->cart.length] = (Position){drone->x, drone->y}; // Добавляем тыкву в тележку
            drone->cart.length++;                                                       // Увеличиваем длину цепочки

            // Генерируем новую тыкву
            spawnNewPumpkin(field);
            break;
        }
    }
}
