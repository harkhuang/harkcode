#ifndef __L_PRIVATEDATA_INCLUDE__
#define __L_PRIVATEDATA_INCLUDE__

#include "datatype.h"
#include "binarydata.h"
#include <lcomm/minipool.h>

#define FUNC_CPRIVATEDATA_SETDATA(type,datamember,fieldtype) \
void SetData(type paramdata) \
{ \
		/* Clear(); */ \
datamember = paramdata; \
m_ntype = fieldtype; \
}

class CPrivateData: public CMiniMemPoolInstance < CPrivateData, 10000 >
{
  DELARE_MINIMEMPOOL(CPrivateData, 10000);
protected:
  CPrivateData()
  {
    Init();
  }

public:
#ifdef _DEBUG
  // 调试溢出错误 前12个字段为key 后
  char m_szdebugkey[12];
  void SetKeyValue(char *lpszkey)
  {
    strncpy(m_szdebugkey, lpszkey, sizeof(m_szdebugkey) - 1);
    m_szdebugkey[sizeof(m_szdebugkey) - 1] = 0;
  }
#endif

  virtual ~CPrivateData()
  {
    Clear();
  }

  int Init()
  {
    m_n64 = I64Const(0);
    m_pcl_binarydata = NULL;
    m_ntype = FIELDP_INVAILD;

    m_szdata[0] = 0;
    m_pszdata = NULL;
    return 0;
  }

  int Uninit()
  {
    Clear();
    return 0;
  }


  FUNC_CPRIVATEDATA_SETDATA(int8, m_n8, FIELDP_INT8);
  FUNC_CPRIVATEDATA_SETDATA(int16, m_n16, FIELDP_INT16);
  FUNC_CPRIVATEDATA_SETDATA(int32, m_n32, FIELDP_INT32);
  FUNC_CPRIVATEDATA_SETDATA(int64, m_n64, FIELDP_INT64);

  FUNC_CPRIVATEDATA_SETDATA(uint8, m_nu8, FIELDP_UINT8);
  FUNC_CPRIVATEDATA_SETDATA(uint16, m_nu16, FIELDP_UINT16);
  FUNC_CPRIVATEDATA_SETDATA(uint32, m_nu32, FIELDP_UINT32);
  FUNC_CPRIVATEDATA_SETDATA(uint64, m_nu64, FIELDP_UINT64);

  FUNC_CPRIVATEDATA_SETDATA(float, m_float, FIELDP_FLOAT);
  FUNC_CPRIVATEDATA_SETDATA(double, m_double, FIELDP_DOUBLE);

  //	FUNC_CPRIVATEDATA_SETDATA(char *, m_strval, FIELDP_STRING);

  void SetData(char * lpszdata)
  {
    int nlen = (int)strlen(lpszdata);

    if (m_pszdata && m_pszdata != m_szdata)
    {
      free(m_pszdata);
      m_pszdata = NULL;
    }

    if (nlen < (int)sizeof(m_szdata))
    {
      m_pszdata = m_szdata;
    }
    else
    {
      m_pszdata = (char *)malloc(nlen + 1);
    }
		if (nlen >0)
		{
    	memcpy(m_pszdata, lpszdata, nlen);
		}
    m_pszdata[nlen] = 0;
    m_ntype = FIELDP_STRING;
  }


  int GetData(int8 &ndata)
  {
    if (m_ntype == FIELDP_INT8)
    {
      ndata = m_n8;
      return 0;
    }
    if (m_ntype == FIELDP_UINT8)
    {
      ndata = m_nu8;
      return 0;
    }
    if (m_ntype == FIELDP_STRING)
    {
      ndata = static_cast < int8 > (atoi((char *)m_pszdata));
      return 0;
    }
    ndata = 0;
    return -1;
  }

