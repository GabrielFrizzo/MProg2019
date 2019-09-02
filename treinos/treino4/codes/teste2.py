print(1, *[0 for _ in range(999)])

for i in range(999):
    print(0, *[1 for _ in range(999)])
