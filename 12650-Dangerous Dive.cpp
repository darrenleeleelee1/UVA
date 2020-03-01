#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	int r;
	int temp;
	int counter = 0;
	while(cin >> n){
		cin >> r;
		bool survi[n + 1];
		for(int i = 1; i <= n; ++i) survi[i] = false;
		for(int i = 1; i <= r; ++i){
			cin >> temp;
			survi[temp] = true;
		}
		for(int i = 1; i <= n; ++i){
			if(!survi[i]) cout << i << " ";
			else counter++;
		}

		if(counter == n) cout << "*" << endl;
		else  cout << endl;
		counter = 0;

	}
	return 0;
}