/*
>>>>>>>>>>> PROVA_PROGRAMAÇÃO_ESTRUTURADA <<<<<<<<<<<<<

* Professor: Igor Malheiros

>>>>>>>>>>>>>>>>>>>>>>>>>|<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
Alunos:
- Jonas Felipe | 20210026948
- Maria Raquel | 20200025900
*/
#include <stdio.h>

void clear(int *notas, int tam);

void clear(int *notas, int tam){
    for (int i = 0; i < tam; i++){
        if (notas[i] > 10){
            notas[i] = 10;
        }
        if (notas[i] < 0){
            notas[i] = 0;
        }
    }
}

void *moda(int *notas, int tam, int *m);
void *moda(int *notas, int tam, int *m){
    int freq[11] = {0};
    
    int maior = 0;    
    for(int i = 0; i < tam; i++){
        freq[notas[i]]++;
    }
       
    for (int i = 0; i <= 10; i++){
        if (freq[i] > maior){
            maior = freq[i];
        }
    }

    for (int i = 0; i < tam; i++){
        if (freq[notas[i]] == maior){
            m[notas[i]]++;
        }
    }

    for (int i = 0; i <= 10; i++){
        printf("%d, ", freq[i]);
    }

}

int main(){
    int m[11] = {0};

    int notas[13] = {5, 3, 3, 8, 7, 10, 10, 0, 2, 7, 12, 9, 10};
    clear(notas, 13);
    moda(notas, 13, m);
    for (int i = 0; i <= 10; i++){
        if(m[i] != 0){
            printf("%d, ", i);
        }
    }
}