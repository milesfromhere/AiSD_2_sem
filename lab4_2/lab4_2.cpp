#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    int N;
    cout << "введите N" << endl;
    cin >> N;
    cout << "оценки" << endl;
    vector<int> scores(N);
    for (int i = 0; i < N; ++i) {
        scores[i] = rand() % 10 + 1;
    }

    sort(scores.begin(), scores.end());

    cout << "Отсортированные оценки: ";
    for (int i = 0; i < N; ++i) {
        cout << scores[i] << " ";
    }
    cout << endl;

    int prizeWinners = 0;
    for (int i = 0; i < N; ++i) {
        if (scores[i] >= 7) { 
            prizeWinners++;
        }
    }
    cout << "Количество победителей: " << prizeWinners << endl;

    return 0;
}
