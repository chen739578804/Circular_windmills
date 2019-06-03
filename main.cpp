#include <iostream>
using namespace std;


//源程序如下
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define PI 3.1415926

int nNum=0,nMaxNum=20;

LRESULT CALLBACK WindowProc(
        HWND hwnd,      // handle to window
UINT uMsg,      // message identifier
        WPARAM wParam,  // first message parameter
LPARAM lParam   // second message parameter
);
int WINAPI WinMain(
        HINSTANCE hInstance,      // handle to current instance
HINSTANCE hPrevInstance,  // handle to previous instance
        LPSTR lpCmdLine,          // command line
int nCmdShow              // show state
)

{
HWND hwnd;
MSG Msg;
WNDCLASS wndclass;
wndclass.cbClsExtra=0;
wndclass.cbWndExtra=0;
wndclass.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH);
wndclass.hCursor=LoadCursor(NULL,IDC_ARROW);
wndclass.hIcon=LoadIcon(NULL,IDI_APPLICATION);
wndclass.hInstance=hInstance;
wndclass.lpfnWndProc=WindowProc;
wndclass.lpszClassName="abc";
wndclass.lpszMenuName=NULL;
wndclass.style=0;

RegisterClass(&wndclass);

hwnd=CreateWindow("abc","旋转的风车",WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,0,600,450,NULL,NULL,hInstance,NULL);

ShowWindow(hwnd,SW_SHOWNORMAL);
UpdateWindow(hwnd);

while(GetMessage(&Msg,hwnd,NULL,0))
{
TranslateMessage(&Msg);
DispatchMessage(&Msg);
}
return 0;
}

LRESULT CALLBACK WindowProc(
        HWND hwnd,      // handle to window
UINT uMsg,      // message identifier
        WPARAM wParam,  // first message parameter
LPARAM lParam   // second message parameter
)
{
HDC hdc;
HBRUSH hBrush;
HPEN hp;
PAINTSTRUCT ps;
int nCenterX,nCenterY;
double fAngle;

switch(uMsg)
{
case WM_PAINT:
hdc=BeginPaint(hwnd,&ps);
SetMapMode(hdc,MM_ANISOTROPIC);
SetWindowExtEx(hdc,400,300,NULL);
SetViewportExtEx(hdc,600,450,NULL);
SetViewportOrgEx(hdc,300,200,NULL);

//        绘制外圆
hp=CreatePen(PS_SOLID,1,RGB(255,0,255));
SelectObject(hdc,hp);
Ellipse(hdc,-100,-100,100,100);

//        绘制风车的叶片
//        绘制红色的叶片
hBrush=CreateSolidBrush(RGB(255,0,0));
SelectObject(hdc,hBrush);
fAngle=2*PI/nMaxNum*nNum;
nCenterX=(int)(50*cos(fAngle));
nCenterY=(int)(50*sin(fAngle));
Pie(hdc,nCenterX-50,nCenterY-50,nCenterX+50,nCenterY+50,(int)(nCenterX+50*cos(fAngle)),(int)(nCenterY+50*sin(fAngle)),(int)(nCenterX+50*cos(fAngle+PI)),(int)(nCenterY+50*sin(fAngle+PI)));

//        绘制蓝色的叶片
hBrush=CreateSolidBrush(RGB(255,255,0));
SelectObject(hdc,hBrush);
nCenterX=(int)(50*cos(fAngle+2*PI/3));
nCenterY=(int)(50*sin(fAngle+2*PI/3));
Pie(hdc,nCenterX-50,nCenterY-50,nCenterX+50,nCenterY+50,(int)(nCenterX+50*cos(fAngle+2*PI/3)),(int)(nCenterY+50*sin(fAngle+2*PI/3)),(int)(nCenterX+50*cos(fAngle+PI+2*PI/3)),(int)(nCenterY+50*sin(fAngle+PI+2*PI/3)));

//        绘制黄色的叶片
hBrush=CreateSolidBrush(RGB(0,255,255));
SelectObject(hdc,hBrush);
nCenterX=(int)(50*cos(fAngle+4*PI/3));
nCenterY=(int)(50*sin(fAngle+4*PI/3));
Pie(hdc,nCenterX-50,nCenterY-50,nCenterX+50,nCenterY+50,(int)(nCenterX+50*cos(fAngle+4*PI/3)),(int)(nCenterY+50*sin(fAngle+4*PI/3)),(int)(nCenterX+50*cos(fAngle+PI+4*PI/3)),(int)(nCenterY+50*sin(fAngle+PI+4*PI/3)));

nNum++;
Sleep(100);
InvalidateRect(hwnd,NULL,1);
EndPaint(hwnd,&ps);

return 0;
case WM_CLOSE:
PostQuitMessage(0);
break;
default:
return DefWindowProc(hwnd,uMsg,wParam,lParam);
}
return 0;
}









int main() {
cout << "Hello, World!" << endl;
    return 0;
}