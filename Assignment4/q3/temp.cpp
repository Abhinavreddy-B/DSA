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
    cin >> t;
    while (t--)
    {
        ll l, r;
        cin >> l >> r;
        if (r >= 2 * l)
        {
            
            cout << r - (r + 1) / 2 - (!(r%2))<< '\n';
            
        }
        else
        {
            cout << r % l << '\n';
        }
    }
}