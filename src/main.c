#include <stdio.h>
#include <stdlib.h>

#include "imprime_jogo.c"
#include "analisa_tecla.c"

#define I 3
#define J 3
#define null 0

main()
{
    // Inicializa variáveis
    int num_iguais, perdeu = 0, fim = 0, mat[3][3], *pmat = mat, i, j, tentativa_atual = 0;
    int  tentativa_facil = 10;
    num_iguais = 0;
    char teclas[20];

    srand(time(null));

    // Popula a matriz com 1's e 2's
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            // Alimenta a matriz com numeros aleatórios, entre 1 e 2
            mat[i][j] = (rand() % 2)+1;
        }
    }
    // Chama função que imprime o jogo
    printf("\n\n");
    imprime_jogo(mat);

    do
    {
        pmat = mat[0];

        printf("\n\t\tTENTATIVAS DISPONIVEIS: %d\n", (tentativa_facil-tentativa_atual));

        printf("\n\n\t\tVoce deve Deixar todos as casas com o mesmo simbolo dentro da quantidade de tentativas disponiveis");
        printf("\n\t  Digite o numero correspondente a posicao que desejas alterar\n");
        printf("\tVale lembrar que outras casas da vizinhanca tambem sao alteradas\n");

        teclas[0] = getche();

        // Limpa a tela (terminal)
        system("cls");

        // Chama a Função que altera os valores do jogo
        analisa_tecla(mat[0], &teclas[0]);

        // Chamada da função que imprime o jogo
        imprime_jogo(mat[0]);

        pmat = mat[0];
        num_iguais = 0;

        // Conta quantos números são iguais
        for (int i = 0; i < 9; i++)
            if (pmat[0] == pmat[i])
                num_iguais++;
        
        //adiciona ao total de tentativas ja feitas
        tentativa_atual ++;

        // Caso todos sejam iguais, o jogador venceu
        if (num_iguais == 9)
        {
            printf("\n\nPARABENS - VOCE CONSEGUIU FAZER COM QUE TODOS SIMBOLOS FICASSEM IGUAIS - VENCEU\n\n");
            fim = 1;

            // // Soa um beep com frequencia de 500 MHZ por 1 segundo, (1000 milissegundos)
            // beep(500, 1000);
        }
        else if (tentativa_atual <= tentativa_facil)
        { 
            if(tentativa_atual == tentativa_facil)
            {
                printf("\t\tAcabou suas tentativas...\n");
            }
            else 
            {
                printf("\n\t\tTENTE NOVAMENTE - PERSISTENCIA ATE ALCANCAR EXITO\n");
            }
        }
        if((tentativa_atual >= tentativa_facil) && fim == 0 )
        {
            printf("\n\t\tNao foi dessa vez, caso queira, é possivel rodar o jogo de novo.\n");
            fim = 1;
        }
    } while (!fim); // Continua repetindo enquanto o jogo nao chega ao fim (por vitoria ou derrota)

    // Espera o usuário digitar qualquer tecla
    getch();
    system("pause");
}