#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CRINCAS 50
#define MIN_NOTA 1
#define MAX_NOTA 5

int main() {
    int notas[NUM_CRINCAS];
    int contagem[MAX_NOTA] = {0};
    int i;
     srand(time(NULL));
     for (i = 0; i < NUM_CRINCAS; i++) {
        notas[i] = rand() % (MAX_NOTA - MIN_NOTA + 1) + MIN_NOTA;
    }
    for (i = 0; i < NUM_CRINCAS; i++) {
        int nota = notas[i];
        contagem[nota - MIN_NOTA]++;
    }
    printf("Frequencia das notas atribuidas:\n");
    for (i = MIN_NOTA; i <= MAX_NOTA; i++) {
        printf("Nota %d: %d vez(es)\n", i, contagem[i - MIN_NOTA]);
    }

    return 0;
}