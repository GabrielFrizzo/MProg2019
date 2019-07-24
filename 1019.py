n = int(input())

h = int(n/3600)
m = int((n%3600)/60)
s = n%60

print('{}:{}:{}'.format(h, m, s))