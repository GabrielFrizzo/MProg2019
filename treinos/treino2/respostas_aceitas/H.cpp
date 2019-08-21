#include <list>
#include <cstdio>
#include <string.h>
using namespace std;

int main() {
	list<char> result; char c; auto it = result.end();
	while (c=getchar(),c!=EOF) {
		if (c == '[') { it = result.begin(); }
		else if (c == ']') { it = result.end(); }
		else if (c == '\n') {
			for (auto i: result) { printf("%c", i); }
			printf("\n");
			result.clear();
			it = result.end();
		}
		else { result.insert(it, c); }
	}

	return 0;
}
