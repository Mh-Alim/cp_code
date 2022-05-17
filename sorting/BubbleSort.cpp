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
void bubbleSort(vector<int> &v){
    int n = v.size();
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(v[j]>v[j+1]){
                swap(v[j],v[j+1]);
            }
        }
    }

    printSort(v);
}



int main(){
    vector<int> v = {8,7,10,2,5};

    bubbleSort(v);
}