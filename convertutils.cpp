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

#include <sstream>
#include <string.h>
#include "convertutils.h"

namespace cx {
	class CONV {
	public:
		template<class _T>
		static void ToString(const _T& v, std::string& s) {
			std::stringstream ss;
			ss << v;
			s = ss.str();
		}

		template<class _T>
		static void ToString(const _T& v, std::string& s, int precision) {
			std::stringstream ss;
			ss.precision(precision);
			ss << v;
			s = ss.str();
		}

		template<class _T>
		static std::string ToString(const _T& v) {
			std::stringstream ss;
			ss << v;
			return ss.str();
		}

		template<class _T>
		static void Parse(const std::string& src, _T& dst) {
			std::stringstream ss;
			ss << src;
			ss >> dst;
		}

		template<class _T>
		static _T Parse(const std::string& src) {
			std::stringstream ss;
			ss << src;
			_T v;

			ss >> v;

			return v;
		}

		template<class _T>
		static _T Parse(const std::string& src, _T defaultValue) {
			std::stringstream ss;
			ss << src;
			_T v = defaultValue;

			ss >> v;

			return v;
		}
	};

	template<>
	void CONV::ToString(const std::string& v, std::string& s) {
		s = v;
	}

	template<>
	std::string CONV::ToString(const std::string& v) {
		return v;
	}

#define CONVToString() \
	String str; CONV::ToString(val, str); return str;

	Int8 to_int8(const String& str) {
		return (Int8)CONV::Parse<Int16>(str, 0);
	}

	UInt8 to_uint8(const String& str) {
		return (UInt8)CONV::Parse<Int16>(str, 0);
	}

	Int16 to_int16(const String& str) {
		return CONV::Parse<Int16>(str, 0);
	}

	UInt16 to_uint16(const String& str) {
		return CONV::Parse<UInt16>(str, 0);
	}

	Int32 to_int32(const String& str) {
		return CONV::Parse<Int32>(str, 0);
	}

	UInt32 to_uint32(const String& str) {
		return CONV::Parse<UInt32>(str, 0);
	}

	Int64 to_int64(const String& str) {
		return CONV::Parse<Int64>(str, 0);
	}

	UInt64 to_uint64(const String& str) {
		return CONV::Parse<UInt64>(str, 0);
	}

	Float to_float(const String& str) {
		return CONV::Parse<Float>(str, 0);
	}

	Double to_double(const String& str) {
		return CONV::Parse<Double>(str, 0);
	}

	String to_string(Int8 val) {
		String str; CONV::ToString((Int16)val, str); return str;
	}

	String to_string(UInt8 val) {
		String str; CONV::ToString((UInt16)val, str); return str;
	}

	String to_string(Int16 val) {
		CONVToString();
	}

	String to_string(UInt16 val) {
		CONVToString();
	}

	String to_string(Int32 val) {
		CONVToString();
	}

	String to_string(UInt32 val) {
		CONVToString();
	}

	String to_string(Int64 val) {
		CONVToString();
	}

	String to_string(UInt64 val) {
		CONVToString();
	}

	String to_string(Float val) {
		CONVToString();
	}

	String to_string(Float val, int precision) {
		String str;
		CONV::ToString(val, str, precision);
		return str;
	}

	String to_string(Double val) {
		CONVToString();
	}

	String to_string(Double val, int precision) {
		String str; 
		CONV::ToString(val, str, precision);
		return str;
	}

	String to_string(const String& str) {
		return str;
	}

	static char _HEX_TABLE[] = {
		'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'
	};

	void to_hex(Byte* src, size_t length, char* dst) {
		if (src == NULL) throw std::invalid_argument("src");
		if (dst == NULL) throw std::invalid_argument("dst");
		if (length == 0) return;

		for (int i = 0; i < length; i++, dst += 2) {
			Byte b = src[i];
			dst[0] = _HEX_TABLE[b >> 4];
			dst[1] = _HEX_TABLE[b & 0x0f];
		}
	}

	void from_hex(const char* src, size_t length, Byte* dst) {
		if (src == NULL) throw std::invalid_argument("src");
		if (dst == NULL) throw std::invalid_argument("dst");
		if (length == 0) return;

		for (int i = 0; i < length; i += 2, dst++) {
			char c1 = src[i];
			char c2 = src[i + 1];

			if (c1 > '9') c1 += 9;
			if (c2 > '9') c2 += 9;

			dst[0] = (c1 << 4) | (c2 & 0x0f);
		}
	}
}