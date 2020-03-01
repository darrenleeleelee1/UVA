#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int count;
    cin >> count;
    int n, m;
    for (int times = 0; times < count; times++)
    {
        cin >> n >> m;
        for (int i = 0; i < m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                for (int k = 0; k < j; k++)
                {
                    cout << j;
                }
                cout << endl;
            }
            for (int j = n-1 ; j >= 1; j--)
            {
                for (int k = 0; k < j; k++)
                {
                    cout << j;
                }
                cout << endl;
            }
            if(times != count-1 || i != m-1) cout << endl;         
        }               
    }
    return 0;
}
