/* 
 * File:   jogodavelha.c
 * Author: regisnumata
 * Created on 25 de Outubro de 2019, 12:40
 * Trabalho Jogo da Velha
 */

#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
#include<string.h>


// função mostra o status atual do jogo na tela
void mostra_velha();                             

// função valida se valores linha e coluna são ok e se posição da matriz tab não está ocupada 
int valida_jogada(int p_l, int p_c, int p_j);    

// função valida se existe vencedor
int valida_vencedor(int p_j);

// Matriz de escopo GLOBAL para armazenamento das jogadas do jogo
char tab[3][3];                                  


int main() {
    setlocale(LC_ALL,"");
    
    
    char jog1[10], jog2[10];
    int l, c, j, cont=0, retorno, vencedor=0;
    
    // Artificio Tecnico para alinhamento da matriz
    tab[0][0] = '.';
    tab[0][1] = '.';
    tab[0][2] = '.';
    tab[1][0] = '.';
    tab[1][1] = '.';
    tab[1][2] = '.';
    tab[2][0] = '.';
    tab[2][1] = '.';
    tab[2][2] = '.';
    
    // Definição do jogador 1 e 2
    printf("Informe o nome do jogador 1 - X: ");
    scanf("%s", &jog1);
    printf("Informe o nome do jogador 2 - O: ");
    scanf("%s", &jog2);
    system("clear");
    mostra_velha();
 

    
    //Enquanto não tiver vencedor permanece no laço    
    while(vencedor == 0){
        
        //Valida jogada do jogador1
        retorno = 0;
        while(retorno == 0){
            j=1;
            printf("\n%s - Informe a linha e Coluna da jogada\n", jog1);
            printf("Linha: ");
            scanf("%d", &l);
            printf("Coluna: ");
            scanf("%d", &c);
            system("clear");
            retorno = valida_jogada(l, c, j);
            mostra_velha();
        }
        
        
        //Valida se jogador1 é o vencedor
        vencedor = valida_vencedor(1);
        if(vencedor != 0){
            printf("============================================\n");
            printf("Parabéns %s (X). Você foi o VENCEDOR !!!\n", jog1);
            printf("============================================\n");
            break;
        }
        
        
            //Contador para empate. Se jogador1 jogar 5x é porque deu empate.
            cont+=1;
            if(cont == 5){
                printf("==============\n");
                printf("EMPATE !!!\n");
                printf("==============\n");
                break;
            }
        
            

        //Valida jogada do jogador2    
        retorno = 0;
        while(retorno == 0){
            j=2;
            printf("\n%s - Informe a linha e Coluna da jogada\n", jog2);
            printf("Linha: ");
            scanf("%d", &l);
            printf("Coluna: ");
            scanf("%d", &c); 
            system("clear");
            retorno = valida_jogada(l, c, j);
            mostra_velha();
        } 

        //Valida se o jogador2 é o vencedor
        vencedor = valida_vencedor(2);
        if(vencedor != 0){
            printf("============================================\n");
            printf("Parabéns %s (O). Você foi o VENCEDOR !!!\n", jog2);
            printf("============================================\n");
            break;
        }
        
        
    } //fim while vencedor
    
    
    return (0);
    system("pause");
}



/* ------- Funções ---------*/

void mostra_velha(){
	
	printf("\n\n");
	printf("\t   0    1    2 \n\n");
	printf("\t      |   |   \n");
	printf("\t0   %c | %c | %c \n", tab[0][0],tab[0][1],tab[0][2]);
	printf("\t   ___|___|___\n");
	printf("\t      |   |   \n");
	printf("\t1   %c | %c | %c \n", tab[1][0],tab[1][1],tab[1][2]);
	printf("\t   ___|___|___\n");
	printf("\t      |   |   \n");
	printf("\t2   %c | %c | %c \n", tab[2][0],tab[2][1],tab[2][2]);
	printf("\t      |   |   \n\n\n");
}


int valida_jogada(int p_l, int p_c, int p_j){
        
        if(p_j == 1){  
            if(p_l<0 || p_c<0 || p_l>2 || p_c>2){
                    printf("=======================================================\n");
                    printf("A Linha %d e Coluna %d já está preenchida ou é Inválida\n", p_l, p_c);
                    printf("=======================================================\n");
                } else if (tab[p_l][p_c] == 'X' || tab[p_l][p_c] == 'O') {
                    printf("=======================================================\n");
                    printf("A Linha %d e Coluna %d já está preenchida ou é Inválida\n", p_l, p_c);
                    printf("=======================================================\n");
                    } else {
                        tab[p_l][p_c] = 'X';
                        return 1;
                    } 
            
        } else if (p_j == 2){
                if(p_l<0 || p_c<0 || p_l>2 || p_c>2){
                    printf("=======================================================\n");
                    printf("A Linha %d e Coluna %d já está preenchida ou é Inválida\n", p_l, p_c);
                    printf("=======================================================\n");
                } else if (tab[p_l][p_c] == 'X' || tab[p_l][p_c] == 'O') {
                    printf("=======================================================\n");
                    printf("A Linha %d e Coluna %d já está preenchida ou é Inválida\n", p_l, p_c);
                    printf("=======================================================\n");
                    } else {
                        tab[p_l][p_c] = 'O';
                        return 1;
                    }                 
                }
 }


int valida_vencedor(int p_j){
    if(p_j == 1){
        if(
           tab[0][0] == 'X' && tab[0][1] == 'X' && tab[0][2] == 'X' ||
           tab[1][0] == 'X' && tab[1][1] == 'X' && tab[1][2] == 'X' ||
           tab[2][0] == 'X' && tab[2][1] == 'X' && tab[2][2] == 'X' ||
           tab[0][0] == 'X' && tab[1][1] == 'X' && tab[2][2] == 'X' ||
           tab[2][0] == 'X' && tab[1][1] == 'X' && tab[0][2] == 'X' ||
           tab[0][0] == 'X' && tab[1][0] == 'X' && tab[2][0] == 'X' ||
           tab[0][1] == 'X' && tab[1][1] == 'X' && tab[2][1] == 'X' ||
           tab[0][2] == 'X' && tab[1][2] == 'X' && tab[2][2] == 'X'     
           ){
            return 1;
        } else {
            return 0;
        }
    } else if (p_j == 2){
        if(
           tab[0][0] == 'O' && tab[0][1] == 'O' && tab[0][2] == 'O' ||
           tab[1][0] == 'O' && tab[1][1] == 'O' && tab[1][2] == 'O' ||
           tab[2][0] == 'O' && tab[2][1] == 'O' && tab[2][2] == 'O' ||
           tab[0][0] == 'O' && tab[1][1] == 'O' && tab[2][2] == 'O' ||
           tab[2][0] == 'O' && tab[1][1] == 'O' && tab[0][2] == 'O' ||
           tab[0][0] == 'O' && tab[1][0] == 'O' && tab[2][0] == 'O' ||
           tab[0][1] == 'O' && tab[1][1] == 'O' && tab[2][1] == 'O' ||
           tab[0][2] == 'O' && tab[1][2] == 'O' && tab[2][2] == 'O'     
           ){
            return 1;
        } else {
            return 0;
        }   
    }    
}
    