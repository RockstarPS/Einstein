@echo off
echo -----------------------------------------
echo *** Converting Elf %1 to Binary ***

arm-none-eabi-objcopy -O binary %1 %1.bin
arm-none-eabi-objcopy -O srec %1 %1.srec

echo *** %1.bin Conversion Successful ***


