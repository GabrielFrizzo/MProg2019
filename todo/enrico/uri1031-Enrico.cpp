# include <stdio.h>

int g(int n, int k,int w){
  while(w<0) w+=n+1; 
  
  if (n==1)
    return 0;
  else if (w==0)
    return 1;
  else if (n>=k)
    return (w==k)?1:g(n-1,k,(w-k));
  else{	
    int nc=(k%n==0?n:k%n);
    return(w==nc)?1: g (n-1,k,w-k);
  }
}

int main (){
  int n=17,k;
  while (scanf("%d",&n),n!=0){
    
    for (k=1;g(n-2,k,12-k);k++);
    printf ("%d\n",k);
  }
  return 0;
}
