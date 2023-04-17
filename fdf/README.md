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
- 선그리기 알고리즘
	- Bresenham 알고리즘
		- 복잡하고 느린 실수 계산을 배제하고 정수 계산으로 직선을 그리기 위한 알고리즘  
		
		직선의 방정식
		<p align='center'><img width="376" alt="image" src="https://user-images.githubusercontent.com/120557342/232446325-9cba7696-fca9-4914-b916-1846c7ff45dd.png"></p>

		픽셀의 표현
		<p align='center'><img width="620" alt="image" src="https://user-images.githubusercontent.com/120557342/232447169-02ef8a43-c069-4583-9aba-1e3827e80329.png"></p>
		
		- 컴퓨터에서 화면은 픽셀로 이루어져있고 직선은 여러 픽셀의 있을 수 있다. 왼쪽 그림처럼 직선을 표현할 때 어떤 픽셀에 표현할지 결정해 직선을 그리는 알고리즘이다.  
		
		픽셀이 오른쪽 그림처럼 이루어져있고 현재 있는 위치를 $(x_k, y_k)$라고 가정한다.<br>$x_{next}$는 $x_k$의 다음 위치이고 $y_{next}$는 $y_k$의 다음 위치이다.  
		이 때,  $x_{next}$는 $x_k + 1$ 이고 $y_{next}$는 $y_k + 1$ 과 $y_k$와의 거리 중 더 가까운 곳을 다음 $y_{next}$값으로 정하게 된다.  
		
		다음 표현할 픽셀을 $y$라고 했을 때<br>$y - y_k$를 $d_1$, $y_k + 1 - y$을 $d_2$라고 한다면 $d_1 - d_2 > 0$이면 $d_2$가 더 가깝기 때문에 $y_{next} = y_k + 1$이<br>$d_1 - d_2 < 0$라면 $y_{next} = y_k$가 된다.
		- 정리
		
		$$x_{next} = x + 1 \\ $$
		$$if,\ d_1 - d_2 > 0,\ y_{next} = y_k + 1 \\ $$
		$$if,\ d_1 - d_2 < 0,\ y_{next} = y_k$$
		
		- 픽셀 구하기  
		
		$$d_1 = y - y_k = m(x_k + 1) + c - y_k \\ $$
		$$d_2 = y_k + 1 - y = y_k + 1 - m(x_k + 1) - c \\ $$
		$$d_1 - d_2 = m(x_k + 1) + c - y_k - (y_k + 1 - m(x_k + 1) - c) \\ $$
		$$\quad = m(x_k + 1) + c - y_k - y_k - 1 + m(x_k + 1) + c \\ $$
		$$\quad = 2m(x_k + 1) - 2y_k + 2c - 1$$
		<br>
		$$\Delta x(d_1 - d_2) = 2\Delta y (x_k + 1) -2\Delta x y_k + 2\Delta x c - \Delta x \\ $$
		$$\quad = 2\Delta yx_k + 2\Delta y - 2\Delta x y_k + 2\Delta x c - \Delta x$$
		$$실제 값에 2 \Delta y x_k와 2\Delta x y_k 만 종속 되므로 나머지 값은 무시한다. \\ $$
		$$\quad\ \therefore p_k = 2 \Delta y x_k - 2\Delta x y_k \\ $$
		<br>
		$$p_{next} = 2 \Delta y x_{next} - 2\Delta x y_{next}$$
		$$p_{next} - p_k = 2\Delta y x_{next} - 2\Delta x y_{next} - (2 \Delta y x_k - 2\Delta x y_k) $$
		$$\quad = 2\Delta y x_{next} - 2\Delta x y_{next} - 2 \Delta y x_k + 2\Delta x y_k$$
		$$\quad = 2\Delta y (x_{next} - x_k) - 2\Delta x (y_{next} - y_k) $$
		
		- 정리
		
		$$if,\ p_{next} - p_k < 0$$
		$$p_{next} = p_k + 2\Delta y (x_k + 1 - x_k) - 2\Delta x (y_k - y_k)$$
		$$\quad = p_k + 2\Delta y$$
		$$if,\ p_{next} - p_k > 0$$
		$$p_{next} = p_k + 2\Delta y (x_k + 1 - x_k) - 2\Delta x (y_k + 1 - y_k)$$
		$$\quad = p_k + 2\Delta y - 2\Delta x$$
		
		- 초기값 구하기
		$$y_1 = mx_1 + c$$
		$$c = y_1 - mx_1$$
		$$\quad = y_1 - \frac{\Delta y x_1}{\Delta x}$$
		$$p_1 = 2\Delta yx_1 + 2\Delta y - 2\Delta x y_1 + 2\Delta x c - \Delta x$$
		$$\quad = 2\Delta yx_1 + 2\Delta y - 2\Delta x y_1 + 2\Delta x (y_1 - \frac{\Delta y x_1}{\Delta x}) - \Delta x$$
		$$\quad = 2\Delta yx_1 + 2\Delta y - 2\Delta x y_1 + 2\Delta x y_1 - 2\Delta yx_1 - \Delta x$$
		$$\therefore p_1 = 2\Delta y - \Delta x$$
		
		- code
		~~~
		bresenham(x1, y1, x2, y2) {
			x = x1
			y = y1
			dx = x2 - x1
			dy = y2 - y1
			p = 2 * dy - dx
			while (x <= x2) {
				draw_pixcel(x,y)
				x++
				if (p < 0)
					p += 2 * dy
				else {
					p += 2 * dy - 2 * dx
					y++;
				}
			}
		}
		~~~
