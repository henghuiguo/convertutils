///////////////////////////////////////////////////////////////////////////////////////
// MIT License
// 
// Copyright (c) 2022 Henghui Guo
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
///////////////////////////////////////////////////////////////////////////////////////
#pragma once

#include <string>
#include <vector>

/** @brief cx namespace. */
namespace cx {

	typedef std::string String;
	typedef std::wstring WString;

	typedef char Int8;
	typedef unsigned char UInt8;
	typedef unsigned char Byte;

	typedef short Int16;
	typedef unsigned short UInt16;

	typedef int Int32;
	typedef unsigned int UInt32;

	typedef long long Int64;
	typedef unsigned long long UInt64;

	typedef float Float;
	typedef double Double;

	typedef std::vector<uint8_t> ByteVector;

	/**
	 * @brief Converts the specified string to Int8 value.
	 * @param str The string.
	 * @return Int8 value.
	 */
	Int8 to_int8(const String& str);

	/**
	 * @brief Converts the specified string to UInt8 value.
	 * @param str The string.
	 * @return UInt8 value.
	 */
	UInt8 to_uint8(const String& str);

	/**
	 * @brief Converts the specified string to Int16 value.
	 * @param str The string.
	 * @return Int16 value.
	 */
	Int16 to_int16(const String& str);

	/**
	 * @brief Converts the specified string to UInt16 value.
	 * @param str The string.
	 * @return UInt16 value.
	 */
	UInt16 to_uint16(const String& str);

	/**
	 * @brief Converts the specified string to Int32 value.
	 * @param str The string.
	 * @return Int32 value.
	 */
	Int32 to_int32(const String& str);

	/**
	 * @brief Converts the specified string to UInt32 value.
	 * @param str The string.
	 * @return UInt32 value.
	 */
	UInt32 to_uint32(const String& str);

	/**
	 * @brief Converts the specified string to Int64 value.
	 * @param str The string.
	 * @return Int64 value.
	 */
	Int64 to_int64(const String& str);

	/**
	 * @brief Converts the specified string to UInt64 value.
	 * @param str The string.
	 * @return UInt64 value.
	 */
	UInt64 to_uint64(const String& str);

	/**
	 * @brief Converts the specified string to Float value
	 * @param str The string.
	 * @return Float value.
	 */
	Float to_float(const String& str);

	/**
	 * @brief Converts the specified string to Double value.
	 * @param str The string.
	 * @return Double value.
	 */
	Double to_double(const String& str);

	/**
	 * @brief Converts a Int8 value to string.
	 * @param val The value to convert.
	 * @return Converted result string.
	 */
	String to_string(Int8 val);

	/**
	 * @brief Converts a UInt8 value to string.
	 * @param val The value to convert.
	 * @return Converted result string.
	 */
	String to_string(UInt8 val);

	/**
	 * @brief Converts a Int16 value to string.
	 * @param val The value to convert.
	 * @return Converted result string.
	 */
	String to_string(Int16 val);

	/**
	 * @brief Converts a UInt16 value to string.
	 * @param val The value to convert.
	 * @return Converted result string.
	 */
	String to_string(UInt16 val);

	/**
	 * @brief Converts a Int32 value to string.
	 * @param val The value to convert.
	 * @return Converted result string.
	 */
	String to_string(Int32 val);

	/**
	 * @brief Converts a UInt32 value to string.
	 * @param val The value to convert.
	 * @return Converted result string.
	 */
	String to_string(UInt32 val);

	/**
	 * @brief Converts a Int64 value to string.
	 * @param val The value to convert.
	 * @return Converted result string.
	 */
	String to_string(Int64 val);

	/**
	 * @brief Converts a UInt64 value to string.
	 * @param val The value to convert.
	 * @return Converted result string.
	 */
	String to_string(UInt64 val);

	/**
	 * @brief Converts a Float value to string.
	 * @param val The value to convert.
	 * @return Converted result string.
	 */
	String to_string(Float val);

	/**
	 * @brief Converts a Float value to string.
	 * @param val The value to convert.
	 * @param precision The precision.
	 * @return Converted result string.
	 */
	String to_string(Float val, int precision);

	/**
	 * @brief Converts a Double value to string.
	 * @param val The value to convert.
	 * @return Converted result string.
	 */
	String to_string(Double val);

	/**
	 * @brief Converts a Double value to string.
	 * @param val The value to convert.
	 * @param precision The precision.
	 * @return Converted result string.
	 */
	String to_string(Double val, int precision);

	/**
	 * @brief Converts a String value to string.
	 * @param val The value to convert.
	 * @return Converted result string.
	 */
	String to_string(const String& str);

}