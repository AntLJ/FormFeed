// FormFeed.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include "FormFeed.h"
#include "GetPrnDC.h"


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	static DOCINFO di = { sizeof(DOCINFO), TEXT("FormFeed") };
	HDC hdcPrint = GetPrinterDC();

	if (hdcPrint != NULL)
	{
		if (StartDoc(hdcPrint, &di) > 0)
			if (StartPage(hdcPrint) > 0 && EndPage (hdcPrint) > 0)
				EndDoc(hdcPrint);
		DeleteDC(hdcPrint);
	}
	return 0;
}

