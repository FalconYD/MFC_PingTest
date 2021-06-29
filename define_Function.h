#pragma once
typedef int(*UserCallBack		)(int funcnum, int seqeuncenum, char* data1, char* data2);
typedef int(*NewImage			)(void* pImg, int width, int height, int channel, const char* title);
typedef int(*NewMessage			)(char* strMessage);
typedef int(*UpdateHistogram	)(float gray[256], float r[256], float g[256], float b[256]);
typedef int(*UpdateProfile		)(int* gray, int* r, int* g, int* b, int nLen);
typedef int(*CL_WriteMessage	)(char* strMessage);

inline void _in_fn_Uni2Multi(const wchar_t* InputString, char* OutString)
{
	//if (wcslen(InputString) <= sizeof(wchar_t) * strlen(OutString))
	if (wcslen(InputString) > 0 && wcslen(InputString) < 1024)
	{
		int len = WideCharToMultiByte(CP_ACP, 0, InputString, -1, NULL, 0, NULL, NULL);
		WideCharToMultiByte(CP_ACP, 0, InputString, -1, OutString, len, NULL, NULL);
	}
	else
	{
		//OutputDebugString(_T("InputString Length Error."));
	}
}

/**
@brief	MultiByte to Unicode
@return	유니코드 문자열
@param	멀티바이트 문자열
@remark
- Multibyte를 Unicode로 변환하는 함수.
@author	선경규(Kyeong Kyu - Seon)
@date	2018/4/24  13:19
*/
inline void _in_fn_Multi2Uni(const char* InputString, wchar_t* OutString)
{
	//if (strlen(InputString) < sizeof(char) * wcslen(OutString))
	if (strlen(InputString) > 0 && strlen(InputString) < 1024)
	{
		static wchar_t strUnicode[1024] = { 0, };
		int nLen = MultiByteToWideChar(CP_ACP, 0, InputString, (int)strlen(InputString), NULL, NULL);
		MultiByteToWideChar(CP_ACP, 0, InputString, (int)strlen(InputString), OutString, nLen);
	}
	else
	{
		//OutputDebugString(_T("InputString Length Error."));
	}
}

inline void _in_fn_Multi2Uni_UTF8(const char* InputString, wchar_t* OutString)
{
	//if (strlen(InputString) < sizeof(char) * wcslen(OutString))
	if (strlen(InputString) > 0 && strlen(InputString) < 1024)
	{
		static wchar_t strUnicode[1024] = { 0, };
		int nLen = MultiByteToWideChar(CP_UTF8, 0, InputString, (int)strlen(InputString), NULL, NULL);
		MultiByteToWideChar(CP_UTF8, 0, InputString, (int)strlen(InputString), OutString, nLen);
	}
	else
	{
		//OutputDebugString(_T("InputString Length Error."));
	}
}

template<typename ... Args> 
std::string string_format(const std::string& format, Args ... args) 
{
	size_t size = snprintf(nullptr, 0, format.c_str(), args ...) + 1; // Extra space for '\0' 
	if (size <= 0) 
	{ 
		throw std::runtime_error("Error during formatting."); 
	} 
	std::unique_ptr<char[]> buf(new char[size]); 
	snprintf(buf.get(), size, format.c_str(), args ...); 
	return std::string(buf.get(), buf.get() + size - 1); // We don't want the '\0' inside 
} 
// 사용법 
/*
std::string sResult = ""; 
std::string stringValue = "string..."; 
int intValue = 999; 
sResult = string_format("string format example : %s / %d", stringValue, intValue);
*/
