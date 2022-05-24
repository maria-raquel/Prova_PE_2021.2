/*
>>>>>>>>>>> PROVA_1_PROGRAMAÇÃO_ESTRUTURADA <<<<<<<<<<<<<

* Professor: Igor Malheiros

>>>>>>>>>>>>>>>>>>>>>>>>>>|<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
Alunos:
- Jonas Felipe | 20210026948
- Maria Raquel | 20200025900
*/

#include <stdio.h>
#include "visualizacao.h"
#include "matematica.h"

//>================== VISUALIZACAO: ==================

/*Funcao que exibe na tela um histograma dos valores fornecidos no array
    > int *notas = array de notas 
    > int n = tamanho do array de notas 
    > int axis = orientacao da tabela: 0 para vertical, 1 para horizontal 
*/
void plot_hist(int *notas, int n, int axis){ 

    //Criando um array que vai possuir as frequencia das notas que variam de 0 a 10

    int freq[11] = {0};

    for(int i = 0; i < n; i++)
        freq[notas[i]]++; // Incrementando na posicao referente a nota no array freq 
    
    printf("--------- Histograma ---------\n"); // Inserindo o histograma na tela

    if(axis){
        int hist[11][11];

        for(int i = 0; i < 11; i++){
            for (int j = 0; j < freq[i]; j++){
                hist[i][j] = 1;
            }
            for (int j = freq[i]; j < 11; j++){
                hist[i][j] = 0;
            }
        }
        
        for (int i = valor_maximo(freq, 11), j; i >= 0; i--){
            printf("\t");
            for (j = 0; j < 11; j++){
                if(hist[j][i])
                    printf("◼ ");
                else
                    printf("  ");

            }
            printf("\n");
        }
        printf("notas\t");
        for (int i = 0; i < 11; i++)
        {
            printf("%d ", i);
        }
    
    }else{
        for (int i = 0; i < 6; i++){ 
            printf("%.2d|",i); // Insere a nota que tera sua frequencia exibida
            for (int j = 0; j < freq[i]; j++){
                printf("◼"); // Insere um "◼" para cada contador da frequencia
                //Ex.: 1 (aparecendo 5 vezes)| ◼◼◼◼◼
            }
            printf("\t(:c)\n"); //Notas abaixo de 6 recebem  rostinhos tristes
        }
        // Insere a frequencia do restante dos valores
        for (int i = 6; i < 11; i++){
        printf("%.2d|",i);
        for (int j = 0; j < freq[i]; j++){
            printf("◼");
        }
        printf("\t(:D)\n"); //Notas a partir de 6 recebem um rostinho feliz
        }
    }
}

/*Funcao que exibe na tela qualquer array unidimensional
    > int *array = array a ser impresso 
    > int n = tamanho do array
*/ 
void printar_arrays(int *array, int n){
    putchar('{');

    for(int i=0; i<n-1; i++)
        printf("%d, ", array[i]);

    printf("%d}\n", array[n-1]);
}