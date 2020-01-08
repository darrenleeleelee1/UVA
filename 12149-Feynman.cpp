#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	while(cin >> n){
		if(n == 0) break;
		int counter = 0, ngrid = 1;
		for(ngrid = 1; ngrid <= n; ++ngrid){
			for (int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					if(j + ngrid > n || i + ngrid > n) continue;
					counter++;
				}
			}
		}
		cout << counter << endl;
	}
	return 0;
}