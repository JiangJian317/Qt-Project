/**
*
*  @ingroup SDKLColPageDEFAULTS_GRP
*  @file    SDKLumiColDeviceDefaults.h
*  @brief   This header files provides default values
*
*/

#ifndef LUMICOL_DEVICE_DEFAULTS_H
#define LUMICOL_DEVICE_DEFAULTS_H

// include SDKCore
#include <SDKCore.h>

// include SDKLumiColSensor specific types and definitions
#include "SDKLumiColDeviceParams.h"

#ifndef LS_IMPORT
#define LS_IMPORT  C4LUMISUITE_IMPORT
#endif
#ifdef __cplusplus
extern "C" {
#endif

    /* ----------------------------------------------------------------------------------------------- */
    /**
    * @ingroup SDKLColPageDEFAULTS_GRP
    * @brief LS_LColD_2dMeasurementParameterDefault
    *
    * This const value represents an @ref LS_LColD_2dMeasurement_Parameter_t struct filled with default values.
    *
    * Please use the @ref LS_LCOLD_2DMEASUREMENT_PARAMETER_CMD macro to define and initialize variables of type \a LS_LColD_2dMeasurement_Parameter_t.
    *
    */
    LS_IMPORT
        LS_LColD_2dMeasurement_Parameter_t LS_LColD_2dMeasurementParameterDefault;


    /**
    * @ingroup SDKLColPageMACROS_GRP
    * @brief LS_LCOLD_2DMEASUREMENT_PARAMETER_CMD
    *
    * This macros can be used to define an variable of type \a LS_LColD_2dMeasurement_Parameter_t that
    * is initialized with the recommended default values.
    *
    * @b Example:
    * @code{.c}
    * {
    *  ...
    *  LS_LCOLD_2DMEASUREMENT_PARAMETER_CMD(2dParamsCmd);
    *  // The variable 2dParamsCmd is of type LS_LColD_2dMeasurement_Parameter_t and is initialized
    *  // with the recommended defaults from LS_LColD_2dMeasurementParameterDefault
    *  ...
    * }
    * @endcode
    */
#define LS_LCOLD_2DMEASUREMENT_PARAMETER_CMD(X)  LS_LColD_2dMeasurement_Parameter_t X = LS_LColD_2dMeasurementParameterDefault;


    /* ----------------------------------------------------------------------------------------------- */
    /**
    * @ingroup SDKLColPageDEFAULTS_GRP
    * @brief LS_LColD_MeasurementParameterCA310Default
    *
    * This const value represents an @ref LS_LColD_Measurement_Parameter_Colorimeter_t struct filled with default values.
    *
    * Please use the @ref LS_MANUAL_CROP_IMAGE_CMD macro to define and initialize variables of type \a LS_LColD_Measurement_Parameter_Colorimeter_t.
    *
    */
    LS_IMPORT
        LS_LColD_Measurement_Parameter_Colorimeter_t LS_LColD_MeasurementParameterCA310Default;


    /**
    * @ingroup SDKLColPageMACROS_GRP
    * @brief LS_LCOLD_MEASUREMENT_PARAMETER_CA310_CMD
    *
    * This macros can be used to define an variable of type \a LS_LColD_Measurement_Parameter_Colorimeter_t that
    * is initialized with the recommended default values.
    *
    * @b Example:
    * @code{.c}
    * {
    *  ...
    *  LS_LCOLD_MEASUREMENT_PARAMETER_CA310_CMD(ca310ParamsCmd);
    *  // The variable ca310ParamsCmd is of type LS_LColD_Measurement_Parameter_Colorimeter_t and is initialized
    *  // with the recommended defaults from LS_LColD_MeasurementParameterCA310Default
    *  ...
    * }
    * @endcode
    */
#define LS_LCOLD_MEASUREMENT_PARAMETER_CA310_CMD(X)  LS_LColD_Measurement_Parameter_Colorimeter_t X = LS_LColD_MeasurementParameterCA310Default;




    /* ----------------------------------------------------------------------------------------------- */
    /**
    * @ingroup SDKLColPageDEFAULTS_GRP
    * @brief LS_LColD_ConfigurationParameterDefault
    *
    * This const value represents an @ref LS_LColD_Configuration_t struct filled with default values.
    *
    * Please use the @ref LS_LCOLD_CONFIGURATION_PARAMETER_CMD macro to define and initialize variables of type \a LS_LColD_Configuration_t.
    *
    */
    LS_IMPORT
        LS_LColD_Configuration_t LS_LColD_ConfigurationParameterDefault;

    /**
    * @ingroup SDKLColPageMACROS_GRP
    * @brief LS_LCOLD_CONFIGURATION_PARAMETER_CMD
    *
    * This macros can be used to define an variable of type \a LS_LColD_Configuration_t that
    * is initialized with the recommended default values.
    *
    */
#define LS_LCOLD_CONFIGURATION_PARAMETER_CMD(X)  LS_LColD_Configuration_t X = LS_LColD_ConfigurationParameterDefault;


    /* ----------------------------------------------------------------------------------------------- */
    /**
    * @ingroup SDKLColPageDEFAULTS_GRP
    * @brief LS_LColD_AddUserCalibrationDefault
    *
    * This const value represents an @ref LS_LColD_MeasureAndRegisterUserCalibration_t struct filled with default values.
    *
    * Please use the @ref LS_LCOLD_ADD_USER_CALIBRATION_CMD macro to define and initialize variables of type \a LS_LColD_MeasureAndRegisterUserCalibration_t.
    *
    */
    LS_IMPORT
        LS_LColD_AddUserCalibration_t LS_LColD_AddUserCalibrationDefault;


    /**
    * @ingroup SDKLColPageMACROS_GRP
    * @brief LS_LCOLD_ADD_USER_CALIBRATION_CMD
    *
    * This macros can be used to define an variable of type \a LS_LColD_MeasureAndRegisterUserCalibration_t that
    * is initialized with the recommended default values.
    *
    * @b Example:
    * @code{.c}
    * {
    *  ...
    *  LS_LCOLD_ADD_USER_CALIBRATION_CMD(userCalibrationCmd);
    *  // The variable userCalibrationCmd is of type LS_LColD_MeasureAndRegisterUserCalibration_t and is initialized
    *  // with the recommended defaults from LS_LColD_MeasureAndRegisterUserCalibrationDefault
    *  ...
    * }
    * @endcode
    */
#define LS_LCOLD_ADD_USER_CALIBRATION_CMD(X)  LS_LColD_AddUserCalibration_t X = LS_LColD_AddUserCalibrationDefault;


    /* ----------------------------------------------------------------------------------------------- */
    /**
    * @ingroup SDKLColPageDEFAULTS_GRP
    * @brief LS_LColD_MeasureAndRegisterUserCalibrationDefault
    *
    * This const value represents an @ref LS_LColD_MeasureAndRegisterUserCalibration_t struct filled with default values.
    *
    * Please use the @ref LS_LSCOLD_MEASURE_AND_REGISTER_USER_CALIBRATION_CMD macro to define and initialize variables of type \a LS_LColD_MeasureAndRegisterUserCalibration_t.
    *
    */
    LS_IMPORT
        LS_LColD_MeasureAndRegisterUserCalibration_t LS_LColD_MeasureAndRegisterUserCalibrationDefault;


    /**
    * @ingroup SDKLColPageMACROS_GRP
    * @brief LS_LSCOLD_MEASURE_AND_REGISTER_USER_CALIBRATION_CMD
    *
    * This macros can be used to define an variable of type \a LS_LColD_MeasureAndRegisterUserCalibration_t that
    * is initialized with the recommended default values.
    *
    * @b Example:
    * @code{.c}
    * {
    *  ...
    *  LS_LSCOLD_MEASURE_AND_REGISTER_USER_CALIBRATION_CMD(userCalibrationCmd);
    *  // The variable userCalibrationCmd is of type LS_LColD_MeasureAndRegisterUserCalibration_t and is initialized
    *  // with the recommended defaults from LS_LColD_MeasureAndRegisterUserCalibrationDefault
    *  ...
    * }
    * @endcode
    */
#define LS_LSCOLD_MEASURE_AND_REGISTER_USER_CALIBRATION_CMD(X)  LS_LColD_MeasureAndRegisterUserCalibration_t X = LS_LColD_MeasureAndRegisterUserCalibrationDefault;


    /* ----------------------------------------------------------------------------------------------- */
    /**
    * @ingroup SDKLColPageDEFAULTS_GRP
    * @brief LS_LColD_DCCalibrationCameraDefault
    *
    * This const value represents an @ref LS_LColD_DCCalibrationCamera_t struct filled with default values.
    *
    * Please use the @ref LS_LCOLD_DCCALIBRATION_CAMERA_CMD macro to define and initialize variables of type \a LS_LColD_DCCalibrationCamera_t.
    *
    */
    LS_IMPORT
        LS_LColD_DCCalibrationCamera_t LS_LColD_DCCalibrationCameraDefault;

    /**
    * @ingroup SDKLColPageMACROS_GRP
    * @brief LS_LCOLD_DCCALIBRATION_CAMERA_CMD
    *
    * This macros can be used to define an variable of type \a LS_LColD_DCCalibrationCamera_t that
    * is initialized with the recommended default values.
    *
    * @b Example:
    * @code{.c}
    * {
    *  ...
    *  LS_LCOLD_DCCALIBRATION_CAMERA_CMD(dcClibrationCmd);
    *  // The variable dcClibrationCmd is of type LS_LColD_DCCalibrationCamera_t and is initialized
    *  // with the recommended defaults from LS_LColD_DCCalibrationCameraDefault
    *  ...
    * }
    * @endcode
    */
#define LS_LCOLD_DCCALIBRATION_CAMERA_CMD(X)  LS_LColD_DCCalibrationCamera_t X = LS_LColD_DCCalibrationCameraDefault;



#ifdef __cplusplus
}
#endif


#endif // LUMICOL_DEVICE_DEFAULTS_H
