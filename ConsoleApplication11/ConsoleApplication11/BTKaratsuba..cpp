#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LL long long
#define min(x, y) ((x)<(y)?(x):(y))

const LL B = 100000000;
const LL SIZE = 8; // độ dài của mỗi chữ số
const LL M[] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000 };

typedef struct {
	int n;
	LL *d;
} num;

// in số ra stdout
void print(num x) {
	if (x.n == 0) printf("0");
	else {
		printf("%lld", x.d[x.n - 1]);
		for (int i = x.n - 1; i--;) printf("%08lld", x.d[i]);
	}
	printf("\n");
}

// tạo một số mới, có số chữ số là `size`
num alloc(int size) {
	num x;
	x.n = size;
	x.d = (LL*)calloc(size, sizeof(LL));
	return x;
}

num zero() {
	num x;
	x.n = 0;
	x.d = NULL;
	return x;
}

// xoá các số 0 vô nghĩa
void shift(num *r) {
	LL *i = r->d + (r->n - 1);
	while (*i == 0 && r->n > 0) r->n--, i--;
}

// đọc số từ chuỗi
num read(char *s) {
	int slen = strlen(s);
	int size = slen / SIZE + (slen % SIZE != 0);
	num r = alloc(size);
	for (int i = 0, j = slen - 1; i < size; i++) {
		r.d[i] = 0;
		for (int c = 0; c < SIZE && j >= 0; c++, j--) r.d[i] += M[c] * (s[j] - 48);
	}
	shift(&r);
	*s = 0; // xoá nội dung của chuỗi sau khi đọc xong
	return r;
}

// x += a
void sum(LL *x, num a) {
	LL rem = 0;
	for (LL *i = a.d, *e = a.d + a.n; i != e; i++, x++) {
		rem += *i + *x;
		if (rem >= B) {
			*x = rem - B;
			rem = 1;
		}
		else {
			*x = rem;
			rem = 0;
		}
	}
	for (; rem > 0; x++) {
		rem += *x;
		if (rem >= B) {
			*x = rem - B;
			rem = 1;
		}
		else {
			*x = rem;
			rem = 0;
		}
	}
}

// x -= a
void sub(LL *x, num a) {
	LL rem = 0;
	for (LL *i = a.d, *e = a.d + a.n; i != e; i++, x++) {
		rem += *x - *i;
		if (rem < 0) {
			*x = rem + B;
			rem = -1;
		}
		else {
			*x = rem;
			rem = 0;
		}
	}
	for (; rem < 0; x++) {
		rem += *x;
		if (rem < 0) {
			*x = rem + B;
			rem = -1;
		}
		else {
			*x = rem;
			rem = 0;
		}
	}
}

// a += b * x
void mul(LL *a, num b, LL x) {
	LL rem = 0;
	for (LL *i = b.d, *e = b.d + b.n; i != e; i++, a++) {
		rem += *a + *i*x;
		*a = rem % B;
		rem /= B;
	}
	for (; rem > 0; a++) {
		rem += *a;
		*a++ = rem % B;
		rem /= B;
	}
}

// tính `m` trong công thức trên
int split_size(int x, int y) {
	int r = min(x, y) / 2;
	if (x - r == r || y - r == r) return r - 1;
	return r;
}

// chia `x` thành `x0` và `x1`
void split(num x, num *x0, num *x1, int m) {
	x0->n = m;
	x0->d = x.d;
	x1->n = x.n - m;
	x1->d = x.d + m;
	shift(x0);
	shift(x1);
}

num copy(num x) {
	num r = alloc(x.n);
	memcpy(r.d, x.d, x.n * sizeof(LL));
	return r;
}

num karatsuba(num x, num y) {
	if (x.n == 0 || y.n == 0) return zero();
	if (x.n <= 16) {
		num t = x; x = y; y = t;
	}
	if (y.n <= 16) {
		// thực hiện phép nhân thông thường nếu 1 trong 2 số x, y có độ dài <= 16
		num r = alloc(x.n + y.n);
		for (int i = 0; i<y.n; i++) {
			mul(r.d + i, x, y.d[i]);
		}
		// lưu ý xoá các số 0 vô nghĩa, nếu không thuật toán sẽ chạy sai
		shift(&r);
		return r;
	}
	num x0, x1, y0, y1;
	int m = split_size(x.n, y.n);
	split(x, &x0, &x1, m);
	split(y, &y0, &y1, m);
	num xy0 = karatsuba(x0, y0); // xy0 = x0 * y0
	num xy1 = karatsuba(x1, y1); // xy1 = x1 * y1
	num r = alloc(x.n + y.n); // kết quả
	memcpy(r.d, xy0.d, xy0.n * sizeof(LL)); // r = x0 * y0
	sum(r.d + m, xy0); // r += x0*y0*B^m
	sum(r.d + m, xy1); // r += x1*y1*B^m
	sum(r.d + 2 * m, xy1); // r += x1*y1*b^2m
	free(xy0.d);
	free(xy1.d);
	// sx = x1 - x0
	num sx = copy(x1);
	sub(sx.d, x0);
	shift(&sx);
	// sy = y1 - y0
	num sy = copy(y1);
	sub(sy.d, y0);
	shift(&sy);
	// xy = (x1 - x0) * (y1 - y0)
	num xy = karatsuba(sx, sy);
	sub(r.d + m, xy); // r -= B^m * (x1 - x0) * (y1 - y0)
	shift(&r);
	free(xy.d);
	free(sx.d);
	free(sy.d);
	return r;
}

int main() {
	int m; scanf("%d", &m);
	char *s = (char*)calloc(300001, 1);
	while (m--) {
		scanf("%s", s);
		num a = read(s);
		scanf("%s", s);
		num b = read(s);
		num ab = karatsuba(a, b);
		print(ab);
		free(ab.d);
		free(a.d);
		free(b.d);
	}
	free(s);
	return 0;
}