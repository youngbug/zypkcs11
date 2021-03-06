/**
* CT-API for CCID Driver
*
* Copyright (c) 2013, CardContact Systems GmbH, Minden, Germany
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*     * Redistributions of source code must retain the above copyright
*       notice, this list of conditions and the following disclaimer.
*     * Redistributions in binary form must reproduce the above copyright
*       notice, this list of conditions and the following disclaimer in the
*       documentation and/or other materials provided with the distribution.
*     * Neither the name of CardContact Systems GmbH nor the
*       names of its contributors may be used to endorse or promote products
*       derived from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL CardContact Systems GmbH BE LIABLE FOR ANY
* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
* @file mutex.h
* @author Frank Thater
* @brief Defines procedures for cross platform mutex handling
*/

#include "mutex.h"



int mutex_init(MUTEX *mutex) {
#ifdef _WIN32
	*mutex = CreateMutex(0, FALSE, 0);
	return (*mutex == 0 ? -1 : 0);
#else
	return pthread_mutex_init(mutex, NULL);
#endif
}



int mutex_lock(MUTEX *mutex) {
#ifdef _WIN32
	return (WaitForSingleObject(*mutex, INFINITE) == WAIT_FAILED ? -1 : 0);
#else
	return pthread_mutex_lock(mutex);
#endif
}



int mutex_unlock(MUTEX *mutex) {
#ifdef _WIN32
	return (ReleaseMutex(*mutex) == 0 ? -1 : 0);
#else
	return pthread_mutex_unlock(mutex);
#endif
}



int mutex_destroy(MUTEX *mutex) {
#ifdef _WIN32
	return (CloseHandle(*mutex) == 0 ? -1 : 0);
#else
	return pthread_mutex_destroy(mutex);
#endif
}
