#include <bits/stdc++.h>

using namespace std;

#define print(a)     for(auto x : a) cout << x << " "; cout << endl





//- Assumption : We are working on even parity 
//-             i.e. total parity should be even in end

int parity(string& s){

    int ct = 0;
    for(int i=0; i<s.size(); ++i){
        if(s[i] == '1') ct++;
    }

    if(ct&1){
        cout << "Odd parity present" << endl;
        s += '1';
    }
    else{
        cout << "Even parity present" << endl;
        s += '0';
    }

    return ct;
}




int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("inputf.txt", "r", stdin);
    freopen("outputf.txt", "w", stdout);
    #endif



    string s;
    cin >> s;


    int ct = parity(s);


    cout << "Parity Bit is : " << (ct&1) << endl;
    cout << "Transmission Code : " << s << endl;



    return 0;
}

// 100110



// Odd parity present
// Parity Bit is : 1
// Transmission Code : 1001101