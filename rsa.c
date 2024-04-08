#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime(int n) {
    if (n <= 1) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    return 1;
}

void factorize(int n) {
    int p, q;

    for (p = 2; p <= sqrt(n); p++) {
        if (n % p == 0 && is_prime(p)) {
            q = n / p;
            if (is_prime(q)) {
                printf("p = %d, q = %d\n", p, q);
                return;
            }
        }
    }
    printf("Prime factors not found\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <number>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    if (n <= 1) {
        printf("Number must be greater than 1\n");
        return 1;
    }

    factorize(n);

    return 0;
}

