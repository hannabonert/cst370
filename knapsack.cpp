/*
 * Title: knapsack.cpp
 * Abstract: This program solves the Knapsack problem.
 * Author: Hanna Bonert 
 * ID: 3333
 * Date: 05/22/2018 
 */
 
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    int numItems, binNumbers, knapCap, setCounter = 1, weight, value, maxValue = 0, maxCap = 0;
    vector<int> solVec; //used to keep track of the solution set
    
    cout << "Enter a number of items: ";
    cin >> numItems;
    
    binNumbers = pow(2, numItems) - 1; 
    
    int * binaryArray; //create an array to hold a binary number- one element per character
    binaryArray = new int [numItems];
    
    int * weightArray; //create an array to hold the weights of the items
    weightArray = new int [numItems];
    
    int * valueArray; //create an array to hold the values of the items
    valueArray = new int [numItems];
    
    cout << "Enter knapsack capacity: ";
    cin >> knapCap;
    
    cout << "Enter weights and values of " << numItems << " items:" << endl;
    
    for(int i = 0; i < numItems; i++)
    {
        cout << "Item " << i + 1 << ": ";
        cin >> weightArray[i];
        cin >> valueArray[i];
    }
   
    int dividedNum, remainder, indexCounter;
    
    for(int i = 0; i < binNumbers + 1; i++)
    {
        //algorithm to convert i to its binary representation
        dividedNum = i;
        indexCounter = 0;
        while(dividedNum > 0)
        {
           remainder = dividedNum % 2;
           dividedNum /= 2;
           binaryArray[indexCounter] = remainder;
           indexCounter++;
        }
        indexCounter = 0;
        
        //convert binary representations to their item number subsets
        //if the binary array has a 1 at that position, substitute with the 
        //corresponding item number (i + 1)
        weight = value = 0;
        cout << "set " << setCounter << ": { ";
        for(int i = 0; i < numItems; i++)
        {
           if(binaryArray[i] == 1)
           {
              cout << i + 1 << " ";
              weight += weightArray[i];
              value += valueArray[i];
           }
        }
        cout << "}   " << "capacity: " << weight;

        if(weight > knapCap)
           cout << "-over capacity, value n/a" << endl;
        else
        {
           cout << ", value: $" << value << endl;
           //if the weight of this set is the highest, this is the solution
           //so set all values
           if(value > maxValue)
           {
              maxValue = value;
              maxCap = weight;
              while(!solVec.empty())
                 solVec.pop_back();
              for(int i = 0; i < numItems; i++)
              {
                 if(binaryArray[i] == 1)
                    solVec.push_back(i + 1);
              }
           }
        }
        setCounter++;
    }

    //report solution
    cout << "Solution: { ";
    while(!solVec.empty())
    {
        cout << solVec.back() << " ";
        solVec.pop_back();
    }
    cout << "}  value: $" << maxValue << ", capacity: " << maxCap << endl;
    
    delete [] binaryArray;
    delete [] weightArray;
    delete [] valueArray;
    return 0;
}