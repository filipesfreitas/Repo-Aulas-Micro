/*
 * hardware.h
 *
 *  Created on: 18.09.2012
 *      Author: A
 */

#ifndef HARDWARE_H_
#define HARDWARE_H_

//to be compatible with IAR settings
#define __no_init
//-----------------------------------------------------------------------------------------------------------
// Hardware.h
// includes hardware independent part only
//-----------------------------------------------------------------------------------------------------------
#define using_interrupts  //used for SerialT
#ifdef PCEmulation
#define byte unsigned __int8   // 8 bit
#define word unsigned __int16  // 16 bit
#define dword unsigned __int32  // 32 bit
#else
#define byte unsigned char   // 8 bit
#define word unsigned short  // 16 bit
#define dword unsigned long  // 32 bit
#endif

#define indextype word        //used for buffer indices @ SerialT,..
//template<int v> struct Int2Type {
//	enum {
//		value = v
//	};
//};

#define loop(i,cnt) for(i=0;i<cnt;i++)
#define ClearBit(var,bit) {var &=~(1<<bit);}
#define SetBit(var,bit) {var |=(1<<bit);}
#define ToggleBit(var,bit) {var ^=(1<<bit);}
#define SetMasked(var,dat,mask) {var=((var)&~(mask))|((dat)&(mask));}

#define HIBYTE(x)  ((byte)(x>>8))
#define LOBYTE(x)  ((byte)(x&(0xFF)))
#define BytesToWord(HI,LO) ((((word)HI)<<8)+((word)LO))

#ifdef PCEmulation
#undef NULL
#endif
//#define NULL ((void *)0)
#define NULL ((byte *)0)
#ifdef PCEmulation
#define CLRWDT
#define nop
#else
#define CLRWDT asm("clrwdt")
#define nop asm("nop")
#endif

//causes compile time error if cond==false; generates no code
#define STATIC_CHECK(cond) {volatile char b[(cond)?(1):(0)];}
//various functions
//template<class T> T min(T a, T b) {
//	return (a < b) ? (a) : (b);
//}
//template<class T> T max(T a, T b) {
//	return (a > b) ? (a) : (b);
//}
//#ifndef PCEmulation
//extern "C" { void printf(char *fmt,...); }
//#endif

// moved into tool.h! inline void memcpy(byte *a, byte *b, word len) {while(len) {*a++=*b++; len--; }}
// moved into tool.h! inline bool memcmp(byte *a, byte *b, word len) {while(len) {if(*a++!=*b++){return false;} len--; } return true; }

//--------------------------------------------------------------------------------------------------------
// Coprocesses
//--------------------------------------------------------------------------------------------------------
#define crwaiting 1  // Coroutine ist in Wartezustand
#define crdone    0  // Coroutine ist fertig (beendet)
#ifdef PCEmulation
#define crBegin usewait(); static word state=0;  switch(state) { case 0:
#else
#define crBegin static word state=0;  switch(state) { case 0:
#endif
#define crBeginC(cond) static word state=0;  if(!(cond)) {state=0; return crdone;} switch(state) { case 0:   //abort if cond==false
#ifdef PCEmulation
#define crYield { state=__COUNTER__+1; return crwaiting; case __COUNTER__:; }
#else
#define crYield {state=__LINE__; return crwaiting; case __LINE__:; }
#endif
//#define crFinish state=0; }  return crdone;
#define crFinish } state=0;   return crdone;
#define __crFinish } state=0; return crdone;   //to be used after a while(1) to supress "statement unreachable" warning
#define crReturn {state=0; return crdone;} //Ausstieg aus einer Coroutine
//Aufruf einer Coroutine aus einer Coroutine heraus; wartet bis Coroutine fertig ist
// damit werden blockierende Funktionshierarchien möglich.
#define crCall(f) { while((f) != crdone) crYield; }

#ifndef PCEmulation  //zu prüfen of Differenzierung notwendig ist
#define crWaitms(d) {static Timer t; t.Start(d); \
		while(!t.iselapsed()) crYield; }
#else
#define usewait() static Timer waitmstimer;
#define crWaitms(d) {waitmstimer.Start(d); while(!waitmstimer.iselapsed())crYield; }
#endif

#define crReturn_Msg(ret) {state=0; return ret;} //Ausstieg aus einer Coroutine mit return value
void waitms(word ms); //blocking wait (avoid to use it !)
void waitus(word usec);

union dwordtobyte {
	dword d;byte b[4];
};

union wordtobyte {
	dword d;byte b[2];
};

#define HW_VERSION_STR    "TRF7970A.MSP430F5529.OEM"
#define HW_VERSION_LENGTH   25

/**
 *Hardware Abstraction Layer
 *
 *@param opcode contains the Command code
 *@param sendbuf contains the reveived data from host.
 *@param sendlen contains the length of revieved data from host
 *@param recbuf contains the sending data to the host.
 *@param reclen contains the length of sending data to the host
 */
class HW {
//private:
	static word hwVersion(word sendlen, byte *recbuf, word &reclen);
//	static word hwTicks32(word sendlen, byte *recbuf, word &reclen);
//	static word hwControl(byte *sendbuf, word sendlen, byte *recbuf,
//			word &reclen);
//	static word hwcSPI(byte *sendbuf, word sendlen, byte *recbuf, word &reclen);
//	static word hwcI2C(byte *sendbuf, word sendlen, byte *recbuf, word &reclen);
//	static word hwcSWP(byte *sendbuf, word sendlen, byte *recbuf, word &reclen);
//	static word hwcUART(byte *sendbuf, word sendlen, byte *recbuf,
//			word &reclen);
	static void reset();
//
public:
	static void Init();
//	// system threads
	static void run(); //must be called in mainloop
	static void Idle(); //must be called in idle loop
//	// Generic Service Entry
//	//static word Call(byte opcode,byte *sendbuf,word sendlen, byte *recbuf, word reclen);
	static word Call(word opcode, byte *sendbuf, word sendlen, byte *recbuf, word &reclen);
//	//static byte Call(byte opcode,byte *sendbuf,byte sendlen, byte *recbuf, byte reclen);
	static word Call(word opcode);
	static word Call(word opcode, byte s1);
	static word Call(word opcode, byte s1, word s2);
//	static void IoSet(byte mask, byte value);
};

//--------------------------------------------------------------------------------------------------------
//Timer
//--------------------------------------------------------------------------------------------------------
class Timer {
	long t; //32 bit time since start
	bool running; //false if elapsed
public:
	Timer();
	void Start(dword msec);
	void StartFC(dword msec);
	dword GetTime();
	void ReStart(dword msec);
	bool iselapsed();
	void Stop();
	void tic();
	double toc();
	bool isactive();
	dword GetTicks32();
};

#endif /* HARDWARE_H_ */
