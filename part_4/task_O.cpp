#include <iostream>
#include <vector>
#include <queue>
#include <list>

using namespace std;

bool depth_first_search(pair<int, list<int>>* graph, int i, int visited_group) {

    graph[i].first = visited_group;

    for (int element : graph[i].second) { 
        if (graph[element].first == 0) { 
            if (!depth_first_search(graph, element, (visited_group == 2) ? 1 : 2)) {
                return false;
            }
        }
        if (graph[element].first == visited_group) {
            return false;
        }
    }
    return true;
}

int main() {

    // количество лкшат
    int n;
    // количество пар лкшат
    int m;

    bool res = true;

    cin >> n;
    cin >> m;

    int number_of_lk_1;
    int number_of_lk_2;
    pair<int, list<int>> graph[n];
    for (int i = 0; i < m; i++) {
        cin >> number_of_lk_1;
        cin >> number_of_lk_2;
        graph[number_of_lk_1 - 1].second.push_back(number_of_lk_2 - 1);
        graph[number_of_lk_2 - 1].second.push_back(number_of_lk_1 - 1);
    }

    for (int i = 0; i < n; i++) {
        if (!res) {
            break;
        }
        if (graph[i].first == 0) {
            res = depth_first_search(graph, i, 1);
        }
    }

    if (res) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
}