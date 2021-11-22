#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void login(){
  int check = 0;
  int i, verifica;
  char email_login[200], senha_login[100], email_cadastro[200], senha_cadastro[100];
  FILE *fp;
  fp = fopen("cadastros.txt", "r");

  printf("Digite seu email: ");
  scanf("%s", email_login);
  printf("\nDigite sua senha: ");
  scanf("%s", senha_login);
  verifica = 0;

  while (fscanf(fp, "%s %s", email_cadastro, senha_cadastro) != EOF) {
    if(!strcmp(email_login, email_cadastro)){
      check = 1;
      if(!strcmp(senha_login, senha_cadastro)){
        printf("\nVoce conseguiu fazer o Login com sucesso!\n");
        verifica = 1;
      }else{
        while (1) {
          printf("\nSenha Incorreta!\n\n");
          printf("Digite sua senha novamente: ");
          scanf("%s", senha_login);
          if(!strcmp(senha_login, senha_cadastro)){
            printf("\nVoce conseguiu fazer o Login com sucesso!\n");
            break;
          }
        }
      }
    }
  }
  
  if (check == 0) {
    printf("\nO e-mail nao foi encontrado, tente novamente.\n\n");
    login();
  }
  fclose(fp);
}

void cadastro() {
  char email[200], senha[100], senha_confirmada[100], email_confirmada[200], aux[99];
  int verifica = 0;
  FILE *fp;
  while (1) {
    printf("Digite seu email: ");
    scanf("%s", &email);
    printf("\nConfirme seu email: ");
    scanf("%s", &email_confirmada);
    if (!strcmp(email, email_confirmada)) {
      break;
    }
    else {
      printf("\nEmail's diferentes, insira novamente.\n\n");
    }
  }
  
  while (1) {
    printf("\nDigite sua senha: ");
    scanf("%s", &senha);
    printf("\nConfirme sua senha: ");
    scanf("%s", &senha_confirmada);
    if (!strcmp(senha, senha_confirmada)) {
      break;
    }
    else {
      printf("\nSenhas diferentes, insira novamente.\n");
    }
  }
  printf("\nCadastro Concluido!\n\n");
  fp = fopen("cadastros.txt", "a");
  fprintf(fp, "%s %s\n", email, senha);
  fclose(fp);
}