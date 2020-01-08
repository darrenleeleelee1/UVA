#include <iostream>
using namespace std;
int pow(int x);
int main(int argc, char const *argv[])
{
	string str;
	int ctr;
	long long int x;
	cin >> ctr;
	for(int counter = 0; counter < ctr; counter++){
		cin >> x;
		if((x - 1) % 3 == 0) cout << "NO" << endl;
		else cout << "YES" << endl;
	}	
	return 0;
}

