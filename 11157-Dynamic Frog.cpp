#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int T; cin >> T;
	int N, D, stone[110], MAX, preP;
	char type[110], garbage;
	bool preS, sink[110];
	int cnt = 1;
	while(T--){
		cin >> N >> D;
		for(int i = 1; i <= N; i++){
			cin >> type[i] >> garbage >> stone[i];
			sink[i] = false;
		}
		type[0] = type[N+1] = 'S';
		stone[0] = 0;
		stone[N+1] = D;
		sink[0] = sink[N+1] = false;
		preS = false;
		MAX = preP = 0;
		for (int i = 1; i < N+2; ++i)
		{
			if(type[i] == 'B'){
				if(MAX < stone[i] - preP) MAX = stone[i] - preP;
				preP = stone[i];
			}
			else if(type[i] == 'S' && !preS){
				if(MAX < stone[i] - preP) MAX = stone[i] - preP;
				preP = stone[i];
				preS = true;
				sink[i] = true;								
			}
			else if(type[i] == 'S' && preS){
				preS = false;
			}
		}
		preP =0;
		for (int i = 0; i < N+2; ++i)
		{
			if(!sink[i]){
				if(MAX < stone[i] - preP) MAX = stone[i] - preP;
				preP = stone[i];
			}

		}
		printf("Case %d: %d\n", cnt++, MAX);
		
	
	}
	return 0;
}