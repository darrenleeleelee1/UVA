#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	int ans[1000+10];
	bool exist[1000+10];
	vector<int> gue;
	int cnt = 1;
	while(cin >> n && n)
	{
		for(int i = 0; i < n; i++){
			cin >> ans[i];
		}
		printf("Game %d:\n", cnt++);
		while(true){
			int temp, a = 0, b = 0;
			gue.clear();
			for(int i = 0; i < n; i++){
				cin >> temp;
				exist[i] = false;
				if(ans[i] == temp) {
					a++;
					exist[i] = true;
				}
				else{ 
					gue.push_back(temp);
				}
			}
			if(temp == 0) break;
			for(auto i : gue){
				for(int j = 0; j < n; j++){
					if(i == ans[j] && !exist[j]){
						exist[j] = true;
						b++;
						break;
					}
				}
			}
			printf("    (%d,%d)\n", a, b);
		}
	}
	return 0;
}