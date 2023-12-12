#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//estrutura para criar as pilhas, nessa pilha eu tenho o nome do livro e uma outra estrutura que aponta para a proxima pilha
typedef struct Pilha{

    char livros[50];
    struct Pilha *prox;

}pilha;
pilha *topo = NULL;

//funçao para imprimir todas pilhas criadas
void imprimir(){
    pilha *temporaria; //pilha para armazenar a pilha do topo
    temporaria = topo;
    printf("\n###PILHA###\n");
    while(temporaria != NULL){

        printf("%s",temporaria->livros);
        temporaria = temporaria->prox;
    };
    printf("\n############\n");
};
void push(char l[50]){

    pilha *novolivro = malloc(sizeof(pilha));
    strncpy(novolivro->livros, l, sizeof(novolivro->livros));
    novolivro->prox = topo;
    topo = novolivro;
};
void pop(){

    if(topo != NULL){
        pilha *temporaria;
        temporaria = topo;
        topo = topo->prox;
        free(temporaria);
    }
};

int main()
{
    printf("\n######PILHA DE LIVROS######");
    int resp;
    char livro[50];
    do{
        printf("\nO que deseja fazer na pilha?\n1-Empilhar\n2-Imprimir\n3-Desempilhar\n4-Esvaziar\n5-Sair\n");
        scanf("%d",&resp);
        getchar();
        switch(resp){

        case 1:

            printf("\nDigite o nome do livro: ");
            fgets(livro, sizeof(livro), stdin);
            push(livro);

            break;

        case 2:
            imprimir();
            break;

        case 3:
            if(topo == NULL){
                printf("\nEmpilhe algum livro primeiro\n");
            }
            pop();
            break;

        case 4:
            if(topo == NULL){
                printf("\nEmpilhe algum livro primeiro\n");
            }
            while(topo != NULL){
                pop();
            }
            imprimir();
            break;

        case 5:
            return 0;

        default:
            printf("\nOpcao invalida\n");
        }

    }while(resp != 5);
    return 0;
}
