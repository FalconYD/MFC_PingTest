#pragma once
class LogManager
{
private:
	std::thread m_thLog;
	static int THREAD_LOG(void* pObject);

	THREAD_PARAM m_stParam;
public:
	std::queue<std::string> m_queueMsg;
	void Init();
	void PushLog(std::string strMsg);
	void FlushLog();
	void Destroy();
};

