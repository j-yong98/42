ft_printf
=
- malloc, free, write, va_start, va_arg, va_end를 사용하여 printf의 %c, %s, %d, %i, %p, %x, %X를 구현하기
- 가번인자
  - 가변인자는 인자의 개수에 상관없이 원하는 결과를 도출하기 위해 사용한다.
  - c에는 <stdarg.h>에 정의 되어 있다.
  - 선언
    - 가변 인자는 몇 개를 사용할지 모르기 때문에 한 개이상의 고정 인자와 ...을 사용하여 선언한다.
    ~~~
    void  test(int a, ...) 
    ~~~
  - va_list
    - 길이가 변할 수 있는 가변인자를 담을 수 있는 공간이다.
  - va_start
    - va_list를 가변인자의 첫번 째 주소로 설정해 주는 매크로 함수이다.
    ~~~
    #define va_start(ap, v) ( (ap) = (va_list)_ADDRESSOF(v) + _INTSIZEOF(v)
    ~~~
  - va_arg
    - va_list의 포인터를 다음 가변 인자의 주소로 옮겨주는 매크로 함수
    ~~~
    #define va_arg(ap, t) (*(t *) ((ap += _INTSIZEOF(t)) - _INTSIZEOF(T))
    ~~~
  - va_end
    - va_list를 널 값으로 초기화 해주는 매크로 함수
    ~~~
    #define va_end(ap) (ap = (va_list)0);
    ~~~
- 구성
  - printf는 ""의 문자열과 그 뒤에 가변 인자를 사용한다. 이후 출력한 문자의 개수를 return 한다. 오류 시 -1 반환
  - int ft_printf(const char *str, ...);
  - 해당 문자열을 하나씩 읽다가 %를 만나면 뒤에 타입과 함께 가변인자를 가져와 출력한다.
- 결과
<div align='center'>
<img width="1077" alt="image" src="https://user-images.githubusercontent.com/120557342/236808116-148854ea-8eec-4029-9e19-5f84297b7b74.png">
<img width="508" alt="image" src="https://user-images.githubusercontent.com/120557342/236808163-6150be9b-9201-450a-9162-fcbeab7a795f.png">

</div>
