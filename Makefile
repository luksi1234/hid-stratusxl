obj-m += stratusxl.o
#MY_CFLAGS += -g -DDEBUG -DHID_DEBUG -DCONFIG_HID_DEBUG -DDEBUG_FS -DCONFIG_DEBUG_FS
#ccflags-y += ${MY_CFLAGS}
#CC += ${MY_CFLAGS}

KVERSION = $(shell uname -r)

all:
	make -C /lib/modules/$(KVERSION)/build V=1 M=$(PWD) modules

#debug:
#	make -C /lib/modules/$(KVERSION)/build V=1 M=$(PWD) modules EXTRA_CFLAGS="$(MY_CFLAGS)"

install:
	make -C /lib/modules/$(KVERSION)/build V=1 M=$(shell pwd) modules_install
	depmod -A
	modprobe stratusxl
	echo "stratusxl" > /etc/modules-load.d/stratusxl.conf

clean:
#	make -C /lib/modules/$(KVERSION)/build V=1 M=$(PWD) clean
	test ! -d /lib/modules/$(KVERSION) || make -C /lib/modules/$(KVERSION)/build V=1 M=$(PWD) clean

load:
	sudo insmod stratusxl.ko

unload:
	sudo rmmod stratusxl


modprobe:
	modprobe stratusxl
	modprobe -r stratuxl

## sudo insmod stratusxl.ko
## sudo rmmod stratusxl.ko

## sudo modprobe stratusxl
## sudo modprobe -r stratusxl


## bluetooth coonect cli

## hcitool dev
## hcitool dev
## hcitool -i hci0 scan
## bluetoothctl
##      trust FC:XX:XX:XX:XX:FE
##      connect FC:XX:XX:XX:XX:FE
##      paired-devices
