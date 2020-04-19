#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	string temp;
	bool first = true;
	int flag, numbers;
	int res = 0;
	while(cin >> temp && temp != "~"){
		if(temp == "#") {
			printf("%d\n", res);
			res = 0;
			continue;
		}
		if(temp.length() <= 2){
			flag = temp.length();
		}
		else{
			numbers = temp.length() - 2;
			if(flag == 1){
				while(numbers--){
					res = res << 1;
					res += 1;
				}
			}
			else{
				res = res << numbers;
			}
		}

	}
	return 0;
}