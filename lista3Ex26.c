/*26) Faça uma função recursiva que retorne a quantidade de nós de uma árvore binária de busca
que possuem apenas um filho.
*/

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

int nFilhos(struct tree *raiz) 
{
    int n;

    if (!raiz)   
        return 0;
    else
    {
        if ((raiz->esq != NULL && raiz->dir == NULL) || (raiz->esq == NULL && raiz->dir != NULL))
            n = 1;
        else
            n = 0;

        return n + nFilhos(raiz->dir) + nFilhos(raiz->esq);
    }
}

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

int main()
{
    int n, x;

    struct tree *t;

    t = NULL;

    printf("\nDigite quantos elementos voce deseja adicionar na árvore: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
    {
        printf("\nDigite um valor: ");
        scanf("%d", &x);

        t = insereABB(t, x);
    }

    printf("\nNós com apenas um filho: %d\n", nFilhos(t));
}