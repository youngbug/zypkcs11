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

#define CALLER_UNKNOWN			0
#define CALLER_FIREFOX			1

/**
* 所有可用的slot信息
*
*/
struct p11SlotPool_t {
	CK_ULONG numberOfSlots;         /**< slot池中slot数量         */
	CK_SLOT_ID nextSlotID;          /**< 分配的下一个slot ID     */
	struct p11Slot_t *list;         /**< 池中第一个slot的指针       */
};



/**
*  会话信息
*
*/
struct p11SessionPool_t {
	CK_ULONG numberOfSessions;              /**< session的数量           */
	CK_SESSION_HANDLE nextSessionHandle;    /**< 下一个分配的session的值 */
	struct p11Session_t *list;              /**< 池中的第一个session的指针      */
};

struct p11Context_t {
	CK_VERSION version;                     /**< cryptoki version       */
	CK_INFO info;                           /**< cryptoki 信息       */
	CK_HW_FEATURE_TYPE hw_feature;          /**< 硬件特征类型          */

	int caller;                             /**< 调用应用                     */
	//FILE *debugFileHandle;
	struct p11SessionPool_t sessionPool;    /**< 会话池	                            */
	struct p11SlotPool_t slotPool;          /**< 可用slot池                  */
	void *mutex;                            /**< 互斥对象    */
};

CK_RV p11CreateMutex(CK_VOID_PTR_PTR ppMutex);
CK_RV p11DestroyMutex(CK_VOID_PTR pMutex);
CK_RV p11LockMutex(CK_VOID_PTR pMutex);
CK_RV p11UnlockMutex(CK_VOID_PTR pMutex);

#endif