/**
 *
 *  @defgroup SDKLColPage_GRP SDK LumiCol Device
 *  @brief     LumiSuite (LS) LumiCol Device SDK
 *
 *  @file      SDKLumiColDevice.h
 *
 *  @brief     LumiSuite (LS) LumiCol Device SDK
 *  @details   The header files provides all methods the can be used from the LumiSuite SDKCore
 *  @author    The LumiSuite (LS) development team
 *  @version   1.0.0.1
 *  @date      2015, 2016
 *  @copyright Copyright © 2015,2016 Instrument Systems GmbH, Munich. All Rights Reserved.
 */

/**
 *
 *  @ingroup SDKLColPage_GRP
 *  @defgroup intro_sec3 Introduction
 *  @brief Introduction and overview
 *  @section intro_sec3 &nbsp;
 *  This documents describes the interfaces of the LumiSuite LumiCol Device SDK library
 *
 *  The <b>LumiSuite SDK LumiCol Device</b> is device dependent and provides a collection of functions to use the LumiCol hardware. With this SDK you
 *  can take an image, get and set measurement and configuration parameters, deal with the embedded camera and colorimeter.
 *
 *  Please refer to @ref SDKCoreGettingStarted_GRP to get more details how to use the LumiSuite SDK.
 *  <br>Please refer to @ref SDKLColFunctions_GRP "SDK LumiCol Device Functions" for the list of available functions and more details.
 *  <br>Please refer to @ref SDKLColPageDataStructs_GRP "SDK LumiCol Data Structures" for the list of available structures, types and enums.
 *  <br>Please refer to @ref SDKLColPageErrors_GRP "SDK LumiCol Error Codes" for the list of error codes.
 *
 */

/**
 *
 *  @ingroup SDKLColPage_GRP
 *  @defgroup SDKLColFunctions_GRP Functions
 *  @brief List of available functions
 *
 */

/**
 *
 *  @ingroup SDKLColPage_GRP
 *  @defgroup SDKLColPageDataStructs_GRP Data Structures
 *  @brief List of available types, data structures and enumerations
 */

/**
 *
 *  @ingroup SDKLColPage_GRP
 *  @defgroup SDKLColPageDefinitions_GRP Defines
 *  @brief List of available definitions
 */

/**
 *
 *  @ingroup SDKLColPage_GRP
 *  @defgroup SDKLColPageErrors_GRP Error Codes
 *  @brief List of available error codes
 *
 */

/**
 *
 *  @ingroup SDKLColPage_GRP
 *  @defgroup SDKLColPageMISC_GRP Miscellaneous
 *  @brief Miscellaneous
 */

/**
 *
 *  @ingroup SDKLColPage_GRP
 *  @defgroup SDKLColPageDEFAULTS_GRP Defaults
 *  @brief List of available defaults
 *
 *  @brief List of default values that should be used to initialize variables that are used with LumiCol Device SDK functions
 *  <br>It is highly recommended to use these values
 *  to initialize variables that are used with LumiCol Device SDK functions. This keeps shure the command structs are always properly
 *  initialized and according with the latest LumiCol Device SDK requirements.
 *
 */

/**
 *
 *  @ingroup SDKLColPage_GRP
 *  @defgroup SDKLColPageMACROS_GRP Macros
 *  @brief List of macros
 *
 */

#ifndef LUMICOL_DEVICE_H
#define LUMICOL_DEVICE_H


// inlcude SDKCore
#include <SDKCore.h>

/* Include SDK Core default values and some macros */
#include "SDKLumiColDeviceDefaults.h"

// include SDKLumiColSensor specific types and definitions
#include "SDKLumiColDeviceParams.h"

#ifdef LS_DOXYGEN_RUN
#undef LS_CALLCONV
#define LS_CALLCONV
#endif



#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/*
 * Public programming interface for accessing the LumiCol device SDK
 */

