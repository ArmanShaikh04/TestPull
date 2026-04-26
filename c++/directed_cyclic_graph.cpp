class Solution {
  public:
  
    bool solve(int vis[],vector<vector<int>>& adj, int src , int pathvis[]){
        
        vis[src]=1;
        pathvis[src]=1;
        for(auto it : adj[src]){
            
            if(!vis[it]){
                if(solve(vis,adj,it,pathvis)){
                vis[it]=1;
                pathvis[it]=1;
                return true;
                }
                
        /// if not has been visited and it sholud be visited on same path then retur true
            }else if(pathvis[it]){// back edge // visited but on curreent path
                return true;
            }
        }
        pathvis[src]=0;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>>& edges) {
        // Code here
        
        vector<vector<int>> adj(V);
        
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            
            adj[u].push_back(v);
            //adj[v].push_back(u);

        }
        int pathvis[V]={0};
        int vis[V]={0};
        for(int i=0;i<V;i++){
            
            if(!vis[i]){
                if(solve(vis,adj,i,pathvis)){
                    return true;
                }
            }
        }return false;
    }
};