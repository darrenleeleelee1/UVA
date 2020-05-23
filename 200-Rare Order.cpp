#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
map<char, int> character;
char order[30];
int ID(char c)
{
	if(!character.count(c)){
		order[cnt] = c;
		character[c] = cnt++;
	}
	return character[c];
}
int main(int argc, char const *argv[])
{
	char input[30], pre[30] = {'\0'};
	char null[30] = {'\0'};
	vector<int> adj[30];
	int ref[30];
	memset(ref, 0, sizeof(ref));
	while(~scanf("%s", &input)){
		if(input[0] == '#'){
			for(int i = 0; i < cnt; i++){
				int s = 0;
				while(s < cnt && ref[s] != 0) {
					s++;
				}
				if(s == cnt) break;
				ref[s] = -1;
				printf("%c", order[s]);
				for(auto j : adj[s]){
					ref[j]--;
				}
			}
			printf("\n");
			for(int i = 0; i < cnt; i++) adj[i].clear();			
			character.clear();
			memset(ref, 0, sizeof(ref));
			strcpy(pre, null);
			cnt = 0;
			continue;
		}
		for(int i = 0; i < strlen(pre); i++){
			if(pre[i] == input[i]) continue;
			else{
				adj[ID(pre[i])].push_back(ID(input[i]));
				ref[ID(input[i])]++;
				break;
			}
		}
		strcpy(pre, input);
	}
	/*
	for(int i = 0; i < cnt; i++){
		for(auto j : adj[i]){
			printf("%d ", j);
		}
		printf("\n");
	}
	*/
	return 0;
}