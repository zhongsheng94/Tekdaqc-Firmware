/*
 * Copyright 2013 Tenkiv, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on
 * an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the
 * specific language governing permissions and limitations under the License.
 */

/**
 * @file Tekdaqc_CalibrationTable.h
 * @brief Header file for the Tekdaqc's calibration table.
 *
 * Contains public definitions and data types for the Tekdaqc's calibration table.
 *
 * @author Jared Woolston (jwoolston@tenkiv.com)
 * @since v1.0.0.0
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef TEKDAQC_CALIBRATIONTABLE_H_
#define TEKDAQC_CALIBRATIONTABLE_H_

/* Define to provide proper behavior with C++ compilers ----------------------*/
#ifdef __cplusplus
extern "C" {
#endif

/*--------------------------------------------------------------------------------------------------------*/
/* INCLUDES */
/*--------------------------------------------------------------------------------------------------------*/

#include "Tekdaqc_Config.h"
#include "ADS1256_Driver.h"
#include <boolean.h>

/*--------------------------------------------------------------------------------------------------------*/
/* PUBLIC METHODS */
/*--------------------------------------------------------------------------------------------------------*/

/**
 * @brief Initializes the Tekdaqc's calibration table for read access.
 */
bool Tekdaqc_CalibrationInit(void);

/**
 * @brief Sets the current operating scale of the analog inputs.
 */
void Tekdaqc_SetAnalogInputScale(ANALOG_INPUT_SCALE_t scale);

/**
 * @brief Retrieves the current operating scale of the analog inputs.
 */
ANALOG_INPUT_SCALE_t Tekdaqc_GetAnalogInputScale(void);

/**
 * @brief Converts a human readable string into its corresponding analog input scale.
 */
ANALOG_INPUT_SCALE_t Tekdaqc_StringToAnalogInputScale(char* str);

/**
 * @brief Retrieves the human readable string for the specified analog input scale.
 */
const char* Tekdaqc_AnalogInputScaleToString(ANALOG_INPUT_SCALE_t scale);

/**
 * @brief Retrieves a self gain calibration value for the specified parameters.
 */
uint32_t Tekdaqc_GetBaseGainCalibration(ADS1256_SPS_t rate, ADS1256_PGA_t gain, ADS1256_BUFFER_t buffer);

/**
 * @brief Retrieves a gain calibration value for the specified parameters.
 */
uint32_t Tekdaqc_GetGainCalibration(ADS1256_SPS_t rate, ADS1256_PGA_t gain, ADS1256_BUFFER_t buffer);

/**
 * @brief Retreives a gain calibration correction factor for the specified parameters.
 */
float Tekdaqc_GetGainCorrectionFactor(ADS1256_SPS_t rate, ADS1256_PGA_t gain, ADS1256_BUFFER_t buffer, float temperature);

/**
 * @brief Retrieves an offset calibration value for the specified parameters.
 */
uint32_t Tekdaqc_GetOffsetCalibration(ADS1256_SPS_t rate, ADS1256_PGA_t gain, ADS1256_BUFFER_t buffer);

/**
 * @brief Retrieves the offset calibration value for the cold junction.
 */
uint32_t Tekdaqc_GetColdJunctionOffsetCalibration(void);

/**
 * @brief Retrieves a gain calibration value for the cold junction.
 */
uint32_t Tekdaqc_GetColdJunctionGainCalibration(void);

/**
 * @brief Enters calibration mode, enabling write access to the calibration table.
 */
FLASH_Status Tekdaqc_SetCalibrationMode(void);

/**
 * @brief Exits calibration mode, disabling write access to the calibration table.
 */
void Tekdaqc_EndCalibrationMode(void);

/**
 * @brief Check if the board is currently in calibration mode.
 */
bool Tekdaqc_IsCalibrationModeEnabled(void);

/**
 * @brief Sets the serial number of this Tekdaqc.
 */
FLASH_Status Tekdaqc_SetSerialNumber(char* serial);

/**
 * @brief Sets the temperature value for the specified temperature entry of the table.
 */
FLASH_Status Tekdaqc_SetCalibrationTemperature(float temp, uint8_t temp_idx);

/**
 * @brief Marks the calibration table to indicate that it is valid.
 */
FLASH_Status Tekdaqc_SetCalibrationValid(void);

/**
 * @brief Sets the gain calibration value for the specified parameters.
 */
FLASH_Status Tekdaqc_SetGainCalibration(float cal, ADS1256_SPS_t rate, ADS1256_PGA_t gain, ADS1256_BUFFER_t buffer,
		ANALOG_INPUT_SCALE_t scale, uint8_t temp_idx);

/**
 * @brief Sets the offset calibration value to be used for the cold junction sensor.
 */
FLASH_Status Tekdaqc_SetColdJunctionOffsetCalibration(uint32_t cal);

/**
 * @brief Sets the gain calibration value to be used for the cold junction sensor.
 */
FLASH_Status Tekdaqc_SetColdJunctionGainCalibration(uint32_t cal, bool forFLASH);

/**
 * @brief Sets the offset calibration value for the specified parameters.
 */
void Tekdaqc_SetOffsetCalibration(uint32_t cal, ADS1256_SPS_t rate, ADS1256_PGA_t gain, ADS1256_BUFFER_t buffer);

/**
 * @brief Sets the base gain calibration value for the specified parameters.
 */
void Tekdaqc_SetBaseGainCalibration(uint32_t cal, ADS1256_SPS_t rate, ADS1256_PGA_t gain, ADS1256_BUFFER_t buffer);

/**
 * @}
 */

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* TEKDAQC_CALIBRATIONTABLE_H_ */
