#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) 
    {
        return EXIT_FAILURE;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) 
    {
        perror("fopen");
        return EXIT_FAILURE;
    }

    int num;

    while (fscanf(fp, "%d", &num) == 1) 
    {
        if (num <= 1) 
	{
            continue;
        }

        int factor = 2;
        while (factor * factor <= num) 
	{
            if (num % factor == 0) 
	    {
                printf("%d=%d*%d\n", num, factor, num / factor);
                break;
            }
            factor++;
        }

    }

    fclose(fp);
    return EXIT_SUCCESS;
}

