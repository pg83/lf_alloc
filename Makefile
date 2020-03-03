CC=clang
AR=llvm-ar
RANLIB=llvm-ranlib
CFLAGS=-O2 -std=c++14

all: liblfalloc.a

liblfalloc.a: lfalloc.o
	$(AR) q liblfalloc.a lfalloc.o
	$(RANLIB) liblfalloc.a

lfalloc.o: array_size.h	atomic_gcc.h compiler.h lf_allocX64.cpp malloc.h types.h atomic.h defaults.h lf_allocX64.h platform.h yassert.h
	$(CC) -c lf_allocX64.cpp -o lfalloc.o $(CFLAGS)


clean:
	rm liblfalloc.a lfalloc.o
