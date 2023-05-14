#include <bits/stdc++.h>

using namespace std;

#define print(a)     for(auto x : a) cout << x << " "; cout << endl






string encrypt(string s){

    for(int i=0; i<s.size(); ++i){
        int x = s[i]-'a';
        x = (x + 3) % 26;
        s[i] = x + 'a';
    }

    return s;
}


string decrypt(string s){
    
    for(int i=0; i<s.size(); ++i){
        int x = s[i]-'a';
        x = x-3;
        if(x >= 0){
            x = x%26;
        }
        else{
            x = (x+26) % 26;
        }
        s[i] = x + 'a';
    }

    return s;
}


//! Works for smaller case only , without any gap



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("inputf.txt", "r", stdin);
    freopen("outputf.txt", "w", stdout);
    #endif


    string s;
    cin >> s;

    cout << s << endl;
    auto e = encrypt(s);
    auto d = decrypt(e);

    cout << e << " , " <<  d << endl;



    return 0;
}

// scienceviva



// scienceviva
// vflhqfhylyd , scienceviva