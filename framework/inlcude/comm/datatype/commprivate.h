
#ifndef __L_COMMPRIVATEDATA_INCLUDE__
#define __L_COMMPRIVATEDATA_INCLUDE__

#include "privatedata.h"
#include <map>
#include <kdcomidl/ICommMsgData.h>

#define FUNCIMP_CPRIVATEDATA_PUTDATA(funcname,fieldtype) \
STDMETHOD(funcname)(LPCTSTR pszKey, fieldtype paramdata) \
{ \
  CPrivateData *pdata = Reset(pszKey);  \
  pdata->SetData((fieldtype)paramdata);  \
  return S_OK; \
}

#define FUNCIMP_CPRIVATEDATA_GETDATA(funcname,fieldtype) \
STDMETHOD(funcname)(LPCTSTR pszKey, fieldtype *paramdata) \
{ \
  CPrivateData *pdata = Find(pszKey); \
  if (pdata == NULL) \
  { \
    return E_FAIL; \
  } \
  if (pdata->GetData((fieldtype &)(*paramdata)) != 0) \
  { \
    return E_FAIL; \
  } \
  return S_OK; \
}

class CCommPrivate:
            public CComObjectRootEx < CComSingleThreadModel > ,
            public CComCoClass < CCommPrivate > ,
            public ICommPrivate
	{
	public:
			CCommPrivate()
			{
			}
	
			DECLARE_NO_REGISTRY()
			DECLARE_NOT_AGGREGATABLE(CCommPrivate)
			DECLARE_PROTECT_FINAL_CONSTRUCT()
	
			BEGIN_COM_MAP(CCommPrivate)
			COM_INTERFACE_ENTRY(ICommPrivate)
			END_COM_MAP()
	
			HRESULT FinalConstruct()
			{
					return S_OK;
			}
			
			void FinalRelease()
			{
					Clear();
			}
		
    // 设置数据
		FUNCIMP_CPRIVATEDATA_PUTDATA(PutData_Int8, signed char);
		FUNCIMP_CPRIVATEDATA_PUTDATA(PutData_Int16, signed short);
		FUNCIMP_CPRIVATEDATA_PUTDATA(PutData_Int32, signed int);
		FUNCIMP_CPRIVATEDATA_PUTDATA(PutData_Int64, signed __int64);
		
		FUNCIMP_CPRIVATEDATA_PUTDATA(PutData_UInt8, unsigned char);
		FUNCIMP_CPRIVATEDATA_PUTDATA(PutData_UInt16, unsigned short);
		FUNCIMP_CPRIVATEDATA_PUTDATA(PutData_UInt32, unsigned int);
		FUNCIMP_CPRIVATEDATA_PUTDATA(PutData_UInt64, unsigned __int64);
		
		FUNCIMP_CPRIVATEDATA_PUTDATA(PutData_Float, float);
		FUNCIMP_CPRIVATEDATA_PUTDATA(PutData_Double, double);
		FUNCIMP_CPRIVATEDATA_PUTDATA(PutData, LPTSTR);

		STDMETHOD(PutData_Buf)(LPCTSTR pszKey, BYTE *pbuf, DWORD dwlen)
		{
				CPrivateData *pdata = Reset(pszKey);
				pdata->SetData((void *)pbuf, dwlen);
				return S_OK;
		};
	
		FUNCIMP_CPRIVATEDATA_GETDATA(GetData_Int8, signed char);
		FUNCIMP_CPRIVATEDATA_GETDATA(GetData_Int16, signed short);
		FUNCIMP_CPRIVATEDATA_GETDATA(GetData_Int32, signed int);
		FUNCIMP_CPRIVATEDATA_GETDATA(GetData_Int64, signed __int64);
		
		FUNCIMP_CPRIVATEDATA_GETDATA(GetData_UInt8, unsigned char);
		FUNCIMP_CPRIVATEDATA_GETDATA(GetData_UInt16, unsigned short);
		FUNCIMP_CPRIVATEDATA_GETDATA(GetData_UInt32, unsigned int);
		FUNCIMP_CPRIVATEDATA_GETDATA(GetData_UInt64, unsigned __int64);
		
		FUNCIMP_CPRIVATEDATA_GETDATA(GetData_Float, float);
		FUNCIMP_CPRIVATEDATA_GETDATA(GetData_Double, double);
		STDMETHOD(GetData_Buf)(LPCTSTR pszKey, BYTE **pbuf, DWORD *pdwlen)
		{
				CPrivateData *pdata = Find(pszKey);
				if (pdata == NULL)
				{
						return E_FAIL;
				}
		
				if (pdata->GetData((void **)pbuf, (int &)(*pdwlen)) != 0)
				{
						return E_FAIL;
				}
				return S_OK;
		}
		
		STDMETHOD(GetData)(LPCTSTR pszKey, BSTR *pbstrValue)
		{
				CPrivateData *pdata = Find(pszKey);
				if (pdata == NULL)
				{
						return E_FAIL;
				}
		
				char szstr[4096] = {0};
				if (pdata->GetData((char *)szstr, (int)(sizeof(szstr) - 1)) != 0)
				{
						return E_FAIL;
				}
				szstr[sizeof(szstr) - 1] = 0;
				CComBSTR bstrTemp(szstr);
				*pbstrValue = bstrTemp.Detach();
				return S_OK;
		}
		
		STDMETHOD(GetData_String)(/* [in] */LPCTSTR pszKey,/* [in] */BYTE *pbValue,/* [in] */int nmaxlen)
		{
				if (pbValue == NULL || nmaxlen <=0)
				{
					return E_FAIL;
				}
				pbValue[0] = 0;
		
				CPrivateData *pdata = Find(pszKey);
				if (pdata == NULL)
				{
						return E_FAIL;
				}
				
				if (pdata->GetData((char *)pbValue, (int)(nmaxlen - 1)) != 0)
				{
						return E_FAIL;
				}
				pbValue[nmaxlen - 1] = 0;
				return S_OK;	
		}

	CPrivateData * Reset(LPCTSTR pszKey)
	{
	  CPrivateData *pdata = NULL;
  	 map_kvdatas::iterator itpos;
		 itpos = m_map_kvdatas.find((char *)pszKey);
		 if (itpos != m_map_kvdatas.end())
		 {
				 pdata = itpos->second;
		 }
     if (!pdata)
     {
        pdata = CPrivateData::CreateFromPool();
        #ifdef _DEBUG
          pdata->SetKeyValue((char *)pszKey);
        #endif
        if (!m_map_kvdatas.insert(std::make_pair((char *)pszKey, pdata)).second)
        {
         // KD_ASSERT(false);
					return NULL;
        }
     }
	   return pdata;
	}

	CPrivateData * Find(LPCTSTR pszKey)
	{
		 map_kvdatas::iterator itpos;
		 itpos = m_map_kvdatas.find((char *)pszKey);
		 if (itpos != m_map_kvdatas.end())
		 {
				 return itpos->second;
		 }
		return NULL;
	}

	void Clear()
	{
			map_kvdatas::iterator itpos;
			for (itpos = m_map_kvdatas.begin();
							itpos != m_map_kvdatas.end();
							++ itpos)
			{
					CPrivateData *pdata = itpos->second;
	
					pdata->ReleaseToPool(pdata);
					// delete pdata;
			}
			m_map_kvdatas.clear();
	}
	STDMETHOD(ClearAll)()
	{
			Clear();
			return S_OK;
	}
	STDMETHOD(DeleteItem)(LPCTSTR pszKey)
	{
 			map_kvdatas::iterator itpos;
	
			itpos = m_map_kvdatas.find((char *)pszKey);
	
			if (itpos != m_map_kvdatas.end())
			{
					CPrivateData *pdata = itpos->second;
					m_map_kvdatas.erase(itpos); 			
					pdata->ReleaseToPool(pdata);
					return S_OK;
			}
 
		return E_FAIL;
	}

	// 数据是否存在
	STDMETHOD(HaveData)(LPCTSTR pszKey)
	{
			CPrivateData *pdata = Find(pszKey);
			if (pdata == NULL)
			{
					return E_FAIL;
			}
			return S_OK;
	}
	
	// 获取数据类型
	STDMETHOD(GetDataType)(LPCTSTR pszKey, DWORD *pdwValue)
	{
			CPrivateData *pdata = Find(pszKey);
			if (pdata == NULL)
			{
					*pdwValue = FIELDP_INVAILD;
					return E_FAIL;
			}
			*pdwValue = pdata->GetType();
			return S_OK;
	}


	STDMETHOD(GoFirst)()
	{
			m_it_map_kvdatas = m_map_kvdatas.begin();
	
			if (m_it_map_kvdatas == m_map_kvdatas.end())
			{
					return E_FAIL;
			}
			return S_OK;
	}
	
	STDMETHOD(MoveNext)()
	{
			++ m_it_map_kvdatas;
	
			if (m_it_map_kvdatas == m_map_kvdatas.end())
			{
					return E_FAIL;
			}
			return S_OK;
	}
	
	STDMETHOD(GetCurrentType)(DWORD *pdwType)
	{
			*pdwType = FIELDP_INVAILD;
			if (m_it_map_kvdatas == m_map_kvdatas.end())
			{
					return E_FAIL;
			}
			CPrivateData *pdata = m_it_map_kvdatas->second;
			if (pdata == NULL)
			{
					return E_FAIL;
			}
			*pdwType = pdata->GetType();
			return S_OK;
	}
	
	STDMETHOD(GetCurrentData)(BSTR *pbstrKey, BSTR *pbstrValue)
	{
			if (m_it_map_kvdatas == m_map_kvdatas.end())
			{
					return E_FAIL;
			}
			CPrivateData *pdata = m_it_map_kvdatas->second;
			if (pdata == NULL)
			{
					return E_FAIL;
			}
	
			char szstr[4096] = {0};
			if (pdata->GetData((char *)szstr, (int)(sizeof(szstr) - 1)) != 0)
			{
					return E_FAIL;
			}
			szstr[sizeof(szstr) - 1] = 0;
			CComBSTR bstrTemp(szstr);
			*pbstrValue = bstrTemp.Detach();
			SAFESTRNCPY(szstr, m_it_map_kvdatas->first.c_str());
			bstrTemp = szstr;
			*pbstrKey = bstrTemp.Detach();
			return S_OK;
	}
	
	STDMETHOD(GetCurrentDataWithType)(BSTR *pbstrKey, BSTR *pbstrValue, DWORD *pdwType)
	{
			*pdwType = FIELDP_INVAILD;
			if (m_it_map_kvdatas == m_map_kvdatas.end())
			{
					return E_FAIL;
			}
			CPrivateData *pdata = m_it_map_kvdatas->second;
			if (pdata == NULL)
			{
					return E_FAIL;
			}
			char szstr[4096] = {0};
			if (pdata->GetData((char *)szstr, (int)(sizeof(szstr) - 1)) != 0)
			{
					return E_FAIL;
			}
			szstr[sizeof(szstr) - 1] = 0;
			CComBSTR bstrTemp(szstr);
			*pbstrValue = bstrTemp.Detach();
			SAFESTRNCPY(szstr, (char *)m_it_map_kvdatas->first.c_str());
			bstrTemp = szstr;
			*pbstrKey = bstrTemp.Detach();
	
			*pdwType = pdata->GetType();
			return S_OK;
	}

	STDMETHOD(Dump)(enum EM_DUMP_FORMAT nformat,BSTR *pbstrDump)
	{
		CComBSTR bstrdump;
	  char szline[4096] = {0};
	  char szname[255 + 1] = {0};
	  char szstr[4096] = {0};
		int i =0;
	  int nrelaoutlen = 0;	
		return S_OK;
	}
	
	private:
		typedef std::map < std::string, CPrivateData * > map_kvdatas;
		map_kvdatas m_map_kvdatas;
    map_kvdatas::iterator m_it_map_kvdatas;

};
#endif
