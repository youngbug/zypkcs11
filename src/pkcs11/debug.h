/*
* ZY PKCS#11 Module
* Copyright(C),2016, Zhao Yang(赵洋),Beijing,P.R.China
* All rights reserved.
* @filename:  debug.h
* @author:  赵洋 Zhao Yang (cnrgc@163.com/sxzhaoyang@gmail.com)
* @version:  0.1
* @date:  2016.12.3
* @brief:  调试函数 使用时打开宏定义 DEBUG
*/

#ifndef __DEBUG_H__
#define __DEBUG_H__

#ifdef DEBUG

void debug(char *log, ...);

#endif // DEBUG
#endif // !__DEBUG_H__

