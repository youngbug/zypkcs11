/*
* ZY PKCS#11 Module
* Copyright(C),2016, Zhao Yang(赵洋),Beijing,P.R.China
* All rights reserved.
* @filename:  p11general.h
* @author:  赵洋 Zhao Yang (cnrgc@163.com/sxzhaoyang@gmail.com)
* @version:  0.1
* @date:  2016.12.3
* @brief:  PKCS#11 接口中的一般函数
*/

#ifndef __P11GENERIC_H_INC__
#define __P11GENERIC_H_INC__

#include "cryptoki.h"

#ifdef DEBUG
#define FUNC_CALLED() do { \
		debug("Function %s called.\n", __FUNCTION__); \
} while (0)

#define FUNC_RETURNS(rc) do { \
		debug("Function %s completes with rc=%d.\n", __FUNCTION__, (rc)); \
		return rc; \
} while (0)

#define FUNC_FAILS(rc, msg) do { \
		debug("Function %s fails with rc=%d \"%s\"\n", __FUNCTION__, (rc), (msg)); \
		return rc; \
} while (0)

#else
#define FUNC_CALLED()
#define FUNC_RETURNS(rc) return (rc)
#define FUNC_FAILS(rc, msg) return (rc)
#endif

#endif