#include<iostream>
#include "reverseArray.cpp"
using namespace std;

void printArray(int arr[], int len){
    for(int i=0; i<len; i++){
        cout << arr[i] << endl;
    }
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7};

    int len = sizeof(arr)/sizeof(int);
    reverseArray(arr, 0, len-1);

    printArray(arr, len);

    return 0;
}