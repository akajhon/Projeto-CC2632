#include <stdio.h>
int numerosDistintos (int* v, int n) {
int v2[n];
int i,j, repete = 0;
int x=0;

for (i=0; i<n; i++){
  if (i==0){
    v2[x] = v[i];
    x++;
  }
  else {
    repete = 0;

    for(j = 0; j <x; j++){
      if(v[i] == v2[j]){
        repete++;
      }
    }

    if(repete<1){
      v2[x]=v[i];
      x++;

    }
  }
}

  return x;
}

int main(void) {

  int n;
  int i;
  scanf("%d", &n);

  int v[n];

  for(i=0;  i<n  ;i++){
    scanf("%d", &v[i]);
  }


 printf("%d", numerosDistintos(v, n));
 puts("ALTEREI AQUI");
 puts("O Jô passou por aqui....")

  return 0;
}
