
//length of X is n and length of Y is m
void LongestCommonSubsequence(string X,string Y,int n,int m){
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

int ShortestCommonSupersequence(string X,string Y,int n,int m){
	int lcs=LongestCommonSubsequence(X,Y,n,m);
	return (n+m-lcs);
}
