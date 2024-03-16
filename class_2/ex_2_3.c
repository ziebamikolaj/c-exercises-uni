#include <stdio.h>

typedef struct {
    int x;
    int y;
} Point;

void changeCoordinates(Point* point, int newX, int newY) {
    point->x = newX;
    point->y = newY;
}

typedef struct {
    Point topLeft;
    Point bottomRight;
} Rectangle;

void calculateRectangle(Rectangle rectangle) {
    int width = rectangle.bottomRight.x - rectangle.topLeft.x;
    int height = rectangle.bottomRight.y - rectangle.topLeft.y;
    int area = width * height;
    int perimeter = 2 * (width + height);

    printf("Pole prostokata: %d\n", area);
    printf("Obwod prostokata: %d\n", perimeter);
}

int main() {
    Point point;
    point.x = 3;
    point.y = 5;

    changeCoordinates(&point, 7, 9);

    printf("Wspolrzedne punktu: (%d, %d)\n", point.x, point.y);

    Rectangle rectangle;
    rectangle.topLeft.x = 2;
    rectangle.topLeft.y = 4;
    rectangle.bottomRight.x = 8;
    rectangle.bottomRight.y = 6;

    calculateRectangle(rectangle);

    return 0;
}