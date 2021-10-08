#include<iostream>
using namespace std;


class Triplet {
public:
    int x, y, gcd;
};

Triplet extEuclid(int a, int b) {
    if (b == 0) {
        Triplet ans;
        ans.x = 1;
        ans.y = 0;
        ans.gcd = a;
        return ans;

    }
    Triplet smallAns = extEuclid(b, a % b);
    Triplet ans;
    ans.gcd = smallAns.gcd;
    ans.x = smallAns.y;
    ans.y = smallAns.x - (a / b) * smallAns.y;
    return ans;
}
int modInverse(int a, int m) {
    return extEuclid(a, m).x;
}
int main() {

    int a, m;
    cin >> a >> m;
    cout << modInverse(a, m) << "\n";
    return 0;
}

//find value of x and y such that, ax + by = gcd(a,b).
//Have lots of application in number theory like calculating inverse mod.