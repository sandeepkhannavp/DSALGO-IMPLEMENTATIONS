 #include <bits/stdc++.h>
 using namespace std;
 #define N 10000
 vector <int> arr[N+1];
 int visit[N+1] , dist[N+1];
 void BFS(int src)
 {
   queue <int> q; 
   q.push(src);
   visit[src]=1;
   dist[src] = 0;
   while(!q.empty())
   {
     int curr = q.front();
     q.pop();
     for(int child : arr[curr])
     {
       if(visit[child]==0){
         q.push(child);
         dist[child] = dist[curr]+1;
         visit[child]=1;
       }
     }
   } 
 } 
 
 int main()
{
  int t , n , m ,a ,b;
  while (t--)
  {
    cin>>n>>m;
    for (int i = 1; i <= N; i++)
    {
      arr[i].clear() , visit[i]=0;
      while(m--) cin>>a>>b , arr[a].push_back(b) , arr[b].push_back(a);
      BFS(1);
      cout<<dist[n];
    }
    
  }
  //bfs(1,0);
}