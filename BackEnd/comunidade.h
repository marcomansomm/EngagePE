#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node_comunidade {
    int id;
    char *titulo;
    struct node_comunidade *next;
};
FILE *arquivo_comunidade;
void push_comunidade(struct node_comunidade **head_c, char titulo[100], int id);
void print_comunidade(struct node_comunidade *head_c);

void comunidade()
{
    struct node_comunidade *head_c = NULL;
    char id_f[10], line[1024];
    int id = 0;
    char *titulo;
    arquivo_comunidade = fopen("discussao_adm.txt", "r");
    
    while (fgets(line, 1024, arquivo_comunidade)) {
        
        char* aux_n = strdup(line);

        strcpy(id_f, getfield(aux_n, 1));
        free(aux_n);

        aux_n = strdup(line);
        titulo = copyString(getfield(aux_n, 2));
        free(aux_n);
        
        id = atoi(id_f);
        push_comunidade(&head_c, titulo, id);
    }
    fclose(arquivo_comunidade);
    char titulo_m[100] = "Aniversario do mestre salustiano";
    int id_m = 1;
    push_comunidade(&head_c, titulo_m, id_m);
    char titulo_2[100] = "Volta do festival coquetel molotov";
    int id_2 = 2;
    push_comunidade(&head_c, titulo_2, id_2);
    print_comunidade(head_c);
    fclose(arquivo_comunidade);
}
void print_comunidade(struct node_comunidade *head_c)
{
    int escolha = 0;
    char comentario[200], line[1024];
    //char comentario_a[200];
    if (head_c == NULL) {
        printf("Nao temos discussões no momento, aguarde atualizacoes do adiministrador...\n\n");
    }
    else {
        while (1) {
            printf("\n---------- Comunidade ----------\n\n");
            printf("Discussoes:\n\n");
            struct node_comunidade *aux = head_c;
            while (aux != NULL) {
                printf("%s\nID:%d\n\n", aux->titulo, aux->id);
                
                aux = aux -> next;
            }
            printf("--------------------------------\n");
            printf("Para entrar em uma discussao insira o seu ID.\n");
            printf("Caso deseje sair da aba de comunidade insira 0.\n");
            printf(">>> ");
            scanf("%d", &escolha);
            if (escolha == 0) { 
                break;
            }
            system("cls");
            struct node_comunidade *aux_2 = head_c;
            while (aux_2 != NULL) {
                if (aux_2->id == escolha) {
                    printf("%s\n\n", aux_2->titulo);
                    printf("Elvis Caio comentou:\n  Muito Interessante!\n\n");
                    printf("Raphael Vieira comentou:\n  Uhuul estou ansioso!\n\n");
                    printf("Rebecca Andrade comentou:\n  Adorei!!!\n\n");
                    printf("Vitor Rique comentou:\n  Eles tao vindo!\n\n");
                    printf("Rafaela Alpes comentou:\n  Isso e minha cara!, empolgadissima.\n\n");
                    printf("Gabriel Assis comentou:\n  Cade as datas??\n\n");
                    printf("Rinaldo Luis comentou:\n  Um abraco pra todos pernambucanos!\n\n");
                    printf("Para voltar a lista de discussoes insira qualquer coisa.\n");
                    printf(">>> ");
                    scanf("%s", &comentario);
                    
                }
                aux_2 = aux_2 -> next;
            }
            system("cls");  
        }
    }
}
void push_comunidade(struct node_comunidade **head_c, char titulo[29], int id)
{
    struct node_comunidade *novo = (struct node_comunidade *)malloc(sizeof(struct node_comunidade));
    novo->titulo = titulo;
    novo->id = id;
    novo->next = *head_c;
	*head_c = novo;
}
