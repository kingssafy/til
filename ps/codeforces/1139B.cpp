#include <cstdio>
#define ll long long
using namespace std;
int array[200001];

int main() {
    int n,  prev, current;
    ll result=0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    prev = array[n-1]+1;
    for (int i = n-1; i >= 0; i--) {
        current = array[i];   
        if (current >= prev) {
            prev--;
            result += prev; 
            if (prev == 0) break;
        } else {
            prev = current;
            result += prev;
        }
    }
    printf("%llu", result);


}
