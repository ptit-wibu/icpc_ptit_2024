/*Chỉ với các que diêm chúng ta cũng có thể tạo ra được những biểu thức số học. Trong bài toán này chúng ta sẽ quan tâm tới các biểu thức số học như sau:

- Một số được mô tả bằng đúng số lượng que diêm

- Phép cộng (+) được mô tả bằng 2 que diêm

- Phép nhân (x) cũng được mô tả bằng 2 que diêm

Chú ý rằng phép nhân có ưu tiên thực hiện hơn phép cộng.

Ví dụ: |||||||x||||| có kết quả là 35 hoặc ||||||x||||||+| có kết quả là 37

Yêu cầu: Cho số N, tìm biểu thức biểu diễn bằng que diêm sử dụng ít que diêm nhất mà kết quả bằng đúng N.

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 6000).

Mỗi test trên một dòng chứa một số nguyên dương N (N < 5001).

Output: 

Với mỗi test, hãy in ra số lượng que diêm dung ít nhất cần sử dụng.*/

//Solution

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf = 1e9;
vector<int> dp(5005, inf);
void sinh()
{
    dp[0] = 0;
    for (int i = 1; i <= 5000; i++) {
    	dp[i] = i;
        for (int j = 1; j * j <= i; j++) {
            if (i % j == 0) {
                dp[i] = min(dp[i], (dp[j] + dp[i / j] + 2));
            }
    }
}
    for(int i = 1; i<=5000;i++)
    {
    	for (int j = 0; j < i; j++) {
            dp[i] = min(dp[i], dp[j] + dp[i - j] + 2);
        }
	}
}
int32_t main() {
	sinh();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << dp[n] << endl;
    }
}
