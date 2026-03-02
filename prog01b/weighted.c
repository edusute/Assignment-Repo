#include <stdio.h>

float weightedAverage(float score1, float weight1, float score2, float weight2, float score3, float weight3) {
    return (score1 * weight1) + (score2 * weight2) + (score3 * weight3);
}

int main() {
    float homework = 85.0;
    float homeworkWeight = 0.40;
    float midterm = 78.0;
    float midtermWeight = 0.25;
    float finalExam = 92.0;
    float finalWeight = 0.35;

    float hwResult = homework * homeworkWeight;
    float mtResult = midterm * midtermWeight;
    float feResult = finalExam * finalWeight;

    printf("Homework:   %.2f x %.2f = %.2f\n", homework, homeworkWeight, hwResult);
    printf("Midterm:    %.2f x %.2f = %.2f\n", midterm, midtermWeight, mtResult);
    printf("Final Exam: %.2f x %.2f = %.2f\n", finalExam, finalWeight, feResult);
    printf("Final Grade: %.2f\n", weightedAverage(homework, homeworkWeight, midterm, midtermWeight, finalExam, finalWeight));

    return 0;
}
