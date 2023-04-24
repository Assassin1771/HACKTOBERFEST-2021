#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main()
{
	int t;
	cin>>t;
	
	while(t--){
		ll n,m,k;
		cin>>n>>m>>k;
		
		bool ans = false;
		
		if(m>(n*(n-1)/2)){
			
		}
		else if(k<=1){
		}
		else if(k==2){
			if(n==1 && m==0) ans = true;
		}
		else if(k==3){
			if(m==(n*(n-1))/2) 
				ans = true;
		}
		else{
			if(m>=(n-1))
				ans = true;
		}
		
		if(ans) cout<<"YES\n";
		else cout<<"NO\n";
	}
}
