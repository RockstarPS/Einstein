/**********************************************************************************
 **
 **  \file dk_bspal_dio.c
 **
 **  \brief This file provides list of API to interact with the gpiod library
 *for toggle the gpio's
 **
 **  Component Name: bspal_dio
 **  Archive:
 **  Date: 27-05-2024
 **  Author: Durai
 **
 ** Copyright 2024 Visteon Corporation.
 **
 ** These materials and the intellectual property rights associated therewith
 ** (?Materials?) are proprietary to Visteon Corporation. Any and all rights in
 ** the Materials are reserved by Visteon Corporation. Nothing contained in
 ** these Materials shall grant or be deemed to grant to you or anyone else, by
 ** implication, stop or otherwise, any rights in these Materials.
 ***********************************************************************************/

#include "dk_bspal_dio.h"
#include "cDio_bspal.h"
#include "dk_logger.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

LOG_DECLARE_CONTEXT(g_log_bspal_dio);

#ifdef EINSTEIN_TI_DIO

#include "CDio_Ioctl.h"
#include <sys/ioctl.h>
#define DIO_PATH "/dev/dio"

#else
#include <gpiod.h>
#define CONSUMER "BSPAL Linux DIO"
#define GPIOCHIP_PATH "gpiochip%d"
#define PATH_LEN (100u)

static uint32_t g_set_bit_U32 = 1U;
static uint32_t g_clear_bit_U32 = 0U;
static uint32_t g_gpio_id_max_U32 = 0U;

static ts_dio_pindata_t g_dio_pindata = {
    .dio_addr_sa[0].bank_mask_addr = 0x00000000,
    .dio_addr_sa[1].bank_mask_addr = 0x00000000,
    .dio_addr_sa[2].bank_mask_addr = 0x00000000,
    .dio_addr_sa[3].bank_mask_addr = 0x00000000,
    .dio_addr_sa[4].bank_mask_addr = 0x00000000,
    .dio_addr_sa[5].bank_mask_addr = 0x00060082,
    .dio_addr_sa[6].bank_mask_addr = 0x00000800,
};
#endif // EINSTEIN_TI_DIO

/**********************************************************************************
@brief API to register context for logging.
 ***********************************************************************************/
void dk_bspal_dio_init(void) {

  LOG_REGISTER_CONTEXT(g_log_bspal_dio, "BSPALDio", "BSPAL_DIO_CONTEXT",
                       DLT_LOG_VERBOSE);
  LOGI(&g_log_bspal_dio, "invoked \n");

#ifndef EINSTEIN_TI_DIO
  dio_count_mask_bits(g_dio_pindata.dio_addr_sa);
#endif // EINSTEIN_TI_DIO
}

/**********************************************************************************
  @brief API to unregister context.
 ***********************************************************************************/
void dk_bspal_dio_deinit(void) {

  LOGI(&g_log_bspal_dio, "invoked \n");
  LOG_UNREGISTER_CONTEXT(g_log_bspal_dio);
}

#ifdef EINSTEIN_TI_DIO

/**********************************************************************************
  @brief API to set value of a DIO pin
  @param[in] p_pin_U32    The pin which value to be set
  @param[in] p_value_BOOL  The value to be set

  @return Set value status.
 ***********************************************************************************/
int32_t dk_bspal_dio_set_value(const uint32_t p_pin_U32,
                               const bool p_value_BOOL) {
  int32_t l_fd_S32 = 0;
  int32_t l_status_S32 = 0;
  ts_dio_data_t dio_pin_details;

  if (p_pin_U32 > DIO_MAX_ID) {
    LOGW(&g_log_bspal_dio,
         "gpio pin num is not within the supported range of values\n");
    l_status_S32 = -1;
  } else {
    dio_pin_details.gpio_pin_num = p_pin_U32;
    dio_pin_details.gpio_value = p_value_BOOL;

    l_fd_S32 = open(DIO_PATH, O_RDWR);
    if (l_fd_S32 < 0) {
      LOGE(&g_log_bspal_dio, "dio device file open failed\n");
      l_status_S32 = -1;
    } else {
      l_status_S32 = ioctl(l_fd_S32, GPIO_VALUE_WRITE, &dio_pin_details);
      if (l_status_S32 < 0) {
        LOGE(&g_log_bspal_dio, "ioctl GPIO_VALUE_WRITE failed\n");
        l_status_S32 = -1;
      }
      close(l_fd_S32);
    }
  }
  return l_status_S32;
}

