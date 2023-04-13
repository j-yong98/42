fdf
=
- minilibx를 이용하여 map 그리기
- minilibx(mlx)란?
	- X-window, Cocoa에 대한 지식 없이도 화면에 무언가를 그리기 위한 그래픽스 라이브러리
	```
	mac은 화면에 그래픽 액세스를 처리하지만 이에 엑세스하려면 기본 macOS 그래픽 프레임 워크에 등록을 해야한다.
	makefile 작성 시
	-framework OpenGL -framework Appkit

	실행 했을 때 파일을 찾을 수 없다 하면 아래와 같이 경로를 재지정 해준다.
	install_name_tool -change lib_name lib_path/lib_name exec_file
	```
