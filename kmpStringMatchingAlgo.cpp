#include <iostream>
#define MAX_N 10005

int reset[MAX_N];
using namespace std;

void KMPresetTable(string pat, int patSize){

    int i = 0, j = -1;
    reset[0] = -1;
    while(i < patSize){

        while(j >= 0 && pat[i] != pat[j]){
            j = reset[j];
        }
        i++;
        j++;
        reset[i] = j;
    }
}

void KMPsearch(string str, string pat){
    int i = 0, j = 0;
    KMPresetTable(pat, pat.size());

    while(i < str.size()){

        while(j >= 0 && str[i] != pat[j]){
            j = reset[j];
        }
        i++;
        j++;
        if(j == pat.size()){
            cout<<"pattern found at index "<<i-j<<endl;
            j = reset[j];
        }
    }
}

int main()
{
    string str, pat;
    cin>>str>>pat;

    for(int i = 0; i < pat.size(); i++){
        reset[i] = -1;
    }

    KMPsearch(str, pat);
    return 0;
}

