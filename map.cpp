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



    return 0;
}

