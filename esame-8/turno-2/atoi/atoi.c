#include <stdint.h>
#include <math.h>


int atoi_rec(const char *str, size_t i, size_t last) {
	if (i > 0) return (str[i] - '0') * pow(10, last - i) + atoi_rec(str, i - 1, last);

	return (str[i] - '0') * pow(10, last - i);
}

int AToI(const char *str) {
	if (str == NULL) return 0;
	size_t i = 0;
	while (str[i] != 0) i++;

	if (i > 1)
		return (str[i - 1] - '0') + atoi_rec(str, i - 2, i - 1);
	else
		return str[i - 1] - '0';
}