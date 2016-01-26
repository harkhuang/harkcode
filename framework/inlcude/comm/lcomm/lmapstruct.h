

#ifndef __L_MAP_STRUCT_DATA_INCLUDE__
#define __L_MAP_STRUCT_DATA_INCLUDE__

// 实际封装 map 对象 包括

// Tfirst 表示 map的第一个 KEY 参数
// TSecond 表示 map的第二个 VALUE 参数 ，必须是 可以 new delete 可以分配的数据结构

// 用于 对map 对象第二个参数的自动释放 和 顺序函数访问 

/*
   2012/11/30 lium CLMapStruct
   增加删除当前单只 bool DeleteCurrentItem();
   增加拷贝数据串到另外一个CLMapStruct中 int CopyToMap(CLMapStruct<Tfirst, TSecond, LMapCmp, TMapClass > &rhs);
   增加带KEY删除单只 bool DeleteWithKey(Tfirst &tfirst);  注意:删除后应立即返回，不要对MAP在进行任何操作

   2012/12/05 lium CLMapStructByString
   增加 Key 为 std::tring 的重载类，便于外部使用 char *操作
   声明使用 CLMapStructByString<[struct name]> 既可, Key 默认 std::string

   2012/12/10 lium DeleteCurrentItem() 问题修正
*/

#include<stdlib.h>
#include<string.h>
#include<map>
#include<string>

template < typename Tfirst, typename TSecond, typename LMapCmp = std::less < Tfirst > , typename TMapClass = std::map < Tfirst, TSecond *, LMapCmp > >
class CLBaseMapStruct
{
public:
  virtual int __Free(TSecond **ppdata) = 0;
  virtual int __Malloc(TSecond **ppdata) = 0;
  virtual int __Clear() = 0;
};

template < typename Tfirst, typename TSecond, typename LMapCmp = std::less < Tfirst > , typename TMapClass = std::map < Tfirst, TSecond *, LMapCmp >,bool bautodelete = true>
class CLMapStruct: public CLBaseMapStruct<Tfirst, TSecond, LMapCmp, TMapClass>
{
	 enum { m_bautodelete = bautodelete };
		friend class CLMapStruct_Iterator;	
public:
  CLMapStruct()
  {
    Clear();
  }
  virtual ~CLMapStruct()
  {
    Clear();
  }

  int Clear()
  {
  	if (!m_bautodelete)
  	{
		m_map_datas.clear();
  		return 0;
  	}
    map_datas_iterator itpos;
    for (itpos = m_map_datas.begin();
         itpos != m_map_datas.end();
         ++itpos)
    {
      TSecond *pdata = itpos->second;
      __Free(&pdata);
    }
    m_map_datas.clear();
    m_itpos_current = m_map_datas.begin();
    m_itpos_realcurrent = m_itpos_current;
    __Clear();
    return 0;
  }

  int AddData(Tfirst &tfirst, TSecond *psecond, bool bcopy = true)
  {
	int nret = 0;
    if (bcopy)
    {
      TSecond * __psecond = NULL;
      __Malloc(&__psecond);
      if (__psecond)
      {
      memcpy(__psecond, psecond, sizeof(TSecond));
      psecond = __psecond;
    }
      else
      {
        psecond = NULL;
      }
    }
    if (psecond)
    {
		TSecond *pdata = FindItem(tfirst);
		if (pdata != NULL)
		{
			nret = -1;
		}
    m_map_datas.insert(std::make_pair(tfirst, psecond));
       // return (m_map_datas.insert(std::make_pair(tfirst, psecond)).second == true) ? 0 : -1;
    }
    return nret;
  }

  int GetSize()
  {
    return (int)m_map_datas.size();
  }

  TSecond *FindItem(Tfirst &tfirst)
  {
    TSecond *__psecond = NULL;
    map_datas_iterator itpos = m_map_datas.find(tfirst);
    if (itpos != m_map_datas.end())
    {
      __psecond = itpos->second;
    }
    return __psecond;
  }

  int GetFirst(TSecond ** ppsecond)
  {
	 TSecond * psecond = NULL;
	(* ppsecond) = NULL;
    map_datas_iterator itpos = m_map_datas.begin();
    if (itpos == m_map_datas.end())
    {
      return -1;
    }
	psecond = itpos->second;
	(* ppsecond) = psecond;
    return 0;
  }

