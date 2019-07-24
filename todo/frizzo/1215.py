#PROBLEMA COM O INPUT
from sys import stdin
import re


entry = ''

while True:
    try:
        entry += input()
    except:
        break

try:
    p = re.compile('[a-zA-Z]+')
    words = p.findall(entry)
    words = list(set(map(lambda word: word.lower(), words)))

    words.sort()

    for word in words:
        print(word)
except:
    print('teste')
