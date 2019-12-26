/*
	@rajujnvgupta
	26/dec/2019
//each character of patter should be at least once into window of str

#include<bits/stdc++.h>
#define int long long int
using namespace std;
const int inf = 1e18+2;
string pat;
string str;
string solve(){

	int pat_size = pat.size();
	int ans = inf;
	unordered_map<char, int>mp;
	string ptrn="";
	//maintaining unique character of pattern
    for(int i = 0; i < pat_size; i++){
		if(mp.find(pat[i]) != mp.end()){
			continue;
		}else{
			ptrn.push_back(pat[i]);
			mp[pat[i]] = pat[i];
		}
	}
	
	int ptrn_size = ptrn.size();
	int str_size = str.size();
	
	unordered_map<char, char>match;
	for(int i = 0; i < ptrn_size; i++){
		match[ptrn[i]] = ptrn[i];
	}
	
	int low = 0;
	int is_found_all_char_ptrn= 0;
	unordered_map<char, int>freq;
	int window_low = -1, window_hi = -1;
	//expanding window
	for(int i = 0; i < str_size; i++){
			if(match.find(str[i]) != match.end()){
				if(freq[str[i]] < 1){
					is_found_all_char_ptrn++;
					//low = i;
				}
				freq[str[i]]++;
			}
			//else if(first_char_of_pattern == 0){
					//low++;
			//}
			
			///shringking window
			if(is_found_all_char_ptrn == ptrn_size){ //freq[str[low]] > 1 && 
				while(freq[str[low]] > 1 || match.find(str[low]) == match.end()){
					//len--;
					if(match.find(str[low]) != match.end()){
						freq[str[low]]--;
					}
					low++;
				}
				//ans = min(ans, i-low+1);
				int len = i - low + 1;
				if(len < ans){
					window_low = low;
					window_hi = i;
					ans = len;
				}
		}
	}
	//case when no window is found
	if(window_low < 0 || window_hi < 0){
		return "No string";
	}
	string window = str.substr(window_low, window_hi-window_low+1);
	return window;
}
int32_t main(){
	getline(cin, str);
	getline(cin, pat);
	//cin>>pat>>str;
	string ans = solve();
	cout<<ans<<'\n';
	return 0;
}
