#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<set>
#define mod 100000009
#define INF 0x3f3f
#define ll long long int
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
using namespace std;

class Graph{
  int V;
  list<int> *adj;
  void DFSUtil(int v,bool visited[]);
public:
  Graph(int v);
  void addedge(int u,int v);
  void DFS();
};

Graph:: Graph(int v){
this->V=v;
adj=new list<int>[v];
}

void Graph:: addedge(int u,int v){
  adj[u].push_back(v);
}

void Graph:: DFSUtil(int v,bool visited[]){
    visited[v]=true;
    cout<<v<<endl;
    list<int>::iterator i;
    for(i=adj[v].begin();i!=adj[v].end();++i){
      if(!visited[*i]){
        DFSUtil(*i,visited);
      }
    }
}

void Graph:: DFS(){
  bool *visited=new bool[V];
  for(int i=0;i<V;i++){
    visited[i]=false;
  }
  for(int i=0;i<V;i++){
    if(visited[i]==false){
      DFSUtil(i,visited);
    }
  }
}

int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addedge(0, 1);
    g.addedge(0, 2);
    g.addedge(1, 2);
    g.addedge(2, 0);
    g.addedge(2, 3);
    g.addedge(3, 3);

    cout << "Following is Depth First Traversaln"<<endl;
    g.DFS();

    return 0;
}
