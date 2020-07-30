# include <iostream>
# include <cmath>

using namespace std;

const int N = 3;
struct point {
    float x, y, z;
};

float distance(float a, float b, float c, int counter) {
    a = a / counter;
    b = b / counter;
    c = c / counter;
    return sqrt(a * a + b * b + c * c);
}


bool exist_point(point t[N], float r, int index, float sum_x, float sum_y, float sum_z, int counter) {
    if (counter >= 2 && distance(sum_x, sum_y, sum_z, counter) <= r) return true;
    if (index == N) return false;
    return exist_point(t, r, index + 1, sum_x + t[index].x, sum_y + t[index].y, sum_z + t[index].z, counter + 1) ||
           exist_point(t, r, index + 1, sum_x, sum_y, sum_z, counter);
}

int main() {
    point t[N];
    for (int i = 0; i < N; i++) cin >> t[i].x >> t[i].y >> t[i].z;
    return exist_point(t, 100, 0, 0, 0, 0, 0);
}