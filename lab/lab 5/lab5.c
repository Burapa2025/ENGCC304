#include <stdio.h>

int main() {
    int Grade;

    // รับข้อมูลเกรด
    printf("enter score : \n");
    if (scanf("%d", &Grade) != 1) {
        printf("please enter number only.\n");
    return 0;
    }

    // ตรวจสอบเกรด
    if (Grade >= 80) {
        printf("Grade = A \n");
    } else if (Grade >= 75) {
        printf("Grade = B+ \n");
    } else if (Grade >= 70) {
        printf("Grade = B \n");
    } else if (Grade >= 65) {
        printf("Grade = C+ \n");
    } else if (Grade >= 60) {
        printf("Grade = C \n");
    } else if (Grade >= 55) {
        printf("Grade = D+ \n");
    } else if (Grade >= 50) {
        printf("Grade = D \n");
    } else if (Grade < 50) {
        printf("Grade = F \n");
    }
    return 0;
}