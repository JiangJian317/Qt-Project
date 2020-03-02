/**
 *
 *  @defgroup SDKLumiTOPPage_GRP SDK LumiTOP Device
 *  @brief     LumiSuite (LS) LumiTOP Device SDK
 *
 *  @file      SDKLumiTOPDevice.h
 *
 *  @brief     LumiSuite (LS) LumiTOP Device SDK
 *  @details   The header files provides all methods the can be used from the LumiSuite SDKCore
 *  @author    The LumiSuite (LS) development team
 *  @version   1.0.0.1
 *  @date      2018
 *  @copyright Copyright © 2018 Instrument Systems GmbH, Munich. All Rights Reserved.
 */

/**
 *
 *  @ingroup SDKLumiTOPPage_GRP
 *  @defgroup intro_sec4 Introduction
 *  @brief Introduction and overview
 *  @section intro_sec4 &nbsp;
 *  This documents describes the interfaces of the LumiSuite LumiTOP Device SDK library
 *
 *  The <b>LumiSuite SDK LumiTOP Device</b> is device dependent and provides a collection of functions to use the LumiTOP hardware. With this SDK you
 *  can take an image, get and set measurement parameters, deal with the embedded camera and an additional CAS device.
 *
 *  Please refer to @ref SDKCoreGettingStarted_GRP to get more details how to use the LumiSuite SDK.
 *  <br>Please refer to @ref SDKLumiTOPFunctions_GRP "SDK LumiTOP Device Functions" for the list of available functions and more details.
 *  <br>Please refer to @ref SDKLumiTOPPageDataStructs_GRP "SDK LumiTOP Data Structures" for the list of available structures, types and enums.
 *  <br>Please refer to @ref SDKLumiTOPPageErrors_GRP "SDK LumiTOP Error Codes" for the list of error codes.
 *
 */

/**
 *
 *  @ingroup SDKLumiTOPPage_GRP
 *  @defgroup SDKLumiTOPFunctions_GRP Functions
 *  @brief List of available functions
 *
 */

/**
 *
 *  @ingroup SDKLumiTOPPage_GRP
 *  @defgroup SDKLumiTOPPageDataStructs_GRP Data Structures
 *  @brief List of available types, data structures and enumerations
 */

/**
 *
 *  @ingroup SDKLumiTOPPage_GRP
 *  @defgroup SDKLumiTOPPageErrors_GRP Error Codes
 *  @brief List of available error codes
 *
 */

/**
 *
 *  @ingroup SDKLumiTOPPage_GRP
 *  @defgroup SDKLumiTOPPageDEFAULTS_GRP Defaults
 *  @brief List of available defaults
 *
 *  @brief List of default values that should be used to initialize variables that are used with LumiTOP Device SDK functions
 *  <br>It is highly recommended to use these values
 *  to initialize variables that are used with LumiTOP Device SDK functions. This keeps shure the command structs are always properly
 *  initialized and according with the latest LumiTOP Device SDK requirements.
 *
 */

/**
 *
 *  @ingroup SDKLumiTOPPage_GRP
 *  @defgroup SDKLumiTOPPageMACROS_GRP Macros
 *  @brief List of macros
 *
 */

#ifndef LUMITOP_DEVICE_H
#define LUMITOP_DEVICE_H


// inlcude SDKCore
#include <SDKCore.h>

/* Include SDK Core default values and some macros */
#include "SDKLumiTOPDeviceDefaults.h"

// include SDKLumiTOPSensor specific types and definitions
#include "SDKLumiTOPDeviceParams.h"

#ifdef LS_DOXYGEN_RUN
#undef LS_CALLCONV
#define LS_CALLCONV
#endif



#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/*
 * Public programming interface for accessing the LumiTOP device SDK
 */

/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKLumiTOPFunctions_GRP
 * @brief   Use this function to connect to a LumiTOP device
 *
 * This function must be used to connect to a LumiTOP device. The serial number is required.
 * Also the CAS connection is set up if required.
 * @remark
 *      Complete CAS functionality is only available, when CAS is connected by this function before.
 *
 * Please refer to @ref LS_LTOPD_Connect2Device_t for details about the input/output parameter properties.
 * Please see also @ref LS_LTOPD_disconnect.
 *
 * @param[in,out]  io_cmd  Ptr. to the command input/output data
 *
 * @return @ref eLS_OK on success or any other error code from @ref SDKCoreErrors_GRP "SDKCore Error Codes" or @ref SDKLumiTOPPageErrors_GRP "LumiTOP device error codes" otherwise.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_LTOPD_connect( LS_LTOPD_Connect2Device_t * io_cmd);


