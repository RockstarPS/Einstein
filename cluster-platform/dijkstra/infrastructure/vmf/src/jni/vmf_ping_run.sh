

./vmf_ping_listener -i 0 -g 01 -c 500 -t &
#./vmf_ping_listener -i 1 -g 01 -c 500 -t &
#./vmf_ping_listener -i 2 -g 01 -c 500 -t &

./vmf_ping_sender -g 01 -e 02 -n 11223344 -l1000 -t -c 500 -d 20 -w 3 &





#    VMF_TRACE_ERROR("usage", "************************************************************************\n");
#    VMF_TRACE_ERROR("usage", "** vmf_sender process                                                 **\n");
#    VMF_TRACE_ERROR("usage", "************************************************************************\n");
#    VMF_TRACE_ERROR("usage", "**                                                                    **\n");
#    VMF_TRACE_ERROR("usage", "** usage: vmf_sender [options]                                        **\n");
#    VMF_TRACE_ERROR("usage", "**                                                                    **\n");
#    VMF_TRACE_ERROR("usage", "**     Opt.   Description                                    Default  **\n");
#    VMF_TRACE_ERROR("usage", "**     -h     this help                                               **\n");
#    VMF_TRACE_ERROR("usage", "**     -g     message group                                  0        **\n");
#    VMF_TRACE_ERROR("usage", "**     -e     event                                          0        **\n");
#    VMF_TRACE_ERROR("usage", "**     -n     near data, always 4byte, NO spaces             -        **\n");
#    VMF_TRACE_ERROR("usage", "**     -l     length of far data                             0        **\n");
#    VMF_TRACE_ERROR("usage", "**     -f     far data, requires option -l, NO spaces        -        **\n");
#    VMF_TRACE_ERROR("usage", "**     -t     put time snapshot into far data (8 bytes)      false    **\n");
#    VMF_TRACE_ERROR("usage", "**     -c     message count                                  1        **\n");
#    VMF_TRACE_ERROR("usage", "**     -d     message delay [ms]                             100      **\n");
#    VMF_TRACE_ERROR("usage", "**     -w     wait (before sending) [s]                      0        **\n");
#    VMF_TRACE_ERROR("usage", "**                                                                    **\n");
#    VMF_TRACE_ERROR("usage", "************************************************************************\n");


#    VMF_TRACE_ERROR("usage", "***************************************************************");
#    VMF_TRACE_ERROR("usage", "** vmf_listener process                                      **");
#    VMF_TRACE_ERROR("usage", "***************************************************************");
#    VMF_TRACE_ERROR("usage", "**                                                           **");
#    VMF_TRACE_ERROR("usage", "** usage: vmf_listener [options]                             **");
#    VMF_TRACE_ERROR("usage", "**     -h     this help                                      **");
#    VMF_TRACE_ERROR("usage", "**     -i     listener index (if more than 1 listener)       **");
#    VMF_TRACE_ERROR("usage", "**     -g     message group                                  **");
#    VMF_TRACE_ERROR("usage", "**     -c     message count                                  **");
#    VMF_TRACE_ERROR("usage", "**     -s     suppress results                               **");
#    VMF_TRACE_ERROR("usage", "**     -t     evaluate time diff per message                 **");
#    VMF_TRACE_ERROR("usage", "**                                                           **");
#    VMF_TRACE_ERROR("usage", "***************************************************************");




