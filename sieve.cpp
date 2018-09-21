/*
 * Title: sieve.cpp
 * Abstract: This program implements the sieve of Eratosthenes algorithm, based 
             on the pseudocode on page 6 of the textbook.
             It finds the list of primes not exceeding n (which is provided by the user)
 * Author: Hanna Bonert 
 * ID: 3333
 * Date: 05/1/2018 
 */
 
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n, j, primeCount;
    
    cout << "Enter a number: " << endl;
    cin >> n;
    
    primeCount = n - 1; //keeps track of how many primes we have left
                        //We don't need n spots becuase we discount 1
    int * numbers;
    numbers = new int [n + 1];
    
    for(int p = 2; p <= n; p++)
       numbers[p] = p;
       
    for(int p = 2; p <= sqrt(n); p++)
    {
        if(numbers[p] != 0)
        {
           j = p * p;
           while(j <= n)
           {
               if(numbers[j] != 0)
                  primeCount--; //decrease the primeCount if we have not deleted
                                //this before
               numbers[j] = 0;
               j += p;
           }
        }
    }
    
    int * primes;
    primes = new int [primeCount];
    
    int i = 0;
    for(int p = 2; p <= n; p++)
    {
        if(numbers[p] != 0)
        {
            primes[i] = numbers[p];
            i++;
        }
    }
      
    cout << "Prime numbers: ";
    for(int i = 0; i < primeCount; i++)
       cout << primes[i] << " ";
    cout << endl;
    
    delete [] numbers;
    delete [] primes;
    return 0;
}