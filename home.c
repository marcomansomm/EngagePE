#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "noticias.h"
#include "programacao2.h"
#include "login.cadastro.h"
#include "comunidade.h"
#include <unistd.h>

int main(){
    int choice, validate = 1, check = 1;
    while (check == 1){
        
        system("cls");
        printf("------------- HOME -------------\n\n");
        printf("Bem-Vindo ao app da TVPE!\n");
        printf("Insira 1 para abrir as noticias.\n");
        printf("Insira 2 para abrir a programacao.\n");
        printf("Insira 3 para fazer seu cadastro.\n");
        printf("Insira 4 para fazer login.\n");
        printf("Insira 5 para abrir a aba da comunidade.\n");
        printf("Insira 6 para sair do programa.\n");
        check = 0;
            
        validate = 1;
        while(validate == 1){
            printf(">>> ");
            scanf("%d", &choice);
            if (choice <= 7 && choice >=1){
                switch (choice){
                    case 1:{
                        system("cls");
                        noticias();
                        printf("Insira 7 para confirmar que deseja voltar a HOME.\n");
                        break;
                    }
                    case 2:{
                        system("cls");
                        programacao();
                        printf("\nInsira 7 para voltar a HOME.\n");
                        break;
                    }
                    case 3:{
                        system("cls");
                        printf("------------- CADASTRO -------------\n\n");
                        cadastro();
                        printf("Insira 7 para voltar a HOME.\n");
                        break;
                    }
                    case 4:{
                        system("cls");
                        printf("------------- LOGIN -------------\n");
                        login();
                        printf("\nInsira 7 para voltar a HOME.\n");
                        break;
                    }
                    case 5:{
                        system("cls");
                        comunidade();
                        printf("Insira 7 para voltar a HOME.\n");
                        break;
                    }
                    case 6:{
                        printf("Obrigado por usar o app!\n");
                        check = 0;
                        validate = 0;
                        break;    
                    }
                    case 7:{
                        validate = 0;
                        check = 1;
                        break;
                    }
                }
            }
            else{
                printf("Insira um numero valido.\n");
            #ifdef _WIN32
                Sleep(2000);
            #else
                usleep(2000);
            #endif
            validate = 0;
            check = 1;
            }
        }
    }
    return 0;
}