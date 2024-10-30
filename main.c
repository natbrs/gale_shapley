#include "gs.c"

int main(){
    printf("Informe o número de candidatos e setores: ");
    scanf("%d", &n);
    printf("Informe as preferências dos candidatos:\n");
    for(int i=0;i<n;i++){
        printf("Candidato %d:\n",i+1);
        for(int j=0;j<n;j++){
            scanf("%d", &Candidatos[i][j]);
            Candidatos[i][j]--;}
    }
    printf("Informe as preferências dos setores:\n");
    for(int i=0;i<n;i++){
        printf("Setor %d:\n",i+1);
        for (int j=0;j<n;j++) {
            scanf("%d", &Setores[i][j]);
            Setores[i][j]--;}
    }
    initPrefInv();
    galeShapley();
    ImprimeMatching();

    return 0;
}