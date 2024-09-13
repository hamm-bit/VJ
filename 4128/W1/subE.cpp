    #include<bits/stdc++.h>
    using namespace std;
    long long n,k,t=1,ans;
    string a,b;

    int main(){
        cin>>n>>k>>a>>b;
        for(int i=0;i<n;i++){
            t<<=1;
            t-=(a[i]=='b')+(b[i]=='a');
            if(t>k) {
                t=k+1,ans+=k;
            }
            else ans+=t;
        }
        cout<<ans;
    } 
