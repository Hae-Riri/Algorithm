#include <iostream>
using namespace std;

int coin[6] = { 500, 100, 50, 10, 5, 1 };
int cnt = 0;

int main() {
    int price;
    cin >> price;
    int change = 1000 - price;

    for (int i = 0; i < coin.size(); i++) {
        cnt += change / coin[i];
        change %= coin[i];
    }

    cout << cnt << "\n";
    return 0;
}