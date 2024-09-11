#include <stdio.h>
#define MAX_TAMANHO 10

void copia_string(char destino[], const char origem[]) {
    int i = 0;
    while (origem[i] != '\0') {
        destino[i] = origem[i];
        i++;
    }
    destino[i] = '\0';
    }
    int comprimento_string(const char str[]) {
    int comprimento = 0;
    while (str[comprimento] != '\0') {
        comprimento++;
    }
    return comprimento;
}
int todas_as_letras_descobertas(const char palavra[], const int letras_descobertas[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (palavra[i] != ' ' && letras_descobertas[i] == 0) {
            return 0;
              }
    }
    return 1;
    }
    int main() {
    char palavra[MAX_TAMANHO + 1];
    char tentativa;
     int vidas;
     int tamanho_palavra;
     int letras_descobertas[MAX_TAMANHO] = {0};
     copia_string(palavra, "cachorro");
     tamanho_palavra = comprimento_string(palavra);
    vidas = tamanho_palavra + 2;
    printf("Bem-vindo ao Jogo da Forca!\n");
    printf("A palavra tem %d letras.\n", tamanho_palavra);

    while (vidas > 0) {
        printf("\nTentativas restantes: %d\n", vidas);
        printf("Palavra: ");
        for (int i = 0; i < tamanho_palavra; i++) {
            if (letras_descobertas[i] == 1 || palavra[i] == ' ') {
                printf("%c ", palavra[i]);
            } else {
                printf("_ ");
            }
        }
        printf("\n");
        printf("Digite uma letra: ");
        scanf(" %c", &tentativa);
         int letra_encontrada = 0;
         for (int i = 0; i < tamanho_palavra; i++) {
            if (palavra[i] == tentativa) {
                letras_descobertas[i] = 1;
                letra_encontrada = 1;
                }
        }
        if (!letra_encontrada) {
            vidas--;
            printf("Letra '%c' nao encontrada!\n", tentativa);
        }

        if (todas_as_letras_descobertas(palavra, letras_descobertas, tamanho_palavra)) {
            printf("Parabens! Voce adivinhou a palavra '%s'!\n", palavra);
            break;
        }
    }
    if (vidas <= 0) {
        printf("Fim de jogo! Você nao conseguiu adivinhar a palavra '%s'.\n", palavra);
    }

    return 0;
}