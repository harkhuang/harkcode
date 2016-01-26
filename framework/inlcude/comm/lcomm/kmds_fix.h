#ifndef __KMDS_FIX_H__
#define __KMDS_FIX_H__

#include <platform/linuxfuncdef.h>
#include <datatype/datatype.h>
#include <lcomm/macro_ldef.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <sstream>

#ifndef CHR_NULL
#define CHR_NULL		' '			// 空字符
#endif

class ToLower
{
public:
	char operator()(char val)
	{
		return tolower(val);
	}
};

class ToUpper
{
public:
	char operator()(char val)
	{
		return toupper(val);
	}
};
inline void string_replace(const std::string& oldValue, const std::string& newValue, std::string& value)
{
	for(std::string::size_type pos = value.find(oldValue);
		pos != std::string::npos;
		pos = value.find(oldValue, pos))
	{
		value.replace(pos, oldValue.size(), newValue);
		pos += newValue.size();
	}
	return;
}

inline std::string string_toLower(const std::string& value)
{
	std::string copy = value;
	std::transform(copy.begin(), copy.end(), copy.begin(), ToLower());
	return copy;
}

inline std::string string_toUpper(const std::string& value)
{
	std::string copy = value;
	std::transform(copy.begin(), copy.end(), copy.begin(), ToUpper());
	return copy;
}

// KmdsFix异常类
class CKmdsFixException : public std::exception
{
public:
	CKmdsFixException():m_nErrorCode(0)
	{}
	CKmdsFixException(const int nErrorCode,const std::string& strErrMsg):m_nErrorCode(nErrorCode),m_strErrMsg(strErrMsg)
	{}
	CKmdsFixException(const int nErrorCode,const char* pszErrMsg):m_nErrorCode(nErrorCode),m_strErrMsg(pszErrMsg)
	{}
	virtual ~CKmdsFixException() throw(){}
	virtual const char *what() const throw ()
	{
		return m_strErrMsg.c_str();
	}
	int GetErrorCode() const
	{
		return m_nErrorCode;
	}
private:
	int m_nErrorCode;
	std::string m_strErrMsg;
};

class CKmdsFix
{
	typedef std::map<std::string, std::string> Name2ValueMap;

public:
	// 增加Tag=Value
	void AddF(const char* szName, const char* szFormat, ...)
	{
		va_list marker;
		char szValue[4096];

		va_start(marker, szFormat);
		_vsnprintf(szValue, sizeof(szValue) - 1, szFormat, marker);
		szValue[sizeof(szValue) - 1] = 0;
		va_end(marker);

		InternalAdd(std::string(szName), std::string(szValue));
	}

	void Add(const char* szName, const char* szValue, int nRecno = 0)
	{
		InternalAdd(std::string(GetFullName(szName, nRecno)), std::string(szValue));
	}

	void AddNoTranstoLower(const char* szName, const char* szValue, int nRecno = 0)
	{
		InternalNoTranstoLower(std::string(GetFullName(szName, nRecno)), std::string(szValue));
	}

	void Add(const char* szName, const std::string strValue, int nRecno = 0)
	{
		InternalAdd(std::string(GetFullName(szName, nRecno)), strValue);
	}

	void Add(const char* szName, char cValue, int nRecno = 0)
	{
		InternalAdd(GetFullName(szName, nRecno), cValue);
	}

	void Add(const char* szName, bool bValue, int nRecno = 0)
	{
		InternalAdd(GetFullName(szName, nRecno), bValue);
	}

	void Add(const char* szName, int nValue, int nRecno = 0)
	{
		InternalAdd(GetFullName(szName, nRecno), nValue);
	}

	void Add(const char* szName, unsigned nValue, int nRecno = 0)
	{
		InternalAdd(GetFullName(szName, nRecno), nValue);
	}

	void Add(const char* szName, long lValue, int nRecno = 0)
	{
		InternalAdd(GetFullName(szName, nRecno), lValue);
	}

	void Add(const char* szName, short nValue, int nRecno = 0)
	{
		InternalAdd(GetFullName(szName, nRecno), nValue);
	}

	void Add(const char* szName, int64 nValue, int nRecno = 0)
	{
		InternalAdd(GetFullName(szName, nRecno), nValue);
	}

	void Add(const char* szName, float dbValue, int nRecno = 0)
	{
		std::string str;
		std::stringstream strm;
		strm<<dbValue;
		strm>>str;

		AddF(GetFullName(szName, nRecno), str.c_str());
	}

