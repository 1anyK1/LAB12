#ifndef POINT_H_
#define POINT_H_

// Структура, описывающая точку в двумерной системе координат
typedef struct {
    int x;
    int y;
} Point;

// Функция для определения параллельности прямой оси ординат
int isParallelToYAxis(Point p1, Point p2);

// Функция для определения параллельности прямой оси абсцисс
int isParallelToXAxis(Point p1, Point p2);

#endif