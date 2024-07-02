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
                    if(nei == target) return dis[target];
                    q.push(nei);
                }
            }
        }
        return 0;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord == endWord) return 0;

        int n = wordList.size();
        
        vector<vector<int> > adj(n+1);
        int target = -1;

        for(int i = 0; i<n; i++){
            if(oneCharDif(beginWord, wordList[i])){
                adj[n].push_back(i);
                adj[i].push_back(n);
            }
            if(wordList[i] == endWord) target = i;
        }

        if(target == -1) return 0;

        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                if(oneCharDif(wordList[i], wordList[j])){
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

    vector<string> v = {"hot","dot","dog","lot","log","cog"};

    cout << sol.ladderLength("hit", "cog", v);
}