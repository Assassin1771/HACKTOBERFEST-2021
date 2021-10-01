#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define PB push_back
#define double long double
#define ULL unsigned long long
#define PUI pair<ULL,int>
#define FI first
#define PII pair<int,int>
#define SE second
const double eps=1e-10,pi=acos(-1);
const int N=2e6+10,M=1e6+10,ha=131,INF=0x3f3f3f3f,mod=998244353;
int n,m;
int r[N];
int a[N];
void solve(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        r[i]=i;
        for(int j=i;j<=n;j++){
            if(a[j]<a[r[i]])r[i]=j;
        }
        if(r[i]!=i){
            ans++;
            int k=a[r[i]];
            for(int j=r[i];j>i;j--)a[j]=a[j-1];
            a[i]=k;
        }
    }
    printf("%d\n",ans);
    for(int i=1;i<=n;i++){
        if(r[i]!=i){
            printf("%d %d %d\n",i,r[i],r[i]-i);
        }
    }
}
int main()
{
 
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
 
    return 0;
}