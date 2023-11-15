#!/usr/bin/bash

ln -s ~/qmk ~/qmk_firmware/keyboards/kbdfans/niu_mini/keymaps/ivo

qmk compile -kb kbdfans/niu_mini -km ivo
qmk flash -kb kbdfans/niu_mini -km ivo

