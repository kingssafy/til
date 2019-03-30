#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int result = 999999999;
void dfs(int garages[], int costs[], int N, int range, int endpoint, int curPosition, int curCost) {
    if (curPosition + range >= endpoint) {
        result = min(result, curCost); 
    }  else {

        for (int i = 0; i < N; i++) {
            if (garages[i] > curPosition && garages[i] <= curPosition + range && curCost+costs[i] < result) {
                dfs(garages, costs, N, range, endpoint, garages[i], curCost+costs[i]);
            }
        }
    }


}



int main() {
    int range, N;
    int garages[51];
    int costs[51];
    scanf("%d", &range);
    scanf("%d", &N);
    int temp=0, summer=0;
    for (int i = 0; i < N+1; i++) { 
        scanf("%d", &temp);
        summer += temp;
        garages[i] = summer;
    }
    int endpoint = garages[N];
    for (int i = 0; i < N; i++) scanf("%d", &costs[i]);
    dfs(garages, costs, N, range, endpoint, 0, 0);
    printf("%d\n", result);

    return 0;
}
