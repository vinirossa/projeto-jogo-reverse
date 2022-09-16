#include <stdio.h>
#include <stdlib.h>

#define I 3
#define J 3

// Função responsável por imprimir o jogo
void imprime_jogo(int *pmat)
{
    int tecla = 1;

    // Mostra as opções de teclas para o jogador digitar
    for (int i = 0; i < I; i++)
    {        
        for (int j = 0; j < J; j++)
        {           
            printf("    %i", tecla);
            tecla++;
        }        
        printf("\n\n");
    }

    printf("\n    ___________\n\n\n");

    // Mostra os símbolos do jogo
    for (int i = 0; i < I; i++)
    {        
        for (int j = 0; j < J; j++)
        {           
            printf("    %c", *pmat);
            *(pmat++); 
        }        
        printf("\n\n");
    }
}