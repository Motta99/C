/*12) Escreva uma função recursiva que recebe um número n e retorne a soma dos dígitos do
número.
*/

#include <stdio.h>

int somadig(int n)
{
    if (n == 0)
        return 0;
    else
        return (n % 10) + somadig(n / 10);
}

int main()
{
    printf("\n%d\n", somadig(55));

    return 0;
}