/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKLColFunctions_GRP
 * @brief   Use this function to connect to an LumiCol device
 *
 * This function must be used to connect to an LumiCol device. The serial number is required.
 *
 * Please refer to @ref LS_LColD_Connect2Device_t for details about the input/output parameter properties.
 * Please see also @ref LS_LColD_disconnect.
 *
 * @param[in,out]  io_cmd  Ptr. to the command input/output data
 *
 * @return @ref eLS_OK on success or any other error code from @ref SDKCoreErrors_GRP "SDKCore Error Codes" or @ref SDKLColPageErrors_GRP "LumiCol device error codes" otherwise.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_LColD_connect( LS_LColD_Connect2Device_t * io_cmd);


/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKLColFunctions_GRP
 * @brief   Disconnect from LumiCol device
 *
 * This function must be used to disconnect from an LumiCol device.
 *
 * Please see also @ref LS_LColD_connect.
 *
 * @param[in]   in_handle   The handle to disconnect.
 *
 * @return @ref eLS_OK on success or any other error code from @ref SDKCoreErrors_GRP "SDKCore Error Codes" or @ref SDKLColPageErrors_GRP "SDKLumiColDevice Error Codes" otherwise.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_LColD_disconnect(LS_Handle_t  in_handle);


/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKLColFunctions_GRP
 * @brief   Use this function to get the serial number of the currently connected LumiCol device
 *
 * Please refer to @ref LS_LColD_SerialNumber_t for details about the input/output parameter properties.
 *
 * @param[in,out]   io_cmd  Ptr. to the command input/output data. Ptr must not be null.
 *
 * @return @ref eLS_OK on success or any other error code from @ref SDKCoreErrors_GRP "SDKCore Error Codes" or @ref SDKLColPageErrors_GRP "SDKLumiColDevice Error Codes" otherwise.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_LColD_getSerialNumber (LS_LColD_SerialNumber_t* io_cmd);


/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKLColFunctions_GRP
 * @brief Use this function to get the temperature of the LumiCol device
 *
 * This functions the returns the temperature (in Celsius) of the LumiCol device.
 *
 * Please refer to @ref LS_LColD_Temperature_t for details about the input/output parameter properties.
 *
 * @param[in]   io_cmd  Ptr. to the command input/output data. Ptr must not be null.
 *
 * @return @ref eLS_OK on success or any other error code from @ref SDKCoreErrors_GRP "SDKCore Error Codes" or @ref SDKLColPageErrors_GRP "SDKLumiColDevice Error Codes" otherwise.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_LColD_getTemperature (LS_LColD_Temperature_t* io_cmd);


/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKLColFunctions_GRP
 * @brief Use this function to take an image
 *
 * This function triggers the LumiCol device to take an image synchronously. No parameters are required.
 * On success an image handle is returned that can be used for further operations.
 *
 * Please refer to @ref LS_LColD_TakeImage_t for details about the input/output parameter properties.
 *
 * @param[in,out]   io_cmd   Ptr. to the command input/output data.
 *
 * @return @ref eLS_OK on success or any other error code from @ref SDKCoreErrors_GRP "SDKCore Error Codes" or @ref SDKLColPageErrors_GRP "SDKLumiColDevice Error Codes" otherwise.
 *
 * @remarks
 *          - The functions @ref LS_LColD_setMeasurementParams  and @ref LS_LColD_setConfiguration must be called before taking an image
 *          - The function operates synchronously, That means the functions does not return until the image has been taken.
 *          - The amount of time until the function will return depends on the used measurement parameters. Thus, it may last several seconds to finish.
 */
LS_SDK_Status_t LS_CALLCONV LS_LColD_takeImage (LS_LColD_TakeImage_t* io_cmd);


