#!/usr/bin/env bash

# This file is part of The RetroPie Project
#
# The RetroPie Project is the legal property of its developers, whose names are
# too numerous to list here. Please refer to the COPYRIGHT.md file distributed with this source.
#
# See the LICENSE.md file at the top-level directory of this distribution and
# at https://raw.githubusercontent.com/RetroPie/RetroPie-Setup/master/LICENSE.md
#

rp_module_id="stratusxl"
rp_module_desc="Updated steelseries Stratus XL bluetooth Linux Kernel driver"
rp_module_help="This is the latest stratusxl driver from https://github.com/luksi1234/hid-stratusxl\n\n\n\nThis fixes mapping the the button KEY_HOEMPAGE and KEY_BACK in Emulation Station.\n\nIf you want the previous trigger behaviour please remoce this driver"
rp_module_licence="GPL2 https://www.kernel.org/pub/linux/kernel/COPYING"
rp_module_repo="git https://github.com/luksi1234/hid-stratusxl.git main"
rp_module_section="driver"
rp_module_flags="nobin"

function _version_stratusxl() {
    echo "0.1"
}

function depends_stratusxl() {
    local depends=(dkms LINUX-HEADERS)
    getDepends "${depends[@]}"
}

function sources_stratusxl() {
    echo "md_inst: $md_inst"
    echo "md_build: $md_build"
    rm -rf "$md_inst"
    #gitPullOrClone "$md_inst"
    gitPullOrClone
    rsync -a --delete "$md_build/hid-stratusxl/" "$md_inst/"
    cd "$md_inst"
}

function build_stratusxl() {
    dkmsManager install hid-stratusxl "$(_version_stratusxl)"
}

function remove_stratusxl() {
    dkmsManager remove hid-stratusxl "$(_version_stratusxl)"
    rm -f /etc/modprobe.d/hid-stratusxl.conf
}

function configure_stratusxl() {
    [[ "$md_mode" == "remove" ]] && return

    #currently no special option for hid driver
    #if [[ ! -f /etc/modprobe.d/hid-stratusxl.conf ]]; then
    #    echo "options stratusxl map_keys_to_buttons=1" >/etc/modprobe.d/stratusxl.conf
    #fi
    dkmsManager reload hid-stratusxl "$(_version_stratusxl)"
}

