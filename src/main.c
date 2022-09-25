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
    int num_iguais, ganhou, mat[3][3], *pmat = mat, i, j;
    num_iguais = ganhou = 0;
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
    imprime_jogo(mat);

    do
    {
        pmat = mat[0];

        printf("\n\n\t\tVoce deve Deixar todos as casas com o mesmo simbolo");
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

        // Caso todos sejam iguais, o jogador venceu
        if (num_iguais == 9)
        {
            printf("\n\nPARABENS - VOCE CONSEGUIU FAZER COM QUE TODOS SIMBOLOS FICASSEM IGUAIS - VENCEU\n\n");
            ganhou = 1;

            // // Soa um beep com frequencia de 500 MHZ por 1 segundo, (1000 milissegundos)
            // beep(500, 1000);
        }
        else
            printf("\n\t\tTENTE NOVAMENTE - PERSISTENCIA ATE ALCANCAR EXITO\n");
    } while (!ganhou); // Continua repetindo enquanto o jogador não ganha o jogo

    // Espera o usuário digitar qualquer tecla
    getch();
    system("pause");
}