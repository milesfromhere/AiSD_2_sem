#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    int N;
    cout << "Введите N\n";
    cin >> N;

    vector<int> prices(N);
    for (int i = 0; i < N; ++i) {
        prices[i] = rand() % 100 + 1;
    }

    sort(prices.begin(), prices.end());

    cout << "Отсортированный массив цен: ";
    for (int i = 0; i < N; ++i) {
        cout << prices[i] << " ";
    }
    cout << endl;

    vector<int> receipt;
    int total = 0;
    int count = 0;
    for (int i = 0; i < N; ++i) {
        if (prices[i] % 2 == 0 && count < 5) {
            total += prices[i];
            receipt.push_back(prices[i]);
            count++;
        }
    }

    cout << "Первые 5 четных чисел: ";
    for (int i = 0; i < receipt.size(); ++i) {
        cout << receipt[i] << " ";
    }
    cout << endl << total << " - максимальная сумма чека" << endl;

    return 0;
}
