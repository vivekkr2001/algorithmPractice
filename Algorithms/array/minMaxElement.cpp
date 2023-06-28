/*
FInd the minimum and maximum element of array.
*/

#include<iostream>

using namespace std;

struct minMaxElement
{
    int min;
    int max;
};

int main(){
    struct minMaxElement result;
    result.max = INT32_MIN;
    result.min = INT32_MAX;

    int arr[] = {1000, 11, 445, 1, 330, 3000};
    int len = sizeof(arr)/sizeof(int);

    for(int i=0; i<len; i++){
        if(arr[i] < result.min)
            result.min = arr[i];
        
        if(arr[i] > result.max)
            result.max = arr[i];
    }

    cout << "Min: " << result.min << " Max: " << result.max << endl;
}