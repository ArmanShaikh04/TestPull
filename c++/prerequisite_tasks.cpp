class Solution {
  public:
  queue<int>q;
  vector<int>ans;
  /*can be done by topo sort is cycle dtected or by dfs + path visited detect a cycle */
    bool isPossible(int N, int P, vector<pair<int, int> >& edges) {
        // Code here
        int V=N;
        vector<vector<int>> adj(V);
        int indegree[V]={0};
        for(auto it: edges){
            int u=it.first;
            int v=it.second;
            adj[u].push_back(v);
            indegree[v]++;
            //adj[v].push_back(u);
            //topo sort works only on directed acyclic graph
        }
        
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node]){
                
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
            
            
            
        }
        if(ans.size()!=V){// indegree not zero for some node that means cycle is there 
            return false;
        }
        return true;
    }
};