/*19) Escreva uma função recursiva que calcule a soma dos primeiros n cubos: S(n) = 13
 + 23
 + ...
+ n3 
.
*/

#include <stdio.h>

int cubo(int n)
{
    if(n == 1)
        return 1;
    
    return (n * n * n) + cubo(n - 1);
}

int main()
{
    int i;

    printf("\nDigite um valor: ");
    scanf("%d", &i);

    printf("\nSérie: %d\n", cubo(i));
}
