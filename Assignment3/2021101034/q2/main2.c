#include <stdio.h>
typedef long long ll;

int foo(ll n){
    int count=0;
    while(!(n%2)){
        n/=2;
        count++;
    }
    return count;
}

ll fastpow(int n){
    // int pow=n,a=2;
    // ll ans=1;
    // while(pow){
    //     if(pow%2){
    //         pow--;
    //         ans*=a;
    //     }else{
    //         a*=a;
    //         pow/=2;
    //     }
    // }
    // return ans;
    return 1LL << n;
}

int main(){
    ll n;
    scanf("%lld",&n);
    int t;
    scanf("%d",&t);
    while(t--){
        ll room;
        scanf("%lld ",&room);
        char temp;
        scanf("%c", &temp);
        ll power=fastpow(foo(room));
        while(temp!='\n'){
            if(temp=='U'&&room!=(n+1)/2){
                if((((room/power)/2)%2)){
                    room-=power;
                }else{
                    room+=power;
                }
                power*=2;
            }
            if(temp=='L'&&!(room%2)){
                // int div=foo(room);
                // ll power=fastpow(div);
                room-=(power/2);
                //power2/=2;
                power/=2;
            }
            if(temp=='R'&&!(room%2)){
                // int div=foo(room);
                // ll power=fastpow(div);
                room+=(power/2);
                power/=2;
                //power2/=2;
            }
            if(scanf("%c", &temp)==EOF)
                break;
        }
        printf("%lld",room);
        printf("\n");
        // }while(temp!='\n');
        
    }
}