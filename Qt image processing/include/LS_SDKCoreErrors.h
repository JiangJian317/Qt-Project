/**
 *
 *  @ingroup SDKCoreErrors_GRP
 *  @file    LS_SDKCoreErrors.h
 *  @brief   This header files provides all error codes.
 *
 */


#ifndef LS_SDK_CORE_ERRORS_H
#define LS_SDK_CORE_ERRORS_H

#include "LS_SDKCoreDefs.h"


/* -----------------------------------------------------------------------
 *
 * LumiSuite (LS) SDK Core - error codes
 *
 * -------------------------------------------------------------------- */
/**
  * @ingroup SDKCoreErrors_GRP
  * @brief Error codes
  */
enum eLS_SDK_Status
{
    /// 0 - No errror, success
    eLS_OK  = 0,

/* common and unspecific error codes */

    /// 1 - Unspecified error
    eLS_Error,

    /// 2 - The given handle is invalid or unknown
    eLS_InvalidHandle,

    /// 3 - Command failed
    eLS_CmdFailed,

    /// 4 - One or more given arguments are invalid
    eLS_InvalidArgument,

    /// 5 - Function or feature not implemented
    eLS_NotImplemented,

    /// 6 - Application is out of memory
    eLS_OutOfMemory,

    /// 7 - Index is out of range
    eLS_OutOfRange,

/* FILE related codes */

    /// 8 - General access denied error
    eLS_AccessDenied,

    /// 9 - The required file name is missing
    eLS_FileNameMissing,

    /// 10 - File not found
    eLS_FileNotFound,

    /// 11 - File already exists
    eLS_FileAlreadyExists,

/* Image related codes */
    /// 12 - Loading an image failed
    eLS_LoadingImageFailed,

    /// 13 - Saveing an image failed
    eLS_SavingImageFailed,

    /// 14 - Image could not be deleted
    eLS_ImageDeleteFailed,

    /// 15 - Image is unknown - invalid or unknown image_id
    eLS_ImageNotFound,

    /// 16 - Non-continuous image are not supported
    eLS_ImageNonContinous,

/* Spotmeter related codes */
    /// 17 - There are no spotmeters set for measurement
    eLS_SpotmeterMissing,

/* Sensor related codes */
    /// 18 - There is already an connection to sensor
    eLS_SensorAllreadyConnected,

    /// 19 - There is no connection to sensor
    eLS_SensorNotConnected,

    /// 20 - The serial number is invalid and cannot be used to connect to sensor
    eLS_InvalidSerialNo,

    /// 21 - No configuration file found.
    /// EPT1 ONLY: The configuration file is required to connect to the sensor. The configuration file must be named as "LColxxxxx.xml"
    /// where x is the serial number. The SDK is seraching for the configuration file within the path which is specified
    /// by the "LCOL_CONFIG_PATH" environment variable and additional, within the local application
    /// data folder (usually "C:/Users/xxxx/AppData/Local/Instrument Systems GmbH/LumiSuite" where x is the name of current user).
    eLS_ConfigurationFileMissing,

    /// 22 - Spot sensor (LumiCol Colorimeter) missing
    eLS_SensorNoSpotSensor,

    /// 23 - Measurement parameters missing, invalid or could not be set
    eLS_SensorMeasurementParams,

    /// 24 - Could not take image
    eLS_SensorTakeImageFailed,

    /// 25 - The ansync version of the take image method is used but the required
    /// parameter <b>ImageReadyCallback</b> is not set
    eLS_SensorTakeImageCallbackMissing,

    /// 26 - Colorimeter Measurement parameters missing, invalid or could not be set
    eLS_WrongColorimeterMeasurementParams,

    /// 27 - Colorimeter XYZ Measurement
    eLS_ColorimeterMeasurementFailed,

    /// 28 - Colorimeter measurement
    eLS_ColorimeterMeasurementOutOfRange,

    /// 29 - Failed to set the active user calibration
    eLS_SetActiveUserCalibrationFailed,

    /// 30 - Failed to delete an user calibration
    /// This could be either the calibration name is unknown or
    /// the calibration name is the current active
    eLS_DeleteUserCalibrationFailed,

    /// 31 - Failed to start adding user calibration process
    eLS_AddingUserCalibrationFailed,

    /// 32 - Failed to measure and register user calibration process
    eLS_MeasureAndRegisterUserCalibrationFailed,

    /// 33 - Failed to end the adding user calibration process
    eLS_EndUserCalibrationFailed,

/* Analysis related codes */
    /// 34 - Analysis ID is unknown or invalid
    eLS_InvalidAnalysisID,

    /// 35 - Analysis result not found (e.g. analysis failed)
    eLS_AnalysisResultNotFound,

    /// 36 - Could not load recipe from file. The file is invalid.
    eLS_RecipeLoadError,

    /// 37 - There are no (supported) analysis available.
    eLS_NoAnalysisAvailabe,

    /// 38 - There are too many analyses added - only @ref LS_MAX_ANALYSIS at the same time are supported
    eLS_TooManyAnalysesAdded,

    /// 39 - The feature is not licensed
    eLS_NotLicensed,

    /* CAS sensor related codes */
    /// 40 - CAS is not connected
    eLS_CASNotConnected,

    /// 41 - CAS measurement parameters missing, invalid or could not be set
    eLS_WrongCASMeasurementParams,

    /// 42 - CAS measurement failed
    eLS_CASMeasurementFailed,

    /// 43 - Image doesn`t have spotmeter information
    eLS_ImageHasNoSpotInformation
};
typedef enum eLS_SDK_Status LS_SDK_Status_t;

#endif // LS_SDK_CORE_ERRORS_H