/**********************************************************************************
  @brief API to get value of a DIO pin
  @param[in] p_pin_U32    The pin which value to be read.
  @param[in] p_value_BOOLP  pointer to the value to be read.

  @return Get value status.
 ***********************************************************************************/
int32_t dk_bspal_dio_get_value(const uint32_t p_pin_U32,
                               bool *const p_value_BOOLP) {

  int32_t l_fd_S32 = 0;
  int32_t l_status_S32 = 0;
  ts_dio_data_t dio_pin_details;

  if (p_pin_U32 > DIO_MAX_ID) {
    LOGW(&g_log_bspal_dio,
         "gpio pin num is not within the supported range of values\n");
    l_status_S32 = -1;
  } else {
    dio_pin_details.gpio_pin_num = p_pin_U32;
    l_fd_S32 = open(DIO_PATH, O_RDONLY);
    if (l_fd_S32 < 0) {
      LOGE(&g_log_bspal_dio, "dio device file open failed\n");
      l_status_S32 = -1;
    } else {
      l_status_S32 = ioctl(l_fd_S32, GPIO_VALUE_READ, &dio_pin_details);
      if (l_status_S32 < 0) {
        LOGE(&g_log_bspal_dio, "ioctl GPIO_VALUE_READ failed\n");
        l_status_S32 = -1;
      } else {
        *p_value_BOOLP = dio_pin_details.gpio_value;
      }
      close(l_fd_S32);
    }
  }
  return l_status_S32;
}

/**********************************************************************************
  @brief API to set direction of a DIO pin
  @param[in] p_pin_U32    the pin which direction to be set.
  @param[in] p_direction_te  the direction to be set.

  @return set direction status.
 ***********************************************************************************/
int32_t dk_bspal_dio_set_direction(const uint32_t p_pin_U32,
                                   const EDirection p_direction_te) {
  int32_t l_fd_S32 = 0;
  int32_t l_status_S32 = 0;
  ts_dio_data_t dio_pin_details;

  if (p_pin_U32 > DIO_MAX_ID) {
    LOGW(&g_log_bspal_dio,
         "gpio pin num is not within the supported range of values\n");
    l_status_S32 = -1;
  } else {
    dio_pin_details.gpio_pin_num = p_pin_U32;
    dio_pin_details.gpio_direction = p_direction_te;

    l_fd_S32 = open(DIO_PATH, O_RDWR);
    if (l_fd_S32 < 0) {
      LOGE(&g_log_bspal_dio, "dio device file open failed\n");
      l_status_S32 = -1;
    } else {
      l_status_S32 = ioctl(l_fd_S32, GPIO_DIRECTION_WRITE, &dio_pin_details);
      if (l_status_S32 < 0) {
        LOGE(&g_log_bspal_dio, "ioctl GPIO_DIRECTION_WRITE failed\n");
        l_status_S32 = -1;
      }
      close(l_fd_S32);
    }
  }
  return l_status_S32;
}

/**********************************************************************************
  @brief API to READ direction of a DIO pin
  @param[in] p_pin_U32    the pin which direction to be set.
  @param[in] p_direction_TEP  pointer to store the direction to be read

  @return get direction status.
 ***********************************************************************************/
int32_t dk_bspal_dio_get_direction(const uint32_t p_pin_U32,
                                   EDirection *const p_direction_TEP) {
  int32_t l_fd_S32 = 0;
  int32_t l_status_S32 = 0;
  ts_dio_data_t dio_pin_details;

  if (p_pin_U32 > DIO_MAX_ID) {
    LOGW(&g_log_bspal_dio,
         "gpio pin num is not within the supported range of values\n");
    l_status_S32 = -1;
  } else {
    dio_pin_details.gpio_pin_num = p_pin_U32;

    l_fd_S32 = open(DIO_PATH, O_RDONLY);
    if (l_fd_S32 < 0) {
      LOGE(&g_log_bspal_dio, "dio device file open failed\n");
      l_status_S32 = -1;
    } else {
      l_status_S32 = ioctl(l_fd_S32, GPIO_DIRECTION_READ, &dio_pin_details);
      if (l_status_S32 < 0) {
        LOGE(&g_log_bspal_dio, "ioctl GPIO_DIRECTION_READ failed\n");
        l_status_S32 = -1;
      } else {
        *p_direction_TEP = dio_pin_details.gpio_direction;
      }
      close(l_fd_S32);
    }
  }
  return 0;
}

