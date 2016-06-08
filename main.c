#include <stdio.h>
#include <stdlib.h>

void quickSort(int vet[], int esq, int dir){
  int i, j, pivo, aux;
  i = esq;
  j = dir;
  pivo = vet[(esq+dir)/2];
  printf("Pivo: %d\n", pivo);

  while(i <= j){
    while(vet[i] < pivo && i < dir){
        i++;
    }
    while(vet[j] > pivo && j > esq){
        j--;
    }
    if(i <= j){
        printf("Trocas: %d %d\n", vet[i], vet[j]);
        aux = vet[i];
        vet[i] = vet[j];
        vet[j] = aux;
        i++;
        j--;
    }
    int cont;
    for(cont = 0; cont < 10; cont++){
        printf("%d ", vet[cont]);
    }
    printf("\n");
  }
  if(j > esq){
    printf("Ramo esquerdo:\n");
    quickSort(vet, esq, j);
  }
  if(i < dir){
      printf("Ramo direito:\n");
    quickSort(vet,i, dir);
  }
}

int main(int argc, const char* argv[]){

    int tam = 10, i;
    int vet[10] = {8,1,7,2,3,4,5,9,0,6};
    /*
    printf("Informe o tamanho do vetor: ");
    scanf("%d", &tam);

    int vet[tam], i;

    for(i = 0; i < tam; i++){
      scanf("%d", &vet[i]);
    }
    */

    quickSort(vet,0,tam-1);

    for(i = 0; i < tam; i++){
      printf("%d ", vet[i]);
    }
    printf("\n");

    return 0;
}
