/*
 * Title: performance.cpp
 * Abstract: This program compares the running times of selectionsort, quicksort,
 *            and insertionsort. It gives the user the option of choosing a list
 *            that is sorted in ascending or descending order, or that is random.
 *            NOTE: A blank file "input.txt" must be in the same directory as the program
 * Author: Hanna Bonert 
 * ID: 3333
 * Date: 05/29/2018 
 */
#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h> 

using namespace std;

void selectionSort(int A[ ], int lengthA);
void insertionSort(int A[ ], int lengthA);
void quickSort(int A[ ], int l, int r);
void generateInputData(int A[], int inputSize, int orderNumber);
int HoarePartition(int A[ ], int l, int r);

int main()
{
   int inputSize, orderChoice;
   time_t startTime, endTime;
   double elapsedTime;
   string startStr, endStr;

   cout << "Please enter an input size: ";
   cin >> inputSize;

   cout << "Select order of input numbers: " << endl;
   cout << "1. Ascending Order" << endl << "2. Descending Order" << endl  
        << "3. Random Order" << endl;
   cout << "Choose Order: ";
   cin >> orderChoice;

   int * A;
   A = new int [inputSize];

   generateInputData(A, inputSize, orderChoice);

   int * B;
   B = new int [inputSize];

   int * C;
   C = new int [inputSize];

   //write the input data that was generated to "input.txt"
   ofstream inputFile;
   inputFile.open ("input.txt");
   
   for(int i = 0; i < inputSize; i++)
      inputFile << A[i] << " ";
      
    inputFile.close();
      
   //copy the data into other arrays for the three sorting algorithms, as they sort in-place      
   for(int i = 0; i < inputSize; i++)
      B[i] = C[i] = A[i];

   startTime = time(NULL);
   selectionSort(A, inputSize);
   endTime = time(NULL);
   elapsedTime = endTime - startTime;
   cout << "Selection sort performance---------------" << endl;
   cout << "Starting time: " << ctime(&startTime);
   cout << "Ending time: " << ctime(&endTime);
   cout << "Elapsed time: " << elapsedTime << " seconds" << endl << endl;

   startTime = time(NULL);
   insertionSort(B, inputSize);
   endTime = time(NULL);
   elapsedTime = endTime - startTime;
   cout << "Insertion sort performance---------------" << endl;
   cout << "Starting time: " << ctime(&startTime);
   cout << "Ending time: " << ctime(&endTime);
   cout << "Elapsed time: " << elapsedTime << " seconds" << endl << endl;

   startTime = time(NULL);
   quickSort(C, 0, inputSize - 1);
   endTime = time(NULL);
   elapsedTime = endTime - startTime;
   cout << "Quick sort performance---------------" << endl;
   cout << "Starting time: " << ctime(&startTime);
   cout << "Ending time: " << ctime(&endTime);
   cout << "Elapsed time: " << elapsedTime << " seconds" << endl << endl;

   delete [] A;
   delete [] B;
   delete [] C;

}

//generates input data according to the user's choice
void generateInputData(int A[], int inputSize, int orderNumber)
{
    switch(orderNumber)
    {
        //ascending order
        case 1: for(int i = 0; i < inputSize; i++)
                   A[i] = i + 1;
                break;
        //descending order
        case 2: for(int i = inputSize, j = 0; i > 0; i--, j++)
                   A[j] = i;
                break;
        //random
        case 3: srand (time(NULL));
                for(int i = 0; i < inputSize; i++)
                {
                    
                    A[i] = rand() % (2 * inputSize);
                }
                   break;
    }
}

/*This sorting algorithm scans the array, finds the smallest element, and
* exchanges it with the first element. Then it scans the list from the second
* element onwards, and places the minimal element in the second position. The
* algorithm continues until the list is finished. Efficiency: Theta (n^2)
* CAUTION: This function sorts the array in place
*/
void selectionSort(int A[ ], int lengthA)
{
   int min, temp;

   for(int i = 0; i < lengthA - 1; i++)
   {
      min = i;

      for(int j = i + 1; j < lengthA; j++)
      {
         if(A[j] < A[min])
            min = j;
      }

      temp = A[i];
      A[i] = A[min];
      A[min] = temp;
   }
}

//insertionsort algorithm- sorts in-place
void insertionSort(int A[], int lengthA)
{
   int value, compPos;
   for(int i = 1; i < lengthA; i++)
   {
      value = A[i];
      compPos = i - 1;

      while(compPos >= 0 && A[compPos] > value)
      {
         A[compPos + 1] = A[compPos];
         compPos--;
      }
      A[compPos + 1] = value;
   }
}

//quicksort algorithm- sorts in place
void quickSort(int A[ ], int l, int r)
{
   int s;
   if(l < r)
   {
      s = HoarePartition(A, l, r);
      quickSort(A, l, s - 1);
      quickSort(A, s + 1, r);
   }
}

//helper function to quicksort algorithm that performs the partitioning
int HoarePartition(int A[ ], int l, int r)
{
   int p = A[l], i = l, j = r + 1, temp;

   do
   {
      do
      {
         i++;
      } while(A[i] < p);

      do
      {
         j--;
      } while(A[j] > p);


      temp = A[i];
      A[i] = A[j];
      A[j] = temp;

   } while(i < j);


   temp = A[i];
   A[i] = A[j];
   A[j] = temp;

   temp = A[l];
   A[l] = A[j];
   A[j] = temp;


   return j;
}