#else 

/**********************************************************************************
  @brief API to mask the bits
  @param[in] ts_dio_add_r pass the addr and bit count

  @return none
 ***********************************************************************************/

void dio_count_mask_bits(ts_dio_addr_t dioCountAaddr_p[]) {
  uint32_t l_bank_U32;
  uint32_t l_mask_val_U32;
  uint32_t l_setbits_U32 = 0;

  for (l_bank_U32 = 0; l_bank_U32 < RCAR3_MAX_BANK_PER_DIO; l_bank_U32++) {
    l_mask_val_U32 = dioCountAaddr_p[l_bank_U32].bank_mask_addr;

    while (l_mask_val_U32) {
      l_setbits_U32 += l_mask_val_U32 & g_set_bit_U32;
      l_mask_val_U32 >>= g_set_bit_U32;
    }

    dioCountAaddr_p[l_bank_U32].set_bits_count_sa = l_setbits_U32;
    g_gpio_id_max_U32 = g_gpio_id_max_U32 + l_setbits_U32;
    l_setbits_U32 = g_clear_bit_U32;
  }

  LOGI(&g_log_bspal_dio,
       " dio_count_mask_bits - Done with counting of set bits in each bank\n");
}


/**********************************************************************************
  @brief  Extract the gpio instance and gpio number
  @param[in]  *dioPinData_p            pass Rcar gpio pin map and addr
  @param[in]  pin_U32                  pass the pin number to find the bank and
 channel number
  @param[in]  *g_currentbanknumber     receive current bank number
  @param[in]  *channel_number          receive correct channel number
  @return function success or failure
 ***********************************************************************************/
static bool dio_data_extract(ts_dio_pindata_t *dioPinData_p, uint32_t p_pin_U32,
                             uint32_t *p_currentbanknumber_U32P,
                             uint32_t *p_channel_number_U32P) {
  uint32_t l_dio_id_U32 = 0;
  uint32_t l_index_U32 = 0;
  uint32_t l_bank_U32;
  uint32_t l_mask_U32;
  uint32_t l_setBitPos_U32;
  uint32_t temp_count;
  uint32_t l_maskVal;
  bool l_ret_BOOL = true;

  l_dio_id_U32 = p_pin_U32;
  l_index_U32 = l_dio_id_U32;

  if (p_pin_U32 > DIO_MAX_ID) {
    LOGW(&g_log_bspal_dio, " dio_data_extract - Invalid DIO_ID passed by user "
                           ": DIO_ID out of range 1");
    l_ret_BOOL = false;
  } else {
    for (l_bank_U32 = 0; l_bank_U32 < RCAR3_MAX_BANK_PER_DIO; l_bank_U32++) {
      temp_count = dioPinData_p->dio_addr_sa[l_bank_U32].set_bits_count_sa;
      if (l_dio_id_U32 < temp_count && (l_index_U32 < 256)) {
        dioPinData_p->dio_pin_sa[l_index_U32].bank_num_U32 = l_bank_U32;
        *p_currentbanknumber_U32P =
            dioPinData_p->dio_pin_sa[l_index_U32].bank_num_U32;
        break;
      } else {

        l_dio_id_U32 = l_dio_id_U32 - temp_count;
      }
    }

    if (l_bank_U32 < RCAR3_MAX_BANK_PER_DIO) {
      l_maskVal = dioPinData_p->dio_addr_sa[l_bank_U32].bank_mask_addr;
      l_setBitPos_U32 = 0;

      for (l_mask_U32 = 0; l_mask_U32 < DIO_PIN_PER_BANK; l_mask_U32++) {
        if ((l_maskVal & g_set_bit_U32) == g_set_bit_U32) {
          l_setBitPos_U32++;

          if ((l_dio_id_U32 + g_set_bit_U32) == l_setBitPos_U32) {
            dioPinData_p->dio_pin_sa[l_index_U32].chnl_num_U32 = l_mask_U32;
            *p_channel_number_U32P =
                dioPinData_p->dio_pin_sa[l_index_U32].chnl_num_U32;
          }
        }
        l_maskVal = l_maskVal >> g_set_bit_U32;
      }

    } else {
      LOGW(&g_log_bspal_dio, "dio_data_extract - Invalid DIO_ID passed by user "
                             ": DIO_ID out of range \n");
      l_ret_BOOL = false;
    }
  }

  return l_ret_BOOL;
}

