#include <stdio.h>

#define LINHAS 10
#define COLUNAS 10

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    int tabuleiro[10][10];
    // letras representando as linhas da tabela
    char letras[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.

    /*
     * Inicializar as posicoes
     * 0: Mar
     * 3: Navio
    */
    // limitar tamhanho dos navios
    int navio1 = 0;
    int navio2 = 0;

    for (int i = 0; i < LINHAS; i++)
    {
        for (int j = 0; j < COLUNAS; j++)
        {
            // posicionar primeiro navio vertical
            if ((i == 1 || i == 2 || i == 3) && j == 5 ) {
                tabuleiro[i][j] = 3;
            } 
            // posicionar segundo navil horizontal
            else if ((j == 2 || j == 3 || j == 4) && i == 8 ) {
                tabuleiro[i][j] = 3;
            } 
            // posicionar primeiro navio diagonal
            else if (navio1 < 3 && i > 1 && i == j) {
                tabuleiro[i][j] = 3;

                navio1 +=1;
            } 
            // // posicionar segundo navio diagonal
            else if (navio2 < 3 && (i + j) == 9) {
                if (j != 9) {
                    tabuleiro[i][j] = 3;
                    navio2 +=1;
                }

            } 
            else {
                tabuleiro[i][j] = 0; // mar
            }

        }    
    }

    // Habilidades
    // Exemplo de saída de habilidade em cone:
    // 0 0 3 0 0
    // 0 3 3 3 0 
    // 3 3 3 3 3   
    // Exemplo de saída de habilidade em cruz:
    // 0 0 3 0 0 
    // 3 3 3 3 3 
    // 0 0 3 0 0
    // Exemplo de saída de habilidade em octaedro:
    // 0 0 3 0 0 
    // 0 3 3 3 0 
    // 0 0 3 0 0
    for (int i = 0; i < LINHAS; i++)
    {
        for (int j = 0; j < COLUNAS; j++)
        {
            // Cone
            if ((i == 0 && j == 3) // 0 0 5 0 0
                || (i == 1 && (j == 2 || j == 3 || j == 4)) // 0 5 5 5 0
                || (i == 2 && (j == 1 || j == 2 || j == 3 || j == 4 || j == 5))) { // 5 5 5 5 5
                tabuleiro[i][j] = 5;
            } 

            // cruz
            if ((i == 4 && j == 7) // 0 0 5 0 0
                || (i == 5 && (j == 5 || j == 6 || j == 7 || j == 8 || j == 9)) // 5 5 5 5 5
                || (i == 6 && (j == 7))) { // 0 0 5 0 0
                tabuleiro[i][j] = 5;
            }

            // octaedro
            if ((i == 7 && j == 3) // 0 0 5 0 0
                || (i == 8 && (j == 2 || j == 3 || j == 4)) // 0 5 5 5 0
                || (i == 9 && (j == 3))) { // 0 0 5 0 0
                tabuleiro[i][j] = 5;
            }
        }
    }
    
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Imprimir inicializaçao da tabela
    printf("# TABULEIRO BATALHA NAVAL # \n");
    // imprimir letras horizontal na tabela
    for (int i = 0; i < 10; i++)
    {   
        // Espaçamento na primeira letra
        if (i == 0) {
            printf("     ");
        }
        printf("%c ", letras[i]);
    }
    printf("\n");

    
    // imprimir as posiçoes horizontal e vertical
    for (int i = 0; i < LINHAS; i++)
    {
        // Espaçamento para alinhar o numero 10
        if (i != 9) {
            printf(" ");
        }
        printf(" %d: %d ", i+1, tabuleiro[0][i]);
        for (int j = 1; j < COLUNAS; j++)
        {
            printf("%d ", tabuleiro[i][j]);

        }

        printf("\n");
    }
    

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
