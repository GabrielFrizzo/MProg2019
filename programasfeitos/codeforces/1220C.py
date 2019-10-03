inp = input()
m = inp[0]
print("Mike")

for i in inp[1:]:
    if m < i:
        print("Ann")
    else:
        print("Mike")
        m = i
