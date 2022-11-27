#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

void helper(int pos, vector<int> adj[], vector<int> &parent, int n, int k, vector<vector<int>> &arr)
{
    if (adj[pos].size() == 1 && adj[pos][0]==parent[pos])
    {
        return;
    }
    for (auto i : adj[pos])
    {
        if (i != parent[pos])
        {
            parent[i] = pos;
            helper(i, adj, parent, n, k, arr);
        }
    }
    for (int j = 1; j < k + 1; j++)
    {
        ll sum = 0;
        for (auto i : adj[pos])
        {
            if (i != parent[pos])
            {
                sum += arr[i][j - 1];
            }
        }
        arr[pos][j] = sum;
    }
    return;
}

ll anshelper(int pos, vector<int> adj[], vector<int> &parent, int n, int k, vector<vector<int>> &arr)
{
    ll ans = arr[pos][k];
    int iter = pos;
    int temp = 1;
    while (parent[iter] != -1 && temp < k)
    {
        ans += arr[parent[iter]][k - temp] - arr[iter][k - temp - 1];
        iter = parent[iter];
        temp++;
    }
    if (parent[iter] != -1 && temp==k)
    {
        ans+=arr[parent[iter]][k - temp];
    }
    return ans;
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
                int x, y;
                cin >> x >> y;
            }
            cout<<n<<'\n';
            continue;
        }
        vector<int> adj[n];
        vector<int> parent(n, -1);
        for (int i = 0; i < n - 1; i++)
        {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<vector<int>> arr(n, vector<int>(k + 1, 0));
        for (int i = 0; i < n; i++)
        {
            arr[i][0] = 1;
            for(int j=1;j<k+1;j++){
                arr[i][j]=0;
            }
        }
        helper(0, adj, parent, n, k, arr);
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += anshelper(i, adj, parent, n, k, arr);
        }
        cout << ans / 2 << '\n';
    }
}