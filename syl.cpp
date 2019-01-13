#include <iostream>
using namespace std;

int main(){
    int n, _, a; cin >> n >> _ >> a;
    int longest = 0;
    int current = 0;
    for (int i = 1; i < n; i++){
        int b; cin >> b;
        current = (b == a)? 0 : current + 1;
        a = b;
        longest = max(current, longest);
    }
    cout << longest + 1;
}
