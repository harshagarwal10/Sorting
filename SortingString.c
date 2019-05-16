#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/**
*   Printing array
*/
void printRes(char *str) {
    int i;
    for(i=0; *(str+i) != '\0'; i++) {
        printf("%c", *(str+i));
    }
    printf("\n");
}

/**
*   Normal quick sort
*/
int partition(char *str, int low, int high) {
    int pivot = high;
    int i = low;
    int j = low;

    for(j=low; j<high; j++) {
        if(*(str+j) < *(str+pivot)) {
            char temp = *(str + i);
            *(str+i) = *(str+j);
            *(str+j) = temp;
            i += 1;
        }
    }
    char temp = *(str+i);
    *(str+i) = *(str+pivot);
    *(str+pivot) = temp;
    return i;
}

void quickSort(char *str, int low, int high) {
    if(low < high) {
        int p = partition(str, low, high);
        quickSort(str, low, p-1);
        quickSort(str, p+1, high);
    }
}

/**
*   Calls quick sort and make changes to the original array.
*/
void Sort(char *str1, char *str2, int s, int lim) {
    quickSort(str2, 0, lim-s);
    int i,j=0;
    for(i=s; i<=lim; i++) {     //starting from place after space and upto number of words
        *(str1 + i) = *(str2 + j);      //replacing original array with new sorted array
        j += 1;
    }
}

/**
*   Creates a seperate character array of words.
*   Then passes the word array  to sort it.
*/
void sortWord(char *str) {
    int i,s=0,j=0;
    char *str2 = (char *)malloc(sizeof(char)*50);       //character array of size 50
    if(str2 == NULL) {
        printf("Memory can't be allocated!\n");
        return;
    } else {
        for(i=0; *(str+i) != '\0'; i++) {
            if(*(str+i+1) == '\0') {
                *(str2+j) = *(str+i);
                Sort(str, str2, s, i);
            } else if(*(str+i) == ' ') {
                Sort(str, str2, s, i-1);
                memset(str2, '\0', 50);     //clearing memory
                s = i+1;
                j = 0;
            }
            if(*(str+i) != ' ') {
                *(str2+j) = *(str+i);      //Copying word to a new array
                j += 1;
            }
        }
        printf("Result:\t");
        printRes(str);
    }
}

/**
*   Sort whole string in alphabetical order.
*/
void sortString(char *str) {
    char *str1 = (char *)malloc(sizeof(char)*10000);
    if(str1 == NULL) {
        printf("Memory can't be allocated!\n");
        return;
    } else {
        int i, j=0;
        for(i=0; *(str+i) != '\0'; i++) {
            if(*(str+i) != ' ') {
                *(str1+j) = *(str+i);
                j += 1;
            }
        }
        quickSort(str1, 0, j-1);
        printf("Result:\t");
        printRes(str1);
    }
}

/**
*   Character wise sorting
*/
void sortChar(char *str) {

}

int main() {
    char t,str1[10000];
    printf("Enter string:\t");
    scanf("%[^\n]%*c", str1);
    printf("How to sort:\n");
    l1: printf("1. Sort word by word\n2. Sort whole string\n3. Sort characters in words\n");
        scanf("%d", &t);
        if(t == 1) {
            sortWord(str1);
        } else if(t == 2) {
            sortString(str1);
        } else if(t == 3) {
            sortChar(str1);
        } else {
            printf("Not a valid choice. Please choose again!\n");
            goto l1;
        }
        return 0;
}
