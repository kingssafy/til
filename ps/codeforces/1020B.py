n = int(input())
students = list(map(int, input().split()))
students = students + students[:1]
answersheet = []


for i in range(1, n+1):
    if students[0] == i:
        meets = [] 
        for student in students:
           if student in meets:
               answersheet.append(student)
               break
           else:
               meets.append(student)
    else:
        meets = [i]
        for student in students:
            if student in meets:
                answersheet.append(student)
                break
            else:
                meets.append(student)
print(*answersheet)