  int GetData(int16 &ndata)
  {
    if (m_ntype == FIELDP_INT8)
    {
      ndata = m_n8;
      return 0;
    }
    if (m_ntype == FIELDP_UINT8)
    {
      ndata = m_nu8;
      return 0;
    }

    if (m_ntype == FIELDP_INT16)
    {
      ndata = m_n16;
      return 0;
    }
    if (m_ntype == FIELDP_UINT16)
    {
      ndata = m_nu16;
      return 0;
    }
    if (m_ntype == FIELDP_STRING)
    {
      ndata = static_cast < int16 > (atoi((char *)m_pszdata));
      return 0;
    }
    ndata = 0;
    return -1;
  }

  int GetData(int32 &ndata)
  {
    if (m_ntype == FIELDP_INT8)
    {
      ndata = m_n8;
      return 0;
    }
    if (m_ntype == FIELDP_UINT8)
    {
      ndata = m_nu8;
      return 0;
    }

    if (m_ntype == FIELDP_INT16)
    {
      ndata = m_n16;
      return 0;
    }
    if (m_ntype == FIELDP_UINT16)
    {
      ndata = m_nu16;
      return 0;
    }

    if (m_ntype == FIELDP_INT32)
    {
      ndata = m_n32;
      return 0;
    }
    if (m_ntype == FIELDP_UINT32)
    {
      ndata = m_nu32;
      return 0;
    }

    if (m_ntype == FIELDP_INT64)
    {
      ndata = INT64ToINT32(m_n64);
      return 0;
    }
    if (m_ntype == FIELDP_UINT64)
    {
      ndata = UINT64ToINT32(m_nu64);
      return 0;
    }

    if (m_ntype == FIELDP_STRING)
    {
      ndata = static_cast < int32 > (atoi((char *)m_pszdata));
      return 0;
    }
    ndata = 0;
    return -1;
  }

  int GetData(int64 &ndata)
  {
    if (m_ntype == FIELDP_INT8)
    {
      ndata = m_n8;
      return 0;
    }
    if (m_ntype == FIELDP_UINT8)
    {
      ndata = m_nu8;
      return 0;
    }

    if (m_ntype == FIELDP_INT16)
    {
      ndata = m_n16;
      return 0;
    }
    if (m_ntype == FIELDP_UINT16)
    {
      ndata = m_nu16;
      return 0;
    }

    if (m_ntype == FIELDP_INT32)
    {
      ndata = m_n32;
      return 0;
    }
    if (m_ntype == FIELDP_UINT32)
    {
      ndata = m_nu32;
      return 0;
    }

    if (m_ntype == FIELDP_INT64)
    {
      ndata = m_n64;
      return 0;
    }
    if (m_ntype == FIELDP_UINT64)
    {
      ndata = m_nu64;
      return 0;
    }

    if (m_ntype == FIELDP_STRING)
    {
      ndata = ATOI64((char *)m_pszdata);
      return 0;
    }
    ndata = I64Const(0);
    return -1;
  }

  int GetData(uint8 &ndata)
  {
    if (m_ntype == FIELDP_INT8)
    {
      ndata = m_n8;
      return 0;
    }
    if (m_ntype == FIELDP_UINT8)
    {
      ndata = m_nu8;
      return 0;
    }
    if (m_ntype == FIELDP_STRING)
    {
      ndata = static_cast < uint8 > (atoi((char *)m_pszdata));
      return 0;
    }
    ndata = 0;
    return -1;
  }

  int GetData(uint16 &ndata)
  {
    if (m_ntype == FIELDP_INT8)
    {
      ndata = m_n8;
      return 0;
    }
    if (m_ntype == FIELDP_UINT8)
    {
      ndata = m_nu8;
      return 0;
    }

    if (m_ntype == FIELDP_INT16)
    {
      ndata = m_n16;
      return 0;
    }
    if (m_ntype == FIELDP_UINT16)
    {
      ndata = m_nu16;
      return 0;
    }
    if (m_ntype == FIELDP_STRING)
    {
      ndata = static_cast < uint16 > (atoi((char *)m_pszdata));
      return 0;
    }
    ndata = 0;
    return -1;
  }

