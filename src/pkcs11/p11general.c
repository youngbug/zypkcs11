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
struct p11Context_t *context = NULL;
static CK_C_INITIALIZE_ARGS initArgs;

CK_RV p11CreateMutex(CK_VOID_PTR_PTR ppMutex)
{
	//CK_C_INITIALIZE_ARGS成员的CreateMutex和mutex.h中包含头文件的宏CreateMutex冲突了,需要undef一下
	#undef CreateMutex		
	if (initArgs.CreateMutex) {
		return (*initArgs.CreateMutex)(ppMutex);
	}
	return CKR_OK;
}


CK_RV p11DestroyMutex(CK_VOID_PTR pMutex)
{
	if (initArgs.DestroyMutex) {
		return (*initArgs.DestroyMutex)(pMutex);
	}
	return CKR_OK;
}


CK_RV p11LockMutex(CK_VOID_PTR pMutex)
{
	if (initArgs.LockMutex) {
		return (*initArgs.LockMutex)(pMutex);
	}
	return CKR_OK;
}


CK_RV p11UnlockMutex(CK_VOID_PTR pMutex)
{
	if (initArgs.UnlockMutex) {
		return (*initArgs.UnlockMutex)(pMutex);
	}
	return CKR_OK;
}

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

/**
* Determine programm calling PKCS#11 module
*/
int determineCaller()
{
	char path[1024], *p;

#ifdef _WIN32
	GetModuleFileName(NULL, path, sizeof(path) - 1);
#else
	int r;

	r = readlink("/proc/self/exe", path, sizeof(path) - 1);
	if (r < 0) 
	{

		return CALLER_UNKNOWN;
	}
	path[r] = '\0';
#endif

	if ((p = strrchr(path, '/')) || (p = strrchr(path, '\\'))) {
		p++;
	}
	else {
		p = path;
	}

	if (!strncmp("firefox", p, 7) || !strncmp("iceweasel", p, 9)) {
		return CALLER_FIREFOX;
	}

	return CALLER_UNKNOWN;
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
	//初始化Cryptoki
	if (context != NULL) 
	{
		return CKR_CRYPTOKI_ALREADY_INITIALIZED;
	}

	context = (struct p11Context_t *) calloc(1, sizeof(struct p11Context_t));

	if (context == NULL) 
	{
		return CKR_HOST_MEMORY;
	}

	rv = p11CreateMutex(&context->mutex);
	if (rv != CKR_OK)
		return CKR_OK;

	context->caller = determineCaller();

	//初始化sessionPool
	//initSessionPool(&context->sessionPool);

	//rv = initSlotPool(&context->slotPool);

	if (rv != CKR_OK) 
	{
		free(context);
		context = NULL;
		FUNC_RETURNS(rv);
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
	FUNC_CALLED();

	if (context != NULL) 
	{
		p11LockMutex(context->mutex);

		//terminateSessionPool(&context->sessionPool);
		//terminateSlotPool(&context->slotPool);

		p11UnlockMutex(context->mutex);

		p11DestroyMutex(context->mutex);

		free(context);
		context = NULL;
	}

	context = NULL;

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
