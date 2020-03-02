#ifndef SDKBLACKMURAPARAMS_H
#define SDKBLACKMURAPARAMS_H

#include <SDKCore.h>

#ifdef __cplusplus
extern "C" {
#endif

/* -----------------------------------------------------------------------
 *
 * LumiSuite (LS) Black Mura SDK - defines
 *
 * -------------------------------------------------------------------- */

/**
  * @ingroup SDKBlackMuraPageDefinitions_GRP
  * @brief LS_MAX_EXPOSURE_TIMES_FOR_CALIBRATION
  */
// #define LS_MAX_EXPOSURE_TIMES_FOR_CALIBRATION   20


/* -----------------------------------------------------------------------
 *
 * LumiSuite (LS) LumiCol Device SDK - type definitions
 *
 * -------------------------------------------------------------------- */

/**
 * @ingroup SDKBlackMuraPageDataStructs_GRP
 * @brief LS_BlackMura_Orientation_t
 */
typedef enum
{
    ///Horizontal alignment
    eHorizontal,
    ///Vertical alignment
    eVertical,
    ///Automatic alignment
    eAutomatic
} LS_BlackMura_Orientation_t;

/**
 * @ingroup SDKBlackMuraPageDataStructs_GRP
 * @brief LS_BlackMura_StandardVersion_t
 *
 * @remark
 * Standard version affects the result of the Black Mura calculation
 */
typedef enum
{
    ///Version 1.15
    eVersion115,
    ///Version 1.20
    eVersion120,
} LS_BlackMura_StandardVersion_t;


/**
 * @ingroup SDKBlackMuraPageDataStructs_GRP
 * @brief LS_BlackMura_VerifyDUTStability_t
 */
typedef struct
{
    /// Input image ID
    LS_ImageId_t _in_imgs[3];

    /// Variation between images. Multiply by 100 to obtain value in percentage
    float _out_dut_variation;
} LS_BlackMura_VerifyDUTStability_t;


/**
 * @ingroup SDKBlackMuraPageDataStructs_GRP
 * @brief LS_BlackMura_VerifyAlignment_t
 */
typedef struct
{
    /// Input image ID
    LS_ImageId_t _in_image_id;

    ///display width in millimeters
    int _in_display_width;
    ///display height in millimeters
    int _in_display_height;
    ///display horizontal resolution in pixels
    int _in_display_resolution_horizontal;
    ///display vertical resolution in pixels
    int _in_display_resolution_vertical;

    ///display orientation
    LS_BlackMura_Orientation_t _in_orientation;

    ///maximum allowed tilt
    float _in_tilt_max;
    ///maximum allowed rotation
    float _in_rotation_max;

    ///Calculated display Offset in X axis, in millimeters
    LS_PassFail_Float_t _out_offset_x;
    ///Calculated display Offset in Y axis, in millimeters
    LS_PassFail_Float_t _out_offset_y;
    ///Calculated display rotation, in degrees
    LS_PassFail_Float_t _out_rotation;
    ///Calculated display horizontal tilt, in degrees
    LS_PassFail_Float_t _out_tilt_horizontal;
    ///Calculated display vertical tilt, in degrees
    LS_PassFail_Float_t _out_tilt_vertical;
    ///Calculated horizontal reproduction scale
    LS_PassFail_Float_t _out_reproduction_scale_horizontal;
    ///Calculated vertical reproduction scale
    LS_PassFail_Float_t _out_reproduction_scale_vertical;    

    /// Global result of calculation. More descriptive information on the log
    LS_SDK_PassFail_t _out_pass_fail;

} LS_BlackMura_VerifyAlignment_t;


/**
 * @ingroup SDKBlackMuraPageDataStructs_GRP
 * @brief LS_BlackMura_VerifyFocus_t
 */
typedef struct
{
    /// Input image ID
    LS_ImageId_t _in_image_id;

    ///display horizontal resolution in pixels
    int _in_display_resolution_horizontal;
    ///display vertical resolution in pixels
    int _in_display_resolution_vertical;

    ///display orientation
    LS_BlackMura_Orientation_t _in_orientation;

    ///Minimum modulation
    float _in_modulation_min;
    ///Maximum modulation
    float _in_modulation_max;

    ///Calculated modulation
    LS_PassFail_Float_t _out_modulation;
    ///Calculated horizontal reproduction scale
    LS_PassFail_Float_t _out_reproduction_scale_horizontal;
    ///Calculated vertical reproduction scale
    LS_PassFail_Float_t _out_reproduction_scale_vertical;

    /// Global result of calculation. More descriptive information on the log
    LS_SDK_PassFail_t _out_pass_fail;

} LS_BlackMura_VerifyFocus_t;

/**
 * @ingroup SDKBlackMuraPageDataStructs_GRP
 * @brief LS_BlackMura_Calculate_t
 *
 * @remark
 * - Please use @ref LS_BlackMura_StandardVersion_t to decide, which Black Mura standard version to use
 * - The calculation result will change due to this setting
 */
typedef struct
{
    /// White image ID
    LS_ImageId_t _in_image_id_white;
    /// Black image ID
    LS_ImageId_t _in_image_id_black;

    ///Horizontal reproduction scale
    float        _in_reproduction_scale_horizontal;
    ///Vertical reproduction scale
    float        _in_reproduction_scale_vertical;
    ///NDE value
    int          _in_filterParam_NDE;

    /// Standard version
    LS_BlackMura_StandardVersion_t _in_standardVersion;

    /// White Uniformity image ID
    LS_ImageId_t _out_image_id_uniformity_white;
    /// Black Uniformity image ID
    LS_ImageId_t _out_image_id_uniformity_black;
    /// White Gradient image ID
    LS_ImageId_t _out_image_id_gradient_white;
    /// Black Gradient image ID
    LS_ImageId_t _out_image_id_gradient_black;

    /// Maximum relative gradient of white image
    LS_PassFail_Float_t _out_max_relative_gradient_white;
    /// Maximum relative gradient of black image
    LS_PassFail_Float_t _out_max_relative_gradient_black;

    /// Uniformity of white image
    LS_PassFail_Float_t _out_uniformity_white;
    /// Uniformity of black image
    LS_PassFail_Float_t _out_uniformity_black;

    /// Global result of calculation. More descriptive information on the log
    LS_SDK_PassFail_t _out_pass_fail;

} LS_BlackMura_Calculate_t;

/**
 * @ingroup SDKBlackMuraPageDataStructs_GRP
 * @brief LS_BlackMura_CalculationImagesToTextFiles_t
 *
 * @remark
 *         - Please be sure the target folder has enough disk space and is writable.
 *         - In case file extension is missing (.txt) it will be added.
 */
typedef struct
{
    /// ID of the image to save
    LS_ImageId_t _in_imageId;

    /// The name of the target file, including full path.
    /// Use UTF-8 encoding
    char _in_destFile [ LS_MAX_FILENAME_LEN ];

} LS_BlackMura_ImageToTextFile_t;

#ifdef __cplusplus
}
#endif

#endif
