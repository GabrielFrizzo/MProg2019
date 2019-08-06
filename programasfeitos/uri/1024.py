def solve(inp):
    res = [chr(ord(char) + 3) if char.isalpha() else char for char in inp]
    res = res[::-1]
    mid = int(len(res)/2)
    res[mid:] = [chr(ord(char) - 1) for char in res[mid:]]

    print(''.join(res))

tests = int(input())

for _ in range(tests):
    solve(input())
