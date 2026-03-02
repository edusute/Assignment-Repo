#include <stdio.h>

char getGrade(int score) {
    if (score >= 90) {
        return 'A';
    } else if (score >= 80) {
        return 'B';
    } else if (score >= 70) {
        return 'C';
    } else if (score >= 60) {
        return 'D';
    } else {
        return 'F';
    }
}

int main() {
    printf("Score: 95 -> Grade: %c\n", getGrade(95));
    printf("Score: 82 -> Grade: %c\n", getGrade(82));
    printf("Score: 74 -> Grade: %c\n", getGrade(74));
    printf("Score: 61 -> Grade: %c\n", getGrade(61));
    printf("Score: 45 -> Grade: %c\n", getGrade(45));

    return 0;
}
