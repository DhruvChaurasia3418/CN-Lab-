#include <bits/stdc++.h>

using namespace std;

#define print(a)     for(auto x : a) cout << x << " "; cout << endl
#define print2d(a)   for(auto x : a) { print(x); }
#define printmap(a)  for(auto x : a) cout << x.first << " " << x.second << " , " << " "; cout << endl
#define bug(...)     __f (#__VA_ARGS__, __VA_ARGS__)

template<typename Arg1>
void __f(const char* name, Arg1&& arg1) {
    cout << name << " : " << arg1 << endl;
}
template<typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}





string add(string s1, string s2){

    string s(s1.size(), '0' );
    int carry = 0;

    for(int i = s1.size()-1; i>=0; i--){
        int sumBit = int(s1[i]-'0') + int(s2[i]-'0') + carry;
        if(sumBit == 2){
            s[i] = '0';
            carry = 1;
        }
        else if(sumBit == 3){
            s[i] = '1';
            carry = 0;
        }
        else{
            s[i] = char(sumBit + '0');
            carry = 0;
        }
    }

    if(carry == 0) return s;

    string temp(s.size(), '0');
    temp.back() = '1';
    return add(s, temp);
}



void invertBits(string &s){
    for(int i=0; i<s.size(); ++i){
        if(s[i] == '1') s[i] = '0';
        else s[i] = '1';
    }
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("inputf.txt", "r", stdin);
    freopen("outputf.txt", "w", stdout);
    #endif



    int n;
    cin >> n;
    vector<string> arr;
    
    for(int i=0; i<n; ++i){
        string x;
        cin >> x;
        arr.push_back(x);
    }    


    string s = arr[0];
    for(int i=1; i<n; ++i){
        s = add(s, arr[i]);
    }

    invertBits(s);

    cout << s << endl;

    return 0;
}

// 5
// 7 11 12 0 6