/*
Description
Matsumoto is a brilliant AI that is built and sent to the past to prevent a war between humans and AI. 
When on his way back to the past, he will receive a set of encoded coordinates indicating where to go.

To decode the coordinates, he has to follow the following steps:
1. split the received line of characters into two groups: characters at odd positions and characters at even positions (index starts by 0 and from left)
2. sum up the numbers in each group
3. write these two numbers into hexadecimal
4. process the two numbers from step 1 if the length of the number is greater than 1
5. the coordinate is the concatenate of the result of the two numbers (the odd one on the left)

=======================================================================================================
Input
A newline character terminated string indicates the encoded coordinate.
The length of the string will be greater than 1 and less than 10001.
Each character represents a hexadecimal, the upper case and the lower case are both possible.

Output
A single line that indicates the decoded coordinate, the letter of the coordinate should be shown in lower case (if any).

Limits
Your program needs to finish task in 1 second.
Your program can only use memory less than 5000 KB.

=======================================================================================================
Sample 1
Input
1111111111
Output
55

Sample 2
Input
ffffffffff
Output
b4b4
*/

/*code*/
#include<stdio.h>

int cipher(int arr[], int total_num){
	int sum_e = 0;
    int sum_o = 0;

    for(int j=0; j<total_num; j++){
    	if(j%2 == 0){
        	sum_e += arr[j];
        }
        else{
        	sum_o += arr[j];
        }
    }
    
    int arr_sum_o[10000];
    int convert_arr_sum_o[10000];
    
    if(sum_o >= 16){ /// or >15
        int i = 0;
        while(sum_o){
            arr_sum_o[i] = sum_o % 16;
            i++;
            sum_o /= 16;
        }
        
        /// convert the array
        int k = 0;
        for(int j=(i-1); j >= 0; j--){ ///mind the condition
            convert_arr_sum_o[k] = arr_sum_o[j];
            k++;
        }

        cipher(convert_arr_sum_o, i);
    }
    else{
       printf("%x",sum_o);
    }


    int arr_sum_e[10000];
    int convert_arr_sum_e[10000];

    if(sum_e >= 16){
  		int i = 0;
        while(sum_e){
        	arr_sum_e[i] = sum_e % 16;
            i++;
            sum_e /= 16;
        }
    	int k = 0;
        for(int j=(i-1); j >= 0; j--){
            convert_arr_sum_e[k] = arr_sum_e[j];
            k++;
        }
        
        cipher(convert_arr_sum_e, i);
    }
    else{
        printf("%x",sum_e);
    }
    

}

int main () {
    int arr[10000];
    int c;
    int ch;
    int num;
    int i =0;
    
    ///if scanf %x, it could be overflow
    while((ch = getchar()) != '\n'){
        if('0' <= ch & ch <= '9'){
            num = ch - '0';
        }
        else if('a' <= ch & ch <= 'f'){
             num = ch - 'a' + 10;
        }
        else if('A' <= ch & ch <= 'F'){
             num = ch - 'A' + 10;
        }
        arr[i] = num;
        i++;
    }
   
    
    cipher(arr, i);
    
    return 0;
}
