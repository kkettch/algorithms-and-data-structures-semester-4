#include<iostream>
#include<fstream>
#include<vector>
#include <map>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {

    //переменные
    string input_string;
    int weights[26];
    unordered_map<char, int> weights_for_letters;
    char letter = 'a';
    vector<int> word_weights;

    //считывается слово
    cin >> input_string;

    //считываются веса
    for (int i = 0; i < 26; ++i) {
        cin >> weights[i];
    }

    //заполняются веса для каждой буквы
    for (int weight : weights) {
        weights_for_letters[letter++] = weight;
    }

    //1. создать ассоциативный массив для каждой цифры (буквы)
    map<char, vector<int>> letter_indexes;

    //2. написать для каждой буквы ее индекс, когда она встречается 
    for (int i = 0; i < input_string.size(); ++i) {
        char letter = input_string[i];
        letter_indexes[letter].push_back(i);
    }

    //3. если встречается более одного раза, то удалить ее первый и последний индекс, при этом сохранив информацию о цифре в отдельный массив
    vector<char> repeated_chars; 
    for (map<char, vector<int>>::iterator it = letter_indexes.begin(); it != letter_indexes.end(); ++it) {
        if (it->second.size() > 1) {
            repeated_chars.push_back(it->first);
            letter_indexes[it->first].erase(letter_indexes[it->first].begin());
            letter_indexes[it->first].pop_back();
        }
    }

    //4. массив с буквами которые встречаются более одного раза отсортировать, реверснуть и между ними вставить оставшиеся цифры из строки
    sort(repeated_chars.begin(), repeated_chars.end(), [&weights_for_letters](char a, char b) {
        return weights_for_letters[a] > weights_for_letters[b];
    });

    //строка, содержащая буквы из repeated_сhars в обратном порядке
    string reversed_repeated_chars;
    for (auto it = repeated_chars.rbegin(); it != repeated_chars.rend(); ++it) {
        reversed_repeated_chars += *it;
    }

    //формируем результат
    string result(repeated_chars.begin(), repeated_chars.end());

    //восстановим строку по новым индексам
    for (map<char, vector<int>>::const_iterator it = letter_indexes.begin(); it != letter_indexes.end(); ++it) {
        char letter = it->first;
        const vector<int>& indexes = it->second;
        for (size_t i = 0; i < indexes.size(); ++i) {
            result += letter;
        }
    }

    //добавить реверснутую строку
    result += reversed_repeated_chars;

    //5. готово!
    cout << result << endl;
}