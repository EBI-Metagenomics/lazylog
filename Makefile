.POSIX:

LAZYLOG_VERSION := 0.3.0

CC := gcc
CFLAGS := $(CFLAGS) -std=c11 -Wall -Wextra

all: example

%.o: %.c $(HDR)
	$(CC) $(CFLAGS) -c $<

lazylog.c: lazylog.h nanoprintf.h
lazylog.o: lazylog.c lazylog.h nanoprintf.h
example.o: example.c lazylog.o

example: example.o lazylog.o
	$(CC) $^ $(CFLAGS) -o $@

dist: clean lazylog.h lazylog.c
	mkdir -p lazylog-$(LAZYLOG_VERSION)
	cp -R README.md LICENSE lazylog.h lazylog.c nanoprintf.h lazylog-$(LAZYLOG_VERSION)
	tar -cf - lazylog-$(LAZYLOG_VERSION) | gzip > lazylog-$(LAZYLOG_VERSION).tar.gz
	rm -rf lazylog-$(LAZYLOG_VERSION)

distclean:
	rm -f lazylog-$(LAZYLOG_VERSION).tar.gz

clean: distclean
	rm -f *.o example

.PHONY: all clean dist distclean
