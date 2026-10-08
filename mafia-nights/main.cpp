#include <iostream>
#include <stack>
#include <vector>

long long int max2(long long int a, long long int i);

int main() {
    std::stack<long long int> stack;
    long long int n;

    if (!(std::cin >> n) || n < 0) return 1;
    if (n == 0) { std::cout << 0 << "\n"; return 0; }
    std::vector<long long> numbs(n);
    std::vector<long long> k(n);
    for (long long int i = 0; i < n; ++i) {
        if (!(std::cin >> numbs[i])) return 1;
        k[i] = 0;
    }
    for (long long int i = n - 1; i >= 0; --i) {
        long long int a = 0;
        long long int z = 0;
        long long int size = stack.size();
        while (size > 0) {
            size--;
            if (numbs[stack.top()] < numbs[i]) {
                a++;
                z = max2(z+1, k[stack.top()]);
                stack.pop();
            } else { break; }
        }

        stack.push(i);
        k[i] = z;

    }
    long long int max = k[0];


    for (int i = 1; i < n; i++)
        if (k[i] > max)
            max = k[i];

    std::cout << max << "\n";


    return 0;
}

long long int max2(long long int a, long long int b) {
    if (a > b) {
        return a;
    }
    return b;
}


