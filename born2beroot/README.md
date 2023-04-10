Born2beRoot
=
LVM (Logical Volume Manager)
-
  - LVM은 리눅스의 저장 공간을 효율적이고 유연하게 관리하기 위한 커널의 한 부분이다.
  - 여러 개의 하드 드라이브 또는 파티션을 하나의 논리적 블록으로 합칠 수 있다.
  - 장점
    - 유연한 용량 변경
    - 크기 조절이 가능한 스토리지 pool
    - disk striping, mirror volume 등 제공  
  ```
  - 일반 Disk Partitioning과의 차이점
    - 기존 방식의 경우, 하드디스크를 파티셔닝 한 후 OS 영역에 마운트하여 read/write를 수행 하였다.
    - 이 경우 크기가 고정적이기 때문에 증설/축소가 어렵다.
    - 반면, LVM은 파티션 대신에 volume이라는 단위로 저장 장치를 다룬다.
    - LVM은 스토리지 확장과 변경에 유연하고 크기를 변경할 때 데이터의 이전이 필요 없다.
  ```
  ```
  - Disk Striping
    - 성능 향상을 위해 단일 파일과 같은 논리적으로 연속된 데이터 세그먼트들이, 물리적으로 여러 개의 장치 나뉘어 기록될 수 있는 것이다.
    - 데이터가 여러 개의 드라이브에 걸쳐 일정 크기의 바이트 또는 섹터별로 나뉘어 기록된다.
  - Mirror Volume
    - Mirror Volume은 두 개이상의 물리적 디스크에 데이터를 복제하는 내결합성 불륨입니다.
    - 데이터를 한 곳에 저장하는 것이 아닌 다른 하나의 저장 매체에 같은 내용을 중복 저장하게 되면서 하나의 디스크에 오류가 나도 다른 디스크로 사용이 가능하며 원본 자체가 존재하기 때문에 복원력은 최고이다.
    - 하지만 같은 데이터를 중복 저장하기 때문에 용량의 낭비가 심하다.
  ```
~~~
LVM 관련 용어
- 물리적 불륨(PV, Physical Volume)
  - 실제 디스크 장치를 분할한 파티션 된 상태를 의미한다.
  - PV는 일정한 크기의 PE로 구성된다.
- 물리적 확장(PE, Physical Extent)
  - PV를 구성하는 일정한 크기의 Block
  - 보통 1PE는 4MB에 해당
  - PE와 LE는 1:1 대응
- 불륨 그룹(VG, Volume Group)
  - 물리적인 디스크의 크기와 수에 따라 유연하게 조정되며, 물리적인 디스크 파티션의 크기와 관계 없이 논리적인 불륨 생성이 가능하다.
- 논리적 불륨(LV, Logical Volume)
  - LVM에서 생성된 가상 디스크로, Volume Grop에서 논리적인 공간을 차지한다
  - VG에서 공간을 할당 받아, 블록 디바이스로 구성됩니다.
  - LV를 생산하면 물리적인 디스크 파티션의 수에 구애받지 않고 필요한 만큼 논리적인 공간을 할당 할 수 있다.
~~~
apt와 aptitude
-
- 두 개 모두 패키지 관리 도구
- apt
  - apt는 기본적으로 제공되는 고급 패키지 관리 도구
  - apt는 빠르고 사용자 친화적
  - 소프트웨어 패키지를 설치, 삭제, 업데이트 하는데 사용 되며 의존성 문제를 자동으로 처리한다.
- aptitude
  - debian에서 사용 가능한 고급 패키지 관리자
  - apt와 비슷한 기능을 제공하지만 좀 더 강력한 의존성 처리 기능과 사용자 친화적 인터페이스 제공
  - 사용자가 설치하려는 패키지와 다른 패키지를 자동으로 처리하며, 패키지 의존성 문제를 처리하는데 좀 더 뛰어난 기능 제공
- apt는 단순하고 빠른 패키지 관리를 위한 유틸리티이고, aptitude는 조금 더 복잡한 패키지 관리 및 의존성 처리를 위한 유틸리티.  

