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
int inserir(){
  puts("Insira");
  puts("1 - Gasto");
  puts("2 - Receita");
  return 0;
}

//Função para o relatorio
int relatorio(){
  puts("Relatório Pronto");
  return 0;
}

//Função para exibir o saldo
int saldo(){
  puts("Bote seu saldo");
  puts("Seu Saldo Atual é:");
  return 0;
}

//Função para excluir um registro
int excluir(){
  puts("Excluindo...");
  puts("Registros excluídos com sucesso!");
  puts("Erro ao excluir o registro!");
  menu();
  return 0;
}

//Função para fazer seu extrato
int extrato(){
  puts("Extrato da conta");
  return 0;
}

//Função Main!!!!
int main(void) {
  int selecionar = 0;
  menu();
  while(selecionar<5 || selecionar>0 ){
    puts("Digite sua opção!!!");
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
      puts("Número Invalido, tente outro!!!");
    }


  }
  return 0;
}

/*
  Escolha sua categoria:
  1 - Moradia
  2 - Alimentação
  3 - Lazer
  4 - Transporte
  5 - Estudos
  6 - Compras
  7 - Trabalho
*/

/* Implementar Senha? */
