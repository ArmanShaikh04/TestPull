/*Kahn's = BFS + indegree

indegree 0 = "I'm free, no dependencies!"
indegree-- = "one less thing holding me back"
indegree 0 again = "now I'm free too!"*/

/*Bonus — Kahn's detects cycle too!
cpp// if cycle exists, some nodes never reach indegree 0
// so ans.size() < V

if (ans.size() != V) → cycle exists!
if (ans.size() == V) → no cycle, valid topo order*/

class Solution {
  public:
  vector<int> ans;
  queue<int>q;
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        int indegree[V]={0};
        for(auto it: edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            indegree[v]++;
            //adj[v].push_back(u);
            //topo sort works only on directed acyclic graph
        }
        
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);// that are not dependent on any 
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
            
            
            
        }return ans;
    }
};