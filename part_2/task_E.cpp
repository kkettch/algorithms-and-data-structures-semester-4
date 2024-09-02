#include<iostream>
using namespace std;

int main() {

    //количество стойл и коров соответственно
    int n, k;
    cin >> n >> k;

    //координаты стойл
    int array_stall[n];
    for (int i = 0; i < n; i++) {
        cin >> array_stall[i];
    }

    int first_element = 0;
    int last_element = array_stall[n - 1] - array_stall[0];

    while (first_element < last_element) {

        //первая корова всегда стоит в первом стойле
        int cows_in_the_stall = 1;

        int middle = (first_element + last_element + 1) / 2;
        int first_element_tmp = array_stall[0];

        for (int i = 1; i < n; i++) {
            if ((array_stall[i] - first_element_tmp) >= middle) {
                //ставим корову в стойло
                cows_in_the_stall++;
                //считаем расстояние от нового стойла
                first_element_tmp = array_stall[i];
            }
        }

        if (cows_in_the_stall >= k) {
            first_element = middle;
        }
        else {
            last_element = middle - 1;
        }

    }
    cout << first_element;
    return 0;
}