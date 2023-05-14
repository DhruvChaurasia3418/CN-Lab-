#include <bits/stdc++.h>

using namespace std;

#define print(a)     for(auto x : a) cout << x << " "; cout << endl








vector<string> decimalToBinaryIP(vector<int>& ip){
    int n = ip.size();

    vector<string> ans;

    for(int i=0; i<n; ++i){
        bitset<8> temp = ip[i];
        ans.push_back(temp.to_string());
    }
    return ans;
}


void IP_Evaluation(string octet, vector<string>& ip){
    int n = ip.size();


    string classIP = "";
    long long int totalIp = 0;
    int networks = 0;
    int hosts = 0;
    int CIDR = 0;


    if(octet[0] == '0'){
        classIP = "A";
        totalIp = pow(2,31);
        networks = pow(2,7) - 2;
        hosts = pow(2, 24)-2;
        CIDR = 8;
    }
    else if(octet[0] == '1' && octet[1] == '0'){
        classIP = "B";
        totalIp = pow(2,30);
        networks = pow(2,14) - 2;
        hosts = pow(2, 16)-2;
        CIDR = 16;

    }
    else if(octet[0] == '1' && octet[1] == '1' && octet[2] == '0'){
        classIP = "C";
        totalIp = pow(2,29);
        networks = pow(2,21) - 2;
        hosts = pow(2, 8) - 2;
        CIDR = 24;

    }
    else if(octet[0] == '1' && octet[1] == '1' && octet[2] == '1' && octet[3] == '0'){
        classIP = "D";
        totalIp = pow(2,28);
        cout << "CLass of IP address is : " << classIP << endl;
        cout << "Total Addresses is : " << totalIp << endl;
        return;

    }
    else if(octet[0] == '1' && octet[1] == '1' && octet[2] == '1' && octet[3] == '1'){
        classIP = "E";
        totalIp = pow(2,28);
        cout << "CLass of IP address is : " << classIP << endl;
        cout << "Total Addresses is : " << totalIp << endl;
        return;
    }


    cout << "CLass of IP address is : " << classIP << endl;

    cout << "Total Addresses is : " << totalIp << endl;
    cout << "Total Networks is : " << networks << endl;
    cout << "Total Hosts is : " << hosts << endl;


    string masks(32, '0');
    string revMask(32, '1');

    for(int i=0; i<CIDR; ++i){
        masks[i] = '1';
        revMask[i] = '0';
    }


    vector<string> firstAddress;

    vector<string> lastAddress;


    int k = 0;
    for(int i=0; i<n; ++i){
        string s = "";
        for(int j=0; j<8; ++j){
            int x =  (  ( int(ip[i][j]-'0') & int(masks[k++])-'0')  );
            s.push_back(char(x + '0'));
        }

        firstAddress.push_back(s);
    }

    k = 0;
    for(int i=0; i<n; ++i){
        string s = "";
        for(int j=0; j<8; ++j){
            int x =  (  ( int(ip[i][j]-'0') | int(revMask[k++])-'0')  );
            s.push_back(char(x + '0'));
        }
        lastAddress.push_back(s);
    }

    cout << "First Address is : ";
    print(firstAddress);

    cout << "Last Address is : ";
    print(lastAddress);

}





int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("inputf.txt", "r", stdin);
    freopen("outputf.txt", "w", stdout);
    #endif


    int n;
    n = 4;
    vector<int> ip;
    
    for(int i=0; i<n; ++i){
        int x;
        cin >> x;
        ip.push_back(x);
    }

    auto ip_binary = decimalToBinaryIP(ip);

    print(ip_binary);

    string first_octet = ip_binary[0];

    cout << first_octet << endl;

    IP_Evaluation(first_octet,  ip_binary );



    return 0;
}

// 192 0 0 8



// 11000000 00000000 00000000 00001000 
// 11000000
// CLass of IP address is : C
// Total Addresses is : 536870912
// Total Networks is : 2097150
// Total Hosts is : 254
// First Address is : 11000000 00000000 00000000 00000000 
// Last Address is : 11000000 00000000 00000000 11111111 
