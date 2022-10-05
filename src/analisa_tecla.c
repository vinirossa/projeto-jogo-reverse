#include <stdio.h>
#include <stdlib.h>

void executa_acao(int *pmatriz, int i_tecla, int j_tecla, int i_mat, int j_mat);
void inverte_casa(int *casa);

// Função que analisa a tecla pressionada e alterna os valores dos quadrados
void analisa_tecla(int *pmatriz, char *pvetor_teclas, int i_mat, int j_mat)
{
    int tecla_valida, erro_avisado, idx_tecla_pressionada;
    tecla_valida = erro_avisado = idx_tecla_pressionada = 0;
    char tecla_pressionada;

    while (tecla_valida == 0)
    {    
        // Detecta tecla digitada (diferente do scanf, não quebra o programa quando é digitada uma letra)
        tecla_pressionada = getch();

        // Checa se a tecla digitada é válida e pega o índice dela no vetor através de ponteiros
        for (int i = 0; i < i_mat * j_mat; i++)
            if (tecla_pressionada == *(pvetor_teclas + i)) {
                tecla_valida = 1;
                idx_tecla_pressionada = (pvetor_teclas + i) - pvetor_teclas;
            }

        // Só exibe aviso que a tecla é inválida uma vez
        if (tecla_valida == 0 && erro_avisado == 0) {
            printf("\n===> A T E N C A O : Digite uma das teclas validas para jogar! (As letras precisam ser maiusculas)");
            erro_avisado = 1;
        }
    } 
    
    // Encontra i e j na matriz de casas a partir do índice do array
    int linha, coluna, i_tecla, j_tecla;
    linha = coluna = i_tecla = j_tecla = 0;

    for (int i = 0; i < i_mat * j_mat; i++)
    {
        if (coluna == i_mat) {
            coluna = 0;
            linha++;
        }

        if (i == idx_tecla_pressionada) {
            i_tecla = linha;
            j_tecla = coluna;
        }

        coluna++;
    }

    // Executa ações pelo pressionamento da tecla (inverte casa atual e sua vizinhança adjacente)
    executa_acao(pmatriz, i_tecla, j_tecla, i_mat, j_mat);
}

// Função responsável por executar a ação de pressionar uma tecla (inverter casa atual e adjacentes)
void executa_acao(int *pmatriz, int i_tecla, int j_tecla, int i_mat, int j_mat)
{
    // Inverte casa principal (p + (i * it) + j)
    inverte_casa(pmatriz + (i_tecla * i_mat) + j_tecla);

    // Inverte casas verticais vizinhas (quanto existem)
    // *Cima (i - 1, j)
    if (i_tecla - 1 >= 0)
        inverte_casa(pmatriz + ((i_tecla - 1) * i_mat) + j_tecla);

    // *Baixo (i + 1, j)
    if (i_tecla + 1 < i_mat)
        inverte_casa(pmatriz + ((i_tecla + 1) * i_mat) + j_tecla);

    // Inverte casas horizontais vizinhas (quanto existem)
    // *Esquerda (i, j - 1)
    if (j_tecla - 1 >= 0)
        inverte_casa(pmatriz + (i_tecla * i_mat) + j_tecla - 1);

    // *Direita (i, j + 1)
    if (j_tecla + 1 < j_mat)
        inverte_casa(pmatriz + (i_tecla * i_mat) + j_tecla + 1);
}

// Função responsável por inverter o valor da casa (símbolo) - quando 2 vira 3, quando 3 vira 2
void inverte_casa(int *casa)
{
    if (*casa == 2)
        *casa = 3;
    else
        *casa = 2;
}