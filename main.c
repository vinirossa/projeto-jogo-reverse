#include <stdio.h>
#include <stdlib.h>

void Imprime(int *p); // Protótipo da função que imprime o jogo
void Analisa(int *p,char *elemento); // Função que analisa a tecla pressionada

main()
{   
    int a, b , c, d=1, mat[3][3], *p=mat[0];
    char elemento[20];

    // Atribui os valores a matriz
    for(a = 0; a < 9; a++)
    { 
        // rand()%2 gera números aleatórios até no máximo um valor menor que 2
        *p = 1 + (rand() % 2);  

        // Ponteiro apontando para a próxima posição
        *(p++);           
    }

    // Chamada da função que imprime o jogo
    Imprime(mat[0]);     

    do
    {     
        p = mat[0];   

        printf("\n\n\t\tVoce deve Deixar todos as casas com o mesmo simbolo");
        printf("\n\t  Digite o numero correspondente a posicao que desejas alterar\n");
        printf("\tVale lembrar que outras casas da vizinhanca tambem sao alteradas\n");

        elemento[0] = getche();

        // Limpando a tela
        system("cls");    

        // Chama a Função que altera os valores do jogo
        Analisa(mat[0], &elemento[0]); 

        // Chamada da função que imprime o jogo   
        Imprime(mat[0]);                

        p = mat[0];
        c = 0;

        // ANALISA SE TODOS VALORES ESTAO IGUAIS. SE TIVER O JOGADOR VENCEU
        for(a = 0; a < 9; a++) 
        
        if(p[0] == p[a])
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

// Função responsável por imprimir o jogo
void Imprime(int *p){
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
        printf("    %c", *p);
        
        if(b == 2) 
            printf("\n\n");

        // Faz o ponteiro apontar para a próxima posição
        *(p++);                
    }
}

// Função que alterna os valores dos quadrados
void Analisa(int *p, char *elemento){
    switch(*elemento) {
        case '1': 
            if(p[0] == 1) p[0] = 2;
            else p[0] = 1;
            if(p[1] == 1) p[1] = 2;
            else p[1] = 1;
            if(p[3] == 1) p[3] = 2;
            else p[3] = 1;
            break;

        case '2': 
            if(p[1] == 1) p[1] = 2;
            else p[1] = 1;
            if(p[0] == 1) p[0] = 2;
            else p[0] = 1;
            if(p[2] == 1) p[2] = 2;
            else p[2] = 1;
            break;

        case '3': 
            if(p[2] == 1) p[2] = 2;
            else p[2] = 1;
            if(p[1] == 1) p[1] = 2;
            else p[1] = 1;
            if(p[5] == 1) p[5] = 2;
            else p[5] = 1;
            break;

        case '4': 
            if(p[3] == 1) p[3] = 2;
            else p[3] = 1;
            if(p[0] == 1) p[0] = 2;
            else p[0] = 1;
            if(p[6] == 1) p[6] = 2;
            else p[6] = 1;
            break;

        case '5': 
            if(p[4] == 1) p[4] = 2;
            else p[4] = 1;
            if(p[1] == 1) p[1] = 2;
            else p[1] = 1;
            if(p[3] == 1) p[3] = 2;
            else p[3] = 1;
            if(p[5] == 1) p[5] = 2;
            else p[5] = 1;
            if(p[7] == 1) p[7] = 2;
            else p[7] = 1;                
            break;

        case '6': 
            if(p[5] == 1) p[5] = 2;
            else p[5] = 1;
            if(p[2] == 1) p[2] = 2;
            else p[2] = 1;
            if(p[8] == 1) p[8] = 2;
            else p[8] = 1;
            break;

        case '7': 
            if(p[6] == 1) p[6] = 2;
            else p[6] = 1;
            if(p[3] == 1) p[3] = 2;
            else p[3] = 1;
            if(p[7] == 1) p[7] = 2;
            else p[7] = 1;
            break;

        case '8': 
            if(p[7] == 1) p[7] = 2;
            else p[7] = 1;
            if(p[6] == 1) p[6] = 2;
            else p[6] = 1;
            if(p[8] == 1) p[8] = 2;
            else p[8] = 1;
            break;

        case '9': 
            if(p[8] == 1) p[8] = 2;
            else p[8] = 1;
            if(p[5] == 1) p[5] = 2;
            else p[5] = 1;
            if(p[7] == 1) p[7] = 2;
            else p[7] = 1;
            break;            
    }
}