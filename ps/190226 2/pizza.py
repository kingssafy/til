import sys
sys.stdin = open("pizza_input.txt")

for tc in range(int(input())):
    N, M = map(int, input().split())
    pizzas = list(map(int, input().split()))
    pizzas = [[key, value] for key, value in enumerate(pizzas, 1)]
    pizzabox = []
    for _ in range(N):
        pizzabox.append(pizzas.pop(0))
    while [item[1] for item in pizzabox].count(0) != N-1:
        for idx in range(len(pizzabox)):
            if pizzabox[idx][1] != 0:
                pizzabox[idx][1] //= 2
            if pizzabox[idx][1] == 0 and pizzas:
                pizzabox[idx] = pizzas.pop(0)
            if [item[1] for item in pizzabox].count(0) == N-1:
                break
    for item in pizzabox:
        if item[1] != 0:
            result = item[0]

    print(f"#{tc+1} {result}")
            

