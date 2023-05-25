minitalk
=
- 서버와 클라이언트가 통신하는 프로그램

- 서버
        - 서버가 먼저 실행 되어야 하고 자신의 PID를 출력 해야한다.
        - 서버는 받은 문자열을 출력 해야한다.
        - 서버는 연속적으로 수신을 받을 수 있어야 한다. 
- 클라이언트
        - 클라이언트는 서버의 PID와 서버로 전송할 문자열을 인자로 갖는다.
        - 클라이언트는 인자로 들어온 문자열을 서버로 전송

- 주의 사항
        - 프로그램 끼리의 통신은 UNIX 시그널을 사용 해야한다.
        - SIGUSR1과 SIGUSR2 두 개의 시그널만 사용 해야한다.

- 시그널
        - 시그널이란 Software Interrupt로 process에 무엇인가 발생했음을 알리는 간단한 메시지를 비동기적으로 보내는 것이다. signal을 받은 프로세스는 Signal에 따른 미리 지정된 기본 동작을 수행할 수도 있고 무시하거나 특별하게 처리를 할 수도 있다.

- 허용 함수

<div align="center">
        
|함수 이름|헤더|형태|인수|반환|
|:-:|:-:|:-:|:-:|:-:|
|signal|signal.h|signal(int signum, void (*handler)(int))|시그널 번호, 핸들러 함수|핸들러 함수|
|getpid|unistd.h|pid_t getpid(void)|-|항상 성공 프로세스의 ID를 반환|
|kill|signal.h|int kill(pid_t pid, int sig)|시그널 받을 프로세스의 ID, 보내려는 시그널|pid > 0 pid로 지정한 프로세스에 시그널을 보낸다.|
|usleep|unistd.h|void sleep(unsigned long useconds|대기 마이크로 초|-|
|pause|unistd.h|int pause(void)|-|항상 -1 반환|

</div>

구현
-
- SIGUSR1과 SIGUSR2 밖에 사용하지 못하기 떄문에 SIGUSR1을 0으로 SIGUSR2를 1로 해석하여 문자의 bit를 통신하도록 구성하였다.  
- 서버를 열고 클라이언트로 signal을 보내 보면 아래 사진과 같이 SIGUSR1은 30 SIGUSR2는 31로 표현이 된다.  
<br>

<div align="center">
<img width="328" alt="image" src="https://github.com/j-yong98/42/assets/120557342/0b1dc964-560c-4c79-a94e-21e78344dca5">
</div>  

- 문자열은 char로 이루어져있으며, char형은 1byte 즉, 7bit으로 이루어져있다. 그렇기 때문에 한 char의 각 비트를 SIGUSR1(0)과 SIGUSR2(1)을 보내고 서버는 해당 시그널이 7개가 되면 한 문자를 출력하면 된다.  
- 예를 들면 'a'라는 문자는 ascii코드로 97에 해당하며 이를 이진법으로 표현하면 1100001으로 표현된다. 이것을 비트 쉬프트 연산을 통해 한 bit씩 전송하는 것이다. 앞자리를 먼저 보내기 위해서 7 - 현재 bit의 위치를 하여 쉬프트 연산을 해주었다.  
- 서버는 해당 비트 받아 전역 변수 t_message(비트 수, 문자)에 저장 후 비트 수가 한 문자를 표현하게 된다면 출력하고 초기화 해준다.  

유의 사항
-
- usleep을 하지 않고 전송 시 몇 개의 시그널이 무시 된다. 그렇기 때문에 시그널 사이에 약간의 sleep이 필요하다.  
- 정상적인 pid는 0부터 99999이다. 하지만 커널에서 사용하는 pid는 0~100까지이다. 예외 처리를 하지 않을 시 프로그램 실행 도중에 오류가 있을 수 있다.  

실행 결과
-

- 클라이언트

<div align="center">
	<img width="643" alt="image" src="https://github.com/j-yong98/42/assets/120557342/89efcbe4-d190-4214-84b2-d4ee95232cac">
</div>

- 서버

<div align="center">
	<img width="321" alt="image" src="https://github.com/j-yong98/42/assets/120557342/5d45e031-c8bd-4413-85c2-aa5a30ad088c">
</div>
