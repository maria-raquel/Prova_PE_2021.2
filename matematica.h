/*
>>>>>>>>>>> PROVA_1_PROGRAMAÇÃO_ESTRUTURADA <<<<<<<<<<<<<

* Professor: Igor Malheiros

>>>>>>>>>>>>>>>>>>>>>>>>>>|<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
Alunos:
- Jonas Felipe | 20210026948
- Maria Raquel | 20200025900
*/

#ifndef MATEMATICA_H
#define MATEMATICA_H

//>================== Assinatura de funcoes: ==================
//>=================== FUNCOES MATEMATICAS: ===================

float desvio_padrao(int *notas, int n);
float media(int *notas, int n);
float mediana(int *notas, int n);
int *moda(int *notas, int n, int *tm);
int valor_maximo(int *notas, int n);
int valor_minimo(int *notas, int n);

#endif