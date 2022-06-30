/*31) Escreva um programa para manipular Árvore Binária de Busca (ABB) com n (lido via
teclado) números inteiros que contenha o seguinte menu de opções:
1- Inserir um nó na ABB
2- Imprimir a ABB
 I- Inoder
 P- Preorder
 O- Postorder
3- Buscar uma chave na ABB
4- Mostrar a altura da ABB
5- Mostrar a quantidade de nós da ABB
6- Mostrar a quantidade de folhas da ABB
7- Mostrar a quantidade de pais da ABB
8- Mostrar a maior e a menor chave da ABB
9- Remover um nó da ABB
10- Sair
Para as opções 1 a 8 crie uma função recursiva para resolver cada item.
Na opção 9, crie uma função não recursiva. Mostre a lista resultante após a remoção do nó.
Na opção 2, mostre o menu com as opções de caminhamentos para o usuário.
Na opção 10, mostre uma mensagem. O menu acaba quando o usuário escolher a opção 10.
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

//Função recursiva para contar os nós da árvore.
int contaNos(struct tree *raiz)
{
    if(!raiz)
        return 0;
    
    return (1 + contaNos(raiz->esq) + contaNos(raiz->dir));
}

//Função recursiva para contar os nós folhas da árvore.
int contaFolhas(struct tree *raiz) 
{ 
    if(!raiz)
        return 0;
    if(!raiz->esq && !raiz->dir) 
        return 1;
    
    return (contaFolhas(raiz->esq) + contaFolhas(raiz->dir)); 
}

//Função recursiva para contar os nós pais da árvore.
int contaPais(struct tree *raiz) 
{ 
    if(!raiz)
        return 0;
    if(!raiz->esq && !raiz->dir) 
        return 0;
    
    return (1 + contaPais(raiz->esq) + contaPais(raiz->dir));
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

void inorder(struct tree *raiz)
{
    if(raiz != NULL)
    {
        inorder(raiz -> esq);
        printf("%d \t", raiz -> chave);
        inorder(raiz -> dir);
    }
}

//Preorder
void preorder(struct tree *raiz)
 {
    if(raiz != NULL)
    {
        printf("%d \t", raiz -> chave);
        preorder(raiz -> esq);
        preorder(raiz -> dir);
    }
}

//Postorder
void postorder(struct tree *raiz)
{
    if(raiz != NULL)
    {
        postorder(raiz -> esq);
        postorder(raiz -> dir);
        printf("%d \t", raiz -> chave);
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

void removeABB(struct tree *raiz, int x) 
{
    struct tree *p, *q, *rp, *f, *s;
    
    q = NULL;
    p = raiz;
    
    while(p && x != p->chave)
    {
        q = p;
        p = (x < p->chave) ? p->esq : p->dir;
    }

    if(!p)
        return;

    if(!p->esq) 
        rp = p->dir;
    
    else
    {
        if(!p->dir)
            rp = p->esq;
        else
        {
            f = p;
            rp = p->dir;
            s = rp->esq;
        
            while(s) 
            {
                f = rp;
                rp = s;
                s = rp->esq;
            }

            if(f != p)
            {
                f->esq = rp->dir;
                rp->dir = p->dir;
            }

            rp->esq = p->esq;
        }
    }
        
    if(!q)
        raiz = rp;
    else
        (p == q->esq) ? (q->esq = rp) : (q->dir = rp);
    
    free(p);
}

int maiorValor(struct tree *raiz)
{        
    if ((raiz->dir) && (raiz->chave < raiz->dir->chave))
    {
        return maiorValor(raiz->dir);
    }
    else
        return raiz->chave;
}

int menorValor(struct tree *raiz)
{       
    if ((raiz->esq) && (raiz->chave > raiz->esq->chave))
    {
        return menorValor(raiz->esq);
    }
    else
        return raiz->chave;
}

int main()
{
    int valor, opcao, x = 1;

    struct tree *tree, *busca;

    tree = busca = NULL;

    while (x != 0)
    {
        printf("\n\nEscolha uma opção.\n\n1 - Inserir um nó na ABB\n2 - Imprimir a ABB\n3 - Buscar uma chave da ABB\n4 - Mostrar a altura da ABB\n5 - Mostrar a quantidade de nós da ABB\n6 - Mostrar a quantidade de folhas da ABB\n7 - Mostrar a quantidade de pais da ABB\n8 - Mostrar a maior e a menor chave da ABB\n9 - Remover um nó da ABB\n0 - sair\n\nOpção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1: printf("\nDigite um valor: ");
                    scanf("%d", &valor);

                    tree = insereABB(tree, valor);
                break;

            case 2: printf("\nInorder\n");
                    inorder(tree);

                    printf("\nPreorder\n");
                    preorder(tree);

                    printf("\nPostorder\n");
                    postorder(tree);
                break;

            case 3: printf("\nDigite a chave que deseja achar: ");
                    scanf("%d", &valor);

                    busca = buscaRec(tree, valor);
                    if (!busca)
                        printf("\nNão achou\n");
                    else
                        printf("\nAchou\n");
                    
                break;

            case 4: printf("\nA altura da árvore é: %d\n", altura(tree));
                break;

            case 5: printf("\nA ABB tem %d nós\n", contaNos(tree));
                break;

            case 6: printf("\nA ABB tem %d folhas\n", contaFolhas(tree));
                break;

            case 7: printf("\nA ABB tem %d pais\n", contaPais(tree));
                break;

            case 8: printf("\nO maior valor da ABB é %d e o menor valor é %d", maiorValor(tree), menorValor(tree));
                break;
                
            case 9: printf("\nDigite um valor: ");
                    scanf("%d", &valor);

                    removeABB(tree, valor);
                    
                    printf("\nABB:\n");
                    inorder(tree);
                break;

            case 0: printf("\nFim...\n");
                    x = 0;
                break;
            
            default: printf("\nDigite uma opção válida");
        }
    }
}
