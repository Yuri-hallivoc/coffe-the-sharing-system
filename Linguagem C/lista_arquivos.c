#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*Se este código for compilado para linux, deixe SISTEMA_WINDOWS
indefinido, caso contrário, defina e compile*/

//#define SISTEMA_WINDOWS

#ifdef SISTEMA_WINDOWS
#define CRIA_LISTA system("powershell ls ./arquivos > ./lista_arquivos.txt")
#endif
#ifndef SISTEMA_WINDOWS
#define CRIA_LISTA system("ls ./arquivos > ./lista_arquivos.txt")
#endif

/*Estrutura para armazenar todas as ocorrências de um termo em uma string.
Termo corresponde ao termo buscado e ocorrencia[n] corresponde a n-ésima
ocorrência do temo na string. Os valores desse array devem ser manipulados 
de forma que a guardar o número da posição onde a primeira letra do termo
foi encontrada. Após todas as ocorrências, deve ser utilizada a constante -1
para indicar a conclusão da pesquisa*/


typedef struct Pesquisa{
    char *string_pesquisada;
    char termo[500];
    int ocorrencia[100];
} Pesquisa;

/*procura por um termo em uma string e retorna uma variável Pesquisa
com as posições onde ele ocorre*/

Pesquisa encontra_termo(char string[], char termo[]);

char *le_arquivo(FILE *arquivo, char *buffer); //le arquivo e armazena em buffer
char **le_itens_lista_para_array(char *lista, char **item);

int main(){
    char *html, *lista, saida[10000], comando[10100];
    FILE *arq_lista, *arq_html;
    char **item;
    Pesquisa Lista_arquivo;
    int i = 0;
    CRIA_LISTA;
    arq_lista = fopen("./lista_arquivos.txt", "r");
    if(arq_lista == NULL){
        printf("Nao foi possivel abrir ./lista_arquivos.txt");
        exit(-1);
    }
    lista = le_arquivo(arq_lista, lista);
    fclose(arq_lista);
    item = le_itens_lista_para_array(lista, item);
    arq_html = fopen("./para_index.html", "r");
    if(arq_html == NULL){
        printf("Nao foi possivel abrir ./para_index.html");
        exit(-1);
    }
    html = le_arquivo(arq_html, html);
    fclose(arq_html);
    Lista_arquivo.string_pesquisada = (char *) malloc(strlen(html)*sizeof(char *));
    strcpy(Lista_arquivo.string_pesquisada, html);
    strcpy(Lista_arquivo.termo, "<a><li>Nenhum arquivo</li></a>");
    Lista_arquivo = encontra_termo(Lista_arquivo.string_pesquisada, Lista_arquivo.termo);
    Lista_arquivo.string_pesquisada[Lista_arquivo.ocorrencia[0]] = '\0';
    puts(Lista_arquivo.string_pesquisada);
    do{
        if(i == 0 && strlen(item[i]) == 0){
            puts("<a><li>Nenhum arquivo</li></a>");
            break;
        }
        puts("<a target='_blank' href='./arquivos/");
        puts(item[i]);
        puts("'><li>");
        puts(item[i]);
        puts("</li></a>");
        i++;
    }while(strcmp(item[i], "") != 0);
    puts("</ul></div></main></body></html>");
    free(item);
    return 0;
}

Pesquisa encontra_termo(char string[], char termo[]){
    int tamanho_string = strlen(string), tamanho_termo = strlen(termo);
    int i, j, n_ocorrencia = 0;
    Pesquisa Termo;
    Termo.string_pesquisada = string;
    strcpy(Termo.termo, termo);
    for(i = 0; i < tamanho_string; i++){
        j = 0;
        while(string[i] == termo[j]){
            i++;
            j++;
            if(i >= tamanho_string || j >= tamanho_termo) break;
        }
        if(j == tamanho_termo){
            Termo.ocorrencia[n_ocorrencia] = i - j;
            n_ocorrencia++;
        }
        if(j != 0) i--;
    }
    Termo.ocorrencia[n_ocorrencia] = -1;
    return Termo;
}

char *le_arquivo(FILE *arquivo, char *buffer){
    int i, tamanho_arquivo = -1;
    if(arquivo == NULL) return NULL;
    while(!feof(arquivo)){
        char a = fgetc(arquivo);
        tamanho_arquivo++;
    }
    rewind(arquivo);
    buffer = (char *) malloc(tamanho_arquivo*sizeof(char *));
    for(i = 0; i < tamanho_arquivo; i++) *(buffer + i) = fgetc(arquivo);
    *(buffer + i) = '\0';
    return buffer;
}

char **le_itens_lista_para_array(char *lista, char **item){
    char proximo_item[1000];
    int i, j, total_itens = 0, n_item = 0;
    for(i = 0; i < strlen(lista); i++){
        if(*(lista + i) == '\n' || *(lista + i) == '\r') total_itens++;
    }
    item = (char **) malloc(total_itens*sizeof(char **));
    for(i = 0; i < strlen(lista); i++){
        j = 0;
        while(*(lista + i) != '\n' && *(lista + i) != '\r' && i < strlen(lista)){
            proximo_item[j] = *(lista + i);
            i++;
            j++;
        }
        proximo_item[j] = '\0';
        if(strlen(proximo_item) > 0){
            *(item + n_item) = (char *) malloc((j + 1)*sizeof(char *)); 
            strcpy(*(item + n_item), proximo_item);
            n_item++;
        }
    }
    *(item + n_item) = "";
    return item;
}