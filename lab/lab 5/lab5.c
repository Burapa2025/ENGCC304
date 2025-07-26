#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isNumber(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        if (!isdigit(str[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

int main() {
    int score = 0;
    char inputBuffer[100];

    while (1) {
        printf("Please enter your score: ");
        scanf("%s", inputBuffer);

        if (isNumber(inputBuffer)) {
            sscanf(inputBuffer, "%d", &score);
            break;
        } else {
            printf("please enter number only.\n");
        }
    }

    printf("Grade: ");
    if (score >= 80) {
        printf("A !\n");
    } else if (score >= 75) {
        printf("B+ !\n");
    } else if (score >= 70) {
        printf("B !\n");
    } else if (score >= 65) {
        printf("C+ !\n");
    } else if (score >= 60) {
        printf("C !\n");
    } else if (score >= 55) {
        printf("D+ !\n");
    } else if (score >= 50) {
        printf("D !\n");
    } else {
        printf("F !\n");
    }
    return 0;
}