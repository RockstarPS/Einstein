/*****************************************************************************/
/* Copyright Statement                                                       */
/* CONFIDENTIAL - VISTEON CORPORATION                                        */
/* This is an unpublished work, which contains trade secrets, created in     */
/* 2008. Visteon Corporation owns all rights to this work and intends        */
/* to maintain it in confidence to preserve its trade secret status. Visteon */
/* Corporation reserves the right, under the copyright laws of the United    */
/* States or those of any other country that may have jurisdiction, to       */
/* protect this work as an unpublished copyright work in the event of an     */
/* inadvertent or deliberate unauthorized publication. Visteon Corporation   */
/* also reserves its rights under the copyright laws to protect this work    */
/* as a published work, when appropriate. Those having access to this work   */
/* may not copy it, use it or disclose the information contained in it       */
/* without the written authorization of Visteon Corporation.                 */
/*****************************************************************************/

/***************************************************************************

  Module:               vmf_app_util.h
  Description:         	mf_app util functions 
  Project Scope:        leopard-e

  Organization:         Visteon Deutschland GmbH, Infotainment Software
  Author:               Joachim Becker

  Compiler/Assembler:   iar
  Target Hardware:      leopard-e

  *****************************************************************************/
  
  
#include "os_if.h"
#include "mqx_osal_if.h"

#include <mfs.h>
#include <mqx_inc.h>
#include <charq.h>
#include <stdlib.h>
#include <tad.h>

#include "vmf_app_util.h"

/*!
 * wrapper for _tad_lightweight_memory_blocks 
 */ 
void vmf_util_tad_lightweight_memory_blocks(void) 
{
	//_tad_lightweight_memory_blocks ();
}

/*!
 * Prints stacks usage. 
 * the original is ugly - so this version was created
 */ 
