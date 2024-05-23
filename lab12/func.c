#include "head.h"

// Функция для определения параллельности прямой оси ординат
int isParallelToYAxis(Point p1, Point p2) {
    return p1.x == p2.x;
}

// Функция для определения параллельности прямой оси абсцисс
int isParallelToXAxis(Point p1, Point p2) {
    return p1.y == p2.y;
}