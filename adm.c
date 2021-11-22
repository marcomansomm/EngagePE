#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
FILE *arquivo;
int adm()
{
    system("cls");
    int escolha = 0, continuar = 0, id = 0, noticias_add = 0;
    char titulo[50], resumo[80], texto[750], programa[20], horario[10], var, aux[90];
    while (1) {
        printf("Bem Vindo Administrador!\n\n");
        printf("Voce deseja:\n");
        printf("1 - Adicionar uma nova noticia no seu app?\n");
        printf("2 - Adicionar uma nova programacao no seu app?\n");
        printf("3 - Adicionar uma nova discussao na aba de comunidade do seu app?\n");
        printf("6 - Sair do programa?\n");
        printf(">>> ");
        scanf("%d", &escolha);
        system("cls");
        if (escolha == 1) {
            gets(aux);
            printf("\nInsira o titulo da noticia.\n");
            printf(">>> ");
            gets(titulo);
            printf("\nInsira o resumo da noticia.\n");
            printf(">>> ");
            gets(resumo);
            printf("\nInsira o texto da noticia.\n");
            printf(">>> ");
            gets(texto);
            printf("\nInsira o ID da noticia (Numero de identificacao), nao usar um ID repetido ou 0.\n");
            scanf("%d", &id);
            arquivo = fopen("noticias_adm2.txt", "a");
            fprintf(arquivo,"%d\n%s\n%s\n%s\n", id, titulo, resumo, texto);
            noticias_add++;
            fclose(arquivo);
            printf("\nNoticia adicionada!");
            #ifdef _WIN32
                Sleep(2000);
            #else
                usleep(2000);
            #endif
            system("cls");
        }
        else if (escolha == 2) {
            arquivo = fopen("programacao_adm.txt", "a");
            while (1) {
                gets(aux);
                printf("\nInsira o nome do Programa\n");
                printf(">>> ");
                gets(programa);
                printf("Insira o horario que ira passar %s, Formatacao = XX:XX\n", programa);
                printf(">>> ");
                gets(horario);
                fprintf(arquivo, "%s; %s\n", programa, horario);
                printf("Deseja inserir outro programa para a programacao? Sim = 1, Nao = 0.\n");
                printf(">>> ");
                scanf("%d", &continuar);
                if (continuar == 0) {
                    printf("\nPrograma(s) foram adicionado(s) na grade de progrmacao!");
                    #ifdef _WIN32
                        Sleep(2000);
                    #else
                        usleep(2000);
                     #endif
                    system("cls");
                    break;
                }
            }
            fclose(arquivo);
        }
        else if (escolha == 3) {
            gets(aux);
            arquivo = fopen("discussao_adm.txt", "a");
            printf("\nInsira o titulo da discussao\n");
            printf(">>> ");
            gets(titulo);
            printf("Insira o ID da discussao (Numero de identificacao), nao usar um ID repetido ou 0.\n");
            printf(">>> ");
            scanf("%d", &id);
            fprintf(arquivo, "%s; %d\n", titulo, id);
            fclose(arquivo);
            printf("\nDiscussao adicionada!");
            #ifdef _WIN32
                Sleep(2000);
            #else
                usleep(2000);
            #endif
            system("cls");
        }
        else if (escolha == 6) {
            printf("\nAte mais!\n");
            break;
        }
    }
}