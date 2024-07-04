#include <bits/stdc++.h>
using namespace std;

bool oneCharDif(string &a, string &b){
    int n = a.size();
    int c = 0;

    for(int i = 0; i<n; i++){
        c += a[i] != b[i];
        if(c > 1) return false;
    }
    return true;
}

class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(0); cin.tie(0);
    }

    int bfs(vector<vector<int> > &adj, int V, int root, int target){
        vector<int> dis(V, 0);
        dis[root] = 1;

        queue<int> q;
        q.push(root);

        int cur;

        while(!q.empty()){
            cur = q.front();
            q.pop();

            for(auto nei: adj[cur]){
                if(!dis[nei]){
                    dis[nei] = dis[cur] + 1;
                    if(nei == target) return dis[target]-1;
                    q.push(nei);
                }
            }
        }
        return -1;
    }

    int minMutation(string startGene, string endGene, vector<string>& bank) {
        if(startGene == endGene) return 0;

        int n = bank.size();
        
        vector<vector<int> > adj(n+1);
        int target = -1;

        for(int i = 0; i<n; i++){
            if(oneCharDif(startGene, bank[i])){
                adj[n].push_back(i);
                adj[i].push_back(n);
            }
            if(bank[i] == endGene) target = i;
        }

        if(target == -1) return -1;

        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                if(oneCharDif(bank[i], bank[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        return bfs(adj, n+1, n, target);
    }
};

int main(){
    Solution sol;

    vector<string> v = {"AACCGGTA","AACCGCTA","AAACGGTA"};

    cout << sol.minMutation("AACCGGTT", "AAACGGTA", v);
}