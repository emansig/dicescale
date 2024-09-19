#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int rollDice() {
    // Generate a random number between 1 and 6
    return (rand() % 6) + 1;
}

void scaleRoll(int rolls) {
    // Create semitone counter
    int semitone = 0;

    // Seed the random number generator with the current time to the power of the pid
    srand(time(NULL) ^ getpid());

    printf("\n");

    for (int i = 0; i < rolls; i++) {
        int result = rollDice();
        semitone += result;
        printf("Roll %d: You rolled: %d\tDistance from A in semitones: %d\n", i + 1, result, semitone);
    }
}

int main() {
    printf("emanuel's semi-automated dice scale maker, version 0.2\n");

    int rolls;
    char reroll;

    do {
        // Ask the user how many rolls they want
        printf("Enter the number of steps you want: ");
        scanf("%d", &rolls);

        // Validate input
        if (rolls <= 0) {
            printf("Please enter a positive number of rolls.\n");
            continue; // Skip to the next iteration if input is invalid
        }

        // Create the scale
        scaleRoll(rolls);

        // Ask if the user wants to reroll
        printf("Do you want to reroll? (y/n): ");
        scanf(" %c", &reroll); // Note the space before %c to consume any leftover newline character

    } while (reroll == 'y' || reroll == 'Y');

    printf("now this is generative music\n");

    return 0;
}
