#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

//для сравнения двух строк
bool is_right_position(string& a, string& b) {
    return (a + b) > (b + a);
}

int main() {

    //считывание числа в файл
    vector<string> numbers;
    ifstream inputFile("number.in");
    string num;
    while (inputFile >> num) {
        numbers.push_back(num);
    }
    inputFile.close();

    //длина массива
    int length = numbers.size();

    //cортировка чисел
    for (int i = 0; i < length - 1; ++i) {
        for (int j = 0; j < length - i - 1; ++j) {

            if (!is_right_position(numbers[j], numbers[j + 1])) {
                string tmp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = tmp;
            }
        }
    }

    //объединение числа в одну строку
    string max_of_numbers;
    for (string& num : numbers) {
        max_of_numbers += num;
    }

    cout << max_of_numbers << endl;

}