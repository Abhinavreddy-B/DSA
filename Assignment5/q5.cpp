#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// #define long long int long long
typedef long long ll;
typedef vector<long long int> vi;

bool cmp(pair<long long int, long long int> &a, pair<long long int, long long int> &b)
{
    return make_pair(a.second, a.first) < make_pair(b.second, b.first);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int t = 1;
    // cin>>t;
    while (t--)
    {
        long long int n;
        cin >> n;
        pair<long long int, long long int> inp[n];
        map<pair<long long int, long long int>, long long int> mp;
        vector<pair<long long int, long long int>> adj[n];
        for (long long int i = 0; i < n; i++)
        {
            cin >> inp[i].first >> inp[i].second;
            mp[inp[i]] = i;
        }
        sort(inp, inp + n);
        for (long long int i = 1; i < n; i++)
        {
            auto fst = inp[i];
            auto snd = inp[i - 1];
            long long int dist = abs(fst.first - snd.first);
            adj[mp[fst]].push_back(make_pair(dist, mp[snd]));
            adj[mp[snd]].push_back(make_pair(dist, mp[fst]));
        }
        sort(inp, inp + n, cmp);
        for (long long int i = 1; i < n; i++)
        {
            auto fst = inp[i];
            auto snd = inp[i - 1];
            long long int dist = abs(fst.second - snd.second);
            adj[mp[fst]].push_back(make_pair(dist, mp[snd]));
            adj[mp[snd]].push_back(make_pair(dist, mp[fst]));
        }
        vector<long long int> d(n, 1e18);
        d[0] = 0;
        set<pair<long long int, pair<long long int, long long int>>> st;
        for (auto i : adj[0])
        {
            st.insert(make_pair(i.first, make_pair(0, i.second)));
        }
        vector<bool> vst(n, false);
        vst[0] = true;
        set<long long int> done;
        while (done.size() < n)
        {
            auto top = *(st.begin());
            st.erase(st.begin());
            if (!vst[top.second.second])
            {
                d[top.second.second] = top.first;
                for (auto j : adj[top.second.second])
                {
                    st.insert(make_pair(j.first, make_pair(top.second.second, j.second)));
                }
            }
            done.insert(top.second.second);
            vst[top.second.second] = true;
        }

        ll ans = 0;
        for (long long int i = 0; i < n; i++)
        {
            ans += d[i];
        }
        cout << ans << '\n';
    }
}