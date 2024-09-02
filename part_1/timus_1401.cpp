#include<iostream>
#include<sstream>
#include<cmath>
#include<vector>
using namespace std;

bool contains(const vector<int>& vec, int element) {
    return find(vec.begin(), vec.end(), element) != vec.end();
}

int i2x2(int x, int y, vector<int> x_arr, vector<int> y_arr, int counter, int** res, int n) {

    int len = static_cast<int>(pow(2, n));

    if (n == 1) {
        int signX = (x % 2 == 0) ? 1 : -1;
        int signY = (y % 2 == 0) ? 1 : -1;
        res[x + signX][y] = counter;
        res[x + signX][y + signY] = counter;
        res[x][y + signY] = counter;
        counter++;
        return counter;
    }
    int len_2 = len / 2;

    int centre_x[2] = {x_arr[len_2 - 1], x_arr[len_2]};
    int centre_y[2] = {y_arr[len_2 - 1], y_arr[len_2]};

    vector<vector<int>> matrix;

    vector<int> x_coord(len_2);
    vector<int> y_coord(len_2);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            // для x
            if (centre_x[i] < x_arr[len_2]) {
                for (int k = 0; k < len_2; k++) {
                    x_coord[k] = x_arr[k];
                }
            } else {
                int middleIndex = len_2;
                for (int k = middleIndex, l = 0; k < len; ++k, ++l) {
                    x_coord[l] = x_arr[k];
                }
            }
            // для y
            if (centre_y[j] < y_arr[len_2]) {
                for (int k = 0; k < len_2; k++) {
                    y_coord[k] = y_arr[k];
                }
            }
            else {
                int middleIndex = len_2;
                for (int k = middleIndex, l = 0; k < len; ++k, ++l) {
                    y_coord[l] = y_arr[k];
                }
            }
            if (!(contains(x_coord, x) && (contains(y_coord, y)))) {
                res[centre_x[i]][centre_y[j]] = counter;
                vector<int> point = {centre_x[i], centre_y[j]};
                matrix.push_back(point);
            } else {
                vector<int> point = {x, y};
                matrix.push_back(point);
            }
        }
    }
    counter++;
    for (const auto& point : matrix) {
        vector<int> x_coord(len_2);
        vector<int> y_coord(len_2);
        // для x
        if (point[0] < x_arr[len_2]) {
            for (int k = 0; k < len_2; k++) {
                x_coord[k] = x_arr[k];
            }
        } else {
            int middleIndex = len_2;
            for (int k = middleIndex, l = 0; k < len; ++k, ++l) {
                x_coord[l] = x_arr[k];
            }
        }
        // для y
        if (point[1] < y_arr[len_2]) {
            for (int k = 0; k < len_2; k++) {
                y_coord[k] = y_arr[k];
            }
        }
        else {
            int middleIndex = len_2;
            for (int k = middleIndex, l = 0; k < len; ++k, ++l) {
                y_coord[l] = y_arr[k];
            }
        }
        if (res[point[0]][point[1]] != 0 || res[x][y] != 0) {
            counter = i2x2(point[0], point[1], x_coord, y_coord, counter, res, n - 1);
        } else {
            counter = i2x2(x, y, x_coord, y_coord, counter, res, n - 1);
        }
    }
    return counter;
}

int main() {

    int n;
    cin >> n;

    int x, y;
    cin >> x >> y;

    x -= 1;
    y -= 1;

    int len = pow(2, n);
    int counter = 1;

    // Выделение памяти для двумерного массива
    int** res = new int*[len];
    for (int i = 0; i < len; ++i) {
        res[i] = new int[len];
    }

    res[x][y] = 0;

    vector<int> array(len);
    for (int i = 0; i < len; i++) {
        array[i] = i;
    }

    counter = i2x2(x, y, array, array, counter, res, n);

    // Вывод массива
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Освобождение памяти
    for (int i = 0; i < len; ++i) {
        delete[] res[i];
    }
    delete[] res;

    return 0;
}