#ifndef __L_COMM_LBUFDATA_H__
#define __L_COMM_LBUFDATA_H__

#include <stdlib.h>
#include <string.h>

class CLBufData
{
	public:
		CLBufData()
		{
			m_pbuf = 0;
			m_pcurrent = 0;
			m_nbuflen = 0;
		}
		CLBufData(char *lpbuf,int nbuflen)
		{
			SetBuf(lpbuf, nbuflen);
		}
		
		virtual ~CLBufData()
		{
		}
		
		int SetBuf(char *lpbuf,int nbuflen)
		{
			m_pbuf = m_pcurrent = lpbuf;
			m_nbuflen = nbuflen;
      return 0;
		}

		unsigned char ReadInt8()
		{
			unsigned char cdata = 0;
			if ((m_nbuflen - (m_pcurrent - m_pbuf)) < (int)sizeof(cdata))
			{
				return 0;
			}
			cdata = (unsigned char)(*((unsigned char *)m_pcurrent));
      m_pcurrent += sizeof(cdata);
			return cdata;
		}
		
		short int ReadInt16()
		{
    	short int ndata = 0;
			if ((m_nbuflen - (m_pcurrent - m_pbuf)) < (int)sizeof(ndata))
			{
				return 0;
			}
			ndata = (short int)(*((short int  *)m_pcurrent));
      m_pcurrent += sizeof(ndata);
			return ndata;
		}

		int ReadInt32()
		{
			int ndata = 0;
			if ((m_nbuflen - (m_pcurrent - m_pbuf)) < (int)sizeof(ndata))
			{
				return 0;
			}
			ndata = (int)(*((int  *)m_pcurrent));
      m_pcurrent += sizeof(ndata);
			return ndata;
		}
		
		int ReadBuf(char *lpbuf,int nbuflen)
		{
			if (nbuflen == 0)
			{
				return 0;
			}
			if ((m_nbuflen - (m_pcurrent - m_pbuf)) < nbuflen)
			{
				return 0;
			}
			memcpy(lpbuf,m_pcurrent,nbuflen);
			m_pcurrent += nbuflen;
			return nbuflen;
		}
		int getOffset()
		{
			int noffset = (int)(m_pcurrent - m_pbuf);
			if (noffset <0)
			{
				noffset = 0;
			}
			return noffset;
		}
		
		char *GetCurBuf()
		{
			return m_pcurrent;
		}
		
		
	private:
		char *m_pbuf ;
		char *m_pcurrent;
		int m_nbuflen;
		
};

#endif //__L_COMM_LBUFDATA_H__
