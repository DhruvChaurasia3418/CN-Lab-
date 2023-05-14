#include <bits/stdc++.h>

using namespace std;

#define print(a)     for(auto x : a) cout << x << " "; cout << endl



vector<int> find_redPos(int r){
    vector<int> ans;

    //* Store all 2^i positions  till i < r
    int pow = 0;
    int num = 1;
    while(pow < r){
        ans.push_back(num);
        num = num * 2;
        pow++;
    }
    return ans;
}

vector<int> find_dataPos(int m, int r, vector<int>& r_pos){
    vector<int> ans;
    int num = 1;
    while(num <= m+r ){
        if(find(r_pos.begin(), r_pos.end(), num) != r_pos.end()){
            num++;
            continue;
        }

        ans.push_back(num);
        num++;
    }

    return ans;
}



vector<int> find_indices(vector<int>& d_pos, int i){
    vector<int> ans;

    for(auto d : d_pos ){
        if(  ( d &  (1 << (i-1) ) )  ){
            ans.push_back(d);
        }
    }
    return ans;
}


void encode(string dataword){

    int m = dataword.length();
    int r = 1;  //* no. of redundant bits

    while((m+r) > pow(2,r)){
        r++;
    }


    vector<char> encodedData(m+r, '0'); 
    vector<int> r_positions = find_redPos(r);
    vector<int> d_positions = find_dataPos(m, r, r_positions);


    int k = 0;
    for(auto i : d_positions ){
        encodedData[i-1] = dataword[k++] ;
    }


    //* Iterating every possible redundant bit
    //* for 1st redundant bit , for 2nd redundant bit .... 
    for(int i=1; i<=r; ++i){
        
        vector<int> req_data_indices = find_indices(d_positions, i);

        int value = 0;
        for(auto idx : req_data_indices ){
            value = (value ^ (encodedData[idx-1]-'0'));
        }

        int ith_r_pos = r_positions[i-1];
        encodedData[ith_r_pos - 1] = value + '0';

    }

    print(encodedData);

}



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("inputf.txt", "r", stdin);
    freopen("outputf.txt", "w", stdout);
    #endif




    string s;
    cin >> s;

    encode(s);




    return 0;
}

// 1010110


// 0 1 1 1 0 1 0 0 1 1 0 