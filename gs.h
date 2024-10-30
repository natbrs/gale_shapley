#include <stdio.h>
#include <stdlib.h>
#define maxNum 100

int n;
int Candidatos[maxNum][maxNum];
int Setores[maxNum][maxNum];
int Matching[maxNum];         
int ProxSetor[maxNum];  
int PrefInversa[maxNum][maxNum];
int Livre[maxNum];