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
        int n;
        cin >> n;
        vector<pair<ll,ll>> ability(n);
        vector<pair<int,int>> links(n);
        for(auto &i : ability){
            cin>>i.first;
            i.second=0;
        } 

        for(int i=1;i<n;i++){
            cin>>links[i].first>>links[i].second;
        }

        for(int i=n-1;i>0;i--){
            if(links[i].second==0){
                ability[links[i].first].first = ability[links[i].first].first + ability[i].second;
                if(ability[i].second > ability[i].first){
                    ability[links[i].first].second+=ability[i].second;
                }else{
                    ability[links[i].first].second+=ability[i].first;
                }
            }else if(links[i].second == 1){
                // if(ability[i].first > ability[i].second){
                    // ability[links[i].first].first += ability[i].first;
                // }else{
                    // ability[links[i].first].first += ability[i].second;
                // }
                ll choose = max(ability[i].first + ability[links[i].first].first  ,ability[i].first + ability[links[i].first].second );
                ability[links[i].first].first = max(choose , ability[i].second + ability[links[i].first].first);
                ability[links[i].first].second += ability[i].second;
            }else if(links[i].second == 2){
                ability[links[i].first].first =  max(ability[i].second + ability[links[i].first].first , ability[i].first + ability[links[i].first].second );
                ability[links[i].first].second += ability[i].second;
            }
        }
        cout<<max(ability[0].first,ability[0].second)<<'\n';
    }
}