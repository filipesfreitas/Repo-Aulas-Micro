/*
 * rs232.h
 *
 *  Created on: 18.09.2012
 *      Author: A
 */

#ifndef HOST_INTERFACE_H_
#define HOST_INTERFACE_H_

#include "hardware.h"


class Host_Interface
{
public:
    static void Init(void);

    static indextype Read(byte *buf, word len);
    static indextype Write(byte *buf, word len);
    static indextype Received();

    static void run();
};

#endif /* RS232_H_ */
