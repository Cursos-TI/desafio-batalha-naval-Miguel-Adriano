#include <stdio.h>

int main() {
    int tabuleiro[10][10] = {0}; // Tabuleiro 10x10 inicializado com água (0)
    int tamanho_navio = 3;

    // Coordenadas iniciais dos navios
    int linha_h = 1, coluna_h = 2; // Navio horizontal começa em (1,2)
    int linha_v = 5, coluna_v = 7; // Navio vertical começa em (5,7)

    // Posiciona navio horizontal (valor 3)
    for (int i = 0; i < tamanho_navio; i++) {
        tabuleiro[linha_h][coluna_h + i] = 3;
    }

    // Posiciona navio vertical (valor 3)
    for (int i = 0; i < tamanho_navio; i++) {
        tabuleiro[linha_v + i][coluna_v] = 3;
    }

    printf("Tabuleiro de Batalha Naval:\n");
    // Exibe cabeçalho das colunas (A, B, C, ...)
    printf("   ");
    for (int j = 0; j < 10; j++) {
        printf("%c ", 'A' + j);
    }
    printf("\n");

    // Exibe o tabuleiro com numeração das linhas (1, 2, 3, ...)
    for (int i = 0; i < 10; i++) {
        printf("%2d ", i + 1); // Numeração da linha
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    return 0;
}