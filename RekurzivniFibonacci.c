#include <stdio.h>
#include <sys/types.h>
#include <time.h>
#include <sys/timeb.h>
#include<stdlib.h>

    typedef struct
	{
        
	        long long int brojPozivaFunkcijeFibo;
	        long long int broj;
        

	}Fibonacci;

	

	Fibonacci fibo(Fibonacci A, int n)
	{    
            
        	
	
	

		if(n==0)
		{
			A.broj=0;
			A.brojPozivaFunkcijeFibo++;
			
		} 

		else if(n==1) 
		{
			A.broj=1;
			A.brojPozivaFunkcijeFibo++;
			

        	} 
		
		else 
       		{	Fibonacci A1 = fibo(A,n-1); 
			Fibonacci A2 = fibo(A,n-2);
			
			
			A.broj = A1.broj + A2.broj;
			A.brojPozivaFunkcijeFibo+=A1.brojPozivaFunkcijeFibo + A2.brojPozivaFunkcijeFibo+1;
			
			
						
			
       		}
			
	

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
    	
	rezultat.brojPozivaFunkcijeFibo=0;

    ftime(&start);

    //start your code block here
    rezultat= fibo(rezultat,n); 
    //End your code block here

    ftime(&kraj);
    //Calculate the time difference in milliseconds
    trajanje = (kraj.time  - start.time) * 1000 +(kraj.millitm- start.millitm);

    printf("\nRekurzivni Fibonacci:\n");
	
	printf("\n\n %d -ta vrijednost Fibonaccijevog niza je: %lld ", n+1, rezultat.broj);
    
	printf("\n\ntrajanje: %d ms",trajanje);

	printf("\n\nBroj poziva funkcije fibo(): %lld ", rezultat.brojPozivaFunkcijeFibo);
	printf("\n\n\n");
	system("pause");
   
}