/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKLColFunctions_GRP
 * @brief Use this function to take an image asynchronously
 *
 * This function triggers the LumiCol device to take an image. No parameters are required. The function returns
 * immediately. On success the given callback function is called when the image has been taken and is available.
 *
 * Please refer to @ref LS_LColD_takeImageAsync for details about the input/output parameter properties.
 *
 * @param[in]      in_imageReadyCallback Function callback. This parameter must be valid and not null. See @ref ImageReadyCallback
 * @param[in,out]  io_cmd   Ptr. to the command input/output data. See @ref LS_LColD_TakeImage_t
 *
 * @return @ref eLS_OK on success or any other error code from @ref SDKCoreErrors_GRP "SDKCore Error Codes" or @ref SDKLColPageErrors_GRP "SDKLumiColDevice Error Codes" otherwise.
 *
 * @remarks
 *              - The functions @ref LS_LColD_setMeasurementParams and @ref LS_LColD_setConfiguration must be called before taking an image
 *              - The function returns immediately
 *              - On success the given callback function is called with an valid image_id and when the image has been taken and is available
 *              - On failure the given callback function is called with an invalid image_id.
 *              - Cancel is supported: Refer to @ref LS_LColD_cancelTakeImageAsync
 *              - The given callback function <b>ImageReadyCallback</b> will be called as soon as the image has been taken and is available
 *              - The callback function may be called from an worker thread that may not the same as the thread when the LS_LColD_takeImageAsync is called.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_LColD_takeImageAsync (ImageReadyCallback in_imageReadyCallback, LS_LColD_TakeImage_t* io_cmd);


/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKLColFunctions_GRP
 * @brief Use this function to abort an take image asynchronously action
 *
 * This function aborts an active take image action. The function does nothing when the action
 * is already finished or if there is no take image action running.
 *
 * Please refer to @ref LS_LColD_takeImageAsync for details about the input/output parameter properties.
 *
 * @param[in,out]  io_cmd   Ptr. to the command input/output data. See @ref LS_LColD_TakeImage_t
 *
 * @return @ref eLS_OK on success or any other error code from @ref SDKCoreErrors_GRP "SDKCore Error Codes" or @ref SDKLColPageErrors_GRP "SDKLumiColDevice Error Codes" otherwise.
 *
 * @remarks
 *              - The functions always returns eLS_OK
 *              - On success the current take image action has been aborted
 */
LS_SDK_Status_t LS_CALLCONV LS_LColD_cancelTakeImageAsync (LS_LColD_TakeImage_t* io_cmd);


/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKLColFunctions_GRP
 * @brief Use this function to get the current state of the LumCol device
 *
 * This function returns the current status of the LCol device. When the device has an error then
 * the \a _out_errorMsg is set with an error message text.
 *
 * Please refer to @ref LS_LColD_SensorState_t for details about the available input/output parameter properties.
 *
 * @param[in]   io_cmd   Ptr. to the command input/output data.
 *
 * @return @ref eLS_OK on success or any other error code from @ref SDKCoreErrors_GRP "SDKCore Error Codes" or @ref SDKLColPageErrors_GRP "SDKLumiColDevice Error Codes" otherwise.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_LColD_getState (LS_LColD_SensorState_t* io_cmd);


/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKLColFunctions_GRP
 * @brief Use this function to perform an DC (dark current) calibration on the colorimeter
 *
 * This function performs DC calibration of the Colorimeter
 *
 * @param[in]   in_connection_handle   The connection handle.
 *
 * @return @ref eLS_OK on success or any other error code from @ref SDKCoreErrors_GRP "SDKCore Error Codes" or @ref SDKLColPageErrors_GRP "SDKLumiColDevice Error Codes" otherwise.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_LColD_runDcCalibration_Colorimeter(LS_Handle_t in_connection_handle);

/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKLColFunctions_GRP
 * @brief Use this function to perform a tristimulus measurement for the Colorimeter.
 *
 * Create a function that runs and returns the values of a tristimulus measurement for the Colorimeter.
 * The measured values are returned as 3 float values within the target color space
 *
 * Please refer to @ref LS_LColD_ColorimeterMeasurement_t for details about the available input/output parameter properties.
 *
 * @param[in]   io_cmd      Ptr. to the command input/output data.
 *
 * @return @ref eLS_OK on success or any other error code from @ref SDKCoreErrors_GRP "SDKCore Error Codes" or @ref SDKLColPageErrors_GRP "SDKLumiColDevice Error Codes" otherwise.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_LColD_runMeasurement_Colorimeter (LS_LColD_ColorimeterMeasurement_t * io_cmd);


