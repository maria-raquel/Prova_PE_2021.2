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
        freq[notas[i]]++; // Criando a frequencia de cada nota 
    
    puts("--------- Histograma ---------");

    if(axis){
        int hist[11][11]; // Criando a matriz quadrada que vai receber os valores da frequencia

        for(int i = 0; i < 11; i++){
            for (int j = 0; j < freq[i]; j++){
                hist[i][j] = 1; // Preenchendo a matriz quadrada com '1' para cada ocorrencia de cada nota
            }
            for (int j = freq[i]; j < 11; j++){
                hist[i][j] = 0; // Preenchendo o restante da matriz com '0'
            }
        }
        
        for (int i = valor_maximo(freq, 11), j; i >= 0; i--){
            putchar('\t');
            for (j = 0; j < 11; j++){
                if(hist[j][i]) // Imprimindo, de baixo para cima, a matriz transposta
                    printf("◼ ");
                else
                    printf("  ");

            }
            putchar('\n');
        }
        printf("notas\t");
        for (int i = 0; i < 11; i++)
        {
            printf("%d ", i);
        }
    
    }else{
        for (int i = 0; i < 6; i++){ 
            printf("%.2d|",i); // Inserindo a nota que tera sua frequencia exibida
            for (int j = 0; j < freq[i]; j++){
                printf("◼"); // Inserindo um "◼" para cada contador da frequencia
                //Ex.: 1 (aparecendo 5 vezes)| ◼◼◼◼◼
            }
            puts("\t(:c)"); // Notas abaixo de 6 recebem rostinhos tristes
        }
        // Inserindo a frequencia do restante dos valores
        for (int i = 6; i < 11; i++){
        printf("%.2d|",i);

        for (int j = 0; j < freq[i]; j++){
            printf("◼");
        }
        puts("\t(:D)"); // Notas a partir de 6 recebem um rostinho feliz
        }
    }
    putchar('\n');
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