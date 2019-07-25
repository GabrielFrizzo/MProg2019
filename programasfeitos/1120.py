while True:
    inp = input()
    if inp == '0 0': break

    x, n = inp.split()
    ans = n.replace(x, '')
    print(int(ans) if ans != '' else 0)
