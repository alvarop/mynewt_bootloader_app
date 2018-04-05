## Bootloader Test App

### Description
Simple test application to demonstrate entering serial bootloader without
requiring a boot pin.

The application uses the NRF52DK board and exposes a serial terminal with two
commands
* bootloader - Resets the board after setting a retained register with the magic bootloader value
* reset - Resets the board normally

### Test Instructions
`newt install`
`newt build nrf52_boot`
`newt load nrf52_boot`
`newt run nrf52dk 0`

Connect over serial and run the `bootloader` command. The device should reset
and enter serial bootloader mode. newtmgr can then be used to list/update images

### Notes
This currently requires modifications to [apache-mynewt-core](https://github.com/apache/mynewt-core).
The changes can be found here: https://github.com/alvarop/mynewt-core/tree/reset_to_bootloader
