#include <stdio.h>
#include <stdlib.h>

// Function to factorize numbers
void factorize(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[100];
    while (fgets(line, sizeof(line), file)) {
        int number = atoi(line);
        if (number % 2 == 0) {
            printf("%d=%d*%d\n", number, number / 2, 2);
            continue;
        }
        int i = 3;
        while (i < number / 2) {
            if (number % i == 0) {
                printf("%d=%d*%d\n", number, number / i, i);
                break;
            }
            i += 2;
        }
        if (i == (number / 2) + 1) {
            printf("%d=%d*%d\n", number, number, 1);
        }
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    factorize(argv[1]);

    return EXIT_SUCCESS;
}

