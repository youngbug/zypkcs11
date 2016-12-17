/*
* ZY PKCS#11 Module
* Copyright(C),2016, Zhao Yang(赵洋),Beijing,P.R.China
* All rights reserved.
* @filename:  p11objects.c
* @author:  赵洋 Zhao Yang (cnrgc@163.com/sxzhaoyang@gmail.com)
* @version:  0.1
* @date:  2016.12.17
* @brief:  PKCS#11 接口中的Object管理函数
*/

#include "p11general.h"


extern struct p11Context_t *context;


/*  C_CreateObject creates a new object. */
CK_DECLARE_FUNCTION(CK_RV, C_CreateObject)
(
	CK_SESSION_HANDLE hSession,
	CK_ATTRIBUTE_PTR pTemplate,
	CK_ULONG ulCount,
	CK_OBJECT_HANDLE_PTR phObject
)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}

/*  C_CopyObject copies an object. */
CK_DECLARE_FUNCTION(CK_RV, C_CopyObject)
(
	CK_SESSION_HANDLE hSession,
	CK_OBJECT_HANDLE hObject,
	CK_ATTRIBUTE_PTR pTemplate,
	CK_ULONG ulCount,
	CK_OBJECT_HANDLE_PTR phNewObject
)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}

/*  C_DestroyObject destroys an object. */
CK_DECLARE_FUNCTION(CK_RV, C_DestroyObject)
(
	CK_SESSION_HANDLE hSession,
	CK_OBJECT_HANDLE hObject
)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}


/*  C_GetObjectSize gets the size of an object. */
CK_DECLARE_FUNCTION(CK_RV, C_GetObjectSize)
(
	CK_SESSION_HANDLE hSession,
	CK_OBJECT_HANDLE hObject,
	CK_ULONG_PTR pulSize
)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}

/*  C_GetAttributeValue obtains the value of one or more attributes of an object. */
CK_DECLARE_FUNCTION(CK_RV, C_GetAttributeValue)
(
	CK_SESSION_HANDLE hSession,
	CK_OBJECT_HANDLE hObject,
	CK_ATTRIBUTE_PTR pTemplate,
	CK_ULONG ulCount
)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}

/*  C_SetAttributeValue modifies the value of one or more attributes of an object. */
CK_DECLARE_FUNCTION(CK_RV, C_SetAttributeValue)
(
	CK_SESSION_HANDLE hSession,
	CK_OBJECT_HANDLE hObject,
	CK_ATTRIBUTE_PTR pTemplate,
	CK_ULONG ulCount
)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}

/*  C_FindObjectsInit initializes a search for token and session objects
that match a template. */
CK_DECLARE_FUNCTION(CK_RV, C_FindObjectsInit)
(
	CK_SESSION_HANDLE hSession,
	CK_ATTRIBUTE_PTR pTemplate,
	CK_ULONG ulCount
)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}

/*  C_FindObjects continues a search for token and session objects that match a template, */
CK_DECLARE_FUNCTION(CK_RV, C_FindObjects)
(
	CK_SESSION_HANDLE hSession,
	CK_OBJECT_HANDLE_PTR phObject,
	CK_ULONG ulMaxObjectCount,
	CK_ULONG_PTR pulObjectCount
)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}

/*  C_FindObjectsFinal terminates a search for token and session objects. */
CK_DECLARE_FUNCTION(CK_RV, C_FindObjectsFinal)
(
	CK_SESSION_HANDLE hSession
)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}

