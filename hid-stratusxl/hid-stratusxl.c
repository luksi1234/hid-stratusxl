#/*
 *  HID Driver for Gamepad SteelSeries Stratus XL (Bluetooth) for Linux
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
#include <linux/slab.h>
#include <linux/hid-debug.h>


#define BTH_VENDOR_ID_STEELSERIES       0x0111
#define BTH_DEVICE_ID_STEELSERIES_STRXL 0x1419


// Original Stratus XL Report Descriptor
/*
static __u8 stratusxl_orig_report_desc[] = {

	0x05, 0x01,        // Usage Page (Generic Desktop Ctrls)
	0x09, 0x06,        // Usage (Keyboard)
	0xA1, 0x01,        // Collection (Application)
	0x85, 0x02,        //   Report ID (2)
	0x05, 0x0C,        //   Usage Page (Consumer)
	0x0A, 0x24, 0x02,  //   Usage (AC Back)
	0x0A, 0x23, 0x02,  //   Usage (AC Home)
	0x09, 0x40,        //   Usage (Menu)
	0x15, 0x00,        //   Logical Minimum (0)
	0x25, 0x01,        //   Logical Maximum (1)
	0x95, 0x03,        //   Report Count (3)
	0x75, 0x01,        //   Report Size (1)
	0x81, 0x02,        //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
	0x95, 0x05,        //   Report Count (5)
	0x81, 0x01,        //   Input (Const,Array,Abs,No Wrap,Linear,Preferred State,No Null Position)
	0xC0,              // End Collection
	0x05, 0x01,        // Usage Page (Generic Desktop Ctrls)
	0x09, 0x02,        // Usage (Mouse)
	0xA1, 0x01,        // Collection (Application)
	0x85, 0x03,        //   Report ID (3)
	0x09, 0x01,        //   Usage (Pointer)
	0xA1, 0x00,        //   Collection (Physical)
	0x05, 0x09,        //     Usage Page (Button)
	0x19, 0x01,        //     Usage Minimum (0x01)
	0x29, 0x05,        //     Usage Maximum (0x05)
	0x15, 0x00,        //     Logical Minimum (0)
	0x25, 0x01,        //     Logical Maximum (1)
	0x95, 0x05,        //     Report Count (5)
	0x75, 0x01,        //     Report Size (1)
	0x81, 0x02,        //     Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
	0x95, 0x01,        //     Report Count (1)
	0x75, 0x03,        //     Report Size (3)
	0x81, 0x01,        //     Input (Const,Array,Abs,No Wrap,Linear,Preferred State,No Null Position)
	0x05, 0x01,        //     Usage Page (Generic Desktop Ctrls)
	0x09, 0x30,        //     Usage (X)
	0x09, 0x31,        //     Usage (Y)
	0x09, 0x38,        //     Usage (Wheel)
	0x15, 0x81,        //     Logical Minimum (-127)
	0x25, 0x7F,        //     Logical Maximum (127)
	0x75, 0x08,        //     Report Size (8)
	0x95, 0x03,        //     Report Count (3)
	0x81, 0x06,        //     Input (Data,Var,Rel,No Wrap,Linear,Preferred State,No Null Position)
	0xC0,              //   End Collection
	0xC0,              // End Collection
	0x05, 0x01,        // Usage Page (Generic Desktop Ctrls)
	0x09, 0x05,        // Usage (Game Pad)
	0xA1, 0x01,        // Collection (Application)
	0x85, 0x01,        //   Report ID (1)
	0x05, 0x01,        //   Usage Page (Generic Desktop Ctrls)
	0x15, 0x00,        //   Logical Minimum (0)
	0x25, 0x07,        //   Logical Maximum (7)
	0x46, 0x3B, 0x01,  //   Physical Maximum (315)
	0x95, 0x01,        //   Report Count (1)
	0x75, 0x04,        //   Report Size (4)
	0x65, 0x14,        //   Unit (System: English Rotation, Length: Centimeter)
	0x09, 0x39,        //   Usage (Hat switch)
	0x81, 0x42,        //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,Null State)
	0x75, 0x01,        //   Report Size (1)
	0x95, 0x04,        //   Report Count (4)
	0x81, 0x01,        //   Input (Const,Array,Abs,No Wrap,Linear,Preferred State,No Null Position)
	0x05, 0x09,        //   Usage Page (Button)
	0x19, 0x01,        //   Usage Minimum (0x01)
	0x29, 0x10,        //   Usage Maximum (0x10)
	0x15, 0x00,        //   Logical Minimum (0)
	0x25, 0x01,        //   Logical Maximum (1)
	0x75, 0x01,        //   Report Size (1)
	0x95, 0x10,        //   Report Count (16)
	0x81, 0x02,        //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
	0x05, 0x01,        //   Usage Page (Generic Desktop Ctrls)
	0x09, 0x01,        //   Usage (Pointer)
	0xA1, 0x00,        //   Collection (Physical)
	0x75, 0x10,        //     Report Size (16)
	0x95, 0x04,        //     Report Count (4)
	0x16, 0x01, 0xF8,  //     Logical Minimum (-2047)
	0x26, 0xFF, 0x07,  //     Logical Maximum (2047)
	0x09, 0x30,        //     Usage (X)
	0x09, 0x31,        //     Usage (Y)
	0x09, 0x32,        //     Usage (Z)
	0x09, 0x35,        //     Usage (Rz)
	0x81, 0x02,        //     Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
	0xC0,              //   End Collection
	0x05, 0x02,        //   Usage Page (Sim Ctrls)
	0xA1, 0x00,        //   Collection (Physical)
	0x15, 0x00,        //     Logical Minimum (0)
	0x26, 0xFF, 0x0F,  //     Logical Maximum (4095)
	0x09, 0xC4,        //     Usage (Accelerator)
	0x09, 0xC5,        //     Usage (Brake)
	0x95, 0x02,        //     Report Count (2)
	0x75, 0x10,        //     Report Size (16)
	0x81, 0x02,        //     Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
	0xC0,              //   End Collection
	0x85, 0x06,        //   Report ID (6)
	0x05, 0x08,        //   Usage Page (LEDs)
	0x09, 0x01,        //   Usage (Num Lock)
	0x09, 0x02,        //   Usage (Caps Lock)
	0x09, 0x03,        //   Usage (Scroll Lock)
	0x09, 0x04,        //   Usage (Compose)
	0x15, 0x00,        //   Logical Minimum (0)
	0x25, 0x01,        //   Logical Maximum (1)
	0x75, 0x01,        //   Report Size (1)
	0x95, 0x04,        //   Report Count (4)
	0x91, 0x02,        //   Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile)
	0x75, 0x04,        //   Report Size (4)
	0x95, 0x01,        //   Report Count (1)
	0x91, 0x03,        //   Output (Const,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile)
	0xC0,              // End Collection
	0x06, 0xC0, 0xFF,  // Usage Page (Vendor Defined 0xFFC0)
	0x09, 0x01,        // Usage (0x01)
	0xA1, 0x01,        // Collection (Application)
	0x06, 0xC1, 0xFF,  //   Usage Page (Vendor Defined 0xFFC1)
	0x85, 0x04,        //   Report ID (4)
	0x15, 0x00,        //   Logical Minimum (0)
	0x26, 0xFF, 0x00,  //   Logical Maximum (255)
	0x75, 0x08,        //   Report Size (8)
	0x09, 0xF0,        //   Usage (0xF0)
	0x95, 0x30,        //   Report Count (48)
	0x81, 0x02,        //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
	0x85, 0x05,        //   Report ID (5)
	0x09, 0xF1,        //   Usage (0xF1)
	0x95, 0x30,        //   Report Count (48)
	0x91, 0x02,        //   Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile)
	0xC0,              // End Collection
	0x00              // Unknown (bTag: 0x00, bType: 0x00)

   
};
*/


