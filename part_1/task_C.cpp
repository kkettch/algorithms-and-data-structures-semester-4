#include <iostream>
#include <stack>
#include <map>
#include <vector>
#include<fstream>

using namespace std;

int main() {


    map<string, stack<int>> res;    
    stack<vector<string>> blocks_changes;
    vector<string> current_changes;
    string given;

    while (getline(cin, given)) {

        //в строке есть знак "="
        if (given.find('=') != string::npos) {
            
            //получаем значения до и после знака "="
            string before_equal = given.substr(0, given.find('='));
            string after_equal = given.substr(given.find('=') + 1);

            //если переменная до знака "=" не существует, то создаем
            if (res.find(before_equal) == res.end()) {
                res[before_equal] = stack<int>({0});
            }

            //если после "=" число
            if (after_equal.find_first_not_of("-0123456789") == string::npos) {

                //сохраняем изменения и новое значение переменной
                current_changes.push_back(before_equal);
                res[before_equal].push(stoi(after_equal));
            }

            //если после "=" не число
            else {

                //если переменная после знака "=" не существует, то создаем
                if (res.find(after_equal) == res.end()) {
                    res[after_equal] = stack<int>({0});
                }

                //сохраняем значение переменной до знака "=" в переменную после знака "="
                current_changes.push_back(before_equal);
                int number = res[after_equal].top();
                res[before_equal].push(number);
                cout << number << endl;
            }
        }

        //если строка содержит "{", то создаем новый массив для сохранения изменений
        else if (given.find('{') != string::npos) {
            blocks_changes.push(current_changes);
            current_changes = vector<string>{};
        }

        //если строка содержит "}", то удаляем новые значения у переменных, которые были изменены в блоке и получаем изменения предыдущего блока
        else if (given.find('}') != string::npos) {
            for (string &number : current_changes) {
                res[number].pop();
            }
            current_changes = blocks_changes.top();
            blocks_changes.pop();
        }
    }

}