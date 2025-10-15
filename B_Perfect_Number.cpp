#include <bits/stdc++.h>
using namespace std;

long long digitSum(long long x) {
    long long s = 0;
    while (x) {
        s += x % 10;
        x /= 10;
    }
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long k;
    if (!(cin >> k)) return 0;

    long long count = 0;
    long long num = 19;
    while (true) {
        if (digitSum(num) == 10) {
            ++count;
            if (count == k) {
                cout << num;
                break;
            }
        }
        ++num;
    }
    return 0;
}