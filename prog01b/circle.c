#include <stdio.h>

float circleArea(float radius) {
    float pi = 3.14159;
    return pi * radius * radius;
}

void printCircleInfo(float radius) {
    float area = circleArea(radius);
    printf("Circle with radius %.1f has area %.2f\n", radius, area);
}

int main() {
    printCircleInfo(5.0);
    printCircleInfo(10.0);
    printCircleInfo(2.5);

    return 0;
}