/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKLumiTOPFunctions_GRP
 * @brief   Disconnect from LumiTOP device
 *
 * This function must be used to disconnect from a LumiTOP device.
 *
 * Please see also @ref LS_LTOPD_connect.
 *
 * @param[in]   in_handle   The handle to disconnect.
 *
 * @return @ref eLS_OK on success or any other error code from @ref SDKCoreErrors_GRP "SDKCore Error Codes" or @ref SDKLumiTOPPageErrors_GRP "SDKLumiTOPDevice Error Codes" otherwise.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_LTOPD_disconnect(LS_Handle_t  in_handle);


/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKLumiTOPFunctions_GRP
 * @brief Use this function to set the measurement parameters. This function allows to specify parameters for the 2D measurement.
 *
 * This function must be called before starting a measurement that is taking an image.
 * Please refer to @ref LS_LTOPD_2dMeasurement_Parameter_t for details about the available measurement parameters and their meaning.
 * Please refer to the macro @ref LS_LTOPD_Measurement_Parameter_CAS_t to set CAS parameters before starting a Hybrid
 * measurement.
 *
 * @param[in]   io_cmd   Ptr. to the command input/output data. Ptr must not be null.
 *
 * @return @ref eLS_OK on success or any other error code from @ref SDKCoreErrors_GRP "SDKCore Error Codes" or @ref SDKLumiTOPPageErrors_GRP "SDKLumiTOPDevice Error Codes" otherwise.
 *
 *
 * @b Example:
 * @code{.c}
 * *
 *  2dMeasurement_Parameter_t._in_deviceHandle = deviceHandle;        // Handle to the connected device
 *  2dMeasurement_Parameter_t._in_exposureMode = ....;                // Exposure mode: Fixed or Auto
 *  2dMeasurement_Parameter_t._in_averageNumber = xxx;                // Num of averages. A value between 1 and 100
 *  2dMeasurement_Parameter_t._in_exposureTime = xxx;                 // Exposure time in seconds: e.g. 0.02s
 *  2dMeasurement_Parameter_t._in_acquisitionMode = xxx;              // Acquisition mode: Hybrid or 2D chroma
 *
 *  LS_SDK_Status_t stat = LS_LTOPD_setMeasurementParams (&measurementParameter2D);
 *
 * @endcode
 *
 * @remark If you use auto exposure, you still have to set a valid exposure time, as this is used in the algorithm for determing the correct auto exposure.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_LTOPD_setMeasurementParams (const LS_LTOPD_2dMeasurement_Parameter_t * io_cmd);



/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKLumiTOPFunctions_GRP
 * @brief   Use this function to get the serial number of the currently connected LumiTOP device
 *
 * Please refer to @ref LS_LTOPD_SerialNumber_t for details about the input/output parameter properties.
 *
 * @param[in,out]   io_cmd  Ptr. to the command input/output data. Ptr must not be null.
 *
 * @return @ref eLS_OK on success or any other error code from @ref SDKCoreErrors_GRP "SDKCore Error Codes" or @ref SDKLumiTOPPageErrors_GRP "SDKLumiTOPDevice Error Codes" otherwise.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_LTOPD_getSerialNumber (LS_LTOPD_SerialNumber_t* io_cmd);

/* ----------------------------------------------------------------------------------------------- */

/**
 *
 * @ingroup SDKLumiTOPFunctions_GRP
 * @brief   Use this function to get the arrays of serial numbers and device types of all discovered LumiTOP devices.
 *
 * Order of listed serial numbers and device types is the same, this means each index of listed serial number
 *
 * is associated to the same index of corresponding device type.
 *
 * Please refer to @ref LS_LTOPD_discoverDevices_t for details about the output parameter properties.
 *
 * @param[in,out]   io_cmd  Ptr. to the command input/output data. Ptr must not be null.
 *
 * @return @ref eLS_OK on success or any other error code from @ref SDKCoreErrors_GRP "SDKCore Error Codes" or @ref SDKLumiTOPPageErrors_GRP "SDKLumiTOPDevice Error Codes" otherwise.
 *
 */

LS_SDK_Status_t LS_CALLCONV LS_LTOPD_discoverDevices (LS_LTOPD_discoverDevices_t* io_cmd);

