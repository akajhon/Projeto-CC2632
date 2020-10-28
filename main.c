#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//ZONA DE STRUCTS!!!!!!!!

struct Data{
  int dia;
  int mes;
  int ano;
};

struct Receita{
  struct Data data;
  float valor;
  char categoria[200];
};

//FIM DA ZONA!!!!!!!!!!!




//Função para o menu aparecer!!!
void menu(void){
puts("");
puts("=================================\n");
puts("Menu de opções\n");
puts("");
puts("=================================\n");
puts("0 - Sair\n");
puts("1 - Inserir\n");
puts("2 - Relatório\n");
puts("3 - Saldo\n");
puts("4 - Excluir\n");
puts("5 - Extrato\n");
puts("=================================\n");
}
//Função para sair do programa
int sair(){
  puts("Saindo...");
  puts("Obrigado por utilizar nosso sistema!");
  return 0;
}

//Função de inserção
<<<<<<< HEAD
int inserir(struct Receita * p){
=======
int inserir(){
>>>>>>> 0c0d2d7b67a4fb351d1f582547ae3de5e4ef254c
  int op;
  struct Receita Receita;
  struct Data DataReceita;
  struct Receita Gasto;
  struct Data DataGasto;
  puts("Insira");
  puts("1 - Gasto");
  puts("2 - Receita");
  printf("Opcão: ");
  scanf(" %d", &op);
  puts(" ");

  //laço pro menu do inserir
  while(op > 2 || op < 1){
    puts("Número inválido! Tente Novamente...");
    scanf("%d", &op);
  }
  //Condição dos gastos
  if ( op == 1){
    puts("Digite o valor do gasto:");
    scanf("%f", &Gasto.valor);
    puts("Digite a data(dd/mm/aa):");
    scanf("%d/%d/%d", &DataGasto.dia, &DataGasto.mes, &DataGasto.ano);

    while ((DataGasto.dia <= 0 || DataGasto.dia >= 32) || (DataGasto.mes <= 0 || DataGasto.mes >= 13) || (DataGasto.ano <= 0)) {
            puts("Data inválida! Tente novamente...");
            scanf("%d/%d/%d", &DataGasto.dia, &DataGasto.mes, &DataGasto.ano);
        }

<<<<<<< HEAD
    puts("Digite a categoria: (moradia, alimentacao, lazer, transporte, estudos, compras, trabalho)");
    scanf("%s", Gasto.categoria);

      while ((strcmp(Gasto.categoria, "moradia") != 0) && (strcmp(Gasto.categoria, "alimentacao") != 0) && (strcmp(Gasto.categoria, "lazer") != 0) && (strcmp(Gasto.categoria, "transporte") != 0) && (strcmp(Gasto.categoria, "estudos") != 0) && (strcmp(Gasto.categoria, "compras") != 0) && (strcmp(Gasto.categoria, "trabalho") != 0)){
=======
    puts("Digite a categoria: (Moradia, Alimentação, Lazer, Transporte, Estudos, Compras, Trabalho)");
    scanf("%s", Gasto.categoria);

      while ((strcmp(Gasto.categoria, "Moradia") != 0) && (strcmp(Gasto.categoria, "Alimentação") != 0) && (strcmp(Gasto.categoria, "Lazer") != 0) && (strcmp(Gasto.categoria, "Transporte") != 0) && (strcmp(Gasto.categoria, "Estudos") != 0) && (strcmp(Gasto.categoria, "Compras") != 0) && (strcmp(Gasto.categoria, "Trabalho") != 0)){
>>>>>>> 0c0d2d7b67a4fb351d1f582547ae3de5e4ef254c
            puts("Categoria inválida! Tente novamente...");
            scanf("%s", Gasto.categoria);
      }
    puts(" ");
<<<<<<< HEAD
    //Ponteiros:
    p->valor = p->valor+(-1*Gasto.valor);
    p->data.dia = DataGasto.dia;
    p->data.mes = DataGasto.mes;
    p->data.ano = DataGasto.ano;
    //Fim dos ponteiros
    FILE * f;
    f=fopen("extrato.txt", "a");
    fprintf(f, "%s\n",Gasto.categoria);
    fprintf(f,"%d/%d/%d\n", p->data.dia, p->data.mes, p->data.ano);
    fprintf(f,"%.2f\n",-1*Gasto.valor);
    fclose(f);
    //p->categoria[200] = Gasto.categoria;

=======
>>>>>>> 0c0d2d7b67a4fb351d1f582547ae3de5e4ef254c
    puts("Gasto registrado com sucesso!");
    puts("===============================");
  }

  //Condição pra receita
  else if (op == 2) {
    puts("Digite o valor da Receita:");
    scanf("%f", &Receita.valor);
    puts("Digite a data(dd/mm/aa):");
    scanf("%d/%d/%d", &DataReceita.dia, &DataReceita.mes, &DataReceita.ano);
      while ((DataReceita.dia <= 0 || DataReceita.dia >= 32) || (DataReceita.mes <= 0 || DataReceita.mes >= 13) || (DataReceita.ano <= 0)) {
            puts("Data inválida! Tente novamente...");
            scanf("%d/%d/%d", &DataReceita.dia, &DataReceita.mes, &DataReceita.ano);
        }
<<<<<<< HEAD
    puts("Digite a categoria: (moradia, alimentação, lazer, transporte, estudos, compras, trabalho)");
=======
    puts("Digite a categoria: (Moradia, Alimentação, Lazer, Transporte, Estudos, Compras, Trabalho)");
>>>>>>> 0c0d2d7b67a4fb351d1f582547ae3de5e4ef254c
    scanf("%s", Receita.categoria);

      while ((strcmp(Receita.categoria, "moradia") != 0) && (strcmp(Receita.categoria, "alimentação") != 0) && (strcmp(Receita.categoria, "lazer") != 0) && (strcmp(Receita.categoria, "transporte") != 0) && (strcmp(Receita.categoria, "estudos") != 0) && (strcmp(Receita.categoria, "compras") != 0) && (strcmp(Receita.categoria, "trabalho") != 0)){
            puts("Categoria inválida! Tente novamente...");
            scanf("%s", Receita.categoria);
    }
<<<<<<< HEAD
    puts(" ");
    //Ponteiros:
    p->valor = p->valor+(Receita.valor);
    p->data.dia = DataReceita.dia;
    p->data.mes = DataReceita.mes;
    p->data.ano = DataReceita.ano;
    //Fim dos ponteiros
    FILE * f;
    f=fopen("extrato.txt", "a");
    fprintf(f, "%s\n",Receita.categoria);
    fprintf(f,"%d/%d/%d\n", p->data.dia, p->data.mes, p->data.ano);
    fprintf(f,"%.2f\n",Receita.valor);
    fclose(f);

    puts("Receita registrada com sucesso!");
    puts("=================================");
  }
=======

    puts(" ");
    puts("Receita registrada com sucesso!");
    puts("=================================");
  }

>>>>>>> 0c0d2d7b67a4fb351d1f582547ae3de5e4ef254c
  return 0;
}

//Função para o relatorio
int relatorio(){
<<<<<<< HEAD
  puts("Relatório Pronto!");
=======
  puts("Relatório Pronto");
  return 0;
}

//Função para exibir o saldo
int saldo(){
  double Saldo;
  struct Receita Gasto;
  struct Receita Receita;
  Saldo = Receita.valor - Gasto.valor;
  printf("Seu Saldo Atual é: R$ %.2lf \n", Saldo);
>>>>>>> 0c0d2d7b67a4fb351d1f582547ae3de5e4ef254c
  return 0;
}

//Função para excluir um registro
int excluir(){
  int op;
  puts("Voce deseja remover um registro ou todos os dados?");
  puts("1 - Apenas 1 Registro");
  puts("2 - Todos os Dados");
  printf("Opcao: ");
  scanf(" %d", &op);

  puts("Excluindo...");
  puts("Registros excluídos com sucesso!");
  puts("Dados excluídos com sucesso!");
  puts("Erro ao excluir o registro!");
  menu();
  return 0;
}

//Função para fazer seu extrato
void extrato(){
  char categoria[200];
  char data[15];
  float saldo;
  int i=0;
  puts("");
  puts("Extrato das movimentações:");
  FILE * f;
  f = fopen("extrato.txt", "r");
  while (fscanf(f, "%s %s %f", categoria, data, &saldo) != EOF){
    puts("=================================");
    printf("Data: %s\nCategoria: %s\nValor: R$%.2f\n",data,categoria,saldo );
    puts("=================================");
  i++;
  }
}

//Função Main!!!!
int main(void) {
  int selecionar = 0;

  while(selecionar<5 || selecionar>0 ){
<<<<<<< HEAD
    struct Receita Receita;
=======
>>>>>>> 0c0d2d7b67a4fb351d1f582547ae3de5e4ef254c
    menu();
    puts("Digite sua opção!!!");
    scanf("%d", &selecionar);

    if(selecionar == 0){
      sair();
      break;
    }

<<<<<<< HEAD
    else if(selecionar == 1){
      inserir(&Receita);
=======
    if(selecionar == 1){
      inserir();

>>>>>>> 0c0d2d7b67a4fb351d1f582547ae3de5e4ef254c
    }

    else if(selecionar == 2){
      relatorio();
    }

    else if(selecionar == 3){

      float s;
      s=Receita.valor;
      puts("=================================");
      printf("Saldo Atual: R$ %.2f",s);
    }

    else if(selecionar == 4){
      excluir();
    }

    else if(selecionar == 5){
      extrato();
    }

    else if (selecionar>5 || selecionar<0 ){
      puts("Número Invalido, tente outro!!!");
    }
  }
  return 0;
}

/*
  Escolha sua categoria:
  1 - moradia
  2 - alimentacao
  3 - lazer
  4 - transporte
  5 - estudos
  6 - compras
  7 - trabalho
*/

/* Implementar Senha? */
