#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_OPERATIONS 100

// Function to apply operations and find the original number
long long apply_operations(int final_number, char operations[MAX_OPERATIONS][10], int num_operations) {
    long long candidate = 1;

    for (int i = 0; i < num_operations; i++) {
        char operator;
        int value;
        sscanf(operations[i], "X %c %d", &operator, &value);

        switch (operator) {
            case '+':
                candidate += value;
                break;
            case '-':
                candidate -= value;
                break;
            case '*':
                candidate *= value;
                break;
            case '/':
                if (value == 0)
                    return -1;
                if (candidate % value != 0)
                    return -2;
                candidate /= value;
                break;
            case '^':
                candidate = pow(candidate, value);
                break;
            case '%':
                if (value == 0)
                    return -1;
                candidate %= value;
                break;
        }
    }

    if (candidate == final_number)
        return candidate;
    else
        return -2;
}

int main() {
    int final_number;
    char operations[MAX_OPERATIONS][10];
    int num_operations;

    // Input final number
    printf("Enter the final number: ");
    scanf("%d", &final_number);

    // Input operations
    printf("Enter the number of operations: ");
    scanf("%d", &num_operations);

    printf("Enter the operations in the format 'X OPERATOR VALUE', separated by spaces:\n");
    for (int i = 0; i < num_operations; i++) {
        scanf("%s", operations[i]);
    }

    // Apply operations and find the original number
    long long result = apply_operations(final_number, operations, num_operations);

    // Output result
    if (result == -1)
        printf("Output: -1 (Invalid operation)\n");
    else if (result == -2)
        printf("Output: -2 (Multiple possible answers)\n");
    else
        printf("Output: %lld\n", result);

    return 0;
}
