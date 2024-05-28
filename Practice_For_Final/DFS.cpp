#include <bits/stdc++.h>

using namespace std;

bool visited[1000];
int lev[1000];
int parent[1000];
vector<int>adj[1000];
stack<int>s;



void dfs(int source){

    if(!visited[source]){
        lev[source] = 0;
        parent[source] = source;
        visited[source] = true;

        s.push(source);

        while(!s.empty()){
            int fr = s.top();
            cout<<fr<<" ";

            s.pop();

            for(int i = 0 ; i<adj[fr].size(); i++){
                int v = adj[fr][i];

                if(!visited[v]){
                    parent[v] = fr;
                    lev[v] = lev[fr] + 1;
                    visited[v] = true;

                    s.push(v);
                }

            }
        }
    }
}


int main(){

    int n, e;

    cout<<"Enter the number of node and edges"<<endl;

    cin>>n>>e;

    int a, b;

    for(int i = 0; i<e;i++){
        cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);


    }

    int source, destination;

    cout<<"Enter the source and destination"<<endl;

    cin>>source;
    cin>>destination;

    dfs(source);

    cout<<"The level of destination is "<<lev[destination]<<endl;

    int now = destination;

    cout<<now<<" ";

    while(now!=source){
        now = parent[now];
        cout<<now<<" ";
    }

    cout<<endl;


}

