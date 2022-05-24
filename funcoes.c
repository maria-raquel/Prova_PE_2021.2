/*
>>>>>>>>>>> PROVA_1_PROGRAMAÇÃO_ESTRUTURADA <<<<<<<<<<<<<

* Professor: Igor Malheiros

>>>>>>>>>>>>>>>>>>>>>>>>>>|<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
Alunos:
- Jonas Felipe | 20210026948
- Maria Raquel | 20200025900
*/

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "funcoes.h"

//>================== LIMPEZA E ORGANIZACAO DOS DADOS: ==================

/*Funcao que realiza a limpeza de notas invalidas nos dados. 
  Notas maiores que 10 são transformadas em 10, e menores que 0 em 0.
    > int *notas = array de notas 
    > int n = tamanho do array
*/
void limpeza(int *notas, int n){
    for (int i = 0; i < n; i++){
        if (notas[i] > 10){
            notas[i] = 10;
        }
        if (notas[i] < 0){
            notas[i] = 0;
        }
    }
}

/*Funcao que organiza o array de notas em ordem crescente, pelo metodo bubble sort
    > int *notas = array de notas 
    > int n = tamanho do array
*/
void ordenacao(int *notas, int n){
    int temp = 0;
    int troca;
    do{
        troca = 0; //a variavel troca indica se houve uma troca de valores na ordencao (inicia False)
        for(int i = 0; i < n-1; i++){ //percorre todos os elementos do array 
            if (notas[i] > notas[i+1]){ //se o valor do array for menor que o proximo ele realiza a troca
                temp = notas[i];
                notas[i] = notas[i+1];
                notas[i+1] = temp;
                troca = 1; //como houve troca a variavel "troca" recebe True
            }
        }
    }while(troca);  //enquanto houver trocas essa ordenacao e executada
}

//>================== FUNCOES MATEMATICAS: ==================

/*Funcao que retorna a media dos valores do array
    > int *notas = array de notas 
    > int n = tamanho do array
*/
float media(int *notas, int n){
    float soma = 0;

    for (int i = 0; i < n; i++)
        soma += notas[i];
    
    return soma/n;
}

/*Funcao que retorna a mediana dos valores do array
    > int *notas = array de notas 
    > int n = tamanho do array
*/
float mediana(int *notas, int n){
    ordenacao(notas, n);
    if (n%2 == 0)
        return (notas[n/2-1] + notas[n/2])/2.0;
    if (n%2 == 1)
        return notas[n/2];
}

/*Funcao que retorna o desvio padrao dos valores do array
    > int *notas = array de notas 
    > int n = tamanho do array
*/
float desvio_padrao(int *notas, int n){
    float soma = 0, m;
    m = media(notas, n);

    for (int i=0; i<n; i++)
        soma += pow((notas[i]-m), 2);
    
    soma /= n;

    return sqrt(soma);
}

/*Funcao que retorna um array com a(s) moda(s) dos valores do array
  Ela tambem retorna o tamanho do array de modas atraves de um ponteiro
    > int *notas = array de notas 
    > int n = tamanho do array 
    > int *tm = ponteiro que aponta para a variavel do tamanho do array de modas
*/
int *moda(int *notas, int n, int *tm){

    int modas[n], *modas_limpas, freq[n], maior_repeticao = 0, repeticoes = 0;

    // Preenchendo o array freq com a quantidade de vezes que cada nota se repete no array notas
    
    for(int i = 0; i < n; i++)
        freq[notas[i]]++;

    // Verificando quantos valores de nota se repetem mais e adicionando-os a um array de modas

    maior_repeticao = valor_maximo(freq, 10);

    for(int i=0; i<11; i++){
        if (freq[i] == maior_repeticao){
            modas[i] = i;
            repeticoes++;
        }
        else modas[i] = -1;
    }

    // A variavel repeticoes representa o tamanho do array final
    // Retornando-a para a função main usando um ponteiro

    *tm = repeticoes; 
    
    // Criando o array final que a função retorna
    
    modas_limpas = malloc(sizeof(int)*repeticoes);

    for(int i=0, j=0; i<n; i++)
        if (modas[i] != -1)
            modas_limpas[j++] = modas[i];

    return modas_limpas;
}

/*Funcao que retorna o valor maximo presente no array
    > int *notas = array de notas
    > int n = tamanho do array
*/
int valor_maximo(int *notas, int n){
    int maior = 0;

    for (int i = 0; i < n; i++)
        if (notas[i] > maior)
            maior = notas[i];

    return maior;
}

/*Funcao que retorna o valor minimo presente no array
    > int *notas = array de notas
    > int n = tamanho do array
*/
int valor_minimo(int *notas, int n){
    int menor = 10;

    for (int i = 0; i < n; i++)
        if (notas[i] < menor)
            menor = notas[i];
        
    return menor;
}   

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