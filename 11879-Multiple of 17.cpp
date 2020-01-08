#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	string str;
	//char lastd[10] = {'0', '7', '4', '1', '8', '5', '2', '9', '6', '3'};
	int r, temp;
	while(getline(cin, str)){
		if(str == "0") break;
		r = (int(str[0]) - 48);
		for(int i = 1; i < str.length(); ++i){
			r = (r * 10 + (int(str[i]) - 48));
			r %= 17;			
		}
		if(r == 0) cout << "1" << endl;
		else cout << "0" << endl;
	}
	
	

	return 0;
}