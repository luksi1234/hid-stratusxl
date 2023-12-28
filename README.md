# hid-stratusxl
Linux HID bluetooth driver for steelseries Stratus XL

This driver is useful if you want to use steelseries Stratus XL gamepad within retropie.

In standard, linux hid-generic driver will be used.
If hid-generic driver is used two buttons will not be available in retropie.

### Installation

The following command will download and install module for RetroPie Setup.
After installation you can install/deinstall the driver for SteelSerie StratusXL in the Retropie Setup.

Exceute as root:
```
wget -O - https://github.com/luksi1234/hid-stratusxl/raw/main/install/retropie_install.sh | bash
```

Afterwards you should be able to install driver with Retropie Setup GUI.

Manage packages -> Manage driver packages -> stratusxl -> Install from source


Have fun.

