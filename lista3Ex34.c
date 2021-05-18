/*34) Escreva uma função recursiva para testar se duas árvores binárias são iguais.*/


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

int compara(struct tree *t1, struct tree *t2)
{
    if((t1 != NULL) && (t2 != NULL))
    {
        compara(t1->esq, t2->esq);

        if (t1->chave != t2->chave)
            return 1;
        
        compara(t1->dir, t2->dir);
    }
}

int main()
{
    int n, x;

    struct tree *t1, *t2;

    t1 = t2 = NULL;

    printf("\nDigite quantos elementos voce deseja adicionar em t1: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
    {
        printf("\nDigite um valor para t1: ");
        scanf("%d", &x);

        t1 = insereABB(t1, x);
    }

    printf("\nDigite quantos elementos voce deseja adicionar em t2: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("\nDigite um valor para t2: ");
        scanf("%d", &x);

        t2 = insereABB(t2, x);
    }

    printf("\nT1: ");
    inorder(t1);

    printf("\nT2: ");
    inorder(t2);

    if (compara(t1, t2) == 1)
        printf("\nAs árvores são diferentes\n");
    else
        printf("\nAs árvores são iguais\n");
}