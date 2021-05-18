/*4) Escreva um programa que leia um vetor de inteiros. Em seguida, chame as seguintes funções
recursivas:
a) calcular e retornar a soma dos elementos no vetor;
b) calcular e retornar o valor mínimo do vetor;
c) calcular e retornar o valor máximo do vetor;
d) calcular e retornar a média dos valores no vetor;
e) imprimir os valores do vetor em ordem inversa (sem trocá-los de ordem no vetor).
*/

#include <stdio.h>
#include <stdlib.h>

#define n 5

int soma(int v[], int i)
{
    int x = 0;;

    if (i == 1)
        return v[0];
    
    return v[i-1] + soma(v, i - 1);
}

float media(int v[], int i)
{
    return soma(v, i)/i;
}

void inverso(int v[], int i)
{
    if (i == n - 1)
        printf("%d\t", v[i]);
        
    else
    {
        inverso(v, i + 1);
        printf("%d\t", v[i]);
    }

}

int maximo(int v[], int i)
{
    if (i == 1)
        return v[0];
    else 
    {
        int m;
        m = maximo(v, i - 1);

        if (m > v[i-1]) 
            return m;
        else 
            return v[i-1]; 
    }
}

int minimo(int v[], int i)
{
    if (i == 1)
        return v[0];
    else 
    {
        int m;
        m = minimo(v, i - 1);

        if (m < v[i-1]) 
            return m;
        else 
            return v[i-1]; 
    }
}

int main()
{
     int i, *v;

    v = (int *) malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        printf("\nDigite o valor para v1: ");
        scanf("%d",&v[i]);
    }
  
    printf("\nInverso = "); 
    inverso(v, 0);
    
    printf("\nSoma = %d\n", soma(v, n));

    printf("Média = %.2f\n", media(v, n));

    printf("Máximo = %d\n", maximo(v, n));

    printf("Minimo = %d\n", minimo(v, n));

    //liberando o espaço de memória alocado
    free(v);

    return 0;
}
