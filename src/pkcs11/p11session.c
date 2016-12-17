/*
* ZY PKCS#11 Module
* Copyright(C),2016, Zhao Yang(赵洋),Beijing,P.R.China
* All rights reserved.
* @filename:  p11session.c
* @author:  赵洋 Zhao Yang (cnrgc@163.com/sxzhaoyang@gmail.com)
* @version:  0.1
* @date:  2016.12.17
* @brief:  PKCS#11 接口中的Session管理函数
*/
#include "p11general.h"

extern struct p11Context_t *context;


/*  C_OpenSession opens a session between an application and a
token in a particular slot. */
CK_DECLARE_FUNCTION(CK_RV, C_OpenSession)
(
	CK_SLOT_ID slotID,
	CK_FLAGS flags,
	CK_VOID_PTR pApplication,
	CK_NOTIFY Notify,
	CK_SESSION_HANDLE_PTR phSession
)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}

/*  C_CloseSession closes a session between an application and a token. */
CK_DECLARE_FUNCTION(CK_RV, C_CloseSession)
(
	CK_SESSION_HANDLE hSession
)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}

/*  C_CloseAllSessions closes all sessions an application has with a token. */
CK_DECLARE_FUNCTION(CK_RV, C_CloseAllSessions)
(
	CK_SLOT_ID slotID
)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}

/*  C_GetSessionInfo obtains information about a session. */
CK_DECLARE_FUNCTION(CK_RV, C_GetSessionInfo)
(
	CK_SESSION_HANDLE hSession,
	CK_SESSION_INFO_PTR pInfo
)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}

/*  C_GetOperationState obtains a copy of the cryptographic operations state of a session. */
CK_DECLARE_FUNCTION(CK_RV, C_GetOperationState)
(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR pOperationState,
	CK_ULONG_PTR pulOperationStateLen
)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}

/*  C_SetOperationState restores the cryptographic operations state of a session. */
CK_DECLARE_FUNCTION(CK_RV, C_SetOperationState)
(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR pOperationState,
	CK_ULONG ulOperationStateLen,
	CK_OBJECT_HANDLE hEncryptionKey,
	CK_OBJECT_HANDLE hAuthenticationKey
)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}

/*  C_Login logs a user into a token. */
CK_DECLARE_FUNCTION(CK_RV, C_Login)
(
	CK_SESSION_HANDLE hSession,
	CK_USER_TYPE userType,
	CK_UTF8CHAR_PTR pPin,
	CK_ULONG ulPinLen
)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}

/*  C_Logout logs a user out from a token. */
CK_DECLARE_FUNCTION(CK_RV, C_Logout)
(
	CK_SESSION_HANDLE hSession
)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}

