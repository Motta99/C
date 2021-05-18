/*9) Escreva uma função recursiva que calcule o valor da série S descrita a seguir para um valor
de n>0 a ser fornecido como parâmetro para a mesma: S= 1+1/2!+1/3!+ ...+1/n!. OBS. A função
fatorial também deve ser recursiva.
*/

#include <stdio.h>
#include <math.h>

int fatorial(int n) 
{
    if(n == 0) 
        return 1;
    
    return (n * fatorial(n-1));
}


float s(int n)
{
    float x;

    if (n == 1)
        return 1;

    return pow(fatorial(n), -1) + s(n-1);
}

int main()
{
    int i;

    printf("\nDigite um valor para série: ");
    scanf("%d", &i);

    printf("\nSérie: %.10f\n", s(i));
}