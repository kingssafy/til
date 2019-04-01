dy = [1, -1, 0, 0];
dx = [0, 0, -1, 0];
import sys
sys.stdin = open("atom_input.txt");

T = int(input())
for tc in range(T):
    N = int(input())
    atoms = dict();
    for _ in range(N):
        x, y, d, k = map(int, input().split())
        atoms[(2*x, 2*y)] = [d, k]
        for time in range(2000):
            next = {};
            for coordinate, atom in atoms.items():
                nx = coordinate[0] + dx[]
