#include<iostream>
#include<vector>
#include <cctype>
using namespace std;

int main(){

    string given;
    cin >> given;

    int len = given.size();
    vector<int> ind_big_letters;
    vector<int> ind_small_letters;
    int counter_big_letters = 0;
    int counter_small_letters = 0;

    //проверяем регистр первого символа
    if (islower(given.at(0))) {
        counter_small_letters += 1;
        ind_small_letters.push_back(counter_small_letters);
    }else {
        counter_big_letters += 1;
        ind_big_letters.push_back(counter_big_letters);
    }

    //создаем массив размер которого равен количеству заглавных букв
    vector<int> res;
    for (char ch : given) {
        if (isupper(ch)) {
            res.push_back(0);
        }
    }

    //массив для индексов 
    vector<int> indexes;
    indexes.push_back(0);
    for (int i = 1; i < len; i++) {
        indexes.push_back(i);

        //проверяем регистр текущей буквы
        if (islower(given[i])) {
            counter_small_letters += 1;
            ind_small_letters.push_back(counter_small_letters);
        }
        else {
            counter_big_letters += 1;
            ind_big_letters.push_back(counter_big_letters);
        }

        //пока текущая и предыдущая буква имеют один регистр и являются одной буквой, забываем их индексы, так как они больше не нужны. 
        while ((indexes.size() > 1) && ((given[indexes[indexes.size() - 1]] == tolower(given[indexes[indexes.size() - 2]])) || (given[indexes[indexes.size() - 1]] == toupper(given[indexes[indexes.size() - 2]]))) && (given[indexes[indexes.size() - 1]] != given[indexes[indexes.size() - 2]]))
        {   
            indexes.pop_back();
            indexes.pop_back();
            //сохраняем текущую маленькую букву по counter'у большой буквы
            res[ind_big_letters.back() - 1] = ind_small_letters.back();
            //забываем буквы которые уже имеют свою пары
            ind_big_letters.pop_back();
            ind_small_letters.pop_back();
        }

    }
    //если у какой-то ловушки нет животного, то выводим impossible
    for (int value : res) {
        if (value == 0) {
            cout << "Impossible";
            return 0;
        }
    }
    //иначе выводим индексы
    cout << "Possible" << endl;
    for (int value : res) {
        cout << value << " ";
    }
    return 0;
}
