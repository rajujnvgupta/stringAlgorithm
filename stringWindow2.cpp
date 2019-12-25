//TODO: program won't work when 1st character is part of minimum string window
//each character of patter should be exactly same number of times into str 
/* 
 * swerty adfgh azxq
 * qas
*/
#include<bits/stdc++.h>
#define int long long int
using namespace std;
const int inf = 1e9;
string pat;
string str;
string solve(){
	//if(pat.size() > str.size()){
		//return "No string";
	//}
	//int pat_size = pat.size();
	int ans = inf;
	//unordered_map<char, int>mp;
	//string ptrn="";
	//maintaining unique character of pattern
    //for(int i = 0; i < pat_size; i++){
		//if(mp.find(pat[i]) != mp.end()){
			//continue;
		//}else{
			//ptrn.push_back(pat[i]);
			//mp[pat[i]] = pat[i];
		//}
	//}
	
	int ptrn_size = pat.size();
	int str_size = str.size();
	//if(str_size < ptr_size){
		//return "No string";
	//}
	unordered_map<char, int>pat_freq;
	for(int i = 0; i < ptrn_size; i++){
		pat_freq[pat[i]]++;
	}
	unordered_map<char, char>match;
	for(int i = 0; i < ptrn_size; i++){
		match[pat[i]] = pat[i];
	}
	int low = 0;
	int is_found_all_char_ptrn = 0;
	//int len = 0;
	unordered_map<char, int>freq;
	int window_low = -1, window_hi = -1;
	int first_char_of_pattern = 0;
	//int string_size = str.size();
	
	//expanding window
	for(int i = 0; i < str_size; i++){
			if(match.find(str[i]) != match.end()){
				//len++;
				first_char_of_pattern = 1;
				if(freq[str[i]] < pat_freq[str[i]]){
					is_found_all_char_ptrn++;
					//low = i;
				}
				freq[str[i]]++;
			}else if(first_char_of_pattern == 0){
				//if(flag == 0){
					
					low++;
				//}else{
				//low++;
					//len++;
				//}
			}
			
			///shringking window
			if(freq[str[low]] > pat_freq[str[low]] && is_found_all_char_ptrn == ptrn_size){
				while((freq[str[low]] > pat_freq[str[low]]) || (match.find(str[low]) == match.end())){
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
	cout<<window_low<<' '<<window_hi<<'\n';
	if(window_low < 0 || window_hi < 0){
		return "No string";
	}
	string window = str.substr(window_low, window_hi-window_low+1);
	//cout<<window<<'\n';
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
