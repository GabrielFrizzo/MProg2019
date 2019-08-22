// Problema de simulação usando uma queue e uma stack

#include <bits/stdc++.h>
using namespace std;

bool notempty(queue<int> queues[101]) {
    for (int i=1; i<=100; i++) {
        if (!queues[i].empty()) {return true;}
    }
    return false;
}

int main() {
    int TC, N, S, Q, Qi, c, time;
    stack<int> carrier;
    queue<int> queues[101];
    scanf("%d", &TC);
    while (TC--) {
        time = 0; //cleanup

        scanf("%d %d %d", &N, &S, &Q);
        for (int i=1; i<=N; i++) {
            scanf("%d ", &Qi);
            while (Qi--) {
                scanf("%d", &c);
                queues[i].push(c);
            }
        }

        int i = 1;
        while (notempty(queues) || !carrier.empty()) {
            time += 2;
            while (queues[i].size() < Q && !carrier.empty()) {
                if (carrier.top() == i) {
                    carrier.pop();
                    time++;
                }
                else if (queues[i].size() < Q) {
                    queues[i].push(carrier.top());
                    carrier.pop();
                    time++;
                }
            }
            while (!carrier.empty() && carrier.top() == i) {
                carrier.pop();
                time++;
            }

            while (!queues[i].empty() && carrier.size() < S) {
                carrier.push(queues[i].front());
                queues[i].pop();
                time++;
            }
            i = i%N + 1;
        }
        printf("%d\n", time-2); // -2 é chuncho para compensar o tempo da primeira "transição"
    }
    return 0;
}
