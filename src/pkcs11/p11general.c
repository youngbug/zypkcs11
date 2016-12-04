/*
* ZY PKCS#11 Module
* Copyright(C),2016, Zhao Yang(赵洋),Beijing,P.R.China
* All rights reserved.
* @filename:  p11general.c
* @author:  赵洋 Zhao Yang (cnrgc@163.com/sxzhaoyang@gmail.com)
* @version:  0.1
* @date:  2016.12.3
* @brief:  PKCS#11 接口中的一般函数 
*/
#include "p11general.h"
#include "mutex.h"

/*设置全局变量*/
static CK_C_INITIALIZE_ARGS initArgs;

static CK_RV osCreateMutex(CK_VOID_PTR_PTR ppMutex)
{
	MUTEX *m = (MUTEX *)calloc(1, sizeof(*m));
	if (m == NULL)
		return CKR_HOST_MEMORY;
	if (mutex_init(m) != 0)
		return CKR_GENERAL_ERROR;
	*ppMutex = (CK_VOID_PTR)m;
	return CKR_OK;
}

static CK_RV osDestroyMutex(CK_VOID_PTR pMutex)
{
	if (mutex_destroy((MUTEX *)pMutex) != 0)
		return CKR_GENERAL_ERROR;

	free(pMutex);
	return CKR_OK;
}

static CK_RV osLockMutex(CK_VOID_PTR pMutex)
{
	if (mutex_lock((MUTEX *)pMutex) != 0)
		return CKR_GENERAL_ERROR;

	return CKR_OK;
}

static CK_RV osUnlockMutex(CK_VOID_PTR pMutex)
{
	if (mutex_unlock((MUTEX *)pMutex) != 0)
		return CKR_GENERAL_ERROR;

	return CKR_OK;
}

/*
* Initialize the PKCS#11 function list.
*
*/
CK_FUNCTION_LIST pkcs11_function_list = {
	{ 0, 10 },			//CK_VERSION version
	C_Initialize,
	C_Finalize,
	C_GetInfo,
	C_GetFunctionList,/*
	C_GetSlotList,
	C_GetSlotInfo,
	C_GetTokenInfo,
	C_GetMechanismList,
	C_GetMechanismInfo,
	C_InitToken,
	C_InitPIN,
	C_SetPIN,
	C_OpenSession,
	C_CloseSession,
	C_CloseAllSessions,
	C_GetSessionInfo,
	C_GetOperationState,
	C_SetOperationState,
	C_Login,
	C_Logout,
	C_CreateObject,
	C_CopyObject,
	C_DestroyObject,
	C_GetObjectSize,
	C_GetAttributeValue,
	C_SetAttributeValue,
	C_FindObjectsInit,
	C_FindObjects,
	C_FindObjectsFinal,
	C_EncryptInit,
	C_Encrypt,
	C_EncryptUpdate,
	C_EncryptFinal,
	C_DecryptInit,
	C_Decrypt,
	C_DecryptUpdate,
	C_DecryptFinal,
	C_DigestInit,
	C_Digest,
	C_DigestUpdate,
	C_DigestKey,
	C_DigestFinal,
	C_SignInit,
	C_Sign,
	C_SignUpdate,
	C_SignFinal,
	C_SignRecoverInit,
	C_SignRecover,
	C_VerifyInit,
	C_Verify,
	C_VerifyUpdate,
	C_VerifyFinal,
	C_VerifyRecoverInit,
	C_VerifyRecover,
	C_DigestEncryptUpdate,
	C_DecryptDigestUpdate,
	C_SignEncryptUpdate,
	C_DecryptVerifyUpdate,
	C_GenerateKey,
	C_GenerateKeyPair,
	C_WrapKey,
	C_UnwrapKey,
	C_DeriveKey,
	C_SeedRandom,
	C_GenerateRandom,
	C_GetFunctionStatus,
	C_CancelFunction,
	C_WaitForSlotEvent*/
};


/* C_Initialize initializes the Cryptoki library. */
CK_DECLARE_FUNCTION(CK_RV, C_Initialize)
(
	CK_VOID_PTR   pInitArgs  /* if this is not NULL_PTR, it gets
							 * cast to CK_C_INITIALIZE_ARGS_PTR
							 * and dereferenced */
)
{
	int rv = CKR_OK;
	//
	memset(&initArgs, 0, sizeof(initArgs));
	//
	//如果pInitArgs传入NULL_PTR那么表示不需要多线程访问Cryptoki
	if (NULL_PTR != pInitArgs)
	{
		initArgs = *(CK_C_INITIALIZE_ARGS_PTR)pInitArgs;
		if (initArgs.pReserved != NULL_PTR)
		{
			FUNC_RETURNS(CKR_ARGUMENTS_BAD);
		}
	}
	//
	/* CK_C_INITIALIZE_ARGS中的flags的是否设置为CKF_OS_LOCKING_OK和函数指针是否提供
	 * 分为以下四种情况
	 * 1.flags没设置 函数指针==NULL_PTR  ==> 应用不需要多线程访问Cryptoki
	 * 2.flags没设置 函数指针提供		 ==> 应用必须使用提供的函数进行多线程
	 * 3.flags设置  函数指针==NULL_PTR	 ==> 应用使用系统原生的函数进行多线程
	 * 4.flags设置  函数指针提供		 ==> 应用使用系统原生的函数或者提供的函数进行多线程
	 */
	if (initArgs.flags & CKF_OS_LOCKING_OK)
	{
		#undef CreateMutex		//CK_C_INITIALIZE_ARGS成员的CreateMutex和mutex.h中包含头文件的宏CreateMutex冲突了,需要undef一下
		initArgs.CreateMutex = osCreateMutex;
		initArgs.DestroyMutex = osDestroyMutex;
		initArgs.LockMutex = osLockMutex;
		initArgs.UnlockMutex = osUnlockMutex;
	}
	//
	FUNC_RETURNS(CKR_OK);
}


/* C_Finalize indicates that an application is done with the
* Cryptoki library. */
CK_DECLARE_FUNCTION(CK_RV, C_Finalize)
(
	CK_VOID_PTR   pReserved  /* reserved.  Should be NULL_PTR */
)
{
	FUNC_RETURNS(CKR_OK);
}

/* C_GetInfo returns general information about Cryptoki. */
CK_DECLARE_FUNCTION(CK_RV, C_GetInfo)
(
	CK_INFO_PTR   pInfo  /* location that receives information */
)
{
	FUNC_RETURNS(CKR_OK);
}


/* C_GetFunctionList returns the function list. */
CK_DECLARE_FUNCTION(CK_RV, C_GetFunctionList)
(
	CK_FUNCTION_LIST_PTR_PTR ppFunctionList  /* receives pointer to
											 * function list */
)
{
	FUNC_RETURNS(CKR_OK);
}
