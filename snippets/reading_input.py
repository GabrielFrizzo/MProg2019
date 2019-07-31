''' Reading one input line, containing strings, ie:
foo bar baz
'''
foo, bar, baz = input().split()

''' Reading one input line, containing integers, ie:
1001 1002 1003
'''
foo, bar, baz = map(int, input().split())

''' Reading multiple input lines, ie:
1001 1002 1003
1004 1005 1006
1007 1008 1009
'''
while True:
    try:
        foo, bar, baz = map(int, input().split())
        print(foo, bar, baz)
    except EOFError:
        break


