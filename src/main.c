#include <stdio.h>
#include <stdlib.h>

#include "imprime_jogo.c"
#include "analisa_tecla.c"

#define I 3
#define J 3

main()
{
    // Inicializa variáveis
    int matriz[3][3], *pmatriz = matriz, dificuldade, num_iguais, perdeu, ganhou, tentativa_atual, tentativa_facil, tentativa_dificil;
    num_iguais = perdeu = ganhou = tentativa_atual = 0;
    tentativa_facil = 10;
    tentativa_dificil = 25;
    char tecla_pressionada;

    // Corrige o comportamento da função rand() para ela de fato gerar números aleatório
    srand(time(0));

    // Popula a matriz com 2's e 3's
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            // Pega o resto da divisão de um número inteiro aleatório por 2 e soma mais 2, resultando sempre em 2 ou 3
            matriz[i][j] = 2 + (rand() % 2);}
    }
    
    do{
    printf("Selecione a dificuldade:\n");
    printf("1.Facil\n2.Dificil\n");
    scanf("%d", &dificuldade);
    } while(dificuldade != 1 && dificuldade != 2);

    if(dificuldade != 1 && dificuldade != 2){
        printf("Esta opcao nao existe, por favor insira uma opcao valida.");
    }

    if (dificuldade == 1)
    {
        printf("Dificuldade selecionada:\n Facil.");
        // Exibe o jogo pela primeira vez
        imprime_jogo(matriz);
    }

    else if(dificuldade == 2){
        printf("Dificuldade selecionada:\n Dificil.");
        //Exibir a versao dificil do jogo
    }

    do
    {
        printf("\n TENTATIVAS RESTANTES: %d", tentativa_facil - tentativa_atual);
        printf("\n OBJETIVO: Deixar todas as casas com o mesmo simbolo");
        printf("\n COMO JOGAR: Digite o número correspondente a posicao que deseja alterar\n");
        printf(" e tanto essa posicao como as aos arredores serao invertidas (exceto as diagonais)\n");

        // Detecta a tecla pressionada pelo jogador
        tecla_pressionada = getche();

        // Checar se essa tecla é uma opção válida

        // Limpa a tela (terminal)
        system("cls");

        // Chama a função que altera os valores do jogo
        analisa_tecla(matriz[0], &tecla_pressionada);

        // Chamada da função que imprime o jogo
        imprime_jogo(matriz[0]);

        pmatriz = matriz[0];
        num_iguais = 0;

        // Conta quantos números são iguais
        for (int i = 0; i < 9; i++)
            if (pmatriz[0] == pmatriz[i])
                num_iguais++;
        
        //adiciona ao total de tentativas ja feitas
        tentativa_atual ++;

        // Caso todos sejam iguais, o jogador venceu
        if (num_iguais == I * J)
        {
            printf("\n\nVITORIA - Parabens, voce conseguiu deixar todos os simbolos iguais!!!\n\n");
            ganhou = 1;

            // // Soa um beep com frequencia de 500 MHZ por 1 segundo, (1000 milissegundos)
            // beep(500, 1000);
        }
        else if (tentativa_atual <= tentativa_facil)
        { 
            if(tentativa_atual == tentativa_facil)
                printf("\t\tAcabou suas tentativas...\n");
            else 
            printf("\n\t\tTENTE NOVAMENTE - Com persistencia voce ira conseguir\n");
        }
        if((tentativa_atual >= tentativa_facil) && ganhou == 0 )
        {
            printf("\n\t\tDERROTA - Nao foi dessa vez, reabra o jogo para tentar de novo!\n");
            ganhou = 1;
        }
    } while (!ganhou); // Continua repetindo enquanto o jogo nao chega ao fim (por vitoria ou derrota)

    // Espera o usuário digitar qualquer tecla
    getch();
    system("pause");
}