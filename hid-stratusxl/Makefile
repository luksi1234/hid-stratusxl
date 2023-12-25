obj-m += hid-stratusxl.o

VERBOSE=0
KVERSION = $(shell uname -r)

all:
	make -C /lib/modules/$(KVERSION)/build V=$(VERBOSE) M=$(PWD) modules

install:
	make -C /lib/modules/$(KVERSION)/build V=$(VERBOSE) M=$(shell pwd) modules_install
	depmod -A
	modprobe hid-stratusxl
	echo "hid-stratusxl" > /etc/modules-load.d/hid-stratusxl.conf

clean:
	test ! -d /lib/modules/$(KVERSION) || make -C /lib/modules/$(KVERSION)/build V=$(VERBOSE) M=$(PWD) clean

load:
	sudo insmod hid-stratusxl.ko

unload:
	sudo rmmod hid-stratusxl

