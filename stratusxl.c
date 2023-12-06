/*
 *  HID support for Linux
 *
 *  Copyright (c) 2023 Lukas Praster
 */

/*
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 */


#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/hid.h>

#define BTH_VENDOR_ID_STEELSERIES       0x0111
#define BTH_DEVICE_ID_STEELSERIES_STRXL 0x1419

static int icade_input_mapped(struct hid_device *hdev, struct hid_input *hi,
	struct hid_field *field, struct hid_usage *usage,
	unsigned long **bit, int *max)
{
	if (usage->type == EV_KEY) {
		switch (usage->hid & HID_USAGE) {
			case 0x224:
				printk(KERN_ALERT "Key.Back     >> BTN_SELECT");
				hid_map_usage(hi,usage,bit,max,EV_KEY, BTN_SELECT);
				set_bit(usage->type, hi->input->evbit);
				break;
			case 0x223:
				printk(KERN_ALERT "Key.HomePage >> BTN_MODE  ");
				hid_map_usage(hi,usage,bit,max,EV_KEY, BTN_MODE);
				set_bit(usage->type, hi->input->evbit);
				break;
			case 0x040:
				printk(KERN_ALERT "Key.Menu     >> KEY_MENU  ");
				break;
			default:
				return 1;
		}
		return 1;
	}

	if (usage->type == EV_ABS) {
		set_bit(usage->type, hi->input->absbit);
		return 1;
	}

	return -1;
}



static const struct hid_device_id hid_stratusxl_table[] = {
	{ HID_BLUETOOTH_DEVICE(BTH_VENDOR_ID_STEELSERIES,BTH_DEVICE_ID_STEELSERIES_STRXL)},
	{ }
};

MODULE_DEVICE_TABLE(hid, hid_stratusxl_table);

static struct hid_driver hid_stratusxl = {
	.name = "stratusxl",
	.id_table = hid_stratusxl_table,
	.input_mapped = icade_input_mapped,
};

static int __init stratusxl_init(void){
	int retval;
	printk(KERN_ALERT ">>>> Hello, SteelSeries Stratus XL (Bluetooth)\n");
	retval = hid_register_driver(&hid_stratusxl);
	return retval;
}


static void __exit stratusxl_exit(void){
	printk(KERN_ALERT ">>>> Goodbye, SteelSeries Stratus XL (Bluetooth)\n");
	hid_unregister_driver(&hid_stratusxl);
}

module_init(stratusxl_init);
module_exit(stratusxl_exit);

MODULE_AUTHOR("Lukas Praster");
MODULE_INFO(key_mappings,"KEY_HOMEPAGE mapped to BTN_MODE\n\t\tKEY_BACK mapped to BTN_SELECT");
MODULE_DESCRIPTION("steelseries Stratus XL\n\t\tbluetooth gamepad driver");
MODULE_LICENSE("GPL");
MODULE_VERSION("1.0");
