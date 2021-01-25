#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void intercalar(int *vetP, int inicio, int meio, int fim)
{
    int tamanho = fim - inicio + 1, k;
    int esquerdo = inicio;
    int direito = meio + 1;
    int fim_esquerdo = 0;
    int fim_direito = 0, *ordenado;
    ordenado = (int *)malloc(sizeof(int) * tamanho);
    printf("\n$inicio: %d\n$meio: %d\n$fim: %d\n", inicio, meio, fim);
    if (ordenado == NULL)
    {
        printf("PORRA");
    }

    for (int i = 0; i < tamanho; i++)
    {
        if (!fim_esquerdo && !fim_direito)
        {
            if (vetP[esquerdo] < vetP[direito])
            {
                ordenado[i] = vetP[esquerdo];
                esquerdo++;
            }
            else
            {
                ordenado[i] = vetP[direito];
                direito++;
            }
            if (esquerdo > meio)
            {
                fim_esquerdo = 1;
            }

            if (direito > fim)
            {
                fim_direito = 1;
            }
        }
        else
        {
            if (!fim_esquerdo)
            {
                ordenado[i] = vetP[esquerdo];
                esquerdo++;
            }
            else
            {
                ordenado[i] = vetP[direito];
                direito++;
            }
        }
    }

    for (int j = 0, k = inicio; j < tamanho; j++, k++)
    {
        vetP[k] = ordenado[j];
    }
}

int mergesort(int *vetP, int inicio, int fim)
{
    int meio;

    if (inicio < fim)
    {
        meio = floor((inicio + fim) / 2); //7
        printf("\ninicio: %d\nmeio: %d\nfim: %d\n", inicio, meio, fim);

        mergesort(vetP, inicio, meio);
        mergesort(vetP, meio+1, fim);
        intercalar(vetP, inicio, meio, fim);
    }
}

int main()
{

    int vet[8] = {12, 1, 4, 2, 6, 9, 8, 34}, *cu;
    cu = vet;
    mergesort(cu, 0, 8);

    for (int i = 0; i < 8; i++)
    {
        printf(" %d", cu[i]);
    }
}