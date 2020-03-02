#ifndef LUMICOLSENSORPARAMS_H
#define LUMICOLSENSORPARAMS_H

#include <LS_SDKCoreDefs.h>

#ifdef __cplusplus
extern "C" {
#endif

/* -----------------------------------------------------------------------
 *
 * LumiSuite (LS) LumiCol Device SDK - defines
 *
 * -------------------------------------------------------------------- */

/**
  * @ingroup SDKLColPageDefinitions_GRP
  * @brief LS_MAX_EXPOSURE_TIMES_FOR_CALIBRATION
  */
#define LS_MAX_EXPOSURE_TIMES_FOR_CALIBRATION   20

/**
  * @ingroup SDKLColPageDefinitions_GRP
  * @brief LS_MAX_FREQUENCY_FOR_JEITA_FLICKER Maximum output frequency for flicker measurement
 */
#define LS_MAX_FREQUENCY_FOR_JEITA_FLICKER      65

/* -----------------------------------------------------------------------
 *
 * LumiSuite (LS) LumiCol Device SDK - type definitions
 *
 * -------------------------------------------------------------------- */

/**
 * @ingroup SDKLColPageDataStructs_GRP
 * @brief ImageReadyCallback
 */
typedef void (__cdecl * ImageReadyCallback)(LS_ImageId_t imageId, LS_SDK_Status_t status, LS_Handle_t handle);


/**
 * @ingroup SDKLColPageDataStructs_GRP
 * @brief eSyncModes
 */

enum eLS_SyncModes
{
    /// sync mode NTSC
    eSyncNTSC,

    /// sync mode PAL
    eSyncPAL ,

    /// sync mode UNIV
    eSyncUNIV,

    /// Sync mode INT
    eSyncINT
};


/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_SDK_ColorSpace_t
 *
 * Currently supported color spaces.
 *
 */
enum eLS_ColorSpace
{
    /// color space XYZ
    Color_Space_XYZ,

    /// color space Lv u'v'
    Color_Space_Lvuv,

    /// color space Lvxy
    Color_Space_Lvxy,

    /// color space CIE1960 Lv u v
    Color_Space_Lvuv1960,
};


/**
 * @ingroup SDKLColPageDataStructs_GRP
 * @brief LS_LColD_Connect2Device_t
 */
typedef struct
{
    /// The serial number of the device to connect for
    char _in_serialNumber[LS_MAX_SERIAL_NUMBER_LEN+1];

    /// The device handle
    /// On return this handle is set and valid when connection
    /// was successfully established to the device. On error the handle is invalid and
    /// an error code is returned.
    LS_Handle_t _out_deviceHandle;

} LS_LColD_Connect2Device_t;

/**
 * @ingroup SDKLColPageDataStructs_GRP
 * @brief LS_LColD_SerialNumber_t
 */
typedef struct
{
    /// The device handle
    LS_Handle_t _in_deviceHandle;

    /// The serial number, \0 terminated string
    char _out_serialNumber[LS_MAX_SERIAL_NUMBER_LEN];

} LS_LColD_SerialNumber_t;

/**
 * @ingroup SDKLColPageDataStructs_GRP
 * @brief LS_LColD_Temperature_t
 */
typedef struct
{
    /// The device handle
    LS_Handle_t _in_deviceHandle;

    /// Temperature of the camera [Celsius]
    float _out_temperature;

} LS_LColD_Temperature_t;


/**
 * @ingroup SDKLColPageDataStructs_GRP
 * @brief LS_LColD_TakeImage_t
 */
typedef struct
{
    /// The device handle
    LS_Handle_t _in_deviceHandle;

    /// ID of the image taken
    LS_ImageId_t _out_imageId;

} LS_LColD_TakeImage_t;



/**
 * @ingroup SDKLColPageDataStructs_GRP
 * @brief LS_LColD_SensorState_t
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

} LS_LColD_SensorState_t;


/**
 * @ingroup SDKLColPageDataStructs_GRP
 * @brief LS_User_Calibration_t
 */
typedef struct
{
    /// The name of the calibration
    char _Name[LS_MAX_CALIBRATION_NAME_LEN];

    /// The comment/description of the calibration
    char _Comment[LS_MAX_CALIBRATION_COMMENT_LEN];

    /// The Colorimeter channel
    int32_t  _Channel;

} LS_LColD_CalibrationInfo_t;


/**
 * @ingroup SDKLColPageDataStructs_GRP
 * @brief LS_LColD_CalibrationListCount_t
 */
typedef struct
{
    /// The device handle
    LS_Handle_t _in_deviceHandle;

    /// The number of (user) calibrations
    int32_t _out_count;

} LS_LColD_CalibrationListCount_t;

/**
 * @ingroup SDKLColPageDataStructs_GRP
 * @brief LS_LColD_CalibrationListItem_t
 */
typedef struct
{
    /// The device handle
    LS_Handle_t _in_deviceHandle;

    /// On return, the LS_CalibrationInfo
    LS_LColD_CalibrationInfo_t _out_UserCalibrationInfo;

} LS_LColD_CalibrationListItem_t;


/**
 * @ingroup SDKLColPageDataStructs_GRP
 * @brief LS_LColD_Calibration_Name_t
 */
typedef struct
{
    /// The device handle
    LS_Handle_t _in_deviceHandle;

    /// The name of the calibration
    char  _in_CalibrationName[LS_MAX_CALIBRATION_NAME_LEN];

} LS_LColD_Calibration_Name_t;

enum eLS_UserCalibrationMode
{
    /// Matrix calibration
    eUmMatrix,

    /// Single point calibration
    eUmSinglePoint
};

/**
 * @ingroup SDKLColPageDataStructs_GRP
 * @brief LS_LColD_Calibration_Name_t
 */
typedef struct
{
    /// The device handle
    LS_Handle_t _in_deviceHandle;

    /// The name of the calibration
    /// The name is mandatory and must be unique (not yet used)
    char  _in_CalibrationName[LS_MAX_CALIBRATION_NAME_LEN];

    /// The comment/description of the calibration
    /// The comment is optional
    char _in_Comment[LS_MAX_CALIBRATION_COMMENT_LEN];

    enum eLS_UserCalibrationMode _in_Mode;
} LS_LColD_AddUserCalibration_t;


/**
 * @ingroup SDKLColPageDataStructs_GRP
 * @brief The eLS_UserCalibrationColor enum
 */
enum eLS_UserCalibrationColor
{
    /// Calibration color WHITE
    eUcWhite,

    /// Calibration color RED
    eUcRed,

    /// Calibration color GREEN
    eUcGreen,

    /// Calibration color BLUE
    eUcBlue
};


/**
 * @ingroup SDKLColPageDataStructs_GRP
 * @brief LS_LColD_MeasureAndRegisterUserCalibration_t
 *
 * Please refer also to @ref LS_LColD_MeasureAndRegisterUserCalibrationDefault and
 * @ref LS_LSCOLD_MEASURE_AND_REGISTER_USER_CALIBRATION_CMD
 *
 */
typedef struct
{
    /// The device handle
    LS_Handle_t _in_deviceHandle;

    /// The name of the calibration
    /// The name is mandatory and must be unique (not yet used)
    char  _in_CalibrationName[LS_MAX_CALIBRATION_NAME_LEN];

    /// The user calibration color
    enum eLS_UserCalibrationColor _in_CalibrationColor;

    /// Reference XYZ value for the given calibration color
    float  _in_colorValue[3];

} LS_LColD_MeasureAndRegisterUserCalibration_t;


/**
 * @ingroup SDKLColPageDataStructs_GRP
 * @brief LumiColSensorParams
 *
 * Please refer also to @ref LS_LColD_2dMeasurementParameterDefault and
 * @ref LS_LCOLD_2DMEASUREMENT_PARAMETER_CMD
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
    int32_t _in_ExposureType;

} LS_LColD_2dMeasurement_Parameter_t;


/**
 * @ingroup SDKLColPageDataStructs_GRP
 * @brief LS_LColD_Measurement_Parameter_Colorimeter_t
 *
 * Please refer also to @ref LS_LColD_MeasurementParameterCA310Default and
 * @ref LS_LCOLD_MEASUREMENT_PARAMETER_CA310_CMD
 *
 */
typedef struct
{
    /// The device handle
    LS_Handle_t _in_deviceHandle;

    /// Averaging number
    /// <br>Valid value range: 1 to 100
    int32_t  _in_averageNumber;

} LS_LColD_Measurement_Parameter_Colorimeter_t;


/**
 * @ingroup SDKLColPageDataStructs_GRP
 * @brief LS_LColD_Configuration_t
 */
typedef struct
{
    /// The connection handle
    LS_Handle_t _in_deviceHandle;

    /// distance in mm
    /// Valid value range: 1 and 10000
    /// The value depends on the calibration!
    uint32_t  _in_distance_mm;

    /// User calibration
    uint16_t _in_userCalibration;

    /// Synchronization mode
    /// see @ref eLS_SyncModes
    enum eLS_SyncModes _in_syncMode;

    /// Synchronization frequency [Hz]
    float _in_syncFreq;

    /// Low luminance measurement mode on or off
    bool _in_bLowLuminanceMode;

    /// infinite distance
    /// Use this property to set the distance as infinite.
    /// If this is enabled the value of the \a _in_distance_mm property is ignored
    bool _in_bInfiniteDistance;

} LS_LColD_Configuration_t;


/**
 * @ingroup SDKLColPageDataStructs_GRP
 * @brief LS_LColD_ColorimeterMeasurement_t
 */
typedef struct
{
    /// The device handle
    LS_Handle_t _in_deviceHandle;

    /// The color space that should be used
    enum eLS_ColorSpace _in_colorSpace;

    /// The X value
    float _out_X;

    /// The Y value
    float _out_Y;

    /// The Z value
    float _out_Z;

} LS_LColD_ColorimeterMeasurement_t;


/**
 * @ingroup SDKLColPageDataStructs_GRP
 * @brief LS_LColD_FlickerMeasurement_t
 */
typedef struct
{
    /// The device handle
    LS_Handle_t _in_deviceHandle;

    /// The flicker measurement value
    float _out_flickerMeasurementValue;

    /// The flicker measurement frequency
    int32_t _out_Freq;

    /// The amplitude from 0 hz to LS_MAX_FREQUENCY_FOR_JEITA_FLICKER hz
    float _out_amplitudes[LS_MAX_FREQUENCY_FOR_JEITA_FLICKER];
} LS_LColD_FlickerMeasurement_t;

/**
 * @ingroup SDKLColPageDataStructs_GRP
 * @brief LS_LColD_ContrastFlickerMeasurement_t
 */
typedef struct
{
    /// The device handle
    LS_Handle_t _in_deviceHandle;

    /// The flicker measurement value
    float _out_flickerMeasurementValue;

} LS_LColD_ContrastFlickerMeasurement_t;


/**
 * @ingroup SDKLColPageDataStructs_GRP
 * @brief LS_LColD_LEDMode_t
 */
typedef struct
{
    /// The device handle
    LS_Handle_t _in_deviceHandle;

    /// the mode to set for the LED
    LS_SDK_LEDMode_t _in_mode;

} LS_LColD_LEDMode_t;


/**
 * @ingroup SDKLColPageDataStructs_GRP
 * @brief LS_LColD_DCCalibrationCamera_t
 *
 * Please refer also to @ref LS_LColD_DCCalibrationCameraDefault and
 * @ref LS_LCOLD_DCCALIBRATION_CAMERA_CMD
 */
typedef struct
{
    /// The device handle
    LS_Handle_t _in_deviceHandle;

    /// List of additional exposure times used to create DC images. The list can be empty (all values set to 0). In any case the default exposure times are used
    float _in_additionalExposureTimes[LS_MAX_EXPOSURE_TIMES_FOR_CALIBRATION];

} LS_LColD_DCCalibrationCamera_t;


/**
 * @ingroup SDKLColPageDataStructs_GRP
 * @brief LS_LColD_SystemInfo_t
 */
typedef struct
{
    /// The device handle
    LS_Handle_t _in_deviceHandle;

    /// The serial number of the device
    char _out_serialNumber[LS_MAX_SERIAL_NUMBER_LEN+1];

    /// The version of the board on the device
    char _out_HardwareVersion[LS_MAX_VERSION_LEN+1];

    /// The version of the firmware on the device
    char _out_FirmwareVersion[LS_MAX_VERSION_LEN+1];

    /// The version of the boot loader on the device
    char _out_BootLoaderVersion[LS_MAX_VERSION_LEN+1];

    /// The number of shutter operations
    uint32_t _out_num_ShutterOperations;

    /// The number of shutter recovery operations
    uint16_t _out_num_ShutterRecoveries;

    /// The system info as formated string (for convenience)
    /// The format is as follows:
    /// sn:xxx;hardware_v:xx;firmware_v:xx.x;bootloader_v:xx.x;shutter_op:xxxxxx;shutter_rec:xxxxxx;
    /// where
    /// sn is the serial number
    /// hardware_v is the hardware version
    /// firmware_v is the firmware version
    /// bootloader_v is the bootloader version
    /// shutter_op is the number of shutter operations
    /// shutter_rec is the number of shutter revoveries
    char _out_systeminfo[LS_MAX_RESULT_LEN];

} LS_LColD_SystemInfo_t;


#ifdef __cplusplus
}
#endif

#endif
