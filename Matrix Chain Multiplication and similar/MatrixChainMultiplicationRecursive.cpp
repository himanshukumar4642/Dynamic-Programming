
/*
basic steps:
1.find i and j
2.find base condition
3.fond k loop scheme
4.find function for temp ans
*/

//initialise i and j in main() as i=1 and j=n-1 where n is the size of array arr[]
int solve(int arr[],int i,int j){
	//base condition
	if(i>=j)
	return 0;
	int mn_cost=INT_MAX;
	//k loop scheme
	for(int k=i;k<j;k++){
		int temp_ans=solve(arr,i,k)+solve(arr,k+1,j)+(arr[i]*arr[k]*arr[j]);
		mn_cost=min(mn_cost,temp_ans);
	}
	return mn_cost;
}
