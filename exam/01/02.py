# 파일명 변경 금지
# 아래에 클래스를 Point와 Rectangle을 선언하세요.
class Point():
    #인스턴트생성될떄 x좌표값과 y좌표값 생성
    def __init__(self, x, y):
        self.x = x #이때 int만들어옴
        self.y = y

    #생성자를 제외한 메서트는없다

class Rectangle():

    def __init__(self, p1, p2):
        self.p1 = p1 #좌측상단
        self.p2 = p2 #우측하단 point클래스의 인스턴스

    def get_area(self):
        #면적을 계산하여 return
        x_length = self.p2.x - self.p1.x
        y_length = self.p1.y - self.p2.y
        return x_length * y_length

    def get_perimeter(self):
        #둘레를 반환합니다!!
        x_length = self.p2.x - self.p1.x
        y_length = self.p1.y - self.p2.y
        return (x_length + y_length)*2


    def is_square(self):
        #정사각형이면 TRUe아니면 FALSE리턴
        x_length = self.p2.x - self.p1.x
        y_length = self.p1.y - self.p2.y
        return x_length == y_length






# 아래의 코드는 수정하지마세요. 
if __name__ == '__main__':
    p1 = Point(1, 3)
    p2 = Point(3, 1)
    r1 = Rectangle(p1, p2)
    print(r1.get_area())
    print(r1.get_perimeter())
    print(r1.is_square())
    p3 = Point(2, 5)
    p4 = Point(8, 3)
    r2 = Rectangle(p3, p4)
    print(r2.get_area())
    print(r2.get_perimeter())
    print(r2.is_square())
