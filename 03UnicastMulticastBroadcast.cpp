#include <bits/stdc++.h>

using namespace std;

#define print(a)     for(auto x : a) cout << x << " "; cout << endl




void hexToBinaryMAC(vector<string>& mac){
    int n = mac.size();

    for(int i=0; i<n; ++i){
        string s = "";
        for(int j=0; j<mac[i].size(); ++j){
            if(mac[i][j] >= '0' && mac[i][j] <= '9'){
                bitset<4> bits = int(mac[i][j] - '0');
                s += bits.to_string();
            }
            else{
                bitset<4> bits = int(mac[i][j] - 'A') + 10;
                s += bits.to_string();
            }
        }
        mac[i] = s;
    }
}



//- We always check LSB of first OCTET of Mac Address
//* LSB is right most bit

void casting(vector<string>& mac){
    int n = mac.size();

    if(mac[0].back() == '0'){
        cout << "Unicast Address" << endl;
        return;
    }

    bool broadcast = true;


    for(int i=0; i<n; ++i){
        for(int j=0; j<mac[i].size(); ++j){
            if(mac[i][j] == '0'){
                broadcast = false;
                break;
            }
        }
    }

    if(broadcast){
        cout << "Broadcast Address" << endl;
    }
    else{
        cout << "Multicast Address" << endl;
    }
}





int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("inputf.txt", "r", stdin);
    freopen("outputf.txt", "w", stdout);
    #endif


    int n = 6;
    vector<string> mac;
    
    for(int i=0; i<n; ++i){
        string x;
        cin >> x;
        mac.push_back(x);
    }


    print(mac);

    hexToBinaryMAC(mac);
    print(mac);

    casting(mac);



    return 0;
}

// FF FF FF FF FF FF
// 47 FF FF FF FF FF


// FF FF FF FF FF FF 
// 11111111 11111111 11111111 11111111 11111111 11111111 
// Broadcast Address

// 47 FF FF FF FF FF 
// 01000111 11111111 11111111 11111111 11111111 11111111 
// Multicast Address
