def bs_up(s, e, d):
    print("bs_up(",s,e,d,")")
    m = -1
    sol = -1
    while s <= e:
        m = (s+e)//2
        print(f"m = (s+e)//2")
        print(f"{m} = ({s} + {e}) // 2")
        if lotus[m] < d:
            print("lotus[m] < d")
            print(f"{lotus[m]} < {d}")
            sol = m +1
            print("sol = m+1")
            print(f"{sol} = {m} + 1")
            s = sol
        else:
            print(f"lotus[{m}] >= {d}")
            e = m-1;
            print("e = m - 1")
            print(f"{e} = {m} - 1")
    return sol; #bug exist`` when target == lotus[0]

lotus = [4,8,9,15,17,29,31] #add 0 for bug fix
print(lotus)
print(bs_up(0,len(lotus)-1, 3))
