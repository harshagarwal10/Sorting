#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdio.h>
 
void quickSort(char word[], int length);
int sortIt(char word[], int left, int right);
 
int main(){
 
    char str[] = "banana people cars peanut yellow";
    int length = strlen(str);
 
    quickSort(str, length);
 
    for(int i=0; i<length; i++){
        printf("%s ", str[i]);
    }
 
    return 0;
}
 
void quickSort(char word[], int length){
    sortIt(word, 0, length-1);
}
 
 
int sortIt(char word[], int left, int right){
 
    char *mid = word[(left+right)/2]; //point to the middle
    char temp[right+1];
    int i= left;
    int j = right;
 
    while(i <= j){
 
        //word[i] is less than mid and i<right
        while((strcmp(word[i], mid) < 0) && (i < right)){
            i++;
        }
 
        //word[i] is greater than mid and j>left
        while((strcmp(word[j],mid) > 0) && (j > left)){
            j--;
        }
 
        //swap
        if(i <= j){
            strcpy(temp, word[i]);
            strcpy(word[i], word[j]);
            strcpy(word[j], temp);
            i++;
            j--;
        }
    }
 
    if(left<j){
        sortIt(word,left,j);
    }
    if(i<right){
        sortIt(word, i,right);
    }
}