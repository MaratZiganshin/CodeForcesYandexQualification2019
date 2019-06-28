#include <iostream>
#include <vector>

using namespace std;

int main() {
    int K, N;
    cin >> K >> N;
    int p = 0;
    int v = 0;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        if (temp % 3 == 0 && temp % 5 == 0)
        {
            continue;
        }
        else if (temp % 3 == 0)
        {
            p++;
            if (p == K)
            {
                cout << "Petya";
                return 0;
            }
        }
        else if (temp % 5 == 0)
        {
            v++;
            if (v == K)
            {
                cout << "Vasya";
                return 0;
            }
        }
    }
    if (p > v)
        cout << "Petya";
    else if (p < v)
        cout << "Vasya";
    else
        cout << "Draw";
}