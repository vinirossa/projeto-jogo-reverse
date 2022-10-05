#include <stdio.h>
#include <stdlib.h>

void mostra_teclas(int dificuldade);
void mostra_instrucoes(int tentativas);

// Função responsável por imprimir o jogo
void imprime_jogo(int *pmatriz_casas, int dificuldade, int i_mat, int j_mat, int tentativas)
{
    // Limpa a tela (terminal)
    system("cls");

    printf("\n> > > > > >  J O G O  R E V E R S E  < < < < < <\n");

    // Mostra as opções de teclas para o jogador digitar
    mostra_teclas(dificuldade);

    // Mostra os símbolos do jogo iterando sobre cada elemento da matriz
    for (int i = 0; i < i_mat; i++)
    {        
        for (int j = 0; j < j_mat; j++)
        {          
            // Ao imprimir o número como caractere, o correspondente ASCII é exibido, no caso, 2 e 3 viram emoticons
            printf("  \t%c", *pmatriz_casas);
            pmatriz_casas++; 
        }        
        printf("\n\n");
    }

    // Mostra a instruções do jogo e também as tentativas restantes
    mostra_instrucoes(tentativas);
}

// Função responsável por mostrar as teclas correspondentes a cada posição da matriz
void mostra_teclas(int dificuldade)
{
    if (dificuldade == 1)
    {
        printf("\n\t   T E C L A S\n\n");

        printf("  \t1\t2\t3\n\n");
        printf("  \tQ\tW\tE\n\n");
        printf("  \tA\tS\tD\n\n");

        printf("  \t_________________\n\n");

        printf("\t    C A S A S\n\n");
    }
    else
    {
        printf("\n\t       T E C L A S\n\n");

        printf("  \t1\t2\t3\t4\n\n");
        printf("  \tQ\tW\tE\tR\n\n");
        printf("  \tA\tS\tD\tF\n\n");
        printf("  \tZ\tX\tC\tV\n\n");

        printf("  \t_________________________\n\n");

        printf("\t        C A S A S\n\n");
    }
}

// Função responsável por mostrar as instruções do jogo
void mostra_instrucoes(int tentativas)
{    
    printf("\n TENTATIVAS: %d", tentativas);
    printf("\n OBJETIVO: Deixar todas as casas com o mesmo simbolo");
    printf("\n COMO JOGAR: Digite o numero correspondente a posicao que deseja alterar\n");
    printf(" e tanto essa posicao como as aos arredores serao invertidas (exceto as diagonais)\n");
}