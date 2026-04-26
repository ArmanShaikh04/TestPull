class Solution {
  public:
    bool dfs(int src,vector<vector<int>> &adj, vector<int>& colour){
      for(auto it: adj[src]){
          if(colour[it]==-1){
               colour[it]=1-colour[src];// mark the colour
              if(!dfs(it,adj,colour)){
                  return false;// 
              }
          }
              else if(colour[it]==colour[src]){
                  return false;// two adjacent are same colour then not a bipartite 
          }
      }
        
        return true;
        
    }
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        
          vector<vector<int>>adj(V);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
      vector<int>colour (V,-1);
    
        for(int i=0;i<V;i++){
          
            if(colour[i]==-1){
                  colour[i]=0;// always set colour of the starting node
                if(!dfs(i, adj, colour)){
                    return false;
                }
            }
        }
        return true;
    }
};