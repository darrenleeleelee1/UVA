#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int N;
	string str;
	vector<int> high, low;
	while(cin >> N && N){
		cin.ignore();
		getline(cin, str);
		if(str == "too high"){
			high.push_back(N);
		}
		else if(str == "too low"){
			low.push_back(N);
		}
		else if(str == "right on"){
			bool honest = true;
			for(auto i : high) if(N >= i) honest = false;
			for(auto i : low) if(N <= i) honest = false;			
			if(honest) printf("Stan may be honest\n");
			else printf("Stan is dishonest\n");
			high.clear();
			low.clear();
		}
	}
	return 0;
}