import sys
sys.stdin = open("car_input.txt")
from heapq import heappush, heapify, heappop
2
MAXT = 50000

T = int(input())
# 1 <= N, M <= 9
for tc in range(T):
    result = 0
    N, M, K, A, B = map(int, input().split())
    #N, M 접수 정비창고개수
    #K고객의수
    #지갑두고간 고객 접수창구A 정비창구B
    #고객 자료구조 (도착시간, 접수창고, 고객번호, 정비창고) default = -1
    arr = list(map(int, input().split())) #접수창고시간
    brr = list(map(int, input().split())) #정비창고시간
    rawcs = list(map(int, input().split())) #고객들
    cs = []
    for num, c in enumerate(rawcs, 1):
        cs.append((c, -1, num, -1))
    #접수 정비창고 시간array
    ata = [[0]*MAXT for _ in range(N)]
    bta = [[0]*MAXT for _ in range(M)]
    #접수다된고객들 대기queue
    drr = []
    #고객들 접수시키기
    for cus in cs:
        at, dnum, cnum, rnum = cus
        #접수창고번호얻기
        flag = 1
        while flag:
            for y in range(N):
                if not ata[y][at]:
                    dnum = y
                    flag = 0
                    break
            if not flag:
                break
            at += 1
        #접수진행
        remaintime = arr[dnum]
        while remaintime:
            remaintime -= 1
            ata[y][at] = 1 #위치중요!
            #print(*ata, sep="\n")
            at += 1
        #접수끝 -> 정비대기실로보내기
        drr.append((at, dnum, cnum, rnum))
    #정비시작하자 #고객정렬부터
    heapify(drr)
    while drr:
        at, dnum, cnum, rnum = heappop(drr)
        # 정비창고번호얻기
        flag = 1
        while flag:
            for y in range(M):
                if not bta[y][at]:
                    rnum = y
                    flag = 0
                    break
            if not flag:
                break
            at += 1
        # 접수진행
        remaintime = brr[rnum]
        while remaintime:
            remaintime -= 1
            bta[y][at] = 1  # 위치중요!
            # print(*ata, sep="\n")
            at += 1
        #결과모으기
        if dnum+1 == A and rnum +1  == B:
            result += cnum
    if not result:
        result = -1
    print("#{} {}".format(tc+1, result))