/**********************************************************************************
  @brief API to set value of a DIO pin
  @param[in] p_pin_U32    The pin which value to be set
  @param[in] p_value_BOOL  The value to be set

  @return Set value status.
 ***********************************************************************************/

int32_t dk_bspal_dio_set_value(const uint32_t p_pin_U32,
                               const bool p_value_BOOL) {
  int32_t l_ret_U32 = -1;
  struct gpiod_chip *chip;
  struct gpiod_line *line;
  int32_t l_ret_spf_SINT = -1;
  char l_path_S8[PATH_LEN];
  int32_t l_ret_SINT = -1;
  bool l_extracted_BOOL = true;

  uint32_t l_channel_number_U32 = 0;
  uint32_t l_currentbanknumber_U32 = 0;
  uint32_t l_line_num_U32 = p_pin_U32;

  l_extracted_BOOL =
      dio_data_extract(&g_dio_pindata, l_line_num_U32, &l_currentbanknumber_U32,
                       &l_channel_number_U32);

  if (l_extracted_BOOL == true) {

    LOGI(&g_log_bspal_dio, "banknumber %d, channelnumber %d, for the pin  %d\n",
         l_currentbanknumber_U32, l_channel_number_U32, l_line_num_U32);

    if ((l_currentbanknumber_U32 == 5) &&
        ((l_channel_number_U32 == 0) || (l_channel_number_U32 == 1) ||
         (l_channel_number_U32 == 2) || (l_channel_number_U32 == 4) ||
         (l_channel_number_U32 == 7) || (l_channel_number_U32 == 17) ||
         (l_channel_number_U32 == 18))) {
      LOGW(&g_log_bspal_dio,
           "p_pin_U32 = %d, is used by kernel hence cannot be updated or "
           "queried \n",
           l_line_num_U32);
      l_ret_SINT = -1;
      goto end;
    } else if ((l_currentbanknumber_U32 == 1) && (l_channel_number_U32 == 6)) {
      LOGW(&g_log_bspal_dio,
           "p_pin_U32 = %d,is used by kernel hence cannot be updated or "
           "queried \n",
           l_line_num_U32);
      l_ret_SINT = -1;
      goto end;
    } else if ((l_currentbanknumber_U32 == 2) &&
               ((l_channel_number_U32 == 13) || (l_channel_number_U32 == 24))) {
      LOGW(&g_log_bspal_dio,
           "p_pin_U32 = %d, is used by kernel hence cannot be updated or "
           "queried \n",
           l_line_num_U32);
      l_ret_SINT = -1;
      goto end;
    } else if ((l_currentbanknumber_U32 == 3) &&
               ((l_channel_number_U32 == 12) || (l_channel_number_U32 == 13))) {
      LOGW(&g_log_bspal_dio,
           "p_pin_U32 = %d, is used by kernel hence cannot be updated or "
           "queried \n",
           l_line_num_U32);
      l_ret_SINT = -1;
      goto end;
    } else {
      l_ret_spf_SINT =
          snprintf(l_path_S8, PATH_LEN, GPIOCHIP_PATH, l_currentbanknumber_U32);
    LOGI(&g_log_bspal_dio, "dk_bspal_dio_set_value - chipname %s\n", l_path_S8);
    if (l_ret_spf_SINT < 0) {
      LOGE(&g_log_bspal_dio, "dk_bspal_dio_set_value - sprintf call failed\n");
      l_ret_SINT = -1;
      goto end;
    }
    chip = gpiod_chip_open_by_name(l_path_S8);
    if (!chip) {
      LOGE(&g_log_bspal_dio, "dk_bspal_dio_set_value - Open chip failed\n");
      l_ret_SINT = -1;
      goto end;
    }

      line = gpiod_chip_get_line(chip, l_channel_number_U32);

    if (!line) {
      LOGE(&g_log_bspal_dio, "dk_bspal_dio_set_value - Get line failed\n");
      l_ret_SINT = -1;
      goto close_chip;
    }

      l_ret_U32 = gpiod_line_request_output(line, CONSUMER, false, 0);

    if (l_ret_U32 < 0) {
      LOGE(&g_log_bspal_dio,
           "dk_bspal_dio_set_value - Request line as output failed\n");
      l_ret_SINT = -1;
      goto release_line;
    }

    l_ret_U32 = gpiod_line_set_value(line, p_value_BOOL);
    
    if (l_ret_U32 < 0) {
      LOGE(&g_log_bspal_dio,
           "dk_bspal_dio_set_value - Set line value output failed\n");
      l_ret_SINT = -1;
      goto release_line;
    } else {
      l_ret_SINT = 0;

      LOGI(&g_log_bspal_dio, "dk_bspal_dio_set_value - value set is =%d\n",
           p_value_BOOL);
    }
  }
release_line:
  gpiod_line_release(line);
close_chip:
  gpiod_chip_close(chip);
}
else {
  l_ret_SINT = -1;
  LOGW(&g_log_bspal_dio,
       "dk_bspal_dio_set_value - pin extraction from mask has issues.\n");
  goto end;
}
end : return l_ret_SINT;
}

