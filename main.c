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


//Fun��o para o menu aparecer!!!
void menu(void){
puts("");
puts("=================================\n");
puts("Menu de op��es\n");
puts("=================================\n");
puts("0 - Sair\n"); //ok
puts("1 - Inserir\n"); //ok
puts("2 - Relat�rio\n");//FALTA S� ESTA MERDA!!!!!
puts("3 - Saldo\n"); //ok
puts("4 - Excluir\n");//ok
puts("5 - Extrato de todas as movimenta��es\n"); //ok
puts("6 - Buscar um registro espec�fico");//ok
puts("=================================\n");
}

//Fun��o para sair do programa
int sair(){
  puts("Saindo...");
  puts("Obrigado por utilizar nosso sistema!");
  return 0;
}

//Fun��o de inser��o
int inserir(struct Receita * p){
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

    puts("Digite a categoria: (moradia, alimentacao, lazer, transporte, estudos, compras, trabalho)");
    scanf("%s", Gasto.categoria);

      while ((strcmp(Gasto.categoria, "moradia") != 0) && (strcmp(Gasto.categoria, "alimentacao") != 0) && (strcmp(Gasto.categoria, "lazer") != 0) && (strcmp(Gasto.categoria, "transporte") != 0) && (strcmp(Gasto.categoria, "estudos") != 0) && (strcmp(Gasto.categoria, "compras") != 0) && (strcmp(Gasto.categoria, "trabalho") != 0)){
            puts("Categoria inv�lida! Tente novamente...");
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
    puts("Digite a categoria: (moradia, alimenta��o, lazer, transporte, estudos, compras, trabalho)");
    scanf("%s", Receita.categoria);

      while ((strcmp(Receita.categoria, "moradia") != 0) && (strcmp(Receita.categoria, "alimenta��o") != 0) && (strcmp(Receita.categoria, "lazer") != 0) && (strcmp(Receita.categoria, "transporte") != 0) && (strcmp(Receita.categoria, "estudos") != 0) && (strcmp(Receita.categoria, "compras") != 0) && (strcmp(Receita.categoria, "trabalho") != 0)){
            puts("Categoria inv�lida! Tente novamente...");
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

//Fun��o para o relatorio
int relatorio(){
  puts("Relat�rio Pronto!");
  sleep(1);
  return 0;
}

//Fun��o para excluir um registro
int excluir(struct Receita * p){
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
    float valor;
    char conf[5];
    puts("Digite a data do registro(dd/mm/aa):");
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
        valor=atof(aux[j+2]);
        if (strcmp(conf,"s") == 0){
              FILE * arq2;
              arq2 = fopen("extrato.txt","w");
              for(k=0;k<i;k++){
                if(j==k){
                  if(k+3>i){
                    break;
                  }
                  k=k+3;
                }
                fprintf(arq2, "%s", aux[k]);
              }
              fclose(arq2);
              puts("Registro exclu�do com sucesso!!!");
              p->valor=p->valor-valor;

        }
        else if(strcmp(conf,"n") == 0){
          puts("Buscando outro registro na data informada...Caso nenhum seja encontrado, voc� retornar� ao menu...\n");
          sleep(2);
        }
        else{
          puts("Comando inv�lido, voltando ao menu...");
          sleep(2);
          break;
        }

        }
        }

  }
  else if (op==2){
    remove("extrato.txt");
    puts("=================================");
    puts("Excluindo...");
    puts("Todos os Dados foram exclu�dos com sucesso!");
  }
  sleep(1);
  return 0;
}

//Fun��o para fazer seu extrato
void extrato(){
  char categoria[200];
  char data[15];
  float saldo;
  int i=0;
  puts("");
  puts("Extrato de todas as movimenta��es:");
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


//Fun��o de busca!!!
void busca(){
    char categoria[200];
    char data[15];
    int i = 0, j = 0;
    char aux[500][20];
    puts("Digite a data do registro que deseja encontrar: (dd/mm/aa)");
    scanf("%s",data);
    puts("");
    puts("Digite a categoria do registro que deseja encontrar: (moradia, alimentacao, lazer, transporte, estudos, compras, trabalho)");
    scanf("%s",categoria);
    puts("");
    FILE *arq;
    arq = fopen("extrato.txt","r");
    while( fgets(aux[i],20 , arq) != NULL ){
    i++;
    }
    fclose(arq);
    for(j=0;j!=i;j++){
      if (strstr(aux[j],data) != NULL){
        if (strstr(aux[j+1],categoria) != NULL){
        puts("Registro encontrado:");
        puts("=================================");
        printf("Categoria: %s", aux[j+1]);
        printf("Valor: %s", aux[j+2]);
        printf("Data: %s", aux[j]);
        puts("=================================");
        puts("");
        }
      else{
        puts("=================================");
        puts("Registro n�o encontrado!");
        puts("=================================");
      }
    }
  }
}

//Recebe o saldo!
int receberSaldo(struct Receita * p){
  FILE * f;
    f=fopen("saldo.txt", "r");
     fscanf(f, "%f", &p->valor);

    fclose(f);
    return 0;
}
//Salva o saldo antes de sair
int saida(struct Receita * p){
  FILE * f;
      f=fopen("saldo.txt","w");
      fprintf(f, "%.2f", p->valor);
      fclose(f);
      return 0;
}

//Fun��o Main!!!!
int main(void) {
  int selecionar = 0;
  struct Receita Receita;
  receberSaldo(&Receita);
  //receberSaldo(&Receita);

  while(selecionar<5 || selecionar>0 ){

    menu();
    puts("Digite sua op��o!!!");
    scanf("%d", &selecionar);

    if(selecionar == 0){
      saida(&Receita);
      puts("Saindo...");
      puts("Obrigado por utilizar nosso sistema!");
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
      excluir(&Receita);
    }

    else if(selecionar == 5){
      extrato();
    }

    else if(selecionar == 6){
      busca();
    }

    else if (selecionar>6 || selecionar<0 ){
      puts("N�mero Invalido, tente outro!!!");
    }
  }
  return 0;
}
