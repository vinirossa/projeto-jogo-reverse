#include <stdio.h>
#include <stdlib.h>

// Função responsável por receber a escolha de dificuldade do jogador
void escolhe_dificuldade(int *pdificuldade)
{
    char tecla_pressionada;

    // Repete seleção de dificuldade até o jogador digitar 1 ou 2
    do
    {
        // Limpa a tela (terminal)
        system("cls");

        printf("\n> > > > > >  J O G O  R E V E R S E  < < < < < <\n");

        printf("\n\t       D I F I C U L D A D E");
        printf("\n\nDigite o numero correspondente a dificuldade desejada:");
        printf("\n\n1. Facil");
        printf("\n2. Dificil");
        printf("\n\n> ");

        // Detecta tecla digitada (diferente do scanf, não quebra o programa quando é digitada uma letra)
        tecla_pressionada = getchar();

    } while(tecla_pressionada != '1' && tecla_pressionada != '2'); 

    if (tecla_pressionada == '1')
        *pdificuldade = 1;
    else
        *pdificuldade = 2;
}