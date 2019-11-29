# sdcard2iso
sdcard2iso is a simple tool to create ISO images from an SD card for Windows.

To properly access the partitions on the disk image, you may need to extend the file by running
```
dd if=/dev/zero bs=512 count=1024 >> sdcard.iso
```
You may need to run this command more than once.

https://unix.stackexchange.com/questions/319922/error-cant-have-a-partition-outside-the-disk-even-though-number-of-sectors
