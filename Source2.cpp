#include <bits/stdc++.h>
using namespace std;
long long res(long long a, long long b, long long c) {
    long long result = 0; 
    a %= c; 
    
    while (b > 0) {
        if (b & 1) {
            result = (result + a) % c;
        }
        a = (a * 2) % c;
        b >>= 1;
    }
    
    return result;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n; cin >> n;
	while(n--){
		long long a, b, c;
		cin >> a >> b >> c;
		cout << res(a, b, c) << endl;
	}
	
	return 0;
}