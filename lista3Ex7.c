/*7) Escreva uma função recursiva para contar o número de ocorrências de um determinado
caractere em uma string. Escreva também a chamada da função.
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
