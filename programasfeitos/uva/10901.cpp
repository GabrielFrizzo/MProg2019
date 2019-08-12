// Simulação utilizando duas filas, uma para o lado esquerdo e outra para o lado direito.(HaHa2.2)
// Repare que temos que mostrar os tempos na ordem na qual recebemos os carros. Por isso,
// foi utilizado um pair<int,int> para representar um carro, ao invés de um int.

#include <cstdio>
#include <queue>
#include <string.h>
using namespace std;

typedef pair<int,int> ii;

int main() {
    int TC, n, t, m, arrival, c_n; long time; //c_n = current loaded number of cars
    char side[10];
    queue<ii> left_q, right_q;
    scanf("%d", &TC);
    long cars[10000];
    bool c_side, empty; // left = false, right = true
    for (int run=0; run<TC; run++) {
        if (run) {printf("\n");}
        scanf("%d %d %d", &n, &t, &m);
        while (!left_q.empty()) {left_q.pop();}
        while (!right_q.empty()) {right_q.pop();}
        for (int i=0; i < m; i++) {
            scanf("%d %s", &arrival, side);
            
            if (strcmp(side, "right") == 0) {
                right_q.push(make_pair(i,arrival));
            }
            else {left_q.push(make_pair(i,arrival));}
        }
        // start
        time = 0;
        c_side = false;
        while (!(left_q.empty() && right_q.empty())) {
            c_n = 0;
            if (c_side) {
                while (!right_q.empty() && right_q.front().second <= time && c_n < n) {
                    c_n += 1;
                    cars[right_q.front().first] = time+t;
                    right_q.pop();
                }
                if (c_n || (!left_q.empty()&&left_q.front().second<=time)) {time += t;c_side=false;} // troca de lado
                else {                                                // espera o proximo carro chegar
                    if ((right_q.empty()) || (!left_q.empty() && left_q.front().second < right_q.front().second)) {time = left_q.front().second+t;c_side=false;}
                    else {time=right_q.front().second;}
                }

            }
            else {
                while (!left_q.empty() && left_q.front().second <= time && c_n < n) {
                    c_n += 1;
                    cars[left_q.front().first] = time+t;
                    left_q.pop();
                }
                if (c_n || (!right_q.empty()&&right_q.front().second<=time)) {time += t;c_side=true;} // troca de lado
                else {                                                // espera o proximo carro chegar
                    if ((left_q.empty())||(!right_q.empty() && right_q.front().second < left_q.front().second)) {time = right_q.front().second+t;c_side=true;}
                    else {time=left_q.front().second;}
                }
            }
        }
        for (int i=0; i < m; i++)
            printf("%ld\n", cars[i]);

        //end
    }

    return 0;
}
