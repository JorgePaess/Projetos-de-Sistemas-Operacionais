# Programa de Cópia de Arquivos em C

Este é um programa simples em C que copia o conteúdo de um arquivo de origem para um arquivo de destino usando a API POSIX. O objetivo do programa é demonstrar o uso de chamadas de sistema para operações de leitura e escrita em arquivos no Linux.

## Objetivo

O objetivo deste programa é:
- Ler o conteúdo de um arquivo de origem.
- Escrever o conteúdo lido em um arquivo de destino.
- Garantir que o arquivo de origem exista e que as operações de leitura e escrita sejam realizadas corretamente, com tratamento de erros.

## Como Funciona

O programa funciona da seguinte maneira:
1. Solicita ao usuário os nomes do arquivo de origem e do arquivo de destino.
2. Abre o arquivo de origem em modo de leitura.
3. Abre ou cria o arquivo de destino em modo de escrita.
4. Lê o conteúdo do arquivo de origem em blocos e escreve esses blocos no arquivo de destino.
5. Exibe uma mensagem de sucesso após a cópia bem-sucedida.

### Verificação de Erros

O programa realiza verificações de erros para:
- Certificar-se de que o arquivo de origem existe e pode ser aberto.
- Garantir que o arquivo de destino pode ser criado ou aberto para escrita.
- Confirmar que a leitura e a escrita dos arquivos foram realizadas sem problemas.

## Como Compilar e Executar

Para compilar e executar o programa em um sistema Linux, siga os passos abaixo:

1. **Clone este repositório** (se ainda não o fez):
    ```bash
    git clone https://github.com/JorgePaess/Projetos-de-Sistemas-Operacionais.git
    cd Projetos-de-Sistemas-Operacionais/copy_file    
    ```

2. **Compile o programa usando o `gcc`:**
    ```bash
    gcc -Wall -o copy_file copy_file.c
    ```

3. **Execute o programa:**
    ```bash
    ./copy_file
    ```

4. **Siga as instruções na tela para fornecer os nomes dos arquivos de origem e destino.**

## Uso com `strace`

Você pode usar o `strace` para rastrear as chamadas de sistema feitas pelo programa. Isso pode ser útil para depuração e análise de desempenho.

### Como usar o `strace`:

1. **Instale o `strace` (se ainda não estiver instalado):**
    ```bash
    sudo apt install strace
    ```

2. **Execute o programa com `strace`:**
    ```bash
    strace ./copy_file
    ```

3. **Opções úteis do `strace`:**
   - **Filtrar chamadas de sistema relacionadas a arquivos:**
     ```bash
     strace -e trace=file ./copy_file
     ```
   - **Salvar a saída em um arquivo:**
     ```bash
     strace -o strace_output.txt ./copy_file
     ```
   - **Resumir o tempo gasto em cada chamada de sistema:**
     ```bash
     strace -c ./copy_file
     ```

### Exemplo de Saída

Aqui está um exemplo de saída simplificada ao executar o programa com `strace`:

```bash
open("origem.txt", O_RDONLY)            = 3
read(3, "conteudo do arquivo", 1024)    = 18
open("destino.txt", O_WRONLY|O_CREAT|O_TRUNC, 0644) = 4
write(4, "conteudo do arquivo", 18)     = 18
close(3)                                = 0
close(4)                                = 0

