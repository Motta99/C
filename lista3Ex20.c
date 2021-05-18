/*20) Escreva uma função recursiva para contar o número de caracteres maiúsculos que a string
possui.
*/

#include <stdio.h>
#include <stdlib.h> 
#include <ctype.h>


int caractere(char str[])
{
    if(str[0] == '\0')
    {
        return 0;
    }
    
    if (isupper(str[0]))
        return 1 + caractere(++str);
    
    return caractere(++str);
}

int main()
{
    char str[20];

    printf("\nDigite a string: ");
    gets(str);

    printf("\nQuantidade de caracteres maiusculos: %d\n", caractere(str));
}

