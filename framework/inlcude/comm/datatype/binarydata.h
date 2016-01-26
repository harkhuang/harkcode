#ifndef __L_BINARYDATA_INCLUDE__
#define __L_BINARYDATA_INCLUDE__

class CBinaryData
{
	public:
		CBinaryData()
		{
			m_pbuf = NULL;
			m_nbuflen = -1;
		}
		~CBinaryData()
		{
			Clear();
		}

		int SetBufData(void *pdata,int nbuflen)
		{
			Clear();
			if (m_pbuf == NULL)
			{
				m_pbuf = malloc(nbuflen +1);
				m_nbuflen = nbuflen;
				memcpy(m_pbuf,pdata,nbuflen);
				return 0;
			}
			return -1;
		}

		int GetBufData(void **ppdata,int &nbuflen)
		{
			(*ppdata) = 0;
			nbuflen = 0;

			if (m_nbuflen <0 || m_pbuf == NULL)
			{
				return -1;
			}

			nbuflen = m_nbuflen;
			(*ppdata) = m_pbuf;

			return 0;
		}
	
	private:
		int Clear()
		{
			if (m_nbuflen >0 && m_pbuf)
			{
				free(m_pbuf);
				m_pbuf = NULL;
				m_nbuflen = -1;
			}
			
			return 0;
		}
		void *m_pbuf;
		int m_nbuflen;
};

#endif  // __L_BINARYDATA_INCLUDE__
