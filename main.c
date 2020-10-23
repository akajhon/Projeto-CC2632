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




//Fun��o para o menu aparecer!!!
void menu(void){
puts("=================================\n");
puts("Menu de op��es\n");
puts("");
puts("=================================\n");
puts("0 - Sair\n");
puts("1 - Inserir\n");
puts("2 - Relat�rio\n");
puts("3 - Saldo\n");
puts("4 - Excluir\n");
puts("5 - Extrato\n");
puts("=================================\n");
}
//Fun��o para sair do programa
int sair(){
  puts("Saindo...");
  puts("Obrigado por utilizar nosso sistema!");
  return 0;
}

//Fun��o de inser��o
int inserir(){
  int op;
  struct Receita Receita;
  struct Data DataReceita;
  struct Receita Gasto;
  struct Data DataGasto;
  puts("Insira");
  puts("1 - Gasto");
  puts("2 - Receita");
  printf("Opc�o: ");
  scanf(" %d", &op);
  puts(" ");

  //la�o pro menu do inserir
  while(op > 2 || op < 1){
    puts("N�mero inv�lido! Tente Novamente...");
    scanf("%d", &op);
  }
  //Condi��o dos gastos
  if ( op == 1){
    puts("Digite o valor do gasto:");
    scanf("%f", &Gasto.valor);
    puts("Digite a data(dd/mm/aa):");
    scanf("%d/%d/%d", &DataGasto.dia, &DataGasto.mes, &DataGasto.ano);

    while ((DataGasto.dia <= 0 || DataGasto.dia >= 32) || (DataGasto.mes <= 0 || DataGasto.mes >= 13) || (DataGasto.ano <= 0)) {
            puts("Data inv�lida! Tente novamente...");
            scanf("%d/%d/%d", &DataGasto.dia, &DataGasto.mes, &DataGasto.ano);
        }

    puts("Digite a categoria: (Moradia, Alimenta��o, Lazer, Transporte, Estudos, Compras, Trabalho)");
    scanf("%s", Gasto.categoria);

      while ((strcmp(Gasto.categoria, "Moradia") != 0) && (strcmp(Gasto.categoria, "Alimenta��o") != 0) && (strcmp(Gasto.categoria, "Lazer") != 0) && (strcmp(Gasto.categoria, "Transporte") != 0) && (strcmp(Gasto.categoria, "Estudos") != 0) && (strcmp(Gasto.categoria, "Compras") != 0) && (strcmp(Gasto.categoria, "Trabalho") != 0)){
            puts("Categoria inv�lida! Tente novamente...");
            scanf("%s", Gasto.categoria);
      }
    puts(" ");
    puts("Gasto registrado com sucesso!");
    puts("===============================");
  }

  //Condi��o pra receita
  else if (op == 2) {
    puts("Digite o valor da Receita:");
    scanf("%f", &Receita.valor);
    puts("Digite a data(dd/mm/aa):");
    scanf("%d/%d/%d", &DataReceita.dia, &DataReceita.mes, &DataReceita.ano);
      while ((DataReceita.dia <= 0 || DataReceita.dia >= 32) || (DataReceita.mes <= 0 || DataReceita.mes >= 13) || (DataReceita.ano <= 0)) {
            puts("Data inv�lida! Tente novamente...");
            scanf("%d/%d/%d", &DataReceita.dia, &DataReceita.mes, &DataReceita.ano);
        }
    puts("Digite a categoria: (Moradia, Alimenta��o, Lazer, Transporte, Estudos, Compras, Trabalho)");
    scanf("%s", Receita.categoria);

      while ((strcmp(Receita.categoria, "moradia") != 0) && (strcmp(Receita.categoria, "alimenta��o") != 0) && (strcmp(Receita.categoria, "lazer") != 0) && (strcmp(Receita.categoria, "transporte") != 0) && (strcmp(Receita.categoria, "estudos") != 0) && (strcmp(Receita.categoria, "compras") != 0) && (strcmp(Receita.categoria, "trabalho") != 0)){
            puts("Categoria inv�lida! Tente novamente...");
            scanf("%s", Receita.categoria);
    }

    puts(" ");
    puts("Receita registrada com sucesso!");
    puts("=================================");
  }

  return 0;
}

//Fun��o para o relatorio
int relatorio(){
  puts("Relat�rio Pronto");
  return 0;
}

//Fun��o para exibir o saldo
int saldo(){
  double Saldo;
  struct Receita Gasto;
  struct Receita Receita;
  Saldo = Receita.valor - Gasto.valor;
  printf("Seu Saldo Atual �: R$ %.2lf \n", Saldo);
  return 0;
}

//Fun��o para excluir um registro
int excluir(){
  int op;
  puts("Voce deseja remover um registro ou todos os dados?");
  puts("1 - Apenas 1 Registro");
  puts("2 - Todos os Dados");
  printf("Opcao: ");
  scanf(" %d", &op);

  puts("Excluindo...");
  puts("Registros exclu�dos com sucesso!");
  puts("Dados exclu�dos com sucesso!");
  puts("Erro ao excluir o registro!");
  menu();
  return 0;
}

//Fun��o para fazer seu extrato
int extrato(){
  puts("Extrato da conta");
  return 0;
}

//Fun��o Main!!!!
int main(void) {
  int selecionar = 0;

  while(selecionar<5 || selecionar>0 ){
    menu();
    puts("Digite sua op��o!!!");
    scanf("%d", &selecionar);

    if(selecionar == 0){
      sair();
      break;
    }

    if(selecionar == 1){
      inserir();

    }

    if(selecionar == 2){
      relatorio();
    }

    if(selecionar == 3){
      saldo();
    }

    if(selecionar == 4){
      excluir();
    }

    if(selecionar == 5){
      extrato();
    }

    if (selecionar>5 || selecionar<0 ){
      puts("N�mero Invalido, tente outro!!!");
    }
  }
  return 0;
}

/*
  Escolha sua categoria:
  1 - Moradia
  2 - Alimenta��o
  3 - Lazer
  4 - Transporte
  5 - Estudos
  6 - Compras
  7 - Trabalho
*/

/* Implementar Senha? */
