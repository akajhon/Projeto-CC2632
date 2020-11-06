
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
puts("2 - Relatório\n");//FALTA SÓ ESTA MERDA!!!!!
puts("3 - Saldo\n"); //ok
puts("4 - Excluir\n");//ok
puts("5 - Extrato de todas as movimentações\n"); //ok
puts("6 - Buscar um registro específico");//ok
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
    int i=-1542;
  FILE * f;
  f=fopen("relatorio_mensal.html","w");
  fprintf(f, "<html><head><style>body {position: relative;top: 20%;left: 400px;width: 100%;text-align: center;}</style><script type='text/javascript' src='https://www.gstatic.com/charts/loader.js'></script><script type='text/javascript'>google.charts.load('current', {'packages':['bar']});google.charts.setOnLoadCallback(drawChart);function drawChart() {var data = google.visualization.arrayToDataTable([['Categorias', 'Valor Gasto no Mês'],['Moradia',");
  fprintf(f,"%d",i);
  fprintf(f,"],['Alimentação', 1300],['Lazer',800],['Transporte',700],['Estudos',300],['Compras',200],['Trabalho',100]]);var options = {chart: {title: 'Relatório Mensal',subtitle: 'Relatório de movimentações para cada categoria do ́ultimo mês',}};var chart = new google.charts.Bar(document.getElementById('columnchart_material'));chart.draw(data, google.charts.Bar.convertOptions(options));}</script></head><body><div id='columnchart_material' style='width: 800px; height: 500px;''></div></body></html>");
  fclose(f);
  puts("Relatório Pronto!");
  sleep(1);
  return 0;
}

//Função para excluir um registro
int excluir(struct Receita * p){
  puts("");
  int op;
  puts("Voce deseja remover um registro ou todos os dados?");
  puts("0 - Voltar ao Menu");
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
              puts("Registro excluído com sucesso!!!");
              p->valor=p->valor-valor;

        }
        else if(strcmp(conf,"n") == 0){
          puts("Buscando outro registro na data informada...Caso nenhum seja encontrado, você retornará ao menu...\n");
          sleep(2);
        }
        else{
          puts("Comando inválido, voltando ao menu...");
          sleep(2);
          break;
        }

        }
        }

  }
  else if (op==2){
    remove("extrato.txt");
    p->valor=0;
    puts("=================================");
    puts("Excluindo...");
    puts("Todos os Dados foram excluídos com sucesso!");
  }
  sleep(1);
  return 0;
  if(op==0){
    puts("=================================");
    puts("Voltando ao menu!!!");
    sleep(1);
    return 0;
  }
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
        puts("Registro não encontrado!");
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

//Função Main!!!!
int main(void) {
  int selecionar = 0;
  struct Receita Receita;
  receberSaldo(&Receita);
  //receberSaldo(&Receita);

  while(selecionar<5 || selecionar>0 ){

    menu();
    puts("Digite sua opção!!!");
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
      sleep(1);
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
      puts("Número Invalido, tente outro!!!");
    }
  }
  return 0;
}

/*   ██░▀██████████████▀░██
   █▌▒▒░████████████░▒▒▐█
   █░▒▒▒░██████████░▒▒▒░█
   ▌░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░▐
   ░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░
███▀▀▀██▄▒▒▒▒▒▒▒▄██▀▀▀██
██░░░▐█░▀█▒▒▒▒▒█▀░█▌░░░█
▐▌░░░▐▄▌░▐▌▒▒▒▐▌░▐▄▌░░▐▌
   █░░░▐█▌░░▌▒▒▒▐░░▐█▌░░█
   ▒▀▄▄▄█▄▄▄▌░▄░▐▄▄▄█▄▄▀▒
   ░░░░░░░░░░└┴┘░░░░░░░░░
   ██▄▄░░░░░░░░░░░░░░▄▄██
   ████████▒▒▒▒▒▒████████
   █▀░░███▒▒░░▒░░▒▀██████
   █▒░███▒▒╖░░╥░░╓▒▐█████
   █▒░▀▀▀░░║░░║░░║░░█████
   ██▄▄▄▄▀▀┴┴╚╧╧╝╧╧╝┴┴███
   ██████████████████████*/
