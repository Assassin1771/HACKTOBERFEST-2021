#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        long long n,sum=0;
        cin>>n;
        long long a[n],b[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        int min_a=a[0],min_b=b[0];
        for(int i=1;i<n;i++){
            if(a[i]<min_a){
                min_a=a[i];
            }
        }
        for(int i=1;i<n;i++){
            if(b[i]<min_b){
                min_b=b[i];
            }
        }
        vector<int> aka;
        vector<int> bka;
        for(int i=0;i<n;i++){
            aka.push_back(a[i] - min_a);
        }
        for(int i=0;i<n;i++){
            bka.push_back(b[i] - min_b);
        }
        for(int i=0;i<n;i++){
            sum+=max(aka[i],bka[i]);
        }
        cout<<sum<<endl;
    }
}