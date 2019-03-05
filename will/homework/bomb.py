import sys
sys.stdin = open("bomb_input.txt")
K = int(input())
N = int(input())

def bomb(person, remaining_time, remaining_rounds):
   T, Z = input().split()
   T = int(T)
   remaining_time = remaining_time-T
   if remaining_time < 0 or remaining_rounds == 0:
       return person+1
   if Z == "T":
       return bomb((person+1)%8, remaining_time, remaining_rounds-1)
   return bomb(person, remaining_time, remaining_rounds-1)

print(bomb(K-1, 210, N))
