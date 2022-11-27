#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        int mess[k];
        for (int i = 0; i < k; i++)
        {
            cin >> mess[i];
            mess[i]--;
        }
        vector<pair<int, ll>> adj[n];
        bool vst[n];
        for(int i=0;i<n;i++){
            vst[i]=false;
        }
        for (int i = 0; i < m; i++)
        {
            int x, y, w;
            cin >> x >> y >> w;
            x--;
            y--;
            adj[x].push_back(make_pair(y, w));
            adj[y].push_back(make_pair(x, w));
        }
        ll d[n];
        for(int i=0;i<n;i++){
            d[i]=LONG_LONG_MAX;
        }
        set<pair<ll, int>> st;
        for (auto i : mess)
        {
            d[i] = 0;
            vst[i]=true;
            for (auto j : adj[i])
            {
                st.insert(make_pair(j.second, j.first));
            }
        }
        while (!st.empty())
        {
            auto top = *(st.begin());
            st.erase(st.begin());
            vst[top.second]=true;
            if (d[top.second] > top.first)
            {
                d[top.second] = top.first;
                for (auto j : adj[top.second])
                {
                    if (!vst[j.first])
                    {
                        st.insert(make_pair(top.first + j.second, j.first));
                    }
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << d[i] << ' ';
        }
        cout << '\n';
    }
}