
//initialise the dp matrix in main() with -1 value
static int dp[1001][1001];
//n is the length of string X and m is the length of string Y
int LongestCommonSubsequence(string X,string Y,int n,int m){
	if(n==0||m==0)
	return 0;
	if(dp[n][m]!=-1)
	return dp[n][m];
	
	if(X[n-1]==Y[m-1])
	return dp[n][m]=1+LongestCommonSubsequence(X,Y,n-1,m-1);
	else
	return dp[n][m]=max(LongestCommonSubsequence(X,Y,n,m-1),LongestCommonSubsequence(X,Y,n-1,m));
}
