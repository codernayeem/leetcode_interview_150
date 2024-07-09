#include <bits/stdc++.h>
using namespace std;

class RandomizedSet {
private:
    vector<int> v;
    unordered_map<int, int> m;
public:
    RandomizedSet() {
        ios_base::sync_with_stdio(0); cin.tie(0);
    }
    
    bool insert(int val) {
        if(m.find(val) == m.end()){
            v.push_back(val);
            m[val] = v.size() - 1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        auto idX = m.find(val);
        if(idX == m.end()){
            return false;
        }
        m[v.back()] = idX->second;
        v[idX->second] = v.back();
        v.pop_back();
        m.erase(val);
        return true;
    }
    
    int getRandom() {
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main(){
    RandomizedSet sol;

}