  int FindItem(Tfirst &tfirst,TSecond ** ppsecond)
  {
    (* ppsecond) = NULL;
    map_datas_iterator itpos = m_map_datas.find(tfirst);
    if (itpos != m_map_datas.end())
    {
      (*ppsecond)  = itpos->second;
		return 0;
    }
    return -1;
  }

	// 0: 存在 -1:不存在 -2:到达底部
  int FindItem_NextData(Tfirst &tfirst,TSecond ** ppsecond)
  {
    (* ppsecond) = NULL;
    map_datas_iterator itpos = m_map_datas.find(tfirst);
    if (itpos != m_map_datas.end())
    {
    	++ itpos;
			if (itpos != m_map_datas.end())	
			{
				(*ppsecond)  = itpos->second;
				return 0;
			}
      return -2; 
    }
    return -1;
  }
	
	// 0: 存在 -1:不存在 -2:到达顶部
  int FindItem_PreData(Tfirst &tfirst,TSecond ** ppsecond)
  {
    (* ppsecond) = NULL;
    map_datas_iterator itpos = m_map_datas.find(tfirst);
    if (itpos != m_map_datas.end())
    {
    	if (itpos == m_map_datas.begin())
    	{
    		return -2;
    	}
    	-- itpos;
			(*ppsecond)  = itpos->second;
			return 0;
    }
    return -1;
  }

  bool GoFirst()
  {
    m_itpos_current = m_map_datas.begin();
    m_itpos_realcurrent = m_itpos_current;
    if (m_itpos_current == m_map_datas.end())
    {
      return false;
    }
    return true;
  }

  bool GoEnd()
  {		
    if (m_map_datas.begin() == m_map_datas.end() ||
			  m_map_datas.size() ==0)
    {
      return false;
    }
    m_itpos_current = m_map_datas.end();
		-- m_itpos_current;

    return true;
  }

  bool GetCurrentData(Tfirst &tfirst, TSecond **ppsecond)
  {
    (*ppsecond) = NULL;
    if (m_itpos_current == m_map_datas.end())
    {
      return false;
    }
    tfirst = m_itpos_current->first;
    (*ppsecond) = m_itpos_current->second;
    m_itpos_realcurrent = m_itpos_current;
    ++ m_itpos_current;
    return true;
  }

  bool GetRangeItem(Tfirst &tfirst)
  {
    m_datas_pair = m_map_datas.equal_range(tfirst);
    if (m_datas_pair.first != m_map_datas.end())
    {
      m_itpos_equal_range = m_datas_pair.first;
      return true;
    }
    return false;
  }

  TSecond *GetNextRangeItem()
  {
    TSecond *__psecond = NULL;
    if (m_itpos_equal_range == m_map_datas.end() ||
        m_itpos_equal_range == m_datas_pair.second)
    {
      return __psecond;
    }
    __psecond = m_itpos_equal_range->second;

    m_itpos_equal_range_deleteitem = m_itpos_equal_range;

    ++ m_itpos_equal_range;
    return __psecond;
  }

  // 仅在 GoFirst 和	while GetCurrentData 中间使用
  // add by lium 2012/10/05 支持删除后的 GetCurrentData 操作类
  bool DeleteCurrentItem()
  {
    if (m_itpos_realcurrent == m_map_datas.end())
    {
      return false;
    }

    TSecond *pdata = m_itpos_realcurrent->second;
    __Free(&pdata);
    m_itpos_realcurrent = m_map_datas.erase(m_itpos_realcurrent);
    m_itpos_current = m_itpos_realcurrent;
    return true;
  }

  // 删除后应立即返回，不要对MAP在进行任何操作
  bool DeleteRangItem()
  {
    if (m_itpos_equal_range_deleteitem == m_map_datas.end())
    {
      return false;
    }
		TSecond *pdata = m_itpos_equal_range_deleteitem->second;
    __Free(&pdata);
    m_map_datas.erase(m_itpos_equal_range_deleteitem);
    return true;
  }

	int CopyToMap(CLMapStruct<Tfirst, TSecond, LMapCmp, TMapClass > &rhs)
	{
		Tfirst tfirst;
		TSecond *psecond = NULL;
		rhs.Clear();

		GoFirst();
		while (GetCurrentData(tfirst, &psecond) &&psecond)
		{
			rhs.AddData(tfirst, psecond);
		}
		
		return 0;
	}

