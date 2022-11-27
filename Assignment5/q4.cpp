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
        vector<int> mess(k);
        for (int i = 0; i < k; i++)
        {
            cin >> mess[i];
            mess[i]--;
        }
        vector<pair<int, ll>> adj[n];
        vector<bool> vst(n,false);
        for (int i = 0; i < m; i++)
        {
            int x, y, w;
            cin >> x >> y >> w;
            x--;
            y--;
            adj[x].push_back(make_pair(y, w));
            adj[y].push_back(make_pair(x, w));
        }
        vector<ll> d(n, LONG_LONG_MAX);
        priority_queue<pair<ll, int>,vector<pair<ll,int>>,greater<pair<ll,int>>> st;
        for (auto i : mess)
        {
            d[i] = 0;
            vst[i]=true;
            for (auto j : adj[i])
            {
                // st.insert();
                st.push(make_pair(j.second, j.first));
            }
        }
        // ll tot=k;
        while (!st.empty())
        {
            // auto top = *(st.begin());
            auto topelement=st.top();
            // st.erase(st.begin());
            st.pop();
            // if(!vst[top.second]) tot++; 
            vst[topelement.second]=true;
            if (d[topelement.second] > topelement.first)
            {
                d[topelement.second] = topelement.first;
                for (auto j : adj[topelement.second])
                {
                    if (!vst[j.first])
                    {
                        // st.insert(make_pair(top.first + j.second, j.first));
                        st.push(make_pair(topelement.first + j.second, j.first));
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