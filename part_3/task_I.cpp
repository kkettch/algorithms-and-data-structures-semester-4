#include <iostream>
#include <list>
#include <unordered_set>
#include <algorithm>
#include <queue>
#include <limits.h>

using namespace std;

int main() {
    int operations = 0;

    int n; // всего машинок
    int k; // машинок на полу
    int p; // номера машинок, с которыми играет

    cin >> n;
    cin >> k;
    cin >> p;
    
    // считать input в массив order_of_cars 
    int order_of_cars[p];  
    for (int i = 0; i < p; i++) {
        cin >> order_of_cars[i];
    }

    // посчитать для каждой машинки на каком шаге она будет нужна
    list<int> cars_history[n];
    for (int i = 0; i < p; i++) {
        int element = --order_of_cars[i];
        cars_history[element].push_back(i);
    }

    unordered_set<int> cars_on_the_floor;                      // для определения какие машинки уже на полу
    priority_queue<pair<int, int>> next_time_of_necessity;  // для определения какая машинка понадобится раньше

    for (int i = 0; i < p; i++) {
        
        int element = order_of_cars[i];
        cars_history[element].pop_front(); 

        // проверяем, что если машинки нет на полу, то берем с полки и ставим на пол
        if (cars_on_the_floor.find(element) == cars_on_the_floor.end()) {
            // если еще есть место без замены, то ставим
            if (cars_on_the_floor.size() < k) {
                cars_on_the_floor.insert(element);
                operations++;
            // иначе меняем местами с машинкой, которая встретится позже всех
            } else {
                // удаляем машинку, которая встретится позже всех
                cars_on_the_floor.erase(next_time_of_necessity.top().second);
                // удаляем ее из списка так как она больше не на полу
                next_time_of_necessity.pop();
                // и ставим на пол другую машинку
                cars_on_the_floor.insert(element);
                operations++;
            }
        }

        // если эта машинка больше не понадобится, то она должна быть первой на полку в следующий раз
        if (cars_history[element].empty()) {
            next_time_of_necessity.push({INT_MAX, element});
        } 
        // иначе просто добавляем номер, когда она встретится в следующий раз
        else {
            next_time_of_necessity.push({cars_history[element].front(), element});
        }
    }

    cout << operations;
}
