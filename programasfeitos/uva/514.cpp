// Simulação usando Stack(pilha). HaHa(2.2)

#include <cstdio>
#include <stack>
using namespace std;

int main() {
    int N, curr, j; bool flag;
    stack<int> s;
    while (scanf("%d", &N), N) {
        while (scanf("%d", &curr), curr) {
            flag = true;
            j = 1;
            while (!s.empty()) {s.pop();}
            for (int i=1; i <= N; i++) {
                if (!s.empty() && s.top() == curr) {s.pop();} 
                else {
                    for (j; j <= N && j != curr; j++) {
                        s.push(j);
                    }
                    if (j > N && flag) {printf("No\n");flag=false;}
                    j++;
                }
                if (i == N) {if(flag){printf("Yes\n");}}
                else {scanf("%d", &curr);}
            }
        }
        printf("\n");
    }

    return 0;
}
