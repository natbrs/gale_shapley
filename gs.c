#include <stdio.h>
#include <stdlib.h>
#include "gs.h" 

// inicia a matriz de preferências inversas
void initPrefInv(){
    for(int s=0;s<n;s++){
        for(int r=0;r<n;r++){
            int c=Setores[s][r];
            PrefInversa[s][c]=r;
        }
    }
}
// implementa o gale shapley
void galeShapley(){
    for(int i=0;i<n;i++){
        Livre[i]=1;
        Matching[i]=-1;
        ProxSetor[i]=0;
    }
    int cLivres=n;
    // enquanto nao houver candidatos livres
    while(cLivres>0){
        int cLivre;
        for(cLivre=0;cLivre<n;cLivre++){
            if(Livre[cLivre]){
                break; 
            }
        }
        // faz proposta ao seu setor preferido
        int sPreferido=Candidatos[cLivre][ProxSetor[cLivre]];
        ProxSetor[cLivre]++;
        // caso livre aceita o candidato
        if(Matching[sPreferido]==-1){
            Matching[sPreferido]=cLivre;
            Livre[cLivre]=0;
            cLivres--;
        } else{
            // setor com candidato, verifica um novo candidato
            int cAtual=Matching[sPreferido];
            if(PrefInversa[sPreferido][cLivre]<PrefInversa[sPreferido][cAtual]){
                Matching[sPreferido]=cLivre;
                Livre[cLivre]=0;
                Livre[cAtual]=1;
            }
        }
    }
}
// imprime o matching resultante
void ImprimeMatching(){
    printf("Matching final:\n");
    for(int s=0;s<n;s++){
        printf("Candidato %d com Setor %d\n",Matching[s]+1,s+1);
    }
}