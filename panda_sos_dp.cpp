#include <iostream>
using namespace std;
#include <bits/stdc++.h>

#define ll long long 

ll F[2000005][130];

int main() {
  //std::cout << "Hello World!\n";
  ll n,i,j;
  ll lim=1000000007;
  cin>>n;
  ll arr[n+1];
  for(i=0;i<n;i++)
  cin>>arr[i];
  ll cum[128];
  
  memset(cum,0,sizeof(cum));
  
  cum[0]=1;
  
  for(i=0;i<n;i++){
  ll tmp[128];
  memset(tmp,0,sizeof(tmp));
  
    for(j=0;j<128;j++){
      tmp[arr[i]^j]=cum[j];
    }
    
    for(j=0;j<128;j++){
      cum[j]+=tmp[j];
      cum[j]%=lim;
      cout<<tmp[j]<<" ";
    }
    cout<<endl;
  }
  
  ll ans=0;
  cum[0]--;
  for(j=0;j<128;j++){
ans+=(((cum[j]*(cum[j]-1))/2)%lim); 
ans%=lim; 
}
cout<<ans<<endl;
  
}
