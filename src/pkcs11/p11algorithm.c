/*
* ZY PKCS#11 Module
* Copyright(C),2016, Zhao Yang(赵洋),Beijing,P.R.China
* All rights reserved.
* @filename:  p11algorithm.c
* @author:  赵洋 Zhao Yang (cnrgc@163.com/sxzhaoyang@gmail.com)
* @version:  0.1
* @date:  2016.12.17
* @brief:  PKCS#11 接口中的算法函数
*/

#include "p11general.h"

extern struct p11Context_t *context;

/*  C_EncryptInit initializes an encryption operation. */
CK_DECLARE_FUNCTION(CK_RV, C_EncryptInit)
(
	CK_SESSION_HANDLE hSession,
	CK_MECHANISM_PTR pMechanism,
	CK_OBJECT_HANDLE hKey
)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}

/*  C_Encrypt encrypts single-part data. */
CK_DECLARE_FUNCTION(CK_RV, C_Encrypt)
(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR pData,
	CK_ULONG ulDataLen,
	CK_BYTE_PTR pEncryptedData,
	CK_ULONG_PTR pulEncryptedDataLen
)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}

/*  C_EncryptUpdate continues a multiple-part encryption operation,
processing another data part. */
CK_DECLARE_FUNCTION(CK_RV, C_EncryptUpdate)
(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR pPart,
	CK_ULONG ulPartLen,
	CK_BYTE_PTR pEncryptedPart,
	CK_ULONG_PTR pulEncryptedPartLen
)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}

/*  C_EncryptFinal finishes a multiple-part encryption operation. */
CK_DECLARE_FUNCTION(CK_RV, C_EncryptFinal)
(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR pLastEncryptedPart,
	CK_ULONG_PTR pulLastEncryptedPartLen
)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}

/*  C_DecryptInit initializes a decryption operation. */
CK_DECLARE_FUNCTION(CK_RV, C_DecryptInit)
(
	CK_SESSION_HANDLE hSession,
	CK_MECHANISM_PTR pMechanism,
	CK_OBJECT_HANDLE hKey
)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}

/*  C_Decrypt decrypts encrypted data in a single part. */
CK_DECLARE_FUNCTION(CK_RV, C_Decrypt)
(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR pEncryptedData,
	CK_ULONG ulEncryptedDataLen,
	CK_BYTE_PTR pData,
	CK_ULONG_PTR pulDataLen
)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}

/*  C_DecryptUpdate continues a multiple-part decryption operation,
processing another encrypted data part. */
CK_DECLARE_FUNCTION(CK_RV, C_DecryptUpdate)
(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR pEncryptedPart,
	CK_ULONG ulEncryptedPartLen,
	CK_BYTE_PTR pPart,
	CK_ULONG_PTR pulPartLen
)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}

/*  C_DecryptFinal finishes a multiple-part decryption operation. */
CK_DECLARE_FUNCTION(CK_RV, C_DecryptFinal)
(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR pLastPart,
	CK_ULONG_PTR pulLastPartLen
)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}

/*  C_DigestInit initializes a message-digesting operation. */
CK_DECLARE_FUNCTION(CK_RV, C_DigestInit)
(
	CK_SESSION_HANDLE hSession,
	CK_MECHANISM_PTR pMechanism
)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}

/*  C_Digest digests data in a single part. */
CK_DECLARE_FUNCTION(CK_RV, C_Digest)
(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR pData,
	CK_ULONG ulDataLen,
	CK_BYTE_PTR pDigest,
	CK_ULONG_PTR pulDigestLen
)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}

/*  C_DigestUpdate continues a multiple-part message-digesting operation,
processing another data part. */
CK_DECLARE_FUNCTION(CK_RV, C_DigestUpdate)
(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR pPart,
	CK_ULONG ulPartLen
)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}

/*  C_DigestKey continues a multiple-part message-digesting operation by
digesting the value of a secret key. */
CK_DECLARE_FUNCTION(CK_RV, C_DigestKey)
(
	CK_SESSION_HANDLE hSession,
	CK_OBJECT_HANDLE hKey
)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}

/*  C_DigestFinal finishes a multiple-part message-digesting operation. */
CK_DECLARE_FUNCTION(CK_RV, C_DigestFinal)
(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR pDigest,
	CK_ULONG_PTR pulDigestLen
)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}

