/*
* ZY PKCS#11 Module
* Copyright(C),2016, Zhao Yang(赵洋),Beijing,P.R.China
* All rights reserved.
* @filename:  debug.c
* @author:  赵洋 Zhao Yang (cnrgc@163.com/sxzhaoyang@gmail.com)
* @version:  0.1
* @date:  2016.12.3
* @brief:  调试函数 使用时打开宏定义 DEBUG
*/
#ifdef DEBUG

#include <stdio.h>
#include <time.h>

void debug(char *format, ...)
{
	struct tm *loctim;
	time_t elapsed;
	va_list argptr;

	if ((context == NULL) || (context->debugFileHandle == NULL)) {
		return;
	}

	time(&elapsed);
	loctim = localtime(&elapsed);

	fprintf(context->debugFileHandle, "%02d.%02d.%04d %02d:%02d:%02d ",
		loctim->tm_mday,
		loctim->tm_mon,
		loctim->tm_year + 1900,
		loctim->tm_hour,
		loctim->tm_min,
		loctim->tm_sec);

	va_start(argptr, format);
	vfprintf(context->debugFileHandle, format, argptr);
	fflush(context->debugFileHandle);
	va_end(argptr);
}

#endif // DEBUG
