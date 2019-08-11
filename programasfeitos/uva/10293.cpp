// Solução bastante parecida com a do Zatesko, mas guardando o char anterior ao inves de usar a flag.

#include <cstdio>
#include <map>
using namespace std;

int main() {
    char curr, prev = '#';
    int count=0;
    map<int, int> counts;
    while ((curr = getchar()) != EOF) {
        if (curr == '\n' && prev=='-') {count=count;}
        else if (isalpha(curr)) {count += 1;}
        else if (curr == '#') {
            for (auto &i : counts)
                printf("%d %d\n", i.first, i.second);
            printf("\n");
            count = 0;
            counts.clear();
        }
        else if (curr == '-' && isalpha(prev)) {count=count;}
        else if (curr == '\'' && (isalpha(prev) || prev=='\n')) {count=count;}
        else if (count > 0) {
            if (!counts[count]) {counts[count] = 0;}
            counts[count]++;
            count=0;
        }
        prev = curr;
    }

    return 0;
}
