# CSS3

## CSS사용법 

1. 태그에 직접 쓰는법
2. Embedding 내부참조
3.  따로 링크파일 만들어서 하는 법(외부에 css파일만들어서)

3번주로사용 코드의 재사용성, 모듈화

##CSS기초

프로퍼티 값의 단위

h1 {color: blue; font-size: 15px;} 는 프로퍼티마다 다르다

### em 

em은 배수단위로  상대단위이다.

요소에 지정된 사이즈(상속된 사이즈나 디폴트 사이즈)에 상대적인 사이즈를 설정한다.



## 2.4 rem

rem은 최상위 요소(html)의 사이즈를 기준으로 삼는다. em보다 rem을 더 많이쓴다

### 2.5. Viewport

상대적인단위인데 디바이스마다 다른크기를 가지고 있기 때문에사용

단위 vw :너비의 1/100

vh 높이의 1/100

vmin 너비또는 높이 중 작은쪽의 1/100

vmax  --snip-- 높은 쪽의 1/100



## 색상표현단위

HEX: #ffffff

RGB:

RGBA:투명도까지



## 박스모델

display: properties

1.block

항상 새로운 라인에서 시작.

화면크기 전체의 가로폭차지(width:100%)

block레벨 요소내에 inline 레벨 요소를 포함 할 수 있다.

div,h1등등등 li,hr,table,form등등등



2. inline

   새로운 라인에서 시작하지 않으며 문장의 중간에 들어갈 수 있다.

   content의 너비만큼 가로폭을 차지한다.

   width, height, margin-top, margin-bottom프로퍼티를 지정할 수 없다.

   상,하 여백은 line-height로 지정

   span a strong img br input select등



3. inline-block

block과 inline레벨 요소의 특징을 모두 갖는다.

inline레벨 요소처럼 한줄에 표시되면서 block에서의 width, height, margin(top, bottom)속성을 모두 지정할 수 있다.

4. None

해당요소를 화면에 표시하지 않는다.(공간조차 사라진다)



## visibility Property

1.visible

2.hidden 안보이게한다 (공간은 있음)







# css로 호박만들어보기





## position

1.static

2.상대위치(relative)

3.절대위치absolute

4.고정위치 혼자박혀있는거





static:기본값(아무것도안줬을때)

relative: static 기본값 기준에서 상하좌우로 움직인 후 원래있었던 공간은 유지됨. 

absolute: 기본 레이어 관계에서 벗어난다. (집나간 자식 붕뜬다)

즉 다른 도형들도 새로운 자리로 움직이게된다.

움직인 후 원래있었던 공간이 사라진다

부모영역을 벗어나 자유롭게 어디든 위치할 수 있다.

부모에 static 이외에 position 프로퍼티가 지정되어 있을 경우에만 부모를 기준으로 위치하게된다.

만약 부모, 조상이 모두 static이면 document body를 기준으로 위치하게 된다.

fixed:  absolute랑 동일하게 움직이지만 스크롤이 생길때 움직이지않고 고정되어있다.

TIP 부모에게 position:relative를 줘서 자식이 absolute를 받을때 기준점을 부모로 인식하도록 하는 것이 편하다.