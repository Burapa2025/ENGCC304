#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int play;
    srand(time(NULL));
    printf("Do you want to play game (1=play, -1=exit): ");
    if (scanf("%d", &play) != 1 || (play != 1 && play != -1)) {
        printf("Please enter only 1 or -1.\n");
        return 0;
    }
    while (play == 1) {
        int score = 100;
        int num = rand() % 100 + 1;
        int guess;

        printf("You have 100 points.\n");

        while (1) {
            printf("Enter your guess (1-100): ");
            if (scanf("%d", &guess) != 1) {
                printf("Please enter a valid number.\n");
                while(getchar() != '\n');
                continue;
            }
            if (guess < 1 || guess > 100) {
                printf("Please enter a number between 1 and 100.\n");
                continue;
            }
            if (guess == num) {
                printf("Congratulations! You guessed correctly.\n");
                printf("Your score: %d\n", score);
                break;
            } else {
                score -= 10;
                if (score <= 0) {
                    printf("Game Over! Your score is 0.\n");
                    printf("The winning number was: %d\n", num);
                    break;
                }
                if (guess < num) {
                    printf("The winning number is Higher than your guess. Your score: %d\n", score);
                } else {
                    printf("The winning number is Lower than your guess. Your score: %d\n", score);
                }
            }
        }
        printf("Do you want to play game (1=play, -1=exit): ");
        if (scanf("%d", &play) != 1 || (play != 1 && play != -1)) {
            printf("Please enter only 1 or -1.\n");
            break;
        }
    }
    printf("See you again.\n");
    return 0;
}