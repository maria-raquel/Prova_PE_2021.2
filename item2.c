/*
>>>>>>>>>>> PROVA_PROGRAMAÇÃO_ESTRUTURADA <<<<<<<<<<<<<

* Professor: Igor Malheiros

>>>>>>>>>>>>>>>>>>>>>>>>>|<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
Alunos:
- Jonas Felipe | 20210026948
- Maria Raquel | 20200025900
*/ 

#include <stdio.h>
#include <math.h>

float media(int *notas, int n){
    float soma = 0;

    for (int i = 0; i < n; i++)
        soma += notas[i];
    
    return soma/n;
}

void bubble_sort(int *notas, int n){
    int temp = 0;
    int troca;
    do{
        troca = 0;
        for(int i = 0; i < n-1; i++){
            if (notas[i] > notas[i+1]){
                temp = notas[i];
                notas[i] = notas[i+1];
                notas[i+1] = temp;
                troca = 1;
            }
        }
    }while(troca);  
}

float mediana(int *notas, int n){
    
    bubble_sort(notas, n);
    
    if (n%2 == 0)
        return (notas[n/2-1] + notas[n/2])/2.0;
    if (n%2 == 1)
        return notas[n/2];
}

float desvio_padrao(int *notas, int n){
    float soma = 0, m;
    m = media(notas, n);

    for (int i=0; i<n; i++)
        soma += pow((notas[i]-m), 2);
    
    soma /= n;

    return sqrt(soma);
}

int valor_maximo(int *notas, int n){
    int maior = 0;

    for (int i = 0; i < n; i++){
        if (notas[i] == 10)
            return 10;
        if (notas[i] > maior)
            maior = notas[i];
    }

    return maior;
}

int valor_minimo(int *notas, int n){
    int menor = 10;

    for (int i = 0; i < n; i++){
        if (notas[i] == 0)
            return 0;
        if (notas[i] < menor)
            menor = notas[i];
        }
    return menor;
}