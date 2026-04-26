class Solution {
  public:
    
   bool solve(int  vis[], vector<vector<int>> & adj , int src){
            
            queue<pair<int,int>>q;
            q.push({src,-1});
            vis[src]=1;
            
            while(!q.empty()){
                int node=q.front().first;
                int parent=q.front().second;
                q.pop();
                
                for(auto it : adj[node]){
                    
                    if(!vis[it]){
                        vis[it]=1;
                        q.push({it,node});
                    }else if(parent!=it){// back edge visted from somewhere elese
                        return true;
                    }
                }
            }return false;
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for(auto it : edges){
            int u=it[0];
            int v=it[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);//remove for directed graph
        }
            int vis[V+1]={0};
            for(int i=0;i<V;i++){
                
                if(!vis[i]){
                    if(solve(vis, adj, i)){
                        return true;
                    }
                }
            }return false;
        
    }
};