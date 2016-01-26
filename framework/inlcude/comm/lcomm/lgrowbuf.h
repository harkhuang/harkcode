#ifndef __CLGROWBUF_INCLUDE_H__
#define __CLGROWBUF_INCLUDE_H__

#include <stdlib.h>
#include <string.h>

#define CLGROWBUF_DEFAULT_CHUNK		1024*10
#define CLGROWBUF_MIN_CHUNK			256

class CLGrowBuf
{
	public:
		CLGrowBuf(int nchunk = CLGROWBUF_MIN_CHUNK)
		{
			if (nchunk < CLGROWBUF_MIN_CHUNK)
			{
				nchunk = CLGROWBUF_DEFAULT_CHUNK;
			}
			m_nchunk = nchunk;
		
			// since constructors cannot report failure, we defer
			// the malloc until the first use.
			m_pbuf = NULL;
			m_nsize = 0;
			m_nspace = 0;
		}
		
		~CLGrowBuf()
		{
			if (m_pbuf)
			{
				free(m_pbuf);
				m_pbuf = NULL;
			}
		}
 		bool WriteInt8(unsigned char cValue)
  	{
	  	return ins(m_nsize,(char *)&cValue,sizeof(cValue));
	  }
		
 		bool WriteInt16(short int nValue)
  	{
	  	return ins(m_nsize,(char *)&nValue,sizeof(nValue));
	  }
		
 		bool WriteInt32(int nValue)
  	{
	  	return ins(m_nsize,(char *)&nValue,sizeof(nValue));
	  }		
			
	  bool append(char * pValue, int nlength)
  	{
	  	return ins(m_nsize,pValue,nlength);
	  }
	
	  bool ins(int nposition, char * pValue, int nlength)
		{
			// insert the given buffer into the growbuf
		
			if (!nlength)
			{
				return true;
			}
			
			if (m_nspace - m_nsize < nlength)
			{
				if (!_growBuf(nlength))
				{
					return false;
				}
			}
		
			if (m_nsize > nposition)
			{
				memmove( m_pbuf + nposition + nlength, m_pbuf + nposition,(m_nsize - nposition) * sizeof(char));
			} 
			m_nsize += nlength;
			memmove(m_pbuf + nposition,pValue,nlength*sizeof(char));
		
			return true;
		}
		
		bool del(int nposition, int namount)
		{  //Lanq 20091020 add,  nposition > m_nsize
			if (!namount || nposition > m_nsize)
			{
				return true;
			}
		
			if (!m_pbuf)
			{
				return false;
			}
			
			memmove(m_pbuf + nposition, m_pbuf + nposition + namount,(m_nsize-nposition-namount)*sizeof(char));
			m_nsize -= namount;
		
			int newSpace = ((m_nsize+m_nchunk-1)/m_nchunk)*m_nchunk; //Calculate the new space needed
			if (newSpace != m_nspace)
			{
				m_pbuf = (char *)realloc(m_pbuf, newSpace*sizeof(char));  //Re-allocate to the smaller size
				m_nspace = newSpace; //update m_nspace to the new figure
			}
			
			return true;
		}
	
		int getLength(void) const
		{
			// return the number of items in the buffer		
			return m_nsize;
		}
		
		int getOffset(void) const
		{
			// return the number of items in the buffer		
			return m_nsize;
		}
		
		char * getPointer(int nposition = 0) const
		{
			// return a read-only pointer to the buffer
			
			if (!m_pbuf || !m_nsize)
				return NULL;
			return m_pbuf + nposition;
		}
		
    bool RewriteInt32(int nposition, int nValue)
    {
    	return 	overwrite(nposition, (char *)&nValue, sizeof(nValue));
    }

    bool RewriteInt16(int nposition, short int nValue)
    {
    	return 	overwrite(nposition, (char *)&nValue, sizeof(nValue));
    }

    bool overwrite(int nposition, char * pValue, int nlength)
		{
			// overwrite the current cells at the given nposition for the given length.
			if (!nlength)
			{
				return true;
			}
			
			if (m_nspace < (nposition + nlength))
			{
				if (!_growBuf(nposition + nlength - m_nspace))
				{
					return false;
				}
			}
		
			memmove(m_pbuf + nposition, pValue, nlength*sizeof(char));
			return true;
		}
	
		void truncate(int nposition)
		{
			if (nposition < m_nsize)
			{
				m_nsize = nposition;
			}
		
			int newSpace = ((m_nsize+m_nchunk-1)/m_nchunk)*m_nchunk; //Calculate the new space needed
			if (newSpace != m_nspace)
			{
				m_pbuf = (char *)realloc(m_pbuf, newSpace*sizeof(*m_pbuf));  //Re-allocate to the smaller size
				m_nspace = newSpace; //update m_nspace to the new figure
			}
		}
		
	private:
		int m_nchunk;
		int m_nsize;
		int m_nspace; 
		char *m_pbuf;
		bool _growBuf(int nspaceNeeded)
	  {
			// expand the buffer if necessary to accomidate the requested space.
			// round up to the next multiple of the chunk size.
			
			int newSize = ((m_nsize + nspaceNeeded + m_nchunk - 1)/m_nchunk)*m_nchunk;
			char * pNew = (char *)calloc(newSize,sizeof(char));
			if (!pNew)
			{
				return false;
			}
			
			if (m_pbuf)
			{
				memmove(pNew,m_pbuf,m_nsize*sizeof(char));
				free(m_pbuf);
			}
		
			m_pbuf = pNew;
			m_nspace = newSize;
		
			return true;
		}
};
#endif

