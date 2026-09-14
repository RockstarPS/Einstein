
#define nw_sil_SBUS_TIOdometerStatus_odoMeterGroupValue_odoMeterValue_get(FrameBuffer)	 	     (*(unsigned32*) (FrameBuffer))
#define nw_sil_SBUS_TIOdometerStatus_odoMeterGroupValue_tripAValue_get(FrameBuffer)		 	     (*(unsigned32*) (FrameBuffer[4]))
#define nw_sil_SBUS_TIOdometerStatus_odoMeterGroupValue_tripBValue_get(FrameBuffer)		 	     (*(unsigned32*) (FrameBuffer[8]))
#define nw_sil_SBUS_TIOdometerStatus_odoMeterStatus_get(FrameBuffer)					 		 (*(unsigned8*)  (FrameBuffer[12]))
#define nw_sil_SBUS_TIOdometerStatus_odoMeterUnit_get(FrameBuffer)						 		 (*(unsigned8*)  (FrameBuffer[13]))

#define nw_sil_SBUS_TIOdometerStatus_odoMeterGroupValue_odoMeterValue_set(FrameBuffer, VALUE)	 (*(unsigned32*) (FrameBuffer     = VALUE))
#define nw_sil_SBUS_TIOdometerStatus_odoMeterGroupValue_tripAValue_set(FrameBuffer, VALUE)		 (*(unsigned32*) (FrameBuffer[4]  = VALUE))
#define nw_sil_SBUS_TIOdometerStatus_odoMeterGroupValue_tripBValue_set(FrameBuffer, VALUE)		 (*(unsigned32*) (FrameBuffer[8]  = VALUE))
#define nw_sil_SBUS_TIOdometerStatus_odoMeterStatus_set(FrameBuffer, VALUE)					     (*(unsigned8*)  (FrameBuffer[12] = VALUE))
#define nw_sil_SBUS_TIOdometerStatus_odoMeterUnit_set(FrameBuffer, VALUE)						 (*(unsigned8*)  (FrameBuffer[13] = VALUE))