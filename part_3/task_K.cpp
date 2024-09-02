#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    int n;
    int m;

    cin >> n;
    cin >> m;

    multimap<int, int> free_by_size;
    map<int, int> free_by_index;
    vector<pair<int, int>> busy(m);

    int current;
    int index;
    int size;

    free_by_index.insert({1, n});
    free_by_size.insert({n, 1});

    for (int i = 0; i < m; busy[i] = {current, index}, i++){
        cin >> current;

        if (current > 0) {
            auto it = free_by_size.lower_bound(current);
            if (it == free_by_size.end()) index = -1;
            else {
                index = it->second;
                size = it->first - current;

                free_by_index.erase(it->second);
                free_by_size.erase(it);
                if (size > 0) {

                    free_by_index.insert({index + current, size});
                    free_by_size.insert({size, index + current});
                }
            }
            cout << index << endl;
        } else {
            int index_x = busy[abs(current) - 1].second;
            int size_x = busy[abs(current) - 1].first;
            if (index_x == -1) continue;

            auto it_current = free_by_index.lower_bound(index_x);
            decltype(free_by_index.begin()) it_next;
            if (it_current == free_by_index.begin()) {
                it_next = free_by_index.end();
            } else {
                it_next = prev(it_current);
            }

            if (it_current != free_by_index.end() && it_current->first == index_x + size_x){
                if (it_next != free_by_index.end() && it_next->first + it_next->second == index_x) {
                    index = it_next->first;
                    size = it_next->second + it_current->second;

                    auto it_1 = free_by_size.find(it_next->second);
                    while (it_1->second != it_next->first) it_1++;
                    free_by_size.erase(it_1);
                    free_by_index.erase(it_next);

                    auto it_2 = free_by_size.find(it_current->second);
                    while (it_2->second != it_current->first) it_2++;
                    free_by_size.erase(it_2);
                    free_by_index.erase(it_current);

                    free_by_index.insert({index, size + size_x});
                    free_by_size.insert({size + size_x, index});

                } else {
                    size = it_current->second;

                    auto it_d = free_by_size.find(it_current->second);
                    while (it_d->second != it_current->first) it_d++;
                    free_by_size.erase(it_d);
                    free_by_index.erase(it_current);

                    free_by_index.insert({index_x, size + size_x});
                    free_by_size.insert({size + size_x, index_x});
                }
            } else {
                if (it_next != free_by_index.end() && it_next->first + it_next->second == index_x) {
                    index = it_next->first;
                    size = it_next->second;

                    auto it_d = free_by_size.find(it_next->second);
                    while (it_d->second != it_next->first) it_d++;
                    free_by_size.erase(it_d);
                    free_by_index.erase(it_next);

                    free_by_index.insert({index, size + size_x});
                    free_by_size.insert({size + size_x, index});

                } else {
                    free_by_index.insert({index_x, size_x});
                    free_by_size.insert({size_x, index_x});
                }
            }

            index = 0;
        }
    }
    return 0;
}