#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <limits.h>
typedef long long ll;

#define MOD 1000000007LL

const ll p=31;


//struct to hold the Hash of substring starting from each character (index wise) of the given string
typedef struct mystruct{
    ll Hash;
    ll power;
}MyStruct;


//find inverse modulo MOD of a
ll inverse(ll a){
    ll pow=MOD;
    pow-=2;
    ll ans=1;
    while(pow!=0){
        if(pow%2==0){
            a=(a*a)%MOD;
            pow/=2;
        }else{
            ans=(ans*a)%MOD;
            pow--;
        }
    }
    return ans;
}


//struct to calculate and store the Hash of substring starting from each character (index wise) of the given string
MyStruct *getHash(char *S)
{
    // ll pow=1;
    // int p=32;
    ll hash = 1;
    ll len=strlen(S);
    MyStruct *Ans = (MyStruct *)malloc((len+1) * sizeof(MyStruct));

    //dummy value at the end
    Ans[len].Hash=0;
    Ans[len].power=1;
   // assert(Ans != NULL);
    for (int i = len-1; i>=0; i--)
    {
        Ans[i].Hash = (hash * (S[i] - 'a' + 1)) %MOD;
        if(i!=len-1){
            Ans[i].Hash=(Ans[i+1].Hash+Ans[i].Hash)%MOD;
        }
        Ans[i].power=hash%MOD;
        hash = (hash * p)%MOD;
        //hash = hash % MOD;
    }
    return Ans;
}

typedef struct data
{
    char _c;
    int left;
    int right;
    int parent;
    ll Hash;
    ll power;
} Data;

void TreeHash(Data* inp,int pos){
    if(inp[pos].left==-1&&inp[pos].right==-1){
        inp[pos].power=1;
        inp[pos].Hash=inp[pos]._c-'a'+1;
        //return;
    }
    else if(inp[pos].left==-1){
        TreeHash(inp,inp[pos].right);
        inp[pos].power=(inp[inp[pos].right].power * p)%MOD;
        inp[pos].Hash=(inp[inp[pos].right].Hash+(inp[pos].power*(inp[pos]._c-'a'+1))%MOD)%MOD;
    }else if(inp[pos].right==-1){
        TreeHash(inp,inp[pos].left);
        inp[pos].power=(inp[inp[pos].left].power * p)%MOD;
        inp[pos].Hash=(inp[inp[pos].left].Hash+(inp[pos].power*(inp[pos]._c-'a'+1))%MOD)%MOD;
    }else{
        TreeHash(inp,inp[pos].left);
        TreeHash(inp,inp[pos].right);
        inp[pos].power=(((((inp[inp[pos].right].power * p)%MOD)*inp[inp[pos].left].power)%MOD) * p)%MOD;
        inp[pos].Hash=(((inp[inp[pos].right].Hash+(inp[inp[pos].left].Hash * ((inp[inp[pos].right].power * p)%MOD))%MOD)%MOD) + ((inp[pos]._c-'a'+1)*inp[pos].power)%MOD)%MOD;
    }
    return;
}

/*void UpdateTree(int pos,char _c){

}*/

int main()
{
    int n;
    scanf("%d", &n);
    Data inp[n];
    scanf("\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%c", &inp[i]._c);
    }
    for (int i = 0; i < n; i++)
    {
        inp[i].parent = -1;
        inp[i].left = -1;
        inp[i].right = -1;
        inp[i].Hash=0;
        inp[i].power=0;
    }
    for (int i = 0; i < n - 1; i++)
    {
        int node, child, dir;
        scanf("%d%d%d", &node, &child, &dir);
        if (dir == 1)
        {
            inp[node - 1].left = child - 1;
            inp[child - 1].parent = node - 1;
        }
        else
        {
            inp[node - 1].right = child - 1;
            inp[child - 1].parent = node - 1;
        }
    }
    int root=0;
    for(int i=0;i<n;i++){
        if(inp[i].parent==-1){
            root=i;
            //break;
        }
    }
    TreeHash(inp,root);
    //scanf("\n");
    char S[1000100];
    scanf("%s",S);
    MyStruct* A=getHash(S);
    ll Q;
    scanf("%lld",&Q);
    while(Q--){
        int mode;
        scanf("%d",&mode);
        if(mode==1){
            int position;
            char _c;
            scanf("%d",&position);
            position--;
            scanf(" %c",&_c);
            ll increment=(((_c-inp[position]._c + MOD)%MOD)*inp[position].power)%MOD;
            inp[position]._c=_c;
            inp[position].Hash = (inp[position].Hash+((MOD + increment)%MOD))%MOD;
            while(inp[position].parent!=-1){
                if(inp[inp[position].parent].right==position){
                    inp[inp[position].parent].Hash=(inp[inp[position].parent].Hash + (increment+MOD)%MOD)%MOD;
                }else{
                    inp[inp[position].parent].Hash=((((inp[inp[inp[position].parent].right].power * p)%MOD)*((increment+MOD)%MOD))%MOD + inp[inp[position].parent].Hash)%MOD;
                    increment=(increment*((inp[inp[inp[position].parent].right].power * p)%MOD))%MOD;
                }
                position=inp[position].parent;
            }
        }else{
            int pos,left,right;
            scanf("%d%d%d",&left,&right,&pos);
            pos--;
            left--;
            right--;
            if(inp[pos].Hash==(((A[left].Hash - A[right+1].Hash + MOD)%MOD)*(inverse(A[right].power)%MOD))%MOD){
                printf("YES\n");
            }else{
                printf("NO\n");
            }
        }
    }
    //printf("\n");
}