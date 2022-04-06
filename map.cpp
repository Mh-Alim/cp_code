#include<iostream>
#include<map>

#define ll long long

using namespace std;



int main(){


    map<int,int> mp;
    mp.insert({1,5});
    mp.insert({12,5});
    mp.insert({14,5});
    mp.insert({18,5});

    // if(mp.find(12) == mp.end()) cout << "founded"
    cout << endl;
    for (auto x:mp){
        cout << x.first <<" " <<x.second << endl;
    }
    if(mp.find(18) == mp.end()) cout << "founded";
    else cout << "not"<<endl;

    // find function me agar mughe koi key nhi milti to mp.end() ke equal ho jaati hai hence vo true return krti hai

    /*
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    map<pair<int,int>,bool> map;

    map[{1,2}] = true;
    map[{3,4}] = false;

     for (auto x:map){
        cout << x.first.first <<" "<<x.first.second<< " " <<x.second << endl;
    }

    if(map.find({1,2}) == map.end()) cout << "founded pair" << endl;
    if(map.find({2,1}) == map.end()) cout << "not founded" << endl;
    */


    //default 0
    cout <<" checking start" << endl;
    cout << endl;
    map<long,long> mapcheck;

    for(int i=0;i<2;i++){
        mapcheck[i]++;
    }
    mapcheck[0]++;
    for(auto x:mapcheck){
        cout << x.first << " " << x.second<<endl;
    }



    return 0;
}

