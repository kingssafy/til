dict.pop(key[, default])

if key in dict returns value that associated , if not returns default.

if you dont pass default value, will raise error

### `.update()`

- key, value 페어를 추가합니다.
- 만약 key 가 존재한다면, value 를 덮어씁니다.

### `.get(key[, default])`

key를 통해 value를 가져옵니다. 

절대로 KeyError가 발생하지 않습니다. default는 기본적으로 None입니다.

