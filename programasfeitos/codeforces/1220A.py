N = int(input())

ns = input().count("n")

print(*(["1"]*ns + ["0"]*((N-3*ns)//4)))
