//Aqui é estruturado como é meu dado, que será
// recebido e interpretado pelo servidor

#ifndef BANCO_H
#define BANCO_H

//Configurações da pool de threads + fila de espera
#define NUM_THREADS 4           
#define MAX_FILA 10

//Configurações do sistema
#define PIPE_NAME "/tmp/bd_pipe"    // Caminho do Named Pipe (aquele que não vem de pai pra filho)
#define MAX_NOME 50                 // Tamanho máximo do campo nome
#define BUFFER_SIZE 256             // Tamanho do buffer de comunicação

//Estrutura de dados do banco Registro(id, nome[])
typedef struct {
    int id;
    char nome[MAX_NOME];
} Registro;

//Estrutura de dados Tarefa, recebe o comando bruto que provém do pipe
typedef struct {
    char comando_bruto[BUFFER_SIZE];
} Tarefa;

typedef enum {
    OP_INVALIDA = 0,
    OP_INSERT = 1,
    OP_DELETE = 2,
    OP_SELECT = 3,       // Pode ser um ou todos
    OP_UPDATE = 4
} TipoOperacao;

#endif
