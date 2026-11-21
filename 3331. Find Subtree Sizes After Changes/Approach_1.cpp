class Solution {
public:
    vector<vector<int>> tree;
    vector<vector<int>> finalTree;
    vector<int> newParent;
    vector<int> ans;
    vector<int> charStack[26];
    string s;

    void dfsBuild(int u) {
        int c = s[u] - 'a';

        if (!charStack[c].empty()) {
            newParent[u] = charStack[c].back();
        }

        charStack[c].push_back(u);

        for (int v : tree[u]) {
            dfsBuild(v);
        }

        charStack[c].pop_back();
    }

    int dfsSize(int u) {
        int sz = 1;

        for (int v : finalTree[u]) {
            sz += dfsSize(v);
        }

        return ans[u] = sz;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string str) {
        int n = parent.size();
        s = str;

        tree.assign(n, {});
        finalTree.assign(n, {});
        newParent = parent;
        ans.assign(n, 0);

        for (int i = 1; i < n; i++) {
            tree[parent[i]].push_back(i);
        }

        dfsBuild(0);

        for (int i = 1; i < n; i++) {
            finalTree[newParent[i]].push_back(i);
        }

        dfsSize(0);

        return ans;
    }
};