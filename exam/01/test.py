class Word:
    def __init__(self):
        self.wordbook = {}

    def add(self, eng, kor):
        self.wordbook[eng] = kor


p = Word()

p.add("King", "Kaa")
print(p.wordbook)
