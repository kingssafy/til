# 파일명 변경 금지
def alphabet_mode(word):
    # 아래에 코드를 작성하시오.
    # word는 소문자로만 구성 되어있습니다.
    # word에서 가장 많이 발생한 알파벳 하나를 반환합니다.
    
    #문자열 갯수가 동일 할 때에는 가장 먼저 나타난 문자를 반환합니다!!

    #문자별 등장횟수를 카운트할 count_dict입니다
    count_dict = {}
    for char in word:
        if char in count_dict:
            count_dict[char] += 1
        else:
            count_dict[char] = 1
    # ****파이썬 3.6에선 딕셔너리는 먼저입력한 순서대로의 순서가 유지됩니다.
    #따라서 카운트 딕셔너리에서 values()에서 맥스값을 찾아서
    #카운트 딕셔너리를 이터레이트하면서 먼저 밸류가 맥스값과 같은애를 리턴하면
    #문자열 갯수가 동일할때에는 가장 먼저 나타난 문자를 반환하게됩니다.
    target_value = max(count_dict.values())
    for key, value in count_dict.items():
        if value == target_value:
            return key

    




# 아래의 코드는 수정하지마세요. 
if __name__ == '__main__':
    print(alphabet_mode('hello'))
    print(alphabet_mode('internationalization'))
    print(alphabet_mode('haha'))