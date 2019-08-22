# include <stdio.h>

int primos[4123];

int g (int n){
  int f=1;
  for (int i =1; i<= n ; i++){
    f = (f+primos[n-i+1]-1)%i+1;
    //printf("%d %d - primo\n",(n-i+1),primos[n-i+1]);
  }
  return f;
}


int ehprimo (int num){
  if (num < 2) return 0;
  else if (num < 4) return 1;
  else if (!(num%2)) return 0;
  for (int i=3;i<num/2;i+=2)
    if ( num%i == 0) return 0;
  return 1;
}



int main (){
  int n=17;
  int numb=1;
  primos[1]=2; 

  for (int i=2;i<=3501;i++){
    numb+=2;
    while(!ehprimo(numb)){
     numb+=2;
    }
    primos[i]=numb;
    
  }
  while (scanf("%d",&n),n!=0){
    printf ("%d\n",g(n));
  }
  return 0;
}
