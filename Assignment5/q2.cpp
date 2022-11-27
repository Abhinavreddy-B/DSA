#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

ll dfs(int pos, int n, vector<int> adj[], int dist, int parent)
{
    if (dist == 0)
    {
        return 1;
    }
    ll cnt = 0;
    for (auto i : adj[pos])
    {
        if (i != parent)
        {
            cnt += dfs(i, n, adj, dist - 1, pos);
        }
    }
    return cnt;
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        if (k == 0)
        {
            for (int i = 0; i < n - 1; i++)
            {
                ll x, y;
                cin >> x >> y;
            }
            cout<<n<<'\n';
            continue;
        }
        vector<int> adj[n+1];
        set<int> s;
        for (int i = 0; i < n - 1; i++)
        {
            ll x, y;
            cin >> x >> y;
            s.insert(x);
            s.insert(y);
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        ll cnt = 0;
        for (auto i: s)
        {
            cnt += dfs(i, n, adj, k, -1);
        }
        cout << cnt / 2 << '\n';
    }
}