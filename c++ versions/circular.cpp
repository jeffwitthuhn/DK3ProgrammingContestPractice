//example problem 5
#include <fstream>
#include <iostream>
#include <vector> 
#include <cassert>
#include <math.h>
using namespace std;
/* 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main(void)
{
    unsigned int lim, i, j;

    printf("Find primes upto: ");
    scanf("%d", &lim);
    lim += 1;
    bool *primes = calloc(lim, sizeof(bool));

    unsigned int sqrtlim = sqrt(lim);
    for (i = 2; i <= sqrtlim; i++)
        if (!primes[i])
            for (j = i * i; j < lim; j += i)
                primes[j] = true;

    printf("\nListing prime numbers between 2 and %d:\n\n", lim - 1);
    for (i = 2; i < lim; i++)
        if (!primes[i])
            printf("%d\n", i);

    return 0;
}
*/

bool isPrime (long long int num)
{
    if (num <=1)
        return false;
    else if (num == 2)         
        return true;
    else if (num % 2 == 0)
        return false;
    else
    {
        bool prime = true;
        int divisor = 3;
        double num_d = static_cast<double>(num);
        int upperLimit = static_cast<int>(sqrt(num_d) +1);
        
        while (divisor <= upperLimit)
        {
            if (num % divisor == 0)
                prime = false;
            divisor +=2;
        }
        return prime;
    }
}
bool checkprime (long long int num)
{
    if (num <=1)
        return false;
    else if (num == 2)        
        return true;
    else if (num % 2 == 0)
        return false;
    else
    {
        bool prime = true;
        int divisor = 3;
      
        int upperLimit =sqrt(num) +1;
        
        while (divisor <= upperLimit)
        {
            if (num % divisor == 0)
                return false;
            divisor +=2;
        }
        return prime;
    }
}
     
     
bool rounder(long int i)
{
     long int dup1,dup2;
     int k,flag=0;
     dup1=dup2=i;
                          if(checkprime(i))
                          {
                                          
                            do
                            {flag=0; k=1; dup1=dup2;
                                   while(dup1>9)
                                   {
                                                if(dup1%10==0)
                                                flag=1;
                                              dup1/=10;
                                              k*=10;}
                                             
                                              dup2=((dup2%k)*10) + dup1;
                                      
                                              if(!checkprime(dup2))
                                              return false;
                                              }while((dup2!=i)&&(flag==0));
                                              if(flag==1)
                                              return false;
                                              else
                                              return true;}
                            else return false;
                            
                            }
std::vector<int>  getSieveOfEratosthenes ( long long int max )
	{
	  std::vector<bool> primes(max, true);
	  int sz = primes.size();

	  for ( int i = 3; i < sz ; i+=2 )
	    if ( primes[i] ) 
	      for ( int j = i * i; j < sz; j+=i)
	        primes[j] = false;

	  std::vector<int> ret;
	  ret.reserve(primes.size());
	  ret.push_back(2);

	  for ( int i = 3; i < sz; i+=2 )
	    if ( primes[i] )
	      ret.push_back(i);

	  return ret;
	}
//INCOMPLETE
int main(){
	ifstream infile("CircularIn.txt"); 
	ofstream outfile("CircularOut.txt"); 
	vector<int> primes=getSieveOfEratosthenes(100000);
	for(int i=0; i<primes.size(); i++){
		//assert(isPrime(primes[i]));
		cout<<primes[i]<<" ";
	}

	cout<<endl;

	for(int z=0; z<2; z++){	
		unsigned long long int count=0;
		//do fancy things to calculate prime numbers fermats little theorem ect.
		//do fancy things to rotate the numbers. 
		cout << count; 
		outfile << count;
	}

	return 0; 
}