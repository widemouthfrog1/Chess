#pragma once

#include "resource.h"
//Code by zett42 on StackOverflow:
class GdiPlusInit
{
public:
	GdiPlusInit()
	{
		Gdiplus::GdiplusStartupInput startupInput;
		Status status = Gdiplus::GdiplusStartup(&m_token, &startupInput, NULL);
		// NOTE: For brevity I omitted error handling, check function return value!
	}

	~GdiPlusInit()
	{
		if (m_token)
			Gdiplus::GdiplusShutdown(m_token);
	}

	// Class is non-copyable.
	GdiPlusInit(const GdiPlusInit&) = delete;
	GdiPlusInit& operator=(const GdiPlusInit&) = delete;

private:
	ULONG_PTR m_token = 0;
};