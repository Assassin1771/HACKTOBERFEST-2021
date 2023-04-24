#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
ll gcd(ll a,ll b )
{
   if(b==0)
      return a;
   return gcd(b,a%b);
}
 
 
int main(){
   int t;
   cin>>t;
   while(t--)
   {
      ll a,b,c;
      cin>>a>>b>>c;
      if(a==1)
      {
         cout<<1<<endl; 
      }
      else if(c==1)
      {
         if(a>b)
            cout<<2<<endl;
         else if(b>a)
            cout<<1<<endl;
         else
            cout<<3<<endl;
      }
      else{
         ll d= abs(c-b)+c-1;
         if(a-1>d)
            cout<<2<<endl;
         else if(d>a-1)
            cout<<1<<endl;
         else
            cout<<3<<endl;
      }
   }
 
   return 0;
}
 