#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int count, now, last;
	cin >> count;
	cout << "Lumberjacks:" << endl;
	for (int time = 0; time < count; ++time){
		cin >> last;
		bool big = true, small = true;
		for (int i = 0; i < 9; ++i){
			cin >> now;
			if(now > last) small = false;
			else if(now < last) big = false;
			last = now;			
		}
		if(big || small) cout << "Ordered" << endl;
		else cout << "Unordered" << endl;
	}
	return 0;
}