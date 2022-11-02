# qmk-config for Ferris keyboards

- setup QMK: https://docs.qmk.fm/#/newbs_getting_started
- instead of creating custom layout, go to `~/qmk_firmware/keyboards/ferris/keymaps` and make a link to this repo, for example `ln -s ~/source/repos/qmk-config fukkei`
- in QMKSYS exec `qmk compile -kb ferris/sweep -km fukkei -j 8`
- output firmware file is `~/qmk_firmware/.build/ferris_sweep_fukkei.hex`. shall be flashed via QMK Toolbox
