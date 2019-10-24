#include <iostream>
#include <ctime>
#include <cstring>
#include <fstream>
#include <string>
#include <intrin.h>

#define LITTLE_ENDIAN
#define INC(x) *(x)++

//#define START_VAL(x)
//#define COPY_REMAINING(count, dst8, scr8) {                 \
//    switch (count) {                                        \
//    case 7: INC(dst8) = INC(src8);                          \
//    case 6: INC(dst8) = INC(src8);                          \
//    case 5: INC(dst8) = INC(src8);                          \
//    case 4: INC(dst8) = INC(src8);                          \
//    case 3: INC(dst8) = INC(src8);                          \
//    case 2: INC(dst8) = INC(src8);                          \
//    case 1: INC(dst8) = INC(src8);                          \
//    case 0:                                                 \
//    default: break;                                         \
//    }                                                       \
//}

char* random_construct(size_t size) {
	char* res = new char[size + 1]();
	for (size_t ind = 0; ind < size; ind++) {
		res[ind] = (rand() % 224) + 32;
	}
	return res;
}

errno_t my_memcpy_s(void* dest, size_t destSize, const void* src, size_t count) {
	if (count == 0)
		return 0;
	if (src == NULL || destSize < count) {
		memset(dest, 0, destSize);
		if (src != NULL)
			return EINVAL;
		if (destSize >= count)
			return ERANGE;
	}
	size_t i;
	size_t byte_x8 = count / 8;
	size_t last = count - byte_x8 * 8;
	double* ddest = static_cast<double*>(dest);
	const double* dsrc = static_cast<const double*>(src);
	for (i = 0; i < byte_x8; ++i)
		INC(ddest) = INC(dsrc);
	if (last & 7) {
		size_t razn = count - last;
		char* cdest = static_cast<char*>(dest) + razn;
		const char* csrc = static_cast<const char*>(src) + razn;
		while (last-- & 7)
			INC(cdest) = INC(csrc);
	}
	return 0;
}

int main() {
	srand(time(NULL));
	size_t size = 1024;
	auto buf1 = random_construct(size);
	char *cpy2 = new char[strlen(buf1) + 1]();
	auto begin1 = __rdtsc();
	my_memcpy_s(cpy2, strlen(buf1) + 1, buf1, strlen(buf1) + 1);
	auto end1 = __rdtsc();
	auto res1 = end1 - begin1;
	std::ofstream fout("C:/Users/alex2/OneDrive/Рабочий стол/report.txt", std::ios_base::app);
	fout << "my_memcpy_s: " << res1 << " virtual pts\n";
	delete[] buf1;
	delete[] cpy2;
	return 0;
}