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

        |함수 이름|헤더|형태|인수|반환|
        |:-:|:-:|:-:|:-:|:-:|
        |signal|signal.h|signal(int signum, void (*handler)(int))|시그널 번호, 핸들러 함수|핸들러 함수|
        |getpid|unistd.h|pid_t getpid(void)|-|항상 성공 프로세스의 ID를 반환|
        |kill|signal.h|int kill(pid_t pid, int sig)|시그널 받을 프로세스의 ID, 보내려는 시그널|pid > 0 pid로 지정한 프로세스에 시그널을 보낸다.|
        |usleep|unistd.h|void sleep(unsigned long useconds|대기 마이크로 초|-|
        |pause|unistd.h|int pause(void)|-|항상 -1 반환|
