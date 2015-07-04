#include <stdio.h>
#include <sys/types.h>
#include <time.h>
#include <sys/timeb.h>
#include<stdlib.h>




	typedef struct
	{	
		long long int brojPozivaFunkcijeFibo;
	    long long int *FiboNiz;
	
	}Fibonacci;

	Fibonacci fibo(Fibonacci A,int n)
	{	
		
		A.brojPozivaFunkcijeFibo++;
		
		if(n==0) {
		A.FiboNiz[0]=0;
		return A;		
		}
		
		A.FiboNiz[0] = 0;
		
		A.FiboNiz[1] = 1;
		
		int i;

		for( i = 2; i<=n ; i++ )
			
			A.FiboNiz[i] = A.FiboNiz[i-1] + A.FiboNiz[i-2];
		
			
		
		return A;	
	}

int main()
  {

void ftime(struct timeb *tp);

int i ,j;

struct timeb start,kraj;

long trajanje;


    int n;
     
	printf("Unesi prirodan broj n: ");
	scanf("%d",&n);
    
    Fibonacci rezultat; 

	rezultat.FiboNiz = (long long int*)malloc((n+1)*sizeof(long long int));	
	
	rezultat.brojPozivaFunkcijeFibo=0;	

    ftime(&start);

    rezultat= fibo(rezultat,n); 
  
	ftime(&kraj);
   
    trajanje = (kraj.time  - start.time) * 1000 +(kraj.millitm- start.millitm);

    printf("\nIterativni Fibonacci:\n");
		
	printf("\n (%d +1) -ta vrijednost Fibonaccijevog niza je: %lld ", n, rezultat.FiboNiz[n]);
    
	printf("\n\ntrajanje: %d ms",trajanje);
	
	printf("\nBroj poziva funkcije fibo(): %lld ", rezultat.brojPozivaFunkcijeFibo);
	
	free(rezultat.FiboNiz); 
    
	printf("\n\n\n");
	system("pause");
   
}