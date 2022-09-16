#include <stdio.h>
#include <stdlib.h>

// Função responsável por imprimir o jogo
void imprime_jogo(int *pmat){
    int a, b ,c = 1;

    // Mostra os numeros
    for(a = 0; a < 9; a++)
    {
        printf("    %i", c);

        if(a == 2 || a == 5) 
            printf("\n\n");

        c++;
    }

    printf("\n    ___________\n\n\n");

    // Mostra os símbolos
    for(a = 0; a < 3; a++) 

    for(b = 0; b < 3; b++) {
        printf("    %c", *pmat);
        
        if(b == 2) 
            printf("\n\n");

        // Faz o ponteiro apontar para a próxima posição
        *(pmat++);                
    }
}