static __u8 stratusxl_report_desc[] = {
	0x05, 0x01,        // Usage Page (Generic Desktop Ctrls)
	0x09, 0x05,        // <--- Usage (Game Pad)   //changed !!!
	0xA1, 0x01,        // Collection (Application)
	0x85, 0x02,        //   Report ID (2)
	0x05, 0x0C,        //   Usage Page (Consumer)
	0x0A, 0x24, 0x02,  //   Usage (AC Back)
	0x0A, 0x23, 0x02,  //   Usage (AC Home)
	0x09, 0x40,        //   Usage (Menu)
	0x15, 0x00,        //   Logical Minimum (0)
	0x25, 0x01,        //   Logical Maximum (1)
	0x95, 0x03,        //   Report Count (3)
	0x75, 0x01,        //   Report Size (1)
	0x81, 0x02,        //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
	0x95, 0x05,        //   Report Count (5)
	0x81, 0x01,        //   Input (Const,Array,Abs,No Wrap,Linear,Preferred State,No Null Position)
	0xC0,              // End Collection
	0x05, 0x01,        // Usage Page (Generic Desktop Ctrls)
	0x09, 0x05,        // Usage (Game Pad)
	0xA1, 0x01,        // Collection (Application)
	0x85, 0x01,        //   Report ID (1)
	0x05, 0x01,        //   Usage Page (Generic Desktop Ctrls)
	0x15, 0x00,        //   Logical Minimum (0)
	0x25, 0x07,        //   Logical Maximum (7)
	0x46, 0x3B, 0x01,  //   Physical Maximum (315)
	0x95, 0x01,        //   Report Count (1)
	0x75, 0x04,        //   Report Size (4)
	0x65, 0x14,        //   Unit (System: English Rotation, Length: Centimeter)
	0x09, 0x39,        //   Usage (Hat switch)
	0x81, 0x42,        //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,Null State)
	0x75, 0x01,        //   Report Size (1)
	0x95, 0x04,        //   Report Count (4)
	0x81, 0x01,        //   Input (Const,Array,Abs,No Wrap,Linear,Preferred State,No Null Position)
	0x05, 0x09,        //   Usage Page (Button)
	0x19, 0x01,        //   Usage Minimum (0x01)
	0x29, 0x10,        //   Usage Maximum (0x10)
	0x15, 0x00,        //   Logical Minimum (0)
	0x25, 0x01,        //   Logical Maximum (1)
	0x75, 0x01,        //   Report Size (1)
	0x95, 0x10,        //   Report Count (16)
	0x81, 0x02,        //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
	0x05, 0x01,        //   Usage Page (Generic Desktop Ctrls)
	0x09, 0x01,        //   Usage (Pointer)
	0xA1, 0x00,        //   Collection (Physical)
	0x75, 0x10,        //     Report Size (16)
	0x95, 0x04,        //     Report Count (4)
	0x16, 0x01, 0xF8,  //     Logical Minimum (-2047)
	0x26, 0xFF, 0x07,  //     Logical Maximum (2047)
	0x09, 0x30,        //     Usage (X)
	0x09, 0x31,        //     Usage (Y)
	0x09, 0x32,        //     Usage (Z)
	0x09, 0x35,        //     Usage (Rz)
	0x81, 0x02,        //     Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
	0xC0,              //   End Collection
	0x05, 0x02,        //   Usage Page (Sim Ctrls)
	0xA1, 0x00,        //   Collection (Physical)
	0x15, 0x00,        //     Logical Minimum (0)
	0x26, 0xFF, 0x0F,  //     Logical Maximum (4095)
	0x09, 0xC4,        //     Usage (Accelerator)
	0x09, 0xC5,        //     Usage (Brake)
	0x95, 0x02,        //     Report Count (2)
	0x75, 0x10,        //     Report Size (16)
	0x81, 0x02,        //     Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
	0xC0,              //   End Collection
	0x85, 0x06,        //   Report ID (6)
	0x05, 0x08,        //   Usage Page (LEDs)
	0x09, 0x01,        //   Usage (Num Lock)
	0x09, 0x02,        //   Usage (Caps Lock)
	0x09, 0x03,        //   Usage (Scroll Lock)
	0x09, 0x04,        //   Usage (Compose)
	0x15, 0x00,        //   Logical Minimum (0)
	0x25, 0x01,        //   Logical Maximum (1)
	0x75, 0x01,        //   Report Size (1)
	0x95, 0x04,        //   Report Count (4)
	0x91, 0x02,        //   Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile)
	0x75, 0x04,        //   Report Size (4)
	0x95, 0x01,        //   Report Count (1)
	0x91, 0x03,        //   Output (Const,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile)
	0xC0//,              // End Collection
	//0x00              // Unknown (bTag: 0x00, bType: 0x00)

   
};

