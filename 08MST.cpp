// https://www.codingninjas.com/codestudio/problems/prim-s-mst_1095633
#include<bits/stdc++.h>
using namespace std;


#define print(a)       for(auto x : a) cout << x << " "; cout << endl


//? Spanning Tree 
//* Spanning tree is a acyclic undirected unweighted Graph M(V,V-1) created from G(V,E) ,
//* with V vertices and V-1 edges such that every node is reachable from every other node i.e. 1 component only 


//? PRIMS 

//* We require 3 data structure
//* cost array , MST array, Parent array
//- It is similar to dijikstra's algo with queue instead of cost vector


//- Note
//* cost[i] denotes cost that vertex i has with its parent
//* parent[i] denotes an edge between vertex i  and parent[i]
//* MST[i] denotes what vertex has been included in MST i.e. similar to visited[]

//* INitialise Cost array with INF, MST array with False, Parent array with -1



//? Prims algo
//- ALgo is similar to Dijikstra's algo , we used a loop to find min cost edge
//* 1) Cost[source] = 0 => cost of source with its parent = 0 (src is its own parent)
//* 2) Parent[source] = -1

//* 3) Pick min cost vertex v(index in vector) from Cost vector
//* that is unvisited or not included in MST

//- Either use For loop to find min cost edge from Cost array
//-                      OR
//- Use Data structures like Min Heap (implemented with priority Queue)

//* 4) Mark it as included in MST or visited

//* 5) Explore all its un-visited child


//- Exploring means 
//* Relax child and parent edge if possible 
//* (just like we relaxed src_dist in Dijikstra's algo)
//* If relaxed then mark it's parent






vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g){

    unordered_map<int,list<pair<int,int>> > G;
    for(int i=0; i<m; ++i){
        int x = g[i].first.first;
        int y = g[i].first.second;
        int wt = g[i].second;
        G[x].push_back({y,wt});
        G[y].push_back({x,wt});
    }

    vector<int> cost(n+1, INT32_MAX);
    vector<bool> MST(n+1, false);
    vector<int> parent(n+1, -1);

    //- MAX HEAP (decreasing sorted order store)
    //* priority_queue<T> maxHeap;
    //- MIN HEAP (increasing sorted order store )
    //* priority_queue<T , vector<T>, greater<T> > minHeap;


    //- Using Min Heap sorted by cost
    //* pq of {cost , v}, already sorted by min cost
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;


    int src = 1;
    cost[src] = 0;
    parent[src] = -1;

    pq.push({cost[src],src});

    while(!pq.empty()){
        auto vt = pq.top(); //! O(1)
        pq.pop(); //! O(logn)
        int v = vt.second;

        MST[v] = true;
        for(auto child : G[v]){
            int child_v = child.first;
            int child_wt = child.second;
            if( !MST[child_v] && child_wt < cost[child_v] ){
                cost[child_v] = child_wt;
                parent[child_v] = v;
                pq.push({cost[child_v],child_v}); //! O(logn)
            }
        }
    }

    vector<pair<pair<int, int>, int>> ans;
    for(int i=2; i<=n; ++i){
        ans.push_back({{parent[i],i}, cost[i]});
    }
    return ans;
}
//? Complexity
//- Time : O(V*logV + E*logV ) = O((V+E)*LogV) = O(N*logN)



void solve(){

    int n, m;
    cin >> n >> m;

    vector<pair<pair<int,int>, int>> g;

    for(int i=0; i<m; ++i){
        int x, y, wt;
        cin >> x >> y >> wt;
        g.push_back({{x,y}, wt});
    }

    auto ans = calculatePrimsMST(n,m,g);

    for(auto edge : ans){
        cout << edge.first.first << " " << edge.first.second << " " << edge.second << endl;
    }

}


int main(){
    
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("inputf.txt", "r", stdin);
    freopen("outputf.txt", "w", stdout);
    #endif
    
    
    solve();


    return 0;
    
}


// 4 5
// 1 2 5
// 1 3 8
// 2 3 10
// 2 4 15
// 3 4 20



// 1 2 5
// 1 3 8
// 2 4 15