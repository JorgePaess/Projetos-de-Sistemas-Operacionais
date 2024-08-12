//Inclusão de bibliotecas
#include <stdio.h> // Funções de I/O
#include <stdlib.h> // Inclue a função 'exit'
#include <fcntl.h> // Uncluem a função 'open'
#include <unistd.h> // Incluem as chamadas de sistema como read, write e close

//Definição do tamanho do Buffer
#define BUFFER_SIZE 1024

int main()
{
//Declaração de variáveis
    char source_file[256]; // Arquivo que armazena o nome do arquivos de origem.
    char dest_file[256]; // Arquivo que armazena o nome do arquivo de destino.
    int source_fd, dest_fd; // Variáveis do tipo int para armazenar os descritores de arquivos.
    ssize_t nread; // Armazena o número de bytes lidos de cada vez do arquivo de origem.
    char buffer[BUFFER_SIZE]; // Um array que serve como espaço temporário para armazenar os dados lidos do arquivo de origem antes de serem escritos no arquivo de destino.
//Solicitação dos nomes dos arquivos
    printf("Digite o nome do arquivo de origem: ");
    scanf("%255s", source_file);
    printf("Digite o nome do arquivo de destino: ");
    scanf("%255s", dest_file);
//Abertura do arquivo de origem
    source_fd = open(source_file, O_RDONLY); // open abre o arquivo para leitura, O_RDONLY retorna -1 se o arquivo não puder ser aberto.
    if (source_fd == -1)
    {
        perror("Erro ao abrir o arquivo de origem"); // Exibe uma mensagem de error detalhada se o arquivo falhar.
        exit(EXIT_FAILURE); // Encerra o programa com um código de error.
    }
//Abertura do arquivo de destino
    dest_fd = open(dest_file, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR); 
    // O_WRONLY abre o arquivo pra escrita, O_CREAT cria o arquivo senão existir um, O_TRUNC limpa o arquivo se ja existir, S_IRUSR | S_IWUSR define permissões de leitura e escrita.
    if (dest_fd == -1)
    {
        // Se o programa falhar exibe uma mensagem de erro e encerra, fechando o arquivo de origem.
        perror("Erro ao abrir o arquivo de destino");
        close(source_fd);
        exit(EXIT_FAILURE);
    }
//Cópia do conteúdo
    while ((nread = read(source_fd, buffer, BUFFER_SIZE)) > 0) //read ler até BUFFER_SIZE bytes do arquivo de origem e armazena no buffer. O número de bytes lidos é armazenado em nread
    {
        if(write(dest_fd, buffer, nread) != nread) // Escreve os bytes lidos(buffer) no arquivo destino
        // O loop continua até que read retorne 0, indicando que o fim do programa foi alcançado.
        {
            perror("Erro ao escrever no arquivo de destino"); // Se ocorrer um erro durante a  leitura e escrita, o programa exibe uma mensagem de erro e encerra.
            close(source_fd);
            close(dest_fd);
            exit(EXIT_FAILURE);
        }
    }
    if (nread == -1)
    {
        perror("Error ao ler o arquivo de origem");
    }
//Fechamento dos arquivos
    close(source_fd);
    close(dest_fd);
//Mensagem de sucesso
    printf("Arquivo copiado com sucesso!\n");
    
    return 0;
}
