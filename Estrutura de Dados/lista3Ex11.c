/*11) Escreva uma função recursiva que recebe uma string e retorne a ocorrência de uma
determinada letra na string.
*/

#include <stdio.h>
#include <stdlib.h> 


int caractere(char str[], char c)
{
    if(str[0] == '\0')
    {
        return 0;
    }
    
    if (str[0] == c)
        return 1 + caractere(++str, c);
    
    return caractere(++str, c);
}

int main()
{
    char c, str[20];

    printf("\nDigite a string: ");
    gets(str);

    printf("\nDigite um caracter para saber a quantidade: ");
    scanf("%c", &c);

    printf("\nQuantidade: %d\n", caractere(str, c));
}
