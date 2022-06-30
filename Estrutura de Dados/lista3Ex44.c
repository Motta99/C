/*44) Escreva uma função recursiva que retorna o número de nós cujos valores são múltiplos de
três.*/

#define TRUE 1
#define FALSE 0

#include <stdio.h>
#include <stdlib.h>


struct tree
{
    struct tree *esq;
    int chave;
    struct tree *dir;
};

struct tree *insereABB(struct tree *raiz, int valor) 
{
    struct tree *p,*t;
    int achou;
    
    p = (struct tree *) malloc( sizeof(struct tree));
    
    p->chave = valor;
    p->dir = p->esq = NULL;
    
    if(!raiz)
        raiz = p;
    
    else
    {
        achou = FALSE;
        t = raiz;
        
        while(!achou)
        {
            if(valor < t->chave)
            {
                if(t->esq == NULL)
                {
                    t->esq = p;
                    achou = TRUE;
                } 
                else
                    t = t->esq;
            }
            else 
                if(t->dir == NULL) 
                {
                    t->dir = p;
                    achou = TRUE;
                }
                else
                    t = t->dir;
        }
    }
    
    return raiz;
}

int multTres(struct tree *raiz)
{
    int n;
    if(!raiz)
        return 0;

    if (raiz->chave % 3 == 0)
        return 1 + multTres(raiz->esq) + multTres(raiz->dir);
        
    else
        return multTres(raiz->esq) + multTres(raiz->dir);
}

int main()
{
    int n, x;

    struct tree *t;

    t = NULL;

    printf("\nDigite quantos elementos você deseja adicionar: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
    {
        printf("\nDigite um valor: ");
        scanf("%d", &x);

        t = insereABB(t, x);
    }

    printf("\nA quantidade de valores multiplos de três é: %d\n", multTres(t));
}
