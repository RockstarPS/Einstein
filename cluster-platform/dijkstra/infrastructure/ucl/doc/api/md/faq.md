# Frequently Asked Questions {#faq}

### Why does my VIP reset after UCL integration?
Please check if you have 
* Allocated sufficient stack in the Davinci Configurator Tool for UclProxyCdd. Recommended size is 2048 bytes.
* UclProxyCdd Periodic Task is configured as recommeded in the UCL User Guide.

### No UCL Communication
Check if the drivers are able to exchange messages without UCL stack. You can use echo/cat commands in the QNX / Linux systems to send / receive data over UART or use the spi_test code to send / receive data over SPI.

### I have configured my message at 10ms periodicity but it is being sent in slower rate.
Check the timers configuration in the UclInstCfg.c for both VIP and GIP.

### UCL Sanity Check ###
[Click here for UCL Sanity Check]( https://visteon.sharepoint.com/sites/OS-BSP-DK/_layouts/15/guestaccess.aspx?guestaccesstoken=ZTd5Pm1zQwnMKXXsOKM%2BHzJjQUHA%2FY9PBhYdcpsimfU%3D&docid=2_03360f8c48fcf4cdfb0ab61cd176446e0&rev=1&e=Y7dIqU)

