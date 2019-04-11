#include <cstdio>
using namespace std;
const int MAXN = 300001;

int N;
int arr[MAXN]; 

bool ok(int size) {
    for(int i = 0; i +size < N; i++) {
        if (arr[i] != arr[i+size]) {
            return true;
        }
    }
    return false;
}



int main() {
//    freopen("A_input.txt", "r", stdin);
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    int x = -1;
    for (int b = N-1; b >= 1; b/=2) {
        while (ok(x+b)) x+=b;
    }
    printf("%d", x);
    
    return 0;
}
