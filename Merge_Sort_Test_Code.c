#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZEARRAY 100000
#define LIMITRAND 75000

void mergesort(int *v, int n);
void sort1(int *v, int *c, int i, int f);
void merge1(int *v, int *c, int i, int m, int f);
void preencherArray(int *array);
void ordenaMergeSort(int *mainArr, int sizeArray);
void sort(int *mainArr, int *tempArray, int initArray, int endArray);
void merge(int *mainArr, int *tempArray, int initArray, int midArray, int endArray);

int main (void) {
  int i;
  int v[SIZEARRAY];

  preencherArray(v);
  //mergesort(v, SIZEARRAY);
  ordenaMergeSort(v, SIZEARRAY);

  for (i = 0; i < SIZEARRAY; i++) printf("%d ", v[i]);

  putchar('\n');

  return 0;
}



void preencherArray(int *array){
    int countA;

    srand(time(NULL));

    for(countA = 0; countA < SIZEARRAY; countA++){
        array[countA] = 1+(rand()%LIMITRAND);
    }
}



/*
  Dado um vetor de inteiros v e um inteiro n >= 0, ordena o vetor v[0..n-1] em ordem crescente.
*/
void mergesort(int *v, int n) {
  int *c = malloc(sizeof(int) * n);
  sort(v, c, 0, n - 1);
  free(c);
}

/*
  Dado um vetor de inteiros v e dois inteiros i e f, ordena o vetor v[i..f] em ordem crescente.
  O vetor c é utilizado internamente durante a ordenação.
*/
void sort1(int *v, int *c, int i, int f) {
  if (i >= f) return;

  int m = (i + f) / 2;

  sort(v, c, i, m);
  sort(v, c, m + 1, f);

  /* Se v[m] <= v[m + 1], então v[i..f] já está ordenado. */
  if (v[m] <= v[m + 1]) return;

  merge(v, c, i, m, f);
}


/*
  Dado um vetor v e três inteiros i, m e f, sendo v[i..m] e v[m+1..f] vetores ordenados,
  coloca os elementos destes vetores, em ordem crescente, no vetor em v[i..f].
*/
void merge1(int *v, int *c, int i, int m, int f) {
  int z,
      iv = i, ic = m + 1;

  for (z = i; z <= f; z++) c[z] = v[z];

  z = i;

  while (iv <= m && ic <= f) {
    /* Invariante: v[i..z] possui os valores de v[iv..m] e v[ic..f] em ordem crescente. */

    if (c[iv] <= c[ic]) v[z++] = c[iv++];
    else v[z++] = c[ic++];
  }

  while (iv <= m) v[z++] = c[iv++];

  while (ic <= f) v[z++] = c[ic++];
}




//Metodo para ordenacao - Selection Sort
void ordenaMergeSort(int *mainArr, int sizeArray) {
    int *tempArr = malloc(sizeof(int) * sizeArray);
    sort(mainArr, tempArr, 0, sizeArray - 1);
    free(tempArr);
}

void sort(int *mainArr, int *tempArr, int initArr, int endArr){
    if (initArr >= endArr) return;

    int midArr = (initArr + endArr) / 2;

    sort(mainArr, tempArr, initArr, midArr);
    sort(mainArr, tempArr, midArr + 1, endArr);

    if (mainArr[midArr] <= mainArr[midArr + 1]) return;

    merge(mainArr, tempArr, initArr, midArr, endArr);
}

void merge(int *mainArr, int *tempArr, int initArr, int midArr, int endArr){
    int auxVar, initMnArr = initArr, initTpArr = midArr + 1;

    for(auxVar = initArr; auxVar <= endArr; auxVar++) tempArr[auxVar] = mainArr[auxVar];

    auxVar = initArr;

    while (initMnArr <= midArr && initTpArr <= endArr) {
        if (tempArr[initMnArr] <= tempArr[initTpArr]) mainArr[auxVar++] = tempArr[initMnArr];
        else mainArr[auxVar++] = tempArr[initTpArr];
    }

    while (initMnArr <= midArr) mainArr[auxVar++] = tempArr[initMnArr++];

    while (initTpArr <= endArr)  mainArr[auxVar++] = tempArr[initTpArr++];

}
