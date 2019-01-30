##calc('123+2-124') #=> 1
#calc('-12+12-7979+9191') #=> 1212
#calc('+1-1+1-1+1-1+1-1+1-1+1-1+1-1+1-1+1-1+1-1+1-1+1-1+1-1+1-1+1-1+1-1') #=> 0

def calc(string):
    return sum(map(int, string.replace('-', ' -').replace('+', ' +').split()))
print(calc('+1-1+1-1+1-1+1-1+1-1+1-1+1-1+1-1+1-1+1-1+1-1+1-1+1-1+1-1+1-1+1-1')) #=> 0
print(calc('-12+12-7979+9191')) #=> 1212


def check_score(real_answers, my_answers):
    result = 0
    for r, m in zip(real_answers, my_answers):
        result += 0 if m == "" else 4 if r == m else -1
    print(max(result, 0))
check_score(["a", "a", "b", "b"], ["a", "c", "b", "d"]) #=> 6
check_score(["a", "a", "c", "b"], ["a", "a", "b", ""]) #=> 7
check_score(["a", "a", "b", "c"], ["a", "a", "b", "c"]) #=> 16
check_score(["b", "c", "b", "a"], ["", "a", "a", "c"]) #=> 0

