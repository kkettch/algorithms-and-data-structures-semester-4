#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    //переменные
    int n;
    int k;
    vector<int> prices(n);
    int sum = 0;

    //считываем кол-во товаров (n) и номер бесплатного товара (k)
    cin >> n >> k;

    //считываем цены товаров
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    //сортируем цены по убыванию
    sort(prices.begin(), prices.end(), greater<int>());

    //считаем цену
    int num = 0;
    for (int i = 0; i < n; i++) {
        num++;
        if (num == k) {
            num = 0;
            continue;
        }
        sum += prices[i];
    }

    cout << sum;
}