get_next_line
=
- get_next_line은 fd(file Descriptor)를 인자로 받아 해당 fd를 개행까지 읽는 기능을 한다. 개행이 없다면 파일 끝까지 읽는다.
- 변수의 종류
  - local variable
    - 함수 내에서만 사용이 가능하다.
    - 함수가 시작 될 때 메모리가 할당되고 종료 시 메모리가 해제 된다.
    - 스택 영역에 저장되며 함수가 끝나면 삭제 된다.
  - global variable
    - 어디에서나 쓸 수 있다.
    - 프로그램이 시작 될 때 메모리가 할당 되고 프로그램이 종료 시 메모리가 해제 된다.
    - 컴파일 시점에 메모리가 데이터 영역에 할당 된다.
    - 프로그램이 종료할 때까지 값이 유지 된다.
  - static variable
    - 특정 함수 내에서만 사용가능하다.
    - 컴파일 시점에 메모리가 데이터 영역에 할당 된다.
    - 프로그램이 종료 될 때까지 값이 유지 된다.
- 구성
  1. static으로 선언된 buffer 변수에 fd의 내용을 buffer_size만큼 읽는다.
  2. buffer의 내용을 확인하며 새로운 변수에 넣어 준다. 
    1. 개행이 발견 되면 해당 개행까지 담은 변수를 반환한다.
    2. 개행 혹은 파일을 끝까지 읽을 때까지 해당 fd를 계속 read 해준다.
  3. 이후 함수 재호출 시 버퍼의 내용을 먼저 확인하여 안에 개행이 있는지 확인한다.
    1. 개행이 있다면 해당 내용을 반환한다.
    2. 새로운 변수에 buffer의 모든 내용을 담아준 뒤 다시 buffer에 buffer_size만큼 읽는다.
  4. 위의 과정을 반복
  
- 구현 시 유의 사항
  - 함수를 계속 호출하기 때문에 처음이 아니라면 버퍼의 내용을 우선적으로 확인하여야 한다.
  - malloc함수의 할당 실패와 read함수의 에러 처리 및 버퍼와 반환할 char *에 null 유의
  - 에러 시 내용을 담던 동적 변수의 메모리 해제 확인
  
- 결과
  <div align='center'>
  <img width="576" alt="image" src="https://user-images.githubusercontent.com/120557342/236816599-0cf90d4b-ec5e-4f04-a703-436047e4bde3.png">
  <img width="617" alt="image" src="https://user-images.githubusercontent.com/120557342/236816669-d72c615d-4b72-4672-b14b-42bf9a6922a2.png">
  </div>
