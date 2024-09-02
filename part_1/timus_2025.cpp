#include <iostream>
#include <sstream>
using namespace std;

int main() {

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {

        int n, k;
        cin >> n >> k;

        int counter = 0;
        int amount_in_cur_team;

        for (int j = 0; j < n; j++) {  

            amount_in_cur_team = (j / k) + 1;
            counter += (j+1) - amount_in_cur_team;

        }

        cout << counter << endl;
    }
}