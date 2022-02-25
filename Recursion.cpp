#include<iostream>
#define ll long long


using namespace std;

void fun(ll &count){
    cout<<count<<" ";
    count++;
    fun(count);
}


int main(){

    ll count =0;

    fun(count);



    return 0;
}

