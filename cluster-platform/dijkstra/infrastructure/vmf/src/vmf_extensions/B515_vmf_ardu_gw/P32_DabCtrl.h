#ifndef __PNS3030_DAB_CTRL_H__
#define __PNS3030_DAB_CTRL_H__

#include "P32_TypeDef.h"

//#define MSC0_E_SRC              0
//#define MSC1_E_SRC              1
//#define FIC_E_SRC               3
//#define FEC_E_SRC               4

#define PN_OFDM_FEC             0x0
#define PN_FEC			0x1

PN_S32  EV_OPERATE(PN_U8 pn_type);
PN_VOID EV_INIT(PN_U8 pn_type, PN_U8 tuner_type, PN_FLOAT frequency);
PN_VOID EV_INIT_TOP(PN_U8 pn_type, PN_U8 tuner_type);
PN_VOID EV_INIT_COMM(PN_U8 pn_type, PN_U8 tuner_type);
PN_VOID EV_INIT_HOST(PN_U8 pn_type, PN_U8 tuner_type);
PN_VOID EV_INIT_OFDM(PN_U8 pn_type, PN_U8 tuner_type, PN_FLOAT frequency);
PN_VOID EV_INIT_FEC(PN_U8 pn_type, PN_U8 tuner_type);
PN_VOID EV_FM_INIT(PN_U8 pn_type, PN_U8 tuner_type);
PN_VOID EV_FM_DEFAULT(PN_U8 pn_type);

PN_VOID EV_SOFT_RESET(PN_U8 pn_type, PN_U8 flag);
PN_VOID EV_INTERRUPT_SETUP(PN_U8 pn_type);
PN_VOID EV_UNMASK_INTERRUPT(PN_U8 pn_type, PN_U8 mem_mode, PN_U8 on_off);
PN_VOID EV_STANDBY_CONTROL(PN_U8 pn_type, PN_S32 stanby);
PN_VOID EV_SLEEP_CONTROL(PN_U8 pn_type, PN_U8 sleep, PN_U8 tuner_type,PN_FLOAT frequency);

PN_VOID EV_RESET_FIC_MEM(PN_U8 pn_type);
PN_VOID EV_RESET_MSC0_MEM(PN_U8 pn_type);
PN_VOID EV_RESET_MSC1_MEM(PN_U8 pn_type);
PN_VOID EV_CLEAR_MSC0_SUBCH(PN_U8 pn_type);
PN_VOID EV_CLEAR_MSC1_SUBCH(PN_U8 pn_type);
PN_VOID EV_SETUP_FIC_MEM(PN_U8 pn_type);
PN_U16  EV_SETUP_MSC0_MEM(PN_U8 pn_type, PN_U16 threshold, PN_U16 readlen);
PN_U16  EV_SETUP_MSC1_MEM(PN_U8 pn_type, PN_U16 threshold, PN_U16 readlen);
PN_U16  EV_SETUP_MSC1_FM_MEM(PN_U8 pn_type, PN_U16 threshold, PN_U16 readlen);
PN_U16  EV_SETUP_MSC0_RDS_MEM(PN_U8 pn_type, PN_U16 threshold, PN_U16 readlen);
PN_VOID EV_SET_PATH_VIDEO_SUBCH(PN_U8 pn_type, PN_U8 subch, PN_U8 channel_on);
PN_VOID EV_SET_PATH_DATA_SUBCH(PN_U8 pn_type, PN_U8 subch, PN_U8 channel_on);
PN_VOID EV_SET_PATH_AUDIO_SUBCH(PN_U8 pn_type, PN_U8 subch, PN_U8 channel_on);
PN_VOID EV_SET_PATH_PKT_SUBCH(PN_U8 pn_type, PN_U8 subch, PN_U16 pkt_addr);

