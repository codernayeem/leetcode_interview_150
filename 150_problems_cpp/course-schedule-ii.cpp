#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(0); cin.tie(0);
    }

    vector<int> topo(vector<vector<int> >& adj, int V, vector<int>& indegree){
        queue<int> q;
        vector<int> order;
        
        for(int i = 0; i<V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int cur = q.front();
            q.pop();
            order.push_back(cur);

            for(auto i: adj[cur]){
                indegree[i]--;

                if(indegree[i] == 0){
                    q.push(i);
                }
            }
        }
        for(int i = 0; i<V; i++){
            if(indegree[i] != 0){
                return {};
            }
        }
        return order;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int> > adj(numCourses);
        vector<int> indegree(numCourses);

        for (auto x: prerequisites){ 
            adj[x[1]].push_back(x[0]);
            indegree[x[0]]++;
        }
        
        return topo(adj, numCourses, indegree);
    }
};

int main(){
    Solution sol;

    vector<vector<int>> prerequisites = {{1,4},{2,4},{3,1},{3,2}};

    auto v = sol.findOrder(5, prerequisites);

    for(int j = 0; j<v.size(); j++){
        cout << v[j] << " ";
    }
}