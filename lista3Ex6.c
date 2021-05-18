/*6) Escreva uma função recursiva para fazer o produto interno entre dois vetores de mesmo
tamanho. Escreva também a chamada da função. Ex: Sejam v={1,2,3} e w={4,5,6} então o
prodint=1*4 + 2*5 + 3*6 = 4+10+18=32. Escreva também a chamada da função.
*/

#include <stdio.h>
#include <stdlib.h> 

int somaVetores(int v1[], int v2[], int n)
{
    if (n == 1)
        return v1[0] * v2[0];

    return v1[n-1] * v2[n-1] + somaVetores(v1, v2, n - 1);
    
}


int main()
{
    int i, n, *v1, *v2;

    printf("Informe o tamanho dos vetores\n");
    scanf("%d", &n);

    v1 = (int *) malloc(n * sizeof(int));
    v2 = (int *) malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        printf("\nDigite o valor para v1: ");
        scanf("%d",&v1[i]);

        printf("\nDigite o valor para v2: ");
        scanf("%d",&v2[i]);
    }
  
    printf("\nProduto interno de v1 e v2: %d\n", somaVetores(v1, v2, n));
  
    //liberando o espaço de memória alocado
    free(v1);
    free(v2);

    return 0;
}