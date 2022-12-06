/** @brief methods to find prime factors of n
 * 05/12/2022
*/

#include<bits/stdc++.h>

using namespace std;

/** @brief Naive method to find prime factors of n
 * O(sqrt(n))
 * 
 * 1) Divide n by 2 until odd
 * 2) For i = 3 to sqrt(n); try dividing n by i; increment i by 2
 * 3) Print n if it is larger than 2 
*/
vector<int> naive_PF(int n)
{
    vector<int> result;
 
    // extract as many 2's as possible
    while (n % 2 == 0)
    {
        result.push_back(2);
        n = n / 2;
    }
 
    // n must be odd at this point
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            result.push_back(i);
            n = n / i;
        }
    }
 
    // If n is prime, it bypass previous 2 steps
    if (n > 2) result.push_back(n);

    return result;
}


/** @brief Using modified Sieve of Eratosthenes
 * O(log(n)) for composite numbers
 * O(n) for prime numbers
 * 
 * Repetitively remove all composite factors by dividing n by 2 
 * until no longer possible. Then go to 3, 4, 5, ... until n <= 1
*/
vector<int> sieve_PF(int n) {
    vector<int> result;
    int c = 2;

    while (c * c <= n) {
        if (n % c == 0) {
            result.push_back(c);
            n /= c;
        } else {
            c++;
        }
    }

    result.push_back(n);
    return result;
}

/** 
 * @brief Slight modification to count number of prime factors
*/
int count_PF(int n) {
    int count = 0;
    int factor = 2;

    while (factor * factor <= n) {
        if (n % factor == 0) {
            n /= factor;
            count++;
        } else {
            factor++;
        }
    }
    return count+1;
}

int main()
{
    int x;
    cin >> x;

    cout << count_PF(x) << endl;
}