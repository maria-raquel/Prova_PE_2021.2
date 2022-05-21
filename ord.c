#include <stdio.h>
void bubble_sort(int *notas, int tam);

void bubble_sort(int *notas, int tam){
    int temp = 0;
    int troca;
    do{
        troca = 0;
        for(int i = 0; i < tam-1; i++){
            if (notas[i] > notas[i+1]){
                temp = notas[i];
                notas[i] = notas[i+1];
                notas[i+1] = temp;
                troca = 1;
            }
        }
    }while(troca);  
}


int main(){
    int notas[13] = {5, 3, 3, 8, 7, 10, 10, -5, 2, 7, 12, 9,10};
    for (int i = 0; i < 13; i++){
        printf("%d, ", notas[i]);
    }
    printf("\n");
    bubble_sort(notas, 13);
    for (int i = 0; i < 13; i++){
        printf("%d, ", notas[i]);
    }
    printf("\n");
}