.. _faq:

FAQ
===

Why I can't download application in Windows?
--------------------------------------------

If you met the following issue as below message showed:

.. code-block:: console

    Nuclei OpenOCD, 64-bit Open On-Chip Debugger 0.10.0+dev-00014-g0eae03214 (2019-12-12-07:43)
    Licensed under GNU GPL v2
    For bug reports, read
            http://openocd.org/doc/doxygen/bugs.html
    Remote communication error.  Target disconnected.: Success.
    "monitor" command not supported by this target.
    "monitor" command not supported by this target.
    "monitor" command not supported by this target.
    You can't do that when your target is ``exec'
    "monitor" command not supported by this target.
    "monitor" command not supported by this target.
    "Successfully uploaded hello_world.elf "


Please check whether your driver is installed successfully as the board user manual described,
especially, for **RV-STAR** and **HummingBird Evaluation** boards, you need to download the
**HummingBird Debugger Windows Driver** from https://nucleisys.com/developboard.php, and install it.

.. note::

    The USB driver might lost when you re-plug the USB port, you might need to reinstall the driver.


Why I can't download application in Linux?
------------------------------------------

Please check that whether you have followed the board user manual to setup the USB JTAG drivers correctly.
The windows steps and linux steps are different, please take care.


Why the provided application is not running correctly in my HummingBird Evaluation Board?
-----------------------------------------------------------------------------------------

Please check the following items:

1. Did you program the correct Nuclei Evaluation FPGA bitstream?
2. Did you re-power the board, when you just programmed the board with FPGA bitstream?
3. Did you choose the right **CORE** as the Nuclei Evaluation FPGA bitstream present?
4. If your application is RTOS demos, did you run in ``flashxip`` mode, if yes, it is expected
   due to flash speed is really slow, you'd better try ``ilm`` or ``flash`` mode.
5. If still not working, you might need to check whether the FPGA bitstream is correct or not?


Why ECLIC handler can't be installed using ECLIC_SetVector?
-----------------------------------------------------------

If you are running in ``FlashXIP`` download mode, it is expected,
since the vector table is placed in Flash area which can't be changed
during running time.

You can only this ``ECLIC_SetVector`` API in when your vector table
is placed in RAM which can be changed during running time, so if you want to
write portable application, we recommended you to use exactly the eclic handler
names defined in **startup_<device>.S**.


Access to github.com is slow, any workaround?
---------------------------------------------

Access speed to github.com sometimes is slow and not stable, but if you want to clone source code,
you can also switch to use our mirror site maintained in gitee.com.

This mirror will sync changes from github to gitee every 6 hours, that is 4 times a day.

You just need to replace the github to gitee when you clone any repo in **Nuclei-Software** or **riscv-mcu**.

For example, if you want to clone **nuclei-sdk** using command
``git clone https://github.com/Nuclei-Software/nuclei-sdk``, then
you can achieve it by command ``git clone https://gitee.com/Nuclei-Software/nuclei-sdk``