  int GetData(uint32 &ndata)
  {
    if (m_ntype == FIELDP_INT8)
    {
      ndata = m_n8;
      return 0;
    }
    if (m_ntype == FIELDP_UINT8)
    {
      ndata = m_nu8;
      return 0;
    }

    if (m_ntype == FIELDP_INT16)
    {
      ndata = m_n16;
      return 0;
    }
    if (m_ntype == FIELDP_UINT16)
    {
      ndata = m_nu16;
      return 0;
    }

    if (m_ntype == FIELDP_INT32)
    {
      ndata = m_n32;
      return 0;
    }
    if (m_ntype == FIELDP_UINT32)
    {
      ndata = m_nu32;
      return 0;
    }

    if (m_ntype == FIELDP_INT64)
    {
      ndata = INT64ToINT32(m_n64);
      return 0;
    }
    if (m_ntype == FIELDP_UINT64)
    {
      ndata = UINT64ToINT32(m_nu64);
      return 0;
    }

    if (m_ntype == FIELDP_STRING)
    {
      ndata = static_cast < uint32 > (atoi((char *)m_pszdata));
      return 0;
    }
    ndata = 0;
    return -1;
  }

  int GetData(uint64 &ndata)
  {
    if (m_ntype == FIELDP_INT8)
    {
      ndata = m_n8;
      return 0;
    }
    if (m_ntype == FIELDP_UINT8)
    {
      ndata = m_nu8;
      return 0;
    }

    if (m_ntype == FIELDP_INT16)
    {
      ndata = m_n16;
      return 0;
    }
    if (m_ntype == FIELDP_UINT16)
    {
      ndata = m_nu16;
      return 0;
    }

    if (m_ntype == FIELDP_INT32)
    {
      ndata = m_n32;
      return 0;
    }
    if (m_ntype == FIELDP_UINT32)
    {
      ndata = m_nu32;
      return 0;
    }

    if (m_ntype == FIELDP_INT64)
    {
      ndata = m_n64;
      return 0;
    }
    if (m_ntype == FIELDP_UINT64)
    {
      ndata = m_nu64;
      return 0;
    }

    if (m_ntype == FIELDP_STRING)
    {
      ndata = static_cast < uint64 > (ATOI64((char *)m_pszdata));
      return 0;
    }
    ndata = I64Const(0);
    return -1;
  }


  int GetData(float &fdata)
  {
    if (m_ntype == FIELDP_FLOAT)
    {
      fdata = m_float;
      return 0;
    }

    if (m_ntype == FIELDP_STRING)
    {
      fdata = static_cast < float > (atof((char *)m_pszdata));
      return 0;
    }

    fdata = 0.0;
    return -1;
  }

  int GetData(double &ddata)
  {
    if (m_ntype == FIELDP_FLOAT)
    {
      ddata = m_float;
      return 0;
    }
    if (m_ntype == FIELDP_DOUBLE)
    {
      ddata = m_double;
      return 0;
    }

    if (m_ntype == FIELDP_STRING)
    {
      ddata = atof((char *)m_pszdata);
      return 0;
    }

    ddata = 0.0;
    return -1;
  }

