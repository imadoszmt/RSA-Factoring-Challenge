#include <stdio.h>
#include <stdlib.h>

void factorize(int value) {
    int i = 2;
    
    if (value < 2)
        return;
    
    while (value % i)
        i++;
    
    printf("%.0f=%.0f*%.0f\n", (float)value, (float)value / i, (float)i);
}

int main(int argc, char *argv[]) {
    if (argc != 2)
        exit(EXIT_FAILURE);
    
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    
    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        int value = atoi(line);
        factorize(value);
    }
    
    fclose(file);
    return 0;
}

