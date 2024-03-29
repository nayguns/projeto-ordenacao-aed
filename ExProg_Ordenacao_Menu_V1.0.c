/*
    Centro Universit�rio de Goias - Uni-Anhanguera
    Disciplina: Algoritmos e Programacao Estruturada
    Professor:  Sandro Teixeira Carvalho
    Alunos(a):  Gabriel de Castro Costa         -   202113117
                Gustavo Muller Bueno Lagares    -   202151136
    Objetivo:   Desenvolvimento de programa com algoritmos para
                variados metodos de ordenacao, com menu de selecao
                e contagem de tempo de execucao de cada metodo.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZEARRAY 3000000
#define LIMITRAND 90000


int menuPrograma();
void menuProgramaAciona(int opcao, unsigned long int *arrayCalled);
void preencherArray(unsigned long int *array, int sizeArray, unsigned long int limitRand);
void imprimirArray(unsigned long int *array, int sizeArray);
void ordenaBubbleSort(unsigned long int *array, int sizeArray);
void ordernaInsertionSort(unsigned long int *array, int sizeArray);
void ordenaSelectionSort(unsigned long int *array, int sizeArray);
void ordenaHeapSort(unsigned long int *array, int N);
void ordenaQuickSort(unsigned long int *array, int inicio, int fim);
void ordenaMergeSort(unsigned long int *array, int sizeArr);
void sort(unsigned long int *array, unsigned long int *arrayTmp, int initArr, int endArr);
void merge(unsigned long int *array, unsigned long int *arrayTmp, int initArr, int midArr, int endArr);
void ordenaShellSort(unsigned long int *array, int sizeArray);
int checarArrayVazio(unsigned long int *array, int sizeArray, unsigned long int limit);


//Main
int main(void){

    int opcaoSelect;
    static unsigned long int emptyArray[SIZEARRAY];

    do {
        opcaoSelect = menuPrograma();
        menuProgramaAciona(opcaoSelect, emptyArray);
    }
    while(opcaoSelect != 0);

    return 0;
}


//Menu com opcoes
int menuPrograma(){
    int opcaoMenu;

    printf("********** PROGRAMA COM METODOS DE ORDENACAO **********");
    printf("\n\nEscolha uma das opcoes abaixo: \n\n");
    printf("  (1) Preencher o array com numeros aleatorios\n");
    printf("  (2) Ordenar o array pelo metodo Bubble Sort\n");
    printf("  (3) Ordenar o array pelo metodo Insertion Sort\n");
    printf("  (4) Ordenar o array pelo metodo Selection Sort\n");
    printf("  (5) Ordenar o array pelo metodo Heap Sort\n");
    printf("  (6) Ordenar o array pelo metodo Quick Sort\n");
    printf("  (7) Ordenar o array pelo metodo Merge Sort\n");
    printf("  (8) Ordenar o array pelo metodo Shell Sort\n");
    printf("  (9) Imprimir o array...\n");
    printf("  (0) Para sair..\n\n");
    printf("  Opcao: ");
    scanf("  %d", &opcaoMenu);

    return opcaoMenu;
}


//Menu com acoes
void menuProgramaAciona(int opcao, unsigned long int *arrayCalled){

    clock_t timer;
    unsigned long int limitRand = LIMITRAND;

    switch(opcao)
    {

        case 0: break;

        case 1:
            preencherArray(arrayCalled, SIZEARRAY, limitRand);
            printf("\n    Array preenchido com %d posicoes!\n\n\n", SIZEARRAY);
        break;

        case 2:
            if (checarArrayVazio(arrayCalled, SIZEARRAY, limitRand) == 1) {
                printf("\n    --- Metodo Bubble Sort selecionado ---\n\n");
                timer = clock();
                printf("    Ordenando... \n");
                ordenaBubbleSort(arrayCalled, SIZEARRAY);
                timer = clock() - timer;
                printf("    Pronto, a ordenacao levou %.3fs\n\n", ((float) timer / CLOCKS_PER_SEC));
            } else {
                printf("\n    O array ainda nao foi preenchido. Tente novamente..\n\n");
            }
        break;

        case 3:
            if (checarArrayVazio(arrayCalled, SIZEARRAY, limitRand) == 1) {
                printf("\n    --- Metodo Insertion Sort selecionado ---\n\n");
                timer = clock();
                printf("    Ordenando... \n");
                ordernaInsertionSort(arrayCalled, SIZEARRAY);
                timer = clock() - timer;
                printf("    Pronto, a ordenacao levou %.3fs\n\n", ((float) timer / CLOCKS_PER_SEC));
            } else {
                printf("\n    O array ainda nao foi preenchido. Tente novamente..\n\n");
            }
        break;

        case 4:
            if (checarArrayVazio(arrayCalled, SIZEARRAY, limitRand) == 1) {
                printf("\n    --- Metodo Selection Sort selecionado ---\n\n");
                timer = clock();
                printf("    Ordenando... \n");
                ordenaSelectionSort(arrayCalled, SIZEARRAY);
                timer = clock() - timer;
                printf("    Pronto, a ordenacao levou %.3fs\n\n", ((float) timer / CLOCKS_PER_SEC));
            } else {
                printf("\n    O array ainda nao foi preenchido. Tente novamente..\n\n");
            }
        break;

        case 5:
            if (checarArrayVazio(arrayCalled, SIZEARRAY, limitRand) == 1) {
                printf("\n    --- Metodo Heap Sort selecionado! ---\n\n");
                timer = clock();
                printf("    Ordenando... \n");
                ordenaHeapSort(arrayCalled, SIZEARRAY);
                timer = clock() - timer;
                printf("    Pronto, a ordenacao levou %.3fs\n\n", ((float) timer / CLOCKS_PER_SEC));
            } else {
                printf("\n    O array ainda nao foi preenchido. Tente novamente..\n\n");
            }
        break;

        case 6:
            if (checarArrayVazio(arrayCalled, SIZEARRAY, limitRand) == 1) {
                printf("\n    --- Metodo Quick Sort selecionado! ---\n\n");
                timer = clock();
                printf("    Ordenando... \n");
                ordenaQuickSort(arrayCalled, 0, SIZEARRAY);
                timer = clock() - timer;
                printf("    Pronto, a ordenacao levou %.3fs\n\n", ((float) timer / CLOCKS_PER_SEC));
            } else {
                printf("\n    O array ainda nao foi preenchido. Tente novamente..\n\n");
            }
        break;

        case 7:
            if (checarArrayVazio(arrayCalled, SIZEARRAY, limitRand) == 1) {
                printf("\n    --- Metodo Merge Sort selecionado ---\n\n");
                timer = clock();
                printf("    Ordenando... \n");
                ordenaMergeSort(arrayCalled,SIZEARRAY);
                timer = clock() - timer;
                printf("    Pronto, a ordenacao levou %.3fs\n\n", ((float) timer / CLOCKS_PER_SEC));
            } else {
                printf("\n    O array ainda nao foi preenchido. Tente novamente..\n\n");
            }
        break;

        case 8:
            if (checarArrayVazio(arrayCalled, SIZEARRAY, limitRand) == 1) {
                printf("\n    --- Metodo Shell Sort selecionado! ---\n\n");
                timer = clock();
                printf("    Ordenando... \n");
                ordenaShellSort(arrayCalled, SIZEARRAY);
                timer = clock() - timer;
                printf("    Pronto, a ordenacao levou  %.3fs\n\n", ((float) timer / CLOCKS_PER_SEC));
            } else {
                printf("\n    O array ainda nao foi preenchido. Tente novamente..\n\n");
            }
        break;

        case 9:
            if (checarArrayVazio(arrayCalled, SIZEARRAY, limitRand) == 1) {
                imprimirArray(arrayCalled, SIZEARRAY);
            } else {
                printf("\n    O array ainda nao foi preenchido. Tente novamente..\n\n");
            }
        break;

        default:
            printf("Opcao Invalida\n");
    }
}


//Metodo para preencher array
void preencherArray(unsigned long int *array, int sizeArray, unsigned long int limitRand){
    unsigned long int countA;

    srand(time(NULL));

    for(countA = 0; countA < sizeArray; countA++){
        array[countA] = 1+((rand() * rand())%limitRand);
    }
}


//Metodo para imprimir o array preenchido
void imprimirArray(unsigned long int *array, int sizeArray){
    unsigned long int countB;
    int flagLimit = 0;
    const int VISUALLIMIT = 100;

    printf("\n");

    for(countB = 0; countB < sizeArray; countB++){

        if(countB < VISUALLIMIT || countB > sizeArray - (VISUALLIMIT + 1)) {
            printf("%lu ", array[countB]);
        } else {
            if (flagLimit == 0){
                printf(" ... ");
                flagLimit = 1;
            }
        }

    }

    printf("\n\n");
}


//Metodo para ordenacao - BubbleSort
void ordenaBubbleSort(unsigned long int *array, int sizeArray) {
    int loopOutPos, loopInPos, varAuxCh;

    for (loopOutPos = 0; loopOutPos < sizeArray - 1; loopOutPos++){
        for(loopInPos = loopOutPos + 1; loopInPos < sizeArray; loopInPos++){
            if(array[loopOutPos] > array[loopInPos]){
                varAuxCh = array[loopInPos];
                array[loopInPos] = array[loopOutPos];
                array[loopOutPos] = varAuxCh;
            }
        }
    }
}


//Metodo para ordenacao - Insertion Sort
void ordernaInsertionSort(unsigned long int *array, int sizeArray){

    int loopOut, loopIn, auxVar;

    for(loopOut = 1; loopOut < sizeArray; loopOut++) {
        auxVar = array[loopOut];
        for(loopIn = loopOut-1; loopIn >= 0 && auxVar < array[loopIn]; loopIn--) {
            array[loopIn+1] = array[loopIn];
        }
        array[loopIn+1] = auxVar;
     }

}


//Metodo para ordenacao - Selection Sort
void ordenaSelectionSort(unsigned long int *array, int sizeArray){
    int loopOutPos, loopInPos, minValue, auxVar;

    for (loopOutPos = 0; loopOutPos < (sizeArray-1); loopOutPos++) {
        minValue = loopOutPos;
        for (loopInPos = (loopOutPos+1); loopInPos < sizeArray; loopInPos++) {
            if(array[loopInPos] < array[minValue]) {
                minValue = loopInPos;
            }
        }
        if(array[loopOutPos] != array[minValue]) {
            auxVar = array[loopOutPos];
            array[loopOutPos] = array[minValue];
            array[minValue] = auxVar;
        }
    }
}

void troca(unsigned long int* a, unsigned long int* b)
{
    unsigned long int temp = *a;

    *a = *b;

    *b = temp;
}


void heapify(unsigned long int *array, int N, int i)
{

    int maior = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;

    if (esquerda < N && array[esquerda] > array[maior])

        maior = esquerda;


    if (direita < N && array[direita] > array[maior])

        maior = direita;


    if (maior != i) {

        troca(&array[i], &array[maior]);

        heapify(array, N, maior);
    }
}

//Metodo para ordenacao - Heap Sort
void ordenaHeapSort(unsigned long int *array, int N){

    for (int i = N / 2 - 1; i >= 0; i--)

        heapify(array, N, i);

    // Heap sort
    for (int i = N - 1; i >= 0; i--) {

        troca(&array[0], &array[i]);

        heapify(array, i, 0);
    }
}

// Metodo para ordenacao - Quick Sort

void ordenaQuickSort(unsigned long int *array, int inicio, int fim)
{
	int i, j, pivo, aux;
	i = inicio;
	j = fim-1;
	pivo = array[(inicio + fim) / 2];
	while(i <= j)
	{
		while(array[i] < pivo && i < fim)
		{
			i++;
		}
		while(array[j] > pivo && j > inicio)
		{
			j--;
		}
		if(i <= j)
		{
			aux = array[i];
			array[i] = array[j];
			array[j] = aux;
			i++;
			j--;
		}
	}
	if(j > inicio)
		ordenaQuickSort(array, inicio, j+1);
	if(i < fim)
		ordenaQuickSort(array, i, fim);
}


//Metodo para ordenacao - Merge Sort
void ordenaMergeSort(unsigned long int *array, int sizeArr) {
    unsigned long int *arrayTmp = malloc(sizeof(int) * sizeArr);
    sort(array, arrayTmp, 0, sizeArr - 1);
    free(arrayTmp);
}

void sort(unsigned long int *array, unsigned long int *arrayTmp, int initArr, int endArr) {
    if (initArr >= endArr) return;

    int midArr = (initArr + endArr) / 2;

    sort(array, arrayTmp, initArr, midArr);
    sort(array, arrayTmp, midArr + 1, endArr);

    if (array[midArr] <= array[midArr + 1]) return;

    merge(array, arrayTmp, initArr, midArr, endArr);
}

void merge(unsigned long int *array, unsigned long int *arrayTmp, int initArr, int midArr, int endArr) {
    int auxVar,
        initMainArr = initArr, initTmpArr = midArr + 1;

    for (auxVar = initArr; auxVar <= endArr; auxVar++) arrayTmp[auxVar] =  array[auxVar];

    auxVar = initArr;

    while (initMainArr <= midArr && initTmpArr <= endArr) {
        if (arrayTmp[initMainArr] <= arrayTmp[initTmpArr])  array[auxVar++] = arrayTmp[initMainArr++];
        else  array[auxVar++] = arrayTmp[initTmpArr++];
    }

    while (initMainArr <= midArr)  array[auxVar++] = arrayTmp[initMainArr++];

    while (initTmpArr <= endArr)  array[auxVar++] = arrayTmp[initTmpArr++];

}


//Metodo para ordenacao - Shell Sort
void ordenaShellSort(unsigned long int *array, int sizeArray){
    int loopOut, loopIn, valueVar;
    int gapVar = 1;

    while(gapVar < sizeArray){
        gapVar = 3*gapVar+1;
    }

    while(gapVar > 1) {
        gapVar = gapVar / 3;
        for(loopOut = gapVar; loopOut < sizeArray; loopOut++){
            valueVar = array[loopOut];
            loopIn = loopOut - gapVar;
            while(loopIn >= 0 && valueVar < array[loopIn]) {
                array[loopIn + gapVar] = array[loopIn];
                loopIn = loopIn - gapVar;
            }
            array [loopIn + gapVar] = valueVar;
        }
    }
}


//Metodo para checar Array cheio
int checarArrayVazio(unsigned long int *array, int sizeArray, unsigned long int limit){
    unsigned long int countA;
    for(countA = 0; countA < sizeArray; countA++){
        if (array[countA] > limit || array[countA] < 0){
            return -1;
        }
    }
    return 1;
}