/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKLumiTOPFunctions_GRP
 * @brief   Use this function to get the serial number of the currently connected CAS device, if you use one
 *
 * Please refer to @ref LS_LTOPD_SerialNumberCAS_t for details about the input/output parameter properties.
 *
 * @param[in,out]   io_cmd  Ptr. to the command input/output data. Ptr must not be null.
 *
 * @return @ref eLS_OK on success or any other error code from @ref SDKCoreErrors_GRP "SDKCore Error Codes" or @ref SDKLumiTOPPageErrors_GRP "SDKLumiTOPDevice Error Codes" otherwise.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_LTOPD_getSerialNumberCAS (LS_LTOPD_SerialNumberCAS_t *io_cmd);

/* ----------------------------------------------------------------------------------------------- */

/**
 *
 * @ingroup SDKLumiTOPFunctions_GRP
 * @brief   Use this function to get the serial numbers of all discovered CAS devices
 *
 * Please refer to @ref LS_LTOPD_discoverCASDevices_t for details about the output parameter properties.
 *
 * @param[in,out]   io_cmd  Ptr. to the command input/output data. Ptr must not be null.
 *
 * @return @ref eLS_OK on success or any other error code from @ref SDKCoreErrors_GRP "SDKCore Error Codes" or @ref SDKLumiTOPPageErrors_GRP "SDKLumiTOPDevice Error Codes" otherwise.
 *
 */


LS_SDK_Status_t LS_CALLCONV LS_LTOPD_discoverCASDevices (LS_LTOPD_discoverCASDevices_t* io_cmd);

/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKLumiTOPFunctions_GRP
 * @brief Use this function to take an image
 *
 * This function triggers the LumiTOP device to take an image synchronously. No parameters are required.
 * On success an image handle is returned that can be used for further operations.
 *
 * Please refer to @ref LS_LTOPD_TakeImage_t for details about the input/output parameter properties.
 *
 * @param[in,out]   io_cmd   Ptr. to the command input/output data. Ptr must not be null.
 *
 * @return @ref eLS_OK on success or any other error code from @ref SDKCoreErrors_GRP "SDKCore Error Codes" or @ref SDKLumiTOPPageErrors_GRP "SDKLumiTOPDevice Error Codes" otherwise.
 *
 * @remarks
 *          - The function @ref LS_LTOPD_setMeasurementParams must be called before taking an image
 *          - The function @ref LS_LTOPD_Measurement_Parameter_CAS_t must be called before when doing a hybrid measurement
 *          - The function operates synchronous, That means the functions does not return until the image has been taken.
 *          - The amount of time until the function will return depends on the used measurement parameters. Thus, it may last several seconds to finish.
 */
LS_SDK_Status_t LS_CALLCONV LS_LTOPD_takeImage (LS_LTOPD_TakeImage_t* io_cmd);


/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKLumiTOPFunctions_GRP
 * @brief Use this function to take an image asynchronously
 *
 * This function triggers the LumiTOP device to take an image. No parameters are required. The function returns
 * immediately. On success the given callback function is called when the image has been taken and is available.
 *
 * Please refer to @ref LS_LTOPD_takeImageAsync for details about the input/output parameter properties.
 *
 * @param[in]      in_imageReadyCallback Function callback. This parameter must be valid and not null. See @ref ImageReadyCallback
 * @param[in,out]  io_cmd   Ptr. to the command input/output data. See @ref LS_LTOPD_TakeImage_t. Ptr must not be null.
 *
 * @return @ref eLS_OK on success or any other error code from @ref SDKCoreErrors_GRP "SDKCore Error Codes" or @ref SDKLumiTOPPageErrors_GRP "SDKLumiTOPDevice Error Codes" otherwise.
 *
 * @remarks
 *              - The function @ref LS_LTOPD_setMeasurementParams must be called before taking an image
 *              - The function @ref LS_LTOPD_Measurement_Parameter_CAS_t must be called before when doing a hybrid measurement
 *              - The function returns immediately
 *              - On success the given callback function is called with an valid image_id and when the image has been taken and is available
 *              - On failure the given callback function is called with an invalid image_id.
 *              - Cancel is supported: Refer to @ref LS_LTOPD_cancelTakeImageAsync
 *              - The given callback function <b>ImageReadyCallback</b> will be called as soon as the image has been taken and is available
 *              - The callback function may be called from an worker thread that may not the same as the thread when the LS_LTOPD_takeImageAsync is called.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_LTOPD_takeImageAsync (ImageReadyCallback in_imageReadyCallback, LS_LTOPD_TakeImage_t* io_cmd);


