/*45) Escreva uma função que retorne o números de nós de uma ABB cujo o valor é maior que x.
No caso da árvore ser vazia deverá ser retornado o valor 0. 
Protótipo: int conta_Maiores(struct tree *raiz, int x);*/


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

int contaMaiores(struct tree *raiz, int x)
{
    if(!raiz)
        return 0;

    if (raiz->chave > x)
        return 1 + contaMaiores(raiz->esq, x) + contaMaiores(raiz->dir, x);

    else
        return contaMaiores(raiz->esq, x) + contaMaiores(raiz->dir, x);
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

    printf("\nDigite um valor para x: ");
    scanf("%d", &x);

    printf("\nA quantidade de valores maiores que %d é: %d\n", x, contaMaiores(t, x));
}