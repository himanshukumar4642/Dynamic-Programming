int LCS(string x,string y,int n,int m){
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0||j==0)
                    dp[i][j]=0;
                else{
                    if(x[i-1]==y[j-1])
                        dp[i][j]=1+dp[i-1][j-1];
                    else
                        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
    int LPS(string x,int n){
        string y=x;
        reverse(y.begin(),y.end());
        return LCS(x,y,n,y.length());
    }
    int minInsertions(string s) {
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        return s.length()-LPS(s,s.length());
    }
