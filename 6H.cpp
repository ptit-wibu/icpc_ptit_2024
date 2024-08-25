/*
Cho dãy số A gồm N số nguyên không âm. Dãy số B gồm N phần tử được tạo từ dãy số A bằng cách như sau:

    Nếu A[i] = 0 thì B[i] = X,
    Ngược lại B[i] = A[i] với 1 EVXM2u0cQFSphYAAAAASUVORK5CYII= i EVXM2u0cQFSphYAAAAASUVORK5CYII= N

Dãy số B được gọi là đẹp nếu tất cả phần tử của B có giá trị lớn hơn 1 và ước số chung lớn nhất của hai phần tử liền kề B[i] và B[i + 1] bằng 1.

Hãy tìm số nguyên dương X nhỏ nhất có thể để dãy số B là dãy số đẹp.

Input: Dòng đầu tiên ghi N (2 ≤ N ≤ 106).

Dòng thứ hai chứa N phần tử của dãy số A (0 ≤ A[i] ≤ 2*107).

Output:  Ghi ra X. Hoặc nếu không thể tạo ra dãy số B đẹp thì ghi ra -1

Ví dụ:

Input
	5

20 0 15 0 30
	


Output


7
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 2 * 10000000 + 5; 
vector<int> min_prime(maxn, 0); 

void sieve(int n) {
    for (int i = 2; i * i <= n; ++i) {
        if (min_prime[i] == 0) { 
            for (int j = i * i; j <= n; j += i) {
                if (min_prime[j] == 0) {
                    min_prime[j] = i;
                }
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        if (min_prime[i] == 0) {
            min_prime[i] = i;
        }
    }
}
vector<int> factorize(int n) {
    vector<int> res;
    while (n != 1) {
        res.push_back(min_prime[n]);
        n /= min_prime[n];
    }
    return res;
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    sieve(maxn - 1); 
    int n;
    cin >> n;
    vector<long long> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    for (int i = 1; i < n; ++i) {
        if ((A[i] > 1 && A[i - 1] > 1 && __gcd(A[i], A[i - 1]) > 1)
            || (A[i] == 0 && A[i - 1] == 0)
            || A[i] == 1 || A[i - 1] == 1) {
            cout << -1;
            return 0;
        }
    }
    int check = 0;
    for(int i = 0; i < n; i ++){
        if(A[i] == 0) {
            check = 1;
            break;
        }
    }
    if(check == 0){
        cout << 1;
        return 0;
    }
    set<int> prime_factors;
    for (int i = 0; i < n; i++) {
        if (A[i] != 0 && ((i > 0 && A[i - 1] == 0) || (i < n - 1 && A[i + 1] == 0))) {
            vector<int> factors = factorize(A[i]);
            prime_factors.insert(factors.begin(), factors.end());
        }
    }
    for (int x = 2; x < maxn; x++) {
        if (min_prime[x] == x && prime_factors.find(x) == prime_factors.end()) { 
