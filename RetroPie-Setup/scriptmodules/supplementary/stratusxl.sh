#!/usr/bin/env bash

# This file is part of The RetroPie Project
#
# The RetroPie Project is the legal property of its developers, whose names are
# too numerous to list here. Please refer to the COPYRIGHT.md file distributed with this source.
#
# See the LICENSE.md file at the top-level directory of this distribution and
# at https://raw.githubusercontent.com/RetroPie/RetroPie-Setup/master/LICENSE.md
#

rp_module_id="stratuxl"
rp_module_desc="Updated steelseries Stratus XL bluetooth Linux Kernel driver"
rp_module_help="This is the latest stratusxl driver from https://github.com/luksi1234/hid-stratusxl\n\n\n\nThis fixes mapping the the button KEY_HOEMPAGE and KEY_BACK in Emulation Station.\n\nIf you want the previous trigger behaviour please remoce this driver"
rp_module_licence="GPL2 https://www.kernel.org/pub/linux/kernel/COPYING"
rp_module_repo="git https://github.com/luksi1234/hid-stratusxl.git master"
rp_module_section="driver"
rp_module_flags="noinstclean !mali"

function _version_stratusxl() {
    echo "0.1"
}

function depends_stratusxl() {
    local depends=(dkms LINUX-HEADERS)
    getDepends "${depends[@]}"
}

function sources_stratusxl() {
    rm -rf "$md_inst"
    gitPullOrClone "$md_inst"
    cd "$md_inst"
    # LED support (as disabled currently in packaged RPI kernel) and allow forcing MAP_TRIGGERS_TO_BUTTONS
    # applyPatch "$md_data/01_enable_leds_and_trigmapping.diff"
    # Tell 'dkms' to use the 'updates' kernel module folder to store the module
    # applyPatch "$md_data/02_dkms_updates_folder.diff"
}

function build_stratusxl() {
    dkmsManager install stratusxl "$(_version_stratusxl)"
}

function remove_stratusxl() {
    dkmsManager remove stratusxl "$(_version_stratusxl)"
    rm -f /etc/modprobe.d/stratsuxl.conf
}

function configure_stratusxl() {
    [[ "$md_mode" == "remove" ]] && return

    if [[ ! -f /etc/modprobe.d/stratusxl.conf ]]; then
        echo "options stratusxl map_keys_to_buttons=1" >/etc/modprobe.d/startusxl.conf
    fi
    dkmsManager reload stratsuxl "$(_version_stratusxl)"
}

