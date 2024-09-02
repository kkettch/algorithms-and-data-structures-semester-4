#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <list>

using namespace std;

struct Element {
    int intValue;
    int idValue;
};
bool operator< (const Element &v1, const Element &v2){
    return v1.intValue > v2.intValue;
}

int main() {

    int n, m, x, y, x_dest, y_dest;
    cin >> n >> m >> x >> y >> x_dest >> y_dest;

    string map_of_game[n];
    for (int i = 0; i < n; ++i){
        cin >> map_of_game[i];
    }

    int start = (x - 1) * m + (y - 1);
    int end = (x_dest - 1) * m + (y_dest - 1);

    // хранение информации о том, какой элемент обходить следующим
    priority_queue<Element> order_of_traversing;
    order_of_traversing.push({0, start});

    // хранение значения оптимальных путей
    Element array_of_visited[n*m];
    for (int i = 0; i < n*m; i++) {
        array_of_visited[i] = {-1, -1};
    }

    while(!order_of_traversing.empty()) {

        auto current_element = order_of_traversing.top();
        order_of_traversing.pop();

        if (current_element.idValue == end) {
            break;
        }

        // для хранения точек, которые получили
        multiset<Element> found_elements;
        int index_current = current_element.idValue;

        int x_current = current_element.idValue / m;
        int y_current = current_element.idValue % m;

        if (map_of_game[x_current][y_current] == '#') {
            continue;
        }

        // вверх
        if (x_current - 1 >= 0 && map_of_game[x_current-1][y_current] != '#') {
            if (map_of_game[x_current-1][y_current] == 'W') {
                found_elements.insert({2, index_current - m});
            } else {
                found_elements.insert({1, index_current - m});
            }
        }

        // вниз
        if (x_current + 1 < n && map_of_game[x_current + 1][y_current] != '#') {
            if (map_of_game[x_current+1][y_current] == 'W') {
                found_elements.insert({2, index_current + m});
            } else {
                found_elements.insert({1, index_current + m});
            }
        }

        // влево
        if (y_current - 1 > 0 && map_of_game[x_current][y_current - 1] != '#') {
            if (map_of_game[x_current][y_current-1] == 'W') {
                found_elements.insert({2, index_current - 1});
            } else {
                found_elements.insert({1, index_current - 1});
            }
        }

        // вправо
        if (y_current + 1 < m && map_of_game[x_current][y_current + 1] != '#') {
            if (map_of_game[x_current][y_current+1] == 'W') {
                found_elements.insert({2, index_current + 1});
            } else {
                found_elements.insert({1, index_current + 1});
            }
        }

        for (auto element : found_elements) {
            int length_of_way = current_element.intValue + element.intValue;
            if (array_of_visited[element.idValue].intValue == -1 || array_of_visited[element.idValue].intValue > length_of_way) {
                order_of_traversing.push({length_of_way, element.idValue});
                array_of_visited[element.idValue].intValue = length_of_way;
                array_of_visited[element.idValue].idValue = current_element.idValue;
            }
        }
    }

    cout << array_of_visited[end].intValue << endl;
    if (array_of_visited[end].intValue == -1) return 0;

    list<string> letters;
    while (end != start) {
        int differences = end - array_of_visited[end].idValue;
        if (differences == -m) {
            letters.push_front("N");
        } else if (differences == m) {
            letters.push_front("S");
        } else if (differences == -1) {
            letters.push_front("W");
        } else if (differences == 1) {
            letters.push_front("E");
        }
        end = array_of_visited[end].idValue;
    }

    for (string& letter : letters) {
        cout << letter;
    }
    cout << endl;

    return 0;
}
