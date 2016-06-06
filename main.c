#include <stdio.h>
#include <stdlib.h>

void quickSort(int vet[], int esq, int dir){
  int i, j, x, y;
  i = esq;
  j = dir;
  x = vet[(esq+dir)/2];

  while(i <= j){
    while(vet[i] < x && i < dir){
        i++;
    }
    while(vet[j] > x && j > esq){
        j--;
    }
    if(i <= j){
        y = vet[i];
        vet[i] = vet[j];
        vet[j] = y;
        i++;
        j--;
    }
  }
  if(j > esq){
    quickSort(vet, esq, j);
  }
  if(i < dir){
    quickSort(vet,i, dir);
  }
}

int main(int argc, const char* argv[]){

    int tam = 0;

    printf("Informe o tamanho do vetor: ");
    scanf("%d", &tam);

    int vet[tam], i;

    for(i = 0; i < tam; i++){
      scanf("%d", &vet[i]);
    }

    quickSort(vet,0,tam-1);

    for(i = 0; i < tam; i++){
      printf("%d ", vet[i]);
    }
    printf("\n");

    return 0;
}
