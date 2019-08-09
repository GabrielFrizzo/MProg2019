// A dificuldade deste problema é maior para receber o input. Usando um buffer e sscanf, a tarefa ficou mais fácil.
// Se mostra bastante útil a habilidade de customizar a função de sort(terceiro argumento).

#include <cstdio>
#include <algorithm>
using namespace std;
#define BUFFER_SIZE 100
struct Team {
    int num;                                            // número do time
    int problems[10] = {-1, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // problemas feitos recebem -1, problemas incompletos 
    int penalty = 0;                                    // recebem o valor do penalty caso sejam feitos corretamente
    int questions = -1;                                 // times que nao submeteram nenhuma questão recebem -1
};

bool sorting_func(Team a, Team b) {
    if (a.questions > b.questions) { return true; }
    else if (a.questions < b.questions) { return false; }
    else {
        if (a.penalty < b.penalty) { return true; }
        else if (a.penalty > b.penalty) { return false; }
        else {
            return a.num < b.num;
        }
    }
}

int main() {
    int TC, team_num, problem, time;
    char L, buffer[BUFFER_SIZE];
    scanf("%d", &TC);
    getchar();getchar(); // pula a primeira linha em branco
    while (TC--) {
        Team teams[101];
        for (int i = 1; i < 101; i++) { teams[i].num = i; }
        while (fgets(buffer, BUFFER_SIZE, stdin) != NULL && buffer[0] != '\n') {
            sscanf(buffer, "%d %d %d %c", &team_num, &problem, &time, &L);
            
            if (teams[team_num].questions == -1) { teams[team_num].questions = 0; }
            if (teams[team_num].problems[problem] == -1 || (L != 'C' && L != 'I')) {continue;}
            if (L == 'C') {
                teams[team_num].penalty += time + teams[team_num].problems[problem];
                teams[team_num].problems[problem] = -1;
                teams[team_num].questions += 1;
            }
            else if (L == 'I') {
                teams[team_num].problems[problem] += 20;
            }
        }

        sort(teams, teams+101, sorting_func);
        for (int i = 0; i < 101; i++) {
            if (teams[i].questions == -1) { break; }
            printf("%d %d %d\n", teams[i].num, teams[i].questions, teams[i].penalty);
        }
        if (TC > 0) { printf("\n"); }
    }

    
    return 0;
}
