/*
* ZY PKCS#11 Module
* Copyright(C),2016, Zhao Yang(赵洋),Beijing,P.R.China
* All rights reserved.
* @filename:  zyutility.c
* @author:  赵洋 Zhao Yang (cnrgc@163.com/sxzhaoyang@gmail.com)
* @version:  0.1
* @date:  2016.12.17
* @brief:  一些公用功能函数
*/
#include "zyutility.h"

/**
* strbpcpy() copies the source string to the destination string.
*
* If the source string has less characters than the destination string,
* the destination string is padded with blanks.
*
* @param dst       Pointer to the destinantion buffer.
* @param src       Pointer to the source buffer.
* @param dstsize   The size of the destination buffer.
*
*/
void strbpcpy(CK_CHAR *dst, const char *src, int dstsize)
{
	int c = strlen(src);
	if (c > dstsize) {
		c = dstsize;
	}
	memcpy(dst, src, c);
	memset(dst + c, ' ', dstsize - c);
}