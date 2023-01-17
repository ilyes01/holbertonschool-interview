#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isDigitsOnly(char* num); // function prototype

int main(int argc, char* argv[]) {
    // Check if the number of arguments is incorrect
    if (argc != 3) {
        printf("Error\n");
        return 98;
    }

    // Check if num1 and num2 are composed of digits only
    if (!isDigitsOnly(argv[1]) || !isDigitsOnly(argv[2])) {
        printf("Error\n");
        return 98;
    }

    // Convert the numbers from strings to int and multiply them
    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);
    int result = num1 * num2;

    // Print the result followed by a new line
    printf("%d\n", result);

    return 0;
}

/*
 * Function: isDigitsOnly
 * ----------------------------
 *   Check if the given string contains only digits
 *
 *   num: string to check
 *
 *   returns: 1 if the string contains only digits, 0 otherwise
 */
int isDigitsOnly(char* num) {
    for (int i = 0; i < strlen(num); i++) {
        if (!isdigit(num[i])) {
            return 0;
        }
    }
    return 1;
}
