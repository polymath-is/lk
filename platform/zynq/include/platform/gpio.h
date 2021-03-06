/*
 * Copyright (c) 2015 Christopher Anderson
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT
 */
#pragma once

#include <platform/interrupts.h>
#include <platform/zynq.h>

/* GPIO registers are not indexed in a particularly convenient manner, but can be calculated
 * via the GPIO bank */

#define GPIO_MASK_DATA_BASE         (GPIO_BASE + 0x0)
#define GPIO_MASK_DATA_LSW(bank)    (GPIO_MASK_DATA_BASE + (8 * bank))
#define GPIO_MASK_DATA_MSW(bank)    (GPIO_MASK_DATA_BASE + 4 + (8 * bank))

#define GPIO_DATA_BASE              (GPIO_BASE + 0x40)
#define GPIO_DATA(bank)             (GPIO_DATA_BASE + (4 * bank))

#define GPIO_DATA_RO_BASE           (GPIO_BASE + 0x60)
#define GPIO_DATA_RO(bank)          (GPIO_DATA_RO_BASE + (4 * bank))

#define GPIO_REGS(bank)             (GPIO_BASE + 0x204 + (0x40 * bank))
#define GPIO_DIRM(bank)             (GPIO_REGS(bank) + 0x0)
#define GPIO_OEN(bank)              (GPIO_REGS(bank) + 0x4)
#define GPIO_INT_MASK(bank)         (GPIO_REGS(bank) + 0x8)
#define GPIO_INT_EN(bank)           (GPIO_REGS(bank) + 0xC)
#define GPIO_INT_DIS(bank)          (GPIO_REGS(bank) + 0x10)
#define GPIO_INT_STAT(bank)         (GPIO_REGS(bank) + 0x14)
#define GPIO_INT_TYPE(bank)         (GPIO_REGS(bank) + 0x18)
#define GPIO_INT_POLARITY(bank)     (GPIO_REGS(bank) + 0x1C)
#define GPIO_INT_ANY(bank)          (GPIO_REGS(bank) + 0x20)

void zynq_unmask_gpio_interrupt(unsigned gpio);
void zynq_mask_gpio_interrupt(unsigned gpio);
void zynq_gpio_init(void);
void zynq_gpio_early_init(void);
void register_gpio_int_handler(unsigned gpio, int_handler handler, void *args);
void unregister_gpio_int_handler(unsigned gpio);
