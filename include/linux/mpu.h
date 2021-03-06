/*
 $License:
    Copyright (C) 2010 InvenSense Corporation, All Rights Reserved.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
  $
 */

#ifndef __MPU_H_
#define __MPU_H_

#ifdef __KERNEL__
#include <linux/types.h>
#endif

#ifdef M_HW
#include "mpu6000.h"
#else
#include "mpu3050.h"
#endif

#define GYRO_NUM_AXES               (3)
#define ACCEL_NUM_AXES              (3)
#define COMPASS_NUM_AXES            (3)

#define MPU_SET_MPU_CONFIG          (0x00)
#define MPU_SET_INT_CONFIG          (0x01)
#define MPU_SET_EXT_SYNC            (0x02)
#define MPU_SET_FULL_SCALE          (0x03)
#define MPU_SET_LPF                 (0x04)
#define MPU_SET_CLK_SRC             (0x05)
#define MPU_SET_DIVIDER             (0x06)
#define MPU_SET_LEVEL_SHIFTER       (0x07)
#define MPU_SET_DMP_ENABLE          (0x08)
#define MPU_SET_FIFO_ENABLE         (0x09)
#define MPU_SET_DMP_CFG1            (0x0a)
#define MPU_SET_DMP_CFG2            (0x0b)
#define MPU_SET_OFFSET_TC           (0x0c)
#define MPU_SET_RAM                 (0x0d)

#define MPU_SET_PLATFORM_DATA       (0x0e)

#define MPU_GET_MPU_CONFIG          (0x80)
#define MPU_GET_INT_CONFIG          (0x81)
#define MPU_GET_EXT_SYNC            (0x82)
#define MPU_GET_FULL_SCALE          (0x83)
#define MPU_GET_LPF                 (0x84)
#define MPU_GET_CLK_SRC             (0x85)
#define MPU_GET_DIVIDER             (0x86)
#define MPU_GET_LEVEL_SHIFTER       (0x87)
#define MPU_GET_DMP_ENABLE          (0x88)
#define MPU_GET_FIFO_ENABLE         (0x89)
#define MPU_GET_DMP_CFG1            (0x8a)
#define MPU_GET_DMP_CFG2            (0x8b)
#define MPU_GET_OFFSET_TC           (0x8c)
#define MPU_GET_RAM                 (0x8d)

#define MPU_READ_REGISTER           (0x40)
#define MPU_WRITE_REGISTER          (0x41)
#define MPU_READ_MEMORY             (0x42)
#define MPU_WRITE_MEMORY            (0x43)

#define MPU_SUSPEND                 (0x44)
#define MPU_RESUME                  (0x45)
#define MPU_READ_COMPASS            (0x46)
#define MPU_READ_ACCEL              (0x47)
#define MPU_READ_PRESSURE           (0x48)

#define MPU_CONFIG_ACCEL            (0x20)
#define MPU_CONFIG_COMPASS          (0x21)
#define MPU_CONFIG_PRESSURE         (0x22)

#define MPU_GET_CONFIG_ACCEL        (0x28)
#define MPU_GET_CONFIG_COMPASS      (0x29)
#define MPU_GET_CONFIG_PRESSURE     (0x2a)

#define HTC_READ_CAL_DATA
#ifdef HTC_READ_CAL_DATA
#define MPU_READ_CAL_DATA           (0xef)
extern unsigned char gyro_gsensor_kvalue[37];
#endif

struct mpu_read_write {
	unsigned short address;
	unsigned short length;
	unsigned char *data;
};

struct mpuirq_data {
	int interruptcount;
	unsigned long long irqtime;
	int data_type;
	int data_size;
	void *data;
};
enum ext_slave_config_key {
	MPU_SLAVE_CONFIG_ODR_SUSPEND,
	MPU_SLAVE_CONFIG_ODR_RESUME,
	MPU_SLAVE_CONFIG_FSR_SUSPEND,
	MPU_SLAVE_CONFIG_FSR_RESUME,
	MPU_SLAVE_CONFIG_MOT_THS,
	MPU_SLAVE_CONFIG_NMOT_THS,
	MPU_SLAVE_CONFIG_MOT_DUR,
	MPU_SLAVE_CONFIG_NMOT_DUR,
	MPU_SLAVE_CONFIG_IRQ_SUSPEND,
	MPU_SLAVE_CONFIG_IRQ_RESUME,
	MPU_SLAVE_WRITE_REGISTERS,
	MPU_SLAVE_READ_REGISTERS,
	MPU_SLAVE_CONFIG_NUM_CONFIG_KEYS,
};

enum ext_slave_config_irq_type {
	MPU_SLAVE_IRQ_TYPE_NONE,
	MPU_SLAVE_IRQ_TYPE_MOTION,
	MPU_SLAVE_IRQ_TYPE_DATA_READY,
};

struct ext_slave_config {
	int key;
	int len;
	int apply;
	void *data;
};

