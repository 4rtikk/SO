#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "banco.h"

void enviar(char *msg) {
    int fd = open(PIPE_NAME, O_WRONLY);
    if (fd == -1) {
        perror("Erro ao abrir pipe. O servidor está ligado?");
        exit(1);
    }
    printf("[CLIENTE] Enviou: %s\n", msg);
    //envia a mensagem até o pipe correto, possui o tamanho da mensagem nele, funciona como FIFO
    write(fd, msg, strlen(msg) + 1);
    close(fd);
}

int main() {
    printf("=== INICIANDO CLIENTE ===\n");

    // 1. Simulação de Inserção
    enviar("INSERT 101 Alice");

    // 2. Simulação de Seleção (Busca)
    enviar("INSERT 102 Bob_Engenharia");

    // 3. Simulação de Atualização
    enviar("INSERT 103 Charlie_Lite");

    // 4. Simulação de Deleção
    enviar("INSERT 104 David_Proa");

    // 5. Simulação de Seleção (Busca)
    enviar("SELECT 101");

    // 6. Simulação de Inserção
    enviar("SELECT 102 Bob_Engenharia");

    // 7. Simulação de Inserção
    enviar("SELECT 104");

    // 8. Simulação de Inserção
    enviar("SELECT 103");

    // 9. Simulação de Inserção
    enviar("SELECT 103");

    // 9. Simulação de Inserção
    enviar("SELECT Alice");

    // 9. Simulação de Inserção
    enviar("SELECT Bob_Engenharia");

    // 9. Simulação de Inserção
    enviar("SELECT Bob");

    // 9. Simulação de Inserção
    enviar("SELECT David_Proa");

    printf("=== TESTE FINALIZADO COM SUCESSO ===\n");
    return 0;
}