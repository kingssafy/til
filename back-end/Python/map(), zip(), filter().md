
## 정리! `map()`, `zip()`, `filter()`


### `map(function, iterable)`

ex) `list(map(함수, 리스트))`
* `map` 은 Iterable 의 요소를 지정된 함수로 처리해주는 함수

* 대표적으로 iterable한 타입 - list, dict, set, str, bytes, tuple, range

* return은 `map_object` 형태로 됩니다.

* map 은 원본을 변경하지 않고 새 값을 생성합니다.

**for 문으로 반복하면서 요소를 변환하기 어려울 때, map 을 사용하면 편리합니다.**

