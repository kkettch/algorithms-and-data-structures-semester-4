#include<iostream>
#include<deque>
#include <sstream>
#include <string>

using namespace std;

int main() {

    int n;                  // общее количество операций
    cin >> n;
    cin.ignore();

    string line;
    string sign;            // для считывания введенного знака
    int number;             // для считывания введенного номера
    deque<int> first_half;   // левая половина очереди
    deque<int> second_half;  // правая половина очереди

    while (n--) {
        getline(cin, line);
        istringstream iss(line);

        iss >> sign;

        if (sign == "-") {
            cout << first_half.front() << " ";
            first_half.pop_front();
            if (first_half.size() != second_half.size()) {
                first_half.push_back(second_half.front());
                second_half.pop_front();
            }
        }

        if (sign == "+") {
            iss >> number;
            if (first_half.size() != second_half.size()) {
                second_half.push_back(number);
            } else {
                if (!first_half.empty()) {
                    first_half.push_back(second_half.front());
                    second_half.pop_front();
                    second_half.push_back(number);
                }
                else
                {
                    first_half.push_back(number);
                }
            }
        }

        if (sign == "*") {
            iss >> number;
            if (first_half.size() == second_half.size()) {
                first_half.push_back(number);
            } else {
                second_half.push_front(number);
            }
        }
    }
}
