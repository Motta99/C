/*43) Escreva uma função recursiva para achar o pai de uma chave passada numa árvore binária,
retornando referência do nó pai ou NULL, caso não exista o pai.
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

struct tree *buscaRec(struct tree *raiz, int x) 
{
    
    if(raiz)
    {
        if((raiz->dir && x == raiz->dir->chave) || (raiz->esq && x == raiz->esq->chave))
            return(raiz);
        
        if(x < raiz->chave)
            return(buscaRec(raiz->esq, x));
        
        if(x > raiz->chave)
            return(buscaRec(raiz->dir, x));
    }

    return(NULL);
}


int main()
{
    int n, x;

    struct tree *t, *no;

    t = NULL;

    printf("\nDigite quantos elementos você deseja adicionar: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
    {
        printf("\nDigite um valor: ");
        scanf("%d", &x);

        t = insereABB(t, x);
    }

    printf("\nDigite a chave: ");
    scanf("%d", &x);

    no = buscaRec(t, x);
    
    if (no)
    {
        printf("\nChave do nó pai: %d\n", no->chave);
        
        if (no->dir)
            printf("\nChave filho da direita: %d\n", no->dir->chave);

        if (no->esq)
            printf("\nChave filho da esquerda: %d\n", no->esq->chave);
    }
    else 
        printf("\nA chave não tem nó pai\n");
}
