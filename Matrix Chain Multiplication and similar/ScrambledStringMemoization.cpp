

unordered_map<string,bool> mp;
bool solve(string a,string b){
	if(a==b)
	return true;
	if(a.length()<=1)
	return false;
	int n=a.length();
	string key=a+" "+b;
	if(mp.find(key)!=mp.end())
	return mp[key];
	bool flag=false;
	for(int i=1;i<n;i++){
		if((solve(a.substr(0,i),b.substr(n-i,i))&&solve(a.substr(i,n-i),b.substr(0,n-i)))||(solve(a.substr(0,i),b.substr(0,i))&&solve(a.substr(i,n-i),b.substr(i,n-i)))){
			flag=true;
			break;
		}
	}
	return mp[key]=flag;
}
