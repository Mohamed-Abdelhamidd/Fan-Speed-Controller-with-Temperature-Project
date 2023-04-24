/*----------------------------------------------------------------------------------
 * Module: LM35 Temperature sensor
 *
 * File name: lm35_temperature_sensor.h
 *
 * Description: header file for LM35 Temperature sensor
 *
 * Author: Mohamed Abdelhamid
 *---------------------------------------------------------------------------------- */

#ifndef LM35_TEMP_SENSOR_H_
#define LM35_TEMP_SENSOR_H_
#include "std_types.h"
#include "adc.h"
/*************************************************************************************
 * 									Definitions										 *
 *************************************************************************************/
#define CHANNEL_NUMBER				2
#define MAXIMUM_SENSOR_TEMP			150
#define SENSOR_MAX_VOLT_VALUE       1.5

/*************************************************************************************
 * 								     Prototypes									     *
 *************************************************************************************/
/**/

uint8 LM35_getTemperature (void);

#endif /* LM35_TEMP_SENSOR_H_ */
