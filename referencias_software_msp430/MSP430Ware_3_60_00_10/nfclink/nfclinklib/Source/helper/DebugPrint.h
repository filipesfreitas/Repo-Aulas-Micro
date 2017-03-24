#ifndef READER_PRINTF_H_
#define READER_PRINTF_H_

#include "hardware.h"
#include "Application.h"

class DebugPrint {
  public:
    static void Init();
    static word Read(byte * buffer, word len);
    static void Write(char *fmt, ...);
    static void Hex(byte * buf, word len);
    static bool overflow();
    
  private:
    static void setNtf();
    static bool hexDump;
};


//CHECK-macros: For use with methods that return error-codes defined in API.h
//Use CHECK(function()); instead of function();
//Use RETURN_CHECK(function()); instead of return function(); in call-method of critical classes

////#define DPW DebugPrint::Write
//#define _DEBUG_PRINT_ON
#define DEBUG_RFID

#ifdef _DEBUG_PRINT_ON
	#define CHECK(func) func
	#define RETURN_CHECK(func) return func
//  #define CHECK(func) { word check_ret=func; if((check_ret&RETURN_ERROR) && (check_ret != NO_ANSWER_FROM_TAG)) { DebugPrint::Write("Err %04Xh: line %d file %s\n",check_ret,__LINE__,__FILE__); }}
//  #define RETURN_CHECK(func) { word check_ret=func; if((check_ret&RETURN_ERROR) && (check_ret != NO_ANSWER_FROM_TAG)) { DebugPrint::Write("Err %04Xh: line %d file %s\n",check_ret,__LINE__,__FILE__); } return check_ret; }
#else
  #define CHECK(func) func
  #define RETURN_CHECK(func) return func
#endif

#endif // READER_PRINTF_H_
