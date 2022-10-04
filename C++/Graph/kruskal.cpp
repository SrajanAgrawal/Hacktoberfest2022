#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int, int>
#define pll pair<ll, ll>
#define vpll vector<pll>

vector<int> parent(1000),Rank(1000);
void makeset(int i)
{
    parent[i]=i;
    Rank[i]=0;
}
int findparent(int node)
{
    if(node==parent[node]) return node;
    return parent[node]=findparent(parent[node]);
}
void Union(int u,int v)
{
  u=findparent(u);
  v=findparent(v);
  if(Rank[u]<Rank[v])
  parent[u]=v;
  else if(Rank[u]>Rank[v])
  parent[v]=u;
  else
  {
      parent[v]=u;
      Rank[u]++;
  }
}

int main()
{
int n,m;
cin>>n>>m;
for(int i=1;i<=n;i++)
{
    makeset(i);
}
vector<vector<int>> edges;
for(int i=0;i<m;i++)
{
    int u,v,w;
    cin>>u>>v>>w;
    edges.pb({w,u,v});
}
sort(edges.begin(),edges.end());
vector<vector<int>> mst;
int cost=0;
for(auto it:edges)
{ int w=it[0];
  int u=it[1];
  int v=it[2];
   if(findparent(u)!=findparent(v))
   { cost+=w;
       Union(u,v);
       mst.pb({w,u,v});
   }
}
cout<<cost<<endl;

 for(auto it:mst )
 cout<<it[1]<<" "<<it[2]<<" "<<it[0]<<endl;
return 0;
}
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define float double
// class node
// {
// public:
//     node(){};
//     int u;
//     int v;
//     int wt;
//     node(int first, int second, int weight)
//     {
//         u = first;
//         v = second;
//         wt = weight;
//     }
// };
// class Heap
// {
// public:
//     node heap[1000];
//     int size = 0;
//     Heap(int n)
//     {
//         heap;
//         size = 0;
//     }
//     void min_heapify(int i)
//     {
//         int largest = i;
//         int lc = (2 * i) + 1;
//         int rc = (2 * i) + 2;
//         if (lc < size && heap[lc].wt < heap[largest].wt)
//             largest = lc;
//         if (rc < size && heap[rc].wt < heap[largest].wt)
//             largest = rc if (largest != i)
//             {
//                 swap(heap[i], heap[largest]);
//                 min_heapify(largest);
//             }
//     }
//     node top()
//     {
//         if (!size)
//             return {0, 0, 0};
//         else
//             return heap[0];
//     }
//     bool empty()
//     {
//         return size == 0;
//     }
//     void pop()
//     {
//         node lastElement = heap[size - 1];
//         heap[0] = lastElement;
//         size = size - 1;
//         min_heapify(0);
//     }
//     void push(node key)
//     {
//         size = size + 1;
//         heap[size - 1] = key;
//         min_heapify(size - 1);
//     }
// };
// int findPar(int u, vector<int> &parent)
// {
//     if (parent[u] == -1)
//         return u;
//     return parent[u] = findPar(parent[u], parent);
// }
// void unionn(int u, int v, vector<int> &parent, vector<int> &rank)
// {
//     u = findPar(u, parent);
//     v = findPar(v, parent);
//     if (rank[u] < rank[v])
//     {
//         parent[u] = v;
//     }
//     else if (rank[v] < rank[u])
//     {
//         parent[v] = u;
//     }
//     else
//     {
//         parent[v] = u;
//         rank[u]++;
//     }
// }
// void kruskalsMST(int N, int e)
// {
//     Heap pq(N);
//     int a, b, wt;
//     for (int i = 0; i < e; i++)
//     {
//         cin >> a >> b >> wt;
//         pq.push({a, b, wt});
//     }
//     vector<int> parent(N);
//     for (int i = 0; i < N; i++)
//         parent[i] = -1;
//     vector<int> rank(N, 0);
//     vector<node> MST;
//     while (!pq.empty())
//     {
//         auto it = pq.top();
//         pq.pop();
//         if (findPar(it.v, parent) != findPar(it.u, parent))
//         {
//             MST.push_back({it.u, it.v, it.wt});
//             unionn(it.u, it.v, parent, rank);
//         }
//     }
//     cout << "The Edges in the MST are : \n";
//     cout << endl;
//     for (auto it : MST)
//         cout << it.u << " ----- " << it.v << " weight : " << it.wt << endl;
// }
// int main()
// {
//     int v, e;
//     cout << "Enter The number of vertices in the graph : ";
//     cin >> v;
//     cout << "Enter The number of edges in the graph: ";
//     cin >> e;
//     kruskalsMST(v, e);
//     return 0;
// }