T = int(input())
for _ in range(T):
    M, A = map(int, input().split())
    A_move = list(map(int, input().split()))
    B_move = list(map(int, input().split()))
    AP = [list(map(int, input().split())) for __ in range(A)]
 
    board = [[0 for ____ in range(10)] for ___ in range(10)]
    move = {0:(0,0),1:(0,-1), 2:(1,0), 3:(0,1), 4:(-1,0)} # '상, 우, 하, 좌' 순(열, 행)
 
    # A, B 위치
    A_loc = (1,1)
    B_loc = (10,10)
 
    # 출발 위치에서도 충전 가능
    A_move = [0] + A_move
    B_move = [0] + B_move
 
    answer = 0
    i = 0
    # A, B 이동
    for i in range(M+1):
        A_loc = (A_loc[0] + move[A_move[i]][0], A_loc[1] + move[A_move[i]][1])
        B_loc = (B_loc[0] + move[B_move[i]][0], B_loc[1] + move[B_move[i]][1])
 
        A_cand = set([j for j in range(A) if abs(A_loc[0] - AP[j][0]) + abs(A_loc[1] - AP[j][1]) <= AP[j][2]])
        B_cand = set([j for j in range(A) if abs(B_loc[0] - AP[j][0]) + abs(B_loc[1] - AP[j][1]) <= AP[j][2]])
 
        if len(A_cand) == 0 and len(B_cand) == 0:
            pass
        elif A_cand and B_cand:
            _sum = 0
            for p in A_cand:
                for q in B_cand:
                    if p == q:
                        temp = AP[p][3]
                    else:
                        temp = AP[p][3] + AP[q][3]
                    if temp > _sum:
                        _sum = temp
            answer += _sum
        elif B_cand:
            answer += max([AP[q][3] for q in B_cand])
        elif A_cand:
            answer += max([AP[p][3] for p in A_cand])
    print('#%d %d' %(_+1, answer))
