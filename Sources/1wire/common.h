////////////////////////////////////////////////////////////////////////////////
/// \file	common.h
///	\breif Holds the common code
///
///	Author: Ronald Alexander Nobrega De Sousa (Opticalworm)
///	Website: www.HashDefineElectronics.com
///
///	Licences:
///
///		Copyright (c) 2014 Ronald Alexander Nobrega De Sousa
///
///		Permission is hereby granted, free of charge, to any person obtaining a copy
///		of this software and associated documentation files (the "Software"), to deal
///		in the Software without restriction, including without limitation the rights
///		to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
///		copies of the Software, and to permit persons to whom the Software is
///		furnished to do so, subject to the following conditions:
///
///		The above copyright notice and this permission notice shall be included in
///		all copies or substantial portions of the Software.
///
///		THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
///		IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
///		FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
///		AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
///		LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
///		OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
///		THE SOFTWARE.
////////////////////////////////////////////////////////////////////////////////
#ifndef __COMMON_H__
#define __COMMON_H__
#include <stdint.h>

/////////////////////////////////////////////////////////////////////////
///	\brief	Defines the true state
/////////////////////////////////////////////////////////////////////////
#define TRUE 	1
/////////////////////////////////////////////////////////////////////////
///	\brief	Defines the false state
/////////////////////////////////////////////////////////////////////////
#define FALSE 	0


/////////////////////////////////////////////////////////////////////////
///	\brief	union type converter.
///	handy for when you want to extract the byte from a data type.
/////////////////////////////////////////////////////////////////////////
typedef union{
    float 		_float[2];
    int64_t 	_int64;
    int32_t 	_int32[2];
    int16_t 	_int16[4];
    int8_t 		_int8[8];
    uint64_t 	_uint64;
    uint32_t 	_uint32[2];
    uint16_t 	_uint16[4];
    uint8_t 	_uint8[8];
} TypeCon;

#endif
