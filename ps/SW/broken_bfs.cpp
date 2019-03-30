#include <iostream>
#include <fstream>
using namespace std;
int N, M, O;
int nums[10] = {};
int ops[4] = {}; 
int W;
struct soul {
    int a;
    int op;
    int b;
    int m;
};
soul Q[100000000];

int eval(int a, int op, int b) {
    if (op == 0) return b;
    if (op == 1) return a + b;
    if (op == 2) return a - b;
    if (op == 3) return a * b;
    int result = a / b;
    return result;
}
int bfs() {
    int front = 0, rear = 0;
    Q[rear].a = 0;
    Q[rear].op = 0;
    Q[rear].b = -9999;
    Q[rear++].m = 0;
    while (front < rear) {
        if (front > 500000) {
            for (int i = 0; i < rear-front; i++) {
                Q[i] = Q[front++];
            }
            rear = rear-front;
            front = 0;
        }
        int a = Q[front].a;
        int op = Q[front].op;
        int b = Q[front].b;
        int m = Q[front++].m;
        if (m > M) return -1;
        if (b > 999) continue;
        if (b == W && m != 0 && op == 0) {
            return m;
        }
        if (m!=0 && (b != 0 || op != 4)) {
            if (b != -9999 && eval(a,op,b) > 999 ) continue;
            if (b != -9999 && eval(a,op,b) == W) {
                return m+1;
            }
        }
        if (b != -9999) {
            for (int i = 0; i < N; i++) {
                Q[rear].a = a;
                Q[rear].op = op;
                Q[rear].b = b*10+nums[i];
                Q[rear++].m = m+1;
            }

            for (int i = 0; i < O; i++) {
                if (b == 0 && op == 4) continue;
                Q[rear].a = eval(a, op, b);
                Q[rear].op = ops[i];
                Q[rear].b = -9999;
                Q[rear++].m = m+1;
            }
        } else {
            for (int i = 0; i < N; i++) {
                Q[rear].a = a;
                Q[rear].op = op;
                Q[rear].b = nums[i];
                Q[rear++].m = m+1;
            }
        }
    }
    return -1;

}




int main() {
    ifstream cin("broken_input.txt");
    int T, minimum;
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        cin >> N >> O >> M;
        for (int i = 0; i < N; i++) cin >> nums[i];
        for (int i = 0; i < O; i++) cin >> ops[i];
        cin >> W;
        minimum = bfs();
        cout << "#" << tc+1 << " " << minimum << endl;
    }


    return 0;
}
