import re
'''
Essa biblioteca usa Expressoes Regulares, importante conhecer.
https://regexr.com/
'''

obj = re.compile('[a-zA-Z]+')
result = obj.findall('quick+brown lazy1fox')

print(result) # ['quick', 'brown', 'lazy', 'fox']

####################################################

obj = re.compile('(\d+)([a-z]+)')
result = obj.search('foo123bar')

print(result.groups()) # ('123', 'bar')
print(result.group(2)) # ('bar')
print(result.group(0)) # ('123bar')

####################################################

obj = re.compile('\d+')
result = obj.search('not a match')

print('Encontrado') if result else print('Nao encontrado') # Nao encontrado
