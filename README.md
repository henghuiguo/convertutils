# convertutils
This project provides a collection of **cross-platform** convertion utilities between C++/STL string and different value types.


# How to use
1. Copy convertutils.h and convertutils.cpp to your project.
2. #include "convertutils.h"
3. Invoke APIs in namespace **cx**, as follows:
```cplusplus
	// Convert a string to Int32 value.
	std::cout << cx::to_int32("1234") << std::endl; // -> 1234
	// Convert a Int32 value to string.
	std::cout << cx::to_string(1234) << std::endl; // -> 1234
	// Convert a string to Double value.
	std::cout.precision(16);
	std::cout << cx::to_double("3.141592653589793") << std::endl; // -> 3.141592653589793
	// Convert a Double value to string.
	std::cout << cx::to_string(3.14159) << std::endl; // -> 3.14159
	// Convert a Double value to string with precision.
	std::cout << cx::to_string(3.141592653589793, 16) << std::endl; // -> 3.141592653589793
	// Convert a string to Float value.
	std::cout.precision(7);
	std::cout << cx::to_float("3.141592") << std::endl; // -> 3.141592
	// Convert a Float value to string.
	std::cout << cx::to_string(3.14159F) << std::endl; // -> 3.14159
	// Convert a Float value to string.
	std::cout << cx::to_string(3.141592F, 7) << std::endl; // -> 3.141592
	// Encode a string to BASE64 format.
	std::cout << cx::to_base64("1234") << std::endl; // -> MTIzNA==
	// Decode a BASE64 string.
	std::cout << cx::from_base64("MTIzNA==") << std::endl; // -> 1234
   // ...
```

# Tests
```cplusplus

#include "convertutils.h"
#include <limits>

#define ASSERT(EXP) \
	if(!(EXP)) { \
		printf("\t#################### F A I L E D ####################\nASSERT: %s \n  => FAILED\n", #EXP); ; fflush(stdout); \
		return false; \
	}

bool EQUALS(float a, float b) {
	static float epsilon = std::numeric_limits<float>::epsilon();
	return ((a - b) < epsilon) && ((b - a) < epsilon);
}

bool EQUALS(double a, double b) {
	static double epsilon = std::numeric_limits<double>::epsilon();
	return ((a - b) < epsilon) && ((b - a) < epsilon);
}


bool test_convert()
{
	ASSERT(cx::to_int8("") == 0);
	ASSERT(cx::to_int8("-1") == -1);
	ASSERT(cx::to_int8("1") == 1);
	ASSERT(cx::to_int8("12") == 12);
	ASSERT(cx::to_uint8("255") == 255);

	ASSERT(cx::to_int16("") == 0);
	ASSERT(cx::to_int16("-1") == -1);
	ASSERT(cx::to_int16("1") == 1);
	ASSERT(cx::to_int16("12") == 12);
	ASSERT(cx::to_uint16("255") == 255);

	ASSERT(cx::to_int32("") == 0);
	ASSERT(cx::to_int32("-1") == -1);
	ASSERT(cx::to_int32("1") == 1);
	ASSERT(cx::to_int32("12") == 12);
	ASSERT(cx::to_uint32("255") == 255);

	ASSERT(cx::to_int64("") == 0);
	ASSERT(cx::to_int64("-1") == -1);
	ASSERT(cx::to_int64("1") == 1);
	ASSERT(cx::to_int64("12") == 12);
	ASSERT(cx::to_uint64("255") == 255);

	ASSERT(cx::to_float("") == 0.0f);
	ASSERT(cx::to_float("0.001") == 0.001f);
	ASSERT(cx::to_float("10.001") == 10.001f);
	ASSERT(cx::to_double("0.001") == 0.001);
	ASSERT(cx::to_double("10.001") == 10.001);

	ASSERT(cx::to_string((unsigned char)1) == "1");
	ASSERT(cx::to_string((unsigned char)255) == "255");
	ASSERT(cx::to_string((short)255) == "255");
	ASSERT(cx::to_string((unsigned short)255) == "255");
	ASSERT(cx::to_string((int)255) == "255");
	ASSERT(cx::to_string((unsigned int)255) == "255");
	ASSERT(cx::to_string((int64_t)255) == "255");
	ASSERT(cx::to_string((uint64_t)255) == "255");

	ASSERT(cx::to_string(0.001f) == "0.001");
	ASSERT(cx::to_string(10.001f) == "10.001");

	// Convert a string to Int32 value.
	ASSERT(cx::to_int32("1234") == 1234);
	// Convert a Int32 value to string.
	ASSERT(cx::to_string(1234) == "1234");
	// Convert a string to Double value.
	ASSERT(EQUALS(cx::to_double("3.141592653589793"), 3.141592653589793));
	// Convert a Double value to string.
	ASSERT(cx::to_string(3.14159) == "3.14159");
	// Convert a Double value to string with precision.
	ASSERT(cx::to_string(3.141592653589793, 16) == "3.141592653589793");
	// Convert a string to Float value.
	ASSERT(EQUALS(cx::to_float("3.141592"), 3.141592F));
	// Convert a Float value to string.
	ASSERT(cx::to_string(3.14159F) == "3.14159");
	// Convert a Float value to string.
	ASSERT(cx::to_string(3.141592F, 7) == "3.141592");
	// Encode a string to BASE64 format.
	ASSERT(cx::to_base64("1234") == "MTIzNA==");
	// Decode a BASE64 string.
	ASSERT(cx::from_base64("MTIzNA==") == "1234");

	{
		std::string src = "123456";
		cx::ByteVector src2;
		std::string src3;
		std::string  dst;
		for (size_t i = 0; i < src.size(); i++)
			src2.push_back((cx::Byte)src[i]);

		cx::to_base64(src2, dst);
		cx::from_base64(dst, src3);

		ASSERT(src == src3);

		ASSERT(cx::from_base64(cx::to_base64(src2)) == src);

	}

	return true;
}

int main()
{
	if (!test_convert()) return 1;

	printf("All tests passed!\n");
	return 0;
}


```