/**********************************************************************************
  @brief API to get value of a DIO pin
  @param[in] p_pin_U32    The pin which value to be read.
  @param[in] p_value_BOOLP  pointer to the value to be read.

  @return Get value status.
 ***********************************************************************************/
int32_t dk_bspal_dio_get_value(const uint32_t p_pin_U32,
                               bool *const p_value_BOOLP) {
  int32_t l_ret_S32 = -1;
  int32_t l_val_S32 = -1;
  struct gpiod_chip *chip;
  struct gpiod_line *line;
  int32_t l_ret_spf_SINT = -1;
  char l_path_S8[PATH_LEN];
  int32_t l_ret_SINT = -1;
  bool l_extracted_BOOL = true;
  uint32_t l_channel_number_U32 = 0;
  uint32_t l_currentbanknumber_U32 = 0;
  uint32_t l_line_num_U32 = p_pin_U32;



    l_extracted_BOOL =
        dio_data_extract(&g_dio_pindata, l_line_num_U32,
                         &l_currentbanknumber_U32, &l_channel_number_U32);


  if (l_extracted_BOOL == true) {

      LOGW(&g_log_bspal_dio,
           "banknumber %d, channelnumber %d, for the pin  %d\n",
           l_currentbanknumber_U32, l_channel_number_U32, l_line_num_U32);

      if ((l_currentbanknumber_U32 == 5) &&
          ((l_channel_number_U32 == 0) || (l_channel_number_U32 == 1) ||
           (l_channel_number_U32 == 2) || (l_channel_number_U32 == 4) ||
           (l_channel_number_U32 == 7) || (l_channel_number_U32 == 17) ||
           (l_channel_number_U32 == 18))) {
        LOGW(&g_log_bspal_dio,
             "p_pin_U32 = %d, is used by kernel hence cannot be updated or "
             "queried \n",
             l_line_num_U32);
        l_ret_SINT = -1;
        goto end;
      } else if ((l_currentbanknumber_U32 == 1) &&
                 (l_channel_number_U32 == 6)) {
        LOGW(&g_log_bspal_dio,
             "p_pin_U32 = %d,is used by kernel hence cannot be updated or "
             "queried \n",
             l_line_num_U32);
        l_ret_SINT = -1;
        goto end;
      } else if ((l_currentbanknumber_U32 == 2) &&
                 ((l_channel_number_U32 == 13) ||
                  (l_channel_number_U32 == 24))) {
        LOGW(&g_log_bspal_dio,
             "p_pin_U32 = %d, is used by kernel hence cannot be updated or "
             "queried \n",
             l_line_num_U32);
        l_ret_SINT = -1;
        goto end;
      } else if ((l_currentbanknumber_U32 == 3) &&
                 ((l_channel_number_U32 == 12) ||
                  (l_channel_number_U32 == 13))) {
        LOGW(&g_log_bspal_dio,
             "p_pin_U32 = %d, is used by kernel hence cannot be updated or "
             "queried \n",
             l_line_num_U32);
        l_ret_SINT = -1;
        goto end;
      } else {

        l_ret_spf_SINT = snprintf(l_path_S8, PATH_LEN, GPIOCHIP_PATH,
                                  l_currentbanknumber_U32);

    LOGI(&g_log_bspal_dio, "dk_bspal_dio_get_value - chipname %s\n", l_path_S8);

    if (l_ret_spf_SINT < 0) {
      LOGE(&g_log_bspal_dio, "dk_bspal_dio_get_value -sprintf call failed\n");
      l_ret_SINT = -1;
      goto end;
    }
    chip = gpiod_chip_open_by_name(l_path_S8);
    if (!chip) {
      LOGE(&g_log_bspal_dio, "dk_bspal_dio_get_value- Open chip failed\n");
      l_ret_SINT = -1;
      goto end;
    }


    line = gpiod_chip_get_line(chip, l_channel_number_U32);

    if (!line) {
      LOGE(&g_log_bspal_dio, "dk_bspal_dio_get_value- Get line failed\n");
      l_ret_SINT = -1;
      goto close_chip;
    }

    l_ret_S32 = gpiod_line_request_input(line, CONSUMER, false);
	
    if (l_ret_S32 < 0) {
      LOGE(&g_log_bspal_dio,
           "dk_bspal_dio_get_value - Request line as input failed\n");
      l_ret_SINT = -1;
      goto release_line;
    }

    l_val_S32 = gpiod_line_get_value(line);
    if (l_val_S32 < 0) {
      LOGE(&g_log_bspal_dio, "dk_bspal_dio_get_value- get value failed\n");
      l_ret_SINT = -1;
      goto release_line;
    } else {
      l_ret_SINT = 0;
      *p_value_BOOLP = l_val_S32;
      LOGI(&g_log_bspal_dio, "dk_bspal_dio_get_value - get value",
           *p_value_BOOLP);
    }
  }

release_line:
  gpiod_line_release(line);
close_chip:
  gpiod_chip_close(chip);
}
else {
  l_ret_SINT = -1;
  LOGW(&g_log_bspal_dio,
       "dk_bspal_dio_get_value- pin extraction from mask has issues.\n");
  goto end;
}
end : return l_ret_SINT;
}