SElinux와 AppArmor
-
- SElinux와 AppArmor는 모두 Linux에서 Mandatory Access Control을 구현하기 위한 보안 프레임워크
- SElinux
  - 각 프로세스 및 파일에 대한 보안 정책을 적용하여 보안 위협으로부터 보호한다.
  - SElinux는 파일 및 디렉토리, 네트워크 및 프로세스 보안을 구현
  - SElinux는 정책 구문 분석 및 정책 구현을 수행하므로, 고급 보안 요구 사항에 적합 하지만, 복잡한 구현이 필요하고 응용프로그램이 원하는대로 작동하지 않을 수도 있다.
- AppArmor
  - AppArmor는 각 응용 프로그램에 대한 보안 프로파일을 만들어 실행 중 프로그램이 할 수 있는 동작을 제한한다.
  - AppArmor는 SElinux 보다 적극적이진 않지만, 간단한 구성과 응용 프로그램이 작동하는데 더 많은 유연성 제공
  
그룹설정
-
- 사용자를 user42와 sudo 그룹에 포함시켜라
- gpasswd
  - /etc/group과 /etc/gshadow를 관리하는 명령어
  - 옵션
    - a <사용자> <그룹>
      - 사용자를 그룹에 추가
    - d <사용자> <그룹>
      - 사용자를 그룹에서 제거
- usermod
  - usermod는 사용자 계정의 속성을 변경하는데 사용하는 명령어
  - option
    - aG <그룹> <사용자>
      - 사용자를 그룹에 추가
- useradd
  - useradd는 새로운 사용자를 추가하는 명령어
  - useradd <username> 후 passwd <username>을 통해 비밀번호를 설정해주어야 로그인이 가능하다.
- id <사용자>를 통해 사용자가 속한 그룹을 확인할 수 있다.
  
ssh와 ufw
-
- ssh
  - 네트워크 프로토콜 중 하나로, 안전하게 통신할 수 있게 암호화된 연결을 제공한다.
  - 서버 인증
    - 클라이언트는 서버로 요청을 보내게 되면 서버에서 자신의 공개키를 전송한다.
    - 최초 접속 시, 서버의 공개키를 저장할 것인지 묻게 된다. -> 저장 시 known_hosts에 저장된다.
    - 이후에 접속 시 로컬에 저장된 공개키가 서버의 공개키와 같은지 비교하여 올바른 서버인지 판단.
    - 이 과정에서 데이터 통신과정에 필요한 대칭키를 생성
      - 클라이언트는 서버의 공개키로 난수 값을 생성하여 전송
      - 서버가 공개키로 해시값을 얻은 후 클라이언트로 전송
      - 클라이언트는 전송 받은 결과와 비교하여 올바른 값이면 정상적인 서버로 판단
  - 사용자 인증
    - 서버 인증과 원리는 같지만 서버와 클라이언트가 바뀐다.
    - 서버에 클라이언트의 공개키를 보낸다.
    - 서버는 받은 공개키로 난수를 발생시키고 해시값을 만들어 저장
    - 난수를 클라이언트에 전송.
    - 난수를 비밀키로 복호화 후 해시값을 얻고 서버에 전송
    - 서버는 해시값을 비교해 정상적인 사용자인지 판단.
 - 가상 머신 포트 포워딩
    - 포트 포워딩 : 포트를 전달해 주는 것. 가상 머신의 네트워크 주소와 실제 네트워크 주소가 다르기 때문에 가상 머신으로 연결해 주어야 한다.
    <img width="1282" alt="image" src="https://user-images.githubusercontent.com/120557342/230057556-e039c468-3fd5-4dc6-b7f1-518cd91bebe9.png">
    <img width="1282" alt="image" src="https://user-images.githubusercontent.com/120557342/230057678-7df3135f-b5a4-48b0-a7bc-6ffefaf5277d.png">
    - DHCP로 동적으로 IP주소 및 서브넷 마스크 및 기본 게이트 웨이를 설정해주기 때문에 호스트 IP와 게스트 IP는 설정하지 않고 포트만 설정해 주었다.
    - virtualBox의 네트워크 설정
    
      ||게스트->호스트|게스트<-호스트|게스트1<->게스트2|게스트->인터넷|게스트<-인터넷|
      |---|---|---|---|---|---|
      |호스트 전용 어댑터|O|O|O|X|X|
      |내부  네트워크|X|X|O|X|X|
      |브릿지 네트워크|O|O|O|O|O|
      |NAT|X|포트 포워딩|X|O|포트 포워딩|
      |NAT 네트워크|X|포트 포워딩|O|O|포트 포워딩|
    ```
    DHCP : TCP/IP 프로토콜의 기본 설정을 클라이언트에게 자동으로 제공해주는 프로토콜
    NAT은 DHCP로 ip
    ```
