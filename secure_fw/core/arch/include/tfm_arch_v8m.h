/*
 * Copyright (c) 2018-2019, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
#ifndef __TFM_ARCH_V8M_H__
#define __TFM_ARCH_V8M_H__

#include <stdint.h>
#include <stdbool.h>

#include "cmsis_compiler.h"

#define EXC_RETURN_INDICATOR                    (0xF << 28)
#define EXC_RETURN_SECURITY_STACK_STATUS_MASK   (0x3 << 5)
#define EXC_RETURN_SECURE_STACK                 (1 << 6)
#define EXC_RETURN_FPU_FRAME_BASIC              (1 << 4)
#define EXC_RETURN_MODE_THREAD                  (1 << 3)
#define EXC_RETURN_STACK_PROCESS                (1 << 2)
#define EXC_RETURN_EXC_SECURE                   (1)

/* Initial EXC_RETURN value in LR when a thread is loaded at the first time */
#define INIT_LR_UNPRIVILEGED                    0xFFFFFFFD

#ifdef __ARM_ARCH_8M_MAIN__
struct tfm_state_context_ext {
    uint32_t    r4;
    uint32_t    r5;
    uint32_t    r6;
    uint32_t    r7;
    uint32_t    r8;
    uint32_t    r9;
    uint32_t    r10;
    uint32_t    r11;
    uint32_t    sp;
    uint32_t    sp_limit;
    uint32_t    dummy;
    uint32_t    lr;
};
#elif defined(__ARM_ARCH_8M_BASE__)
struct tfm_state_context_ext {
    uint32_t    r8;
    uint32_t    r9;
    uint32_t    r10;
    uint32_t    r11;
    uint32_t    r4;
    uint32_t    r5;
    uint32_t    r6;
    uint32_t    r7;
    uint32_t    sp;
    uint32_t    sp_limit;
    uint32_t    dummy;
    uint32_t    lr;
};
#endif

/* Disable NS exceptions by setting NS PRIMASK to 1 */
#define TFM_NS_EXC_DISABLE()    __TZ_set_PRIMASK_NS(1)
/* Enable NS exceptions by setting NS PRIMASK to 0 */
#define TFM_NS_EXC_ENABLE()     __TZ_set_PRIMASK_NS(0)

#endif
