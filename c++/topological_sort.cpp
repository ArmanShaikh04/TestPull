/*
What is Topological Sort?
Linear ordering of nodes such that for every edge u→v,
u always comes BEFORE v in the ordering.

Only works on DAG (Directed Acyclic Graph)

DFS + Stack
   → do DFS, push node to stack AFTER visiting all neighbors
   → reverse of stack = topo order
*/
//neeed of topo sort 
/*3. TASK SCHEDULING
   Task 1 must finish before Task 3 starts
   Task 2 must finish before Task 3 starts

   What order to execute? → Topo Sort!

4. PACKAGE INSTALLATION
   install numpy → before → install pandas
   install pandas → before → install sklearn

   pip install order? → Topo Sort!*/
class Solution {
  public:
  
  vector<int> ans;
  stack<int>st;
    
    void solve(int node, vector<vector<int>> & adj, int vis[]){
        vis[node]=1;
        
        for(auto it: adj[node]){
            if(!vis[it]){
                solve(it,adj,vis);
            }
        }
        //when done put it in stack
        st.push(node);// we just stored the node whose dfs was completed thats all
    }
        
        
  
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        
        for(auto it: edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            //adj[v].push_back(u);
            //topo sort works only on directed acyclic graph
        }
        int vis[V]={0};
        for(int i=0;i<V;i++){
            if(!vis[i]){
                solve(i,adj,vis);
            }
        }
        
        while(!st.empty()){
            int top=st.top();
            st.pop();
            ans.push_back(top);
        }return ans;
    }
};