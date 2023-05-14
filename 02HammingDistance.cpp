#include <bits/stdc++.h>

using namespace std;

#define print(a)     for(auto x : a) cout << x << " "; cout << endl




//- Asssumption : 
//* We are directly entering 8 bit binary string but in form of decimal of 8 bits


int HammingDistance(int a, int b){

    int ct = 0;
    while(a || b){

        int x1 = a%10;
        int x2 = b%10;

        if(x1 ^ x2 == 1) ct++;

        a = a / 10;
        b = b / 10;
    }
    return ct;
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("inputf.txt", "r", stdin);
    freopen("outputf.txt", "w", stdout);
    #endif


    int a, b;
    cin >> a >> b;

    cout << HammingDistance(a, b) << endl;




    return 0;
}

// 00001000
// 00010000