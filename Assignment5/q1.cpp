#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

void dfs(int color, int pos, int n, vector<pair<int, int>> adj[], vector<pair<bool, bool>> &vst, int dest, int parent)
{
    vst[pos].first = true;
    if (pos == dest)
    {
        vst[pos].second = true;
        return;
    }
    for (auto i : adj[pos])
    {
        if (color == i.second)
        {
            if (!vst[i.first].first)
            {
                dfs(color, i.first, n, adj, vst, dest, pos);
            }
            if (vst[i.first].second)
            {
                vst[pos].second = true;
                return;
            }
        }
    }
    return;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < m; i++)
    {
        int x, y, c;
        cin >> x >> y >> c;
        x--;
        y--;
        adj[x].push_back(make_pair(y, c));
        adj[y].push_back(make_pair(x, c));
    }
    int q;
    cin >> q;
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        int cnt = 0;
        set<int> clr;
        for (auto i : adj[u])
        {
            if (clr.find(i.second)==clr.end())
            {
                vector<pair<bool, bool>> vst(n, make_pair(false, false));
                dfs(i.second, i.first, n, adj, vst, v, u);
                cnt += (vst[i.first].second == true);
                clr.insert(i.second);
            }
        }
        cout << cnt << '\n';
    }
}