#include <stdio.h>

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int main() {
    printf("max(7, 3) = %d\n", max(7, 3));
    printf("max(2, 9) = %d\n", max(2, 9));
    printf("max(-5, -1) = %d\n", max(-5, -1));
    printf("max(4, 4) = %d\n", max(4, 4));

    return 0;
}