  // 删除后应立即返回，不要对MAP在进行任何操作
		bool DeleteWithKey(Tfirst &tfirst)
		{
			map_datas_iterator itpos = m_map_datas.find(tfirst);
			if (itpos != m_map_datas.end())
			{
				TSecond *pdata = itpos->second;
      __Free(&pdata);
      m_map_datas.erase(itpos);
      return true;
    }
    return false;
  }

  int __Free(TSecond **ppdata)
  {
    int nret = -1;
    if (ppdata == NULL || *ppdata == NULL)
				{
      return nret;
    }

    TSecond *pdata = (*ppdata);
					delete pdata;
    (*ppdata) = NULL;
    return 0;
				}

  int __Malloc(TSecond **ppdata)
  {
    TSecond *pdata = NULL;
    pdata = new TSecond;
    (*ppdata) = pdata;
    return 0;
			}

  int __Clear()
  {
    return 0;
		}

//private:
#ifdef _WIN32
  typedef typename TMapClass map_datas;
#else
  typedef TMapClass map_datas;
#endif

  typedef typename TMapClass::iterator map_datas_iterator;
  typedef typename TMapClass::reverse_iterator map_datas_riterator;

  typedef typename std::pair < map_datas_iterator, map_datas_iterator > map_datas_pair;
  map_datas m_map_datas;
  map_datas_iterator m_itpos_current;
  map_datas_iterator m_itpos_realcurrent;

  map_datas_pair m_datas_pair;
  map_datas_iterator m_itpos_equal_range;
  map_datas_iterator m_itpos_equal_range_deleteitem;     // map 删除的对应 iterator

  // make T non-copyable
private:
  CLMapStruct( const CLMapStruct& );                // not implemented
  CLMapStruct& operator=( const CLMapStruct& );     // not implemented
}
;


// 增加 Key 为 std::tring 的重载类，便于外部使用 char * 操作
// FindItem AddData 可以直接使用 char *
template <typename TSecond >
class CLMapStructByString: public CLMapStruct<std::string, TSecond>
{
public:
  TSecond *FindItem(std::string strdata)
  {
    return CLMapStruct<std::string, TSecond>::FindItem(strdata);
  }

  TSecond *FindItem(char *lpszdata)
  {
    std::string str = lpszdata;
    return CLMapStruct<std::string, TSecond>::FindItem(str);
  }

  int AddData(std::string strdata, TSecond *psecond, bool bcopy = true)
  {
    return CLMapStruct<std::string, TSecond>::AddData(strdata, psecond, bcopy);
  }

  int AddData(char *lpszdata, TSecond *psecond, bool bcopy = true)
  {
    std::string str = lpszdata;
    return CLMapStruct<std::string, TSecond>::AddData(str, psecond, bcopy);
  }

  bool GetCurrentData(std::string &strdata, TSecond **ppsecond)
  {
    return CLMapStruct<std::string, TSecond>::GetCurrentData(strdata, ppsecond);
  }

  bool GetCurrentData(char *lpszdata, int nmaxlen, TSecond **ppsecond)
  {
    bool bresult = false;
    std::string str = lpszdata;
    bresult = GetCurrentData(str, ppsecond);
    if (nmaxlen > 0)
    {
      strncpy(lpszdata, (const char *)str.c_str(), nmaxlen);
      lpszdata[nmaxlen - 1] = 0;
    }
    return bresult;
  }

  // 从 int 的 map 数据拷贝到本 String 类中
  // noffset 为 Key 从原 map的结构中取得 offset(struct name,field name);
  int CopyFromIntMap(CLMapStruct<int, TSecond> &mapint_datas, int noffset)
  {
    int nret = -1;
    int nct = 0;

    TSecond *pst_data = NULL;
    char *pszdata = NULL;
    CLMapStruct<std::string, TSecond>::Clear();
    mapint_datas.GoFirst();
    while (mapint_datas.GetCurrentData(nct, &pst_data) && pst_data)
    {
      pszdata = (char *)((char *)pst_data + noffset);
      if (pszdata)
      {
        AddData(pszdata, pst_data);
      }
    }
    nret = 0;
    return nret;
  }
};