  int GetData(char *lpszdata, int nmaxbuflen)
  {
    if (nmaxbuflen <= 0 || lpszdata == NULL)
    {
      return -1;
    }

    if (m_ntype == FIELDP_UINT8)
    {
      _snprintf(lpszdata, nmaxbuflen - 1, "%u", (uint32)m_nu8);
      lpszdata[nmaxbuflen - 1] = 0;
      return 0;
    }

    if (m_ntype == FIELDP_UINT16)
    {
      _snprintf(lpszdata, nmaxbuflen - 1, "%u", (uint32)m_nu16);
      lpszdata[nmaxbuflen - 1] = 0;
      return 0;
    }

    if (m_ntype == FIELDP_UINT32)
    {
      _snprintf(lpszdata, nmaxbuflen - 1, "%u", m_nu32);
      lpszdata[nmaxbuflen - 1] = 0;
      return 0;
    }

    if (m_ntype == FIELDP_UINT64)
    {
#ifdef _WIN32		
      _snprintf(lpszdata, nmaxbuflen - 1, "%I64u", m_nu64);
#else
	  _snprintf(lpszdata,nmaxbuflen -1,"%llu",m_nu64);
#endif
      lpszdata[nmaxbuflen - 1] = 0;
      return 0;
    }

    if (m_ntype == FIELDP_INT8)
    {
      _snprintf(lpszdata, nmaxbuflen - 1, "%d", (int32)m_n8);
      lpszdata[nmaxbuflen - 1] = 0;
      return 0;
    }

    if (m_ntype == FIELDP_INT16)
    {
      _snprintf(lpszdata, nmaxbuflen - 1, "%d", (int32)m_n16);
      lpszdata[nmaxbuflen - 1] = 0;
      return 0;
    }

    if (m_ntype == FIELDP_INT32)
    {
      _snprintf(lpszdata, nmaxbuflen - 1, "%d", m_n32);
      lpszdata[nmaxbuflen - 1] = 0;
      return 0;
    }

    if (m_ntype == FIELDP_INT64)
    {
		_snprintf(lpszdata, nmaxbuflen - 1, DEF_I64D, m_n64);
	  lpszdata[nmaxbuflen - 1] = 0;
      return 0;
    }

    if (m_ntype == FIELDP_FLOAT)
    {
      _snprintf(lpszdata, nmaxbuflen - 1, "%.3f", m_float);
      lpszdata[nmaxbuflen - 1] = 0;
      return 0;
    }

    if (m_ntype == FIELDP_DOUBLE)
    {
      _snprintf(lpszdata, nmaxbuflen - 1, "%.3f", m_double);
      lpszdata[nmaxbuflen - 1] = 0;
      return 0;
    }

    if (m_ntype == FIELDP_STRING)
    {
      _snprintf(lpszdata, nmaxbuflen - 1, "%s", (char *)m_pszdata);
      lpszdata[nmaxbuflen - 1] = 0;
      return 0;
    }

    return -1;
  }

  void SetData(void *pdata, int nlen)
  {
    //Clear();
    m_pcl_binarydata = new CBinaryData;
    m_pcl_binarydata->SetBufData(pdata, nlen);
    m_ntype = FIELDP_BINARY;
  }

  int GetData(void **ppdata, int &nlen)
  {
    if (ppdata == NULL)
    {
      (*ppdata) = NULL;
      nlen = 0;
      return -1;
    }

    if (m_ntype == FIELDP_BINARY && m_pcl_binarydata)
    {
      m_pcl_binarydata->GetBufData(ppdata, nlen);
      return 0;
    }

    (*ppdata) = NULL;
    nlen = 0;
    return -1;
  }

  FIELDP_TYPE GetType()
  {
    return m_ntype;
  }

private:
  FIELDP_TYPE m_ntype;

  union
  {
    int8 m_n8;
    int16 m_n16;
    int32 m_n32;
    int64 m_n64;
    uint8 m_nu8;
    uint16 m_nu16;
    uint32 m_nu32;
    uint64 m_nu64;
    float m_float;
    double m_double;
  };
  char m_szdata[32];
  char *m_pszdata;
  CBinaryData * m_pcl_binarydata;
private:
  int Clear()
  {
    if (m_ntype == FIELDP_BINARY && m_pcl_binarydata != NULL)
    {
      delete m_pcl_binarydata;
      m_pcl_binarydata = NULL;
    }

    if (m_pszdata && m_pszdata != m_szdata)
    {
      free(m_pszdata);
      m_szdata[0] = 0;
      m_pszdata = NULL;
    }

    if (m_ntype != FIELDP_INVAILD)
    {
      Init();
    }
    return 0;
  }

};

#endif // __L_PRIVATEDATA_INCLUDE__
