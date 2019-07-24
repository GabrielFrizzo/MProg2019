def adicao(a, b, carry=False):
    result = a + b
    if carry:
        result += 1
    if result >=10:
        return True
    return False

while True:
    a, b = map(lambda x: x[::-1], input().split(' '))

    if a == '0' and b == '0':
        break

    if len(a) < len(b):
        b, a = (a, b)
    b += '0'*(len(a)-len(b))
    count = 0
    carry = False
    for i, j in zip(a, b):
        carry = adicao(int(i), int(j), carry)
        if carry:
            count += 1

    if count == 0:
        print('No carry operation.')
    elif count == 1:
        print('1 carry operation.')
    else:
        print('{} carry operations.'.format(count))
   
