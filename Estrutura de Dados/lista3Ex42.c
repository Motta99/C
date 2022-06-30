/*42) Escreva uma função que recebe como parâmetro o ponteiro para a raiz de uma árvore
binária de busca que armazena apenas valores inteiros e retorna um ponteiro para o menor valor
armazenado na árvore. Caso a árvore seja vazia, a função deve retornar NULL.
O protótipo da função é: struct tree *menor_valor(struct tree *raiz);
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

int menorValor(struct tree *raiz)
{
    if (!raiz)
        return NULL;
        
    if ((raiz->esq) && (raiz->chave > raiz->esq->chave))
    {
        return menorValor(raiz->esq);
    }
    else
        return raiz->chave;
}


int main()
{
    int n, x, p;

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

    p = menorValor(t);

    printf("\nO menor valor da árvore é %d\n", p);
}
