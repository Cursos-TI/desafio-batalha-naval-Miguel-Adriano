#include <stdio.h>

int main() {
    int tabuleiro[10][10] = {0}; // Tabuleiro 10x10 inicializado com água (0)
    int tamanho_navio = 3;
    int sobreposicao = 0;

    // Coordenadas iniciais dos navios
    int linha_h = 1, coluna_h = 2; // Navio horizontal começa em (1,2)
    int linha_v = 5, coluna_v = 7; // Navio vertical começa em (5,7)
    int linha_d1 = 0, coluna_d1 = 0; // Diagonal principal começa em (0,0)
    int linha_d2 = 7, coluna_d2 = 2; // Diagonal secundária começa em (7,2)

    // Validação e posicionamento do navio horizontal
    if (coluna_h + tamanho_navio <= 10) {
        for (int i = 0; i < tamanho_navio; i++) {
            if (tabuleiro[linha_h][coluna_h + i] != 0) sobreposicao = 1;
        }
        if (!sobreposicao) {
            for (int i = 0; i < tamanho_navio; i++) {
                tabuleiro[linha_h][coluna_h + i] = 3;
            }
        }
    }

    // Validação e posicionamento do navio vertical
    sobreposicao = 0;
    if (linha_v + tamanho_navio <= 10) {
        for (int i = 0; i < tamanho_navio; i++) {
            if (tabuleiro[linha_v + i][coluna_v] != 0) sobreposicao = 1;
        }
        if (!sobreposicao) {
            for (int i = 0; i < tamanho_navio; i++) {
                tabuleiro[linha_v + i][coluna_v] = 3;
            }
        }
    }

    // Validação e posicionamento do navio diagonal principal (↘)
    sobreposicao = 0;
    if (linha_d1 + tamanho_navio <= 10 && coluna_d1 + tamanho_navio <= 10) {
        for (int i = 0; i < tamanho_navio; i++) {
            if (tabuleiro[linha_d1 + i][coluna_d1 + i] != 0) sobreposicao = 1;
        }
        if (!sobreposicao) {
            for (int i = 0; i < tamanho_navio; i++) {
                tabuleiro[linha_d1 + i][coluna_d1 + i] = 3;
            }
        }
    }

    // Validação e posicionamento do navio diagonal secundária (↙)
    sobreposicao = 0;
    if (linha_d2 - (tamanho_navio - 1) >= 0 && coluna_d2 + tamanho_navio <= 10) {
        for (int i = 0; i < tamanho_navio; i++) {
            if (tabuleiro[linha_d2 - i][coluna_d2 + i] != 0) sobreposicao = 1;
        }
        if (!sobreposicao) {
            for (int i = 0; i < tamanho_navio; i++) {
                tabuleiro[linha_d2 - i][coluna_d2 + i] = 3;
            }
        }
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