#include<iostream>
#include<vector>
#include<queue>
#define MaxSize 1000

using namespace std;

bool visited[MaxSize];
vector<int>adjacent[MaxSize];
queue<int>q;
int lev[MaxSize];
int parent[MaxSize];

void bfs(int node)
{
    if(!visited[node])
    {
        lev[node]=0;
        parent[node]=node;
        q.push(node);
        visited[node]=true;
        cout<<"\nThe required bfs traversal is"<<endl;
        //By printing fr variable after every change gives us the bfs traversal
        while(!q.empty())
        {
            int fr=q.front();
            cout<<fr<<" ";
            q.pop();
            for(int i=0; i<adjacent[fr].size(); ++i)
            {
                int v = adjacent[fr][i];
                if(!visited[v])
                {
                    lev[v]=lev[fr]+1;
                    parent[v]=fr;
                    visited[v]=true;
                    q.push(v);
                }
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
        adjacent[a].push_back(b);
        adjacent[b].push_back(a);
    }
    int d;
    cin>>node>>d;
    bfs(node);
    cout<<"The level of "<<d<<" is "<<lev[d]<<endl;


    //The required bfs path to a destination node from parent node

    cout<<"\n\nThe path from source to destination is"<<endl;
    int now=d;
    cout<<now<<" ";
    while(now!=node){
        now=parent[now];
        cout<<now<<" ";
    }
    cout<<endl;

    

  return 0;
}