/**
 *
 * @ingroup SDKLColFunctions_GRP
 * @brief Use this function to perform flicker measurement Colorimeter
 *
 * This function runs and returns the JEITA flicker measurement for the Colorimeter.
 *
 * Please refer to @ref LS_LColD_FlickerMeasurement_t for details about the available input/output parameter properties.
 *
 * @param[in]   io_cmd      Ptr. to the command input/output data.
 *
 * @return @ref eLS_OK on success or any other error code from @ref SDKCoreErrors_GRP "SDKCore Error Codes" or @ref SDKLColPageErrors_GRP "SDKLumiColDevice Error Codes" otherwise.
 *
 */
LS_SDK_Status_t LS_CALLCONV  LS_LColD_runJEITAFlickerMeasurement_Colorimeter (LS_LColD_FlickerMeasurement_t * io_cmd);


/**
 *
 * @ingroup SDKLColFunctions_GRP
 * @brief Use this function to perform contrast flicker measurement Colorimeter
 *
 * This function runs and returns the contrast flicker measurement for the Colorimeter.
 *
 * Please refer to @ref LS_LColD_ContrastFlickerMeasurement_t for details about the available input/output parameter properties.
 *
 * @param[in]   io_cmd      Ptr. to the command input/output data.
 *
 * @return @ref eLS_OK on success or any other error code from @ref SDKCoreErrors_GRP "SDKCore Error Codes" or @ref SDKLColPageErrors_GRP "SDKLumiColDevice Error Codes" otherwise.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_LColD_runContrastFlickerMeasurement_Colorimeter (LS_LColD_ContrastFlickerMeasurement_t * io_cmd);


/**
 *
 * @ingroup SDKLColFunctions_GRP
 * @brief Use this function to set the actice user calibration
 *
 * @param[in]   io_cmd   Ptr. to the command input/output data. The <b>_in_CalibrationName</b> must be valid
 *              and the specified calibration name must be known.
 *
 * @return @ref eLS_OK on success or any other error code from @ref SDKCoreErrors_GRP "SDKCore Error Codes" or @ref SDKLColPageErrors_GRP "SDKLumiColDevice Error Codes" otherwise.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_LColD_setActivUserCalibration (LS_LColD_Calibration_Name_t *io_cmd);


/**
 *
 * @ingroup SDKLColFunctions_GRP
 * @brief Use this function to delete an user calibration
 *
 * @param[in]   io_cmd   Ptr. to the command input/output data. The <b>_in_CalibrationName</b> must be valid
 *              and the specified calibration name must be known.
 *
 * @return @ref eLS_OK on success or any other error code from @ref SDKCoreErrors_GRP "SDKCore Error Codes" or @ref SDKLColPageErrors_GRP "SDKLumiColDevice Error Codes" otherwise.
 *
 * @remark The active user calibration cannot be deleted.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_LColD_deleteUserCalibration (LS_LColD_Calibration_Name_t * io_cmd);


/**
 *
 * @ingroup SDKLColFunctions_GRP
 * @brief Use this function to start the adding new user calibration process
 *
 * Adding an new user calibration requires the following steps:
 *      <br>1st: Start user calibration process
 *      <br>2nd: Set the reference XYZ color values
 *      <br>3rd: Save and finish the user calibration process
 *
 * Please refer to @ref LS_LColD_measureAndRegisterUserCalibration and @ref LS_LColD_endAddingUserCalibration
 *
 * @param[in]   io_cmd   Ptr. to the command input/output data.
 *              <br>Please refer to @ref LS_LColD_AddUserCalibration_t for more details about the required data.
 *
 * @return @ref eLS_OK on success or any other error code from @ref SDKCoreErrors_GRP "SDKCore Error Codes" or @ref SDKLColPageErrors_GRP "SDKLumiColDevice Error Codes" otherwise.
 *
 * @remark
 *          - Some user interaction is required in order to finish the process to add an new user calibration
 *          - The given name for the user calibration must not be be empty.
 *          - The function will return with an error if there already exists an user calibration with the given calibration name
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_LColD_startAddingUserCalibration (LS_LColD_AddUserCalibration_t * io_cmd);


/**
 *
 * @ingroup SDKLColFunctions_GRP
 * @brief Use this function to measure and register user calibration
 *
 *
 * This function must be called for each color (white, red, green, blue)
 *
 * The user calibration process must be started by calling @ref LS_LColD_startAddingUserCalibration and finished
 * with calling @ref LS_LColD_endAddingUserCalibration
 *
 * Please refer to @ref LS_LColD_startAddingUserCalibration and @ref LS_LColD_endAddingUserCalibration
 *
 * @param[in]   io_cmd   Ptr. to the command input/output data.
 *              <br>Please refer to @ref LS_LColD_AddUserCalibration_t for more details about the required data.
 *
 * @return @ref eLS_OK on success or any other error code from @ref SDKCoreErrors_GRP "SDKCore Error Codes" or @ref SDKLColPageErrors_GRP "SDKLumiColDevice Error Codes" otherwise.
 *
 * @remark
 *          - Before calling this function the function @ref LS_LColD_startAddingUserCalibration has to be called.
 *          - This function must be called for each color
 *          - SOme user interaction is required.
 *          - The function will return with an error if @ref LS_LColD_startAddingUserCalibration has not be called before
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_LColD_measureAndRegisterUserCalibration (LS_LColD_MeasureAndRegisterUserCalibration_t * io_cmd);


/**
 *
 * @ingroup SDKLColFunctions_GRP
 * @brief Use this function to save and finish the adding new user calibration process
 *
 * Adding an new user calibration requires the following steps: Start user calibration, set reference XYZ color values and then save and finish.
 *
 * Please refer to @ref LS_LColD_measureAndRegisterUserCalibration and @ref LS_LColD_endAddingUserCalibration
 *
 * @param[in]   io_cmd   Ptr. to the command input/output data. Please refer to @ref LS_LColD_AddUserCalibration_t for more details about the required data.
 *
 * @return @ref eLS_OK on success or any other error code from @ref SDKCoreErrors_GRP "SDKCore Error Codes" or @ref SDKLColPageErrors_GRP "SDKLumiColDevice Error Codes" otherwise.
 *
 * @remark
 *          - Some user interaction is required in order to finish the process to add an new user calibration
 *          - The given name for the user calibration must not be be empty.
 *          - The function will return with an error if @ref LS_LColD_startAddingUserCalibration and @ref LS_LColD_measureAndRegisterUserCalibration have not be called before.
 *          - The function will also return with an error if @ref LS_LColD_measureAndRegisterUserCalibration has not been called for each color.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_LColD_endAddingUserCalibration (LS_LColD_AddUserCalibration_t * io_cmd);


/**
 *
 * @ingroup SDKLColFunctions_GRP
 * @brief Use this function to get the number of user calibrations
 *
 * On return this function returns the number of user calibrations.

 * Please use the function @ref LS_LColD_getUserCalibrationItem to receive the individual
 * user calibration info. Plese refer also to @ref LS_LColD_CalibrationInfo_t.
 *
 * @param[in]   io_cmd      Ptr. to the command input/output data.
 *
 * @return @ref eLS_OK on success or any other error code from @ref SDKCoreErrors_GRP "SDKCore Error Codes" or @ref SDKLColPageErrors_GRP "SDKLumiColDevice Error Codes" otherwise.
 *
 * @b Example:
 * @code{.c}
 *
 *  LS_LColD_CalibrationListCount_t countCmd;
 *  countCmd._in_deviceHandle = deviceHandle;
 *  LS_SDK_Status_t stat = LS_LColD_getUserCalibrationCount(&countCmd);
 *
 *  if(stat== eLS_OK)
 *  {
 *      int32_t i=0;
 *      for(i=0; i < countCmd._out_count; i++)
 *      {
 *          LS_LColD_CalibrationListItem_t calibrationItem;
 *          calibrationItem._in_deviceHandle = deviceHandle;
 *          stat= LS_LColD_getUserCalibrationItem (i, &calibrationItem);
 *          if(stat== eLS_OK)
 *          {
 *              // use the received LS_LColD_CalibrationInfo_t data
 *              // calibrationItem._out_UserCalibrationInfo._Name
 *              // calibrationItem._out_UserCalibrationInfo._Comment
 *              // calibrationItem._out_UserCalibrationInfo._Channel
 *          }
 *      }
 *  }
 *
 * @endcode
 */
