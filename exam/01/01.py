# 파일명 변경 금지
# 아래에 클래스 Word를 선언하세요.
class Word():
    def __init__(self):
        self.wordbook = {} 

    def add(self, eng, kor):
        #인자 영문,한글
        #영문key 한글value로 추가
        self.wordbook[eng]=kor
        #return 없음
    def delete(self, eng):
        #인자 영문
        #wordbook 딕셔너리키에 해당 영문없으면 False반환!!
        # something in dictionary 구문은 딕셔너리 키만 검사함!!
        #not eng in , eng not in 둘다사용가능 
        if eng not in self.wordbook:
            return False
        #해당영문이 있으면 wordbook딕셔너리에서 삭제하고 True반환
        else:
            self.wordbook.pop(eng)
            return True

    def print(self):
        for key, value in self.wordbook.items():
            print(f"{key}: {value}")





# 아래의 코드는 수정하지마세요. 
if __name__ == '__main__':
    my_book = Word()
    my_book.add('apple', '사과')
    my_book.add('banana', '바나나')
    my_book.add('cherry', '체리')
    my_book.add('durian', '두리안')
    my_book.print() 
    print(my_book.delete('cherry'))
    print(my_book.delete('durian'))
    print(my_book.delete('egg'))
    my_book.print()
