
//n is length of x and m is length of y
int LCS(string x,string y,int n,int m){
	int dp[n+1][m+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i==0||j==0)
			dp[i][j]=0;
			else{
				if(x[i-1]==y[j-1]){
					dp[i][j]=1+dp[i-1][j-1];
				}else{
					dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
				}
			}
		}
	}
	return dp[n][m];
}

int[] InsAndDel(string a,string b,int n,int m){
	int ans[2];
	int lcs=LCS(a,b,n,m);
	int insertions=m-lcs;
	int deletions=n-lcs;
	ans[0]=insertions;
	ans[1]=deletions;
	return ans;
}
