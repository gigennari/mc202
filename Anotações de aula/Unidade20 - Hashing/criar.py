"""
1º caso de teste: 10 100
2º caso de teste: 100000 72000
3º caso de teste: 100000 720000
"""

import random 

numero_palavras = 10000
numero_ocorrencias = 72000

palavras = list()

num = 0

while len(palavras) < numero_palavras:
    palavras.append('palavra' + str(num))
    num += 1

num = 0
while num < numero_ocorrencias:
    print(random.choice(palavras))
    num += 1