/*  C_SignInit initializes a signature operation,
here the signature is an appendix to the data. */
CK_DECLARE_FUNCTION(CK_RV, C_SignInit)
(
	CK_SESSION_HANDLE hSession,
	CK_MECHANISM_PTR pMechanism,
	CK_OBJECT_HANDLE hKey
)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}

/*  C_Sign signs data in a single part, where the signature is an appendix to the data. */
CK_DECLARE_FUNCTION(CK_RV, C_Sign)
(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR pData,
	CK_ULONG ulDataLen,
	CK_BYTE_PTR pSignature,
	CK_ULONG_PTR pulSignatureLen
)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}

/*  C_SignUpdate continues a multiple-part signature operation,
processing another data part. */
CK_DECLARE_FUNCTION(CK_RV, C_SignUpdate)
(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR pPart,
	CK_ULONG ulPartLen
)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}

/*  C_SignFinal finishes a multiple-part signature operation. */
CK_DECLARE_FUNCTION(CK_RV, C_SignFinal)
(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR pSignature,
	CK_ULONG_PTR pulSignatureLen
)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}

/*  C_SignRecoverInit initializes a signature operation, where the data
can be recovered from the signature. */
CK_DECLARE_FUNCTION(CK_RV, C_SignRecoverInit)
(
	CK_SESSION_HANDLE hSession,
	CK_MECHANISM_PTR pMechanism,
	CK_OBJECT_HANDLE hKey
)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}

/*  C_SignRecover signs data in a single operation, where the data can be
recovered from the signature. */
CK_DECLARE_FUNCTION(CK_RV, C_SignRecover)
(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR pData,
	CK_ULONG ulDataLen,
	CK_BYTE_PTR pSignature,
	CK_ULONG_PTR pulSignatureLen
)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}

/*  C_VerifyInit initializes a verification operation, where the signature is
an appendix to the data. */
CK_DECLARE_FUNCTION(CK_RV, C_VerifyInit)
(
	CK_SESSION_HANDLE hSession,
	CK_MECHANISM_PTR pMechanism,
	CK_OBJECT_HANDLE hKey
)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}

/*  C_Verify verifies a signature in a single-part operation, where the signature
is an appendix to the data. */
CK_DECLARE_FUNCTION(CK_RV, C_Verify)
(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR pData,
	CK_ULONG ulDataLen,
	CK_BYTE_PTR pSignature,
	CK_ULONG ulSignatureLen
)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}

/*  C_VerifyUpdate continues a multiple-part verification operation,
processing another data part. */
CK_DECLARE_FUNCTION(CK_RV, C_VerifyUpdate)
(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR pPart,
	CK_ULONG ulPartLen
)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}

/*  C_VerifyFinal finishes a multiple-part verification operation,
checking the signature. */
CK_DECLARE_FUNCTION(CK_RV, C_VerifyFinal)
(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR pSignature,
	CK_ULONG ulSignatureLen
)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}

/*  C_VerifyRecoverInit initializes a signature verification operation,
where the data is recovered from the signature. */
CK_DECLARE_FUNCTION(CK_RV, C_VerifyRecoverInit)
(
	CK_SESSION_HANDLE hSession,
	CK_MECHANISM_PTR pMechanism,
	CK_OBJECT_HANDLE hKey
)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}

/*  C_VerifyRecover verifies a signature in a single-part operation,
where the data is recovered from the signature. */
CK_DECLARE_FUNCTION(CK_RV, C_VerifyRecover)
(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR pSignature,
	CK_ULONG ulSignatureLen,
	CK_BYTE_PTR pData,
	CK_ULONG_PTR pulDataLen
)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}

/*  C_DigestEncryptUpdate continues multiple-part digest and encryption
operations, processing another data part. */
CK_DECLARE_FUNCTION(CK_RV, C_DigestEncryptUpdate)
(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR pPart,
	CK_ULONG ulPartLen,
	CK_BYTE_PTR pEncryptedPart,
	CK_ULONG_PTR pulEncryptedPartLen
)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}

/*  C_DecryptDigestUpdate continues a multiple-part combined decryption and
digest operation, processing another data part. */
CK_DECLARE_FUNCTION(CK_RV, C_DecryptDigestUpdate)
(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR pEncryptedPart,
	CK_ULONG ulEncryptedPartLen,
	CK_BYTE_PTR pPart,
	CK_ULONG_PTR pulPartLen
)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}

