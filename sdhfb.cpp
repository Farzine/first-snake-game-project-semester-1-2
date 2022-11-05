#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;

        cin>>n;
        int a[n];
        int sum = 0;
        int dum = 0;
        for( i=0;i<n;i++){
            cin>> a[i];
            if(a[i]>0) sum+=a[i];
            else dum+=a[i];
        }
        int res=0;
        res=abs(abs(sum)-(abs(dum)));
        cout<<res<<endl;

    }
    return 0;
}