enum ext_slave_type {
	EXT_SLAVE_TYPE_GYROSCOPE,
	EXT_SLAVE_TYPE_ACCELEROMETER,
	EXT_SLAVE_TYPE_COMPASS,
	EXT_SLAVE_TYPE_PRESSURE,
	
};

enum ext_slave_id {
	ID_INVALID = 0,

	ACCEL_ID_LIS331,
	ACCEL_ID_LSM303,
	ACCEL_ID_KXSD9,
	ACCEL_ID_KXTF9,
	ACCEL_ID_BMA150,
	ACCEL_ID_BMA222,
	ACCEL_ID_ADI346,
	ACCEL_ID_MMA8450,
	ACCEL_ID_MMA845X,
	ACCEL_ID_MPU6000,
    ACCEL_ID_LIS3DH,

	COMPASS_ID_AKM,
	COMPASS_ID_AKM8963,
	COMPASS_ID_AMI30X,
	COMPASS_ID_YAS529,
	COMPASS_ID_HMC5883,
	COMPASS_ID_LSM303,
	COMPASS_ID_MMC314X,
	COMPASS_ID_HSCDTD002B,
	COMPASS_ID_HSCDTD004A,

	PRESSURE_ID_BMA085,
	ACCEL_ID_BMA250,
};

enum ext_slave_endian {
	EXT_SLAVE_BIG_ENDIAN,
	EXT_SLAVE_LITTLE_ENDIAN,
	EXT_SLAVE_FS8_BIG_ENDIAN,
	EXT_SLAVE_FS16_BIG_ENDIAN,
};

enum ext_slave_bus {
	EXT_SLAVE_BUS_INVALID = -1,
	EXT_SLAVE_BUS_PRIMARY = 0,
	EXT_SLAVE_BUS_SECONDARY = 1
};


struct ext_slave_platform_data {
	struct ext_slave_descr *(*get_slave_descr) (void);
	int irq;
	int adapt_num;
	int bus;
	unsigned char address;
	signed char orientation[9];
	void *irq_data;
	void *private_data;
};


struct tFixPntRange {
	long mantissa;
	long fraction;
};

struct ext_slave_descr {
	int (*init) (void *mlsl_handle,
		     struct ext_slave_descr *slave,
#ifdef CONFIG_M7_CIR_ALWAYS
		     struct ext_slave_platform_data *pdata,
		     int (*power_LPM)(int on)
		     );
#else
		     struct ext_slave_platform_data *pdata);
#endif

	int (*exit) (void *mlsl_handle,
		     struct ext_slave_descr *slave,
		     struct ext_slave_platform_data *pdata);
	int (*suspend) (void *mlsl_handle,
			struct ext_slave_descr *slave,
			struct ext_slave_platform_data *pdata);
	int (*resume) (void *mlsl_handle,
		       struct ext_slave_descr *slave,
		       struct ext_slave_platform_data *pdata);
	int (*read) (void *mlsl_handle,
		     struct ext_slave_descr *slave,
		     struct ext_slave_platform_data *pdata,
		     unsigned char *data);
	int (*config) (void *mlsl_handle,
		       struct ext_slave_descr *slave,
		       struct ext_slave_platform_data *pdata,
		       struct ext_slave_config *config);
	int (*get_config) (void *mlsl_handle,
			   struct ext_slave_descr *slave,
			   struct ext_slave_platform_data *pdata,
			   struct ext_slave_config *config);

	char *name;
	unsigned char type;
	unsigned char id;
	unsigned char reg;
	unsigned int len;
	unsigned char endian;
	struct tFixPntRange range;
};

struct mpu3050_platform_data {
	unsigned char int_config;
	signed char orientation[MPU_NUM_AXES * MPU_NUM_AXES];
	unsigned char level_shifter;
	struct ext_slave_platform_data accel;
	struct ext_slave_platform_data compass;
	struct ext_slave_platform_data pressure;
	int (*g_sensors_reset)(void);
	int (*power_LPM)(int on);
};


#define get_accel_slave_descr NULL

#ifdef CONFIG_MPU_SENSORS_ADXL346	
struct ext_slave_descr *adxl346_get_slave_descr(void);
#undef get_accel_slave_descr
#define get_accel_slave_descr adxl346_get_slave_descr
#endif

#ifdef CONFIG_MPU_SENSORS_BMA150	
struct ext_slave_descr *bma150_get_slave_descr(void);
#undef get_accel_slave_descr
#define get_accel_slave_descr bma150_get_slave_descr
#endif

#ifdef CONFIG_MPU_SENSORS_BMA250	
struct ext_slave_descr *bma250_get_slave_descr(void);
#undef get_accel_slave_descr
#define get_accel_slave_descr bma250_get_slave_descr
#endif