	void Add(const char* szName, double dbValue, int nRecno = 0)
	{
		std::string str;
		std::stringstream strm;
		strm<<dbValue;
		strm>>str;

		AddF(GetFullName(szName, nRecno), str.c_str());
	}

	// 获取Tag=Value
	const char* GetVal(const char* szName, int nRecno = 0)
	{
		return InternalGet(GetFullName(szName, nRecno));
	}

	const char* TryGetVal(const char* szName, int nRecno = 0)
	{
		return InternalTryGet(GetFullName(szName, nRecno));
	}

	void Get(const char* szName, char* szValue, int nValueSize, int nRecno = 0)
	{
		strncpy(szValue, InternalGet(GetFullName(szName, nRecno)), nValueSize);
		szValue[nValueSize - 1] = '\0';
	}

	bool TryGet(const char* szName, char* szValue, int nValueSize, int nRecno = 0)
	{
		const char* pTemp = InternalTryGet(GetFullName(szName, nRecno));
		if (pTemp == NULL)
			return false;
		strncpy(szValue, pTemp, nValueSize);
		szValue[nValueSize - 1] = '\0';
		return true;
	}

	void Get(const char* szName, char& cValue, int nRecno = 0)
	{
		char szValue[32];
		Get(szName, szValue, sizeof(szValue), nRecno);
		cValue = szValue[0];
		if (cValue == 0)
			cValue = CHR_NULL;
	}

	bool TryGet(const char* szName, char& cValue, int nRecno = 0)
	{
		char szValue[32];
		if (!TryGet(szName, szValue, sizeof(szValue), nRecno))
			return false;
		cValue = szValue[0];
		if (cValue == 0)
			cValue = CHR_NULL;
		return true;
	}

	void Get(const char* szName, bool& bValue, int nRecno = 0)
	{
		char cValue;
		Get(szName, cValue, nRecno);
		bValue = (cValue == '1' || cValue == 'T');
	}

	bool TryGet(const char* szName, bool& bValue, int nRecno = 0)
	{
		char cValue;
		if (!TryGet(szName, cValue, nRecno))
			return false;
		bValue = (cValue == '1' || cValue == 'T');
		return true;
	}

	void Get(const char* szName, int& nValue, int nRecno = 0)
	{
		char szValue[32];
		Get(szName, szValue, sizeof(szValue), nRecno);
		nValue = atoi(szValue);
	}

	bool TryGet(const char* szName, int& nValue, int nRecno = 0)
	{
		char szValue[32];
		if (!TryGet(szName, szValue, sizeof(szValue), nRecno))
			return false;
		nValue = atoi(szValue);
		return true;
	}

	void Get(const char* szName, unsigned& nValue, int nRecno = 0)
	{
		char szValue[32];
		Get(szName, szValue, sizeof(szValue), nRecno);
		nValue = atoi(szValue);
	}

	bool TryGet(const char* szName, unsigned& nValue, int nRecno = 0)
	{
		char szValue[32];
		if (!TryGet(szName, szValue, sizeof(szValue), nRecno))
			return false;
		nValue = atoi(szValue);
		return true;
	}

	void Get(const char* szName, long& lValue, int nRecno = 0)
	{
		char szValue[32];
		Get(szName, szValue, sizeof(szValue), nRecno);
		lValue = atol(szValue);
	}

	bool TryGet(const char* szName, long& lValue, int nRecno = 0)
	{
		char szValue[32];
		if (!TryGet(szName, szValue, sizeof(szValue), nRecno))
			return false;
		lValue = atol(szValue);
		return true;
	}

	void Get(const char* szName, short& nValue, int nRecno = 0)
	{
		char szValue[32];
		Get(szName, szValue, sizeof(szValue), nRecno);
		nValue = atoi(szValue);
	}

	bool TryGet(const char* szName, short& nValue, int nRecno = 0)
	{
		char szValue[32];
		if (!TryGet(szName, szValue, sizeof(szValue), nRecno))
			return false;
		nValue = atoi(szValue);
		return true;
	}

	void Get(const char* szName, int64& nValue, int nRecno = 0)
	{
		char szValue[32];
		Get(szName, szValue, sizeof(szValue), nRecno);
		nValue = _atoi64(szValue);
	}

