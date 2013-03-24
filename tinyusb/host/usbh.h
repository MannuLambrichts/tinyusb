/*
 * usbh.h
 *
 *  Created on: Jan 19, 2013
 *      Author: hathach
 */

/*
 * Software License Agreement (BSD License)
 * Copyright (c) 2013, hathach (tinyusb.net)
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
 * SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 *
 * This file is part of the tiny usb stack.
 */

/** \file
 *  \brief TBD
 *
 *  \note TBD
 */

/** \ingroup TBD
 *  \defgroup TBD
 *  \brief TBD
 *
 *  @{
 */

#ifndef _TUSB_USBD_HOST_H_
#define _TUSB_USBD_HOST_H_

#ifdef __cplusplus
 extern "C" {
#endif

//--------------------------------------------------------------------+
// INCLUDE
//--------------------------------------------------------------------+
#include "hcd.h"

//--------------------------------------------------------------------+
// MACRO CONSTANT TYPEDEF
//--------------------------------------------------------------------+
typedef enum pipe_status_{
  PIPE_STATUS_READY = 0,
  PIPE_STATUS_BUSY,
  PIPE_STATUS_COMPLETE,
  PIPE_STATUS_ERROR
} pipe_status_t;

typedef uint32_t tusbh_flag_class_t;

typedef struct {
  void (* const init) (void);
  tusb_error_t (* const open_subtask)(uint8_t, uint8_t const *, uint16_t*);
  void (* const isr) (pipe_handle_t, tusb_bus_event_t);
  void (* const close) (uint8_t);
} host_class_driver_t;
//--------------------------------------------------------------------+
// INTERNAL OBJECT & FUNCTION DECLARATION
//--------------------------------------------------------------------+

//--------------------------------------------------------------------+
// APPLICATION API
//--------------------------------------------------------------------+
tusb_error_t tusbh_configuration_set     (uint8_t dev_addr, uint8_t configure_number) ATTR_WARN_UNUSED_RESULT;
tusb_device_state_t tusbh_device_get_state (uint8_t const dev_addr) ATTR_WARN_UNUSED_RESULT;

//--------------------------------------------------------------------+
// APPLICATION CALLBACK
//--------------------------------------------------------------------+
uint8_t      tusbh_device_attached_cb (tusb_descriptor_device_t const *p_desc_device) ATTR_WEAK ATTR_WARN_UNUSED_RESULT;
void         tusbh_device_mount_succeed_cb (uint8_t dev_addr) ATTR_WEAK;
void         tusbh_device_mount_failed_cb(tusb_error_t error, tusb_descriptor_device_t const *p_desc_device) ATTR_WEAK; // TODO refractor remove desc_device


#if TUSB_CFG_OS == TUSB_OS_NONE // TODO move later
//static inline void tusb_tick_tock(void) ATTR_ALWAYS_INLINE;
//static inline void tusb_tick_tock(void)
//{
//  osal_tick_tock();
//}
#endif

//--------------------------------------------------------------------+
// CLASS-USBD API
//--------------------------------------------------------------------+
#ifdef _TINY_USB_SOURCE_FILE_

tusb_error_t usbh_init(void);
pipe_status_t usbh_pipe_status_get(pipe_handle_t pipe_hdl) ATTR_WARN_UNUSED_RESULT;

#endif

#ifdef __cplusplus
 }
#endif

#endif /* _TUSB_USBD_HOST_H_ */

/** @} */
