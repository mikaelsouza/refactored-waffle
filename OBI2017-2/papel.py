import statistics

qnt_entradas = int(input())
entradas = [int(x) for x in input().split()]

mediana = statistics.median(entradas)

cont = 0

for el in entradas:
    if(el > mediana):
        cont += 1
print(cont)
