#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// printing of sorted array

void printSort(vector<int> &v){
    for(int i=0;i<v.size();i++){
        cout << v[i] <<  " ";
    }
}

void swap(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}
void insertionSort(vector<int> &v){
    int n = v.size();
    for(int i=1;i<n;i++){
        int temp = v[i];
        int j = i-1;

        while(j>=0 && v[j]>temp){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = temp;
    }

    printSort(v);
}



int main(){
    vector<int> v = {8,7,10,2,5};

    insertionSort(v);
}