#ifndef _TOOL_H
#define _TOOL_H
/*******************************************************************************
 * @file     tool.h
 * @brief    contains helpfull functions
 * @author   Alexander Baar
 * @version  V0.0.1
 * @date     02/08/2012
 * @details  contains helpfull functions like memcpy and memcmp.
 *
 * THE SOURCE CODE AND ITS RELATED DOCUMENTATION IS PROVIDED "AS IS". KRONEGGER
 * GMBH MAKES NO OTHER WARRANTY OF ANY KIND, WHETHER EXPRESS, IMPLIED OR,
 * STATUTORY AND DISCLAIMS ANY AND ALL IMPLIED WARRANTIES OF MERCHANTABILITY,
 * SATISFACTORY QUALITY, NON INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 * THE SOURCE CODE AND DOCUMENTATION MAY INCLUDE ERRORS. KRONEGGER GMBH
 * RESERVES THE RIGHT TO INCORPORATE MODIFICATIONS TO THE SOURCE CODE IN LATER
 * REVISIONS OF IT, AND TO MAKE IMPROVEMENTS OR CHANGES IN THE DOCUMENTATION OR 
 * THE PRODUCTS OR TECHNOLOGIES DESCRIBED THEREIN AT ANY TIME.
 *
 * KRONEGGER GMBH SHALL NOT BE LIABLE FOR ANY DIRECT, INDIRECT OR CONSEQUENTIAL 
 * DAMAGE OR LIABILITY ARISING FROM YOUR USE OF THE SOURCE CODE OR ANY 
 * DOCUMENTATION, INCLUDING BUT NOT LIMITED TO, LOST REVENUES, DATA OR PROFITS, 
 * DAMAGES OF ANY SPECIAL, INCIDENTAL OR CONSEQUENTIAL NATURE, PUNITIVE DAMAGES,
 * LOSS OF PROPERTY OR LOSS OF PROFITS ARISING OUT OF OR IN CONNECTION WITH THIS
 * AGREEMENT, OR BEING UNUSABLE, EVEN IF ADVISED OF THE POSSIBILITY OR 
 * PROBABILITY OF SUCH DAMAGES AND WHETHER A CLAIM FOR SUCH DAMAGE IS BASED UPON
 * WARRANTY, CONTRACT, TORT, NEGLIGENCE OR OTHERWISE.
 *
 * (C)Copyright Kronegger GmbH 2012 All rights reserved
 ******************************************************************************/
#include "hardware.h"

inline void memcpy(byte *a, byte *b, word len) {
  while(len) {
    *a++=*b++; 
    len--; 
  }
}

inline bool memcmp(byte *a, byte *b, word len) {
  while(len) {
    if(*a++!=*b++){ return false; } 
    len--; 
  } 
  return true; 
}

#endif //_TOOL_H