/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKLumiTOPFunctions_GRP
 * @brief Use this function to abort an take image asynchronously action
 *
 * This function aborts an active take image action. The function does nothing when the action
 * is already finished or if there is no take image action running.
 *
 * Please refer to @ref LS_LTOPD_takeImageAsync for details about the input/output parameter properties.
 *
 * @param[in,out]  io_cmd   Ptr. to the command input/output data. See @ref LS_LTOPD_TakeImage_t. Ptr must not be null.
 *
 * @return @ref eLS_OK on success or any other error code from @ref SDKCoreErrors_GRP "SDKCore Error Codes" or @ref SDKLumiTOPPageErrors_GRP "SDKLumiTOPDevice Error Codes" otherwise.
 *
 * @remarks
 *              - The functions always returns eLS_OK
 *              - On success the current take image action has been aborted
 *              - If an image acquisition is already finished, before this function is called, nothing happens.
 */
LS_SDK_Status_t LS_CALLCONV LS_LTOPD_cancelTakeImageAsync (LS_LTOPD_TakeImage_t* io_cmd);


/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKLumiTOPFunctions_GRP
 * @brief Use this function to get the current state of the LumTOP device
 *
 * This function returns the current status of the LumiTOP device. When the device has an error then
 * the \a _out_errorMsg is set with an error message text.
 *
 * Please refer to @ref LS_LTOPD_SensorState_t for details about the available input/output parameter properties.
 *
 * @param[in]   io_cmd   Ptr. to the command input/output data. Ptr must not be null.
 *
 * @return @ref eLS_OK on success or any other error code from @ref SDKCoreErrors_GRP "SDKCore Error Codes" or @ref SDKLumiTOPPageErrors_GRP "SDKLumiTOPDevice Error Codes" otherwise.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_LTOPD_getState (LS_LTOPD_SensorState_t* io_cmd);


/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKLumiTOPFunctions_GRP
 * @brief Use this function to perform flicker measurement
 *
 * This function runs the flicker measurement and returns results.
 *
 * Please refer to @ref LS_LTOPD_FlickerMeasurement_t for details about the available input/output parameter properties.
 *
 * @param[in]   io_cmd      Ptr. to the command input/output data. Ptr must not be null.
 *
 * @return @ref eLS_OK on success or any other error code from @ref SDKCoreErrors_GRP "SDKCore Error Codes" or @ref SDKLumiTOPPageErrors_GRP "SDKLumiTOPDevice Error Codes" otherwise.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_LTOPD_runFlickerMeasurement (LS_LTOPD_FlickerMeasurement_t * io_cmd);


/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKLumiTOPFunctions_GRP
 * @brief Use this function to perform a luminance modulation measurement.
 *
 * This function returns a frequency (e.g. from a display) and modulation amplitude
 *
 * Please refer to @ref LS_LTOPD_LuminanceModulation_t for details about the available input/output parameter properties.
 *
 * @param[in]   io_cmd      Ptr. to the command input/output data. Ptr must not be null.
 *
 * @return @ref eLS_OK on success or any other error code from @ref SDKCoreErrors_GRP "SDKCore Error Codes" or @ref SDKLumiTOPPageErrors_GRP "SDKLumiTOPDevice Error Codes" otherwise.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_LTOPD_runLuminanceModulation (LS_LTOPD_LuminanceModulation_t * io_cmd);


/**
 *
 * @ingroup SDKLumiTOPFunctions_GRP
 * @brief Use this function to perform a DC (dark current) camera calibration, if connected.
 *
 * Please refer to @ref LS_LTOPD_DCCalibrationCamera_t for details about the available input/output parameter properties.
 *
 * @param[in]   io_cmd      Ptr. to the command input/output data. Ptr must not be null.
 *
 * @return @ref eLS_OK on success or any other error code from @ref SDKCoreErrors_GRP "SDKCore Error Codes" or @ref SDKLumiTOPPageErrors_GRP "SDKLumiTOPDevice Error Codes" otherwise.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_LTOP_runDcCalibration_Camera(LS_LTOPD_DCCalibrationCamera_t * io_cmd);


/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKLumiTOPFunctions_GRP
 * @brief Use this function to perform an DC (dark current) calibration on the CAS device, if connected.
 *
 * @param[in]   in_device_handle   The device handle.
 *
 * @return @ref eLS_OK on success or any other error code from @ref SDKCoreErrors_GRP "SDKCore Error Codes" or @ref SDKLumiTOPPageErrors_GRP "SDKLumiTOPDevice Error Codes" otherwise.
 *
 * @remarks
 *           - The function @ref LS_LTOPD_setMeasurementParams_CAS must be called before running a DC calibration
 */
