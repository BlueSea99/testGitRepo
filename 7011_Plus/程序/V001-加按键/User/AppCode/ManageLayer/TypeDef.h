/*=============================================================================
 File name: TypeDef.h
 Author:    JiangFan
 Date:      May.04.2016
 Version:   V1.0
 Brief:     This file provides all data type and common marco definition.
==============================================================================*/
#ifndef TYPE_DEF_H_
#define TYPE_DEF_H_

/*=============================================================================
------------------------- 1. DATA TYPE DEFINITION -----------------------------
=============================================================================*/
//--------------------------------------------->General data type
typedef  unsigned int               DBIT;     //Read & Write
typedef  unsigned char              BOOL;     //Read & Write
typedef  unsigned char              UI08;     //Read & Write
typedef  signed   char              SI08;     //Read & Write
typedef  unsigned short             UI16;     //Read & Write
typedef  signed   short             SI16;     //Read & Write
typedef  unsigned long              UI32;     //Read & Write
typedef  signed   long              SI32;     //Read & Write

//--------------------------------------------->Const data type
typedef  const unsigned char        CU08;     //Read only
typedef  const signed   char        CS08;     //Read only
typedef  const unsigned short       CU16;     //Read only
typedef  const signed   short       CS16;     //Read only
typedef  const unsigned long        CU32;     //Read only
typedef  const signed   long        CS32;     //Read only

//--------------------------------------------->Volatile data type
typedef  volatile unsigned char     VU08;     //Read & Write from original address
typedef  volatile signed   char     VS08;     //Read & Write from original address
typedef  volatile unsigned short    VU16;     //Read & Write from original address
typedef  volatile signed   short    VS16;     //Read & Write from original address
typedef  volatile unsigned long     VU32;     //Read & Write from original address
typedef  volatile signed   long     VS32;     //Read & Write from original address
  	
/*============================================================================*/
//-------------------------------------------->Bit data type
typedef struct 
{
	DBIT  b0:1;                                 //8bit access b0
  DBIT  b1:1;                                 //8bit access b1
  DBIT  b2:1;                                 //8bit access b2
  DBIT  b3:1;                                 //8bit access b3
  DBIT  b4:1;                                 //8bit access b4
  DBIT  b5:1;                                 //8bit access b5
  DBIT  b6:1;                                 //8bit access b6
  DBIT  b7:1;                                 //8bit access b7
} Bit8_Def;

typedef struct 
{
  DBIT  b0:1;                                 //16bit access b0
  DBIT  b1:1;                                 //16bit access b1
  DBIT  b2:1;                                 //16bit access b2
  DBIT  b3:1;                                 //16bit access b3
  DBIT  b4:1;                                 //16bit access b4
  DBIT  b5:1;                                 //16bit access b5
  DBIT  b6:1;                                 //16bit access b6
  DBIT  b7:1;                                 //16bit access b7
  DBIT  b8:1;                                 //16bit access b8
  DBIT  b9:1;                                 //16bit access b9
  DBIT  b10:1;                                //16bit access b10
  DBIT  b11:1;                                //16bit access b11
  DBIT  b12:1;                                //16bit access b12
  DBIT  b13:1;                                //16bit access b13
  DBIT  b14:1;                                //16bit access b14
  DBIT  b15:1;                                //16bit access b15
} Bit16_Def;

typedef struct 
{
	DBIT  b0:1;                                 //32bit access b0
  DBIT  b1:1;                                 //32bit access b1
  DBIT  b2:1;                                 //32bit access b2
  DBIT  b3:1;                                 //32bit access b3
  DBIT  b4:1;                                 //32bit access b4
  DBIT  b5:1;                                 //32bit access b5
  DBIT  b6:1;                                 //32bit access b6
  DBIT  b7:1;                                 //32bit access b7
  DBIT  b8:1;                                 //32bit access b8
  DBIT  b9:1;                                 //32bit access b9
  DBIT  b10:1;                                //32bit access b10
  DBIT  b11:1;                                //32bit access b11
  DBIT  b12:1;                                //32bit access b12
  DBIT  b13:1;                                //32bit access b13
  DBIT  b14:1;                                //32bit access b14
  DBIT  b15:1;                                //32bit access b15
  DBIT  b16:1;                                //32bit access b16
  DBIT  b17:1;                                //32bit access b17
  DBIT  b18:1;                                //32bit access b18
  DBIT  b19:1;                                //32bit access b19
  DBIT  b20:1;                                //32bit access b20
  DBIT  b21:1;                                //32bit access b21
  DBIT  b22:1;                                //32bit access b22
  DBIT  b23:1;                                //32bit access b23
  DBIT  b24:1;                                //32bit access b24
  DBIT  b25:1;                                //32bit access b25
  DBIT  b26:1;                                //32bit access b26
  DBIT  b27:1;                                //32bit access b27
  DBIT  b28:1;                                //32bit access b28
  DBIT  b29:1;                                //32bit access b29
  DBIT  b30:1;                                //32bit access b30
  DBIT  b31:1;                                //32bit access b31
} Bit32_Def;

