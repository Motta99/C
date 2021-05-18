/*30) Escreva uma função recursiva espelhar uma árvore T e retornar uma nova árvore T, mas com 
as subárvores esquerda e direita de todos os nós trocadas.*/


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

void inorder(struct tree *raiz)
{
    if(raiz != NULL)
    {
        inorder(raiz -> esq);
        printf("%d \t", raiz -> chave);
        inorder(raiz -> dir);
    }
}

void troca(struct tree *raiz)
{
    struct tree *aux;

    if(raiz != NULL)
    {
        if (raiz->esq && raiz->esq)
        {
            aux = raiz->esq;
            raiz->esq = raiz->dir;
            raiz->dir = aux;
        }
        troca(raiz->esq);
    }
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

    printf("\nÁrvore: ");
    inorder(t);

    troca(t);
    
    printf("\nÁrvore trocada: ");
    inorder(t);
}