	bool TryGet(const char* szName, int64& nValue, int nRecno = 0)
	{
		char szValue[32];
		if (!TryGet(szName, szValue, sizeof(szValue), nRecno))
			return false;
		nValue = _atoi64(szValue);
		return true;
	}

	void Get(const char* szName, float& dbValue, int nRecno = 0)
	{
		char szValue[32];
		Get(szName, szValue, sizeof(szValue), nRecno);
		dbValue = (float)atof(szValue);
	}

	bool TryGet(const char* szName, float& dbValue, int nRecno = 0)
	{
		char szValue[32];
		if (!TryGet(szName, szValue, sizeof(szValue), nRecno))
			return false;
		dbValue = (float)atof(szValue);
		return true;
	}

	void Get(const char* szName, double& dbValue, int nRecno = 0)
	{
		char szValue[32];
		Get(szName, szValue, sizeof(szValue), nRecno);
		dbValue = atof(szValue);
	}

	bool TryGet(const char* szName, double& dbValue, int nRecno = 0)
	{
		char szValue[32];
		if (!TryGet(szName, szValue, sizeof(szValue), nRecno))
			return false;
		dbValue = atof(szValue);
		return true;
	}

	// string方式
	void Get(const char* szName, std::string& strValue, int nRecno = 0)
	{
		strValue = InternalGetByString(GetFullName(szName, nRecno));
	}

public:
	void Clear()
	{
		m_mapName2Value.clear();
		m_vectName.clear();
	}

	void GetFixStr(std::string& strResult)
	{
		strResult.clear();
		strResult.reserve(m_mapName2Value.size() * 32);

		// 按输入顺序输出fix串
		std::vector<std::string>::const_iterator iterName;
		for (iterName = m_vectName.begin(); iterName != m_vectName.end(); ++iterName)
		{
			Name2ValueMap::const_iterator iterValue = m_mapName2Value.find(*iterName);
			if (iterValue == m_mapName2Value.end())
			{
				char szTemp[256];
				SAFESNPRINTF(szTemp, sizeof(szTemp), "CKmdsFix::GetFixStrFIX协议中字段[%s]未找到。", (*iterName).c_str());
				throw CKmdsFixException(2000,szTemp);
			}
			strResult += iterValue->first + "=" + iterValue->second + "\001";
		}

		//Name2ValueMap::const_iterator theIter;
		//for (theIter = m_mapName2Value.begin(); theIter != m_mapName2Value.end(); ++theIter)
		//{
		//	strResult += theIter->first + "=" + theIter->second + "\001";
		//}
	}

	void GetFixStr(char* szFixStr, int nFixStrSize)
	{
		std::string strResult;
		GetFixStr(strResult);
		if (nFixStrSize <= (int)strResult.length())
		{
			char szTemp[256];
			SAFESNPRINTF(szTemp, sizeof(szTemp), "CKmdsFix::GetFixStr字符串数组越界，需要数组大小为[%d]。", strResult.length());
			throw CKmdsFixException(2000,szTemp);
		}
		strncpy(szFixStr, strResult.c_str(), nFixStrSize);
		szFixStr[nFixStrSize - 1] = '\0';
	}

	void PutFixStr(const std::string strFixStr, std::string::size_type pos = 0, std::map<std::string, std::string>* mapBinaryTag = NULL)
	{
		Clear();

		m_vectName.reserve(strFixStr.size() / 32);
		std::string strName;
		std::string strValue;
		while (pos < strFixStr.size() - 1)
		{
			ExtractField(strFixStr, pos, strName, strValue, mapBinaryTag);
			InternalAdd(strName, strValue);
		}
	}

	void PutFixStr(const char* szFixStr, std::string::size_type pos = 0)
	{
		PutFixStr(std::string(szFixStr), pos);
	}