/*==============================================================================
  1Word =2Byte   for 16bit data bus CPU system   ---> 1Lword = 2Word = 4byte
  1Word =4Byte   for 32bit data bus CPU system   ---> 1Word = 2Hword = 4byte            
===============================================================================*/
//-------------------------------------------->Unsigned union data type
typedef union
{
	UI08 Byte;                                  //unsigned 8bit RAM
	Bit8_Def Bit;                               //8bit RAM access bit
} UU08;                                       //8bit unsigned union

typedef union 
{
	UI16 Word;                                  //unsigned 16bit RAM
	struct                                      //Little endian mode
	  {
	    UI08 Lb;                                //16bit access L byte	
	    UI08 Hb;                                //16bit access H byte	
	  } Byte;                                    
	Bit16_Def Bit;                              //16bit RAM access bit
} UU16;                                       //16bit unsigned union

typedef union
{
	UI32 Lword;                                 //unsigned 32bit RAM
	struct                                      //Little endian mode
	  {
	  	UI16 Lw;                                //32bit access L word
			UI16 Hw;                                //32bit access H word
	  } Word;   
	struct                                      //Little endian mode
	  {
	    UI08 LLb;                               //32bit access LL byte	
	    UI08 LHb;                               //32bit access LH byte	
	    UI08 HLb;                               //32bit access HL byte	
	    UI08 HHb;                               //32bit access HH byte	
	  } Byte;        
	Bit32_Def Bit;                              //32bit RAM access bit
} UU32;                                       //32bit unsigned union

//-------------------------------------------->Signed union data type
typedef union
{
	SI08 Byte;                                  //signed 8bit RAM
	Bit8_Def Bit;                               //8bit RAM access bit
} US08;                                       //8bit signed union

typedef union 
{
	SI16 Word;                                  //signed 16bit RAM
	struct                                      //Little endian mode
	  {
	    UI08 Lb;                                //16bit access L byte	
	    SI08 Hb;                                //16bit access H byte	
	  } Byte;                                    
	Bit16_Def Bit;                              //16bit RAM access bit
} US16;                                       //16bit signed union

typedef union
{
	SI32 Lword;                                 //signed 32bit RAM
	struct                                      //Little endian mode
	  {
	  	UI16 Lw;                                //32bit access L word
			SI16 Hw;                                //32bit access H word
	  } Word;    
	struct                                      //Little endian mode
	  {
	    UI08 LLb;                               //32bit access LL byte	
	    UI08 LHb;                               //32bit access LH byte	
	    UI08 HLb;                               //32bit access HL byte	
	    SI08 HHb;                               //32bit access HH byte	
	  } Byte;        
	Bit32_Def Bit;                              //32bit RAM access bit
} US32;                                       //32bit signed union

/*==============================================================================*/
//-------------------------------------------->Unsigned voalatile union data type
typedef volatile  UU08    VUU08;              //8bit volatile unsigned union
typedef volatile  UU16    VUU16;              //16bit volatile unsigned union
typedef volatile  UU32    VUU32;              //32bit volatile unsigned union

//-------------------------------------------->Signed voalatile union data type
typedef volatile  US08    VUS08;              //8bit volatile signed union
typedef volatile  US16    VUS16;              //16bit volatile signed union
typedef volatile  US32    VUS32;              //32bit volatile signed union

/*===============================================================================
-------------------------- 2.PUBLIC MACRO DEFINITION ----------------------------
================================================================================*/
#define Bit0              0x0001              //Bit0
#define Bit1              0x0002              //Bit1
#define Bit2              0x0004
#define Bit3              0x0008
#define Bit4              0x0010
#define Bit5              0x0020
#define Bit6              0x0040
#define Bit7              0x0080
#define Bit8              0x0100
#define Bit9              0x0200
#define Bit10             0x0400
#define Bit11             0x0800
#define Bit12             0x1000
#define Bit13             0x2000
#define Bit14             0x4000
#define Bit15             0x8000

