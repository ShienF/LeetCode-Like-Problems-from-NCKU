/*
Description
The algorithm of quicksort could be describe as following:
1. You have an unsorted array, the index of first element is called "low", and the index of the last one is called "high".
2. Arbitrarily pick a number from the given array as "pivot". The "pivot" is used to "divide" the array into two sub-arrays, 
    according to whether they are less than or greater than the pivot. 
    In this question, we require you to always pick the last number in array as "pivot".
3. Iterate through the array (except the "pivot") to find the index of "pivot". 
    In this iteration, we keep moving the numbers that are smaller than "pivot" or equal to "pivot" to the front of the array, 
    and keep track of the index of the last number of them. After we finishing iterating, 
    the index of "pivot" is next to the last number that is smaller than it.
4. Move "pivot" to the position we found in step 2. At this point, you have "divide" the original array into two sub-arrays, 
    but they both are still unsorted.
5. Repeat step 1 - 4 on two sub-arrays recursively, until you find the length of divided sub-array is 1 or 0, which is trivially sorted.

We can illustrate this process with array 8 5 1 9 10 7 3 2 4 6:
   l                  h
1. 8 5 1 9 10 7 3 2 4 6 // you have an unsorted array, the first index is low, the last is high

   l                  h
2. 8 5 1 9 10 7 3 2 4 6 // pick the last one as "pivot", in this case, it is 6
                      p

   l                  h
3. 8 5 1 9 10 7 3 2 4 6 // move those numbers that are smaller than 6 to the front
   i                  p
   8 5 1 9 10 7 3 2 4 6 // 8 is bigger than 6, no action
 s i                  p
   5 8 1 9 10 7 3 2 4 6 // 5 is smaller than 6, move to the front
   s i                p
   5 1 8 9 10 7 3 2 4 6 // 1 is smaller than 6, move to the front
     s i              p
   5 1 8 9 10 7 3 2 4 6 // 9 is bigger than 6, no action
     s   i            p
   5 1 8 9 10 7 3 2 4 6 // 10 is bigger than 6, no action
     s      i         p
   5 1 8 9 10 7 3 2 4 6 // 7 is bigger than 6, no action
     s        i       p
   5 1 3 9 10 7 8 2 4 6 // 3 is smaller than 6, move to the front
       s        i     p
   5 1 3 2 10 7 8 9 4 6 // 2 is smaller than 6, move to the front
         s        i   p
   5 1 3 2 4 7 8 9 10 6 // 4 is smaller than 6, move to the front
           s        i p

   l                  h
4. 5 1 3 2 4 6 8 9 10 7 // move "pivot" to the center of two sub-arrays
             p

   l       h
5. 5 1 3 2 4 6 8 9 10 7 // repeat it on sub-arrays recursively
           p
-> 1 3 2 4 5 6 8 9 10 7
         p

...

5. 1 2 3 4 5 6 7 8 9 10 // Sorted!
It is better that we can trace the sorting process with our eye than with our mind. 
So besides implementing the sorting algorithm above, we need you to print out the result of step 4 everytime you "conquer" the sub problem. You need to use bracket [ ] to show the range of sub-array, and put asterisk * in front of the pivot in that sub-array. Please refer to the sample output.

=======================================================================================================
Input
The first line is an integer n (1 <= n <= 500), indicating the number of numbers in the given array.
The following line is an unsorted array with n integer numbers. Notice that there may be duplicated value in the array.

Output
The process of quick sort, line by line.
And the final line is the sorted array.
Please refer to samples.

Limits
Your program needs to finish task in 1 second.
Your program can only use memory less than 65536 KB.
=======================================================================================================
Sample 1
Input
10
8 5 1 9 10 7 3 2 4 6
Output
[ 5 1 3 2 4 *6 8 9 10 7 ] 
[ 1 3 2 *4 5 ] 6 8 9 10 7 
[ 1 *2 3 ] 4 5 6 8 9 10 7 
1 2 3 4 5 6 [ *7 9 10 8 ] 
1 2 3 4 5 6 7 [ *8 10 9 ] 
1 2 3 4 5 6 7 8 [ *9 10 ] 
1 2 3 4 5 6 7 8 9 10 

Sample 2
Input
1
1
Output
1 

Sample 3
Input
10
2 7 10 1 9 6 3 2 5 6 
Output
[ 2 1 6 3 2 5 *6 9 10 7 ] 
[ 2 1 3 2 *5 6 ] 6 9 10 7 
[ 2 1 *2 3 ] 5 6 6 9 10 7 
[ *1 2 ] 2 3 5 6 6 9 10 7 
1 2 2 3 5 6 6 [ *7 10 9 ] 
1 2 2 3 5 6 6 7 [ *9 10 ] 
1 2 2 3 5 6 6 7 9 10 

Sample 4
Input
10
10 11 12 13 14 15 16 17 18 19 
Output
[ 10 11 12 13 14 15 16 17 18 *19 ] 
[ 10 11 12 13 14 15 16 17 *18 ] 19 
[ 10 11 12 13 14 15 16 *17 ] 18 19 
[ 10 11 12 13 14 15 *16 ] 17 18 19 
[ 10 11 12 13 14 *15 ] 16 17 18 19 
[ 10 11 12 13 *14 ] 15 16 17 18 19 
[ 10 11 12 *13 ] 14 15 16 17 18 19 
[ 10 11 *12 ] 13 14 15 16 17 18 19 
[ 10 *11 ] 12 13 14 15 16 17 18 19 
10 11 12 13 14 15 16 17 18 19 

Sample 5
Input
10
13 12 11 10 9 8 7 6 5 4 
Output
[ *4 12 11 10 9 8 7 6 5 13 ] 
4 [ 12 11 10 9 8 7 6 5 *13 ] 
4 [ *5 11 10 9 8 7 6 12 ] 13 
4 5 [ 11 10 9 8 7 6 *12 ] 13 
4 5 [ *6 10 9 8 7 11 ] 12 13 
4 5 6 [ 10 9 8 7 *11 ] 12 13 
4 5 6 [ *7 9 8 10 ] 11 12 13 
4 5 6 7 [ 9 8 *10 ] 11 12 13 
4 5 6 7 [ *8 9 ] 10 11 12 13 
4 5 6 7 8 9 10 11 12 13 
*/

/*code*/
#include <stdio.h>
#define N 500
#define swap(x, y) {int tmp = x; x = y; y = tmp;}

void quicksort(int a[], int low, int high);
int partition(int a[], int low, int high);

int size;

int main(void){
    int array[N];
    scanf("%d", &size);

    for (int i = 0; i < size; i++){
        scanf("%d", &array[i]);
    }

    quicksort(array, 0, size - 1);

    for (int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }
    return 0;
}

void quicksort(int a[], int low, int high) {

    int p = partition(a, low, high);

    if(low >= high){ ///termination
    	return;
    }

    for(int i=0; i<size; i++){
        if(i==low){
        printf("[ ");
        }

        if(i==p){
        	printf("*");
        }

        printf("%d ",a[i]);

    	if(i==high){
            printf("] ");
        }

        if(i==size-1){
            printf("\n");
        }
    }
   
    if(p!=0){ ///termination
        quicksort(a,low,p-1);
    }
    quicksort(a,p+1,high);

}

int partition(int a[], int low, int high) {

	int p = high;
    int s=-1;
    for(int i=0; i<high; i++){
        if(a[i] <= a[p]){
            s++;
            swap(a[s],a[i])
        }
    }

    swap(a[s+1],a[p]);    

    return s+1;
}
