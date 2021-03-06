/*==========================================================
 * Copyright 2020 QuickLogic Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *==========================================================*/

/*==========================================================
 *                                                          
 *    File   : QL_SDF_Accel.h
 *    Purpose: Contain private structures used by Accel SDF drivers 
 *             which is compatible with SAL and SensorFrameworks
 *                                                          
 *=========================================================*/

#ifndef SENSORFRAMEWORK_DRIVERS_INC_QL_SDF_ACCEL_H_
#define SENSORFRAMEWORK_DRIVERS_INC_QL_SDF_ACCEL_H_

#include "QL_SDF.h"
/*
 * Private Structure to maintain the states of the sensor, as well as the states of individual instances held by clients *
 * FFE_SENSOR_ID will need to be maintained - common for all instances
 * FFE_INSTANCE_STATE - individually for each instance
 */

#define CONFIG_MAX_FFE_ACCEL_INSTANCE 2

#define SENSOR_STATE_INVALID	0
#define SENSOR_STATE_PROBED		1
#define SENSOR_STATE_OPENED		2  

/* represents an instance of the sensor */
typedef struct 
{
	unsigned char state;
	/* do we need any other variables for each instance ? */
}
QL_Accel_Ffe_Dev;

/*
 *
 * This is a private structure for the proxy driver running on M4.
 * The real driver is on FFE Side.
 * First member has to be QL_SDF_SensorDrv type as it is known by that type on the framework side.
 *
 */
typedef struct
{
	struct QL_SDF_SensorDrv drvData; 									/* Framework Side Representation */
	/* private stuff below */
	unsigned int  ffe_accel_id;											/* FFE Side Sensor ID */
	QL_Accel_Ffe_Dev devInstances[CONFIG_MAX_FFE_ACCEL_INSTANCE];		/* instance specific data */
}
QL_Accel_Ffe_Drv;

typedef struct {
	signed short dataX;
	signed short dataY;
	signed short dataZ;
}Accel_data;

extern void Accel_test();
double Get_Accel_Scale_Factor();
float Get_Accel_Scale_Factor_1000mG(void);


QL_Status Accel_init();
QL_Status Accel2_init();
QL_Status DT_init();
QL_Status PCG_init();
QL_Status SensiMl_SensorApp_init();

#endif /* SENSORFRAMEWORK_DRIVERS_INC_QL_SDF_ACCEL_H_ */
