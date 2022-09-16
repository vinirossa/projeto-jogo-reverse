#include <stdio.h>
#include <stdlib.h>

// Função que alterna os valores dos quadrados
void analisa_tecla(int *pmat, char *elem)
{
    switch(*elem) {
        case '1': 
            if(pmat[0] == 1) pmat[0] = 2;
            else pmat[0] = 1;
            if(pmat[1] == 1) pmat[1] = 2;
            else pmat[1] = 1;
            if(pmat[3] == 1) pmat[3] = 2;
            else pmat[3] = 1;
            break;

        case '2': 
            if(pmat[1] == 1) pmat[1] = 2;
            else pmat[1] = 1;
            if(pmat[0] == 1) pmat[0] = 2;
            else pmat[0] = 1;
            if(pmat[2] == 1) pmat[2] = 2;
            else pmat[2] = 1;
            break;

        case '3': 
            if(pmat[2] == 1) pmat[2] = 2;
            else pmat[2] = 1;
            if(pmat[1] == 1) pmat[1] = 2;
            else pmat[1] = 1;
            if(pmat[5] == 1) pmat[5] = 2;
            else pmat[5] = 1;
            break;

        case '4': 
            if(pmat[3] == 1) pmat[3] = 2;
            else pmat[3] = 1;
            if(pmat[0] == 1) pmat[0] = 2;
            else pmat[0] = 1;
            if(pmat[6] == 1) pmat[6] = 2;
            else pmat[6] = 1;
            break;

        case '5': 
            if(pmat[4] == 1) pmat[4] = 2;
            else pmat[4] = 1;
            if(pmat[1] == 1) pmat[1] = 2;
            else pmat[1] = 1;
            if(pmat[3] == 1) pmat[3] = 2;
            else pmat[3] = 1;
            if(pmat[5] == 1) pmat[5] = 2;
            else pmat[5] = 1;
            if(pmat[7] == 1) pmat[7] = 2;
            else pmat[7] = 1;                
            break;

        case '6': 
            if(pmat[5] == 1) pmat[5] = 2;
            else pmat[5] = 1;
            if(pmat[2] == 1) pmat[2] = 2;
            else pmat[2] = 1;
            if(pmat[8] == 1) pmat[8] = 2;
            else pmat[8] = 1;
            break;

        case '7': 
            if(pmat[6] == 1) pmat[6] = 2;
            else pmat[6] = 1;
            if(pmat[3] == 1) pmat[3] = 2;
            else pmat[3] = 1;
            if(pmat[7] == 1) pmat[7] = 2;
            else pmat[7] = 1;
            break;

        case '8': 
            if(pmat[7] == 1) pmat[7] = 2;
            else pmat[7] = 1;
            if(pmat[6] == 1) pmat[6] = 2;
            else pmat[6] = 1;
            if(pmat[8] == 1) pmat[8] = 2;
            else pmat[8] = 1;
            break;

        case '9': 
            if(pmat[8] == 1) pmat[8] = 2;
            else pmat[8] = 1;
            if(pmat[5] == 1) pmat[5] = 2;
            else pmat[5] = 1;
            if(pmat[7] == 1) pmat[7] = 2;
            else pmat[7] = 1;
            break;            
    }
}