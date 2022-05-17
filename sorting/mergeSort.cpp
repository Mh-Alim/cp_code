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

// this function will merge two sorted arrays

void merge(vector<int> &a,int l,int mid,int r){

    int i = l;
    int j = mid+1;
    int k = l;
    vector<int> b(r);

    while(i<= mid && j<=r){
        if(a[i]<a[j]){
            b[k] = a[i];
            i++;
        }
        else {
            b[k] = a[j];
            j++;
        }
        k++;
    }

    if(i>mid){
        while(j<=r) {
            b[k] = a[j];
            j++;
            k++;
        }
    }
    else{
        while(i<=mid) {
            b[k] = a[i];
            i++;
            k++;
        }
    }

    for(int z = l;z<=r;z++){
        a[k] = b[k];
    }



}

void mergeSort(vector<int> &,int l , int r){

    if(l >= r) return ;

    int mid = l + (r-l)/2;
    mergeSort(a,l,mid);
    mergeSort(a,mid+1,r);

    merge(a,l,mid,r);
}



int main(){
    vector<int> v = {8,7,10,2,5};

    mergeSort(v,0,v.size()-1);

    for(int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }
}