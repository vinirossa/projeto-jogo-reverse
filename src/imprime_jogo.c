#include <stdio.h>
#include <stdlib.h>

#define I 3
#define J 3

// Função responsável por imprimir o jogo
void imprime_jogo(int *pmat)
{
    printf("\n>>>>>> J O G O  R E V E R S E <<<<<<\n");

    // Mostra as opções de teclas para o jogador digitar
    printf("\n\t   T E C L A S\n\n");

    printf("  \t1\t2\t3\n\n");
    printf("  \tQ\tW\tE\n\n");
    printf("  \tA\tS\tD\n\n");

    printf("  \t_________________\n\n");

    // Mostra os símbolos do jogo iterando sobre cada elemento da matriz via ponteiro
    printf("\t    C A S A S\n\n");

    for (int i = 0; i < I; i++)
    {        
        for (int j = 0; j < J; j++)
        {          
            // Ao imprimir o número como caractere, o correspondente ASCII é exibido, no caso, 2 e 3 como emoticons
            printf("  \t%c", *pmat);
            pmat++; 
        }        
        printf("\n\n");
    }
}