/*
*******************************************************************************
The MIT License (MIT)

Copyright (c) 2016 Daryl Dohner

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*******************************************************************************
*/
//#include <random>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
#include <windows.h>
#include <shlobj.h>
#include "gen.h"

//#define APP_DEBUG
#undef APP_DEBUG

#ifdef APP_DEBUG
#include <iostream>
#endif

LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
	switch(Message)
	{
		case WM_CREATE:
		{
			//CENTER TEXT
			int cW=250;
			int cH=30;
			int cX=(data.w/2)-(cW/2);
			int cY=data.h * 0.05;
			data.centerText=CreateWindowA("STATIC", "Options:", WS_CHILD | WS_VISIBLE | SS_CENTER, cX, cY, cW, cH, hwnd, NULL, NULL, NULL);
			SendMessage(data.centerText, WM_SETFONT, (WPARAM)Arial24BoldUnderline, TRUE);
			//FILE LOC
			int lcW=350;
			int lcH=20;
			int lcX=(data.w/2)-(lcW/2);
			int lcY=((data.h+(cY+cH))*.05)+cY;
			data.locCenterText=CreateWindowA("STATIC", "Image File Name:", WS_CHILD | WS_VISIBLE | SS_CENTER, lcX, lcY, lcW, lcH, hwnd, NULL, NULL, NULL);
			SendMessage(data.locCenterText, WM_SETFONT, (WPARAM)Arial18, TRUE);
			int lcbW=lcW;
			int lcbH=20;
			int lcbX=(data.w/2)-(lcbW/2);
			int lcbY=((data.h+(cY+cY))*0.08)+cY;
			data.locBox=CreateWindowA("EDIT", "", WS_CHILD | WS_VISIBLE | ES_CENTER | ES_AUTOHSCROLL, lcbX, lcbY, lcbW, lcbH, hwnd, NULL, NULL, NULL);
			SendMessage(data.locBox, WM_SETFONT, (WPARAM)Arial16, TRUE);
			//MARGINS
			int mcW=cW;
			int mcH=lcH;
			int mcX=(data.w/2)-(mcW/2);
			int mxY=((data.h+(cY+cH))*0.12)+cY;
			data.marginCenterText=CreateWindowA("STATIC", "Margins:", WS_CHILD | WS_VISIBLE | SS_CENTER, mcX, mxY, mcW, mcH, hwnd, NULL, NULL, NULL);
			SendMessage(data.marginCenterText, WM_SETFONT, (WPARAM)Arial18, TRUE);
			//LEFT
			int mlbcW=35;
			int mlbcH=20;
			int mlbcX=(data.w/2)-(25)-mlbcW-10;
			int mlbcY=((data.h+(cY+cH))*0.15)+cY;
			data.marginLBoxCaption=CreateWindowA("STATIC", "Left:", WS_CHILD | WS_VISIBLE | SS_CENTER, mlbcX, mlbcY, mlbcW, mlbcH, hwnd, NULL, NULL, NULL);
			SendMessage(data.marginLBoxCaption, WM_SETFONT, (WPARAM)Arial16, TRUE);
			int mlbW=50;
			int mlbH=18;
			int mlbX=mlbcX+mlbcW+5;
			int mlbY=mlbcY;
			data.marginLBox=CreateWindow("EDIT", "", WS_CHILD | WS_VISIBLE | ES_CENTER | ES_NUMBER, mlbX, mlbY, mlbW, mlbH, hwnd, NULL, NULL, NULL);
			SendMessage(data.marginLBox, WM_SETFONT, (WPARAM)Arial16, TRUE);
			int mlbsW=10;
			int mlbsH=20;
			int mlbsX=mlbX+mlbW+5;
			int mlbsY=mlbY;
			data.marginLBoxSymbol=CreateWindow("STATIC", "%", WS_CHILD | WS_VISIBLE | SS_CENTER, mlbsX, mlbsY, mlbsW, mlbsH, hwnd, NULL, NULL, NULL);
			SendMessage(data.marginLBoxSymbol, WM_SETFONT, (WPARAM)Arial16, TRUE);
			//RIGHT
			int mrbcW=mlbcW;
			int mrbcH=mlbcH;
			int mrbcX=mlbcX;
			int mrbcY=((data.h+(cY+cH))*0.18)+cY;
			data.marginRBoxCaption=CreateWindowA("STATIC", "Right:", WS_CHILD | WS_VISIBLE | SS_CENTER, mrbcX, mrbcY, mrbcW, mrbcH, hwnd, NULL, NULL, NULL);
			SendMessage(data.marginRBoxCaption, WM_SETFONT, (WPARAM)Arial16, TRUE);
			int mrbW=50;
			int mrbH=18;
			int mrbX=mrbcX+mrbcW+5;
			int mrbY=mrbcY;
			data.marginRBox=CreateWindow("EDIT", "", WS_CHILD | WS_VISIBLE | ES_CENTER | ES_NUMBER, mrbX, mrbY, mrbW, mrbH, hwnd, NULL, NULL, NULL);
			SendMessage(data.marginRBox, WM_SETFONT, (WPARAM)Arial16, TRUE);
			int mrbsW=10;
			int mrbsH=20;
			int mrbsX=mrbX+mrbW+5;
			int mrbsY=mrbY;
			data.marginRBoxSymbol=CreateWindow("STATIC", "%", WS_CHILD | WS_VISIBLE | SS_CENTER, mrbsX, mrbsY, mrbsW, mrbsH, hwnd, NULL, NULL, NULL);
			SendMessage(data.marginRBoxSymbol, WM_SETFONT, (WPARAM)Arial16, TRUE);
			//TOP
			int mtbcW=mlbcW;
			int mtbcH=mlbcH;
			int mtbcX=mlbcX;
			int mtbcY=((data.h+(cY+cH))*0.21)+cY;
			data.marginTBoxCaption=CreateWindowA("STATIC", "Top:", WS_CHILD | WS_VISIBLE | SS_CENTER, mtbcX, mtbcY, mtbcW, mtbcH, hwnd, NULL, NULL, NULL);
			SendMessage(data.marginTBoxCaption, WM_SETFONT, (WPARAM)Arial16, TRUE);
			int mtbW=50;
			int mtbH=18;
			int mtbX=mtbcX+mtbcW+5;
			int mtbY=mtbcY;
			data.marginTBox=CreateWindow("EDIT", "", WS_CHILD | WS_VISIBLE | ES_CENTER | ES_NUMBER, mtbX, mtbY, mtbW, mtbH, hwnd, NULL, NULL, NULL);
			SendMessage(data.marginTBox, WM_SETFONT, (WPARAM)Arial16, TRUE);
			int mtbsW=10;
			int mtbsH=20;
			int mtbsX=mrbX+mrbW+5;
			int mtbsY=mtbY;
			data.marginTBoxSymbol=CreateWindow("STATIC", "%", WS_CHILD | WS_VISIBLE | SS_CENTER, mtbsX, mtbsY, mtbsW, mtbsH, hwnd, NULL, NULL, NULL);
			SendMessage(data.marginTBoxSymbol, WM_SETFONT, (WPARAM)Arial16, TRUE);
			//BOTTOM
			int mbbcW=mlbcW+10;
			int mbbcH=mlbcH;
			int mbbcX=mlbcX-10;
			int mbbcY=((data.h+(cY+cH))*0.24)+cY;
			data.marginBBoxCaption=CreateWindowA("STATIC", "Bottom:", WS_CHILD | WS_VISIBLE | SS_CENTER, mbbcX, mbbcY, mbbcW, mbbcH, hwnd, NULL, NULL, NULL);
			SendMessage(data.marginBBoxCaption, WM_SETFONT, (WPARAM)Arial16, TRUE);
			int mbbW=50;
			int mbbH=18;
			int mbbX=mbbcX+mbbcW+5;
			int mbbY=mbbcY;
			data.marginBBox=CreateWindow("EDIT", "", WS_CHILD | WS_VISIBLE | ES_CENTER | ES_NUMBER, mbbX, mbbY, mbbW, mbbH, hwnd, NULL, NULL, NULL);
			SendMessage(data.marginBBox, WM_SETFONT, (WPARAM)Arial16, TRUE);
			int mbbsW=10;
			int mbbsH=20;
			int mbbsX=mbbX+mbbW+5;
			int mbbsY=mbbY;
			data.marginBBoxSymbol=CreateWindow("STATIC", "%", WS_CHILD | WS_VISIBLE | SS_CENTER, mbbsX, mbbsY, mbbsW, mbbsH, hwnd, NULL, NULL, NULL);
			SendMessage(data.marginBBoxSymbol, WM_SETFONT, (WPARAM)Arial16, TRUE);
			//FADES
			int fcW=cW;
			int fcH=lcH;
			int fcX=(data.w/2)-(mcW/2);
			int fxY=((data.h+(cY+cH))*0.28)+cY;
			data.fadeText=CreateWindowA("STATIC", "Fades:", WS_CHILD | WS_VISIBLE | SS_CENTER, fcX, fxY, fcW, fcH, hwnd, NULL, NULL, NULL);
			SendMessage(data.fadeText, WM_SETFONT, (WPARAM)Arial18, TRUE);
			//UP
			int fubcW=35;
			int fubcH=20;
			int fubcX=(data.w/2)-(25)-fubcW-10;
			int fubcY=((data.h+(cY+cH))*0.31)+cY;
			data.fadeUpCaption=CreateWindowA("STATIC", "Up:", WS_CHILD | WS_VISIBLE | SS_CENTER, fubcX, fubcY, fubcW, fubcH, hwnd, NULL, NULL, NULL);
			SendMessage(data.fadeUpCaption, WM_SETFONT, (WPARAM)Arial16, TRUE);
			int fubW=50;
			int fubH=18;
			int fubX=fubcX+fubcW+5;
			int fubY=fubcY;
			data.fadeUpBox=CreateWindow("EDIT", "", WS_CHILD | WS_VISIBLE | ES_CENTER | ES_NUMBER, fubX, fubY, fubW, fubH, hwnd, NULL, NULL, NULL);
			SendMessage(data.fadeUpBox, WM_SETFONT, (WPARAM)Arial16, TRUE);
			int fubsW=16;
			int fubsH=20;
			int fubsX=fubX+fubW+5;
			int fubsY=fubY;
			data.fadeUpSymbol=CreateWindow("STATIC", "ms", WS_CHILD | WS_VISIBLE | SS_CENTER, fubsX, fubsY, fubsW, fubsH, hwnd, NULL, NULL, NULL);
			SendMessage(data.fadeUpSymbol, WM_SETFONT, (WPARAM)Arial16, TRUE);
			//DOWN
			int fdbcW=fubcW;
			int fdbcH=fubcH;
			int fdbcX=fubcX;
			int fdbcY=((data.h+(cY+cH))*0.34)+cY;
			data.fadeDownCaption=CreateWindowA("STATIC", "Down:", WS_CHILD | WS_VISIBLE | SS_CENTER, fdbcX, fdbcY, fdbcW, fdbcH, hwnd, NULL, NULL, NULL);
			SendMessage(data.fadeDownCaption, WM_SETFONT, (WPARAM)Arial16, TRUE);
			int fdbW=50;
			int fdbH=18;
			int fdbX=fubcX+fdbcW+5;
			int fdbY=fdbcY;
			data.fadeDownBox=CreateWindow("EDIT", "", WS_CHILD | WS_VISIBLE | ES_CENTER | ES_NUMBER, fdbX, fdbY, fdbW, fdbH, hwnd, NULL, NULL, NULL);
			SendMessage(data.fadeDownBox, WM_SETFONT, (WPARAM)Arial16, TRUE);
			int fdbsW=16;
			int fdbsH=20;
			int fdbsX=fubX+fdbW+5;
			int fdbsY=fdbY;
			data.fadeDownSymbol=CreateWindow("STATIC", "ms", WS_CHILD | WS_VISIBLE | SS_CENTER, fdbsX, fdbsY, fdbsW, fdbsH, hwnd, NULL, NULL, NULL);
			SendMessage(data.fadeDownSymbol, WM_SETFONT, (WPARAM)Arial16, TRUE);
			//BUTTON
			int gbW=70;
			int gbH=20;
			int gbX=(data.w/2)-(gbW/2);
			int gbY=((data.h+(cY+cH))*0.38)+cY;
			data.GenBtn=CreateWindow("BUTTON", "Generate", WS_CHILD | WS_VISIBLE | SS_CENTER, gbX, gbY, gbW, gbH, hwnd, (HMENU) 2, NULL, NULL);
			SendMessage(data.fadeDownSymbol, WM_SETFONT, (WPARAM)Arial16, TRUE);
			break;
		}
		case WM_CTLCOLORSTATIC:
		{
			HDC hdC=(HDC)wParam;
            SetTextColor(hdC, data.textColor);
        	SetBkMode(hdC, TRANSPARENT);
           	return (LRESULT)GetStockObject(NULL_BRUSH);
			break;
		}
		case WM_CTLCOLOREDIT:
		{
   			HDC hdC=(HDC)wParam;
           	SetTextColor(hdC, data.textColor);
           	SetBkMode(hdC, TRANSPARENT);
           	RECT rect;
           	GetClientRect((HWND)lParam, &rect);
           	HBRUSH hBrush=CreateSolidBrush(data.boxColor);
           	HPEN x=CreatePen(BS_SOLID, 1, data.textColor);
           	SelectObject(hdC, hBrush);
           	SelectObject(hdC, x);
           	if((HWND)lParam==data.locBox)
           	{
           		RoundRect(hdC, (int)rect.left, (int)rect.top-2, (int)rect.right, (int)rect.bottom, 3, 3);
            }
            else
            {
            	RoundRect(hdC, (int)rect.left, (int)rect.top-4, (int)rect.right, (int)rect.bottom, 7, 7);
            }
           	DeleteObject(hBrush);
            DeleteObject(x);
           	return (LRESULT)GetStockObject(NULL_BRUSH);
    		break;
		}
		case WM_COMMAND:
		{
			switch(wParam)
			{
				case 2:
				{
					char path[201];
					char marginLeft[5];
					char marginRight[5];
					char marginTop[5];
					char marginBottom[5];
					char fadeUp[6];
					char fadeDown[6];
					GetWindowText(data.locBox, path, 200);
					GetWindowText(data.marginLBox, marginLeft, 4);
					GetWindowText(data.marginRBox, marginRight, 4);
					GetWindowText(data.marginTBox, marginTop, 4);
					GetWindowText(data.marginBBox, marginBottom, 4);
					GetWindowText(data.fadeUpBox, fadeUp, 5);
					GetWindowText(data.fadeDownBox, fadeDown, 5);
					std::stringstream path_str_pre;
					path_str_pre << path;
					std::string path_str=path_str_pre.str();
					std::size_t counter=path_str.find_first_of(" ");
					while(counter!=std::string::npos)
					{
						path_str.replace(counter, 1, "%20");
						counter=path_str.find_first_of(" ");
					}
					std::stringstream file_txt_pre;
					file_txt_pre << "	<!DOCTYPE html>\n \
										<html style = \"background-color:black;width:100%;height:100%;\">\n \
											<head>\n \
												<style>\n \
													body\n \
													{\n \
														width: 100%;\n \
														height: 85%;\n \
														background-image: url(\"" << path_str << "\");\n \
														background-position: center center;\n \
														background-repeat: no-repeat;\n \
														background-size: cover;\n \
														opacity: 0;\n \
														margin-top: " << marginTop << "%;\n \
														margin-left: " << marginLeft << "%;\n \
														margin-bottom: " << marginBottom << "%;\n \
														margin-right: " << marginRight << "%;\n \
														overflow: hidden;\n \
													}\n \
												</style>\n \
												<script>\n \
													var fIn = " << fadeUp << ";\n \
													var fOut = " << fadeDown << ";\n \
													var flash = 100;\n \
												    window.onload = function() \
													{ \
														addEventListener(\"keydown\", function(e)\n \
														    						  {\n \
																					    e = e || window.event;\n \
																						var key = e.which || e.keyCode;\n \
																						if (key === 192)\n \
																						{//tilde\n \
																						    var opacity = 0;\n \
																						    if (fIn > 0)\n \
																						    {\n \
																								var h = setInterval(function()\n \
																							                    	{ \
																												    	opacity += 0.01;\n \
																												    	document.body.style.opacity = opacity.toString();\n \
																														if (opacity >= 1)\n \
																														{\n \
																														    clearInterval(h);\n \
																														}\n \
																													}, fIn / 100);\n \
																							}\n \
																							else\n \
																							{\n \
																								var h = setTimeout(function()\n \
																													{\n \
																														document.body.style.opacity = 1;\n \
																													}, 0);\n \
																							}\n \
																				        }\n \
																						else if (key === 220)\n \
																						{//pipe\n \
																						    var opacity = 1;\n \
																						    if (fOut > 0)\n \
																						    {\n \
																								var h = setInterval(function()\n \
																								{\n \
																								    opacity -= 0.01;\n \
																									document.body.style.opacity = opacity.toString();\n \
																									if (opacity <= 0)\n \
																									{\n \
																									    clearInterval(h);\n \
																									}\n \
																								}, fOut/100);\n \
																							}\n \
																							else\n \
																							{\n \
																								var h = SetTimeout(function()\n \
																													{\n \
																														document.body.style.opacity = 1;\n \
																													})\n \
																							}\n \
																				        }\n \
																				      });\n \
													}; \n \
												</script>\n \
											</head>\n \
										<body>\n \
									</body>\n \
								</html>";
					std::string file_txt=file_txt_pre.str();
					char fpath[MAX_PATH+1];
					SHGetFolderPath(NULL,CSIDL_DESKTOPDIRECTORY | CSIDL_FLAG_CREATE, NULL, SHGFP_TYPE_CURRENT,fpath);
					//std::mt19937 generator;
					//std::uniform_int_distribution<std::mt19937::result_type> distribution(0,10000000);
					//int num = distribution(generator);
					srand(time(NULL));
					int num = rand();
					std::stringstream path_name;
					path_name << /*fpath << "\\projectorfade"*/ "projectorfade" << num << ".html";
					std::string path_name_str=path_name.str();
					HANDLE file=CreateFile(path_name_str.c_str(), GENERIC_READ | GENERIC_WRITE, 0, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);
					WriteFile(file, (LPVOID)file_txt.c_str(), file_txt.length(), NULL, NULL);
					#ifdef APP_DEBUG
					std::cout << path_name_str << "\t" << GetLastError() << "\n";
					#endif
					break;
				}
				default:
				{
						
				}
			}
			break;
		}
		case WM_DESTROY:
		{
			PostQuitMessage(0);
			break;
		}
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	#ifdef APP_DEBUG
    AllocConsole();
    freopen("CONOUT$", "w", stdout);
	#endif
	
	data.bkColor=RGB(0xDF, 0xDF, 0xDF);
	data.textColor=RGB(0x44, 0x22, 0x22);
	data.boxColor=RGB(0xBF, 0xBF, 0xBF);
	
	WNDCLASSEX wc;
	HWND hwnd;
	MSG Msg;
	memset(&wc,0,sizeof(wc));
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc;
	wc.hInstance	 = hInstance;
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = CreateSolidBrush(data.bkColor);
	wc.lpszClassName = "Main";
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION);
	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION);

	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}
	
    WindInfo metrics=GetMetrics();
    WindInfo t_metrics=GetTaskMetrics();
    data.x=300;
    data.y=0;
    data.w=metrics.x-(data.x*2);
    data.h=metrics.y-t_metrics.y;
    
	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"Main","Projector Fade Generator ",WS_VISIBLE|WS_OVERLAPPEDWINDOW,
		data.x, /* x */
		data.y, /* y */
		data.w, /* width */
		data.h, /* height */
		NULL,NULL,hInstance,NULL);

	if(hwnd == NULL)
	{
		MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	while(GetMessage(&Msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
	return Msg.wParam;
}
