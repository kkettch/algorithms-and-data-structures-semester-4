#include<iostream>
using namespace std;

int main(){

    //считываем количество цветов
    int n;
    cin >> n;

    //массив для хранения видов цветков
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int num_first_answer;
    int num_last_answer;
    int first_temp = 1;
    int last_temp = 0;
    int max_len = 0;

    for (int i = 1; i < n; i++) {
        //если не последний элемент массива
        if (i != (n - 1)) {
            //если по бокам от шестерки стоят две шестерки
            if (arr[i] == arr[i-1] && arr[i] == arr[i+1]) {
                //сохраняем индекс последнего элемента
                last_temp = i + 1;
                //если длина полученного ряда больше максимальной 
                if ((last_temp - first_temp + 1) > max_len) {
                    //то меняем максимальную длину на новую максимальную и сохраняем значения первого и последнего индекса 
                    max_len = last_temp - first_temp + 1;
                    num_first_answer = first_temp;
                    num_last_answer = last_temp;
                }
                //меняем индекс первого элемента ряда так как продолжаем идти дальше по ряду и искать максимальное значение
                first_temp = i + 1;
            }
        } 
        //если дошли до конца ряда
        else {
            //сохраняем индекс последнего элемента
            last_temp = i + 1;
            //и проверяем не является ли ряд максимальным
            if ((last_temp - first_temp + 1) > max_len) {
                max_len = last_temp - first_temp + 1;
                num_first_answer = first_temp;
                num_last_answer = last_temp;
            }
        }
    }

    //вывод индексов
    if (n == 1) {
        cout << 1 << " " << 1;
    } else {
        cout << num_first_answer << " " << num_last_answer;
    }

    return 0;
}
