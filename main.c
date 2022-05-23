/*
>>>>>>>>>>> PROVA_PROGRAMAÇÃO_ESTRUTURADA <<<<<<<<<<<<<

* Professor: Igor Malheiros

>>>>>>>>>>>>>>>>>>>>>>>>>|<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
Alunos:
- Jonas Felipe | 20210026948
- Maria Raquel | 20200025900
*/

#include <stdio.h>
// #include <stdlib.h>

// void printar_arrays(int *array, int n){
//     for(int i=0; i<n; i++)
//         printf("%d ", array[i]);
//     putchar('\n');
// }

// void bubble_sort(int *notas, int n){
//     int temp = 0;
//     int troca;
//     do{
//         troca = 0;
//         for(int i = 0; i < n-1; i++){
//             if (notas[i] > notas[i+1]){
//                 temp = notas[i];
//                 notas[i] = notas[i+1];
//                 notas[i+1] = temp;
//                 troca = 1;
//             }
//         }
//     }while(troca);  
// }

// int repeticoes_nota(int *notas, int i){
//     if (notas[i] != notas[i+1])
//         return 0;
//     if (notas[i] == notas[i+1])
//         return 1 + repeticoes_nota(notas, i+1);
// }

// int *moda(int *notas, int n){

//     int modas[n], *modas_limpas, counts[n], maior_repeticao = 0, repeticoes = 0;

//     counts[n-1] = 0;
    
//     for(int i=0; i<n-1; i++)
//         counts[i] = repeticoes_nota(notas, i);

//     for(int i=0; i<n; i++)
//         if (counts[i] > maior_repeticao)
//             maior_repeticao = counts[i];

//     for(int i=0; i<n; i++){
//         if (counts[i] == maior_repeticao){
//             modas[i] = notas[i];
//             repeticoes++;
//         }
//         else modas[i] = -1;
//     }
    
//     modas_limpas = malloc(sizeof(int)*repeticoes);

//     for(int i=0, j=0; i<n; i++)
//         if (modas[i] != -1)
//             modas_limpas[j++] = modas[i];

//     return modas_limpas;
// }

int main(){
    int notas[13] = {5, 3, 3, 8, 7, 10, 10, -5, 2, 7, 12, 9, 10};
    int n = 13;
    return 0;

    printf("oi");

    return 0;
}