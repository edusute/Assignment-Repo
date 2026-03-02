#include <stdio.h>

float fahrenheitToCelsius(float f) {
    return (f - 32) * 5.0 / 9.0;
}

int main() {
    printf("%.2f F = %.2f C\n", 32.0, fahrenheitToCelsius(32.0));
    printf("%.2f F = %.2f C\n", 212.0, fahrenheitToCelsius(212.0));
    printf("%.2f F = %.2f C\n", 72.0, fahrenheitToCelsius(72.0));
    printf("%.2f F = %.2f C\n", 98.6, fahrenheitToCelsius(98.6));

    return 0;
}
