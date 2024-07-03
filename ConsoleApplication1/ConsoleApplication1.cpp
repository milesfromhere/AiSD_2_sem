#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    int N;
    cin >> N;

    vector<int> prices(N);
    for (int i = 0; i < N; ++i) {
        // Генерируем случайные цены от 1 до 100
        prices[i] = rand() % 100 + 1;
    }

    // Сортируем цены по убыванию
    sort(prices.rbegin(), prices.rend());

    // Пробиваем товары на кассе
    vector<int> receipt;
    int total = 0;
    for (int i = 0; i < N; ++i) {
        if (i % 2 == 0) {
            total += prices[i]; // Добавляем цену товара к общей сумме
            receipt.push_back(prices[i]); // Добавляем товар в чек
        }
        else {
            receipt.push_back(prices[i]); // Добавляем товар в чек, но он бесплатный
        }
    }

    // Выводим порядок пробивания на кассе и общую сумму чека
    for (int i = 0; i < N; ++i) {
        cout << receipt[i] << " ";
    }
    cout << endl << total << " - максимальная сумма чека" << endl;

    return 0;
}