#include <bits/stdc++.h>
using namespace std;
#define STACKSIZE 10
struct stk {
    int Item[STACKSIZE];
    int Top;
};
struct stk S;
void Initialize() {
    S.Top = -1;
} 
bool IsEmpty() {
    return (S.Top == -1);
}
void Push(int x) {
    if (S.Top == (STACKSIZE - 1)) {
        cout << "Stack Overflows";
        exit(1);
    } else {
        S.Top++;
        S.Item[S.Top] = x;
    }
}
int Pop() {
    if (IsEmpty()) {
        cout << "Stack Underflows";
        exit(1);
    } else {
        int x = S.Item[S.Top];
        S.Top--;
        return x;
    }
}
void BalancedPara(char arr[]) {
    Initialize();
    int i = 0, flag = 0;
    while (arr[i] != '\0') {
        if (arr[i] == '(') {
            Push(arr[i]);
        } else if (arr[i] == ')') {
            if (!IsEmpty()) {
                Pop();
            } else {
                flag = 1;
                break;
            }
        }
        i++;
    }
    if (IsEmpty() && flag == 0)
        cout << "Valid Expression";
    else
        cout << "Invalid Expression";
}
int main() {
    int N;
    cout << "Enter total number of parentheses: ";
    cin >> N;
    char arr[N + 1];
    cout << "Enter parentheses expression: ";
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    arr[N] = '\0';
    BalancedPara(arr);
    return 0;
}
