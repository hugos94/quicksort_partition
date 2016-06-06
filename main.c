#include <stdio.h>
#define TAM 10

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
    int vet[TAM], i;

    for(i = 0; i < TAM; i++){
      scanf("%d", &vet[i]);
    }

    quickSort(vet,0,TAM-1);

    for(i = 0; i < TAM; i++){
      printf("%d ", vet[i]);
    }
    printf("\n");

    return 0;
}