static int stratusxl_input_mapping(struct hid_device *hdev, struct hid_input *hi,
		struct hid_field *field, struct hid_usage *usage,
		unsigned long **bit, int *max)
{

	if ((usage->hid & HID_USAGE_PAGE) == HID_UP_CONSUMER) {

		switch (usage->hid & HID_USAGE) {
			case 0x224:
				hid_info(hdev,"Key.Back      >> BTN_SELECT");
				hid_map_usage(hi,usage,bit,max,EV_KEY, BTN_SELECT);
				set_bit(usage->type, hi->input->evbit);
				break;
			case 0x223:
				hid_info(hdev, "Key.Homepage >> BTN_MODE");
				hid_map_usage(hi,usage,bit,max,EV_KEY, BTN_MODE);
				set_bit(usage->type, hi->input->evbit);
				break;
			default:
				return -1;
		}
		return 1;
	}

	return 0;

}


static __u8 *stratusxl_report_fixup(struct hid_device *hdev, __u8 *rdesc,
		unsigned int *rsize)
{
	hid_info(hdev, "Fixing up Report Descriptor (report size: %d)",*rsize);

	rdesc = stratusxl_report_desc;
	*rsize = sizeof(stratusxl_report_desc);

	return rdesc;
}


static int stratusxl_probe(struct hid_device *hdev,
			     const struct hid_device_id *id)
{
	int ret;

	ret = hid_parse(hdev);
	if (ret)
		return ret;

	return hid_hw_start(hdev, HID_CONNECT_DEFAULT);
}


