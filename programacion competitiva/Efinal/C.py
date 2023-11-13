def solve(n):
    result = 1
    temp = ""
    tempr = 0
    v = []
    for i in range(n): ## O(n)
        tempr = result * 7
        temp = str(tempr)
        if i + 1 == len(temp): ##si el tamaño del nuevo numero aumenta un digito
            result *= 7 ##multplicamos por 7 primero
            v.append(7)
        else: ## caso no se cumpla necesitamos tenemos que utilizar el siguiente primo
            result *= 11 ##por 11
            v.append(11)
    for j in v:
        print(j, end=" ") ## imprimimos los valores guardados
    print()

test = int(input())
for i in range(test): ##O(test)
    n = int(input())
    solve(n)