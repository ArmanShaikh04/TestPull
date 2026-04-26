class Solution {
  public:
  
    bool solve(int vis[],vector<vector<int>>& adj, int src , int parent){
        
        vis[src]=1;
        
        for(auto it : adj[src]){
            
            if(!vis[it]){
                if(solve(vis,adj,it,src)){
                vis[it]=1;
                return true;
                }
            }else if(parent!=it){// back edge
                return true;
            }
        }return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        
        vector<vector<int>> adj(V);
        
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);

        }
        int vis[V]={0};
        for(int i=0;i<V;i++){
            
            if(!vis[i]){
                if(solve(vis,adj,i,-1)){
                    return true;
                }
            }
        }return false;
    }
};