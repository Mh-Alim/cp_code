#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void swap(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}
void selectionSort(vector<int> &v){

    for(int i=0;i<v.size();i++){
    int min_value = 1e5;
        for(int j=i;i<v.size();i++){
            min_value = min(min_value,v[j]);
        }
        swap(v[i],min_value);
    }

    for(int i =0;i<v.size();i++){
        cout << v[i] << " ";
    }
}

int main(){
    vector<int> v = {4,5,6,7,8};

    selectionSort(v);
}