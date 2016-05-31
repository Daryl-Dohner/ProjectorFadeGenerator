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

#ifndef GEN_H
#define GEN_H

struct WindInfo
{
	int x;
	int y;
};

struct AppData
{
	int x;
	int y;
	int w;
	int h;
	COLORREF bkColor;
	COLORREF textColor;
	COLORREF boxColor;
	HWND centerText;
	HWND locCenterText;
	HWND locBox;
	HWND marginCenterText;
	HWND marginLBox;
	HWND marginLBoxCaption;
	HWND marginLBoxSymbol;
	HWND marginRBox;
	HWND marginRBoxCaption;
	HWND marginRBoxSymbol;
	HWND marginTBox;
	HWND marginTBoxCaption;
	HWND marginTBoxSymbol;
	HWND marginBBox;
	HWND marginBBoxCaption;
	HWND marginBBoxSymbol;
	HWND fadeText;
	HWND fadeUpBox;
	HWND fadeUpCaption;
	HWND fadeUpSymbol;
	HWND fadeDownBox;
	HWND fadeDownCaption;
	HWND fadeDownSymbol;
	HWND GenBtn;
};

AppData data;

HFONT Arial24BoldUnderline = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 1, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arial");
HFONT Arial24Bold = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arial");
HFONT Arial20Bold = CreateFont(20, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arial");
HFONT Arial18     = CreateFont(18, 0, 0, 0, FW_NORMAL, 0, 0, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arial");
HFONT Arial16     = CreateFont(16, 0, 0, 0, FW_NORMAL, 0, 0, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arial");

WindInfo GetMetrics()
{
	WindInfo wi;
	wi.x=GetSystemMetrics(SM_CXSCREEN);
	wi.y=GetSystemMetrics(SM_CYSCREEN);
	return wi;
}
WindInfo GetTaskMetrics()
{
	RECT rect;
    HWND taskBar = FindWindowA("Shell_traywnd", NULL);
    if(taskBar && GetWindowRect(taskBar, &rect))
	{
		WindInfo wi;
		wi.x=rect.right-rect.left;
		wi.y=rect.bottom-rect.top;
        return wi;
    }
}
    
#endif
