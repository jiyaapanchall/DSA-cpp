#include <iostream>
#include <vector>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {

    vector<int> st;

    for (int asteroid : asteroids) {

        bool destroyed = false;

        // Collision possible
        while (!st.empty() &&
               st.back() > 0 &&
               asteroid < 0) {

            if (st.back() < -asteroid) {
                // Stack asteroid is smaller
                st.pop_back();
                continue;
            }

            else if (st.back() == -asteroid) {
                // Both are destroyed
                st.pop_back();
                destroyed = true;
                break;
            }

            else {
                // Current asteroid is smaller
                destroyed = true;
                break;
            }
        }

        if (!destroyed) {
            st.push_back(asteroid);
        }
    }

    return st;
}

int main() {

    vector<int> asteroids = {5, 10, -5};

    vector<int> result = asteroidCollision(asteroids);

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}