LS_SDK_Status_t LS_CALLCONV LS_LColD_getUserCalibrationCount(LS_LColD_CalibrationListCount_t *io_cmd);

/**
 *
 * @ingroup SDKLColFunctions_GRP
 * @brief @brief Use this function to get user calibration info
 *
 * @param[in]     idx       Index which @ref LS_LColD_CalibrationInfo_t is requested
 *                          Idx must not be out of range (maxCalibrationItem < Idx > 0)
 *
 * @param[in,out] io_cmd    Ptr. to the command input/output data.
 *
 * @return @ref eLS_OK on success or any other error code from @ref SDKCoreErrors_GRP "SDKCore Error Codes" or @ref SDKLColPageErrors_GRP "SDKLumiColDevice Error Codes" otherwise.
 *
 * @b Example:
 * @code{.c}
 *
 *  LS_LColD_CalibrationListCount_t countCmd;
 *  countCmd._in_deviceHandle = deviceHandle;
 *  LS_SDK_Status_t stat = LS_LColD_getUserCalibrationCount(&countCmd);
 *
 *  if(stat== eLS_OK)
 *  {
 *      int32_t i=0;
 *      for(i=0; i < countCmd._out_count; i++)
 *      {
 *          LS_LColD_CalibrationListItem_t calibrationItem;
 *          calibrationItem._in_deviceHandle = deviceHandle;
 *          stat= LS_LColD_getUserCalibrationItem (i, &calibrationItem);
 *          if(stat== eLS_OK)
 *          {
 *              // use the received LS_LColD_CalibrationInfo_t data
 *              // calibrationItem._out_UserCalibrationInfo._Name
 *              // calibrationItem._out_UserCalibrationInfo._Comment
 *              // calibrationItem._out_UserCalibrationInfo._Channel
 *          }
 *      }
 *  }
 * @endcode
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_LColD_getUserCalibrationItem (int idx, LS_LColD_CalibrationListItem_t *io_cmd);


/**
 *
 * @ingroup SDKLColFunctions_GRP
 * @brief Use this function to set the mode for the LED
 *
 *
 * @param[in]   io_cmd   Ptr. to the command input/output data.
 *
 * @return @ref eLS_OK on success or any other error code from @ref SDKCoreErrors_GRP "SDKCore Error Codes" or @ref SDKLColPageErrors_GRP "SDKLumiColDevice Error Codes" otherwise.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_LColD_setLEDMode (const LS_LColD_LEDMode_t * io_cmd);


/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKLColFunctions_GRP
 * @brief Use this function to set the measurement parameters. This function allows to specify parameters for the 2D measurement.
 *
 * The difference between this function and the function @ref LS_LColD_setConfiguration is that the parameters for this function
 * change frequently while the others are seldom changed. In any case, @ref LS_LColD_setConfiguration should be called at least once per session.
 *
 * Please refer to @ref LS_LColD_2dMeasurement_Parameter_t for details about the available measurement parameters and their meaning.
 * <br>Please refer to the macro @ref LS_LCOLD_2DMEASUREMENT_PARAMETER_CMD for details how to use proper default values for variables
 * of type \a LS_LColD_2dMeasurement_Parameter_t.
 *
 * @param[in]   io_cmd   Ptr. to the command input/output data.
 *
 * @return @ref eLS_OK on success or any other error code from @ref SDKCoreErrors_GRP "SDKCore Error Codes" or @ref SDKLColPageErrors_GRP "SDKLumiColDevice Error Codes" otherwise.
 *
 *
 * @b Example:
 * @code{.c}
 *
 *  LS_LCOLD_2DMEASUREMENT_PARAMETER_CMD(measurementParameter2D);          // Use macro to define an variable of type LS_LColD_2dMeasurement_Parameter_t and to init with default values.
 *
 *  measurementParameter2D._in_deviceHandle = deviceHandle;             // Handle to the connected device
 *  measurementParameter2D._in_exposureMode = ....;                     // Exposure mode: Fixed or Auto
 *  measurementParameter2D._in_averageNumber = xxx;                     // Num of averages. A value between 1 and 100
 *  measurementParameter2D._in_exposureTime = xxx;                      // Exposure time: e.g. 0.02s
 *  measurementParameter2D._in_ExposureType = xxx;                      // Exposure type: FineCorrected or WithoutFineCorrection
 *
 *  LS_SDK_Status_t stat = LS_LColD_setMeasurementParams (&measurementParameter2D);
 *
 * @endcode
 *
 * @remark If you use auto exposure, you still have to set a valid exposure time, as this is used in the algorithm for determing the correct auto exposure.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_LColD_setMeasurementParams (const LS_LColD_2dMeasurement_Parameter_t * io_cmd);


/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKLColFunctions_GRP
 * @brief Use this function to set measurement parameters of the Colorimeter
 *
 *
 * Please refer to @ref LS_LColD_Measurement_Parameter_Colorimeter_t for details about the available input parameter properties.
 *
 * @param[in]   in_cmd   Ptr. to the command input/output data.
 *
 * @return @ref eLS_OK on success or any other error code from @ref SDKCoreErrors_GRP "SDKCore Error Codes" or @ref SDKLColPageErrors_GRP "SDKLumiColDevice Error Codes" otherwise.
 *
 * @remark  This function does not affect 2D camera measurements, it is only applicable for single Colorimeter measurements.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_LColD_setMeasurementParams_Colorimeter (const LS_LColD_Measurement_Parameter_Colorimeter_t * in_cmd);


/**
 *
 * @ingroup SDKLColFunctions_GRP
 * @brief Use this function to set configuration parameters
 *
 * The difference between this function and the @ref LS_LColD_setMeasurementParams is that the parameters for this function
 * changed seldom while the others are changed frequently. Thus, set configuration parameter at the beginning of the
 * measurement and set the measurement parameters frequentyl. Although measurements can be performed without calling this function, this is not recommended,
 * as default values will be used, for example, for focus distance, therefore if the focus distance is not properly set, results can be incorrect.
 *
 * @param[in]   io_cmd   Ptr. to the command input/output data.
 *
 * @return @ref eLS_OK on success or any other error code from @ref SDKCoreErrors_GRP "SDKCore Error Codes" or @ref SDKLColPageErrors_GRP "SDKLumiColDevice Error Codes" otherwise.
 *
 * @remark
 *      -   In case this function is not called defaults are used.
 *      -   When this function is called only some parameters can be validated and later measurement may fail.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_LColD_setConfiguration(const LS_LColD_Configuration_t *io_cmd);


/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKLColFunctions_GRP
 * @brief Use this function to perform an DC (dark current) calibration on the camera
 *
 * It measure dark current images for the given list of exposure times and store in the memory.
 * After you call this function, DC images taken by this function are used.
 *
 * @param[in]   in_cmd   Ptr. to the command input data. Please refer to @ref LS_LColD_DCCalibrationCamera_t
 * for details about the expected input paramters/values.
 *
 * @return @ref eLS_OK on success or any other error code from @ref SDKCoreErrors_GRP "SDKCore Error Codes" or @ref SDKLColPageErrors_GRP "SDKLumiColDevice Error Codes" otherwise.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_LColD_runDcCalibration_Camera(const LS_LColD_DCCalibrationCamera_t *in_cmd);


/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKLColFunctions_GRP
 * @brief Use this function to reset camera calibration to factory
 *
 * @param[in]   in_connection_handle   The connection handle.
 *
 * @return @ref eLS_OK on success or any other error code from @ref SDKCoreErrors_GRP "SDKCore Error Codes" or @ref SDKLColPageErrors_GRP "SDKLumiColDevice Error Codes" otherwise.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_LColD_resetDcCalibration_Camera(LS_Handle_t in_connection_handle);


/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKLColFunctions_GRP
 * @brief Use this function to get system details of the connected device
 *
 * @param[in]   io_cmd   Ptr. to the command input/output data.
 *
 * @return @ref eLS_OK on success or any other error code from @ref SDKCoreErrors_GRP "SDKCore Error Codes" or @ref SDKLColPageErrors_GRP "SDKLumiColDevice Error Codes" otherwise.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_LColD_getSystemInformation(LS_LColD_SystemInfo_t *io_cmd );



#ifdef __cplusplus
}
#endif // __cplusplus

#endif // LUMICOL_DEVICE_H
