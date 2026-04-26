// bipartite grapg isa graph that we can colour with only 2 colour such that no two adjacent can have same colour
/*
1> every linear graph will be bipartite
2>in a cyle if cycle is even then it is a bipartite
3> odd cycle means not bipartite

so simple if and two adjacent node have same colour then not a bipartite graph
*/

class Solution {
  public:
    bool bfs(int src,vector<vector<int>>& adj, vector<int>& colour ){
         queue<int> q;
    colour[src] = 0;              // ✅ start with 0 not 1
    q.push(src);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto it : adj[node]) {
            if (colour[it] == -1) {
                colour[it] = 1 - colour[node];  // ✅ flips 0↔1
                q.push(it);
            } else if (colour[it] == colour[node]) {
                return false;
            }
        }
    }
    return true;
        
        //return true;
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
                if(!bfs(i, adj, colour)){
                    return false;
                }
            }
        }
        return true;
    }
    

};