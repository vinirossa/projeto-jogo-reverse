#include <stdio.h>
#include <stdlib.h>

#include "imprime_jogo.c"
#include "analisa_tecla.c"

main()
{   
    int a, b, c, d = 1, mat[3][3], *pmat = mat[0];
    char elem[20];

    // Atribui os valores a matriz
    for(a = 0; a < 9; a++)
    { 
        // rand() % 2 gera números aleatórios até no máximo um valor menor que 2
        *pmat = 1 + (rand() % 2);  

        // Ponteiro apontando para a próxima posição
        *(pmat++);           
    }

    // Chamada da função que imprime o jogo
    imprime_jogo(mat[0]);     

    do
    {     
        pmat = mat[0];   

        printf("\n\n\t\tVoce deve Deixar todos as casas com o mesmo simbolo");
        printf("\n\t  Digite o numero correspondente a posicao que desejas alterar\n");
        printf("\tVale lembrar que outras casas da vizinhanca tambem sao alteradas\n");

        elem[0] = getche();

        // Limpando a tela
        system("cls");    

        // Chama a Função que altera os valores do jogo
        analisa_tecla(mat[0], &elem[0]); 

        // Chamada da função que imprime o jogo   
        imprime_jogo(mat[0]);                

        pmat = mat[0];
        c = 0;

        // ANALISA SE TODOS VALORES ESTAO IGUAIS. SE TIVER O JOGADOR VENCEU
        for(a = 0; a < 9; a++) 
        
        if(pmat[0] == pmat[a])
            c++;
        
        if(c == 9)
        {
            printf("\n\nPARABENS - VOCE CONSEGUIU FAZER COM QUE TODOS SIMBOLOS FICASSEM IGUAIS - VENCEU\n\n");
            d = 0;

            // // Soa um beep com frequencia de 500 MHZ por 1 segundo, (1000 milissegundos)
            // beep(500, 1000); 
        }
        else 
            printf("\n\t\tTENTE NOVAMENTE - PERSISTENCIA ATE ALCANCAR EXITO\n");
    } while(d); // Enquanto d for diferente de zero 0

    // Espera o usuário digitar qualquer tecla
    getch();       
    system("pause");      
}