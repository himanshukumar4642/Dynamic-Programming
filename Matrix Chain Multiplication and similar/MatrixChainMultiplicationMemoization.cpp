
//initialise i and j in main() as i=1 and j=n-1 where n is the size of array arr[]
int static dp[1001][1001];
//initialise dp table in main() with -1 
int solve(int arr[],int i,int j){
	//base condition
	if(i>=j)
	return 0;
	if(dp[i][j]!=-1)
	return dp[i][j];
	int mn_cost=INT_MAX;
	//k loop scheme
	for(int k=i;k<j;k++){
		int temp_ans=solve(arr,i,k)+solve(arr,k+1,j)+(arr[i]*arr[k]*arr[j]);
		mn_cost=min(mn_cost,temp_ans);
	}
	return dp[i][j]=mn_cost;
}