    void ExtractField(const std::string& strFixStr, std::string::size_type& pos, std::string& strName, std::string& strValue, std::map<std::string, std::string>* mapBinaryTag = NULL)
	{
		std::string::size_type equalSign = strFixStr.find_first_of('=', pos);
		if (equalSign == std::string::npos)
		{
			char szTemp[256];
			SAFESNPRINTF(szTemp, sizeof(szTemp), "%s","CKmdsFix::ExtractFieldFIX协议中字段未找到'='。");
			throw CKmdsFixException(2000,szTemp);
		}
		strName  = string_toLower(strFixStr.substr(pos, equalSign - pos));

		// 计算长度
		std::string::size_type soh;
		std::map<std::string, std::string>::const_iterator theIter;
		if (mapBinaryTag != NULL &&
		   ((theIter =  mapBinaryTag->find(strName)) != mapBinaryTag->end()))		// 二进制TAG
		{
			int nBinaryLen = 0;
			Get(theIter->second.c_str(), nBinaryLen);
			soh = equalSign + 1 + nBinaryLen;
		}
		else
		{
			soh = strFixStr.find_first_of('\001', equalSign + 1);
			if (soh == std::string::npos)
			{
				char szTemp[256];
				SAFESNPRINTF(szTemp, sizeof(szTemp), "%s", "CKmdsFix::ExtractFieldFIX协议中字段未找到SOH(\001)。");
				throw CKmdsFixException(2000,szTemp);
			}
		}
		strValue = strFixStr.substr(equalSign + 1, soh - (equalSign + 1));
		pos = soh + 1;
	}

	// static GetByName 应用
public:
	static void GetByName(const std::string& strFixStr, std::string::size_type& pos, const char* szName, char* szValue, int nValueSize)
	{
		std::string strValue;
		ExtractFieldByName(strFixStr, pos, szName, strValue);
		strncpy(szValue, strValue.c_str(), nValueSize);
		szValue[nValueSize - 1] = '\0';
	}

	static void GetByName(const std::string& strFixStr, std::string::size_type& pos, const char* szName, char& cValue)
	{
		char szValue[32];
		GetByName(strFixStr, pos, szName, szValue, sizeof(szValue));
		cValue = szValue[0];
		if (cValue == 0)
			cValue = CHR_NULL;
	}

	static void GetByName(const std::string& strFixStr, std::string::size_type& pos, const char* szName, bool& bValue)
	{
		char cValue;
		GetByName(strFixStr, pos, szName, cValue);
		bValue = (cValue == '1' || cValue == 'T');
	}

	static void GetByName(const std::string& strFixStr, std::string::size_type& pos, const char* szName, int& nValue)
	{
		char szValue[32];
		GetByName(strFixStr, pos, szName, szValue, sizeof(szValue));
		nValue = atoi(szValue);
	}

	static void GetByName(const std::string& strFixStr, std::string::size_type& pos, const char* szName, unsigned& nValue)
	{
		char szValue[32];
		GetByName(strFixStr, pos, szName, szValue, sizeof(szValue));
		nValue = atoi(szValue);
	}

	static void GetByName(const std::string& strFixStr, std::string::size_type& pos, const char* szName, long& lValue)
	{
		char szValue[32];
		GetByName(strFixStr, pos, szName, szValue, sizeof(szValue));
		lValue = atol(szValue);
	}

	static void GetByName(const std::string& strFixStr, std::string::size_type& pos, const char* szName, short& nValue)
	{
		char szValue[32];
		GetByName(strFixStr, pos, szName, szValue, sizeof(szValue));
		nValue = atoi(szValue);
	}

	static void GetByName(const std::string& strFixStr, std::string::size_type& pos, const char* szName, int64& nValue)
	{
		char szValue[32];
		GetByName(strFixStr, pos, szName, szValue, sizeof(szValue));
		nValue = _atoi64(szValue);
	}

	static void GetByName(const std::string& strFixStr, std::string::size_type& pos, const char* szName, float& dbValue)
	{
		char szValue[32];
		GetByName(strFixStr, pos, szName, szValue, sizeof(szValue));
		dbValue = (float)atof(szValue);
	}

