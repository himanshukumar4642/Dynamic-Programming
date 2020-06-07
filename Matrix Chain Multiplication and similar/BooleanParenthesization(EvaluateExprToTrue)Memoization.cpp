unordered_map<string,int> m;

int solve(string s,int i,int j,bool isTrue){
	//base condition
	if(i>j)
	return true;
	if(i==j){
		if(isTrue)
		return s[i]=='T';
		else
		return s[i]=='F';
	}
	string temp=to_string(i)+" "+to_string(j)+" "+to_string(isTrue);
	if(m.find(temp)!=m.end())
	return m[temp];
	int ans=0;
	for(int k=i+1;k<j;k+=2){
		int lt=solve(s,i,k-1,true);
		int lf=solve(s,i,k-1,false);
		int rt=solve(s,k+1,j,true);
		int rf=solve(s,k+1,j,false);
		if(s[k]=='&'){
			if(isTrue){
				ans+=(lt*rt);
			}else{
				ans+=(lf*rf)+(lt*rf)+(lf*rt);
			}
		}else if(s[k]=='|'){
			if(isTrue){
				ans+=(lt*rt)+(lt*rf)+(lf*rt);
			}else{
				ans+=(lf*rf);
			}
		}
		else if(s[k]=='^'){
			if(isTrue){
				ans+=(lf*rt)+(lt*rf);
			}else{
				ans+=(lt*rt)+(lf*rf);
			}
		}
	}
	return m[temp]=ans;
}

