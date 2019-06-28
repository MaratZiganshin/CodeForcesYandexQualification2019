#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<long long> t;
long long X;

bool mod_equal(long long a, long long b)
{
    return a % X == b % X;
}

bool mod_less(long long a, long long b)
{
    if (a % X == b % X)
        return a < b;
    return a % X < b % X;
}


long long sum(long long T)
{
    long long result = 0;
    for (long long i = 0; i < t.size(); i++)
    {
        long long number = (T - t[i]) / X;
        if (T >= t[i])
            number++;
        result += std::max(number, (long long)0);
    }
    return result;
}

long long binarysearch(long long low, long long high, long long K)
{
    long long mid;

    while ( low <= high )
    {
        mid = low + ((high - low) >> 1);

        long long _sum = sum(mid);
        if (_sum == K)
        {
            long long prev_sum = sum(mid - 1);
            if (prev_sum == _sum)
            {
                high = mid - 1;
                continue;
            }
            return mid;
        }
        else if (_sum > K)
        {
            high = mid - 1;
        }
        else if (_sum < K)
        {
            low = mid + 1;
        }
    }
    throw std::invalid_argument( "received negative value" );
}

int main() {
    long long N, K;
    cin >> N >> X >> K;

    for (long long i = 0; i < N; i++)
    {
        long long temp;
        cin >> temp;
        t.push_back(temp);
    }

    sort(t.begin(), t.end(), mod_less);

    t = std::vector<long long>(t.begin(), unique(t.begin(), t.end(), mod_equal));

    long long T;

    long long result = binarysearch(*std::min_element(t.begin(), t.end()),
                       *std::max_element(t.begin(), t.end()) + (K + 1) * X + 1, K);

    cout << result;
}