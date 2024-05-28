#include <bits/stdc++.h>
using namespace std;



vector <int> adj[1000];
queue<int>q;

bool visited[1000];
int parent[1000];
int lev[1000];



void bfs(int source){

    if(!visited[source]){
        parent[source] = source;
        lev[source] = 0;

        q.push(source);

        while(!q.empty()){

            int fr = q.front();
            cout<<fr<<" ";

            q.pop();

            for(int i=0; i<adj[fr].size(); i++){

                int v = adj[fr][i];
                if(!visited[v]){
                    lev[v] = lev[fr] + 1;
                    parent[v] = fr;
                    visited[v] = true;
                    q.push(v);

                }
            }
        }
    }

}

int main(){

    int n,e;
    cout<<"Enter the number of nodes and edges"<<endl;
    cin>>n>>e;

    int a,b;
    cout<<"Adjacency ......."<<endl;
    for(int i = 0; i<e;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);

    }

    int start, destination;

    cout<<"Enter the start and destination"<<endl;

    cin>>start>>destination;


    bfs(start);

    cout<<"The level of the destination is"<<lev[destination]<<endl;

    int now = destination;
    cout<<now<<" ";

    while(now!=start){
        now = parent[now];
        cout<<now<<" ";
    }

    cout<<endl;

    return 0;



}
