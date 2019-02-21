import sys
sys.stdin = open("calculator3.txt")

priorities = {"+":0, "*":1, "(":-1}
for tc in range(1, 11):
    a = input()
    given = input()
    nums = []
    operators = []
    stack = []
    #convert
    for char in given: 
        if char in '0123456789':
            nums.append(char)
        elif char == '(':
            operators.append(char)
        elif char == ')':
            while operators and operators[-1] != '(':
                nums.append(operators.pop())
            operators.pop()
        elif operators and priorities[char] <= priorities[operators[-1]]:
            while operators and priorities[char] <= priorities[operators[-1]]:
                nums.append(operators.pop())
            operators.append(char)
        else:
            operators.append(char)
    while operators:
        nums.append(operators.pop())

    for token in nums:
        if token == '+':
            stack[-2] += stack[-1]
            stack.pop()
        elif token == '*':
            stack[-2] *= stack[-1]
            stack.pop()
        else:
            stack.append(int(token))
    print(f"#{tc} {stack[0]}")