void vmf_util_tad_stack_usage(void) 
{
#if MQX_MONITOR_STACK && MQX_TD_HAS_STACK_LIMIT
   _mqx_uint_ptr            stack_used, stack_limit;
   _mqx_int                 percent, size;
   TD_STRUCT_PTR            td_ptr;
   TASK_TEMPLATE_STRUCT_PTR template_ptr;
   KERNEL_DATA_STRUCT_PTR   kernel_data_ptr = _mqx_get_kernel_data ();
   char_ptr                 task_name;
   unsigned32 				used_b=0;
   unsigned32 				size_b=0;
   char						ch_overflow[]={"No  "};  /* YES or NO */

   
   
   printf ("\nStack Usage:\n");
   printf ("%20s  Stack-Base   Stack-size  Stack-used   %%Used   Overflow?\n","Task");


   size = _QUEUE_GET_SIZE(&kernel_data_ptr->TD_LIST);
   td_ptr = (TD_STRUCT_PTR)((uchar_ptr)kernel_data_ptr->TD_LIST.NEXT - FIELD_OFFSET(TD_STRUCT,TD_LIST_INFO));
   while ((0 != size) && (NULL != td_ptr))
   {
  #if MQX_TD_HAS_TASK_TEMPLATE_PTR
      template_ptr = td_ptr->TASK_TEMPLATE_PTR;
      task_name = template_ptr->TASK_NAME;
  #else
      char  name[12];
      sprintf(name, "0x%x", td_ptr->TASK_ID);
      task_name = name;
  #endif        
      stack_used = td_ptr->STACK_LIMIT;
      stack_used++;
      while (*stack_used == 0x7374616B) 
      {
         stack_used++;
      }
      if ((stack_used == td_ptr->STACK_LIMIT) || (stack_used == (_mqx_uint_ptr)td_ptr->STACK_LIMIT + 1)) 
      {
         percent=100;
      }
      else 
      {
		 percent = ((_mqx_uint_ptr)td_ptr->STACK_BASE - stack_used) * 100 / ((_mqx_uint_ptr)td_ptr->STACK_BASE - (_mqx_uint_ptr)td_ptr->STACK_LIMIT);
      }
	  used_b = ((_mqx_uint_ptr)td_ptr->STACK_BASE - stack_used) * sizeof(void*);
	  size_b = ((_mqx_uint_ptr)td_ptr->STACK_BASE - (_mqx_uint_ptr)td_ptr->STACK_LIMIT) * sizeof(void*);
      printf ("%20s  0x%lx   %5ldbyte   %5ldbyte   %3ld%%     %s\n", task_name, td_ptr->STACK_BASE, size_b, used_b, percent,percent>=100?"Yes":"No");
        
      size--;
      td_ptr = (TD_STRUCT_PTR)((uchar_ptr)(td_ptr->TD_LIST_INFO.NEXT) - FIELD_OFFSET(TD_STRUCT,TD_LIST_INFO));
   }
    
   stack_used = stack_limit = (_mqx_uint_ptr)(((_mqx_uint)(kernel_data_ptr->INTERRUPT_STACK_PTR)) - kernel_data_ptr->INIT.INTERRUPT_STACK_SIZE);
   stack_used++;
   while (*stack_used == 0x7374616B) 
   {
      stack_used++;
   }
   used_b = ((_mqx_uint_ptr)kernel_data_ptr->INTERRUPT_STACK_PTR - stack_used) * sizeof(void *);
   size_b = ((_mqx_uint_ptr)kernel_data_ptr->INTERRUPT_STACK_PTR - stack_limit) * sizeof(void *);

   if ((stack_used == td_ptr->STACK_LIMIT) || (stack_used == (_mqx_uint_ptr)td_ptr->STACK_LIMIT + 1)) 
   {
	  snprintf(ch_overflow,sizeof(ch_overflow),"Yes");
   }
   else 
   {
      percent = ((_mqx_uint_ptr)kernel_data_ptr->INTERRUPT_STACK_PTR - stack_used) * 100 / ((_mqx_uint_ptr)kernel_data_ptr->INTERRUPT_STACK_PTR - stack_limit);
   }
    printf ("%20s  0x%lx   %5ldbyte   %5ldbyte   %3ld%%     %s\n\n", "interrupt",kernel_data_ptr->INTERRUPT_STACK_PTR, size_b, used_b, percent,ch_overflow);

#endif
}

/*************************************************************************//**
 *
 *   hex_dump
 *   NOTE: hex dump a buffer
 *   
 *
 *   \param[in] unsigned8 *     - pointer to bufer  
 *   \param[in] len             - length of bufer   
 *   \return    void 
 *
 ******************************************************************************/
void nw_con_HexDump(char * name,unsigned8 *buffer,int len)
{
#define CPL 16
    static  BOOL b_in_use = FALSE;
    int     i,j, ct;
    char    asci[2*CPL+1];

    if (buffer == NULL)
    {
        fprintf(ERROR_CHANNEL,"nw_con_HexDump - buffer == NULL\n");
        return;
    }

    while (b_in_use)
    {
        delay(1);
    }
    b_in_use = TRUE;


    if (len <= 0) 
    {
        b_in_use = TRUE;
        return;
    }

    fprintf(ERROR_CHANNEL,"%s\n",name);
    for (i=0,j=0; i<len; ++i) 
    {
        asci[j]='.';
        asci[j+1]=0;

        ct = (int)buffer[i];
        fprintf(ERROR_CHANNEL,"%02x ", ct);
        if ((ct > 0x1f) && (ct < 0x7f))
        {
            asci[j]=ct;
        }

        if ((((i+1) % CPL) == 0))
        {
            fprintf(ERROR_CHANNEL,"    %s\n",asci);
            asci[0]=0;
            j=0;
        }
        else
        {
            j+=1;
        }
    }
    for (; j<CPL; ++j) 
    {
        fprintf(ERROR_CHANNEL,"   ");
    }

    fprintf(ERROR_CHANNEL,"    %s\n\n",asci);
    b_in_use = FALSE;
}


