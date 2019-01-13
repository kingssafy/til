get_num = 48
ex_str = " " * (get_num-1) + "*" + " "
print(ex_str)
istr = ""
mode = 1
kingssafy = 0
def str_rev(istr):
    len_istr = len(istr)
    for n in range(1,len_istr+1):
        istr += istr[len_istr-(n+1)]
    return istr        

for i in range(1, int(get_num/2)):
    
    k = i+1 #+1해줌
    is3sq = 0
    if k >= 3:
        k = k/3    
    while k >= 2:
        k = k/2
    else:
        if k == 1 :
            is3sq = 1

    kingssafy = 1
    if mode == 1:
        for str_cnt in range(get_num):
            if ex_str[str_cnt + 1] == "*" or ex_str[str_cnt - 1] == "*" :
                istr += "*"
            else:
                istr += " "
        else:
            ex_str = istr + " "
            print(str_rev(istr))
            istr = ""
            mode = 2
            continue
    
    if mode == 2:
        for str_cnt in range(get_num):
            if ex_str[str_cnt + 1] != " " or ex_str[str_cnt - 1] != " " or ex_str[str_cnt] == "*":
                istr += "*"
            else:
                istr += " "
        else:
            ex_str = istr + " "
            print(str_rev(istr))
            istr = ""
            if is3sq == 1 :  #점하나만찍는걸로 분기하자
                mode = 0 # 점1
            else:
                mode = 3 #점*****점
            continue
    
    if mode == 0:
        active = 1
        for str_cnt in range(get_num):
            if ex_str[str_cnt + 1]  == "*" and active == 1:
                istr += "*"
                active = 0
            else:
                istr += " "
        else:
            ex_str = istr + " "
            print(str_rev(istr))
            istr = ""
            mode = 1
        continue

    if mode == 3:
        active = 1
        for str_cnt in range(get_num):
            if ex_str[str_cnt + 1] == "*" and active == 1:
                istr += "*"
                active = 0
            elif ex_str[str_cnt] == " " and active == 0:
                istr += "*"
                active = 1
            else:
                istr += " "
        else:
            ex_str = istr + " "
            print(str_rev(istr))
            istr =""
            mode = 1
        continue