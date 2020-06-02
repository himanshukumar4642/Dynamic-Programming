

static int dp[1001][1001];
void LongestCommonSubsequence(string X,string Y,int n,int m){
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
}

string printLCS(string X,string Y,int n,int m){
	int i=n,j=m;
	string ans="";
	while(i>0 && j>0){
		if(X[i-1]==Y[j-1]){
			ans+=X[i-1];
			i--;
			j--;
		}else{
			if(dp[i-1][j]>dp[i][j-1])
				i--;
			else
				j--;
		}
	}
	return ans;
}

