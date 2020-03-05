#include <iostream>

using namespace std;

char a[105][105];
int ans = 0;

int main() {
    int r,c,k;
    cin >> r >> c >> k;

    for(int i=1;i<=r;i++) {
        for(int j=1;j<=c;j++) {
            cin >> a[i][j];
        }
    }

    for(int i=1;i<=r;i++) {
        int cnt = 0;
        for(int j=1;j<=c+1;j++) {
            if(a[i][j] == '.') cnt++;
            else {
                if(cnt-k+1 > 0) ans += cnt - k + 1;
                cnt = 0;
            }
        }
    }

    for(int i=1;i<=c;i++) {
        int cnt = 0;
        for(int j=1;j<=r+1;j++) {
            if(a[j][i] == '.') cnt++;
            else {
                if(cnt-k+1 > 0) ans += cnt - k + 1;
                cnt = 0;
            }
        }
    }
    if(k == 1)
        cout << ans / 2 << endl;
    else
        cout << ans << endl;
}