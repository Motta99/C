/*27) Dada uma estrutura de árvore binária de busca ou não. Escreva funções recursivas para:
- v Calcular a altura da árvore;
- v Determinar quantos nós da árvore são maiores que zero;
- v Determinar quantos nós tem dois filhos;
- Determinar se uma árvore binária é ABB.
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

struct tree *buscaRec(struct tree *raiz, int x) 
{
    
    if(raiz)
    {
        if(x == raiz->chave)
            return(raiz);
        
        if(x < raiz->chave)
            return(buscaRec(raiz->esq, x));
        
        if(x > raiz->chave)
            return(buscaRec(raiz->dir, x));
    }

    return(NULL);
}

int nFilhos(struct tree *raiz) 
{
    int n;

    if (!raiz)   
        return 0;
    else
    {
        if (raiz->esq != NULL && raiz->dir != NULL)
            n = 1;
        else
            n = 0;

        return n + nFilhos(raiz->dir) + nFilhos(raiz->esq);
    }
}

int maiorQueZero(struct tree *raiz)
{
    int n;

    if (!raiz)   
        return 0;

    if (raiz->chave > 0)
        return 1 + maiorQueZero(raiz->dir) + maiorQueZero(raiz->esq);
    else
        return  maiorQueZero(raiz->dir) + maiorQueZero(raiz->esq);
}

int eABB(struct tree *raiz)
{
    if (!raiz)   
        return 0;

    if ((raiz->esq && raiz->chave < raiz->esq->chave) || (raiz->dir && raiz->chave > raiz->dir->chave))
        return 1;
    
    return eABB(raiz->esq) + eABB(raiz->dir);
}

//Função recursiva para calcular a a altura da árvore.
int altura(struct tree *raiz) 
{
    int e, d;
    
    if(!raiz)
        return 0;
    
    e = 1 + altura(raiz->esq);
    d = 1 + altura(raiz->dir);
    
    return (e >= d ? e : d);
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

    printf("\nA altura da árvore é: %d\n", altura(t));

    printf("\nNós com dois filhos: %d\n", nFilhos(t));
    
    printf("\nMaior que zero: %d\n", maiorQueZero(t));

    if (eABB(t) > 0)
    {
        printf("\nNão é ABB\n");
    }
    else
        printf("\nÉ ABB\n");
    
}