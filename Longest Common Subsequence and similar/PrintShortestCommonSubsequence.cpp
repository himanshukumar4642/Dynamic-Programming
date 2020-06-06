

int dp[1001][1001];
void LongestCommonSubsequence(string x,string y,int n,int m){
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

string printSCS(string x,string y,int n,int m){
	LCS(x,y,n,m);
	int i=n,j=m;
	string ans="";
	while(i>0 && j>0){
		if(x[i-1]==y[j-1]){
			ans+=x[i-1];
			i--;j--;
		}else{
			if(dp[i-1][j]>dp[i][j-1]){
				ans+=x[i-1];
				i--;
			}else{
				ans+=y[j-1];
				j--;
			}
		}
	}
	while(i--){
		ans+=x[i];
	}
	while(j--){
		ans+=y[j];
	}
	reverse(ans.begin(),ans.end());
	return ans;
}