/*  C_SignEncryptUpdate continues a multiple-part combined signature and
encryption operation, processing another data part. */
CK_DECLARE_FUNCTION(CK_RV, C_SignEncryptUpdate)
(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR pPart,
	CK_ULONG ulPartLen,
	CK_BYTE_PTR pEncryptedPart,
	CK_ULONG_PTR pulEncryptedPartLen
)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}

/*  C_DecryptVerifyUpdate continues a multiple-part combined decryption and verification
operation, processing another data part. */
CK_DECLARE_FUNCTION(CK_RV, C_DecryptVerifyUpdate)
(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR pEncryptedPart,
	CK_ULONG ulEncryptedPartLen,
	CK_BYTE_PTR pPart,
	CK_ULONG_PTR pulPartLen
)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}

/*  C_GenerateKey generates a secret key or set of domain parameters,
creating a new object. */
CK_DECLARE_FUNCTION(CK_RV, C_GenerateKey)
(
	CK_SESSION_HANDLE hSession,
	CK_MECHANISM_PTR pMechanism,
	CK_ATTRIBUTE_PTR pTemplate,
	CK_ULONG ulCount,
	CK_OBJECT_HANDLE_PTR phKey
)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}

/*  C_GenerateKeyPair generates a public/private key pair, creating new key objects. */
CK_DECLARE_FUNCTION(CK_RV, C_GenerateKeyPair)
(
	CK_SESSION_HANDLE hSession,
	CK_MECHANISM_PTR pMechanism,
	CK_ATTRIBUTE_PTR pPublicKeyTemplate,
	CK_ULONG ulPublicKeyAttributeCount,
	CK_ATTRIBUTE_PTR pPrivateKeyTemplate,
	CK_ULONG ulPrivateKeyAttributeCount,
	CK_OBJECT_HANDLE_PTR phPublicKey,
	CK_OBJECT_HANDLE_PTR phPrivateKey
)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}

/*  C_WrapKey wraps (i.e., encrypts) a private or secret key. */
CK_DECLARE_FUNCTION(CK_RV, C_WrapKey)
(
	CK_SESSION_HANDLE hSession,
	CK_MECHANISM_PTR pMechanism,
	CK_OBJECT_HANDLE hWrappingKey,
	CK_OBJECT_HANDLE hKey,
	CK_BYTE_PTR pWrappedKey,
	CK_ULONG_PTR pulWrappedKeyLen
)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}

/*  C_UnwrapKey unwraps (i.e. decrypts) a wrapped key, creating a new private key
or secret key object. */
CK_DECLARE_FUNCTION(CK_RV, C_UnwrapKey)
(
	CK_SESSION_HANDLE hSession,
	CK_MECHANISM_PTR pMechanism,
	CK_OBJECT_HANDLE hUnwrappingKey,
	CK_BYTE_PTR pWrappedKey,
	CK_ULONG ulWrappedKeyLen,
	CK_ATTRIBUTE_PTR pTemplate,
	CK_ULONG ulAttributeCount,
	CK_OBJECT_HANDLE_PTR phKey
)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}

/*  C_DeriveKey derives a key from a base key, creating a new key object. */
CK_DECLARE_FUNCTION(CK_RV, C_DeriveKey)
(
	CK_SESSION_HANDLE hSession,
	CK_MECHANISM_PTR pMechanism,
	CK_OBJECT_HANDLE hBaseKey,
	CK_ATTRIBUTE_PTR pTemplate,
	CK_ULONG ulAttributeCount,
	CK_OBJECT_HANDLE_PTR phKey
)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}

/*  C_SeedRandom mixes additional seed material into the token�s random number generator. */
CK_DECLARE_FUNCTION(CK_RV, C_SeedRandom)
(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR pSeed,
	CK_ULONG ulSeedLen
)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}

/*  C_GenerateRandom generates random or pseudo-random data. */
CK_DECLARE_FUNCTION(CK_RV, C_GenerateRandom)
(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR pRandomData,
	CK_ULONG ulRandomLen
)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}

/*  C_GetFunctionStatus obtained the status of a function
running in parallel with an application. Now legacy! */
CK_DECLARE_FUNCTION(CK_RV, C_GetFunctionStatus)
(
	CK_SESSION_HANDLE hSession
)
{

}

/*  C_CancelFunction cancelled a function running in parallel
with an application. Now legacy! */
CK_DECLARE_FUNCTION(CK_RV, C_CancelFunction)
(
	CK_SESSION_HANDLE hSession
)
{
	FUNC_RETURNS(CKR_FUNCTION_NOT_SUPPORTED);
}

