#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int x1, y1, x2, y2;
	double temp;
	while(cin >> x1 >> y1 >> x2 >> y2){
		if(x1 == 0 && y1 == 0){
			if(x2 == 0 && y2 == 0)
				break;
		}
		else if(x1 == x2 && y1 == y2){
			cout << "0" << endl;
			continue;
		}
		else if(x1 - x2 == 0){
			cout << "1" << endl;
			continue;
		}

		else if(y1 - y2 == 0){
			cout << "1" << endl;
			continue;
		}
		temp = double((x1 - x2)) / double((y1 - y2));
		if(y1 - y2 != 0){
			if(temp == 1){
				cout << "1" << endl;
				continue;
			}
			else if(temp == -1){
				cout << "1" << endl;
				continue;
			}
		}
		cout << "2" << endl;
	}
	return 0;
}