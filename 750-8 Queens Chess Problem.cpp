#include <bits/stdc++.h>
using namespace std;
bool ok(double A, double B, double C, double D){
	if(B - D == 0) return false;
	if(A - C == 0) return false;
	if(abs((A - C) / (B - D)) == 1) return false;
	return true;
}
vector<string> ans;
vector<pair<int, int>> temp;
void eigth_queen(int cur_row, int cur_col){
	temp.push_back(make_pair(cur_row, cur_col));
	int pos[10];
	if(temp.size() == 8){
		for(auto v : temp){
			pos[v.second] = v.first;
		}
		string tmp = "";
		for(int i = 1; i <= 8; i++){
			string n = to_string(pos[i]);
			
			if(i != 8) tmp += n + " ";
			else tmp += n;
		}
		ans.push_back(tmp);
	}
	else{
		int i;
		int new_row = (cur_row + 1) % 8 > 0 ? (cur_row + 1) % 8 : 8;
		for(i = 1; i <= 8; i++){
			bool flag = true;
			for(auto v: temp){
				if(!ok(v.first, v.second, new_row, i)) flag = false; 
			}
			if(flag) eigth_queen(new_row, i);
		}	
		
	}
	
	temp.pop_back();

}
int main(int argc, char const *argv[])
{
	int T; cin >> T;
	int row, col;
	bool first = true;
	while(T--){
		cin >> row >> col;
		if(first) first = false;
		else printf("\n");
		temp.clear();
		ans.clear();
		eigth_queen(row, col);
		int sol = 1;
		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");
		sort(ans.begin(), ans.end());
		for(auto i : ans){			
			printf("%2d      ", sol++);
			cout << i << endl;
		}
	}
	return 0;
}