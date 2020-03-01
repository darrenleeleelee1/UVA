#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    double v, t;
    while(cin >> v >> t){
        double result = v * t / 2;
        cout << int(result * 4) << endl;
    }
}
