#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <unistd.h>

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
puts("=================================\n");
puts("0 - Sair\n"); //ok
puts("1 - Inserir\n"); //ok
puts("2 - Relatório\n");
puts("3 - Saldo\n"); //ok
puts("4 - Excluir\n");
puts("5 - Extrato de todas as movimentações\n"); //ok
puts("6 - Buscar um registro específico");
puts("=================================\n");
}

//Função para sair do programa
int sair(){
  puts("Saindo...");
  puts("Obrigado por utilizar nosso sistema!");
  return 0;
}

//Função de inserção
int inserir(struct Receita * p){
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

    puts("Digite a categoria: (moradia, alimentacao, lazer, transporte, estudos, compras, trabalho)");
    scanf("%s", Gasto.categoria);

      while ((strcmp(Gasto.categoria, "moradia") != 0) && (strcmp(Gasto.categoria, "alimentacao") != 0) && (strcmp(Gasto.categoria, "lazer") != 0) && (strcmp(Gasto.categoria, "transporte") != 0) && (strcmp(Gasto.categoria, "estudos") != 0) && (strcmp(Gasto.categoria, "compras") != 0) && (strcmp(Gasto.categoria, "trabalho") != 0)){
            puts("Categoria inválida! Tente novamente...");
            scanf("%s", Gasto.categoria);
      }
    puts(" ");
    //Ponteiros:
    p->valor = p->valor+(-1*Gasto.valor);
    p->data.dia = DataGasto.dia;
    p->data.mes = DataGasto.mes;
    p->data.ano = DataGasto.ano;
    //Fim dos ponteiros
    FILE * f;
    f=fopen("extrato.txt", "a");
    fprintf(f,"%d/%d/%d\n", p->data.dia, p->data.mes, p->data.ano);
    fprintf(f, "%s\n",Gasto.categoria);
    fprintf(f,"%.2f\n",-1*Gasto.valor);
    fclose(f);
    //p->categoria[200] = Gasto.categoria;

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
    puts("Digite a categoria: (moradia, alimentação, lazer, transporte, estudos, compras, trabalho)");
    scanf("%s", Receita.categoria);

      while ((strcmp(Receita.categoria, "moradia") != 0) && (strcmp(Receita.categoria, "alimentação") != 0) && (strcmp(Receita.categoria, "lazer") != 0) && (strcmp(Receita.categoria, "transporte") != 0) && (strcmp(Receita.categoria, "estudos") != 0) && (strcmp(Receita.categoria, "compras") != 0) && (strcmp(Receita.categoria, "trabalho") != 0)){
            puts("Categoria inválida! Tente novamente...");
            scanf("%s", Receita.categoria);
    }
    puts(" ");
    //Ponteiros:
    p->valor = p->valor+(Receita.valor);
    p->data.dia = DataReceita.dia;
    p->data.mes = DataReceita.mes;
    p->data.ano = DataReceita.ano;
    //Fim dos ponteiros
    FILE * f;
    f=fopen("extrato.txt", "a");
    fprintf(f,"%d/%d/%d\n", p->data.dia, p->data.mes, p->data.ano);
    fprintf(f, "%s\n",Receita.categoria);
    fprintf(f,"%.2f\n",Receita.valor);
    fclose(f);

    puts("Receita registrada com sucesso!");
    puts("=================================");
  }
  sleep(1);
  return 0;
}

//Função para o relatorio
int relatorio(){
  puts("Relatório Pronto!");
  sleep(1);
  return 0;
}

//Função para excluir um registro
int excluir(){
  puts("");
  int op;
  puts("Voce deseja remover um registro ou todos os dados?");
  puts("1 - Apenas 1 Registro");
  puts("2 - Todos os Dados");
  printf("Opcao: ");
  scanf(" %d", &op);
  puts("");
  if (op==1){
    char aux[500][20];
    char data[10];
    int i=0;
    int j=0;
    int k=0;
    char conf[5];
    puts("Digite a data do registro:");
    scanf("%s",data);
    puts("");
    FILE *arq;
    arq = fopen("extrato.txt","r");
    while( fgets(aux[i],20 , arq) != NULL ){
    i++;
    }
    fclose(arq);
    for(j=0;j!=i;j++){
      if (strstr(aux[j],data) != NULL){
        puts("Registro encontrado:");
        puts("=================================");
        printf("Categoria: %s", aux[j+1]);
        printf("Valor: %s", aux[j+2]);
        printf("Data: %s", aux[j]);
        puts("=================================");
        puts("");
        puts("Deseja excluir o registro encontrado? (s/n)");
        scanf("%s",conf);
        if (strcmp(conf,"s") == 0){
              FILE * arq2;
              arq2 = fopen("extrato.txt","w");
              for(k=0;k!=i;k++){
                if(j==k){
                  if(k+3>i){
                    k=k-4;
                    break;
                  }
                  printf("%d",i);
                  k=k+3;
                }
                fprintf(arq2, "%s", aux[k]);
              }
              fclose(arq2);
              puts("Registro excluído com sucesso!!!");

        }
        else{
          puts("Retornando ao menu...");
          break;
        }
        }
        }

  }
  else if (op==2){
    remove("extrato.txt");
    puts("=================================");
    puts("Excluindo...");
    puts("Todos os Dados foram excluídos com sucesso!");
  }
  sleep(1);
  return 0;
}

//Função para fazer seu extrato
void extrato(){
  char categoria[200];
  char data[15];
  float saldo;
  int i=0;
  puts("");
  puts("Extrato de todas as movimentações:");
  FILE * f;
  f = fopen("extrato.txt", "r");
  while (fscanf(f, "%s %s %f", categoria, data, &saldo) != EOF){
    puts("=================================");
    printf("Data: %s\nCategoria: %s\nValor: R$%.2f\n",data,categoria,saldo );
    puts("=================================");
  i++;
  }
  sleep(1);
}

//Função de busca!!!
void busca(){

}

//Função Main!!!!
int main(void) {
  int selecionar = 0;

  while(selecionar<5 || selecionar>0 ){
    struct Receita Receita;
    menu();
    puts("Digite sua opção!!!");
    scanf("%d", &selecionar);

    if(selecionar == 0){
      sair();
      break;
    }

    else if(selecionar == 1){
      inserir(&Receita);
    }

    else if(selecionar == 2){
      relatorio();
    }

    else if(selecionar == 3){

      float s;
      s = Receita.valor;
      puts("=================================");
      printf("Saldo Atual: R$ %.2f",s);
    }

    else if(selecionar == 4){
      excluir();
    }

    else if(selecionar == 5){
      extrato();
    }

    else if(selecionar == 6){
      busca();
    }

    else if (selecionar>6 || selecionar<0 ){
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
