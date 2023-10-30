 /*IMPLEMENT THE OPERATIONS OF CIRCULAR QUEUE IN AN STRING ARRAY (INSERT, DELETE, PEEK, ISEMPTY, ISFULL)*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50
#define STR_LEN 100

void enqueue(char arr[], int size, const char value[], int *i, int *j) {
    if (((*i + 1) % size) == *j) {
        printf("Full\n");
        return;
    } else {
        if (*j == -1) {
            *j = 0;
        }
        *i = (*i + 1) % size;
        int index = *i * STR_LEN;
        for (int k = 0; value[k] != '\0'; k++) {
            arr[index + k] = value[k];
        }
        arr[index + STR_LEN - 1] = '\0'; // Ensure null-terminated string
    }
}

void dequeue(char arr[], int size, int *i, int *j) {
    if (*i == -1 && *j == -1) {
        printf("Empty\n");
        return;
    } else {
        if (*i == *j) {
            *i = *j = -1;
            printf("i & j is on -1\n");
        } else {
            *j = (*j + 1) % size;
        }
    }
}

void display(char arr[], int size, int i, int j) {
    int k;
    if (i == -1 && j == -1) {
        printf("Empty\n");
        return;
    } else {
        k = j;
        while (k != i) {
            int index = k * STR_LEN;
            for (int l = 0; arr[index + l] != '\0'; l++) {
                printf("%c", arr[index + l]);
            }
            printf("->");
            k = (k + 1) % size;
        }
        int index = i * STR_LEN;
        for (int l = 0; arr[index + l] != '\0'; l++) {
            printf("%c", arr[index + l]);
        }
        printf("\n");
    }
}

int main() {
    char arr[MAX_SIZE * STR_LEN];
    int ch, size = MAX_SIZE;
    int i = -1, j = -1;
    char value[STR_LEN];

    printf("\nPress 1: Insert");
    printf("\nPress 2: Delete");
    printf("\nPress 3: Display");
    printf("\nPress 4: Exit the code");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\nEnter value to insert: ");
                scanf("%s", value);
                enqueue(arr, size, value, &i, &j);
                break;

            case 2:
                dequeue(arr, size, &i, &j);
                break;

            case 3:
                display(arr, size, i, j);
                break;

            case 4:
                printf("**Code has been terminated**\n");
                exit(0);
                break;

            default:
                printf("\nInvalid choice\n");
        }
    }

    return 0;
}
