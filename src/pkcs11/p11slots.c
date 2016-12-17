/*
* ZY PKCS#11 Module
* Copyright(C),2016, Zhao Yang(赵洋),Beijing,P.R.China
* All rights reserved.
* @filename:  p11slots.c
* @author:  赵洋 Zhao Yang (cnrgc@163.com/sxzhaoyang@gmail.com)
* @version:  0.1
* @date:  2016.12.17
* @brief:  PKCS#11 接口中的Slot和Token管理函数
*/
#include "p11general.h"


extern struct p11Context_t *context;

/*  C_GetSlotList obtains a list of slots in the system. */
CK_DECLARE_FUNCTION(CK_RV, C_GetSlotList)
(
	CK_BBOOL tokenPresent,
	CK_SLOT_ID_PTR pSlotList,
	CK_ULONG_PTR pulCount
)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}

/*  C_GetSlotInfo obtains information about a particular slot. */
CK_DECLARE_FUNCTION(CK_RV, C_GetSlotInfo)
(
	CK_SLOT_ID slotID,
	CK_SLOT_INFO_PTR pInfo
)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}

/*  C_GetTokenInfo obtains information about a particular token in the system. */
CK_DECLARE_FUNCTION(CK_RV, C_GetTokenInfo)
(
	CK_SLOT_ID slotID,
	CK_TOKEN_INFO_PTR pInfo
)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}

/*  C_WaitForSlotEvent waits for a slot event to occur. */
CK_DECLARE_FUNCTION(CK_RV, C_WaitForSlotEvent)
(
	CK_FLAGS flags,
	CK_SLOT_ID_PTR pSlot,
	CK_VOID_PTR pReserved
)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}

/*  C_GetMechanismList obtains a list of mechanisms supported by a token. */
CK_DECLARE_FUNCTION(CK_RV, C_GetMechanismList)(
	CK_SLOT_ID slotID,
	CK_MECHANISM_TYPE_PTR pMechanismList,
	CK_ULONG_PTR pulCount
	)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}

/*  C_GetMechanismInfo obtains information about a particular mechanism
supported by a token. */
CK_DECLARE_FUNCTION(CK_RV, C_GetMechanismInfo)(
	CK_SLOT_ID slotID,
	CK_MECHANISM_TYPE type,
	CK_MECHANISM_INFO_PTR pInfo
)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}

/*  C_InitToken initializes a token. */
CK_DECLARE_FUNCTION(CK_RV, C_InitToken)(
	CK_SLOT_ID slotID,
	CK_UTF8CHAR_PTR pPin,
	CK_ULONG ulPinLen,
	CK_UTF8CHAR_PTR pLabel
)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}

/*  C_InitPIN initializes the normal user's pin. */
CK_DECLARE_FUNCTION(CK_RV, C_InitPIN)(
	CK_SESSION_HANDLE hSession,
	CK_UTF8CHAR_PTR pPin,
	CK_ULONG ulPinLen
)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}

/*  C_SetPIN modifies the PIN of the user that is currently logged in,
or the CKU_USER PIN if the session is not logged in. */
CK_DECLARE_FUNCTION(CK_RV, C_SetPIN)(
	CK_SESSION_HANDLE hSession,
	CK_UTF8CHAR_PTR pOldPin,
	CK_ULONG ulOldLen,
	CK_UTF8CHAR_PTR pNewPin,
	CK_ULONG ulNewLen
)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}