	static void GetByName(const std::string& strFixStr, std::string::size_type& pos, const char* szName, double& dbValue)
	{
		char szValue[32];
		GetByName(strFixStr, pos, szName, szValue, sizeof(szValue));
		dbValue = atof(szValue);
	}

private:
	static void ExtractFieldByName(const std::string& strFixStr, std::string::size_type& pos, const char* szName, std::string& strValue)
	{
		std::string::size_type equalSign = strFixStr.find_first_of('=', pos);
		if (equalSign == std::string::npos)
		{
			char szTemp[256];
			SAFESNPRINTF(szTemp, sizeof(szTemp), "%s", "CKmdsFix::ExtractFieldByNameFIX协议中字段未找到'='。");
			throw CKmdsFixException(2000,szTemp);
		}

		std::string::size_type soh = strFixStr.find_first_of('\001', equalSign + 1);
		if (soh == std::string::npos)
		{
			char szTemp[256];
			SAFESNPRINTF(szTemp, sizeof(szTemp), "%s", "CKmdsFix::ExtractFieldByNameFIX协议中字段未找到SOH(\001)。");
			throw CKmdsFixException(2000,szTemp);
		}

		std::string strName = string_toLower(strFixStr.substr(pos, equalSign - pos));
		if (stricmp(szName, strName.c_str()) != 0)
		{
			char szTemp[256];
			SAFESNPRINTF(szTemp, sizeof(szTemp), "CKmdsFix::ExtractFieldByNameFIX协议中字段[%s]未找到。", szName);
			throw CKmdsFixException(2000,szTemp);
		}

		strValue = strFixStr.substr(equalSign + 1, soh - (equalSign + 1));
		pos = soh + 1;
	}

private:
	void InternalAdd(const std::string strName, const std::string strValue)
	{
		std::pair<Name2ValueMap::iterator, bool> ret = m_mapName2Value.insert(Name2ValueMap::value_type(string_toLower(strName), strValue));
		if (ret.second)
			m_vectName.push_back(string_toLower(strName));
	}


	void InternalNoTranstoLower(const std::string strName, const std::string strValue)
	{
		std::pair<Name2ValueMap::iterator, bool> ret = m_mapName2Value.insert(Name2ValueMap::value_type(strName, strValue));
		if (ret.second)
			m_vectName.push_back(strName);
	}


	void InternalAdd(const char* szName, char cValue)
	{
		char szValue[2];
		szValue[0] = cValue;
		szValue[1] = 0;
		AddF(szName, szValue);
	}

	void InternalAdd(const char* szName, bool bValue)
	{
		char cValue = bValue ? '1' : '0';
		InternalAdd(szName, cValue);
	}

	void InternalAdd(const char* szName, int nValue)
	{
		AddF(szName, "%d", nValue);
	}

	void InternalAdd(const char* szName, unsigned nValue)
	{
		AddF(szName, "%d", nValue);
	}

	void InternalAdd(const char* szName, long lValue)
	{
		AddF(szName, "%ld", lValue);
	}

	void InternalAdd(const char* szName, short nValue)
	{
		AddF(szName, "%d", nValue);
	}

	void InternalAdd(const char* szName, int64 nValue)
	{
		AddF(szName, DEF_I64D, nValue);
	}

	void InternalAdd(const char* szName, float fValue)
	{
		std::string str;
		std::stringstream strm;
		strm<<fValue;
		strm>>str;
		AddF(szName, str.c_str());
	}

	void InternalAdd(const char* szName, double dbValue)
	{
		std::string str;
		std::stringstream strm;
		strm<<dbValue;
		strm>>str;
		AddF(szName, str.c_str());
	}

	const char* GetFullName(const char* szName, int nRecno)
	{
		if (nRecno > 0)
		{
			SAFESNPRINTF(m_szFullName, sizeof(m_szFullName), "%s%d", szName, nRecno);
			return(m_szFullName);
		}
		else
			return szName;
	}

	const char* InternalGet(const char* szName) const
	{
		Name2ValueMap::const_iterator theIter = m_mapName2Value.find(string_toLower(std::string(szName)));
		if (theIter == m_mapName2Value.end())
		{
			char szTemp[256];
			SAFESNPRINTF(szTemp, sizeof(szTemp), "CKmdsFix::InternalGetFIX协议中字段[%s]未找到。", szName);
			throw CKmdsFixException(2000,szTemp);
		}
		return theIter->second.c_str();
	}

	const char* InternalTryGet(const char* szName) const
	{
		Name2ValueMap::const_iterator theIter = m_mapName2Value.find(string_toLower(std::string(szName)));
		if (theIter == m_mapName2Value.end())
			return NULL;
		return theIter->second.c_str();
	}

	std::string InternalGetByString(const char* szName) const
	{
		Name2ValueMap::const_iterator theIter = m_mapName2Value.find(string_toLower(std::string(szName)));
		if (theIter == m_mapName2Value.end())
		{
			char szTemp[256];
			SAFESNPRINTF(szTemp, sizeof(szTemp), "CKmdsFix::InternalGetByStringFIX协议中字段[%s]未找到。", szName);
			throw CKmdsFixException(2000,szTemp);
		}
		return theIter->second;
	}
private:
	std::string		m_strFieldValue;
	char			m_szFullName[256];
	Name2ValueMap	m_mapName2Value;
	std::vector<std::string>	m_vectName;
};

#endif
