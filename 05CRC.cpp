#include <bits/stdc++.h>

using namespace std;

#define print(a)     for(auto x : a) cout << x << " "; cout << endl




string string_xor(string a, string b){
    string ans = "";
    for(int i=0; i<a.size(); ++i){

        if(a[i] == b[i])    ans += "0";
        else    ans += "1";
    }
    return ans;
}




string crc(string dataword, string divisor){

    int k = divisor.size();
    int m = dataword.size();

    int n = m + k - 1;
    int r = n - m;  //* r = divisor length - 1


    string str = string_xor(dataword.substr(0, k), divisor);

    string zeros(k, '0');

    int i = k;
    while(i<n){
        str = str.substr(1, k-1);

        str += "0";

        if(str[0] == '0')   str = string_xor(str, zeros);
        else    str = string_xor(str, divisor);

        i++;
    }

    string remainder = str;
    if(remainder[0] == '0'){
        remainder = remainder.substr(1, k-1);
    }

    string codeword = dataword + remainder;
    return codeword;

}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("inputf.txt", "r", stdin);
    freopen("outputf.txt", "w", stdout);
    #endif



    string dataword, divisor;
    cin >> dataword >> divisor;

    cout << crc(dataword, divisor) << endl;


    return 0;
}

//* i/p
// 1001
// 1011

//* o/p
// 1001110
