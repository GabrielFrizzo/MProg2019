#include <bits/stdc++.h>
#define MAX 112345
using namespace std;

int parents[MAX], heights[MAX]; 
vector<int> children[MAX];

int height(int node) {
    if (children[node].empty()) { return heights[node] = 0; }
    int max_ = -1;
    for (auto child : children[node]) { max_ = max(max_, height(child)); }
    return heights[node] = max_+1;
}

int main(int argc, char const *argv[])
{
    parents[1] = -1;

    int N, K, curr, nx;
    scanf("%d %d", &N, &K);
    for (int i = 2; i <= N; i++) {
        scanf("%d", &parents[i]);
        children[parents[i]].push_back(i);
    }
    height(1);
    // for (int i = 1; i <= N; i++) { printf("%d ", heights[i]);}printf("ALTURAS\n");

    auto compare = [](int a, int b) { return heights[a] < heights[b]; };
    priority_queue<int, vector<int>, decltype(compare)> q(compare);
    
    q.push(1);
    int total = 0;
    while (K--) {
        if (q.empty()) {break;}
        curr = q.top();q.pop();
        total+=heights[curr]+1;

        while (!children[curr].empty()) {
            nx = 0;
            for (auto child : children[curr]) {
                if (heights[child] == heights[curr]-1 && !nx) { nx = child; }
                else { q.push(child); }
            }
            curr = nx;
        }
    }

    printf("%d\n", total);
    return 0;
}