#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "escolhe_dificuldade.c"
#include "imprime_jogo.c"
#include "analisa_tecla.c"

int main()
{
    // Inicializa variáveis
    int i_mat, j_mat, dificuldade, tentativas;

    // Corrige o comportamento da função rand() para ela de fato gerar números aleatórios
    srand(time(0)); 

    // Aguarda o jogador escolher a dificuldade
    escolhe_dificuldade(&dificuldade);

    // Atribui valores às variáveis de acordo com a dificuldade
    if (dificuldade == 1) {
        i_mat = j_mat = 3; // 3x3
        tentativas = 10;
    } else {
        i_mat = j_mat = 4; // 4x4
        tentativas = 25;
    }

    // Cria vetor de teclas de acordo com as dimensões da dificuldade
    char vetor_teclas[i_mat * j_mat];

    // Popula vetor de teclas com suas correspondentes na matriz de acordo com a dificuldade
    if (dificuldade == 1) 
        strcpy(vetor_teclas, "123QWEASD");
    else 
        strcpy(vetor_teclas, "1234QWERASDFZXCV");

    // Cria matriz de casas de acordo com as dimensões da dificuldade
    int matriz_casas[i_mat][j_mat], *pmatriz_casas;
    pmatriz_casas = &matriz_casas;

    // Popula a matriz com 2's e 3's
    for (int i = 0; i < i_mat; i++)
        for (int j = 0; j < j_mat; j++) {            
            // Pega o resto da divisão de um número inteiro aleatório por 2 e soma mais 2, resultando sempre em 2 ou 3
            matriz_casas[i][j] = 2 + (rand() % 2);
        }

    do
    {   
        // Imprime o jogo e suas instruções
        imprime_jogo(matriz_casas, dificuldade, i_mat, j_mat, tentativas);

        // Detecta a tecla pressionada pelo jogador e altera os valores das casas
        analisa_tecla(matriz_casas, vetor_teclas, i_mat, j_mat);

        // Diminui as tentativas restantes
        tentativas--;

        // Conta quantos símbolos são iguais
        int num_iguais = 0;
        for (int i = 0; i < i_mat * j_mat; i++)
            if (*pmatriz_casas == *(pmatriz_casas + i))
                num_iguais++;

        // Verifica se o jogador ganhou (todos símbolos são iguais)
        if (num_iguais == i_mat * j_mat) {
            system("cls");  
            printf("\n> > > > > >  J O G O  R E V E R S E  < < < < < <\n");
            printf("\n\t\t  V I T O R I A\n\n");
            printf("Parabens \\o/, voce conseguiu deixar todos os simbolos iguais!!!\n\n");
            system("pause");

            return 0;
        }

        // Verifica se o jogador perdeu (acabaram as tentativas)
        if (tentativas == 0) {
            system("cls");  
            printf("\n> > > > > >  J O G O  R E V E R S E  < < < < < <\n");
            printf("\n\t\t  D E R R O T A\n\n");
            printf("Nao foi dessa vez, suas tentativas acabaram :c\n\n");
            printf("      Reabra o jogo para tentar de novo!\n\n");
            system("pause");

            return 0;
        }

    } while (1); // Continua repetindo enquanto o jogo não chega ao fim (vitória ou derrota)
}