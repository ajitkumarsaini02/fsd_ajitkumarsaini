//Input sorted array (-3,-2,-1,0,2,4) and sort on the basis of equation Ax2+Bx+C, A=-1,B=-4,c=1
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static bool cmp_quadratic(int x, int y) {
     int A = -1;
     int B = -4;
     int C = 1;
    return ((A*x*x + B*x + C)<(A*y*y + B*y + C));
}

int main() {
    vector<int> v{-3, -2, -1, 0, 2, 4};
    sort(v.begin(), v.end(), cmp_quadratic);
    
    for (int i : v) {
        cout << i << " ";
    }

    return 0;
}