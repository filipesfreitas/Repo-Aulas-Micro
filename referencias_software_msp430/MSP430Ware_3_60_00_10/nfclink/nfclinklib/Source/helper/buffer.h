#ifndef BUFFER_H
#define BUFFER_H
#include "hardware.h"

template <word Arraysize> class Array
{
public:
  word len;
  byte data[Arraysize];
  void Init()
  {
    word i;
    loop(i,Arraysize) data[i]=0x00;
    len=0;
  }
};

template <typename IndexType,word Buffersize> class Buffer
{
  private:
    byte buf[Buffersize]; /* data storage */
    volatile  IndexType readptr, writeptr; /* read and write pointers */
    volatile IndexType _free;    /* number of unused bytes in data storage */
    volatile  IndexType lastfree, lastreadptr;
    bool _overflow;
  
  public:
    /* number of used bytes in storage */
    inline IndexType used() { 
      return (IndexType)Buffersize-_free; 
    }
    
    /* number of unused bytes in storage */
    inline IndexType free() {
      return _free; 
    }
    
    /* true if empty */
    inline bool empty() {
      return (_free==(IndexType)Buffersize);
    }  
    
    /* true if full */
    inline bool full() {
      return (_free==0);
    }  
    
    inline bool overflow() {
      return _overflow;
    }
    
    Buffer() { 
      flush(); 
    }
    
    /* flush and initialize the buffer */
    void flush()  
    {
      _overflow=false;
      readptr=0;
      writeptr=0;
      _free=(IndexType)Buffersize;
    }
  
    /* write bytes into buffer
    * @param dat pointer to data
    * @param len number of bytes
    * @return 0 if written, otherwise 0xff
    */
    IndexType Write(void *dat, IndexType len)
    {
      IndexType i;
      loop(i,len)
      {
        if(full())
        {
          _overflow=true;
          return i;
        }
        buf[writeptr++]=((byte *)dat)[i];
        if(writeptr >= Buffersize) writeptr=0;
        _free--;
      }
      return len;
    }

    void updateBufferValues(IndexType dataSize)
    {
    	if(_free >= dataSize)
    	{
        	_free = _free - dataSize;
        	writeptr = writeptr + dataSize;
    	}
    }

    byte * getBufferPtr(void)
    {
    	return (buf + writeptr);
    }

    word getBufferSize(void)
    {
    	return Buffersize;
    }
  
    /* read bytes from buffer
    * @param dat pointer to data
    * @param buflen number of bytes
    * @return number of bytes read
    */
    IndexType Read(void *dat,IndexType buflen)
    {
      IndexType i;
      lastfree=_free;  //used for Undo()
      lastreadptr=readptr;
      loop(i,buflen)
      {
        if(empty())
		{
        	 flush();
        	return i;
		}
        ((char *)dat)[i]=buf[readptr++];
        if(readptr >= Buffersize) readptr=0;
        _free++;
      }

      // If the buffer is (empty)
      if(empty())
    	  flush();

      return buflen;
    }
  
    /* sets back to state of last reading */
    void Undo() 
    {
        _free=lastfree;
        readptr=lastreadptr;
    }	
};

#endif

