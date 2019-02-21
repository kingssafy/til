def recurse(row, n):
    global mean
    row += 1 #choose next row 
    currentsum = sum(boards[row][column] for row, column in enumerate(answersheet[0:row])) 
    if currentsum > mean: ## put your bounding function here
        return
    if row == n: ##when you get to bottom of recursion tree
        if currentsum < mean:
            mean = currentsum
            return
    for column in range(n): #recursive part
        if column not in answersheet[:row]: #check if column is already selected! [critical][pythonic]
            answersheet[row] = column
            recurse(row, n)

boards = [[5, 2, 1, 1, 9],
        [3, 3, 8, 3, 1],
        [9, 2, 8, 8, 6],
        [1, 5, 7, 8, 3],
        [5, 5, 4, 6, 8]
        ]
n = len(boards)

answersheet = [-1] * n  #using index as a row, 
                        #value as column what you took at that row
row = -1
mean = 9999999
recurse(row, n)
print(f"the least  {mean}")
