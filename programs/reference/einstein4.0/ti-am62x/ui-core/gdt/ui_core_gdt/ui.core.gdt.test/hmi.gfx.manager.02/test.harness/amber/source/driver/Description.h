/*
        *** THIS IS A FILE FOR DOXYGEN AND NOT A C HEADER FILE ***
*/

/**
 *******************************************************************************
 ** \mainpage PDL for Traveo - Documentation
 ** <hr>
 *******************************************************************************
 ** \image html Spansion_logo.png
 **
 ** Copyright (C) 2014 Spansion LLC. All Rights Reserved. 
 **
 ** This software is owned and published by: 
 ** Spansion LLC, 915 DeGuigne Dr. Sunnyvale, CA  94088-3453 ("Spansion").
 **
 ** BY DOWNLOADING, INSTALLING OR USING THIS SOFTWARE, YOU AGREE TO BE BOUND 
 ** BY ALL THE TERMS AND CONDITIONS OF THIS AGREEMENT.
 **
 ** This software contains source code for use with Spansion 
 ** components. This software is licensed by Spansion to be adapted only 
 ** for use in systems utilizing Spansion components. Spansion shall not be 
 ** responsible for misuse or illegal use of this software for devices not 
 ** supported herein.  Spansion is providing this software "AS IS" and will 
 ** not be responsible for issues arising from incorrect user implementation 
 ** of the software.
 **
 ** SPANSION MAKES NO WARRANTY, EXPRESS OR IMPLIED, ARISING BY LAW OR OTHERWISE,
 ** REGARDING THE SOFTWARE (INCLUDING ANY ACOOMPANYING WRITTEN MATERIALS), 
 ** ITS PERFORMANCE OR SUITABILITY FOR YOUR INTENDED USE, INCLUDING, 
 ** WITHOUT LIMITATION, THE IMPLIED WARRANTY OF MERCHANTABILITY, THE IMPLIED 
 ** WARRANTY OF FITNESS FOR A PARTICULAR PURPOSE OR USE, AND THE IMPLIED 
 ** WARRANTY OF NONINFRINGEMENT.  
 ** SPANSION SHALL HAVE NO LIABILITY (WHETHER IN CONTRACT, WARRANTY, TORT, 
 ** NEGLIGENCE OR OTHERWISE) FOR ANY DAMAGES WHATSOEVER (INCLUDING, WITHOUT 
 ** LIMITATION, DAMAGES FOR LOSS OF BUSINESS PROFITS, BUSINESS INTERRUPTION, 
 ** LOSS OF BUSINESS INFORMATION, OR OTHER PECUNIARY LOSS) ARISING FROM USE OR 
 ** INABILITY TO USE THE SOFTWARE, INCLUDING, WITHOUT LIMITATION, ANY DIRECT, 
 ** INDIRECT, INCIDENTAL, SPECIAL OR CONSEQUENTIAL DAMAGES OR LOSS OF DATA, 
 ** SAVINGS OR PROFITS, 
 ** EVEN IF SPANSION HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES. 
 ** YOU ASSUME ALL RESPONSIBILITIES FOR SELECTION OF THE SOFTWARE TO ACHIEVE YOUR
 ** INTENDED RESULTS, AND FOR THE INSTALLATION OF, USE OF, AND RESULTS OBTAINED 
 ** FROM, THE SOFTWARE.  
 **
 ** This software may be replicated in part or whole for the licensed use, 
 ** with the restriction that this Disclaimer and Copyright notice must be 
 ** included with each copy of this software, whether used in part or whole, 
 ** at all times. 
 **
 ** <br>
 ** <hr>
 ** <b>History</b>
 **  - 2014-06-23
 **    - Version 0.01
 **    - Comment: First alpha release version
 **
 **  - 2014-07-4
 **    - Version 0.02
 **    - Comment: Beta release version
 **
 ** <hr>
 ** 
 ** <b>Implementations in PDL:</b>
 ** <table border="0">
 ** <tr><td> HWDG   </td><td>&nbsp; Hardware Watch Dog Timer                        </td></tr>
 ** <tr><td> SWDG   </td><td>&nbsp; Software Watch Dog Timer                        </td></tr>
 ** <tr><td> PORT   </td><td>&nbsp; Port functions                                  </td></tr>
 ** <tr><td> WFLASH </td><td>&nbsp; Work Flash operation                            </td></tr>
 ** <tr><td> CPU    </td><td>&nbsp; CPU Module                                      </td></tr>
 ** <tr><td> MEM    </td><td>&nbsp; Memory functions(i.e. configure core MPU)       </td></tr>
 ** <tr><td> UART   </td><td>&nbsp; Asynchronous Serial Interface                   </td></tr>
 ** <tr><td> LIN    </td><td>&nbsp; Local Interconnect Network                      </td></tr>
 ** <tr><td> ADC    </td><td>&nbsp; Analog to Digital Converter                     </td></tr>
 ** <tr><td> CAN-FD </td><td>&nbsp; CAN with Flexible Data rate                     </td></tr>
 ** <tr><td> FRT    </td><td>&nbsp; Free Running Timer                              </td></tr>
 ** <tr><td> PWM    </td><td>&nbsp; Pulse Width Modulation                          </td></tr>
 ** <tr><td> RLT    </td><td>&nbsp; Reload Timer                                    </td></tr>
 ** <tr><td> ICU    </td><td>&nbsp; Input Capture Unit                              </td></tr>
 ** <tr><td> EIC    </td><td>&nbsp; External Interrupt Controller                   </td></tr>
 ** </table>
 **
 ** <hr>
 **
 ** <b>Examples:</b>
 ** 
 ** - HWDG
 **   - <pre>use_prewarn            Setup Hwdg(Use pre-warning interrupt)</pre>
 **
 ** - SWDG
 **   - <pre>use_prewarn            Setup Swdg(Use pre-warning interrupt)</pre>
 **
 ** - PORT
 **   - <pre>blink_led              Simple port setting (Blink LEDs) </pre>
 ** 
 ** - WFLASH
 **   - <pre>write_sector0          Work Flash operation test</pre>
 **
 ** - UART
 **   - <pre>fifo_use               UART normal mode (HW FIFO used) </pre>
 ** 
 ** - LIN
 **   - <pre>mfs_lin_use_ch2_ch3    Tansfer between Master(ch3) and Slave(ch2) </pre>
 **
 ** - ADC
 **   - <pre>single_irq_sw          Single channel conversion with conversion end interrupt </pre>
 **
 ** - CAN-FD
 **   - <pre>echoback_message       Echoback by reception data, and not use FIFO</pre>
 ** 
 ** - FRT
 **   - <pre>updown_count           FRT up/down mode operation</pre>
 ** 
 ** - PWM
 **   - <pre>output_waveform        Output waveform by 50% duty</pre>
 ** 
 ** - RLT
 **   - <pre>reload_continuous      Running contunuous mode</pre>
 **
 ** - ICU
 **   - <pre>detect_falling_edge    Detect falling edge and get a timer data</pre>
 **
 ** - EIC
 **   - <pre>detect_rising_edge     Detect rising edge</pre>
 ** 
 ** <b>Usage of example code:</b>
 ** 
 ** Each example code consists of a 'main.c' and a 'driver/pdl_user.h' module.
 ** Some modules have flash_marker.asm, mcu_settings.h.
 ** The main module contains the example code, where 'pdl_user.h'
 ** contains all necessary settings and definitions for the example
 ** itself.
 ** To use and compile an example, just copy these modules
 ** to the 'source' and 'source/driver' folder, overwriting the modules located
 ** there.The overwritten modules have backups in the 'source/backup' folder for recovery.
 ** 
 ** <br><hr><br>
 ** 
 ******************************************************************************/