/**********************************************************************************
  @brief API to set direction of a DIO pin
  @param[in] p_pin_U32    the pin which direction to be set.
  @param[in] p_direction_te  the direction to be set.

  @return set direction status.
 ***********************************************************************************/
int32_t dk_bspal_dio_set_direction(const uint32_t p_pin_U32,
                                   const EDirection p_direction_te) {

  struct gpiod_chip *chip;
  struct gpiod_line *line;
  int32_t l_ret_S32 = -1;
  int32_t l_ret_spf_SINT = -1;
  char l_path_S8[PATH_LEN];
  int32_t l_ret_SINT = -1;
  bool l_extracted_BOOL = true;

  uint32_t l_channel_number_U32 = 0;
  uint32_t l_currentbanknumber_U32 = 0;
  uint32_t l_line_num_U32 = p_pin_U32;


      l_extracted_BOOL =
          dio_data_extract(&g_dio_pindata, l_line_num_U32,
                           &l_currentbanknumber_U32, &l_channel_number_U32);

  if (l_extracted_BOOL == true) {

        LOGI(&g_log_bspal_dio,
             "banknumber %d, channelnumber %d, for the pin  %d\n",
             l_currentbanknumber_U32, l_channel_number_U32, l_line_num_U32);
        if ((l_currentbanknumber_U32 == 5) &&
            ((l_channel_number_U32 == 0) || (l_channel_number_U32 == 1) ||
             (l_channel_number_U32 == 2) || (l_channel_number_U32 == 4) ||
             (l_channel_number_U32 == 7) || (l_channel_number_U32 == 17) ||
             (l_channel_number_U32 == 18))) {
          LOGW(&g_log_bspal_dio,
               "p_pin_U32 = %d, is used by kernel hence cannot be updated or "
               "queried \n",
               l_line_num_U32);
          l_ret_SINT = -1;
          goto end;
        } else if ((l_currentbanknumber_U32 == 1) &&
                   (l_channel_number_U32 == 6)) {
          LOGW(&g_log_bspal_dio,
               "p_pin_U32 = %d,is used by kernel hence cannot be updated or "
               "queried \n",
               l_line_num_U32);
          l_ret_SINT = -1;
          goto end;
        } else if ((l_currentbanknumber_U32 == 2) &&
                   ((l_channel_number_U32 == 13) ||
                    (l_channel_number_U32 == 24))) {
          LOGW(&g_log_bspal_dio,
               "p_pin_U32 = %d, is used by kernel hence cannot be updated or "
               "queried \n",
               l_line_num_U32);
          l_ret_SINT = -1;
          goto end;
        } else if ((l_currentbanknumber_U32 == 3) &&
                   ((l_channel_number_U32 == 12) ||
                    (l_channel_number_U32 == 13))) {
          LOGW(&g_log_bspal_dio,
               "p_pin_U32 = %d, is used by kernel hence cannot be updated or "
               "queried \n",
               l_line_num_U32);
          l_ret_SINT = -1;
          goto end;
        } else {

          l_ret_spf_SINT = snprintf(l_path_S8, PATH_LEN, GPIOCHIP_PATH,
                                    l_currentbanknumber_U32);
    LOGI(&g_log_bspal_dio, "dk_bspal_dio_set_direction- chipname %s\n",
         l_path_S8);

    if (l_ret_spf_SINT < 0) {
      LOGE(&g_log_bspal_dio,
           "dk_bspal_dio_set_direction- sprintf call failed\n");
      l_ret_SINT = -1;
      goto end;
    }

    chip = gpiod_chip_open_by_name(l_path_S8);
    if (!chip) {
      LOGE(&g_log_bspal_dio, "dk_bspal_dio_set_direction- Open chip failed\n");
      l_ret_SINT = -1;
      goto end;
    }

      line = gpiod_chip_get_line(chip, l_channel_number_U32);


    if (!line) {
      LOGE(&g_log_bspal_dio, "dk_bspal_dio_set_direction- Get line failed\n");
      l_ret_SINT = -1;
      goto close_chip;
    }

    if (p_direction_te == 0) // user requested direction request is  input
    {
      LOGI(&g_log_bspal_dio,
           "dk_bspal_dio_set_direction- user requested direction is input\n");

      l_ret_S32 = gpiod_line_request_input(line, CONSUMER, false);

      if (l_ret_S32 < 0) {
        LOGE(&g_log_bspal_dio,
             "dk_bspal_dio_set_direction - Request line as input failed\n");
        l_ret_SINT = -1;
        goto release_line;

      } else {
        l_ret_SINT = 0;
        LOGI(&g_log_bspal_dio,
             "dk_bspal_dio_set_direction - Direction set is = INPUT!!\n");
      }

    } else // direction requested is  output
    {
      LOGI(&g_log_bspal_dio,
           "dk_bspal_dio_set_direction - user requested direction is output\n");


      l_ret_S32 = gpiod_line_request_output(line, CONSUMER, false, 0);

      if (l_ret_S32 < 0) {
        LOGE(&g_log_bspal_dio,
             "dk_bspal_dio_set_direction - Request line as output failed\n");
        l_ret_SINT = -1;
        goto release_line;
      } else {
        l_ret_SINT = 0;
        LOGI(&g_log_bspal_dio,
             "dk_bspal_dio_set_direction - Direction set is = OUTPUT!!\n");
      }
    }
  }

release_line:
  gpiod_line_release(line);
close_chip:
  gpiod_chip_close(chip);
}
else {
  l_ret_SINT = -1;
  LOGW(&g_log_bspal_dio,
       "dk_bspal_dio_set_direction - pin extraction from mask has issues.\n");
  goto end;
}
end : return l_ret_SINT;
}

