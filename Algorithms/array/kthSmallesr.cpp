/*
Given an array arr[] and an integer K where K is smaller than size of array, 
the task is to find the Kth smallest element in the given array.
It is given that all array elements are distinct.
*/

#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int main(){
    int arr[] = {1, 2, 3, 7, 19, 12, 5};
    int N = sizeof(arr)/sizeof(int);

    int K = 2;
    set<int>  s(arr, arr+N);

    set<int>::iterator itr = s.begin();
    advance(itr, K-1);

    cout << *itr << endl;
    return 0;
}