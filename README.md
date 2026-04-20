
## Trabalhos feitos para a disciplina de Sistemas Operacionais

### 1. Criar um sistema com banco de dados e threads

Neste trabalho construimos um [servidor](https://github.com/juuubsbs/SO/blob/main/trabM1/servidor.c) que recebe requisições em estilo SQL simples e executa em [banco.txt](https://github.com/juuubsbs/SO/blob/main/trabM1/banco.txt) e/ou no terminal (`SELECT`).
Para executar este trabalho é necessário um sistema Linux/Unix-like (pode ser executado no codespaces).

#### Compilar

```shell
    cd ./trabM1
    gcc ./servidor.c -o servidor.out
    gcc ./cliente.c -o cliente.out
```

#### Executar

- Primeiro Bash

```shell
    ./servidor.out
```

- Segundo Bash

```shell
    ./cliente.out
```
Para garantir a integridade dos dados na simulação do SGBD, optou-se pelo uso de `pthread_mutex_t`. Embora o sistema suporte múltiplas threads concorrentes, o mutex garante que a zona crítica (o arquivo de dados) seja acessada de forma atômica (exclusão mútua), evitando condições de corrida durante as operações de `INSERT`, `DELETE`, `UPDATE` e `SELECT`.