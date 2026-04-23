
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

#### Testar comandos do banco

Com o servidor rodando, o cliente envia alguns comandos prontos para testar as quatro operações:

```shell
    ./cliente.out
```

Também é possível enviar comandos individuais diretamente pelo pipe:

```shell
    printf "INSERT 1 Ana\0" > /tmp/bd_pipe
    printf "SELECT 1\0" > /tmp/bd_pipe
    printf "UPDATE 1 Maria\0" > /tmp/bd_pipe
    printf "DELETE 1\0" > /tmp/bd_pipe
```

Formato dos comandos suportados:

```text
INSERT <id> <nome>
SELECT <id>
UPDATE <id> <novo_nome>
DELETE <id>
```

Exemplos:

```shell
    printf "INSERT 10 Aluno_Univali\0" > /tmp/bd_pipe
    printf "SELECT 10\0" > /tmp/bd_pipe
    printf "UPDATE 10 Novo_Nome_Editado\0" > /tmp/bd_pipe
    printf "DELETE 10\0" > /tmp/bd_pipe
```

O arquivo `banco.txt` guarda os registros no formato:

```text
id nome
```

Para conferir o conteúdo salvo no banco:

```shell
    cat banco.txt
```

Para limpar o banco antes de um novo teste:

```shell
    > banco.txt
```

Para garantir a integridade dos dados na simulação do SGBD, optou-se pelo uso de `pthread_mutex_t`. Embora o sistema suporte múltiplas threads concorrentes, o mutex garante que a zona crítica (o arquivo de dados) seja acessada de forma atômica (exclusão mútua), evitando condições de corrida durante as operações de `INSERT`, `DELETE`, `UPDATE` e `SELECT`.