cin>>n>>m;
for(int i=0;i<n;i++)cin>>a[i];
sort(a,a+n);
f[0][0][0]=1;
for(int i=0;i<n;i++)
    for(long long j=0;j<=i;j++)
    {
        int cur=(a[i]-(i?a[i-1]:0))*j;
        for(int k=0;k+cur<=m;k++)
            if(f[i][j][k])
            {
                f[i+1][j][k+cur]=(f[i+1][j][k+cur]+(j+1)*f[i][j][k])%mod;
                f[i+1][j+1][k+cur]=(f[i+1][j+1][k+cur]+f[i][j][k])%mod;
                if(j)f[i+1][j-1][k+cur]=(f[i+1][j-1][k+cur]+j*f[i][j][k])%mod;
            }
    }
long long ans=0;
for(int i=0;i<=m;i++)ans+=f[n][0][i];
cout<<ans%mod<<endl;
return 0;
