#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int count;
    cin >> count;
    int farmer;
    for (int times = 0; times < count; times++)
    {
        cin >> farmer;
        double temp1, temp2, temp3;
        double sum = 0;
        for (int i = 0; i < farmer; i++)
        {
            
            cin >> temp1 >> temp2 >> temp3;
            sum += (temp1 / temp2 * temp3) * temp2;
        }
        cout << int(sum) << endl;
        
    }
       
    return 0;
}
