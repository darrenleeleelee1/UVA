#include <iostream>
#include <sstream>
using namespace std;
void initialize(int n, int parent[], int rank[]){
	for (int i = 1; i <= n; ++i)
	{
		parent[i] = -1;
		rank[i] = 1;
	}
}
int findRoot(int x, int parent[]){
	int xRoot = x;
	while(parent[xRoot] != -1){
		xRoot = parent[xRoot];
	}
	return xRoot;
}
void unions(int x, int y, int parent[], int rank[]){
	int xRoot = findRoot(x, parent);
	int yRoot = findRoot(y, parent);
	if(xRoot != yRoot){
		if(rank[xRoot] > rank[yRoot]){
			parent[yRoot] = xRoot;
			rank[xRoot] += rank[yRoot];
		}
		else{
			parent[xRoot] = yRoot;
			rank[yRoot] += rank[xRoot];	
		}
	}
}
int main(int argc, char const *argv[])
{
	string str;
	stringstream sstr;
	int count, n, temp1, temp2;
	char command;
	cin >> count;
	cin.ignore();
	for(int times = 0; times < count; times++){
		cin >> n;
		int parent[n+1], rank[n+1], ctr1 = 0, ctr2 = 0;
		initialize(n, parent, rank);
		cin.ignore();
		while(getline(cin, str)){
			if(str == "") break;
			sstr << str;
			sstr >> command;
			sstr >> temp1; 
			sstr >> temp2;
			if(command == 'c'){
				unions(temp1, temp2, parent, rank);
			}
			else if(command == 'q'){
				temp1 = findRoot(temp1, parent);
				temp2 = findRoot(temp2, parent);
				//cout << temp1 << " " << temp2 << endl; 
				if(temp1 == temp2) ctr1++;
				else ctr2++;
			}
			sstr.clear();
			sstr.str("");
			//cout << command << " " << temp1 << " " << temp2 << endl;
		}
		if(times == count - 1) cout << ctr1 << "," << ctr2 << endl;
		else cout << ctr1 << "," << ctr2 << endl << endl;
	}	
	return 0;
}