This is the readme file for J721E IMG OMXIL video encoder & decoder -
Release date - Sep 16 2022

Overview
--------
Provides both an IMG OMXIL video encoder & decoder with resource manager support,
along with an OMX encode test app and an OMX decode test app.

Applicable for
--------------
J721E/TDA4VX

Build steps:
-----------
1: Follow the "Getting Started" chapter in the Processor SDK QNX documentation
2: cd ${PSDK_RTOS}/psdkqa/qnx
3: make clean
4: make all
5: make qnx_fs_create

NOTE1: The IMG OMX video encoder & decoder test apps currently only support NV12 .yuv inputs (encode) and outputs (decode)

NOTE2: The default run time env "OMXIL_COMPONENT_PATH" defaults to /lib/dll/omxil.
However, for the TI PSDKQA package, the location is expected to be in the SD card filesystem
path /ti_fs/tilib. This has been updated in the user.sh script found under /ti_fs/scripts

Decoder Test steps:
-------------------
1: Please note that in the supplied user.sh script, the IMG decoder resource manager is started. See user.sh file in the /scripts folder.

2: To run the OpenMAXIL test app for a single H.264/HEVC decode, boot QNX on the EVM and then run a command like this example:

omxil_video_dec -v -i /ti_fs/codec_test/bitstream/test_example.265 -o /ti_fs/codec_test/output/test_example.yuv

Multi-channel Decode Test steps:
--------------------------------
1a: To run the OpenMAXIL test app for multi-channel decode test (e.g., 2x decodes), create a script, ti_j7_dec.sh, with a couple of commands like this:

omxil_video_dec -i /ti_fs/codec_test/bitstream/test_example1.265 -o /ti_fs/codec_test/output/test_example1.yuv&
omxil_video_dec -i /ti_fs/codec_test/bitstream/test_example2.265 -o /ti_fs/codec_test/output/test_example2.yuv&

1b: Copy the ti_j7_dec.sh script to the scripts folder on the SD card

2: Boot QNX on the EVM and then run this:
# /ti_fs/scripts/ti_j7_dec.sh

Output YUV (NV12) files will be in the location: /ti_fs/codec_test/output/

Encoder Test steps:
-------------------
1: Please note that in the supplied user.sh script, the IMG encoder resource manager is started. See user.sh file in the /scripts folder.

2a: To run the OpenMAXIL test app for multi-channel encode test (e.g., 2x encodes), create a script, ti_j7_enc.sh, with these lines:

omxil_video_enc -i /ti_fs/codec_test/nv12/8bit_BQTerrace_720x128_9frame_nv12.yuv -c /ti_fs/codec_test/encoder_parameters.conf -o /tmp/bt.264 -d -f nv12,720x128@30&
omxil_video_enc -i /ti_fs/codec_test/nv12/mix_1920x1080_8b_10frm_nv12.yuv -c /ti_fs/codec_test/encoder_parameters.conf -o /tmp/mix.264 -d -f nv12,1920x1080@30&

2b: Copy the ti_j7_enc.sh script to the scripts folder on the SD card

3: Boot QNX on the EVM and then run this:
# /ti_fs/scripts/ti_j7_enc.sh

4: After the encoded bitstream files are complete in the /tmp dir, then copy to the FS:
# cp /tmp/*.264 /ti_fs/codec_test/output/

NOTE1: The default encoder parameters can be overriden with a configuration file for the OMX encoder test apps.
The file is found in: codec/img/qnx/OpenMAXIL/test/enc/encoder_parameters.conf
In case we would like to use the configuration file, we must provide an additonal command line parameter "-c /ti_fs/codec_test/encoder_parameters.conf"

Test steps for performance analysis only:
----------------------------------------
1: Please note that in the supplied user.sh script, the IMG encoder resource manager is started. See user.sh file in the /scripts folder.

2a: To run the OpenMAXIL performance test app for multi-channel encode test (e.g., 2x encodes) for default 10 sec, create a script, ti_j7_enc_p.sh, with these lines:

omxil_video_enc_p -n -i /ti_fs/codec_test/nv12/8bit_BQTerrace_720x128_9frame_nv12.yuv -c /ti_fs/codec_test/encoder_parameters.conf -o /tmp/bt_p.264 -d -f nv12,720x128@30&
omxil_video_enc_p -n -i /ti_fs/codec_test/nv12/mix_1920x1080_8b_10frm_nv12.yuv -c /ti_fs/codec_test/encoder_parameters.conf -o /tmp/mix_p.264 -d -f nv12,1920x1080@30&

2b: Copy the ti_j7_enc_p.sh script to the scripts folder on the SD card

3: Boot QNX on the EVM and then run this:
# /ti_fs/scripts/ti_j7_enc_p.sh

4: After the encoded bitstream files are complete in the /tmp dir, then copy to the FS:
# cp /tmp/*.264 /ti_fs/codec_test/output/

NOTE1: The generated output will only contain the first 15 frames of the input repeatedly encoded into the output file.

NOTE2: The average fps for each encode is printed out on the terminal at the end of the encode test.

NOTE3: The default encoder parameters can be overriden with a configuration file for the OMX encoder test apps.
The file is found in: codec/img/qnx/OpenMAXIL/test/enc/encoder_parameters.conf
In case we would like to use the configuration file, we must provide an additonal command line parameter "-c /ti_fs/codec_test/encoder_parameters.conf"


Overriding encoder parameters:
------------------------------

# bitrate 8M
bitrate=8000000

# rate control mode
# 1 OMX_Video_ControlRateVariable
# 2 OMX_Video_ControlRateConstant
rcmode=1

# AVC IDR Period
idr_period=60


Performance measurements for video decode:
-----------------------------------------
Frame-to-frame decoding delay and average decoding FPS can be measured in the resource manager layer.
To enable the log: export the following environment variable

#export VXDDEC_PERFORMANCE_LOG_DIR=/tmp

restart vxd_dec:

#slay vxd_dec
#vxd_dec

This way, performance_log_ch_$CHID.log will be generated in $VXDDEC_PERFORMANCE_LOG_DIR directory.
$CHID is the channel id of the decoding channel, if there's more than one decoding instance running simultaneously
the performance data will be logged in different files for each decode instance.
To disable performance logging, you need to unset VXDDEC_PERFORMANCE_LOG_DIR, then restart vxd_dec.

Here's what's in the performance log file:
1: input timestamp for each frame to be decoded by the omxil decode component, logged before calling the function to decode a frame.
2: output timestamp for each frame decoded, after the decoded output buffer is returned.
3: decoding delay measured in milliseconds for each frame.
   when each frame is about to be decoded, its timestamp (i_ts) is inserted into a timestamp queue.
   Then, when the frame is decoded and the output buffer is returned, the current time is c_ts.
   So, the decoding delay for the frame is calculated with:

   delay = c_ts - i_ts

4: you can find average decoding FPS at the end of log file. The average decoding FPS is calculated with:

   ave_fps = total_frames_decoded / total_decoding_time

   total decoding time is the time from first frame being sent until getting the last frame (flag EOS).


Performance measurements for video encode:
-----------------------------------------
Average frame rate, total encode time, and total frames decoded can be measured by the omxil_video_enc_p test app.
To enable logging: export the following environment variable

export VXEENC_PERFORMANCE_LOG_DIR=/tmp

There is no need to restart vxe_enc, but removing the log files between tests is required for accurate logging.

performance_log_ch_$CHID.log will be generated in the $VXEENC_PERFORMANCE_LOG_DIR directory. $CHID is the channel id of the 
decoding channel, if there's more than one decoding instance running simultaneously the performance data will be logged in 
different files for each decode instance. To disable performance logging, you need to unset $VXEENC_PERFORMANCE_LOG_DIR

*** end of document ***
