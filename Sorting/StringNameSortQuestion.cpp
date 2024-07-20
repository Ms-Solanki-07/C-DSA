/*
give an array of names of the fruits, you are supposed to sort it in lexicographical order using the selection sort
*/

#include<iostream>
#include<string.h>
using namespace std;

void selectionSort(char fruit[][60], int n){

for(int i=0; i<n-1; i++){

        // finding the min element
        int min = i;
        for(int j=i+1; j<n; j++){
            if(strcmp(fruit[min], fruit[j]) > 0){
                min = j;
            }
        }

        // place the  min element at the beginning
        if(i!=min){
            swap(fruit[i], fruit[min]);
        }
    }

    return;
}

int main (){
    char fruit[][60] = {"papaya", "lime", "watermelon", "apple", "mango", "kiwi"};
    int n = sizeof(fruit)/sizeof(fruit[0]);

    selectionSort(fruit, n);

    for(int i=0; i<n; i++){
        cout<<fruit[i]<<" ";
    }



    return 0;
}