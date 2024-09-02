#include <iostream>
#include <vector>
#include <queue>
#include <list>

using namespace std;

int depth_first_search(pair<int, list<int>>* graph, int i) {

    int counter = 0;

    // вершина становится посещенной в первый раз, поэтому присваиваем 1
    graph[i].first = 1;

    for (int element : graph[i].second) { 
        // если связанная вершина уже посещалась 1 раз, то добавляем counter
        if (graph[element].first == 1) {
            return 1;
        }
        // если еще ни разу не вызывалась, то рекурсивно вызываем метод depth_first_search()
        if (graph[element].first == 0) {
            counter += depth_first_search(graph, element);
        }
    }

    // присваиваем значению посещения 2, чтобы больше не считать эту вершину так как она посещена и уже посчитана
    graph[i].first = 2;

    return counter;
}

int main() {

    // счетчик для результата
    int counter = 0;

    // значение количества ключей в копилке
    int key_of_graph;

    // количество вершин графа (копилок)
    int n;

    // считывание
    cin >> n;

    // считывание в каждую вершину графа ключи для каких графов она имеет
    pair<int, list<int>> graph[n];
    for (int i = 0; i < n; i++) {
        cin >> key_of_graph;
        graph[key_of_graph - 1].second.push_back(i);
    }
    
    for (int i = 0; i < n; i++) {
        
        // если связанную вершину графа еще не посещали, то вызываем поиск в глубину
        if (graph[i].first == 0) {
            counter += depth_first_search(graph, i);
        }
    }

    cout << counter << endl;
}