LS_SDK_Status_t LS_CALLCONV LS_LTOPD_runDcCalibration_CAS(LS_Handle_t in_device_handle);


/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKLumiTOPFunctions_GRP
 * @brief Use this function to set measurement parameters of the CAS
 *
 * Please refer to @ref LS_LTOPD_Measurement_Parameter_CAS_t for details about the available input parameter properties.
 *
 * @param[in]   in_cmd   Pointer to the command input/output data. Pointer must not be null.
 *
 * @return @ref eLS_OK on success or any other error code from @ref SDKCoreErrors_GRP "SDKCore Error Codes" or @ref SDKLumiTOPPageErrors_GRP "SDKLumiTOPDevice Error Codes" otherwise.
 *
 * @remark  This function does not affect 2D camera measurements, it is only applicable for single CAS measurements
 * and mandatory before doing a hybrid camera measurement.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_LTOPD_setMeasurementParams_CAS (const LS_LTOPD_Measurement_Parameter_CAS_t * in_cmd);


/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKLumiTOPFunctions_GRP
 * @brief Use this function to perform a measurement for the CAS.
 *
 * Create a function that runs and returns the values of a measurement for the CAS.
 * @remark Set valid measurement parameter before. Refer to @ref LS_LTOPD_setMeasurementParams_CAS.
 *
 * Please refer to @ref LS_LTOPD_CASMeasurement_t for details about the available input/output parameter properties.
 *
 * @param[in]   io_cmd      Ptr. to the command input/output data. Ptr must not be null.
 *
 * @return @ref eLS_OK on success or any other error code from @ref SDKCoreErrors_GRP "SDKCore Error Codes" or @ref SDKLumiTOPPageErrors_GRP "SDKLumiTOPDevice Error Codes" otherwise.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_LTOPD_runMeasurement_CAS (LS_LTOPD_CASMeasurement_t * io_cmd);


/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKLumiTOPFunctions_GRP
 * @brief Use this function to get the CAS spectrum result from the last measurement.
 *
 * Following measurement has to run before - otherwise an error is returned:
 * @ref LS_LTOPD_runMeasurement_CAS.
 *
 * Please refer to @ref LS_LTOPD_CASSpectrum_t for details about
 * the available and necessary input/output parameter properties.
 *
 * @param[in]   io_cmd      Ptr. to the command input/output data. Ptr must not be null.
 *
 * @return @ref eLS_OK on success or any other error code from @ref SDKCoreErrors_GRP "SDKCore Error Codes" or
 * @ref SDKLumiTOPPageErrors_GRP "SDKLumiTOPDevice Error Codes" otherwise.
 *
 * @remark
 *        - The \a io_cmd._out_spectrum must be a pointer to allocated memory where the spectrum can be serialized into.
 *        - The caller must allocate the memory for the spectrum and take care to delete as soon as the spectrum is no
 *          longer needed.
 *        - The size of the allocated memory buffer must be sufficient to serialize
 *          the spectrum otherwise the application would crash!
 *        - The size is returned by a CAS measurement. Refer to @ref LS_LTOPD_CASMeasurement_t
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_LTOPD_get_CAS_Spectrum (LS_LTOPD_CASSpectrum_t * io_cmd);


