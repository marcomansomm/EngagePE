#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h> 
struct node_programacao {
    char* titulo;
    char* comeca;
    struct node_programacao *next;
};
FILE *arquivo_programacao;
void print_programacao(struct node_programacao *head_p);
void push_p(struct node_programacao **head_p, char titulo[29], char comeca[10]);
void programacao()
{
    struct node_programacao *head_p = NULL;
    char *programa, *horario, line[1024];
    arquivo_programacao = fopen("programacao_adm.txt", "r");
    while (fgets(line, 1024, arquivo_programacao)) {
        
        char* aux_n = strdup(line);
        
        programa = copyString(getfield(aux_n, 1));
        free(aux_n);

        aux_n = strdup(line);
        horario = copyString(getfield(aux_n, 2));
        free(aux_n);

        push_p(&head_p, programa, horario);
    }
    fclose(arquivo_programacao);

    print_programacao(head_p);
}
void print_programacao(struct node_programacao *head_p)
{
    struct tm *data_hora_atual;     
    time_t segundos;
    time(&segundos);   
    data_hora_atual = localtime(&segundos); 
    char escolha[99];   
    char comentario[200];
    char comentario_a[200];
    if (head_p == NULL) {
        printf("\n---------- PROGRAMACAO ----------\n\n");
        printf("%d/%d\n", data_hora_atual->tm_mday, data_hora_atual->tm_mon+1);
        printf("\nNao temos a tabela de programacao no momento, aguarde atualizacoes do adiministrador...\n\n");
        printf("---------------------------------\n");
    }
    else {
        
        printf("\n---------- PROGRAMACAO ----------\n\n");
        printf("%d/%d\n\n", data_hora_atual->tm_mday, data_hora_atual->tm_mon+1);
        struct node_programacao *aux = head_p;
        while (aux != NULL) {
            printf("%s    Comeca as %s\n", aux->titulo, aux->comeca);
            aux = aux -> next;
        }
        printf("---------------------------------\n");
        printf("Para sair insira qualquer coisa.\n");
        printf(">>> ");
        scanf("%s", &escolha);
    }
}
void push_p(struct node_programacao **head_p, char titulo[29], char comeca[10])
{
    struct node_programacao *novo = (struct node_programacao *)malloc(sizeof(struct node_programacao));
    novo->titulo = titulo;
    novo->comeca = comeca;
    novo->next = *head_p;
	*head_p = novo;
}