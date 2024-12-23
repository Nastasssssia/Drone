#include "autopilot.h"
#include "dron.h"
#include <stdlib.h>

void autopilot(Drone *drone, Field *field)
{
    int closestPumpkin = -1;
    int minDistance = MAX_X + MAX_Y;

    // Находим ближайшую тыкву
    for (int i = 0; i < field->pumpkinCount; i++)
    {
        int distX = abs(field->pumpkins[i].x - drone->x);
        int distY = abs(field->pumpkins[i].y - drone->y);
        int distance = distX + distY; // Манхэттенское расстояние

        if (distance < minDistance)
        {
            minDistance = distance;
            closestPumpkin = i;
        }
    }

    if (closestPumpkin != -1)
    {
        int targetX = field->pumpkins[closestPumpkin].x;
        int targetY = field->pumpkins[closestPumpkin].y;

        // Двигаем дрон в сторону ближайшей тыквы
        if (drone->x < targetX)
            drone->x++;
        else if (drone->x > targetX)
            drone->x--;

        if (drone->y < targetY)
            drone->y++;
        else if (drone->y > targetY)
            drone->y--;
    }
}