/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKLumiTOPFunctions_GRP
 * @brief Use this function to get density filter information from the CAS
 *
 *
 * Please refer to @ref LS_LTOPD_CASFilter_t for details about the available parameter properties.
 *
 * @param[in]   io_cmd   Ptr. to the command input/output data. Ptr must not be null.
 *
 * @return @ref eLS_OK on success or any other error code from @ref SDKCoreErrors_GRP "SDKCore Error Codes" or @ref SDKLumiTOPPageErrors_GRP "SDKLumiTOPDevice Error Codes" otherwise.
 *
 * * @b Example:
 * @code{.c}
 *
 *  LS_LTOPD_CASFilter_t filterCmd;
 *  filterCmd._in_deviceHandle = deviceHandle;
 *  // filterCmd._in_densityFilter is by default 0
 *  LS_SDK_Status_t stat = LS_LTOPD_getFilterCAS(&filterCmd);
 *
 *  if(stat!= eLS_OK)
 *  {
 *      // an error occured.
 *      return;
 *  }
 *
 *  char filterName[LS_MAX_RESULT_LEN] = filterCmd._out_filterName;
 *  // filterName is "no filter" for _in_densityFilter 0
 *
 *  if(filterCmd._out_filterCount == 1)
 *  {
 *      // CAS has no filter
 *      return;
 *  }
 *
 *  int32_t i=1;
 *  for(i; i < filterCmd._out_filterCount; i++)
 *  {
 *      filterCmd._in_densityFilter = i;
 *      stat = LS_LTOPD_getFilterCAS(&filterCmd);
 *      filterName = filterCmd._out_filterName;
 *      // filterName contains the corresponding name to i
 *  }
 * @endcode
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_LTOPD_getFilterCAS(LS_LTOPD_CASFilter_t * io_cmd);


/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKLumiTOPFunctions_GRP
 * @brief Use this function to get CAS spot information(size and location) from an image
 *
 * @param[in]   io_cmd   Ptr. to the command input/output data. Ptr must not be null.
 *
 * @return @ref eLS_OK on success or any other error code from @ref SDKCoreErrors_GRP "SDKCore Error Codes" or @ref SDKLumiTOPPageErrors_GRP "SDKLumiTOPDevice Error Codes" otherwise.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_LTOPD_CASSpotInformation(LS_LTOPD_ImageCASSpotInformation_t *io_cmd);


/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKLumiTOPFunctions_GRP
 * @brief Use this function to get system details of the connected device
 *
 * @param[in]   io_cmd   Ptr. to the command input/output data. Ptr must not be null.
 *
 * @return @ref eLS_OK on success or any other error code from @ref SDKCoreErrors_GRP "SDKCore Error Codes" or @ref SDKLumiTOPPageErrors_GRP "SDKLumiTOPDevice Error Codes" otherwise.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_LTOPD_getSystemInformation(LS_LTOPD_SystemInfo_t *io_cmd);


/**
 *
 * @ingroup SDKLumiTOPFunctions_GRP
 * @brief LS_LTOPD_getCameraTemperature
 *
 *
 * This function returns the camera temperature in celsius of the LumiTOP device.
 *
 *
 * @param[in]   io_cmd  Ptr. to the command input/output data. Ptr must not be null.
 *
 * @return @ref eLS_OK on success or any other error code from @ref SDKCoreErrors_GRP "SDKCore Error Codes" or @ref SDKLumiTOPPageErrors_GRP "SDKLumiColDevice Error Codes" otherwise.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_LTOPD_getTemperature (LS_LTOPD_Temperature_t* io_cmd);


/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKLumiTOPFunctions_GRP
 * @brief Use this function to apply a fine correction with X, Y, Z values on an image.
 * If you control a CAS by yourself, use this function to apply CAS X, Y, Z values to an image.
 *
 * Please refer to @ref LS_LTOPD_FineCorrection_t for details about the necessary input data.
 *
 * @param[in]   io_cmd   Ptr. to the command input/output data. Ptr must not be null.
 *
 * @return @ref eLS_OK on success or any other error code from @ref SDKCoreErrors_GRP "SDKCore Error Codes" or @ref SDKLumiTOPPageErrors_GRP "SDKLumiTOPDevice Error Codes" otherwise.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_LTOPD_applyFineCorrection(LS_LTOPD_FineCorrection_t *io_cmd);


/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKLumiTOPFunctions_GRP
 * @brief Use this function to get specific image properties from an input image.
 *
 * Please refer to @ref LS_LTOPD_ImageProperties_t for details about the necessary input data.
 *
 * @param[in]   io_cmd   Ptr. to the command input/output data. Ptr must not be null.
 *
 * @return @ref eLS_OK on success or any other error code from @ref SDKCoreErrors_GRP "SDKCore Error Codes" or @ref SDKLumiTOPPageErrors_GRP "SDKLumiTOPDevice Error Codes" otherwise.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_LTOPD_getImageProperties(LS_LTOPD_ImageProperties_t *io_cmd);  //


#ifdef __cplusplus
}
#endif // __cplusplus

#endif // LUMITOP_DEVICE_H
