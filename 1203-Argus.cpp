#include<bits/stdc++.h>
using namespace std;
class item{
public :
	int id, period, time;
	item(int i, int p, int t){
		id = i;
		period = p;
		time = t;
	}
	void printItem(){
		printf("%d %d\n", id, period);
	}
	bool operator< (const item other) const{
		return (time > other.time) || (time == other.time && id > other.id);
	}
};
int main(int argc, char const *argv[])
{
	string temps;
	int T, i, p, t;
	priority_queue<item> pq;
	while(cin >> temps && temps != "#"){
		cin >> i >> p;
		t = p;
		pq.push(item(i, p, t));
	}
	cin >> T;
	while(T-- && !pq.empty()){
		item temp = pq.top(); pq.pop();
		cout << temp.id << endl;
		pq.push(item(temp.id, temp.period, temp.time + temp.period));
	}
	return 0;
}