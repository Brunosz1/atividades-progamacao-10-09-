#include <stdio.h>
#define NUM_CONTAS 100
int buscaBinaria(int contas[], int tamanho, int contaProcurada, int *comparacoes) {
    int esquerda = 0;
    int direita = tamanho - 1;
    *comparacoes = 0;

    while (esquerda <= direita) {
        (*comparacoes)++;
        int meio = esquerda + (direita - esquerda) / 2;

        if (contas[meio] == contaProcurada) {
            return meio;
        }
        if (contas[meio] < contaProcurada) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }
      return -1;
}

int main() {
    int contas[NUM_CONTAS];
    int contaProcurada;
    int posicao, comparacoes;
    for (int i = 0; i < NUM_CONTAS; i++) {
        contas[i] = i + 1;
    }
    printf("Digite o numero da conta que deseja verificar: ");
    scanf("%d", &contaProcurada);
    posicao = buscaBinaria(contas, NUM_CONTAS, contaProcurada, &comparacoes);
     if (posicao != -1) {
        printf("Conta %d encontrada na posicao %d.\n", contaProcurada, posicao);
    } else {
        printf("Conta %d nao encontrada.\n", contaProcurada);
    }
    printf("Numero de comparacoes realizadas: %d\n", comparacoes);

    return 0;
}