PN_U16  EV_GET_SUBCH_SIZE(PN_U8 pn_type, PN_U8 subch);
PN_VOID EV_SET_RECONFIGURATION(PN_U8 pn_type, PN_U8 subch, PN_U8 type, PN_U16 pkt_addr);

PN_S32  EV_CHANNEL_SCAN_CONTROL(PN_U8 pn_type, PN_S32 tuner_type, PN_FLOAT frequency);
PN_S32  MAX2172_CHANNEL_SCAN_CONTROL(PN_U8 pn_type, PN_S32 tuner_type, PN_FLOAT frequency);
PN_S32  EV_OFDM_LOCK_STAT(PN_U8 pn_type, PN_U8 tuner_type, PN_U8 *tr_mode, PN_U8 check_time);
PN_S32  MAX2172_OFDM_LOCK_STAT(PN_U8 pn_type, PN_U8 tuner_type, PN_U8 *tr_mode, PN_U8 check_time);
PN_VOID EV_ALL_LOCK_STAT(PN_U8 pn_type, PN_U8 *agc_lock, PN_U8 *coarse_lock, PN_U8 *time_lock, PN_U8 *ofdm_lock);
PN_VOID EV_OFDM_STAT(PN_U8 pn_type, PN_U8 *tr_mode, PN_U16 *null_len, PN_U8 *iq_inv, PN_U16 *con_vari, PN_S32 *snr_bar, PN_S32 *snr, PN_S32 tuner_type, PN_S8 *cfreq);
PN_VOID EV_OFDM_STAT2(PN_U8 pn_type, PN_U8 *fsm, PN_U8 *adc_over, PN_U8 *ascv, PN_S8 *tscv, PN_U8 *fft_vcnt, PN_U8 *clk_cnt, PN_U8 *tclk_cnt);
PN_VOID EV_OFDM_STAT3(PN_U8 pn_type, PN_S32 *facc, PN_S8 *toffset, PN_S32 *tacc, PN_U16 *sym_offset, PN_U8 *coef, PN_U16 *post_agc, PN_U16 *pre_agc);
PN_VOID EV_OFDM_STAT4(PN_U8 pn_type, PN_U8 *co_ch_sel, PN_U8 *co_ch_cnt, PN_U8 *co_ch_lock, PN_U16 *co_ch_start, PN_U16 *co_ch_end, PN_U16 *co_ch_apwr);
PN_VOID EV_OFDM_STAT5(PN_U8 pn_type, PN_S16 *mon_imb_i, PN_S16 *mon_imb_q, PN_U8 *fic_spec_mon);
PN_VOID EV_OFDM_STAT6(PN_U8 pn_type, PN_U8 *id_on, PN_U16 *pre_des, PN_U16 *post_des,PN_U8 *echo_lock, PN_U8 *echo_pre_lcnt, PN_U8 *echo_post_lcnt, PN_U8 *o_vari,PN_U8 *out_sel,PN_U8 *fec_ndata);
PN_VOID EV_OFDM_STAT7(PN_U8 pn_type, PN_U16 *notACS_fic, PN_U16 *notACS_msc, PN_U16 *renorm_fic,PN_U16 *renorm_msc,PN_U16 *total_subchsize, PN_U16 *current_subchsize, PN_U8 *cif_cnt, PN_U8 *recon_cif);
PN_VOID EV_OFDM_STAT8(PN_U8 pn_type, PN_U8 *scan_mon, PN_U16 *mon_scan_pwr);
PN_VOID EV_RF_STAT(PN_U8 pn_type, PN_U8 *rf_reg00, PN_U8 *rf_reg01, PN_U8 *rf_reg02, PN_U8 *rf_reg04, PN_U8 *rf_reg15);

