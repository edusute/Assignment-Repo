#include <stdio.h>

int main() {
    // Integer division: both sides are int
    int a = 10;
    int b = 3;
    int intResult = a / b;
    printf("int / int: %d / %d = %d\n", a, b, intResult);

    // Float division: at least one side is float
    float c = 10.0;
    float d = 3.0;
    float floatResult = c / d;
    printf("float / float: %.1f / %.1f = %.4f\n", c, d, floatResult);

    // Mixed: casting int to float
    float castResult = (float)a / b;
    printf("(float)int / int: %d / %d = %.4f\n", a, b, castResult);

    // The WRONG way (common mistake)
    float wrongResult = a / b;  // Division happens as int FIRST, then becomes float
    printf("Wrong way: %d / %d = %.4f\n", a, b, wrongResult);

    return 0;
}
