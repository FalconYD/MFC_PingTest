#pragma once

typedef enum EN_THREAD_STATUS
{
	THREAD_STAT_NONE = 0,
	THREAD_STAT_ACTIVE,
	THREAD_STAT_RUNNING,
	THREAD_STAT_COMPLETE
}THREAD_STATUS;

typedef struct ST_THREAD_PARAM
{
	void* cObjectPointer1;
	void* cObjectPointer2;
	int		nScanInterval;
	int		nThreadIndex;
	bool	bThreadFlag;
	THREAD_STATUS enState;

	ST_THREAD_PARAM()
	{
		cObjectPointer1 = nullptr;
		cObjectPointer2 = nullptr;
		nScanInterval = 300;
		nThreadIndex = 0;
		bThreadFlag = false;
		enState = THREAD_STAT_NONE;
	}
}THREAD_PARAM;

typedef struct ST_POINT
{
	size_t x;
	size_t y;
	ST_POINT()
	{
		x = 0;
		y = 0;
	}
	ST_POINT(size_t nx, size_t ny)
	{
		x = nx;
		y = ny;
	}
}DEFPOINT;