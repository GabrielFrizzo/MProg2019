# print(2**"{0:b}".format(int(input())).count("1"))
n = int(input())
n_bin = "{0:b}".format(n)

print(2**n_bin.count("1"))