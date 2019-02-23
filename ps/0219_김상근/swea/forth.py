import sys
sys.stdin = open('forth_input.txt')

for tc in range(int(input())):
    given = input()
    stack = []
    temp = ''
    for char in given:
        if char == ' ':
            if temp:
                stack.append(int(temp))
                temp = ''
            else:
                continue
        elif char in '1234567890':
            temp += char
            continue
        elif char == '.':
            if len(stack) == 1:
                print(f"#{tc+1} {stack[-1]}")
            else:
                print(f"#{tc+1} error")
        elif char in '+-*/' and len(stack) <2:
            print(f"#{tc+1} error")
            break

        elif char == '+': 
            stack[-2] += stack[-1]
            stack.pop()
        elif char == '-':
            stack[-2] -= stack[-1]
            stack.pop()
        elif char == '/':
            stack[-2] //= stack[-1]
            stack.pop()
        elif char == '*':
            stack[-2] *= stack[-1]
            stack.pop()
