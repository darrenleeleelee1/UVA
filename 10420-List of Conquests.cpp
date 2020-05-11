#include <bits/stdc++.h>
using namespace std;
map<string, int> cmap;
set<string> cset[2000+10];
int cnt = 0;
int ID(string contry)
{
	if(!cmap.count(contry)){
		cmap[contry] = cnt++;
	}
	return cmap[contry];	
};
int main(int argc, char const *argv[])
{
	string str, contry, name;
	set<string> cnset;
	int T; cin >> T;
	cin.ignore();
	while(T--)
	{
		getline(cin, str);
		contry = name = "";
		bool cb = true;
		for(int i = 0; i < str.length(); i++){
			if(str[i] == ' ') {
				cb = false;
				continue;
			}
			if(cb) contry += str[i];
			else name += str[i];
		}
		cnset.insert(contry);
		cset[ID(contry)].insert(name);
	}
	for(auto i : cnset){
		cout << i << " " << cset[ID(i)].size() << endl;
	}
}