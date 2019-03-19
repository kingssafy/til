#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

int main() {
    freopen("6781_input.txt", "r", stdin);
    //    ios_base::sync_with_stdio(false);
    //    cin.tie(NULL);
    int T, temp, nums[9];
    char c, cols[9];
    scanf("%d", &T); 
    for (int tc = 0; tc < T; tc++) {
        int R[9]={0}, G[9]={0}, B[9]={0};
        for(int i = 0; i < 9; i++) {
            scanf("%1d", &temp);
            nums[i] = temp;
        }
        for (int i = 0; i < 9; i++) {
            scanf(" %1c", &c);
            cols[i] = c;
        }
        for (int i = 0; i < 9; i++) {
            char r = 'R';
            char g = 'G';
            if (cols[i] == r) {
                R[i] = nums[i];
            } else if (cols[i] == g) {
                G[i] = nums[i];
            } else {
                B[i] = nums[i];
            }
        }
        sort(R, R+9);
        int stack[9] = {};
        int last = 0, temp = 0, counter = 0,end = 0, dcounter =0;
        bool flag = true;
        for (int i = 8; i >=0; i--) {
            temp = R[i];
            if (temp == 0) break;
            stack[last] = temp; 
            if (last-temp >= 2) {
                flag = false;
                break;
            } else if (temp == last) {
                counter++;
                dcounter = 1;
                if (counter ==3) {
                    end -= 3;

                }
            }  else {
                counter = 1;
                dcounter ++;
                if (dcounter ==3) {
                    end -=3;
                }
            }
            last = temp; 
            end ++;
        } 
        if (end !=0) flag = false;
        sort(G, G+9);
        last = 0, temp = 0, counter = 0,end = 0, dcounter =0;
        for (int i = 8; i >=0; i--) {
            temp = G[i];
            if (temp == 0) break;
            stack[last] = temp; 
            if (last-temp >= 2) {
                flag = false;
                break;
            } else if (temp == last) {
                counter++;
                dcounter = 1;
                if (counter ==3) {
                    end -= 3;

                }
            }  else {
                counter = 1;
                dcounter ++;
                if (dcounter ==3) {
                    end -=3;
                }
            }
            last = temp; 
            end ++;
        } 
        if (end != 0) flag = false;
        sort(B, B+9);
        last = 0, temp = 0, counter = 0,end = 0, dcounter =0;
        for (int i = 8; i >=0; i--) {
            temp = B[i];
            if (temp == 0) break;
            stack[last] = temp; 
            if (last-temp >= 2) {
                flag = false;
                break;
            } else if (temp == last) {
                counter++;
                dcounter = 1;
                if (counter ==3) {
                    end -= 3;

                }
            }  else {
                counter = 1;
                dcounter ++;
                if (dcounter ==3) {
                    end -=3;
                }
            }
            last = temp; 
            end ++;
        } 
        if (end != 0) flag = false;
        if (flag) {
            cout << "#" << tc+1 << " " << "WIN" << endl;
        } else {
            cout << "#" << tc+1 << " " << "Continue" << endl;
        }
    }
    
}
