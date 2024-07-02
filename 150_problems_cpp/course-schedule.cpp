#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(0); cin.tie(0);
    }

    bool topo(vector<vector<int> >& adj, int V, vector<int>& indegree){
        queue<int> q;
        
        for(int i = 0; i<V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int cur = q.front();
            q.pop();

            for(auto i: adj[cur]){
                indegree[i]--;

                if(indegree[i] == 0){
                    q.push(i);
                }
            }
        }
        for(int i = 0; i<V; i++){
            if(indegree[i] != 0){
                return false;
            }
        }
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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

    cout << sol.canFinish(5, prerequisites);
}