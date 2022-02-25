#include<iostream>
#include<vector>
#define ll long long
using namespace std;




int main(){


    //declare a 2-d vector

    vector<vector<ll>> vect
    {
        {1,2,3},
        {4,5,6,10,12},
        {7,8,9}
    };

    // printing value of vector
    // row = vect.size();
    // col = vect[i].size();
    for(int i=0;i<vect.size();i++){
        for(int j=0;j<vect[i].size();j++){
            cout<<vect[i][j]<<" ";
        }
        cout<<endl;
    }

    // printing element of 2-d vector with the help of iterator

    for(vector<ll> v : vect){
        for(ll a: v){
            cout<<a<<" ";
        }
        cout<<endl;
    }

    // declaring a vector element as 0;


    /*
    int row = 5;
    vector<ll> zeroVecter(row,0);
    for(int i=0;i<row;i++) cout<<zeroVecter[i]<<" ";

    */



    // Suppose we want to initialize a 2D vector of “n” rows and “m” columns, with a value 0.
    ll row = 4;
    ll col = 5;

    vector<vector<ll>> zeroTwoD_Vect(row,vector<ll> (col,0));

    for(int i=0;i<zeroTwoD_Vect.size();i++){
        for(int j=0;j<zeroTwoD_Vect[i].size();j++){
            cout<<zeroTwoD_Vect[i][j]<<" ";
        }
        cout<<endl;
    }



    return 0;
}

