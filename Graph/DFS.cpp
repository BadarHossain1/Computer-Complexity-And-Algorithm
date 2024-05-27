#include<bits/stdc++.h>
#include<vector>
#define maxn 1000

using namespace std;

bool vis[maxn];
vector<int>adj[maxn];
stack<int>q;
int lev[maxn];

int par[maxn];

void Dfs(int node)
{
    
        lev[node]=0;
        par[node]=node;
        q.push(node); //The purpose is to push the node in the stack because we are using stack to traverse the graph and we are pushing the node in the stack to traverse the graph. 
        vis[node]=true;
        cout<<"\nThe required dfs traversal is"<<endl;
        //By printing fr variable after every change gives us the dfs traversal
        while(!q.empty())
        {
            int fr=q.top(); //here fr is the top element of the stack which we are popping and will use it to traverse the graph. For example if we have a graph 1->2->3->4->5 and we are at 1 then we will go to 2 and then 3 and so on. So we are using stack to traverse the graph.
            cout<<fr<<" ";
            q.pop(); //popping the top element of the stack
            for(int i=0; i<adj[fr].size(); ++i) //here adj[fr] is the adjacency list of the node fr. So we are traversing the adjacency list of the node fr.
            {
                int v= adj[fr][i];
                if(!vis[v])
                {
                    lev[v]=lev[fr]+1;
                    par[v]=fr;
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
    
    cout<<endl<<endl;
}
int main()
{
    int n,e,node;
    cin>>n>>e;
    for(int i=0; i<e; ++i)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int d;
    cout<<"Enter source and destination"<<" : ";
    cin>>node>>d;
    Dfs(node);
    cout<<"The level of "<<d<<" is "<<lev[d]<<endl;


    //The required dfs path to a destination node from parent node

    cout<<"\n\nThe path from source to destination is"<<endl;
    int now=d;
    cout<<now<<" ";
    while(now!=node){
        now=par[now];
        cout<<now<<" ";
    }
    cout<<endl;

    

 return 0;
}