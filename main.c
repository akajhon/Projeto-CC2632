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
  puts("Insira");
  puts("1 - Gasto");
  puts("2 - Receita");
  return 0;
}

//Fun��o para o relatorio
int relatorio(){
  puts("Relat�rio Pronto");
  return 0;
}

//Fun��o para exibir o saldo
int saldo(){
  puts("Bote seu saldo");
  puts("Seu Saldo Atual �:");
  return 0;
}

//Fun��o para excluir um registro
int excluir(){
  puts("Excluindo...");
  puts("Registros exclu�dos com sucesso!");
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
  menu();
  while(selecionar<5 || selecionar>0 ){
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