/**********************************************************************************
  @brief API to READ direction of a DIO pin
  @param[in] p_pin_U32    the pin which direction to be set.
  @param[in] p_direction_TEP  pointer to store the direction to be read

  @return get direction status.
 ***********************************************************************************/
int32_t dk_bspal_dio_get_direction(const uint32_t p_pin_U32,
                                   EDirection *const p_direction_TEP) {
  uint32_t l_direction_U32;
  struct gpiod_chip *chip;
  struct gpiod_line *line;
  int32_t l_ret_spf_SINT = -1;
  char l_path_S8[PATH_LEN];
  int32_t l_ret_SINT = -1;
  bool l_extracted_BOOL = true;

        uint32_t l_channel_number_U32 = 0;
        uint32_t l_currentbanknumber_U32 = 0;
        uint32_t l_line_num_U32 = p_pin_U32;
        l_extracted_BOOL =
            dio_data_extract(&g_dio_pindata, l_line_num_U32,
                             &l_currentbanknumber_U32, &l_channel_number_U32);

  if (l_extracted_BOOL == true) {



          LOGI(&g_log_bspal_dio,
               "banknumber %d, channelnumber %d, for the pin  %d\n",
               l_currentbanknumber_U32, l_channel_number_U32, l_line_num_U32);

          if ((l_currentbanknumber_U32 == 5) &&
              ((l_channel_number_U32 == 0) || (l_channel_number_U32 == 1) ||
               (l_channel_number_U32 == 2) || (l_channel_number_U32 == 4) ||
               (l_channel_number_U32 == 7) || (l_channel_number_U32 == 17) ||
               (l_channel_number_U32 == 18))) {
            LOGW(&g_log_bspal_dio,
                 "p_pin_U32 = %d, is used by kernel hence cannot be updated or "
                 "queried \n",
                 l_line_num_U32);
            l_ret_SINT = -1;
            goto end;
          } else if ((l_currentbanknumber_U32 == 1) &&
                     (l_channel_number_U32 == 6)) {
            LOGW(&g_log_bspal_dio,
                 "p_pin_U32 = %d,is used by kernel hence cannot be updated or "
                 "queried \n",
                 l_line_num_U32);
            l_ret_SINT = -1;
            goto end;
          } else if ((l_currentbanknumber_U32 == 2) &&
                     ((l_channel_number_U32 == 13) ||
                      (l_channel_number_U32 == 24))) {
            LOGW(&g_log_bspal_dio,
                 "p_pin_U32 = %d, is used by kernel hence cannot be updated or "
                 "queried \n",
                 l_line_num_U32);
            l_ret_SINT = -1;
            goto end;
          } else if ((l_currentbanknumber_U32 == 3) &&
                     ((l_channel_number_U32 == 12) ||
                      (l_channel_number_U32 == 13))) {
            LOGW(&g_log_bspal_dio,
                 "p_pin_U32 = %d, is used by kernel hence cannot be updated or "
                 "queried \n",
                 l_line_num_U32);
            l_ret_SINT = -1;
            goto end;
          } else {
            l_ret_spf_SINT = snprintf(l_path_S8, PATH_LEN, GPIOCHIP_PATH,
                                      l_currentbanknumber_U32);


    LOGI(&g_log_bspal_dio, "dk_bspal_dio_get_direction - gpio chipname %s\n",
         l_path_S8);

    if (l_ret_spf_SINT < 0) {
      LOGE(&g_log_bspal_dio,
           " dk_bspal_dio_get_direction - sprintf call failed\n");
      l_ret_SINT = -1;
      goto end;
    }

    chip = gpiod_chip_open_by_name(l_path_S8);
    if (!chip) {
      LOGE(&g_log_bspal_dio,
           "dk_bspal_dio_get_direction - gpio chip open  failed\n");
      l_ret_SINT = -1;
      goto end;
    }

    line = gpiod_chip_get_line(chip, l_channel_number_U32);

    if (!line) {
      LOGE(&g_log_bspal_dio,
           "dk_bspal_dio_get_direction- gpio chip get line Get line failed\n");
      l_ret_SINT = -1;
      goto close_chip;
    } else {
      l_direction_U32 = gpiod_line_direction(line);

      *p_direction_TEP = l_direction_U32;
      l_ret_SINT = 0;
      if (l_direction_U32 == 1) {
        LOGI(&g_log_bspal_dio, " dk_bspal_dio_get_direction - Got line "
                               "direction is = INPUT,mapped it to "
                               "our enum direction \n");
        *p_direction_TEP = l_direction_U32;
        goto release_line;
      }
      if (l_direction_U32 == 2) {
        LOGI(&g_log_bspal_dio, " dk_bspal_dio_get_direction - Got line "
                               "direction is = OUTPUT,mapped it to "
                               "our enum direction\n");
        *p_direction_TEP = l_direction_U32;
        goto release_line;
      }
    }
  }

release_line:
  gpiod_line_release(line);
close_chip:
  gpiod_chip_close(chip);
}
else {
  l_ret_SINT = -1;
  LOGE(&g_log_bspal_dio,
       "dk_bspal_dio_get_direction - pin extraction from mask has issues.\n");
  goto end;
}
end : return l_ret_SINT;
}

#endif //EINSTEIN_TI_DIO

/***************************************************** End of File
 * *****************************************************************************/

/*--------------------------------------------------------------------------------------------------------------------
   REVISION HISTORY
 ---------------------------------------------------------------------------------------------------------------------
 Date               : 09-07-2024
 By                 : dpanneer
 Trace-ability      : GIT#
 Change Description : Initial Version for Linux
 @version
 07FEB2025   | PKRISH12 |  TFDCX32348-66086 | Implemeted Ioctl based gpio set and get functions for Toyota project.  
 --------------------------------------------------------------------------------------------------------------------*/
