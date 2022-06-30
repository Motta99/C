/*22 - 
a) O que essa função faz? Explique com um exemplo.
R: Faz a soma dos "a" primeiros números

b) Calcule a sua ordem de complexidade. Mostre como você chegou a esse resultado. 
R:  
int eureka(int a) 
{ 
    if (a <= 0)---------------------- n + 1
        return 0;-------------------- 1 
    else  
        return (a + eureka(a-1));---- n
}

    ----> n + 1 + 1 + n = 2n + 2. A ordem de complexidade do algoritmo é linear (O(n))

c) Escreva uma função não-recursiva que resolve o mesmo problema. Qual é a ordem de
complexidade da sua função? Explique. 
R:  
    int soma = 0;--------------------- 1

    for (int i = 1; i <= a; i++)------- n - 1 + 1 = n
    {
        soma += i;-------------------- n
    }

    return soma;---------------------- 1

    ----> n + n + 1 + 1 = 2n + 2. A ordem de complexidade do algoritmo é linear (O(n))

d) Qual implementação é mais eficiente? Justifique.
R: Os algoritos tem a mesma complexidade e executam o mesmo número de passos, então eles vão ter a mesma eficiencia.
     _________________________________
    |     n     | 1 | 2 | 3 |  4 |  5 |
    | iterativo | 4 | 6 | 8 | 10 | 12 |
    | recursivo | 4 | 6 | 8 | 10 | 12 |
     ---------------------------------

40) Porque é importante que uma Árvore Binária de Busca sempre esteja balanceada?
R: Isso ocorre porque a complexidade do algoritmo, em uma árvore binária, está diretamente relacionado com a sua altura, com isso uma árvore balanceada vai ter uma complexidade menor do que uma árvore não balanceada, resultando em um menor tempo de processamento.
 */
#include <stdio.h>

int eureka(int a) 
{ 
    if (a <= 0) 
        return 0; 
    else  
        return (a + eureka(a-1)); 
}

int funcaoNaoRecursivaParaResolverOProblema(int a) 
{ 
    int soma = 0;

    for (int i = 1; i <= a; i++)
    {
        soma += i; 
    }

    return soma;
}

int main()
{
    int n;

    printf("\nDigite um número: ");
    scanf("%d", &n);

    printf("\nExemplo da a: %d\n", eureka(n));

    printf("\nExemplo da c: %d\n", funcaoNaoRecursivaParaResolverOProblema(n));
    return 0;
}
