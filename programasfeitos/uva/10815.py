# Utilizando a biblioteca de expressões regulares do Python para encontrar as palavras.

import re
import sys
entry = sys.stdin.buffer.read().decode() # O judge do URI mostrou problemas com caracteres unicode.
                                         # Utilizando buffer e depois decode(), contornamos esse problema,
                                         # pois recebemos bytes e depois os decodificamos para string
    
p = re.compile('[a-zA-Z]+')
words = p.findall(entry)
low_words = list(set([word.lower() for word in words]))

for word in sorted(low_words):
    print(word)
