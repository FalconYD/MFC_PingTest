#include "pch.h"
#include "LogManager.h"

void LogManager::Init()
{
	m_stParam.bThreadFlag = true;
	m_stParam.cObjectPointer1 = this;
	m_stParam.enState = THREAD_STATUS::THREAD_STAT_NONE;
	m_stParam.nScanInterval = 100;

	m_thLog = std::thread(THREAD_LOG, &m_stParam);
}

void LogManager::PushLog(std::string strMsg)
{
	m_queueMsg.push(strMsg);
}

void LogManager::FlushLog()
{
	if (m_queueMsg.size() > 0)
	{
		std::string strMsg = m_queueMsg.front() + "\n";
		m_queueMsg.pop();


		std::ofstream stream("");
		stream << strMsg.c_str();

		stream.flush();
		stream.close();
	}
}

void LogManager::Destroy()
{
	m_stParam.bThreadFlag = false;
	m_thLog.join();
}

int LogManager::THREAD_LOG(void* pObject)
{
	THREAD_PARAM* pParam = (THREAD_PARAM*)pObject;
	LogManager* pMain = (LogManager*)pParam->cObjectPointer1;

	pParam->enState = THREAD_STATUS::THREAD_STAT_ACTIVE;
	while (pParam->bThreadFlag)
	{
		Sleep(pParam->nScanInterval);
		pParam->enState = THREAD_STATUS::THREAD_STAT_RUNNING;

		pMain->FlushLog();
	}
	pParam->enState = THREAD_STATUS::THREAD_STAT_COMPLETE;
}