/*******************************************************************************
	Copyright (C), 2011-2015, Andrew Min Chang
	
	File name: AMCMemPool.h
	Description: 	
			This file provide simple and educational memory pool tools.
			
	Author:		Andrew Chang (Zhang Min) 
	History:
		2014-05-05: File created

--------------------------------------------------------------
	Copyright information: 
			This file was intended to be under GPL protocol. However, I may use this library
		in my working as I am an employee. And my company may require me to keep it se-
		cret. Therefore, this file is neither open source nor under GPL control. 
		
********************************************************************************/

#ifndef _AMC_MEM_POOL_H
#define _AMC_MEM_POOL_H

#include <stdio.h>
#include <stdlib.h>

#ifndef BOOL
#define BOOL	long
#define FALSE	(0)
#define TRUE	(!0)
#endif

#ifndef NULL
#define NULL	((void*)0)
#endif

struct AMCMemPool;
struct AMCMemUnit;

struct AMCMemPool *AMCMemPool_Create(unsigned long unitSize, unsigned long initUnitCount, unsigned long growUnitCount, BOOL useLock);
int AMCMemPool_Destory(struct AMCMemPool *pool);
BOOL AMCMemPool_IsAllFree(struct AMCMemPool *pool);

struct AMCMemUnit *AMCMemPool_Alloc(struct AMCMemPool *pool);
int AMCMemPool_Free(struct AMCMemUnit *unit);

inline void *AMCMemPool_DataPtr(struct AMCMemUnit *unit);
inline unsigned long AMCMemPool_UnitSize(struct AMCMemUnit *unit);
inline unsigned long AMCMemPool_UnitSizeForPool(struct AMCMemPool *pool);


#endif	/* EOF */
