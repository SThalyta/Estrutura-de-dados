#include <stdio.h> //entrada e saida
#include <stdlib.h> // estruturas
#include <time.h> //utilizar o tempo como semente para geraçao das senhas aleatorias

// estrutura cliente
typedef struct Cliente{
    
    int num_cliente;
    struct Cliente *prox;

}cliente;

// fila do banco
typedef struct Fila{

    cliente *inicio;
    cliente *fim;

}fila;

void enqueue(fila *banco, int c) //adicionar cliente na fila
{
    cliente *novo_cliente = malloc(sizeof(cliente)); //memoria pra cliente
    if(novo_cliente == NULL){
        printf("\nFalha na alocacao de memoria"); //verifica a alocacao
    }
    novo_cliente->num_cliente = c;
    novo_cliente->prox = NULL; //configura os parametros

    if(banco->fim == NULL){

        banco->inicio = novo_cliente;
        banco->fim = novo_cliente;
    }
    else{
        banco->fim->prox = novo_cliente;
        banco->fim = novo_cliente;
    }
};
int dequeue(fila *banco) //remover(atender) cliente
{
    if(banco->inicio == NULL )
    {
        printf("\nAmigo, tu vai atender quem?"); //fila vazia
    }
    else
    {
        int num;
        cliente *cliente_atendido = malloc(sizeof(cliente));
        cliente_atendido = banco->inicio;
        num = cliente_atendido->num_cliente;
        banco->inicio = banco->inicio->prox; //meu novo inicio é o proximo do antigo inicio
        free(cliente_atendido);
        return num;
    }
};
int main(){

    fila filabanco;
    filabanco.inicio = NULL;
    filabanco.fim = NULL;
    int primeira = -1; //aqui tava dando problema, a primeira = ultima
    int ultima = -1; //decalrei depois como NULL, mas isso seria se fosse void. Funcionou com o NULL, mas estava com erros no console, resolvi deixar como -1
        
    printf("\n###BANCO ABERTO###");
    printf("\nSenhas geradas");
    srand(time(NULL));
    int senha;
    //esse trecho de codigo gera 10 clientes.
    for (int cliente = 1;cliente <= 10;cliente++)
    {
        senha = rand() % 10000;
        enqueue(&filabanco, senha);
        printf("\n%d", senha);
            if(primeira == -1){
                    
                primeira = senha;
            }
                ultima = senha;
    }
        senha = rand() % 10000;
        enqueue(&filabanco, senha); //adicionei uma nova pessoa na fila
        
        int c_atendido = dequeue(&filabanco); //desenfileirei a primeira pessoa
    
        printf("\nA primeira senha gerada foi: %d.A ultima senha gerada foi: %d",primeira, ultima);
        printf("\nLista de espera:");
        cliente *fila_espera = filabanco.inicio;
        //imprimo os clientes na fila
        while(fila_espera != NULL){
            printf("\n%d",fila_espera->num_cliente);
            fila_espera = fila_espera->prox;
        }
        printf("\n\nAtendendo...");
        //atendo todos os clientes
        while(filabanco.inicio != NULL){
                int c_atendido_fechar = dequeue(&filabanco);
                printf("\n%d foi atendido",c_atendido_fechar);
        }
        printf("\n\n###BANCO  FECHADO###");
        
    return 0;
}