- ufw
  - 방화벽으로 특정 포트나 ip에 대해 접근을 허용/거부 가능
  
암호 정책
-
- chage
  - 사용자 계정의 암호 만료 정보를 수정하는 데 사용
  - 시스템 관리자는 최대 및 최소 암호 사용 기간, 암호 만료 경고 기간 및 너무 많은 로그인 시도 후 계정 잠금 등 다양한 암호 정책 설정을 변경할 수 있다.
  - 옵션
    - d <날짜>
      - 계정의 마지막 암호 변경일을 날짜 이전으로 설정
    - E <만료 날짜>
      - 계정의 만료 날짜를 만료 날짜로 설정
    - I <비활성화 기간>
      - 계정이 비활성화 되는 기간을 비활성화 기간으로 설정
    - m <최소 일수>
      - 암호를 변경할 수 있는 최소 일수를 최소 일수로 설정
    - M <최대 일수>
      - 암호를 변경해야 하는 최대 일수를 최대 일수로 설정
    - W <날짜>
      - 암호 만료 경고를 발생시키는 일수를 날짜로 설정
  
  설정 관련
  -
    - /etc/login.defs
      - pass_max_days, pass_min_days 변경으로 사용자 암호 만료 정보 수정
    - libpam-cracklib
      - libpam-cracklib는 debian에서 사용자 암호를 검증하는데 사용하는 모듈
      1.  libpam-cracklib 설치 (sudo apt-get install libpam-cracklib)
      2.  /etc/pam.d/common-passwd 파일을 편집
          - minlen, ucredit, lcredit, dcredit, ocredit은 각각 대문자 소문자 숫자 특수 문자를 지정
          - maxrepeat : 최대 같은 문자 반복횟수 지정, reject_username
    - pam(pluggable Authentication Module: 착탈형 인증 모듈)
      - 사용자를 인증하고 그 사용자의 서비스에 대한 엑세스를 제어하는 모듈화된 기법.
      - [PAM?](https://www.igloo.co.kr/security-information/%EB%A6%AC%EB%88%85%EC%8A%A4-pam-%EB%AA%A8%EB%93%88%EC%9D%98-%EC%9D%B4%ED%95%B4/)
      
sudo 정책
-
- sudo를 사용하게 되면 일반 사용자가 일시적으로 root의 권한을 얻게 된다.
- sudo에 관련 설정은 /etc/sudoers 파일에 하면 된다.
- Defaults는 기본적으로 sudo를 실행할 때 적용되는 전역적인 설정을 하는 옵션
- badbass_message, authfail_message, requiretty, passwd_tries, logfile=경로, log_input, log_output 등 다양한 옵션이 있다.  
```
tty란?
terminaltyepwriter의 약자로 리눅스 디바이스 드라이브 중 터미널이나 콘솔을 의미한다.
명령어를 입력하고 결과를 출력하기 위한 콘솔 세션을 의미하고 다른 tty와 별도의 프로세스 그룹을 가지고 있다.
```

monitoring.sh
-
- 운영체제와 커널의 버전에 대한 구조
  - uname 명령어를 사용하면 시스템에 대한 정보 출력
- 물리 프로세서의 수
  - nproc을 사용
- 가상 프로세서의 수
  - /proc/cpuinfo에서 관련 정보 출력
- RAM 사용률
  - free 명령어를 사용하면 메모리의 사용에 대한 정보가 나온다
- disk 사용률
  - df 명령어를 사용하면 disk에 대한 정보가 나온다. -B옵션을 통해 출력 단위를 설정할 수 있다.
- cpu 사용률
  - apt-get install sysstat을 설치 후 mpstat 명령어를 사용하면 현재 cpu의 사용률이 나온다. 이 외에 top 명령어 등이 있다.
- 마지막 부팅시간
  - who 명령어를 사용 시 현재 로그인된 사용자의 정보가 나온다. -b 옵션을 주게 되면 최근 부팅 시간에 대한 정보가 나온다
- lvm 활성화 여부
  - lsblk 명령어를 통해 파티션의 정보를 가지고 lvm이 있으면 yes를 출력하도록 했다.
  ```
  쉘 스크립트 if 사용법 (대괄호 뒤에 공백을 넣어 줘야한다.
  if [ (비교문) ]; then
  ~~
  else
  ~~
  fi
  ```
- tcp를 사용해 서버를 사용하는 유저 수
  - ss 명령어를 사용하게 되면 소켓에 관련된 정보가 나오게 된다. 이 중에 tcp관련 소켓만 보려면 -t옵션을 주면 된다.
- 서버의 IPv4와 mac주소
  - hostname -I를 사용하게 되면 현재 서버의 ip주소를 얻을 수 있다.
  - mac 주소는 ip 명령어를 사용
- sudo 프로그램으로 실행된 명령의 수
  - journalctl 명령어를 사용하면 현재 system의 로그 정보를 얻을 수 있다.
  - journalctl 명령어를 사용해 _COMM=sudo or /usr/bin/sudo sudo를 사용한 부분만 가져온다.
  
- 해당 쉘 스크립트를 주기적으로 실행하기 위해 작업 예약 스케줄러 cron을 사용
- cron -e 에 * * * * * <동작>  
   min/hour/day of month/month/day of week
   
보너스
-
- 자신만의 웹 서비스 구축하기(wordpress, lighttpd, mariadb, php 사용)
- lighttpd : 경량형 웹서버 (설치전 아파치 확인- 충돌 일어날 수 있음.) /etc/lighttpd/
  ~~~
  sudo apt install lighttpd
  sudo systemctl start lighttpd
  sudo systemctl enable lighttpd
  sudo ufw allow http
  ~~~
- mariadb : 오픈 소스 DBMS. MySql과 동일한 소스 코드
  ~~~
  sudo apt install mariadb-server
  sudo systemctl start mariadb
  sudo systemctl enable mariadb
  sudo mysql_secure_installation (mysql 기본 보안 설정(익명 사용자, 루트 비밀번호 등)
  sudo systemctl restart mariadb
  -- 이후 루트 계정으로 DB로그인 후 user(관리자)를 생성하고 권한을 설정
  mysql -u root -p
  create database wordpress;
  create user 'admin'@'localhost' identified by 'password'
  grant all on wordpress.* to 'admin'@'localhost' identified by 'password' with grant option;
  flush privileges (변경 사항을 적용하기, grant table을 reload한다함)
  ~~~
- php : 서버 사이드 스크립트 언어
  ~~~
  sudo apt install php
  @php ver7.4
  ~~~
- wordpress : 콘텐츠 관리 시스템
- /etc/lighttpd/lighttpd.conf 파일을 열어보면 document/root가 /var/www/html로 설정 되어 있다.
  ~~~
  wget http://wordpress.org/latest.tar.gz 
  tar -xvzf latest.tar.gz
  sudo mv wordpress/* /var/www/html/
  ~~~
  아래 사진과 같이 wp-config-sample.php의 db정보 부분을 위에서 설정한 것으로 변경한 후 이름을 wp-config.php로 변경
  ![image](https://user-images.githubusercontent.com/120557342/230721582-6ec1f45e-297d-4396-91b1-fb0cd8b52f80.png)  
  403 forbbiden시 확인 사항 - 웹서버의 권한 설정
  ~~~
  //권한 설정
  sudo chown -R www-data:www-data /var/www/html
  sudo chmod 755 /var/www/html
  sudo systemctl restart lighttpd
  //php cgi 패키지 설치
  sudo apt-get install php-cgi
  sudo lighttpd-enable-mod fastcgi-php
  ***
  cgi란?
  cgi(common-gateway-interface)로 웹서버와 외부 프로그램간의 인터페이스로 웹서버에 요청이 오면 해당 요청을 처리하기 위해 웹서버는 cgi를 실행하여 웹서버와 표준 입출력, 환경변수 및 기타 파일 디스크립터를 통해 통신을 하게 된다. 이렇게 생성된 결과를 반환한다.
  ***
  ~~~
  localhost:8080 or ip:8080
  이후 접속하면 설정 페이지가 나오게 된다.
  ![image](https://user-images.githubusercontent.com/120557342/230721814-35e15caa-62c3-4067-8bf5-7f9fab95fc77.png)
