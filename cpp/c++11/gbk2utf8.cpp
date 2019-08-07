
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <iconv.h> //for gbk/big5/utf8

bool  IsTextUTF8(const char* str,int length)
{
  int nBytes=0;//UFT8可用1-6个字节编码,ASCII用一个字节
  unsigned char chr;
  bool bAllAscii=true; //如果全部都是ASCII, 说明不是UTF-8
  for(int i=0; i<length; ++i)
  {
    chr= *(str+i);
    if( (chr&0x80) != 0 ) // 判断是否ASCII编码,如果不是,说明有可能是UTF-8,ASCII用7位编码,但用一个字节存,最高位标记为0,o0xxxxxxx
      bAllAscii= false;
    if(nBytes==0) //如果不是ASCII码,应该是多字节符,计算字节数
    {
      if(chr>=0x80)
      {
        if(chr>=0xFC&&chr<=0xFD)
          nBytes=6;
        else if(chr>=0xF8)
          nBytes=5;
        else if(chr>=0xF0)
          nBytes=4;
        else if(chr>=0xE0)
          nBytes=3;
        else if(chr>=0xC0)
          nBytes=2;
        else
          return false;
        nBytes--;
      }
    }
    else //多字节符的非首字节,应为 10xxxxxx
    {
      if( (chr&0xC0) != 0x80 )
        return false;
      nBytes--;
    }
  }
  if( nBytes > 0 ) //违返规则
    return false;
  if( bAllAscii ) //如果全部都是ASCII, 说明不是UTF-8
    return false;
  return true;
}


std::string  CodeConvert(char *source_charset, char *to_charset, const std::string& sourceStr) //sourceStr是源编码字符串
{
  iconv_t cd = iconv_open(to_charset, source_charset);//获取转换句柄，void*类型
  if (cd == 0)
    return "iconv  open error";
  size_t inlen = sourceStr.size();
  size_t outlen = 255;
  char* inbuf = (char*)sourceStr.c_str();
  char outbuf[255];//这里实在不知道需要多少个字节，这是个问题
  //char *outbuf = new char[outlen]; 另外outbuf不能在堆上分配内存，否则转换失败，猜测跟iconv函数有关
  memset(outbuf, 0, outlen);
  char *poutbuf = outbuf; //多加这个转换是为了避免iconv这个函数出现char(*)[255]类型的实参与char**类型的形参不兼容
  if (iconv(cd, &inbuf, &inlen, &poutbuf,&outlen) == -1)
    return "iconv error";
  std::string strTemp(outbuf);//此时的strTemp为转换编码之后的字符串
  iconv_close(cd);
  return strTemp;
}
//gbk转UTF-8
std::string GbkToUtf8(const std::string& strGbk)// 传入的strGbk是GBK编码
{
  if(IsTextUTF8(strGbk.c_str(),strlen(strGbk.c_str()))==false)
    return CodeConvert("gb2312", "utf-8",strGbk);
  else
    return strGbk;
}




int GBK2UTF8(const std::string &strGBK, std::string &strUTF8)
{
#if defined(_MSC_VER) && (_MSC_VER >= 1400)
	int nRet = -1;
	if (strGBK.empty())
		return nRet;

	int nLenOfWide = MultiByteToWideChar(CP_ACP, 0, strGBK.c_str(), strGBK.size(), nullptr, 0);
	if (nLenOfWide <= 0)
		return nRet;

	wchar_t *pWideData = new wchar_t[nLenOfWide + 1];
	memset((void *)pWideData, 0, nLenOfWide + 1);
	nLenOfWide = MultiByteToWideChar(CP_ACP, 0, strGBK.c_str(), strGBK.size(), pWideData, nLenOfWide);
	if (nLenOfWide <= 0)
	{
		delete[] pWideData;
		pWideData = nullptr;
		return nRet;
	}

	//---------------------------------------------------------------------------------
	int nLenOfMultiByte = WideCharToMultiByte(CP_UTF8, 0, pWideData, nLenOfWide, nullptr, 0, nullptr, nullptr);
	if (nLenOfMultiByte <= 0)
	{
		delete[] pWideData;
		pWideData = nullptr;
		return nRet;
	}

	char *pUTF8Data = new char[nLenOfMultiByte + 1];
	memset((void *)pUTF8Data, 0, nLenOfMultiByte + 1);
	nLenOfMultiByte = WideCharToMultiByte(CP_UTF8, 0, pWideData, nLenOfWide, pUTF8Data, nLenOfMultiByte, nullptr, nullptr);
	if (nLenOfMultiByte <= 0)
	{
		delete[] pWideData;
		pWideData = nullptr;

		delete[] pUTF8Data;
		pUTF8Data = nullptr;
		return nRet;
	}

	strUTF8 = std::string(pUTF8Data, nLenOfMultiByte);

	delete[] pWideData;
	pWideData = nullptr;

	delete[] pUTF8Data;
	pUTF8Data = nullptr;

    nRet = 0;
    return nRet;
#else

  //strUTF8 = any2utf8(strGBK,std::string("gb2312"),std::string("utf-8"));
  strUTF8 = GbkToUtf8(strGBK);

  return 0;
#endif

}