static const struct hid_device_id hid_stratusxl_table[] = {
	{ HID_BLUETOOTH_DEVICE(BTH_VENDOR_ID_STEELSERIES,BTH_DEVICE_ID_STEELSERIES_STRXL)},
	{ }
};


MODULE_DEVICE_TABLE(hid, hid_stratusxl_table);


static struct hid_driver hid_stratusxl = {
	.name          = "hid-stratusxl",
	.id_table      = hid_stratusxl_table,
	.input_mapping = stratusxl_input_mapping, 
	.probe         = stratusxl_probe,
	.report_fixup  = stratusxl_report_fixup,
};

static int __init stratusxl_init(void){
	int retval;
	printk(KERN_INFO ">>>> Hello, SteelSeries Stratus XL (Bluetooth)\n");
	retval = hid_register_driver(&hid_stratusxl);
	return retval;
}


static void __exit stratusxl_exit(void){
	printk(KERN_INFO ">>>> Goodbye, SteelSeries Stratus XL (Bluetooth)\n");
	hid_unregister_driver(&hid_stratusxl);
}


module_init(stratusxl_init);
module_exit(stratusxl_exit);


MODULE_AUTHOR("Lukas Praster");
MODULE_INFO(key_mappings,"KEY_HOMEPAGE mapped to BTN_MODE\n\t\tKEY_BACK mapped to BTN_SELECT");
MODULE_DESCRIPTION("steelseries Stratus XL\n\t\tbluetooth gamepad driver");
MODULE_LICENSE("GPL");
MODULE_VERSION("0.1");