template < typename Tfirst, typename TSecond, typename LMapCmp = std::less < Tfirst > , typename TMapClass = std::map < Tfirst, TSecond *, LMapCmp >, bool bautodelete = true >
class CLMallocMapStruct: public CLMapStruct<Tfirst, TSecond, LMapCmp, TMapClass, bautodelete>
{
public:
  CLMallocMapStruct(int ninitmalloc = 0)
  {
    m_ninitmalloc = 0;
    m_nmalloc_used = 0;
    m_pmalloc_data = NULL;

    if (m_pmalloc_data == NULL && ninitmalloc > 0)
    {
      m_pmalloc_data = (void *)malloc(ninitmalloc * sizeof(TSecond));
      if (m_pmalloc_data)
      {
        m_ninitmalloc = ninitmalloc;
        memset(m_pmalloc_data, 0, ninitmalloc * sizeof(TSecond));
      }
    }
  }

  virtual ~CLMallocMapStruct()
  {
    CLMapStruct<Tfirst, TSecond, LMapCmp, TMapClass, bautodelete>::Clear();
    if (m_pmalloc_data)
    {
      free(m_pmalloc_data);
      m_pmalloc_data = NULL;
    }
  }


  bool IsInMalloced(void *pdata)
  {
    if (m_pmalloc_data != NULL && m_ninitmalloc > 0)
    {
      if (pdata >= m_pmalloc_data  &&
          pdata < ((char *)m_pmalloc_data + m_ninitmalloc * sizeof(TSecond)))
      {
        return true;
      }
    }
    return false;
  }

  int __Free(TSecond **ppdata)
  {
    TSecond *pdata = (*ppdata);
    if (pdata)
    {
      if (!IsInMalloced(pdata))
      {
        free((void *)pdata);
      }
    }
    (*ppdata) = NULL;
    return 0;
  }

  int __Malloc(TSecond **ppdata)
  {
    int nret = -1;
    if (ppdata == NULL || *ppdata == NULL)
    {
      return nret;
    }
    TSecond *pdata = NULL;
    if (m_pmalloc_data != NULL && m_ninitmalloc > 0 && m_nmalloc_used < m_ninitmalloc)
    {
      pdata = (TSecond *)((char *)m_pmalloc_data + m_nmalloc_used * sizeof(TSecond));
      m_nmalloc_used ++;
    }
    else
    {
      pdata = (TSecond *)malloc(sizeof(TSecond));
    }
    (*ppdata) = pdata;
    return 0;
  }

  int __Clear()
  {
    m_nmalloc_used = 0;
    return 0;
  }


private:

  // 初始化个数
  int m_ninitmalloc;
  int m_nmalloc_used;
  void *m_pmalloc_data;

};

template < typename Tfirst, typename TSecond, typename LMapCmp = std::less < Tfirst > , typename TMapClass = std::map < Tfirst, TSecond *, LMapCmp >,bool bautodelete = true>
class CLMapStruct_Scan
{
	typedef CLMapStruct<Tfirst,TSecond,LMapCmp,TMapClass,bautodelete> typedef_parent_mapstruct;
	public:
		CLMapStruct_Scan(typedef_parent_mapstruct * pmapstruct)
		{
        m_parent_mapstruct = pmapstruct;
				m_itpos_current = m_parent_mapstruct->m_map_datas.end();
		}

		bool GoFirst()
		{
			m_itpos_current = m_parent_mapstruct->m_map_datas.begin();
			if (m_itpos_current == m_parent_mapstruct->m_map_datas.end())
			{
				return false;
			}
			return true;
		}

		bool GetCurrentData(Tfirst &tfirst, TSecond **ppsecond)
		{
			(*ppsecond) = NULL;
			if (m_itpos_current == m_parent_mapstruct->m_map_datas.end())
			{
				return false;
			}
			tfirst = m_itpos_current->first;
			(*ppsecond) = m_itpos_current->second;
	
			++ m_itpos_current;
			return true;
		}
		
		virtual ~CLMapStruct_Scan()
  {};

	private:
		typename typedef_parent_mapstruct::map_datas_iterator m_itpos_current;
    typedef_parent_mapstruct* m_parent_mapstruct;
};

#endif