#ifdef CONFIG_MPU_SENSORS_BMA222	
struct ext_slave_descr *bma222_get_slave_descr(void);
#undef get_accel_slave_descr
#define get_accel_slave_descr bma222_get_slave_descr
#endif

#ifdef CONFIG_MPU_SENSORS_KXSD9	
struct ext_slave_descr *kxsd9_get_slave_descr(void);
#undef get_accel_slave_descr
#define get_accel_slave_descr kxsd9_get_slave_descr
#endif

#ifdef CONFIG_MPU_SENSORS_KXTF9	
struct ext_slave_descr *kxtf9_get_slave_descr(void);
#undef get_accel_slave_descr
#define get_accel_slave_descr kxtf9_get_slave_descr
#endif

#ifdef CONFIG_MPU_SENSORS_LIS331DLH	
struct ext_slave_descr *lis331dlh_get_slave_descr(void);
#undef get_accel_slave_descr
#define get_accel_slave_descr lis331dlh_get_slave_descr
#endif


#ifdef CONFIG_MPU_SENSORS_LIS3DH	
struct ext_slave_descr *lis3dh_get_slave_descr(void);
#undef get_accel_slave_descr
#define get_accel_slave_descr lis3dh_get_slave_descr
#endif

#ifdef CONFIG_MPU_SENSORS_LSM303DLHA	
struct ext_slave_descr *lsm303dlha_get_slave_descr(void);
#undef get_accel_slave_descr
#define get_accel_slave_descr lsm303dlha_get_slave_descr
#endif

#if defined(CONFIG_MPU_SENSORS_MPU6000) || \
    defined(CONFIG_MPU_SENSORS_MPU6000_MODULE)
struct ext_slave_descr *mantis_get_slave_descr(void);
#undef get_accel_slave_descr
#define get_accel_slave_descr mantis_get_slave_descr
#endif

#ifdef CONFIG_MPU_SENSORS_MMA8450	
struct ext_slave_descr *mma8450_get_slave_descr(void);
#undef get_accel_slave_descr
#define get_accel_slave_descr mma8450_get_slave_descr
#endif

#ifdef CONFIG_MPU_SENSORS_MMA845X	
struct ext_slave_descr *mma845x_get_slave_descr(void);
#undef get_accel_slave_descr
#define get_accel_slave_descr mma845x_get_slave_descr
#endif


#define get_compass_slave_descr NULL

#ifdef CONFIG_MPU_SENSORS_AK8975	
struct ext_slave_descr *ak8975_get_slave_descr(void);
#undef get_compass_slave_descr
#define get_compass_slave_descr ak8975_get_slave_descr
#endif

#ifdef CONFIG_MPU_SENSORS_AK8963	
struct ext_slave_descr *ak8963_get_slave_descr(void);
#undef get_compass_slave_descr
#define get_compass_slave_descr ak8963_get_slave_descr
#endif

#ifdef CONFIG_MPU_SENSORS_AMI30X	
struct ext_slave_descr *ami30x_get_slave_descr(void);
#undef get_compass_slave_descr
#define get_compass_slave_descr ami30x_get_slave_descr
#endif

#ifdef CONFIG_MPU_SENSORS_HMC5883	
struct ext_slave_descr *hmc5883_get_slave_descr(void);
#undef get_compass_slave_descr
#define get_compass_slave_descr hmc5883_get_slave_descr
#endif

#ifdef CONFIG_MPU_SENSORS_MMC314X	
struct ext_slave_descr *mmc314x_get_slave_descr(void);
#undef get_compass_slave_descr
#define get_compass_slave_descr mmc314x_get_slave_descr
#endif

#ifdef CONFIG_MPU_SENSORS_LSM303DLHM	
struct ext_slave_descr *lsm303dlhm_get_slave_descr(void);
#undef get_compass_slave_descr
#define get_compass_slave_descr lsm303dlhm_get_slave_descr
#endif

#ifdef CONFIG_MPU_SENSORS_YAS529	
struct ext_slave_descr *yas529_get_slave_descr(void);
#undef get_compass_slave_descr
#define get_compass_slave_descr yas529_get_slave_descr
#endif

#ifdef CONFIG_MPU_SENSORS_HSCDTD002B	
struct ext_slave_descr *hscdtd002b_get_slave_descr(void);
#undef get_compass_slave_descr
#define get_compass_slave_descr hscdtd002b_get_slave_descr
#endif

#ifdef CONFIG_MPU_SENSORS_HSCDTD004A	
struct ext_slave_descr *hscdtd004a_get_slave_descr(void);
#undef get_compass_slave_descr
#define get_compass_slave_descr hscdtd004a_get_slave_descr
#endif
#define get_pressure_slave_descr NULL

#ifdef CONFIG_MPU_SENSORS_BMA085	
struct ext_slave_descr *bma085_get_slave_descr(void);
#undef get_pressure_slave_descr
#define get_pressure_slave_descr bma085_get_slave_descr
#endif

#endif				