PN_VOID EV_CHANNEL_STAT(PN_U8 pn_type, PN_U8 *fic_crc, PN_U16 *fic_val, PN_U16 *fic_cnt, PN_U32 *msc_val, PN_U32 *msc_cnt, PN_U32 *zero_ber);
PN_VOID EV_CHANNEL_STAT2(PN_U8 pn_type, PN_U8 *fec_sync_f,PN_U8 *rnorm_cnt);
PN_VOID EV_CONSTELL_STAT(PN_U8 pn_type, PN_S8 *mon_diff_i, PN_S8 *mon_diff_q);
PN_VOID EV_TII_MON_STAT(PN_U8 pn_type, PN_U8 *tii_c1, PN_U8 *tii_p1, PN_U16 *tii_s1);
PN_VOID EV_RS_STAT(PN_U8 pn_type, PN_U8 *rs_sync, PN_U32 *bit_cnt, PN_U32 *bit_val, PN_U16 *alarm_err);
PN_VOID EV_SNR_MON(PN_U8 pn_type); 
PN_VOID EV_TII1_STAT(PN_U8 pn_type, PN_S32 *tii_c, PN_S32 *tii_p, PN_S32 *tii_s, PN_S32 *tii_t);
PN_VOID EV_TII2_STAT(PN_U8 pn_type, PN_S32 *tii_c2, PN_S32 *tii_p2, PN_S32 *tii_s2, PN_S32 *tii_t2);
PN_VOID EV_MRC_STATUS(PN_U8 pn_type, PN_U8 *mrc_mode, PN_U8 *frame_sync, PN_U8 *symbol_sync);
PN_VOID EV_MRC_SETUP(PN_U8 pn_type, PN_U8 mrc_state, PN_U8 tuner_type);

PN_S32  EV_AGC_STAT(PN_U8 pn_type);
PN_S32  EV_POST_AGC_STAT(PN_U8 pn_type);

PN_VOID EV_RSSI_STAT(PN_U8 pn_type, PN_S16 *sig_level, PN_S8 *sig_bar, PN_FLOAT frequency);
PN_VOID EV_MAX2172_RSSI_STAT(PN_U8 pn_type, PN_S16 *sig_level, PN_S8 *sig_bar, PN_FLOAT Frequency);

PN_S32  EV_FM_LOCK_STAT(PN_U8 pn_type);
PN_VOID EV_FMRDS_STAT(PN_U8 pn_type, PN_U8 *fm_lock, PN_U8 *rds_lock, PN_U8 *rds_gain, PN_U8 *osc57_offset, PN_U8 *fm_cnt);
PN_VOID EV_FMRDS_STAT2(PN_U8 pn_type, PN_U8 *fm_adc_over, PN_U16 *fm_post_agc, PN_U16 *fm_pre_agc, PN_S32 *fm_facc, PN_S32 *fm_tacc);
PN_VOID EV_FMRDS_STAT3(PN_U8 pn_type,PN_U8 *fm_mode, PN_U8 *filter_coef, PN_S16 *mon_imb_i, PN_S16 *mon_imb_q, PN_U8 *hpf_th_h, PN_U8 *hpf_th_l,
                                      PN_U16 *mon_hpf_noise, PN_U8 *noise_status, PN_U8 *fm_scan_en);
PN_VOID EV_FMRDS_ERR(PN_U8 pn_type, PN_S32 *dc_val, PN_U8 *fm_vary, PN_S32 *rds_toffset);

PN_S32  EV_WRITE_TUNER_REG(PN_U8 pn_type, PN_U8 chip_addr, PN_U8 reg_addr, PN_U8 value);
PN_S32  EV_WRITE_TUNER_BURST(PN_U8 pn_type, PN_U8 chip_addr, PN_U8 reg_addr, PN_U8 *value, PN_U8 size);
PN_S32  EV_READ_TUNER_REG(PN_U8 pn_type, PN_U8 chip_addr, PN_U8 reg_addr, PN_U8 *value);
PN_S32  EV_READ_TUNER_BURST(PN_U8 pn_type, PN_U8 chip_addr, PN_U8 reg_addr, PN_U8 *value, PN_U8 size);
#endif

