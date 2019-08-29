// Lazy evaluation segment tree

#include <bits/stdc++.h>
#define MAX 1123456 

using namespace std;

long long int tree[MAX];
long long int lazy[MAX];
  
void updateRangeUtil(int si, int ss, int se, int us, 
                     int ue, long long int diff) 
{ 
    if (lazy[si] != 0) 
    { 
        tree[si] += (se-ss+1)*lazy[si]; 
  
        if (ss != se) 
        { 
            lazy[si*2 + 1]   += lazy[si]; 
            lazy[si*2 + 2]   += lazy[si]; 
        } 
  
        lazy[si] = 0; 
    } 
  
    if (ss>se || ss>ue || se<us) 
        return ; 
  
    if (ss>=us && se<=ue) 
    { 
        tree[si] += (se-ss+1)*diff; 
  
        if (ss != se) 
        { 
            lazy[si*2 + 1]   += diff; 
            lazy[si*2 + 2]   += diff; 
        } 
        return; 
    } 
  
    int mid = (ss+se)/2; 
    updateRangeUtil(si*2+1, ss, mid, us, ue, diff); 
    updateRangeUtil(si*2+2, mid+1, se, us, ue, diff); 
  
    tree[si] = tree[si*2+1] + tree[si*2+2]; 
} 
  
void updateRange(int n, int us, int ue, long long int diff) 
{ 
   updateRangeUtil(0, 0, n-1, us, ue, diff); 
} 
  
  
long long int getSumUtil(int ss, int se, int qs, int qe, int si) 
{ 
    if (lazy[si] != 0) 
    { 
        tree[si] += (se-ss+1)*lazy[si]; 
  
        if (ss != se) 
        { 
            lazy[si*2+1] += lazy[si]; 
            lazy[si*2+2] += lazy[si]; 
        } 
  
        lazy[si] = 0; 
    } 
  
    if (ss>se || ss>qe || se<qs) 
        return 0; 
  
    if (ss>=qs && se<=qe) 
        return tree[si]; 
  
    int mid = (ss + se)/2; 
    return getSumUtil(ss, mid, qs, qe, 2*si+1) + 
           getSumUtil(mid+1, se, qs, qe, 2*si+2); 
} 
  
long long int getSum(int n, int qs, int qe) 
{ 
    if (qs < 0 || qe > n-1 || qs > qe) 
    { 
        printf("%d", qs);
        printf("%d", qe > n-1);
        printf("%d\n", qs > qe);
        printf("Invalid Input"); 
        return -1; 
    } 
  
    return getSumUtil(0, n-1, qs, qe, 0); 
} 
  
int main() 
{ 
    int T, C, p, q, v, op, n;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &C);
        memset(tree, 0, sizeof(tree));
        memset(lazy, 0, sizeof(lazy));

        while (C--) {
            scanf("%d %d %d", &op, &p, &q);
            int _min = min(p, q), _max = max(p,q);
            if (op) {
                printf("%lld\n", getSum(n, _min-1, _max-1));
            }
            else {
                scanf("%d", &v);
                updateRange(n, _min-1, _max-1, (long long int)v);
            }
        }
    }
  
    return 0; 
} 

