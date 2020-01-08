#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	while(cin >> n){
		if(n == 0) break;
		n += 1;
		int arr[n][2];
		for (int i = 0; i < n; ++i){
			cin >> arr[i][0] >> arr[i][1];
		}
		for (int i = 1; i < n; ++i){
			if(arr[i][0] - arr[0][0] == 0 || arr[i][1] - arr[0][1] == 0) cout << "divisa" << endl;
			else if(arr[i][0] - arr[0][0] > 0){
				if(arr[i][1] - arr[0][1] > 0) cout << "NE" << endl;
				else cout << "SE" << endl;
			}
			else{
				if(arr[i][1] - arr[0][1] > 0) cout << "NO" << endl;
				else cout << "SO" << endl;	
			}
		}
	}
	return 0;
}