#define CBit0             0xFFFE
#define CBit1             0xFFFD
#define CBit2             0xFFFB
#define CBit3             0xFFF7
#define CBit4             0xFFEF
#define CBit5             0xFFDF
#define CBit6             0xFFBF
#define CBit7             0xFF7F
#define CBit8             0xFEFF
#define CBit9             0xFDFF
#define CBit10            0xFBFF
#define CBit11            0xF7FF
#define CBit12            0xEFFF
#define CBit13            0xDFFF
#define CBit14            0xBFFF
#define CBit15            0x7FFF

#define UI08_MAX          255
#define SI08_MAX          127
#define SI08_MIN         -128
 
#define UI16_MAX          65535
#define SI16_MAX          32767
#define SI16_MIN         -32768

//-------------------------------------------->Common use bit operation macro.
#define IQ(n)             (1<<n)              //Left shift N bit
#define CIQ(n)            (~(1<<n))           //anti code
#define AIQ(a,n)          (a*IQ(n))           //a*IQ
#define XorBit(a,b)       ((a)^(b))           //XOR
#define SetBit(x,n)       ((x)|=IQ(n))        //Set bit
#define RstBit(x,n)       ((x)&=~IQ(n))       //Reset bit
#define ClrBit(x,n)       ((x)&=~IQ(n))       //Clear bit
#define ChkBit(x,n)       ((x)&IQ(n))         //Check bit

//-------------------------------------------->Common use calculate macro.
#define Abs(a)            (a<0?(-a):a)        //absolute value
#define Max2(a,b)         (a>b?a:b)           //get bigger value in two value
#define Min2(a,b)         (a<b?a:b)           //get smaller value in two value
#define Max3(a,b,c)       (((a>b?a:b)>c)?(a>b?a:b):c)           
#define Min3(a,b,c)       (((a>b?a:b)>c)?(a>b?a:b):c) 

#define IS_AF(c)          ((c>='A')&&(c<='F'))
#define IS_af(c)          ((c>='a')&&(c<='f'))
#define IS_09(c)          ((c>='0')&&(c<='9'))
#define IS_VALID_HEX(c)   IS_AF(c) || IS_af(c) || IS_09(c) 
#define IS_VALID_DEC(c)   IS_09(c)
#define CHAR_TO_DEC(c)    (c-'0')

//-------------------------------------------->Common array and structure macro.
#define ARRAY_SIZE(x) 	  (UI08)(sizeof(x)/sizeof((x)[0]))
#define STRUCT08_SIZE(x)  (UI08)(sizeof(x))  
#define STRUCT16_SIZE(x)  (UI08)(sizeof(x)>>1)
#define STRUCT32_SIZE(x)  (UI08)(sizeof(x)>>2)

/* Common use bool definition ***************************************************/
#if !defined(FORWARD)&& !defined(BACKWARD)
  #define FORWARD         (0)
  #define BACKWARD        (1)
#endif

#if !defined(POSITIVE)&& !defined(NAGETIVE)
  #define POSITIVE        (0)
  #define NAGETIVE        (1)
#endif

#if !defined(OPEN_LOOP)&& !defined(CLOSE_LOOP)
  #define OPEN_LOOP				(0)
  #define CLOSE_LOOP			(1)
#endif

#if !defined(TRUE)&& !defined(FALSE)
  #define TRUE            (1)
  #define FALSE           (0)
#endif

#if !defined(YES)&& !defined(NO)&& !defined(NC)
  #define YES             (1)
  #define NO              (0)
  #define NC              (1)
#endif

#if !defined(OK)&& !defined(NG)
  #define OK              (1)
  #define NG              (0)
#endif

#if !defined(ON)&& !defined(OFF)
  #define ON              (1)
  #define OFF             (0)
#endif

#if !defined(SET)&& !defined(CLR)
  #define SET             (1)
  #define CLR             (0)
#endif

#if !defined(RST)&& !defined(RESET)
  #define RST             (0)
  #define RESET           (0)
#endif

#if !defined(HIGH)&& !defined(LOW)
#define HIGH             (1)
#define LOW              (0)
#endif

#if !defined(ODD)&& !defined(EVEN)
#define ODD              (1)
#define EVEN             (0)
#endif

#if !defined(SEND)&& !defined(RECV)
#define SEND             (1)
#define RECV             (0)
#endif

#if !defined(OPEN)&& !defined(CLOSE)
#define OPEN             (1)
#define CLOSE            (0)
#endif

#if !defined(SUCCESS)&& !defined(ERROR)
#define SUCCESS          (1)
#define ERROR            (0)
#endif

#if !defined(NULL)
#define HAVE             (1)
#define NULL             (0)
#endif

#if !defined(ZERO)
#define ZERO             (0)
#endif

#endif

/*========================== END OF FILE =================================*/
