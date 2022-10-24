#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

// QUESTION : Count the number of primes strictly less than the given number n.
class Solution {
public:
    // Approach 1 : Brute Force --> For every number till n, check if it has any factor in [2, root(n)]
    // Why check only till root(n) and not till n-1 ? Because any number bigger than root(n) can't be its factor

    // Approach 2 : Sieve of Eratosthenes
    // 0, 1 are not prime numbers
    // Starting from 2 upto root(n), any multiple of prime number is not a prime
    // After all non-prime numbers are marked, only prime numbers are left
    //
    // Implementation : Take a list with size (n + 1) --> Index represent number
    // Mark every index as false except 0 and 1
    // Now run a loop from 2 upto root(n) and if the index's value is true, mark all of its multiples < n as true
    // After the loop is completed, only the indices which represent prime number will be marked true, count them!
    //
    // Optimization : Instead of using array, use a bitset.
    int countPrimes(int n)
    {
        if (n <= 2)  return false;
        vector<bool> primes(n+1, true);
        primes[0] = primes[1] = false;
        int count = 0;

        for (int number = 2; number <= int(sqrt(n)); number++)
        {
            for (int multiple = number*2; multiple <= n; multiple += number)
            {
                primes[multiple] = false;
            }
        }
        for (int number = 2; number < n; number++)
        {
            count += primes[number] == true ? 1 : 0;
        }
        return count;
    }
};

int main()
{
    Solution sol;
    return 0;
}