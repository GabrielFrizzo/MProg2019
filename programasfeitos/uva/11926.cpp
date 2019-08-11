// Usando bitset e fazendo a simulação, como orienta HaHa(2.2).

#include <cstdio>
#include <bitset>
using namespace std;

bitset<1123456> schedule;
void run(int n, int m) {
    int start, end, interval;
    bool flag = false;
    schedule.reset();
    while (n--) {
        scanf("%d %d", &start, &end);
        if (flag) {continue;}
        for (int i=start; i < end; i++) {
            if (schedule.test(i)) {
                flag = true;
            }
            schedule.set(i);
        }
    }
    while (m--) {
        scanf("%d %d %d", &start, &end, &interval);
        if (flag) {continue;}
        for (int j = 0; j+start <= 1000000; j+= interval) {
            for (int i = start+j; i<end+j && i <= 1000000; i++) {
                if (schedule.test(i)) {
                    flag = true;
                }
                schedule.set(i);
            }
        }
    }
    flag ? printf("CONFLICT\n") : printf("NO CONFLICT\n");
    return;
}

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m), n || m) {
        run(n, m);
    }


    return 0;
}
