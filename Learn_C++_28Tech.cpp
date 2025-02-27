#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);    
    cout.tie(nullptr);
    
    int d, r;
    cin >> d >> r;
    cout << "Chu vi HCN la : " << 2*(d+r) << endl;
    cout << "Dien tich HCN la : " << 1ll*d*r << endl;
    return 0;
}