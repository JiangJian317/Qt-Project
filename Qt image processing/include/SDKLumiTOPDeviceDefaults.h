/**
*
*  @ingroup SDKLumiTOPPageDEFAULTS_GRP
*  @file    SDKLumiTOPDeviceDefaults.h
*  @brief   This header files provides default values
*
*/

#ifndef LUMITOP_DEVICE_DEFAULTS_H
#define LUMITOP_DEVICE_DEFAULTS_H

// include SDKCore
#include <SDKCore.h>

// include SDKLumiTOPSensor specific types and definitions
#include "SDKLumiTOPDeviceParams.h"

#ifndef LS_IMPORT
#define LS_IMPORT  C4LUMISUITE_IMPORT
#endif
#ifdef __cplusplus
extern "C" {
#endif

    /* ----------------------------------------------------------------------------------------------- */
    /**
    * @ingroup SDKLumiTOPPageDEFAULTS_GRP
    * @brief LS_LTOPD_2dMeasurementParameterDefault
    *
    * This const value represents a @ref LS_LTOPD_2dMeasurement_Parameter_t struct filled with default values.
    *
    * Please use the @ref LS_LTOPD_2DMEASUREMENT_PARAMETER_CMD macro to define and initialize variables of type \a LS_LTOPD_2dMeasurement_Parameter_t.
    *
    */
    LS_IMPORT
        LS_LTOPD_2dMeasurement_Parameter_t LS_LTOPD_2dMeasurementParameterDefault;


    /**
    * @ingroup SDKLumiTOPPageMACROS_GRP
    * @brief LS_LTOPD_2DMEASUREMENT_PARAMETER_CMD
    *
    * This macros can be used to define a variable of type \a LS_LTOPD_2dMeasurement_Parameter_t that
    * is initialized with the recommended default values.
    *
    * @b Example:
    * @code{.c}
    * {
    *  ...
    *  LS_LTOPD_2DMEASUREMENT_PARAMETER_CMD(cmd);
    *  // The variable cmd is of type LS_LTOPD_2dMeasurement_Parameter_t and is initialized
    *  // with the recommended defaults from LS_LTOPD_2dMeasurementParameterDefault
    *  ...
    * }
    * @endcode
    */
#define LS_LTOPD_2DMEASUREMENT_PARAMETER_CMD(X)  LS_LTOPD_2dMeasurement_Parameter_t X = LS_LTOPD_2dMeasurementParameterDefault;

    /* ----------------------------------------------------------------------------------------------- */

    /**
    * @ingroup SDKLumiTOPPageDEFAULTS_GRP
    * @brief LS_LTOPD_serialNumberDefault
    *
    * This const value represents a @ref LS_LTOPD_SerialNumber_t struct filled with default values.
    *
    * Please use the @ref LS_LTOPD_SERIAL_NUMBER_CMD macro to define and initialize variables of type \a LS_LTOPD_SerialNumber_t.
    *
    */
    LS_IMPORT
        LS_LTOPD_SerialNumber_t LS_LTOPD_serialNumberDefault;


    /**
    * @ingroup SDKLumiTOPPageMACROS_GRP
    * @brief LS_LTOPD_SERIAL_NUMBER_CMD
    *
    * This macros can be used to define a variable of type \a LS_LTOPD_SerialNumber_t that
    * is initialized with the recommended default values.
    *
    * @b Example:
    * @code{.c}
    * {
    *  ...
    *  LS_LTOPD_SERIAL_NUMBER_CMD(cmd);
    *  // The variable cmd is of type LS_LTOPD_SerialNumber_t and is initialized
    *  // with the recommended defaults from LS_LTOPD_serialNumberDefault
    *  ...
    * }
    * @endcode
    */
#define LS_LTOPD_SERIAL_NUMBER_CMD(X)  LS_LTOPD_SerialNumber_t X = LS_LTOPD_serialNumberDefault;


    /* ----------------------------------------------------------------------------------------------- */

    /**
    * @ingroup SDKLumiTOPPageMACROS_GRP
    * @brief LS_LTOP_DISCOVER_DEVICES_INIT
    *
    * This macros can be used to define and initialize a variable of type \a LS_LTOPD_discoverDevices_t that
    * is initialized with the recommended default values.
    *
    * @b Example:
    * @code{.c}
    * {
    *  ...
    *  LS_LTOP_DISCOVER_DEVICES_INIT(cmd);
    *  // The variable cmd is of type LS_LTOPD_discoverDevices_t
    *  // and is zeroed by macro LS_LTOP_DISCOVER_DEVICES_INIT
    *  ...
    * }
    * @endcode
    */

#define LS_LTOP_DISCOVER_DEVICES_INIT(X)          LS_LTOPD_discoverDevices_t X; \
                                                  memset(&X, 0, sizeof(LS_LTOPD_discoverDevices_t));

    /* ----------------------------------------------------------------------------------------------- */

    /**
    * @ingroup SDKLumiTOPPageDEFAULTS_GRP
    * @brief LS_LTOPD_serialNumberCAS_Default
    *
    * This const value represents a @ref LS_LTOPD_SerialNumberCAS_t struct filled with default values.
    *
    * Please use the @ref LS_LTOP_SERIAL_NUMBER_CAS_CMD macro to define and initialize variables of type \a LS_LTOPD_SerialNumberCAS_t.
    *
    */
    LS_IMPORT
        LS_LTOPD_SerialNumberCAS_t LS_LTOPD_serialNumberCAS_Default;


    /**
    * @ingroup SDKLumiTOPPageMACROS_GRP
    * @brief LS_LTOP_SERIAL_NUMBER_CAS_CMD
    *
    * This macros can be used to define a variable of type \a LS_LTOPD_SerialNumberCAS_t that
    * is initialized with the recommended default values.
    *
    * @b Example:
    * @code{.c}
    * {
    *  ...
    *  LS_LTOP_SERIAL_NUMBER_CAS_CMD(cmd);
    *  // The variable cmd is of type LS_LTOPD_SerialNumberCAS_t and is initialized
    *  // with the recommended defaults from LS_LTOPD_serialNumberCAS_Default
    *  ...
    * }
    * @endcode
    */
#define LS_LTOP_SERIAL_NUMBER_CAS_CMD(X)  LS_LTOPD_SerialNumberCAS_t X = LS_LTOPD_serialNumberCAS_Default;


    /* ----------------------------------------------------------------------------------------------- */

    /**
    * @ingroup SDKLumiTOPPageMACROS_GRP
    * @brief LS_LTOP_DISCOVER_CASDEVICES_INIT
    *
    * This macros can be used to define and initialize a variable of type \a LS_LTOPD_discoverCASDevices_t that
    * is initialized with the recommended default values.
    *
    * @b Example:
    * @code{.c}
    * {
    *  ...
    *  LS_LTOP_DISCOVER_CASDEVICES_INIT(CAS_Devices);
    *  // The variable cmd is of type LS_LTOPD_discoverCASDevices_t
    *  // and is zeroed by macro LS_LTOP_DISCOVER_CASDEVICES_INIT
    *  ...
    * }
    * @endcode
    */

#define LS_LTOP_DISCOVER_CASDEVICES_INIT(X)       LS_LTOPD_discoverCASDevices_t X; \
                                                  memset(&X, 0, sizeof(LS_LTOPD_discoverCASDevices_t));

    /* ----------------------------------------------------------------------------------------------- */

    /**
    * @ingroup SDKLumiTOPPageDEFAULTS_GRP
    * @brief LS_LTOPD_takeImageDefault
    *
    * This const value represents a @ref LS_LTOPD_TakeImage_t struct filled with default values.
    *
    * Please use the @ref LS_LTOPD_TAKE_IMAGE_CMD macro to define and initialize variables of type \a LS_LTOPD_TakeImage_t.
    *
    */
    LS_IMPORT
        LS_LTOPD_TakeImage_t LS_LTOPD_takeImageDefault;


    /**
    * @ingroup SDKLumiTOPPageMACROS_GRP
    * @brief LS_LTOPD_TAKE_IMAGE_CMD
    *
    * This macros can be used to define a variable of type \a LS_LTOPD_TakeImage_t that
    * is initialized with the recommended default values.
    *
    * @b Example:
    * @code{.c}
    * {
    *  ...
    *  LS_LTOPD_TAKE_IMAGE_CMD(cmd);
    *  // The variable cmd is of type LS_LTOPD_TakeImage_t and is initialized
    *  // with the recommended defaults from LS_LTOPD_takeImageDefault
    *  ...
    * }
    * @endcode
    */
#define LS_LTOPD_TAKE_IMAGE_CMD(X)  LS_LTOPD_TakeImage_t X = LS_LTOPD_takeImageDefault;

    /* ----------------------------------------------------------------------------------------------- */

    /**
    * @ingroup SDKLumiTOPPageDEFAULTS_GRP
    * @brief LS_LTOPD_sensorStateDefault
    *
    * This const value represents a @ref LS_LTOPD_SensorState_t struct filled with default values.
    *
    * Please use the @ref LS_LTOPD_SENSOR_STATE_CMD macro to define and initialize variables of type \a LS_LTOPD_SensorState_t.
    *
    */
    LS_IMPORT
        LS_LTOPD_SensorState_t LS_LTOPD_sensorStateDefault;


    /**
    * @ingroup SDKLumiTOPPageMACROS_GRP
    * @brief LS_LTOPD_SENSOR_STATE_CMD
    *
    * This macros can be used to define a variable of type \a LS_LTOPD_SensorState_t that
    * is initialized with the recommended default values.
    *
    * @b Example:
    * @code{.c}
    * {
    *  ...
    *  LS_LTOPD_SENSOR_STATE_CMD(cmd);
    *  // The variable cmd is of type LS_LTOPD_SensorState_t and is initialized
    *  // with the recommended defaults from LS_LTOPD_sensorStateDefault
    *  ...
    * }
    * @endcode
    */
#define LS_LTOPD_SENSOR_STATE_CMD(X)  LS_LTOPD_SensorState_t X = LS_LTOPD_sensorStateDefault;



    /* ----------------------------------------------------------------------------------------------- */

    /**
    * @ingroup SDKLumiTOPPageDEFAULTS_GRP
    * @brief LS_LTOPD_measurementParameterCASDefault
    *
    * This const value represents a @ref LS_LTOPD_Measurement_Parameter_CAS_t struct filled with default values.
    *
    * Please use the @ref LS_LTOPD_MEASUREMENT_PARAMETER_CAS_CMD macro to define and initialize variables of type \a LS_LTOPD_Measurement_Parameter_CAS_t.
    *
    */
    LS_IMPORT
        LS_LTOPD_Measurement_Parameter_CAS_t LS_LTOPD_measurementParameterCASDefault;


    /**
    * @ingroup SDKLumiTOPPageMACROS_GRP
    * @brief LS_LTOPD_MEASUREMENT_PARAMETER_CAS_CMD
    *
    * This macros can be used to define a variable of type \a LS_LTOPD_Measurement_Parameter_CAS_t that
    * is initialized with the recommended default values.
    *
    * @b Example:
    * @code{.c}
    * {
    *  ...
    *  LS_LTOPD_MEASUREMENT_PARAMETER_CAS_CMD(cmd);
    *  // The variable cmd is of type LS_LTOPD_Measurement_Parameter_CAS_t and is initialized
    *  // with the recommended defaults from LS_LTOPD_measurementParameterCASDefault
    *  ...
    * }
    * @endcode
    */
#define LS_LTOPD_MEASUREMENT_PARAMETER_CAS_CMD(X)  LS_LTOPD_Measurement_Parameter_CAS_t X = LS_LTOPD_measurementParameterCASDefault;


    /* ----------------------------------------------------------------------------------------------- */

    /**
    * @ingroup SDKLumiTOPPageDEFAULTS_GRP
    * @brief LS_LTOPD_CASMeasurementDefault
    *
    * This const value represents a @ref LS_LTOPD_CASMeasurement_t struct filled with default values.
    *
    * Please use the @ref LS_LTOPD_CAS_MEASUREMENT_CMD macro to define and initialize variables of type \a LS_LTOPD_CASMeasurement_t.
    *
    */
    LS_IMPORT
        LS_LTOPD_CASMeasurement_t LS_LTOPD_CASMeasurementDefault;


    /**
    * @ingroup SDKLumiTOPPageMACROS_GRP
    * @brief LS_LTOPD_CAS_MEASUREMENT_CMD
    *
    * This macros can be used to define a variable of type \a LS_LTOPD_CASMeasurement_t that
    * is initialized with the recommended default values.
    *
    * @b Example:
    * @code{.c}
    * {
    *  ...
    *  LS_LTOPD_CAS_MEASUREMENT_CMD(cmd);
    *  // The variable cmd is of type LS_LTOPD_CASMeasurement_t and is initialized
    *  // with the recommended defaults from LS_LTOPD_CASMeasurementDefault
    *  ...
    * }
    * @endcode
    */
#define LS_LTOPD_CAS_MEASUREMENT_CMD(X)  LS_LTOPD_CASMeasurement_t X = LS_LTOPD_CASMeasurementDefault;

    /* ----------------------------------------------------------------------------------------------- */

    /**
    * @ingroup SDKLumiTOPPageDEFAULTS_GRP
    * @brief LS_LTOPD_CASSpectrumDefault
    *
    * This const value represents a @ref LS_LTOPD_CASSpectrum_t struct filled with default values.
    *
    * Please use the @ref LS_LTOPD_CAS_SPECTRUM_CMD macro to define and initialize variables of type \a LS_LTOPD_CASSpectrum_t.
    *
    */
    LS_IMPORT
        LS_LTOPD_CASSpectrum_t LS_LTOPD_CASSpectrumDefault;


    /**
    * @ingroup SDKLumiTOPPageMACROS_GRP
    * @brief LS_LTOPD_CAS_SPECTRUM_CMD
    *
    * This macros can be used to define a variable of type \a LS_LTOPD_CASSpectrum_t that
    * is initialized with the recommended default values.
    *
    * @b Example:
    * @code{.c}
    * {
    *  ...
    *  LS_LTOPD_CAS_SPECTRUM_CMD(Cmd);
    *  // The variable Cmd is of type LS_LTOPD_CASSpectrum_t and is initialized
    *  // with the recommended defaults from LS_LTOPD_CASSpectrumDefault
    *  ...
    * }
    * @endcode
    */
#define LS_LTOPD_CAS_SPECTRUM_CMD(X)  LS_LTOPD_CASSpectrum_t X = LS_LTOPD_CASSpectrumDefault;

    /* ----------------------------------------------------------------------------------------------- */

    /**
    * @ingroup SDKLumiTOPPageDEFAULTS_GRP
    * @brief LS_LTOPD_CASFilterDefault
    *
    * This const value represents a @ref LS_LTOPD_CASFilter_t struct filled with default values.
    *
    * Please use the @ref LS_LTOPD_CAS_FILTER_CMD macro to define and initialize variables of type \a LS_LTOPD_CASFilter_t.
    *
    */
    LS_IMPORT
        LS_LTOPD_CASFilter_t LS_LTOPD_CASFilterDefault;


    /**
    * @ingroup SDKLumiTOPPageMACROS_GRP
    * @brief LS_LTOPD_CAS_FILTER_CMD
    *
    * This macros can be used to define a variable of type \a LS_LTOPD_CASFilter_t that
    * is initialized with the recommended default values.
    *
    * @b Example:
    * @code{.c}
    * {
    *  ...
    *  LS_LTOPD_CAS_FILTER_CMD(cmd);
    *  // The variable cmd is of type LS_LTOPD_CASFilter_t and is initialized
    *  // with the recommended defaults from LS_LTOPD_CASFilterDefault
    *  ...
    * }
    * @endcode
    */
#define LS_LTOPD_CAS_FILTER_CMD(X)  LS_LTOPD_CASFilter_t X = LS_LTOPD_CASFilterDefault;


    /* ----------------------------------------------------------------------------------------------- */

    /**
    * @ingroup SDKLumiTOPPageDEFAULTS_GRP
    * @brief LS_LTOPD_imageCASSpotInformationDefault
    *
    * This const value represents a @ref LS_LTOPD_ImageCASSpotInformation_t struct filled with default values.
    *
    * Please use the @ref LS_LTOPD_IMAGE_CAS_SPOT_IMFORMATION_CMD macro to define and initialize variables of type \a LS_LTOPD_ImageCASSpotInformation_t.
    *
    */
    LS_IMPORT
        LS_LTOPD_ImageCASSpotInformation_t LS_LTOPD_imageCASSpotInformationDefault;


    /**
    * @ingroup SDKLumiTOPPageMACROS_GRP
    * @brief LS_LTOPD_IMAGE_CAS_SPOT_IMFORMATION_CMD
    *
    * This macros can be used to define a variable of type \a LS_LTOPD_ImageCASSpotInformation_t that
    * is initialized with the recommended default values.
    *
    * @b Example:
    * @code{.c}
    * {
    *  ...
    *  LS_LTOPD_IMAGE_CAS_SPOT_IMFORMATION_CMD(cmd);
    *  // The variable cmd is of type LS_LTOPD_ImageCASSpotInformation_t and is initialized
    *  // with the recommended defaults from LS_LTOPD_imageCASSpotInformationDefault
    *  ...
    * }
    * @endcode
    */
#define LS_LTOPD_IMAGE_CAS_SPOT_IMFORMATION_CMD(X)  LS_LTOPD_ImageCASSpotInformation_t X = LS_LTOPD_imageCASSpotInformationDefault;


    /* ----------------------------------------------------------------------------------------------- */

    /**
    * @ingroup SDKLumiTOPPageDEFAULTS_GRP
    * @brief LS_LTOPD_systemInfoDefault
    *
    * This const value represents a @ref LS_LTOPD_SystemInfo_t struct filled with default values.
    *
    * Please use the @ref LS_LTOPD_SYSTEM_INFO_CMD macro to define and initialize variables of type \a LS_LTOPD_SystemInfo_t.
    *
    */
    LS_IMPORT
        LS_LTOPD_SystemInfo_t LS_LTOPD_systemInfoDefault;


    /**
    * @ingroup SDKLumiTOPPageMACROS_GRP
    * @brief LS_LTOPD_SYSTEM_INFO_CMD
    *
    * This macros can be used to define a variable of type \a LS_LTOPD_SystemInfo_t that
    * is initialized with the recommended default values.
    *
    * @b Example:
    * @code{.c}
    * {
    *  ...
    *  LS_LTOPD_SYSTEM_INFO_CMD(Cmd);
    *  // The variable Cmd is of type LS_LTOPD_SystemInfo_t and is initialized
    *  // with the recommended defaults from LS_LTOPD_systemInfoDefault
    *  ...
    * }
    * @endcode
    */
#define LS_LTOPD_SYSTEM_INFO_CMD(X)  LS_LTOPD_SystemInfo_t X = LS_LTOPD_systemInfoDefault;


    /* ----------------------------------------------------------------------------------------------- */

    /**
    * @ingroup SDKLumiTOPPageDEFAULTS_GRP
    * @brief LS_LTOPD_temperatureDefault
    *
    * This const value represents a @ref LS_LTOPD_Temperature_t struct filled with default values.
    *
    * Please use the @ref LS_LTOPD_TEMPERATURE_CMD macro to define and initialize variables of type \a LS_LTOPD_Temperature_t.
    *
    */
    LS_IMPORT
        LS_LTOPD_Temperature_t LS_LTOPD_temperatureDefault;


    /**
    * @ingroup SDKLumiTOPPageMACROS_GRP
    * @brief LS_LTOPD_TEMPERATURE_CMD
    *
    * This macros can be used to define a variable of type \a LS_LTOPD_Temperature_t that
    * is initialized with the recommended default values.
    *
    * @b Example:
    * @code{.c}
    * {
    *  ...
    *  LS_LTOPD_TEMPERATURE_CMD(cmd);
    *  // The variable cmd is of type LS_LTOPD_Temperature_t and is initialized
    *  // with the recommended defaults from LS_LTOPD_temperatureDefault
    *  ...
    * }
    * @endcode
    */
#define LS_LTOPD_TEMPERATURE_CMD(X)  LS_LTOPD_Temperature_t X = LS_LTOPD_temperatureDefault;


    /* ----------------------------------------------------------------------------------------------- */

    /**
    * @ingroup SDKLumiTOPPageDEFAULTS_GRP
    * @brief LS_LTOPD_flickerMeasurementDefault
    *
    * This const value represents a @ref LS_LTOPD_FlickerMeasurement_t struct filled with default values.
    *
    * Please use the @ref LS_LTOPD_FLICKER_MEASUREMENT_CMD macro to define and initialize variables of type \a LS_LTOPD_FlickerMeasurement_t.
    *
    */
    LS_IMPORT
        LS_LTOPD_FlickerMeasurement_t LS_LTOPD_flickerMeasurementDefault;

    /**
    * @ingroup SDKLumiTOPPageMACROS_GRP
    * @brief LS_LTOPD_FLICKER_MEASUREMENT_CMD
    *
    * This macros can be used to define a variable of type \a LS_LTOPD_FlickerMeasurement_t that
    * is initialized with the recommended default values.
    *
    * @b Example:
    * @code{.c}
    * {
    *  ...
    *  LS_LTOPD_FLICKER_MEASUREMENT_CMD(cmd);
    *  // The variable cmd is of type LS_LTOPD_FlickerMeasurement_t and is initialized
    *  // with the recommended defaults from LS_LTOPD_flickerMeasurementDefault
    *  ...
    * }
    * @endcode
    */
#define LS_LTOPD_FLICKER_MEASUREMENT_CMD(X)  LS_LTOPD_FlickerMeasurement_t X = LS_LTOPD_flickerMeasurementDefault;


     /* ----------------------------------------------------------------------------------------------- */

    /**
    * @ingroup SDKLumiTOPPageDEFAULTS_GRP
    * @brief LS_LTOPD_luminanceModulationDefault
    *
    * This const value represents a @ref LS_LTOPD_LuminanceModulation_t struct filled with default values.
    *
    * Please use the @ref LS_LTOPD_LUMINANCE_MODULATION_CMD macro to define and initialize variables of type \a LS_LTOPD_LuminanceModulation_t.
    *
    */
    LS_IMPORT
        LS_LTOPD_LuminanceModulation_t LS_LTOPD_luminanceModulationDefault;

    /**
    * @ingroup SDKLumiTOPPageMACROS_GRP
    * @brief LS_LTOPD_LUMINANCE_MODULATION_CMD
    *
    * This macros can be used to define a variable of type \a LS_LTOPD_LuminanceModulation_t that
    * is initialized with the recommended default values.
    *
    * @b Example:
    * @code{.c}
    * {
    *  ...
    *  LS_LTOPD_LUMINANCE_MODULATION_CMD(cmd);
    *  // The variable cmd is of type LS_LTOPD_LuminanceModulation_t and is initialized
    *  // with the recommended defaults from LS_LTOPD_luminanceModulationDefault
    *  ...
    * }
    * @endcode
    */
#define LS_LTOPD_LUMINANCE_MODULATION_CMD(X)  LS_LTOPD_LuminanceModulation_t X = LS_LTOPD_luminanceModulationDefault;

    /* ----------------------------------------------------------------------------------------------- */

    /**
    * @ingroup SDKLumiTOPPageDEFAULTS_GRP
    * @brief LS_LTOPD_fineCorrectionDefault
    *
    * This const value represents a @ref LS_LTOPD_FineCorrection_t struct filled with default values.
    *
    * Please use the @ref LS_LTOPD_FINE_CORRECTION_CMD macro to define and initialize variables of type \a LS_LTOPD_FineCorrection_t.
    *
    */
    LS_IMPORT
        LS_LTOPD_FineCorrection_t LS_LTOPD_fineCorrectionDefault;

    /**
    * @ingroup SDKLumiTOPPageMACROS_GRP
    * @brief LS_LTOPD_FINE_CORRECTION_CMD
    *
    * This macros can be used to define a variable of type \a LS_LTOPD_FineCorrection_t that
    * is initialized with the recommended default values.
    *
    */
#define LS_LTOPD_FINE_CORRECTION_CMD(X)  LS_LTOPD_FineCorrection_t X = LS_LTOPD_fineCorrectionDefault;


    /* ----------------------------------------------------------------------------------------------- */

    /**
    * @ingroup SDKLumiTOPPageDEFAULTS_GRP
    * @brief LS_LTOPD_imagePropertiesDefault
    *
    * This const value represents a @ref LS_LTOPD_ImageProperties_t struct filled with default values.
    *
    * Please use the @ref LS_LTOPD_IMAGE_PROPERTIES_CMD macro to define and initialize variables of type \a LS_LTOPD_ImageProperties_t.
    *
    */
    LS_IMPORT
        LS_LTOPD_ImageProperties_t LS_LTOPD_imagePropertiesDefault;

    /**
    * @ingroup SDKLumiTOPPageMACROS_GRP
    * @brief LS_LTOPD_IMAGE_PROPERTIES_CMD
    *
    * This macros can be used to define a variable of type \a LS_LTOPD_ImageProperties_t that
    * is initialized with the recommended default values.
    *
    */
#define LS_LTOPD_IMAGE_PROPERTIES_CMD(X)  LS_LTOPD_ImageProperties_t X = LS_LTOPD_imagePropertiesDefault;


    /* ----------------------------------------------------------------------------------------------- */

    /**
    * @ingroup SDKLumiTOPPageDEFAULTS_GRP
    * @brief LS_LTOPD_DCCalibrationCameraDefault
    *
    * This const value represents a @ref LS_LTOPD_DCCalibrationCamera_t struct filled with default values.
    *
    * Please use the @ref LS_LTOPD_DCCALIBRATION_CAMERA_CMD macro to define and initialize variables of type \a LS_LTOPD_DCCalibrationCamera_t.
    *
    */
    LS_IMPORT
        LS_LTOPD_DCCalibrationCamera_t LS_LTOPD_DCCalibrationCameraDefault;


    /**
    * @ingroup SDKLumiTOPPageMACROS_GRP
    * @brief LS_LTOPD_DCCALIBRATION_CAMERA_CMD
    *
    * This macros can be used to define a variable of type \a LS_LTOPD_DCCalibrationCameraDefault that
    * is initialized with the recommended default values.
    *
    * @b Example:
    * @code{.c}
    * {
    *  ...
    *  LS_LTOPD_DCCALIBRATION_CAMERA_CMD(cmd);
    *  // The variable cmd is of type LS_LTOPD_DCCalibrationCamera_t and is initialized
    *  // with the recommended defaults from LS_LTOPD_DCCalibrationCameraDefault
    *  ...
    * }
    * @endcode
    */
#define LS_LTOPD_DCCALIBRATION_CAMERA_CMD(X)  LS_LTOPD_DCCalibrationCamera_t X = LS_LTOPD_DCCalibrationCameraDefault;

    /* ----------------------------------------------------------------------------------------------- */
    /**
    * @ingroup SDKLumiTOPPageDEFAULTS_GRP
    * @brief LS_LTOPD_connect2DeviceDefault
    *
    * This const value represents a @ref LS_LTOPD_Connect2Device_t struct filled with default values.
    *
    * Please use the @ref LS_LTOPD_CONNECT2DEVICE_CMD macro to define and initialize variables of type \a LS_LTOPD_Connect2Device_t.
    *
    */
    LS_IMPORT
        LS_LTOPD_Connect2Device_t LS_LTOPD_connect2DeviceDefault;


    /**
    * @ingroup SDKLumiTOPPageMACROS_GRP
    * @brief LS_LTOPD_CONNECT2DEVICE_CMD
    *
    * This macros can be used to define a variable of type \a LS_LTOPD_Connect2Device_t that
    * is initialized with the recommended default values.
    *
    * @b Example:
    * @code{.c}
    * {
    *  ...
    *  LS_LTOPD_CONNECT2DEVICE_CMD(cmd);
    *  // The variable cmd is of type LS_LTOPD_Connect2Device_t and is initialized
    *  // with the recommended defaults from LS_LTOPD_connect2DeviceDefault
    *  ...
    * }
    * @endcode
    */
#define LS_LTOPD_CONNECT2DEVICE_CMD(X)  LS_LTOPD_Connect2Device_t X = LS_LTOPD_connect2DeviceDefault;

    /* ----------------------------------------------------------------------------------------------- */
    /**
    * @ingroup SDKLumiTOPPageDEFAULTS_GRP
    * @brief LS_LTOP_DCCalParamsDefault
    *
    * This const value represents a @ref LS_LTOP_DCCalParams_t struct filled with default values.
    *
    * Please use the @ref LS_LTOP_DC_CAL_PARAMS_CMD macro to define and initialize variables of type \a LS_LTOP_DCCalParams_t.
    *
    */
    LS_IMPORT
        LS_LTOP_DCCalParams_t LS_LTOP_DCCalParamsDefault;


    /**
    * @ingroup SDKLumiTOPPageMACROS_GRP
    * @brief LS_LTOP_DC_CAL_PARAMS_CMD
    *
    * This macros can be used to define a variable of type \a LS_LTOP_DCCalParams_t that
    * is initialized with the recommended default values.
    *
    * @b Example:
    * @code{.c}
    * {
    *  ...
    *  LS_LTOP_DC_CAL_PARAMS_CMD(cmd);
    *  // The variable cmd is of type LS_LTOP_DCCalParams_t and is initialized
    *  // with the recommended defaults from LS_LTOP_DCCalParamsDefault
    *  ...
    * }
    * @endcode
    */
#define LS_LTOP_DC_CAL_PARAMS_CMD(X)  LS_LTOP_DCCalParams_t X = LS_LTOP_DCCalParamsDefault;


    /* ----------------------------------------------------------------------------------------------- */
    /* T E M P L A T E */
    /**
    * @ingroup SDKLumiTOPPageDEFAULTS_GRP
    * @brief XXXDefault
    *
    * This const value represents a @ref XXX_t struct filled with default values.
    *
    * Please use the @ref YYY macro to define and initialize variables of type \a XXX_t.
    *
    */
//    LS_IMPORT
//        XXX_t XXXDefault;


    /**
    * @ingroup SDKLumiTOPPageMACROS_GRP
    * @brief YYY
    *
    * This macros can be used to define a variable of type \a XXX_t that
    * is initialized with the recommended default values.
    *
    * @b Example:
    * @code{.c}
    * {
    *  ...
    *  YYY(cmd);
    *  // The variable cmd is of type XXX_t and is initialized
    *  // with the recommended defaults from XXXDefault
    *  ...
    * }
    * @endcode
    */
//#define YYY(X)  XXX_t X = XXXDefault;


#ifdef __cplusplus
}
#endif


#endif // LUMITOP_DEVICE_DEFAULTS_H
