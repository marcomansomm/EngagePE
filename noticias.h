#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
FILE *arquivo;
struct node {
    int id;
    char* titulo;
    char* resumo;
    char* texto;
    struct node *next;
};
void print_noticias(struct node *head);
void push(struct node **head, int id, char titulo[29], char resumo[80], char texto[750]);
const char* getfield(char* line, int num);
void noticias()
{
    system("cls");
    struct node *head = NULL;
    char titulo_f[50], resumo_f[80], texto_f[750], aux[99], var, line[1024];
    int id_f = 0;
    arquivo = fopen("noticias_adm2.txt", "r");

    /*while (!feof(arquivo)) {
        fscanf(arquivo, "%d", &id_f);
        fgets(titulo_f, 50, arquivo);
        fgets(resumo_f, 80, arquivo);
        fgets(texto_f, 750, arquivo);
        push(&head, titulo_f, resumo_f, texto_f, id_f);
    }*/
    while (fgets(line, 1024, arquivo)) {
        
        char* aux_n = strdup(line);
        strcpy(titulo_f, getfield(aux_n, 2));
        free(aux_n);
        aux_n = strdup(line);

        strcpy(resumo_f, getfield(aux_n, 3));
        free(aux_n);
        aux_n = strdup(line);

        strcpy(texto_f, getfield(aux_n, 4));

        push(&head, 5, titulo_f, resumo_f, texto_f);
        
    }
    
    fclose(arquivo);
    char titulo_m[29] = "Mulheres conquistam direito.", resumo_m[80] = "Mulheres tem cirurgia de reconstrucao da mama garantida por lei.", texto_m[520] = "As mulheres submetidas a retirada da mama tem a cirurgia de reconstrucao por\nmeio do Sistema Unico de Saude (SUS) garantida por lei. A reconstrucao mamaria\naumenta tanto a qualidade de vida quanto a expectativa de vida das mulheres. \n\nA Lei n 12.802, de 2013, declara que a paciente tem direito a realizar o\nprocedimento atraves do SUS imediatamente apos a retirada da mama com\ncancer, na mesma cirurgia, se houver condicoes clinicas, ou assim que a paciente\napresentar os requisitos necessarios.";
    int id_m = 1;
    char titulo_2[29] = "Petrolina com inovacao!", resumo_2[80] = "Petrolina recebe, pela primeira vez, edicao da Campus Party Weekend.", texto_2[670] = "A cidade de Petrolina recebe, a partir desta quinta-feira (28), a nova edicao do\nCampus Party Weekend, evento de divulgacao de conhecimento em inovacao,\ntecnologia e criatividade. Com formato inteligente e sustentavel, as atividades\nserao mistas, com as presenciais sendo realizadas no Campus da Universidade\nFederal do Vale do Sao Francisco (Univasf). \n\nO retorno da Campus Party e uma iniciativa conjunta da Secretaria de Ciencia,\nTecnologia e Inovacao (Secti), Serviço Brasileiro de Apoio as Micro e Pequenas\nEmpresas de Pernambuco (Sebrae-PE), Instituto Campus Party e Univasf. As\ninscricoes estao disponiveis no site da Campus Party Weekend.";
    int id_2 = 2;
    char titulo_3[29] = "Reggae Pernambucano!", resumo_3[80] = "Nzambi aposta em musica e ancestralidade em show no #Amplifica", texto_3[750] = "A banda de reggae pernambucana NZambi apresenta o show do album Palavras\nde Amor no #Amplifica deste domingo (31), a partir das 18h. O terceiro trabalho da\nbanda, que conta com a producao de Buguinha Dub, investe na efervecencia e\nmistura de sons e ritmos pernambucanos. \n\nCom composicoes que trazem mensagens de justica social, celebracao da vida e\ncombate ao racismo, a banda ja soma tres albuns gravados em estudio: Kaya, Mas\nse Oriente (2008), Pra Verdade Estremecer (2014) e Palavras de Amor (2021). \n\nA banda tem se destacado na cena nacional com um reggae com identidade, ao\nbeber dos diversos generos musicais de matriz africana, com referencias no Ska,\nDub, Rap, Ragga, Blues, Frevo, Cumbia e o Jazz.";
    int id_3 = 3;
    //push(&head, titulo_m, resumo_m, texto_m, id_m);
    //push(&head, titulo_2, resumo_2, texto_2, id_2);
    //push(&head, titulo_3, resumo_3, texto_3, id_3);
    print_noticias(head);
}
void push(struct node **head, int id, char titulo[29], char resumo[80], char texto[750])
{
    struct node *novo = (struct node *)malloc(sizeof(struct node));
    novo->titulo = titulo;
    novo->resumo = resumo;
    novo->texto = texto;
    novo->id = id;
    novo->next = *head;
	*head = novo;
}
void print_noticias(struct node *head)
{
    
    int escolha = 0, check = 0;
    char voltar[100];
    if (head == NULL) {
        printf("\nNao temos noticias no momento, aguarde atualizacoes do administrador...\n");
    }
    else {
        while (1) {
            struct node *aux = head;
            printf("\n---------- Noticias ----------\n");
            while (aux != NULL) {
                printf("\n%s         ID: %d\n\n", aux->titulo, aux->id);
                printf("    %s\n\n", aux->resumo);
                aux = aux->next;
            }
            printf("------------------------------\n");
            printf("Para entrar em uma noticia insira o seu ID.\n");
            printf("Caso deseje sair da aba de noticias insira 0.\n");
            
            check = 0;
            printf(">>> ");
            scanf("%d", &escolha);
            if (escolha == 0) {
                break;
            }
            struct node *aux_2 = head;
            system("cls");
            while (aux_2 != NULL) {
                if (aux_2->id == escolha) {
                    printf("\n%s\n\n", aux_2->resumo);                        
                    printf("\t%s\n\n", aux_2->texto);
                    printf("Insira qualquer coisa para voltar: ");
                    scanf("%s", &voltar);
                    check = 1;
                    break;
                }
                aux_2 = aux_2->next;
            }
            system("cls");
            if (check == 0) {
                printf("Nao foi encontrado noticias com este ID, tente novamente.\n");
            }
        }
    }
}


const char* getfield(char* line, int num)
{
	const char* tok;
	for (tok = strtok(line, "|");
			tok && *tok;
			tok = strtok(NULL, "|\n"))
	{
		if (!--num)
			return tok;
	}
	return NULL;
}