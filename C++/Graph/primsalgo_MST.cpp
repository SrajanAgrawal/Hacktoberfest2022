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
#define vpi vector<pi>
#define vpll vector<pll>
#define sz(x) ((int)(x).size())
#define prec(n) fixed<<setprecision(n)
#define maxpq priority_queue<int>
#define minpq priority_queue<int, vector<int>, greater<int>>
#define  uniq(a) a.resize(unique(a.begin(), a.end()) - a.begin());

#define FAST ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
const  ll mod = 1e9 + 7;
const  ll  inf = 1e16;
const  ll N = 2e5 + 10;

int main()
{
FAST;
ll n,m;
cin>>n>>m;
vector<pair<int,int>> adj[n];
int a,b,wt;
for(int i=0;i<m;i++)
{
    cin>>a>>b>>wt;
    adj[a].pb({b,wt});
    adj[b].pb({a,wt});

}
ll parent[n],key[n];
vector<bool> mst(n);
for(int i=0;i<n;i++)  //O(N)
{
    parent[i]=-1;
    key[i]=inf;
    mst[i]=false;
}
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
key[0]=0;
pq.push({0,0});
// wt,ind
//O(N+E+NLOGN) ~O(NLOGN) space O(3N+N+E)
// use while(!pq.empty()) wrong ans coming from for(int i=0;i<n-1;i++)
// for(int i=0;i<n-1;i++) not use this 
while(!pq.empty()) 
 { ll mini=inf,ind;
   ind=pq.top().ss; //O(LOGN)
   pq.pop();
   mst[ind]=true;
   for(auto it:adj[ind]) //N+E 2 loops
   {
       int v=it.ff;
       int w=it.ss;
       if(mst[v]==false and w<key[v])
       {
        parent[v]=ind;
           key[v]=w;
        pq.push({key[v],v});

       }
   }

}
//O(N*N) brute force
// for(int i=0;i<n-1;i++) //iterate over n-1 edges
// { ll mini=inf,ind;

//  //finding min among all so we can replace it with set or priority_queue
//  //O(N*N)
//      for(int j=0;j<n;j++) // find min key value and not part of mst
//     {
//         if(mst[j]==false and key[j]<mini)
//         {
//           mini=key[j];
//           ind=j;
//         }
//     }
//     mst[ind]=true;
//     // now iterate over all edges which is min among all
//     for(auto it:adj[ind])
//     {   int v=it.ff;
//         int w=it.ss;
//         if(w<key[v] and mst[v]==false)
//         {
//             key[v]=w;
//             parent[v]=ind; // mark parents
//         }
//     }
// }
int cost=0;
for(int i=1;i<n;i++)
{ cost+=key[i];
    // cout<<parent[i]<<"-->"<<i<<" "<<"\n";
}
cout<<cost<<endl;
return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define float double
// vector<pair<int, int>> adj[100000];
// class Heap
// {
// public:
//     pair<int, int> *heap;
//     int size = 0;
//     Heap(int n)
//     {
//         heap = new pair<int, int>[n];
//         size = 0;
//     }
//     void min_heapify(int i)
//     {
//         int largest = i;
//         int lc = (2 * i) + 1;
//         int rc = (2 * i) + 2;
//         if (lc < size && heap[lc].second < heap[largest].second)
//             largest = lc;
//         if (rc < size && heap[rc].second < heap[largest].second)
//             largest = rc;
//         if (largest != i)
//         {
//             swap(heap[i], heap[largest]);
//             min_heapify(largest);
//         }
//     }
//     pair<int, int> top()

//     {
//         if (!size)
//             return {0, 0};
//         else
//             return heap[0];
//     }
//     bool empty()
//     {
//         return size == 0;
//     }
//     void pop()
//     {
//         pair<int, int> lastElement = heap[size - 1];
//         heap[0] = lastElement;
//         size = size - 1;
//         min_heapify(0);
//     }
//     void push(pair<int, int> key)
//     {
//         size = size + 1;
//         heap[size - 1] = key;
//         min_heapify(size - 1);
//     }
// };

// void primsMST(int N)
// {
//     int parent[N];
//     int key[N];
//     bool mstSet[N];
//     for (int i = 0; i < N; i++)
//         key[i] = INT_MAX, mstSet[i] = false;
//     Heap pq(N);
//     key[0] = 0;
//     parent[0] = -1;
//     pq.push({0, 0});
//     while (!pq.empty())
//     {
//         int u = pq.top().second;
//         pq.pop();
//         mstSet[u] = true;
//         for (auto it : adj[u])
//         {
//             int v = it.first;
//             int weight = it.second;
//             if (mstSet[v] == false && weight < key[v])
//             {
//                 parent[v] = u;
//                 key[v] = weight;
//                 pq.push({key[v], v});
//             }
//         }
//     }
//     cout << "The Edges in the MST are : \n";
//     cout << endl;
//     for (int i = 1; i < N; i++)
//         cout << parent[i] << " ------ " << i << " weight : " << key[i]
//              << " \n";
// }
// signed main()
// {
//     int v, e;
//     int a, b, wt;
//     // cout << "Enter The number of vertices in the graph : ";
//     cin >> v;
//     // cout << "Enter The number of edges in the graph : ";
//     cin >> e;
//     for (int i = 0; i < e; i++)
//     {
//         cin >> a >> b >> wt;
//         adj[a].push_back(make_pair(b, wt));
//         adj[b].push_back(make_pair(a, wt));
//     }
//     primsMST(v);
//     return 0;
// }
