#include <stdio.h>
#include <sys/types.h>
#include <time.h>
#include <sys/timeb.h>
#include<stdlib.h>
#include<math.h>



typedef struct
{
	long long int brojPozivaFunkcijeFibo;
	long long int matrica[2][2];


}Fibonacci;

void mnozenje(long long int M1[2][2],long long int M2[2][2]);
void potenciranje(long long int A[2][2], int n);

Fibonacci fibo(int n)
{	
	    Fibonacci A;
	    
	    A.brojPozivaFunkcijeFibo=0;
	    
	    A.matrica[0][0]=0;
	    A.matrica[0][1]=1;
        A.matrica[1][0]=1;
	    A.matrica[1][1]=1;
		

            if(n == 0)
	      { 
		A.matrica[0][0]=0;
		A.matrica[0][1]=0;
		A.matrica[1][0]=0;
		A.matrica[1][1]=0;  
                
		
		A.brojPozivaFunkcijeFibo=1;
		
		return A;
	      }
		
	     A.brojPozivaFunkcijeFibo++;
	     
	     if(n == 0)
	      { 
		A.matrica[0][0]=0;
		A.matrica[0][1]=0;
		A.matrica[1][0]=0;
		A.matrica[1][1]=0;  
              
		
	      }
	     
	     else { 
			
			potenciranje(A.matrica,n);
		  }	      

	
	       
	
	        return A;	
	}

void potenciranje(long long int A[2][2], int n)
{	

	long long  int M[2][2] = {{1,0},{0,1}};
	
	while(n!=0)
	{
	
	

	if(n%2!=0)
	{
	mnozenje(M,A);
	
	}

	n=n/2;
    mnozenje(A,A);
	
	}
	
	
    A[0][0]=M[0][0];
	A[0][1]=M[0][1];
	A[1][0]=M[1][0];
	A[1][1]=M[1][1];
	
}

void mnozenje(long long int M1[2][2],long long int M2[2][2])
{
		
		
		long long int a = M1[0][0]*M2[0][0] + M1[0][1]*M2[1][0];
		long long int b = M1[0][0]*M2[0][1] + M1[0][1]*M2[1][1];
		long long int c = M1[1][0]*M2[0][0] + M1[1][1]*M2[1][0];
		long long int d = M1[1][0]*M2[0][1] + M1[1][1]*M2[1][1];

	      	M1[0][0]=a;
	        M1[0][1]=b;
	       	M1[1][0]=c;
	       	M1[1][1]=d;
		
}



int main(void)
  {

void ftime(struct timeb *tp);

int i ,j;

struct timeb start,kraj;

long trajanje;


    int n;
     
	printf("Unesi prirodan broj n: ");
	scanf("%d",&n);
    
    

	ftime(&start);

    Fibonacci Fibo = fibo(n);
  
	ftime(&kraj);
   
    long long int vrijednostFibonaccijevogNiza = Fibo.matrica[1][0];
	long long  int brojPozivaFunkcijeFibo = Fibo.brojPozivaFunkcijeFibo;

	
    trajanje = (kraj.time  - start.time) * 1000 +(kraj.millitm- start.millitm);

    printf("\nMatricni Fibonacci:\n");
	
	printf("\n %d  -ta vrijednost Fibonaccijevog niza je: %lld ", n+1 ,vrijednostFibonaccijevogNiza);

    
	printf("\n\ntrajanje: %d ms",trajanje);
	
	printf("\nBroj poziva funkcije fibo(): %lld ",brojPozivaFunkcijeFibo);
	
	
    
	printf("\n\n\n");
	system("pause");
   
}