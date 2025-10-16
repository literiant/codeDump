#include <iostream>
using namespace std;
int main()
{
    double a, b, c, max;
    cout << "Please enter 3 numbers:" << endl;
    cin >> a >> b >> c;
    max = a;
    if (b > max)
        max = b;
    if (c > max)
        max = c;
    cout << "The max number is:" << max << endl;
    return 0;
}