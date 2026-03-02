#include <stdio.h>

// This function takes an integer and returns it doubled
int doubleValue(int x) {
    return x * 2;
}

int main() {
    int original = 8;
    int doubled = doubleValue(original);

    printf("Original: %d\n", original);
    printf("Doubled: %d\n", doubled);
    printf("Doubling 15 gives: %d\n", doubleValue(15));

    return 0;
}
