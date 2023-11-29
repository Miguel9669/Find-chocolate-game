/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   main.c
 * Author: TONIIIIIIII
 *
 * Created on 21 de novembro de 2023, 13:55 --> NÃO PERGUNTEIIIII
 * BYE
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int COLS = 0, LINES = 0;

typedef enum {FALSE, TRUE} bool;

/*
 * 
 */

int Random(int from, int to) {
    // generate random number
    return (rand() % to) + from;
}

void print(int tabuleiro[LINES][COLS], bool debug) {
    int i, j;
    for (i = 0; i < LINES; i++) {
        printf("\n ------------------------------------------------------------------------------------------------------\n");
        printf("%2d|", i + 1);
         
        for (j = 0; j < COLS; j++) {
            if (debug == TRUE) {
                printf(" %2d |", tabuleiro[i][j]);
            } else if (tabuleiro[i][j] == 0) {
                printf("  0 |");
            } else {
                printf("    |");
            }
        }
        
    }
     printf("\n -------------------------------------------------------------------------------------");
    printf("\n   ");
    for (int i = 0; i < LINES; i++) {
        printf(" %2d |", i + 1);
    }
    printf("\n");
   
    
}

void preencher(int tabuleiro[LINES][COLS], int from, int to){
    for (int i = 0; i < LINES; i++) {  
        for (int j = 0; j < COLS; j++) {
            tabuleiro[i][j] = Random(from, to);
        }
    }
}
void bombas(int tabuleiro[LINES][COLS], int quant) {
    int linha, coluna;
    do {
        linha = Random(0 ,COLS);
        coluna = Random(0 ,COLS);
        if (tabuleiro[linha][coluna] != -1) {
            tabuleiro[linha][coluna] = -1;
            quant--;
        }
                
    }while(quant != 0);
}
int pedir(char* question) {
    int n;
    printf("%s", question);
    scanf("%d", &n);
    return n - 1;
}

int verify(int linha, int coluna, int tabuleiro[LINES][COLS]) {
    if (tabuleiro[linha][coluna] > 0) {
        return 1;
    }else if (tabuleiro[linha][coluna] == 0) {
        return 0;
    }else {
        return -1;
        
    }
}
int main(int argc, char** argv) {
    int chocolate = 0, linha, coluna, verificar, opcaoLevel, from, to, quant;
    char opcao;
    
    srand(time(NULL));
    
    printf("Levels: \n1 Facil\n2 Medio\n3 Dificil\n>>> ");
    scanf("%d", &opcaoLevel);
    
    switch(opcaoLevel){
        case 1:
            COLS = 4;
            LINES = 4;
            from = 1;
            to = 20;
            quant = 3;
            break;
        case 2:
            COLS = 8;
            LINES = 8;
            from = 1;
            to = 60;
            quant = 30;
            break;
        case 3:
            COLS = 12;
            LINES = 12;
            from = 1;
            to = 1000;
            quant = 80;
            break;
            
    }
    
    int tabuleiro[LINES][COLS];
    preencher(tabuleiro, from, to);
    bombas(tabuleiro, quant);
    
    do {
        system("clear");
        print(tabuleiro, FALSE);
        printf("Chocolates: %d\n", chocolate);
        linha = pedir("Linha: ");
        coluna = pedir("Coluna: ");
        verificar = verify(linha, coluna, tabuleiro);
        if (verificar == 1){
            printf("Encontras-te %d chocolates", tabuleiro[linha][coluna]);
            chocolate += tabuleiro[linha][coluna];
            tabuleiro[linha][coluna] = 0;
            printf("\nPretende sair? (y/n) ");
            scanf(" %c", &opcao);
        }else if (verificar == 0){
            printf("Não ves que tem um 0 aí????");
            printf("\nPretende sair? (y/n) ");
            scanf(" %c", &opcao);
        }else {
            
            chocolate = 0;
            opcao = 'y'; 
        }
    }while(opcao != 'Y' && opcao != 'y');
    system("clear");
    printf("Perdes-te e ficas te sem chocolates\n");
    printf("Chocolates final: %d", chocolate);

    
    return (EXIT_SUCCESS);
}