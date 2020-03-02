#ifndef LUMITOPDEVICEPARAMS_H
#define LUMITOPDEVICEPARAMS_H

#include <LS_SDKCoreDefs.h>

#ifdef __cplusplus
extern "C" {
#endif


/* -----------------------------------------------------------------------
 *
 * LumiSuite (LS) LumiTOP Device SDK - type definitions
 *
 * -------------------------------------------------------------------- */

/**
 * @ingroup SDKLumiTOPPageDataStructs_GRP
 * @brief ImageReadyCallback
 */
typedef void (__cdecl * ImageReadyCallback)(LS_ImageId_t imageId, LS_SDK_Status_t status, LS_Handle_t handle);

/**
 * @ingroup SDKLumiTOPPageDataStructs_GRP
 * @brief LS_LTOPD_DeviceTypes_t
 */
typedef enum eLS_LTOPD_DeviceTypes
{
    /// LumiTOP 2700
    LS_LTOPD_DeviceTypes_LumiTOP2700 = 4,
    /// LumiTOP 4000
    LS_LTOPD_DeviceTypes_LumiTOP4000 = 6,
} LS_LTOPD_DeviceTypes_t;

/**
 * @ingroup SDKLumiTOPPageDataStructs_GRP
 * @brief LS_LTOPD_Connect2Device_t
 */
typedef struct
{
    /// The device type to connect to
    LS_LTOPD_DeviceTypes_t _in_devType;

    /// The serial number of the device to connect to
    char _in_serialNumber[LS_MAX_SERIAL_NUMBER_LEN+1];

    /// Set true, if you want to connect to CAS. False otherwise.
    bool _in_connectToCAS;

    /// The device handle
    /// On return this handle is set and valid when connection
    /// was successfully established to the device. On error the handle is invalid and
    /// an error code is returned.
    LS_Handle_t _out_deviceHandle;

} LS_LTOPD_Connect2Device_t;


/**
 * @ingroup SDKLumiTOPPageDataStructs_GRP
 * @brief LS_LTOPD_SerialNumber_t
 */
typedef struct
{
    /// The device handle
    LS_Handle_t _in_deviceHandle;

    /// The serial number, \0 terminated string
    char _out_serialNumber[LS_MAX_SERIAL_NUMBER_LEN];

} LS_LTOPD_SerialNumber_t;


/**
 * @ingroup SDKLumiTOPPageDataStructs_GRP
 * @brief LS_LTOPD_discoverDevices_t
 */
typedef struct
{
    /// LumiTOP serial numbers
    char _out_serialNumbers[LS_MAX_NUMBER_DEVICES][LS_MAX_SERIAL_NUMBER_LEN];

    /// LumiTOP device types
    char _out_deviceTypes[LS_MAX_NUMBER_DEVICES][LS_MAX_DEVICE_TYPE_LEN];

    /// Number of detected devices
    int32_t _out_deviceCount;

} LS_LTOPD_discoverDevices_t;


/**
 * @ingroup SDKLumiTOPPageDataStructs_GRP
 * @brief LS_LTOPD_SerialNumberCAS_t
 */
typedef struct
{
    /// The device handle
    LS_Handle_t _in_deviceHandle;

    /// CAS serial number
    char _out_serialNumberCAS[LS_MAX_SERIAL_NUMBER_LEN];

} LS_LTOPD_SerialNumberCAS_t;


/**
 * @ingroup SDKLumiTOPPageDataStructs_GRP
 * @brief LS_LTOPD_discoverCASDevices_t
 */
typedef struct
{
    /// CAS interface type
    LS_SDK_CasInterfaceType_t _in_interface_type;

    /// CAS serial numbers
    char _out_serialNumbersCAS[LS_MAX_NUMBER_DEVICES][LS_MAX_SERIAL_NUMBER_LEN];

    /// Number of detected devices
    int32_t _out_deviceCount;

} LS_LTOPD_discoverCASDevices_t;


/**
 * @ingroup SDKLumiTOPPageDataStructs_GRP
 * @brief LS_LTOPD_Temperature_t
 */
typedef struct
{
    /// The device handle
    LS_Handle_t _in_deviceHandle;

    /// Temperature of the camera [Celsius]
    float _out_temperature;

} LS_LTOPD_Temperature_t;


/**
 * @ingroup SDKLumiTOPPageDataStructs_GRP
 * @brief LS_LTOPD_TakeImage_t
 */
typedef struct
{
    /// The device handle
    LS_Handle_t _in_deviceHandle;

    /// ID of the image taken
    LS_ImageId_t _out_imageId;

} LS_LTOPD_TakeImage_t;


/**
 * @ingroup SDKLumiTOPPageDataStructs_GRP
 * @brief LS_LTOPD_SensorState_t
 */
typedef struct
{
    /// The device handle
    LS_Handle_t _in_deviceHandle;

    /// The system status values
    /// @li 0 device is disconnected
    /// @li 1 device is initializing
    /// @li 2 device is connected and idle
    /// @li 3 device is taking an single image
    /// @li 4 device is in state live view
    /// @li 5 device is in state loop
    int32_t _out_systemStatus;

    /// Error text details.
    /// Only in case the device is in error. Otherwise this field is empty.
    char _out_errorMsg[LS_STATUS_ERROR_TEXT_LEN];

} LS_LTOPD_SensorState_t;


/**
 * @ingroup SDKLumiTOPPageDataStructs_GRP
 * @brief LS_LTOPD_FlickerMeasurement_t
 */
typedef struct
{
    /// The device handle
    LS_Handle_t _in_deviceHandle;

    /// The repetition frequency that should be used
    float _in_flickerRepetitionFrequency;

    /// The flicker measurement result
    double _out_flickerMeasurementResult;

    /// The flicker measurement amplitude in [dB]
    double _out_flickerMeasurementAmplitude;

    /// Regarding the flicker measurement data, note that the first measurment point
    /// is skipped, because it is the DC value at 0 Hz. That means that the first x axis
    /// value corresponds to _out_flickerXAxisMeasurementStep.
    double _out_flickerMeasurementData[LS_MAX_NUMBER_LT_FLICKER_DATA];

    /// Equidistant distance between x axis mesurement points
    double _out_flickerXAxisMeasurementStep;

    /// number of flicker measurement points
    uint32_t _out_flickerMeasPoints;

} LS_LTOPD_FlickerMeasurement_t;


/**
 * @ingroup SDKLumiTOPPageDataStructs_GRP
 * @brief LS_LTOPD_LuminanceModulation_t
 */
typedef struct
{
    /// The device handle
    LS_Handle_t _in_deviceHandle;

    /// The sampling frequency. Must be between 300 and 5000 .
    float _in_samplingFrequency;

    /// The modulation frequency
    double _out_modulationFrequency;

    /// The modulation amplitude
    double _out_modulationAmplitude;

    /// Regarding the modulation measurement data, note that the first measurment point
    /// is skipped, because it is the DC value at 0 Hz. That means first x axis
    /// value corresponds to _out_modulationXAxisMeasurementStep.
    double _out_modulationMeasurementData[LS_MAX_NUMBER_LT_FLICKER_DATA];

    /// Equidistant distance between x axis mesurement points.
    double _out_modulationXAxisMeasurementStep;

    /// number of modulation measurement points
    uint32_t _out_modulationMeasPoints;

} LS_LTOPD_LuminanceModulation_t;

/**
 * @ingroup SDKLumiTOPPageDataStructs_GRP
 * @brief LS_LTOP_DCCalParams_t
 */
typedef struct
{
    /// Exposure time [s]
    /// The valid value range depends on the camera connection
    float _in_exposureTime;

    /// Averaging number
    /// <br>Valid value range: 1 to 100
    uint32_t _in_averageNumber;

} LS_LTOP_DCCalParams_t;

/**
 * @ingroup SDKLumiTOPPageDataStructs_GRP
 * @brief LS_LTOPD_DCCalibrationCamera_t
 */
typedef struct
{
    /// The device handle
    LS_Handle_t _in_deviceHandle;

    /// number of DC calibration parameter pairs
    uint32_t _in_numberOfPairs;

    /// List of exposure times and related average numbers. The list can be empty (all values set to 0), but
    /// a default exposure time of 1ms with 34 averages is always used, even it is not included in the array.
    /// Add a pair with 1ms exposure time and different averages to change the 34 averages for your measurement.
    LS_LTOP_DCCalParams_t _in_paramPairs[LS_MAX_PARAM_PAIRS_DC_CAL];

} LS_LTOPD_DCCalibrationCamera_t;

/**
 * @ingroup SDKLumiTOPPageDataStructs_GRP
 * @brief LS_LTOPD_2dMeasurement_Parameter_t
 *
 * Please refer also to @ref LS_LTOPD_2dMeasurementParameterDefault and
 * @ref LS_LTOPD_2DMEASUREMENT_PARAMETER_CMD
 * *
 */
typedef struct
{
    /// The connection handle
    LS_Handle_t _in_deviceHandle;

    /// Exposure mode
    /// see @ref SDKCorePageDataStructs_GRP LS_SDK_ExposureMode_t
    LS_SDK_ExposureMode_t  _in_exposureMode;

    /// Exposure time [s]
    /// The valid value range depends on the camera connection
    float _in_exposureTime;

    /// Averaging number
    /// <br>Valid value range: 1 to 100
    int32_t  _in_averageNumber;

    /// Exposure type
    /// see @ref SDKCorePageDataStructs_GRP LS_SDK_AquisitionMode_t
    LS_SDK_AquisitionMode_t _in_acquisitionMode;

} LS_LTOPD_2dMeasurement_Parameter_t;


/**
 * @ingroup SDKLumiTOPPageDataStructs_GRP
 * @brief LS_LTOPD_Measurement_Parameter_CAS_t
 *
 * Please refer also to @ref LS_LTOPD_MeasurementParameterCASDefault and
 * @ref LS_LUMITOP_MEASUREMENT_PARAMETER_CAS_CMD
 *
 * @remark
 * - If _in_exposureMode is set to eAuto, _in_integrationTime is not applied
 * - With exposure mode "auto" it is suggested to do a first measurement with an averaging number of 1.
 * After that you can increase the averaging number. This will keep the measurement duration short.
 *
 *
 */
typedef struct
{
    /// The device handle
    LS_Handle_t _in_deviceHandle;

    /// Exposure mode
    /// see @ref SDKCorePageDataStructs_GRP LS_SDK_ExposureMode_t
    LS_SDK_ExposureMode_t  _in_exposureMode;

    /// Maximum auto integration time
    /// The valid value range depends on the camera connection
    float  _in_maxAutoIntegrationTime;

    /// Integration time
    /// <br>time in seconds; range 0.001f to 10.0f
    float  _in_integrationTime;

    /// Averaging number
    /// <br>Valid value range: 1 to 100
    int32_t  _in_averageNumber;

    /// Density filter
    /// <br>Valid value range: 0 (no filter) to last OD filter
    /// Please refer to @ref LS_LTOPD_CASFilter_t to get number of filters
    uint32_t  _in_densityFilter;

} LS_LTOPD_Measurement_Parameter_CAS_t;


/**
 * @ingroup SDKLumiTOPPageDataStructs_GRP
 * @brief LS_LTOPD_CASFilter_t
 */
typedef struct
{
    /// The device handle
    LS_Handle_t _in_deviceHandle;

    /// Density filter
    /// <br>Valid value range: 0 (no filter) to _out_filterCount-1
    uint32_t  _in_densityFilter;

    /// Number of filters
    /// Does always include the "no filter", thus is always >= 1
    uint32_t _out_filterCount;

    /// The name of the filter, searched by _in_densityFilter. Empty when _in_densityFilter doesn`t exist.
    char _out_filterName[LS_MAX_RESULT_LEN];

} LS_LTOPD_CASFilter_t;


/**
 * @ingroup SDKLumiTOPPageDataStructs_GRP
 * @brief LS_LTOPD_CASMeasurement_t
 *
 * @remark Use _out_spectrum_size  to calculate the memory size that must be allocated for getting the spectrum and wavelength:
 * <br> <em>required_mem_size_spectrum = _out_spectrum_size * sizeof(float)</em>
 * <br> <em>required_mem_size_wavelength = _out_spectrum_size * sizeof(float)</em>
 * Please refer to @ref LS_LTOPD_CASSpectrum_t
 */
typedef struct
{
    /// The device handle
    LS_Handle_t _in_deviceHandle;

    /// The (capital)X value
    double _out_X;

    /// The (capital)Y value
    double _out_Y;

    /// The (capital)Z value
    double _out_Z;

    /// The Lv value
    double _out_Lv;

    /// The (small)x value
    double _out_x;

    /// The (small)y value
    double _out_y;

    /// Size of the resulting spectrum - Needed for allocating memory for getting the CAS spectrum and wavelength
    uint32_t _out_spectrum_size;

} LS_LTOPD_CASMeasurement_t;


/**
 * @ingroup SDKLumiTOPPageDataStructs_GRP
 * @brief LS_LTOPD_CASSpectrum_t
 *
 * @ref LS_LTOPD_CASMeasurement_t to get spectrum size for allocating memory for _out_spectrum and _out_wavelength.
 * Both have the same size!
 *
 */
typedef struct
{
    /// The device handle
    LS_Handle_t _in_deviceHandle;

    /// The spectrum from last measurement
    /// ptr where to copy spectrum data
    /// <br>On input \a _out_spectrum must be a valid pointer to allocated memory where the spectrum can be serialized into
    /// <br>On output \a _out_spectrum itself is not changed and refers to memory where the spectrum data has been copied into.
    float* _out_spectrum;

    /// The corresponding wavelength to the spectrum from last measurement
    /// ptr where to copy wavelength data
    /// <br>On input \a _out_wavelength must be a valid pointer to allocated memory where the wavelength can be serialized into
    /// <br>On output \a _out_wavelength itself is not changed and refers to memory where the wavelength data has been copied into.
    float* _out_wavelength;

} LS_LTOPD_CASSpectrum_t;


/**
 * @ingroup SDKLumiTOPPageDataStructs_GRP
 * @brief LS_LTOPD_ImageCASSpotInformation_t
 */
typedef struct
{
    /// ID of the input image
    LS_ImageId_t _in_imageId;

    /// x-Position (center position) in pixels
    float _out_posX;

    /// y-Position (center position) in pixels
    float _out_posY;

    /// radius in pixel
    float _out_radius;

} LS_LTOPD_ImageCASSpotInformation_t;


/**
 * @ingroup SDKLumiTOPPageDataStructs_GRP
 * @brief LS_LTOPD_SystemInfo_t
 */
typedef struct
{
    /// The device handle
    LS_Handle_t _in_deviceHandle;

    /// The serial number of the device
    char _out_serialNumber[LS_MAX_SERIAL_NUMBER_LEN+1];

    /// The serial number of the CAS device, if available - else empty
    char _out_serialNumberCAS[LS_MAX_SERIAL_NUMBER_LEN+1];

    /// The system info as formated string (for convenience)
    /// The format is as follows:
    /// sn:xxx;sn_CAS:xx;
    /// where
    /// sn is the serial number
    /// sn_CAS is serial number of CAS
    char _out_systeminfo[LS_MAX_RESULT_LEN];

} LS_LTOPD_SystemInfo_t;


/**
 * @ingroup SDKLumiTOPPageDataStructs_GRP
 * @brief LS_LTOPD_FineCorrectionMethod_t
 */
typedef enum eLS_LTOPD_FineCorrectionMethod
{
    /// No correction in case 2DChroma
    LS_LTOPD_FineCorrectionMethod_None,
    /// Correction by XYZ
    LS_LTOPD_FineCorrectionMethod_XYZ,
    /// Correction by vector
    LS_LTOPD_FineCorrectionMethod_Vector,

} LS_LTOPD_FineCorrectionMethod_t;


/**
 * @ingroup SDKLumiTOPPageDataStructs_GRP
 * @brief LS_LTOPD_FineCorrection_t
 */
typedef struct
{
    /// ID of the input image
    LS_ImageId_t _in_imageId;

    /// Correction method
    LS_LTOPD_FineCorrectionMethod_t _in_method;

    /// X value, depends on _in_method
    double _in_X;

    /// Y value, depends on _in_method
    double _in_Y;

    /// Z value, depends on _in_method
    double _in_Z;

    /// ID of the new fine corrected image. This image is added to the image pool
    LS_ImageId_t _out_imageId;

} LS_LTOPD_FineCorrection_t;


/**
 * @ingroup SDKLumiTOPPageDataStructs_GRP
 * @brief LS_LTOPD_ImageProperties_t
 *
 * @remark
 *  - if _out_CAS is false, _out_signalLevelCAS and _out_overExposedCAS do not contain proper information
 */
typedef struct
{
    /// ID of the input image
    LS_ImageId_t _in_imageId;

    /// The camera exposure time in [s]
    float _out_exposureTime;

    /// The CAS exposure time in [s]
    float _out_exposureTimeCAS;

    /// The camera signal level in percentage [%]
    uint32_t _out_signalLevelCamera;

    /// The CAS signal level in percentage [%]
    uint32_t _out_signalLevelCAS;

    /// True, when camera was well exposed. False otherwise.
    bool _out_wellExposedCamera;

    /// True, when CAS was used for image acquisition. False otherwise.
    bool _out_CAS;

    /// True, when CAS was over exposed. False otherwise.
    bool _out_overExposedCAS;

    /// CAS tristimulus X value
    double _out_tristimulus_X;

    /// CAS tristimulus Y value
    double _out_tristimulus_Y;

    /// CAS tristimulus Z value
    double _out_tristimulus_Z;

    /// X fine correction value
    double _out_X_fineCorrection;

    /// Y fine correction value
    double _out_Y_fineCorrection;

    /// Z fine correction value
    double _out_Z_fineCorrection;


} LS_LTOPD_ImageProperties_t;

#ifdef __cplusplus
}
#endif

#endif //LUMITOPDEVICEPARAMS_H

