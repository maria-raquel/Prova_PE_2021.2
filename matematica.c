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
#include "matematica.h"
#include "limpeza.h"

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

    limpeza(notas, n);

    int modas[11], *modas_limpas, freq[11] = {0}, maior_repeticao = 0, repeticoes = 0;

    // Preenchendo o array freq com a quantidade de vezes que cada nota se repete no array notas
    
    for(int i = 0; i < n; i++)
        freq[notas[i]]++;

    // Verificando quantos valores de nota se repetem mais e adicionando-os a um array de modas

    maior_repeticao = valor_maximo(freq, 11);

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
