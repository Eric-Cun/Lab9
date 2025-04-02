#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void DFS(vector<int>* G, bool* seen, int* f, int v, int& time){
  // populate f
  seen[v] = true;

  for(int u : G[v]){
    if(!seen[u]){
      DFS(G, seen, f, u, time);
    }
  }
  f[v] = time++;
}

void DFS2(vector<int>* G, bool* seen, vector<int>& scc, int v){
  seen[v] = true;
  scc.push_back(v);
  for(int u : G[v]){
    if(!seen[v]){
      DFS2(G, seen, scc, v);
    }
  }
  //
}

int main(){

  int V; // no. of vertices
  int E; // no. of edges
  cin>>V;
  cin>>E;

  vector<int>* G = new vector<int>[V];
  for(int i = 0; i < E; i++){
    int u,v;
    cin>>u>>v;
    G[u].push_back(v);
  }

  vector<int>* GT = new vector<int>[V];
  for(int i = 0; i < V; i++){
    for(int j = 0; j < G[i].size(); j++){
      int u = i;
      int v = G[i][j];
      GT[v].push_back(u);
    }
  }

  bool* seen = new bool[V];
  int* f = new int[V];
  int time = 0;
  for(int i = 0; i < V; i++){
    if(!seen[i]){
       DFS(G, seen, f, i, time);
    }
  }

  for(int i = 0; i < V; i++){
    seen[i] = false;
  }
  
  //              0  1  2  3  4
  // argsort f = [3, 9, 4, 2, 5]
  // sort:  [2, 3, 4, 5, 9]
  // asort: [3, 0, 2, 4, 1]
  // modify sorting, you can built-in function to do argsort

  vector<int> af(V);
  for(int i = 0; i < V; i++){
    af[i] = i;
  }
  sort(af.begin(), af.end(), [&f](int i, int j){
    return f[i] < f[j];
  });
  //af = argsort(f);
  int* res = new int[V];

  for(int i = 0; i < V; i++){
    int v = af[i];
    v = af[i];
    if(!seen[v]){
      vector<int> scc;
      DFS2(G, seen, scc, v);
      //sccid = min(scc);
      int sccid = scc[0];
      for(int u : scc){
        if(u < sccid){
          sccid = u;
        }
      }
      for(int u : scc){
         res[u] = sccid;
      }
    }
  }

  for(int i = 0; i < V; i++){
    cout<<res[i]<<endl;
  }

  return 0;
}