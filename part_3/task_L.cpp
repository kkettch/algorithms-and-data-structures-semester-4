#include<iostream>
#include<deque>
#include<vector>

using namespace std;

int main() {

    int n; // общее количество чисел
    int k; // количество чисел в окне

    cin >> n >> k;

    int numbers[n];
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    deque<int> window;

    for (int i = 0; i < k; i++) {
        
        // если в начале очереди элемент меньше чем текущий, то снимаем элемент с начала очереди
        while (!window.empty() && numbers[i] < numbers[window.front()]) {
            window.pop_front();
        }
        // индекс в начало очереди
        window.push_front(i);
    }

    cout << numbers[window.back()];

    for (int i = k; i < n; i++) {

        // избавляемся от индексов, которые не могут быть в текущем окне
        while (!window.empty() && window.back() == i - k) {
            window.pop_back();
        }

        // добавляем следующий индекс
        while (!window.empty() && numbers[i] < numbers[window.front()]) {
            window.pop_front();
        }
        window.push_front(i);

        // в конце очереди получаем наименьший элемент
        cout << " " << numbers[window.back()];

    }
}
