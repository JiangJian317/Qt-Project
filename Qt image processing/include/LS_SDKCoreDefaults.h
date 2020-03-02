/**
 *
 *  @ingroup SDKCoreDEFAULT_GRP
 *  @file    LS_SDKCoreDefaults.h
 *  @brief   This header files provides all error codes.
 *
 */


#ifndef LS_SDK_CORE_DEFAULTS_H
#define LS_SDK_CORE_DEFAULTS_H

#include "SDKCoreExport.h"
#include "LS_SDKCoreDefs.h"

#ifndef LS_IMPORT
    #ifdef __MACH__
        #define LS_IMPORT extern
    #else
        #define LS_IMPORT  C4LUMISUITE_IMPORT
    #endif
#endif

/* ----------------------------------------------------------------------------------------------- */
/**
 * @ingroup SDKCoreDEFAULT_GRP
 * @brief LS_saveFileDefault
 *
 * This const value represents an @ref LS_SaveFile_t struct filled with default values.
 *
 * Please use the @ref LS_SAVE_FILE_CMD macro to define and initialize variables of type \a LS_SaveFile_t.
 *
 */
LS_IMPORT
LS_SaveFile_t LS_saveFileDefault;


/**
 * @ingroup SDKCoreMACROS_GRP
 * @brief LS_SAVE_FILE_CMD
 *
 * This macros can be used to define an variable of type \a LS_SaveFile_t that
 * is initialized with the recommended default values.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_SAVE_FILE_CMD(cmd);
 *  // The variable cmd is of type LS_SaveFile_t and is initialized
 *  // with the recommended defaults from LS_saveFileDefault
 *  ...
 * }
 * @endcode
 */
#define LS_SAVE_FILE_CMD(X)  LS_SaveFile_t X = LS_saveFileDefault;

/* ----------------------------------------------------------------------------------------------- */

/**
 * @ingroup SDKCoreDEFAULT_GRP
 * @brief LS_getImageInfoDefault
 *
 * This const value represents an @ref LS_GetImageInfo_t struct filled with default values.
 *
 * Please use the @ref LS_GET_IMAGE_INFO_CMD macro to define and initialize variables of type \a LS_GetImageInfo_t.
 *
 */
LS_IMPORT
LS_GetImageInfo_t LS_getImageInfoDefault;


/**
 * @ingroup SDKCoreMACROS_GRP
 * @brief LS_GET_IMAGE_INFO_CMD
 *
 * This macros can be used to define an variable of type \a LS_GetImageInfo_t that
 * is initialized with the recommended default values.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_GET_IMAGE_INFO_CMD(cmd);
 *  // The variable cmd is of type LS_GetImageInfo_t and is initialized
 *  // with the recommended defaults from LS_getImageInfoDefault
 *  ...
 * }
 * @endcode
 */
#define LS_GET_IMAGE_INFO_CMD(X)  LS_GetImageInfo_t X = LS_getImageInfoDefault;

/* ----------------------------------------------------------------------------------------------- */

/**
 * @ingroup SDKCoreDEFAULT_GRP
 * @brief LS_loadImageDefault
 *
 * This const value represents an @ref LS_LoadImage_t struct filled with default values.
 *
 * Please use the @ref LS_LOAD_IMAGE_CMD macro to define and initialize variables of type \a LS_LoadImage_t.
 *
 */
LS_IMPORT
LS_LoadImage_t LS_loadImageDefault;

/**
 * @ingroup SDKCoreMACROS_GRP
 * @brief LS_LOAD_IMAGE_CMD
 *
 * This macros can be used to define an variable of type \a LS_LoadImage_t that
 * is initialized with the recommended default values.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_LOAD_IMAGE_CMD(cmd);
 *  // The variable cmd is of type LS_LoadImage_t and is initialized
 *  // with the recommended defaults from LS_loadImageDefault
 *  ...
 * }
 * @endcode
 */
#define LS_LOAD_IMAGE_CMD(X)  LS_LoadImage_t X = LS_loadImageDefault;

/* ----------------------------------------------------------------------------------------------- */

/**
 * @ingroup SDKCoreDEFAULT_GRP
 * @brief LS_getVersionDefault
 *
 * This const value represents an @ref LS_GetVersion_t struct filled with default values.
 *
 * Please use the @ref LS_GET_VERSION_CMD macro to define and initialize variables of type \a LS_GetVersion_t.
 *
 */
LS_IMPORT
LS_GetVersion_t LS_getVersionDefault;

/**
 * @ingroup SDKCoreMACROS_GRP
 * @brief LS_GET_VERSION_CMD
 *
 * This macros can be used to define an variable of type \a LS_GetVersion_t that
 * is initialized with the recommended default values.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_GET_VERSION_CMD(cmd);
 *  // The variable cmd is of type LS_GetVersion_t and is initialized
 *  // with the recommended defaults from LS_getVersionDefault
 *  ...
 * }
 * @endcode
 */
#define LS_GET_VERSION_CMD(X)  LS_GetVersion_t X = LS_getVersionDefault;

/* ----------------------------------------------------------------------------------------------- */
/**
 * @ingroup SDKCoreDEFAULT_GRP
 * @brief LS_moireFilterImageDefault
 *
 * This const value represents an @ref LS_MoireFilterImage_t struct filled with default values.
 *
 * Please use the @ref LS_MOIRE_FILTER_IMAGE_CMD macro to define and initialize variables of type \a LS_MoireFilterImage_t.
 *
 */
LS_IMPORT
LS_MoireFilterImage_t LS_moireFilterImageDefault;

/**
 * @ingroup SDKCoreMACROS_GRP
 * @brief LS_MOIRE_FILTER_IMAGE_CMD
 *
 * This macros can be used to define an variable of type \a LS_MoireFilterImage_t that
 * is initialized with the recommended default values.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_MOIRE_FILTER_IMAGE_CMD(cmd);
 *  // The variable cmd is of type LS_MoireFilterImage_t and is initialized
 *  // with the recommended defaults from LS_moireFilterImageDefault
 *  ...
 * }
 * @endcode
 */
#define LS_MOIRE_FILTER_IMAGE_CMD(X)  LS_MoireFilterImage_t X = LS_moireFilterImageDefault;


/* ----------------------------------------------------------------------------------------------- */
/**
 * @ingroup SDKCoreDEFAULT_GRP
 * @brief LS_manualCropImageDefault
 *
 * This const value represents an @ref LS_ManualCropImage_t struct filled with default values.
 *
 * Please use the @ref LS_MANUAL_CROP_IMAGE_CMD macro to define and initialize variables of type \a LS_ManualCropImage_t.
 *
 */
LS_IMPORT
LS_ManualCropImage_t LS_manualCropImageDefault;

/**
 * @ingroup SDKCoreMACROS_GRP
 * @brief LS_MANUAL_CROP_IMAGE_CMD
 *
 * This macros can be used to define an variable of type \a LS_ManualCropImage_t that
 * is initialized with the recommended default values.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_MANUAL_CROP_IMAGE_CMD(cmd);
 *  // The variable cmd is of type LS_ManualCropImage_t and is initialized
 *  // with the recommended defaults from LS_manualCropImageDefault
 *  ...
 * }
 * @endcode
 */
#define LS_MANUAL_CROP_IMAGE_CMD(X)  LS_ManualCropImage_t X = LS_manualCropImageDefault;


/* ----------------------------------------------------------------------------------------------- */
/**
 * @ingroup SDKCoreDEFAULT_GRP
 * @brief LS_croppingAndFillingDefault
 *
 * This const value represents an @ref LS_CroppingAndFilling_t struct filled with default values.
 *
 * Please use the @ref LS_CROPPING_AND_FILLING_CMD macro to define and initialize variables of type \a LS_CroppingAndFilling_t.
 *
 */
LS_IMPORT
LS_CroppingAndFilling_t LS_croppingAndFillingDefault;

/**
 * @ingroup SDKCoreMACROS_GRP
 * @brief LS_CROPPING_AND_FILLING_CMD
 *
 * This macros can be used to define an variable of type \a LS_CroppingAndFilling_t that
 * is initialized with the recommended default values.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_CROPPING_AND_FILLING_CMD(cmd);
 *  // The variable cmd is of type LS_CroppingAndFilling_t and is initialized
 *  // with the recommended defaults from LS_croppingAndFillingDefault
 *  ...
 * }
 * @endcode
 */
#define LS_CROPPING_AND_FILLING_CMD(X)  LS_CroppingAndFilling_t X = LS_croppingAndFillingDefault;

/* ----------------------------------------------------------------------------------------------- */

/**
 * @ingroup SDKCoreDEFAULT_GRP
 * @brief LS_spotmeterDefault
 *
 * This const value represents an @ref LS_Spotmeter_t struct filled with the
 * recommended default values.
 *
 * Please use the macro @ref LS_SPOTMETER_CMD to define and initialize variables of type \a LS_Spotmeter_t.
 */
LS_IMPORT
LS_Spotmeter_t LS_spotmeterDefault;

/**
 * @ingroup SDKCoreMACROS_GRP
 * @brief LS_SPOTMETER_CMD
 *
 * This macros can be used to define an variable of type \a LS_Spotmeter_t that
 * is initialized with the recommended default values.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_SPOTMETER_CMD(cmd);
 *  // The variable cmd is of type LS_Spotmeter_t and is initialized
 *  // with the recommended defaults from LS_spotmeterDefault.
 *  ...
 * }
 * @endcode
 */
#define LS_SPOTMETER_CMD(X)  LS_Spotmeter_t X = LS_spotmeterDefault;

/* ----------------------------------------------------------------------------------------------- */

/**
 * @ingroup SDKCoreDEFAULT_GRP
 * @brief LS_rectangularSpotmeterDefault
 *
 * This const value represents an @ref LS_RectangularSpotmeter_t struct filled with the
 * recommended default values.
 *
 * Please use the macro @ref LS_RECTANGULARSPOTMETER_CMD to define and initialize variables of type \a LS_RectangularSpotmeter_t.
 */
LS_IMPORT
LS_RectangularSpotmeter_t LS_rectangularSpotmeterDefault;

/**
 * @ingroup SDKCoreMACROS_GRP
 * @brief LS_RECTANGULARSPOTMETER_CMD
 *
 * This macros can be used to define an variable of type \a LS_RectangularSpotmeter_t that
 * is initialized with the recommended default values.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_RECTANGULARSPOTMETER_CMD(cmd);
 *  // The variable cmd is of type LS_RectangularSpotmeter_t and is initialized
 *  // with the recommended defaults from LS_rectangularSpotmeterDefault.
 *  ...
 * }
 * @endcode
 */
#define LS_RECTANGULARSPOTMETER_CMD(X)  LS_RectangularSpotmeter_t X = LS_rectangularSpotmeterDefault;

/* ----------------------------------------------------------------------------------------------- */

/**
 * @ingroup SDKCoreDEFAULT_GRP
 * @brief LS_lineProfileDefault
 *
 * This const value represents an @ref LS_LineProfile_t struct filled with the
 * recommended default values.
 *
 * Please use the macro @ref LS_LINEPROFILE_CMD to define and initialize variables of type \a LS_LineProfile_t.
 */
LS_IMPORT
LS_LineProfile_t LS_lineProfileDefault;

/**
 * @ingroup SDKCoreMACROS_GRP
 * @brief LS_LINEPROFILE_CMD
 *
 * This macros can be used to define an variable of type \a LS_LineProfile_t that
 * is initialized with the recommended default values.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_LINEPROFILE_CMD(cmd);
 *  // The variable cmd is of type LS_LineProfile_t and is initialized
 *  // with the recommended defaults from LS_lineProfileDefault.
 *  ...
 * }
 * @endcode
 */
#define LS_LINEPROFILE_CMD(X)  LS_LineProfile_t X = LS_lineProfileDefault;


/* ----------------------------------------------------------------------------------------------- */

/**
 * @ingroup SDKCoreDEFAULT_GRP
 * @brief LS_addLineProfileDefault
 *
 * This const value represents an @ref LS_AddLineProfile_t struct filled with
 * the recommended default values.
 *
 * Please use the macro @ref LS_ADD_LINE_PROFILE_CMD to define and initialize variables of type \a LS_AddLineProfile_t.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_ADD_LINE_PROFILE_CMD(addLineProfileCmd);
 *  ...
 * }
 * @endcode
 */
LS_IMPORT
LS_AddLineProfile_t LS_addLineProfileDefault;

/**
 * @ingroup SDKCoreMACROS_GRP
 * @brief LS_ADD_LINE_PROFILE_CMD
 *
 * This macros can be used to define an variable of type \a LS_AddLineProfile_t that
 * is initialized with the recommended default values.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_ADD_LINE_PROFILE_CMD(cmd);
 *  // The variable cmd is of type LS_AddLineProfile_t and is initialized
 *  // with the recommended defaults from LS_addLineProfileDefault.
 *  ...
 * }
 * @endcode
 */
#define LS_ADD_LINE_PROFILE_CMD(X)  LS_AddLineProfile_t X = LS_addLineProfileDefault;

/* ----------------------------------------------------------------------------------------------- */

/**
 * @ingroup SDKCoreDEFAULT_GRP
 * @brief LS_addBrightDarkAnalysisDefault
 *
 * This const value represents an @ref LS_AddBrightDarkAnalysis_t struct filled with
 * the recommended default values.
 *
 * Please use the macro @ref LS_ADD_BRIGHT_DARK_ANALYSIS_CMD to define and initialize variables of type \a LS_AddBrightDarkAnalysis_t.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_ADD_BRIGHT_DARK_ANALYSIS_CMD(addBrightDarkAnalysisCmd);
 *  ...
 * }
 * @endcode
 */
LS_IMPORT
LS_AddBrightDarkAnalysis_t LS_addBrightDarkAnalysisDefault;

/**
 * @ingroup SDKCoreMACROS_GRP
 * @brief LS_ADD_BRIGHT_DARK_ANALYSIS_CMD
 *
 * This macros can be used to define an variable of type \a LS_AddBrightDarkAnalysis_t that
 * is initialized with the recommended default values.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_ADD_BRIGHT_DARK_ANALYSIS_CMD(cmd);
 *  // The variable cmd is of type LS_AddBrightDarkAnalysis_t and is initialized
 *  // with the recommended defaults from LS_addBrightDarkAnaysisDefault.
 *  ...
 * }
 * @endcode
 */
#define LS_ADD_BRIGHT_DARK_ANALYSIS_CMD(X)  LS_AddBrightDarkAnalysis_t X = LS_addBrightDarkAnalysisDefault;

/* ----------------------------------------------------------------------------------------------- */

/**
 * @ingroup SDKCoreDEFAULT_GRP
 * @brief LS_addSlantedEdgeAnalysisDefault
 *
 * This const value represents an @ref LS_AddSlantedEdgeAnalysis_t struct filled with
 * the recommended default values.
 *
 * Please use the macro @ref LS_ADD_SLANTED_EDGE_ANALYSIS_CMD to define and initialize variables of type \a LS_AddSlantedEdgeAnalysis_t.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_ADD_SLANTED_EDGE_ANALYSIS_CMD(addSlantedEdgeAnalysisCmd);
 *  ...
 * }
 * @endcode
 */
LS_IMPORT
LS_AddSlantedEdgeAnalysis_t LS_addSlantedEdgeAnalysisDefault;

/**
 * @ingroup SDKCoreMACROS_GRP
 * @brief LS_ADD_SLANTED_EDGE_ANALYSIS_CMD
 *
 * This macros can be used to define an variable of type \a LS_AddSlantedEdgeAnalysis_t that
 * is initialized with the recommended default values.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_ADD_SLANTED_EDGE_ANALYSIS_CMD(cmd);
 *  // The variable cmd is of type LS_AddSlantedEdgeAnalysis_t and is initialized
 *  // with the recommended defaults from LS_addBrightDarkAnaysisDefault.
 *  ...
 * }
 * @endcode
 */
#define LS_ADD_SLANTED_EDGE_ANALYSIS_CMD(X)  LS_AddSlantedEdgeAnalysis_t X = LS_addSlantedEdgeAnalysisDefault;

/* ----------------------------------------------------------------------------------------------- */

/**
 * @ingroup SDKCoreDEFAULT_GRP
 * @brief LS_getSlantedEdgeResultInfoDefault
 *
 * This const value represents an @ref LS_GetSlantedEdgeResultInfo_t struct filled with
 * the recommended default values.
 *
 * Please use the macro @ref LS_GET_SLANTED_EDGE_RESULT_INFO_CMD to define and initialize variables of type \a LS_getSlantedEdgeResultInfoDefault.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_GET_SLANTED_EDGE_RESULT_INFO_CMD(getSlantedEdgeResultInfoCmd);
 *  ...
 * }
 * @endcode
 */
LS_IMPORT
LS_GetSlantedEdgeResultInfo_t LS_getSlantedEdgeResultInfoDefault;

/**
 * @ingroup SDKCoreMACROS_GRP
 * @brief LS_GET_SLANTED_EDGE_RESULT_INFO_CMD
 *
 * This macros can be used to define an variable of type \a LS_GetSlantedEdgeResultInfo_t that
 * is initialized with the recommended default values.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_GET_SLANTED_EDGE_RESULT_INFO_CMD(cmd);
 *  // The variable cmd is of type LS_GetSlantedEdgeResultInfo_t and is initialized
 *  // with the recommended defaults from LS_getSlantedEdgeResultInfoDefault.
 *  ...
 * }
 * @endcode
 */
#define LS_GET_SLANTED_EDGE_RESULT_INFO_CMD(X)  LS_GetSlantedEdgeResultInfo_t X = LS_getSlantedEdgeResultInfoDefault;

/* ----------------------------------------------------------------------------------------------- */

/**
 * @ingroup SDKCoreDEFAULT_GRP
 * @brief LS_getSlantedEdgeResultDefault
 *
 * This const value represents an @ref LS_GetSlantedEdgeResult_t struct filled with
 * the recommended default values.
 *
 * Please use the macro @ref LS_GET_SLANTED_EDGE_RESULT_CMD to define and initialize variables of type \a LS_getSlantedEdgeResultDefault.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_GET_SLANTED_EDGE_RESULT_CMD(getSlantedEdgeResultCmd);
 *  ...
 * }
 * @endcode
 */
LS_IMPORT
LS_GetSlantedEdgeResult_t LS_getSlantedEdgeResultDefault;

/**
 * @ingroup SDKCoreMACROS_GRP
 * @brief LS_GET_SLANTED_EDGE_RESULT_CMD
 *
 * This macros can be used to define an variable of type \a LS_GetSlantedEdgeResult_t that
 * is initialized with the recommended default values.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_GET_SLANTED_EDGE_RESULT_CMD(cmd);
 *  // The variable cmd is of type LS_GetSlantedEdgeResult_t and is initialized
 *  // with the recommended defaults from LS_getSlantedEdgeResultDefault.
 *  ...
 * }
 * @endcode
 */
#define LS_GET_SLANTED_EDGE_RESULT_CMD(X)  LS_GetSlantedEdgeResult_t X = LS_getSlantedEdgeResultDefault;

/* ----------------------------------------------------------------------------------------------- */

/**
 * @internal
 * @ingroup SDKCoreDEFAULT_GRP
 * @brief LS_addFourierSharpnessAnalysisDefault
 *
 * This const value represents an @ref LS_AddFourierSharpnessAnalysis_t struct filled with
 * the recommended default values.
 *
 * Please use the macro @ref LS_ADD_FOURIER_SHARPNESS_ANALYSIS_CMD to define and initialize variables of type \a LS_AddFourierSharpnessAnalysis_t.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_ADD_FOURIER_SHARPNESS_ANALYSIS_CMD(cmd);
 *  ...
 * }
 * @endcode
 */
LS_IMPORT
LS_AddFourierSharpnessAnalysis_t LS_addFourierSharpnessAnalysisDefault;

/**
 * @internal
 * @ingroup SDKCoreMACROS_GRP
 * @brief LS_ADD_FOURIER_SHARPNESS_ANALYSIS_CMD
 *
 * This macros can be used to define an variable of type \a LS_AddFourierSharpnessAnalysis_t that
 * is initialized with the recommended default values.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_ADD_FOURIER_SHARPNESS_ANALYSIS_CMD(cmd);
 *  // The variable cmd is of type LS_AddFourierSharpnessAnalysis_t and is initialized
 *  // with the recommended defaults from LS_addFourierSharpnessAnalysisDefault.
 *  ...
 * }
 * @endcode
 */
#define LS_ADD_FOURIER_SHARPNESS_ANALYSIS_CMD(X)  LS_AddFourierSharpnessAnalysis_t X = LS_addFourierSharpnessAnalysisDefault;

/* ----------------------------------------------------------------------------------------------- */

/**
 * @internal
 * @ingroup SDKCoreDEFAULT_GRP
 * @brief LS_getFourierSharpnessResultDefault
 *
 * This const value represents an @ref LS_GetFourierSharpnessResult_t struct filled with
 * the recommended default values.
 *
 * Please use the macro @ref LS_GET_FOURIER_SHARPNESS_RESULT_CMD to define and initialize variables of type \a LS_GetFourierSharpnessResult_t.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_GET_FOURIER_SHARPNESS_RESULT_CMD(cmd);
 *  ...
 * }
 * @endcode
 */
LS_IMPORT
LS_GetFourierSharpnessResult_t LS_getFourierSharpnessResultDefault;

/**
 * @internal
 * @ingroup SDKCoreMACROS_GRP
 * @brief LS_GET_FOURIER_SHARPNESS_RESULT_CMD
 *
 * This macros can be used to define an variable of type \a LS_GetFourierSharpnessResult_t that
 * is initialized with the recommended default values.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_GET_FOURIER_SHARPNESS_RESULT_CMD(cmd);
 *  // The variable cmd is of type LS_GetFourierSharpnessResult_t and is initialized
 *  // with the recommended defaults from LS_getFourierSharpnessResultDefault.
 *  ...
 * }
 * @endcode
 */
#define LS_GET_FOURIER_SHARPNESS_RESULT_CMD(X)  LS_GetFourierSharpnessResult_t X = LS_getFourierSharpnessResultDefault;

/* ----------------------------------------------------------------------------------------------- */

/**
 * @ingroup SDKCoreDEFAULT_GRP
 * @brief LS_getGridOfSpotmetersInfoDefault
 *
 * This const value represents an @ref LS_GetGridOfSpotmetersInfo_t struct filled with
 * the recommended default values.
 *
 * Please use the macro @ref LS_GET_GRID_OF_SPOTMETERS_INFO_CMD to define and initialize variables of type \a LS_GetGridOfSpotmetersInfo_t.
 *
 */
LS_IMPORT
LS_GetGridOfSpotmetersInfo_t LS_getGridOfSpotmetersInfoDefault;

/**
 * @ingroup SDKCoreMACROS_GRP
 * @brief LS_GET_GRID_OF_SPOTMETERS_INFO_CMD
 *
 * This macros can be used to define an variable of type \a LS_GetGridOfSpotmetersInfo_t that
 * is initialized with the recommended default values.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_GET_GRID_OF_SPOTMETERS_INFO_CMD(cmd);
 *  // The variable cmd is of type LS_GetGridOfSpotmetersInfo_t and is initialized
 *  // with the recommended defaults from LS_getGridOfSpotmetersInfoDefault.
 *  ...
 * }
 * @endcode
 */
#define LS_GET_GRID_OF_SPOTMETERS_INFO_CMD(X)  LS_GetGridOfSpotmetersInfo_t X = LS_getGridOfSpotmetersInfoDefault;

/* ----------------------------------------------------------------------------------------------- */

/**
 * @ingroup SDKCoreDEFAULT_GRP
 * @brief LS_getGridOfSpotmetersResultDefault
 *
 * This const value represents an @ref LS_GetGridOfSpotmetersResult_t struct filled with
 * the recommended default values.
 *
 * Please use the macro @ref LS_GET_GRID_OF_SPOTMETERS_RESULT_CMD to define and initialize variables of type \a LS_GetGridOfSpotmetersResult_t.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_GET_GRID_OF_SPOTMETERS_RESULT_CMD(cmd);
 *  ...
 * }
 * @endcode
 */
LS_IMPORT
LS_GetGridOfSpotmetersResult_t LS_getGridOfSpotmetersResultDefault;

/**
 * @ingroup SDKCoreMACROS_GRP
 * @brief LS_GET_GRID_OF_SPOTMETERS_RESULT_CMD
 *
 * This macros can be used to define an variable of type \a LS_GetGridOfSpotmetersResult_t that
 * is initialized with the recommended default values.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_GET_GRID_OF_SPOTMETERS_RESULT_CMD(cmd);
 *  // The variable cmd is of type LS_GetGridOfSpotmetersResult_t and is initialized
 *  // with the recommended defaults from LS_getGridOfSpotmetersResultDefault.
 *  ...
 * }
 * @endcode
 */
#define LS_GET_GRID_OF_SPOTMETERS_RESULT_CMD(X)  LS_GetGridOfSpotmetersResult_t X = LS_getGridOfSpotmetersResultDefault;

/* ----------------------------------------------------------------------------------------------- */

/**
 * @ingroup SDKCoreDEFAULT_GRP
 * @brief LS_getSingleSlantedEdgeResultDefault
 *
 * This const value represents an @ref LS_GetSingleSlantedEdgeResult_t struct filled with
 * the recommended default values.
 *
 * Please use the macro @ref LS_GET_SINGLE_SLANTED_EDGE_RESULT_CMD to define and initialize variables of type \a LS_GetSingleSlantedEdgeResult_t.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_GET_SINGLE_SLANTED_EDGE_RESULT_CMD(cmd);
 *  ...
 * }
 * @endcode
 */
LS_IMPORT
LS_GetSingleSlantedEdgeResult_t LS_getSingleSlantedEdgeResultDefault;

/**
 * @ingroup SDKCoreMACROS_GRP
 * @brief LS_GET_SINGLE_SLANTED_EDGE_RESULT_CMD
 *
 * This macros can be used to define an variable of type \a LS_GetSingleSlantedEdgeResult_t that
 * is initialized with the recommended default values.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_GET_SINGLE_SLANTED_EDGE_RESULT_CMD(cmd);
 *  // The variable cmd is of type LS_GetSingleSlantedEdgeResult_t and is initialized
 *  // with the recommended defaults from LS_getSingleSlantedEdgeResultDefault.
 *  ...
 * }
 * @endcode
 */
#define LS_GET_SINGLE_SLANTED_EDGE_RESULT_CMD(X)  LS_GetSingleSlantedEdgeResult_t X = LS_getSingleSlantedEdgeResultDefault;

/* ----------------------------------------------------------------------------------------------- */

/**
 * @ingroup SDKCoreDEFAULT_GRP
 * @brief LS_addSpotmeterDefault
 *
 * This const value represents an @ref LS_AddSpotmeter_t struct filled with
 * the recommended default values.
 *
 * Please use the macro @ref LS_ADD_SPOTMETER_CMD to define and initialize variables of type \a LS_AddSpotmeter_t.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_ADD_SPOTMETER_CMD(cmd);
 *  ...
 * }
 * @endcode
 */
LS_IMPORT
LS_AddSpotmeter_t LS_addSpotmeterDefault;

/**
 * @ingroup SDKCoreMACROS_GRP
 * @brief LS_ADD_SPOTMETER_CMD
 *
 * This macros can be used to define an variable of type \a LS_AddSpotmeter_t that
 * is initialized with the recommended default values.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_ADD_SPOTMETER_CMD(cmd);
 *  // The variable cmd is of type LS_AddSpotmeter_t and is initialized
 *  // with the recommended defaults from LS_addSpotmeterDefault.
 *  ...
 * }
 * @endcode
 */
#define LS_ADD_SPOTMETER_CMD(X)  LS_AddSpotmeter_t X = LS_addSpotmeterDefault;

/* ----------------------------------------------------------------------------------------------- */

/**
 * @ingroup SDKCoreDEFAULT_GRP
 * @brief LS_addGridOfSpotmetersDefault
 *
 * This const value represents an @ref LS_AddGridOfSpotmeters_t struct filled with
 * the recommended default values.
 *
 * Please use the macro @ref LS_ADD_GRID_OF_SPOTMETERS_CMD to define and initialize variables of type \a LS_AddGridOfSpotmeters_t.
 *
 */

LS_IMPORT
LS_AddGridOfSpotmeters_t LS_addGridOfSpotmetersDefault;

/**
 * @ingroup SDKCoreMACROS_GRP
 * @brief LS_ADD_GRID_OF_SPOTMETERS_CMD
 *
 * This macros can be used to define an variable of type \a LS_AddGridOfSpotmeters_t that
 * is initialized with the recommended default values.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_ADD_GRID_OF_SPOTMETERS_CMD(cmd);
 *  // The variable cmd is of type LS_AddGridOfSpotmeters_t and is initialized
 *  // with the recommended defaults from LS_addGridOfSpotmetersDefault.
 *  ...
 * }
 * @endcode
 */
#define LS_ADD_GRID_OF_SPOTMETERS_CMD(X)  LS_AddGridOfSpotmeters_t X = LS_addGridOfSpotmetersDefault;

/* ----------------------------------------------------------------------------------------------- */

/**
 * @ingroup SDKCoreDEFAULT_GRP
 * @brief LS_addRectangularSpotmeterDefault
 *
 * This const value represents an @ref LS_AddRectangularSpotmeter_t struct filled with
 * the recommended default values.
 *
 * Please use the macro @ref LS_ADD_RECTANGULARSPOTMETER_CMD to define and initialize variables of type \a LS_AddRectangularSpotmeter_t.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_ADD_RECTANGULARSPOTMETER_CMD(cmd);
 *  ...
 * }
 * @endcode
 */
LS_IMPORT
LS_AddRectangularSpotmeter_t LS_addRectangularSpotmeterDefault;

/**
 * @ingroup SDKCoreMACROS_GRP
 * @brief LS_ADD_RECTANGULARSPOTMETER_CMD
 *
 * This macros can be used to define an variable of type \a LS_AddRectangularSpotmeter_t that
 * is initialized with the recommended default values.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_ADD_RECTANGULARSPOTMETER_CMD(cmd);
 *  // The variable cmd is of type LS_AddRectangularSpotmeter_t and is initialized
 *  // with the recommended defaults from LS_addRectangularSpotmeterDefault.
 *  ...
 * }
 * @endcode
 */
#define LS_ADD_RECTANGULARSPOTMETER_CMD(X)  LS_AddRectangularSpotmeter_t X = LS_addRectangularSpotmeterDefault;

/* ----------------------------------------------------------------------------------------------- */

/**
 * @ingroup SDKCoreDEFAULT_GRP
 * @brief LS_addEllipticalSpotmeterDefault
 *
 * This const value represents an @ref LS_AddEllipticalSpotmeter_t struct filled with
 * the recommended default values.
 *
 * Please use the macro @ref LS_ADD_ELLIPTICALSPOTMETER_CMD to define and initialize variables of type \a LS_AddEllipticalSpotmeter_t.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_ADD_ELLIPTICALSPOTMETER_CMD(cmd);
 *  ...
 * }
 * @endcode
 */
LS_IMPORT
LS_AddEllipticalSpotmeter_t LS_addEllipticalSpotmeterDefault;

/**
 * @ingroup SDKCoreMACROS_GRP
 * @brief LS_ADD_ELLIPTICALSPOTMETER_CMD
 *
 * This macros can be used to define an variable of type \a LS_AddEllipticalSpotmeter_t that
 * is initialized with the recommended default values.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_ADD_ELLIPTICALSPOTMETER_CMD(cmd);
 *  // The variable cmd is of type LS_AddEllipticalSpotmeter_t and is initialized
 *  // with the recommended defaults from LS_addEllipticalSpotmeterDefault.
 *  ...
 * }
 * @endcode
 */
#define LS_ADD_ELLIPTICALSPOTMETER_CMD(X)  LS_AddEllipticalSpotmeter_t X = LS_addEllipticalSpotmeterDefault;


/* ----------------------------------------------------------------------------------------------- */

/**
 * @ingroup SDKCoreDEFAULT_GRP
 * @brief LS_calculateSpotmeterDefault
 *
 * This const value represents an @ref LS_CalculateSpotmeter_t struct filled with
 * the recommended default values.
 *
 * Please use the macro @ref LS_CALCULATE_SPOTMETER_CMD to define and initialize variables of type \a LS_CalculateSpotmeter_t.
 */
LS_IMPORT
LS_CalculateSpotmeter_t LS_calculateSpotmeterDefault;

/**
 * @ingroup SDKCoreMACROS_GRP
 * @brief LS_CALCULATE_SPOTMETER_CMD
 *
 * This macros can be used to define an variable of type \a LS_CalculateSpotmeter_t that
 * is initialized with the recommended default values.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_CALCULATE_SPOTMETER_CMD(cmd);
 *  // The variable cmd is of type LS_CalculateSpotmeter_t and is initialized
 *  // with the recommended defaults from LS_calculateSpotmeterDefault.
 *  ...
 * }
 * @endcode *
 */
#define LS_CALCULATE_SPOTMETER_CMD(X)  LS_CalculateSpotmeter_t X = LS_calculateSpotmeterDefault;

/* ----------------------------------------------------------------------------------------------- */

/**
 * @ingroup SDKCoreDEFAULT_GRP
 * @brief LS_GetImageInfoDefault
 *
 * This const value represents an @ref LS_GetImageInfo_t struct filled with
 * the recommended default values.
 *
 * Please use the macro @ref LS_GET_IMAGE_INFO_CMD to define and initialize variables of type \a LS_GetImageInfo_t.
 */
LS_IMPORT
LS_GetImageInfo_t LS_getImageInfoDefault;

/**
 * @ingroup SDKCoreMACROS_GRP
 * @brief LS_GET_IMAGE_INFO_CMD
 *
 * This macros can be used to define an variable of type \a LS_GetImageInfo_t that
 * is initialized with the recommended default values.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_GET_IMAGE_INFO_CMD(cmd);
 *  // The variable cmd is of type LS_GetImageInfo_t and is initialized
 *  // with the recommended defaults from LS_imageInfoDefault.
 *  ...
 * }
 * @endcode
 */
#define LS_GET_IMAGE_INFO_CMD(X) LS_GetImageInfo_t X = LS_getImageInfoDefault;

/* ----------------------------------------------------------------------------------------------- */

/**
 * @ingroup SDKCoreDEFAULT_GRP
 * @brief LS_getImageDefault
 *
 * This const value represents an @ref LS_GetImage_t struct filled with
 * the recommended default values.
 *
 * Please use the macro @ref LS_GET_IMAGE_CMD to define and initialize variables of type \a LS_GetImage_t.
 */
LS_IMPORT
LS_GetImage_t LS_getImageDefault;

/**
 * @ingroup SDKCoreMACROS_GRP
 * @brief LS_GET_IMAGE_CMD
 *
 * This macros can be used to define an variable of type \a LS_GetImage_t that
 * is initialized with the recommended default values.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_GET_IMAGE_CMD(cmd);
 *  // The variable cmd is of type LS_GetImage_t and is initialized
 *  // with the recommended defaults from LS_getImageDefault
 *  ...
 * }
 * @endcode
 */
#define LS_GET_IMAGE_CMD(X) LS_GetImage_t X = LS_getImageDefault;

/* ----------------------------------------------------------------------------------------------- */

/**
 * @ingroup SDKCoreDEFAULT_GRP
 * @brief LS_getSpotmeterResultDefault
 *
 * This const value represents an @ref LS_GetSpotmeterResult_t struct filled with
 * the recommended default values.
 *
 * Please use the macro @ref LS_GET_SPOTMETER_RESULT_CMD to define and initialize variables of type \a LS_GetSpotmeterResult_t.
 */
LS_IMPORT
LS_GetSpotmeterResult_t LS_getSpotmeterResultDefault;

/**
 * @ingroup SDKCoreMACROS_GRP
 * @brief LS_GET_SPOTMETER_RESULT_CMD
 *
 * This macros can be used to define an variable of type \a LS_GetSpotmeterResult_t that
 * is initialized with the recommended default values.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_GET_SPOTMETER_RESULT_CMD(getSpotmeterCmd);
 *  // The variable getSpotmeterCmd is of type LS_GetSpotmeterResult_t and is initialized
 *  // with the recommended defaults from LS_getSpotmeterResultDefault
 *  ...
 * }
 * @endcode
 */
#define LS_GET_SPOTMETER_RESULT_CMD(X) LS_GetSpotmeterResult_t X = LS_getSpotmeterResultDefault;

/* ----------------------------------------------------------------------------------------------- */

/**
 * @ingroup SDKCoreDEFAULT_GRP
 * @brief LS_getLineProfileResultInfoDefault
 *
 * This const value represents an @ref LS_GetLineProfileResultInfo_t struct filled with
 * the recommended default values.
 *
 * Please use the macro @ref LS_GET_LINE_PROFILE_RESULT_INFO_CMD to define and initialize variables of type \a LS_GetLineProfileResultInfo_t.
 */
LS_IMPORT
LS_GetLineProfileResultInfo_t LS_getLineProfileResultInfoDefault;

/**
 * @ingroup SDKCoreMACROS_GRP
 * @brief LS_GET_LINE_PROFILE_RESULT_INFO_CMD
 *
 * This macros can be used to define an variable of type \a LS_GetLineProfileResultInfo_t that
 * is initialized with the recommended default values.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_GET_LINE_PROFILE_RESULT_INFO_CMD(cmd);
 *  // The variable cmd is of type LS_GetLineProfileResultInfo_t and is initialized
 *  // with the recommended defaults from LS_lineProfileResultInfoDefault
 *  ...
 * }
 * @endcode
 */
#define LS_GET_LINE_PROFILE_RESULT_INFO_CMD(X) LS_GetLineProfileResultInfo_t X = LS_getLineProfileResultInfoDefault;

/* ----------------------------------------------------------------------------------------------- */

/**
 * @ingroup SDKCoreDEFAULT_GRP
 * @brief LS_GetLineProfileResultDefault
 *
 * This const value represents an @ref LS_GetLineProfileResult_t struct filled with
 * the recommended default values.
 *
 * Please use the macro @ref LS_GET_LINE_PROFILE_RESULT_CMD to define and initialize variables of type \a LS_GetLineProfileResult_t.
 */
LS_IMPORT
LS_GetLineProfileResult_t LS_getLineProfileResultDefault;

/**
 * @ingroup SDKCoreMACROS_GRP
 * @brief LS_GET_LINE_PROFILE_RESULT_CMD
 *
 * This macros can be used to define an variable of type \a LS_GetLineProfileResult_t that
 * is initialized with the recommended default values.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_GET_LINE_PROFILE_RESULT_CMD(cmd);
 *  // The variable cmd is of type LS_GetLineProfileResult_t and is initialized
 *  // with the recommended defaults from LS_getLineProfileResultDefault
 *  ...
 * }
 * @endcode
 */
#define LS_GET_LINE_PROFILE_RESULT_CMD(X) LS_GetLineProfileResult_t X = LS_getLineProfileResultDefault;

/* ----------------------------------------------------------------------------------------------- */

/**
 * @ingroup SDKCoreDEFAULT_GRP
 * @brief LS_brightDarkAnalysisResultDefault
 *
 * This const value represents an @ref LS_GetBrightDarkAnalysisResult_t struct filled with
 * the recommended default values.
 *
 * Please use the macro @ref LS_GET_BRIGHT_DARK_ANALYSIS_RESULT_CMD to define and initialize variables of type \a LS_GetBrightDarkAnalysisResult_t.
 */
LS_IMPORT
LS_GetBrightDarkAnalysisResult_t LS_getBrightDarkAnalysisResultDefault;

/**
 * @ingroup SDKCoreMACROS_GRP
 * @brief LS_GET_BRIGHT_DARK_ANALYSIS_RESULT_CMD
 *
 * This macros can be used to define an variable of type \a LS_GetBrightDarkAnalysisResult_t that
 * is initialized with the recommended default values.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_GET_BRIGHT_DARK_ANALYSIS_RESULT_CMD(cmd);
 *  // The variable cmd is of type LS_GetBrightDarkAnalysisResult_t and is initialized
 *  // with the recommended defaults from LS_brightDarkAnalysisResultDefault
 *  ...
 * }
 * @endcode
 */
#define LS_GET_BRIGHT_DARK_ANALYSIS_RESULT_CMD(X) LS_GetBrightDarkAnalysisResult_t X = LS_getBrightDarkAnalysisResultDefault;

/* ----------------------------------------------------------------------------------------------- */

/**
 * @ingroup SDKCoreDEFAULT_GRP
 * @brief LS_rotateImage90DegreeStepsDefault
 *
 * This const value represents an @ref LS_RotateImage90DegreeSteps_t struct filled with
 * the recommended default values.
 *
 * Please use the macro @ref LS_ROTATE_IMAGE_90DEGREE_STEPS_CMD to define and initialize variables of type \a LS_RotateImage90DegreeSteps_t.
 */
LS_IMPORT
LS_RotateImage90DegreeSteps_t LS_rotateImage90DegreeStepsDefault;

/**
 * @ingroup SDKCoreMACROS_GRP
 * @brief LS_ROTATE_IMAGE_90DEGREE_STEPS_CMD
 *
 * This macros can be used to define an variable of type \a LS_RotateImage90DegreeSteps_t that
 * is initialized with the recommended default values.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_ROTATE_IMAGE_90DEGREE_STEPS_CMD(cmd);
 *  // The variable cmd is of type LS_RotateImage90DegreeSteps_t and is initialized
 *  // with the recommended defaults from LS_rotateImage90DegreeStepsDefault
 *  ...
 * }
 * @endcode
 */
#define LS_ROTATE_IMAGE_90DEGREE_STEPS_CMD(X) LS_RotateImage90DegreeSteps_t X = LS_rotateImage90DegreeStepsDefault;

/* ----------------------------------------------------------------------------------------------- */

/**
 * @ingroup SDKCoreDEFAULT_GRP
 * @brief LS_rotateImageDefault
 *
 * This const value represents an @ref LS_RotateImage_t struct filled with
 * the recommended default values.
 *
 * Please use the macro @ref LS_ROTATE_IMAGE_CMD to define and initialize variables of type \a LS_RotateImage_t.
 */
LS_IMPORT
LS_RotateImage_t LS_rotateImageDefault;

/**
 * @ingroup SDKCoreMACROS_GRP
 * @brief LS_ROTATE_IMAGE_CMD
 *
 * This macros can be used to define an variable of type \a LS_RotateImage_t that
 * is initialized with the recommended default values.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_ROTATE_IMAGE_CMD(cmd);
 *  // The variable cmd is of type LS_RotateImage_t and is initialized
 *  // with the recommended defaults from LS_rotateImageDefault
 *  ...
 * }
 * @endcode
 */
#define LS_ROTATE_IAMGE_CMD(X) LS_RotateImage_t X = LS_rotateImageDefault;

/* ----------------------------------------------------------------------------------------------- */

/**
 * @ingroup SDKCoreDEFAULT_GRP
 * @brief LS_loadRecipeDefault
 *
 * This const value represents an @ref LS_LoadRecipe_t struct filled with
 * the recommended default values.
 *
 * Please use the macro @ref LS_LOAD_RECIPE_CMD to define and initialize variables of type \a LS_LoadRecipe_t.
 */
LS_IMPORT
LS_LoadRecipe_t LS_loadRecipeDefault;

/**
 * @ingroup SDKCoreMACROS_GRP
 * @brief LS_LOAD_RECIPE_CMD
 *
 * This macros can be used to define an variable of type \a LS_LoadRecipe_t that
 * is initialized with the recommended default values.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_LOAD_RECIPE_CMD(cmd);
 *  // The variable cmd is of type LS_LoadRecipe_t and is initialized
 *  // with the recommended defaults from LS_loadRecipeDefault
 *  ...
 * }
 * @endcode
 */
#define LS_LOAD_RECIPE_CMD(X) LS_LoadRecipe_t X = LS_loadRecipeDefault;

/* ----------------------------------------------------------------------------------------------- */

/**
 * @ingroup SDKCoreDEFAULT_GRP
 * @brief LS_executeDefault
 *
 * This const value represents an @ref LS_Execute_t struct filled with
 * the recommended default values.
 *
 * Please use the macro @ref LS_EXECUTE_CMD to define and initialize variables of type \a LS_Execute_t.
 */
LS_IMPORT
LS_Execute_t LS_executeDefault;

/**
 * @ingroup SDKCoreMACROS_GRP
 * @brief LS_EXECUTE_CMD
 *
 * This macros can be used to define an variable of type \a LS_Execute_t that
 * is initialized with the recommended default values.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_EXECUTE_CMD(cmd);
 *  // The variable cmd is of type LS_Execute_t and is initialized
 *  // with the recommended defaults from LS_executeDefault
 *  ...
 * }
 * @endcode
 */
#define LS_EXECUTE_CMD(X) LS_Execute_t X = LS_executeDefault;

/* ----------------------------------------------------------------------------------------------- */

/**
 * @ingroup SDKCoreDEFAULT_GRP
 * @brief LS_analysisTypeDefault
 *
 * This const value represents an @ref LS_GetAnalysisType_t struct filled with
 * the recommended default values.
 *
 * Please use the macro @ref LS_GET_ANALYSIS_TYPE_CMD to define and initialize variables of type \a LS_GetAnalysisType_t.
 */
LS_IMPORT
LS_GetAnalysisType_t LS_getAnalysisTypeDefault;

/**
 * @ingroup SDKCoreMACROS_GRP
 * @brief LS_GET_ANALYSIS_TYPE_CMD
 *
 * This macros can be used to define an variable of type \a LS_GetAnalysisType_t that
 * is initialized with the recommended default values.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_GET_ANALYSIS_TYPE_CMD(cmd);
 *  // The variable cmd is of type LS_GetAnalysisType_t and is initialized
 *  // with the recommended defaults from LS_analysisTypeDefault
 *  ...
 * }
 * @endcode
 */
#define LS_GET_ANALYSIS_TYPE_CMD(X) LS_GetAnalysisType_t X = LS_getAnalysisTypeDefault;

/* ----------------------------------------------------------------------------------------------- */

/**
 * @ingroup SDKCoreDEFAULT_GRP
 * @brief LS_2dBinningDefault
 *
 * This const value represents an @ref LS_2dBinning_t struct filled with default values.
 *
 * Please use the @ref LS_2DBINNING_CMD macro to define and initialize variables of type \a LS_2dBinning_t.
 *
 */
LS_IMPORT
LS_2dBinning_t LS_2dBinningDefault;

/**
 * @ingroup SDKCoreMACROS_GRP
 * @brief LS_2DBINNING_CMD
 *
 * This macros can be used to define a variable of type \a LS_2dBinning_t that
 * is initialized with the recommended default values.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_2DBINNING_CMD(cmd);
 *  // The variable cmd is of type LS_2dBinning_t and is initialized
 *  // with the recommended defaults from LS_2dBinningDefault
 *  ...
 * }
 * @endcode
 */
#define LS_2DBINNING_CMD(X)  LS_2dBinning_t X = LS_2dBinningDefault;

/* ----------------------------------------------------------------------------------------------- */

/**
 * @ingroup SDKCoreDEFAULT_GRP
 * @brief LS_SDK_InitDefault
 *
 * This const value represents an @ref LS_SDK_Init_t struct filled with default values.
 *
 * Please use the @ref LS_SDK_INIT_CMD macro to define and initialize variables of type \a LS_SDK_Init_t.
 *
 */
LS_IMPORT
LS_SDK_Init_t LS_SDK_InitDefault;

/**
 * @ingroup SDKCoreMACROS_GRP
 * @brief LS_SDK_INIT_CMD
 *
 * This macros can be used to define a variable of type \a LS_SDK_Init_t that
 * is initialized with the recommended default values.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_SDK_INIT_CMD(cmd);
 *  // The variable cmd is of type LS_SDK_Init_t and is initialized
 *  // with the recommended defaults from LS_SDK_InitDefault
 *  ...
 * }
 * @endcode
 */
#define LS_SDK_INIT_CMD(X)  LS_SDK_Init_t X = LS_SDK_InitDefault;


/* ----------------------------------------------------------------------------------------------- */

/**
 * @ingroup SDKCoreDEFAULT_GRP
 * @brief LS_loadProjDefault
 *
 * This const value represents an @ref LS_LoadProj_t struct filled with default values.
 *
 * Please use the @ref LS_LOADPROJ_CMD macro to define and initialize variables of type \a LS_LoadProj_t.
 *
 */
LS_IMPORT
LS_LoadProj_t LS_loadProjDefault;

/**
 * @ingroup SDKCoreMACROS_GRP
 * @brief LS_LOADPROJ_CMD
 *
 * This macros can be used to define a variable of type \a LS_LoadProj_t that
 * is initialized with the recommended default values.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_LOADPROJ_CMD(cmd);
 *  // The variable cmd is of type LS_LoadProj_t and is initialized
 *  // with the recommended defaults from LS_loadProjDefault
 *  ...
 * }
 * @endcode
 */
#define LS_LOADPROJ_CMD(X)  LS_LoadProj_t X = LS_loadProjDefault;


/* ----------------------------------------------------------------------------------------------- */

/**
 * @ingroup SDKCoreDEFAULT_GRP
 * @brief LS_calculateUniformityDefault
 *
 * This const value represents an @ref LS_CalculateUniformity_t struct filled with default values.
 *
 * Please use the @ref LS_CALCULATE_UNIFORMITY_CMD macro to define and initialize variables of type \a LS_CalculateUniformity_t.
 *
 */
LS_IMPORT
LS_CalculateUniformity_t LS_calculateUniformityDefault;

/**
 * @ingroup SDKCoreMACROS_GRP
 * @brief LS_CALCULATE_UNIFORMITY_CMD
 *
 * This macros can be used to define a variable of type \a LS_CalculateUniformity_t that
 * is initialized with the recommended default values.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_CALCULATE_UNIFORMITY_CMD(cmd);
 *  // The variable cmd is of type LS_CalculateUniformity_t and is initialized
 *  // with the recommended defaults from LS_calculateUniformityDefault
 *  ...
 * }
 * @endcode
 */
#define LS_CALCULATE_UNIFORMITY_CMD(X)  LS_CalculateUniformity_t X = LS_calculateUniformityDefault;

/* ----------------------------------------------------------------------------------------------- */

/**
 * @ingroup SDKCoreDEFAULT_GRP
 * @brief LS_getBitmapInfoDefault
 *
 * This const value represents an @ref LS_GetBitmapInfo_t struct filled with default values.
 *
 * Please use the @ref LS_GET_BITMAP_INFO_CMD macro to define and initialize variables of type \a LS_GetBitmapInfo_t.
 *
 */
LS_IMPORT
LS_GetBitmapInfo_t LS_getBitmapInfoDefault;

/**
 * @ingroup SDKCoreMACROS_GRP
 * @brief LS_GET_BITMAP_INFO_CMD
 *
 * This macros can be used to define a variable of type \a LS_GetBitmapInfo_t that
 * is initialized with the recommended default values.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_GET_BITMAP_INFO_CMD(cmd);
 *  // The variable cmd is of type LS_GetBitmapInfo_t and is initialized
 *  // with the recommended defaults from LS_getBitmapInfoDefault
 *  ...
 * }
 * @endcode
 */
#define LS_GET_BITMAP_INFO_CMD(X)  LS_GetBitmapInfo_t X = LS_getBitmapInfoDefault;

/* ----------------------------------------------------------------------------------------------- */

/**
 * @ingroup SDKCoreDEFAULT_GRP
 * @brief LS_getBitmapDataDefault
 *
 * This const value represents an @ref LS_GetBitmapData_t struct filled with default values.
 *
 * Please use the @ref LS_GET_BITMAP_DATA_CMD macro to define and initialize variables of type \a LS_GetBitmapData_t.
 *
 */
LS_IMPORT
LS_GetBitmapData_t LS_getBitmapDataDefault;

/**
 * @ingroup SDKCoreMACROS_GRP
 * @brief LS_GET_BITMAP_DATA_CMD
 *
 * This macros can be used to define a variable of type \a LS_GetBitmapData_t that
 * is initialized with the recommended default values.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_GET_BITMAP_DATA_CMD(cmd);
 *  // The variable cmd is of type LS_GetBitmapData_t and is initialized
 *  // with the recommended defaults from LS_getBitmapDataDefault
 *  ...
 * }
 * @endcode
 */
#define LS_GET_BITMAP_DATA_CMD(X)  LS_GetBitmapData_t X = LS_getBitmapDataDefault;

/* ----------------------------------------------------------------------------------------------- */

/**
 * @ingroup SDKCoreDEFAULT_GRP
 * @brief LS_findDisplayDefault
 *
 * This const value represents an @ref LS_FindDisplay_t struct filled with default values.
 *
 * Please use the @ref LS_FIND_DISPLAY_CMD macro to define and initialize variables of type \a LS_FindDisplay_t.
 *
 */
LS_IMPORT
LS_FindDisplay_t LS_findDisplayDefault;

/**
 * @ingroup SDKCoreMACROS_GRP
 * @brief LS_FIND_DISPLAY_CMD
 *
 * This macros can be used to define a variable of type \a LS_FindDisplay_t that
 * is initialized with the recommended default values.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_FIND_DISPLAY_CMD(cmd);
 *  // The variable cmd is of type LS_FindDisplay_t and is initialized
 *  // with the recommended defaults from LS_findDisplayDefault
 *  ...
 * }
 * @endcode
 */
#define LS_FIND_DISPLAY_CMD(X)  LS_FindDisplay_t X = LS_findDisplayDefault;

/* ----------------------------------------------------------------------------------------------- */

/**
 * @ingroup SDKCoreDEFAULT_GRP
 * @brief LS_autoCropImageDefault
 *
 * This const value represents an @ref LS_AutoCropImage_t struct filled with default values.
 *
 * Please use the @ref LS_AUTO_CROP_IMAGE_CMD macro to define and initialize variables of type \a LS_AutoCropImage_t.
 *
 */
LS_IMPORT
LS_AutoCropImage_t LS_autoCropImageDefault;

/**
 * @ingroup SDKCoreMACROS_GRP
 * @brief LS_AUTO_CROP_IMAGE_CMD
 *
 * This macros can be used to define a variable of type \a LS_AutoCropImage_t that
 * is initialized with the recommended default values.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_AUTO_CROP_IMAGE_CMD(cmd);
 *  // The variable cmd is of type LS_AutoCropImage_t and is initialized
 *  // with the recommended defaults from LS_autoCropImageDefault
 *  ...
 * }
 * @endcode
 */
#define LS_AUTO_CROP_IMAGE_CMD(X)  LS_AutoCropImage_t X = LS_autoCropImageDefault;

/* ----------------------------------------------------------------------------------------------- */

/**
 * @ingroup SDKCoreDEFAULT_GRP
 * @brief LS_applyMultiPointCorrectionDefault
 *
 * This const value represents an @ref LS_ApplyMultiPointCorrection_t struct filled with default values.
 *
 * Please use the @ref LS_APPLY_MULTIPOINT_CORRECTION_CMD macro to define and initialize variables of type \a LS_ApplyMultiPointCorrection_t.
 *
 */
LS_IMPORT
LS_ApplyMultiPointCorrection_t LS_applyMultiPointCorrectionDefault;

/**
 * @ingroup SDKCoreMACROS_GRP
 * @brief LS_APPLY_MULTIPOINT_CORRECTION_CMD
 *
 * This macros can be used to define a variable of type \a LS_ApplyMultiPointCorrection_t that
 * is initialized with the recommended default values.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_APPLY_MULTIPOINT_CORRECTION_CMD(cmd);
 *  // The variable cmd is of type LS_ApplyMultiPointCorrection_t and is initialized
 *  // with the recommended defaults from LS_applyMultiPointCorrectionDefault
 *  ...
 * }
 * @endcode
 */
#define LS_APPLY_MULTIPOINT_CORRECTION_CMD(X)  LS_ApplyMultiPointCorrection_t X = LS_applyMultiPointCorrectionDefault;

/* ----------------------------------------------------------------------------------------------- */

/**
 * @ingroup SDKCoreDEFAULT_GRP
 * @brief LS_RemoveSpotmeter
 *
 * This const value represents an @ref LS_RemoveSpotmeter_t struct filled with default values.
 *
 * Please use the @ref LS_REMOVE_SPOTMETER_CMD macro to define and initialize variables of type \a LS_RemoveSpotmeter_t.
 *
 */
LS_IMPORT
LS_RemoveSpotmeter_t LS_RemoveSpotmeterDefault;

/**
 * @ingroup SDKCoreMACROS_GRP
 * @brief LS_REMOVE_SPOTMETER_CMD
 *
 * This macros can be used to define a variable of type \a LS_RemoveSpotmeter_t that
 * is initialized with the recommended default values.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_REMOVE_SPOTMETER_CMD(cmd);
 *  // The variable cmd is of type LS_RemoveSpotmeter_t and is initialized
 *  // with the recommended defaults from LS_RemoveSpotmeterDefault
 *  ...
 * }
 * @endcode
 */
#define LS_REMOVE_SPOTMETER_CMD(X)  LS_RemoveSpotmeter_t X = LS_RemoveSpotmeterDefault;

/* ----------------------------------------------------------------------------------------------- */

/**
 * @ingroup SDKCoreDEFAULT_GRP
 * @brief LS_RemoveSpotmeterGrid
 *
 * This const value represents an @ref LS_RemoveSpotmeterGrid_t struct filled with default values.
 *
 * Please use the @ref LS_REMOVE_SPOTMETER_GRID_CMD macro to define and initialize variables of type \a LS_RemoveSpotmeterGrid_t.
 *
 */
LS_IMPORT
LS_RemoveSpotmeterGrid_t LS_RemoveSpotmeterGridDefault;

/**
 * @ingroup SDKCoreMACROS_GRP
 * @brief LS_REMOVE_SPOTMETER_GRID_CMD
 *
 * This macros can be used to define a variable of type \a LS_RemoveSpotmeterGrid_t that
 * is initialized with the recommended default values.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_REMOVE_SPOTMETER_GRID_CMD(cmd);
 *  // The variable cmd is of type LS_RemoveSpotmeterGrid_t and is initialized
 *  // with the recommended defaults from LS_RemoveSpotmeterGridDefault
 *  ...
 * }
 * @endcode
 */
#define LS_REMOVE_SPOTMETER_GRID_CMD(X)  LS_RemoveSpotmeterGrid_t X = LS_RemoveSpotmeterGridDefault;

/* ----------------------------------------------------------------------------------------------- */

/**
 * @ingroup SDKCoreDEFAULT_GRP
 * @brief LS_RemoveLineProfile
 *
 * This const value represents an @ref LS_RemoveLineProfile_t struct filled with default values.
 *
 * Please use the @ref LS_REMOVE_LINE_PROFILE_CMD macro to define and initialize variables of type \a LS_RemoveLineProfile_t.
 *
 */
LS_IMPORT
LS_RemoveLineProfile_t LS_RemoveLineProfileDefault;

/**
 * @ingroup SDKCoreMACROS_GRP
 * @brief LS_REMOVE_LINE_PROFILE_CMD
 *
 * This macros can be used to define a variable of type \a LS_RemoveLineProfile_t that
 * is initialized with the recommended default values.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_REMOVE_LINE_PROFILE_CMD(cmd);
 *  // The variable cmd is of type LS_RemoveLineProfile_t and is initialized
 *  // with the recommended defaults from LS_RemoveLineProfileDefault
 *  ...
 * }
 * @endcode
 */
#define LS_REMOVE_LINE_PROFILE_CMD(X)  LS_RemoveLineProfile_t X = LS_RemoveLineProfileDefault;

/* ----------------------------------------------------------------------------------------------- */

/**
 * @ingroup SDKCoreDEFAULT_GRP
 * @brief LS_RemoveBrightDarkAnalysis
 *
 * This const value represents an @ref LS_RemoveBrightDarkAnalysis_t struct filled with default values.
 *
 * Please use the @ref LS_REMOVE_BRIGHT_DARK_ANALYSIS_CMD macro to define and initialize variables of type \a LS_RemoveBrightDarkAnalysis_t.
 *
 */
LS_IMPORT
LS_RemoveBrightDarkAnalysis_t LS_RemoveBrightDarkAnalysisDefault;

/**
 * @ingroup SDKCoreMACROS_GRP
 * @brief LS_REMOVE_BRIGHT_DARK_ANALYSIS_CMD
 *
 * This macros can be used to define a variable of type \a LS_RemoveBrightDarkAnalysis_t that
 * is initialized with the recommended default values.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_REMOVE_BRIGHT_DARK_ANALYSIS_CMD(cmd);
 *  // The variable cmd is of type LS_RemoveBrightDarkAnalysis_t and is initialized
 *  // with the recommended defaults from LS_RemoveBrightDarkAnalysisDefault
 *  ...
 * }
 * @endcode
 */
#define LS_REMOVE_BRIGHT_DARK_ANALYSIS_CMD(X)  LS_RemoveBrightDarkAnalysis_t X = LS_RemoveBrightDarkAnalysisDefault;

/* ----------------------------------------------------------------------------------------------- */

/**
 * @ingroup SDKCoreDEFAULT_GRP
 * @brief LS_RemoveSlantedEdgeAnalysis
 *
 * This const value represents an @ref LS_RemoveSlantedEdgeAnalysis_t struct filled with default values.
 *
 * Please use the @ref LS_REMOVE_SLANTED_EDGE_ANALYSIS_CMD macro to define and initialize variables of type \a LS_RemoveSlantedEdgeAnalysis_t.
 *
 */
LS_IMPORT
LS_RemoveSlantedEdgeAnalysis_t LS_RemoveSlantedEdgeAnalysisDefault;

/**
 * @ingroup SDKCoreMACROS_GRP
 * @brief LS_REMOVE_SLANTED_EDGE_ANALYSIS_CMD
 *
 * This macros can be used to define a variable of type \a LS_RemoveSlantedEdgeAnalysis_t that
 * is initialized with the recommended default values.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_REMOVE_SLANTED_EDGE_ANALYSIS_CMD(cmd);
 *  // The variable cmd is of type LS_RemoveSlantedEdgeAnalysis_t and is initialized
 *  // with the recommended defaults from LS_RemoveSlantedEdgeAnalysisDefault
 *  ...
 * }
 * @endcode
 */
#define LS_REMOVE_SLANTED_EDGE_ANALYSIS_CMD(X)  LS_RemoveSlantedEdgeAnalysis_t X = LS_RemoveSlantedEdgeAnalysisDefault;

/* ----------------------------------------------------------------------------------------------- */

/**
 * @internal
 * @ingroup SDKCoreDEFAULT_GRP
 * @brief LS_RemoveFourierSharpnessAnalysis
 *
 * This const value represents an @ref LS_RemoveFourierSharpnessAnalysis_t struct filled with default values.
 *
 * Please use the @ref LS_REMOVE_FOURIER_SHARPNESS_ANALYSIS_CMD macro to define and initialize variables of type \a LS_RemoveFourierSharpnessAnalysis_t.
 *
 */
LS_IMPORT
LS_RemoveFourierSharpnessAnalysis_t LS_RemoveFourierSharpnessAnalysisDefault;

/**
 * @internal
 * @ingroup SDKCoreMACROS_GRP
 * @brief LS_REMOVE_FOURIER_SHARPNESS_ANALYSIS_CMD
 *
 * This macros can be used to define a variable of type \a LS_RemoveFourierSharpnessAnalysis_t that
 * is initialized with the recommended default values.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_REMOVE_FOURIER_SHARPNESS_ANALYSIS_CMD(cmd);
 *  // The variable cmd is of type LS_RemoveFourierSharpnessAnalysis_t and is initialized
 *  // with the recommended defaults from LS_RemoveFourierSharpnessAnalysisDefault
 *  ...
 * }
 * @endcode
 */
#define LS_REMOVE_FOURIER_SHARPNESS_ANALYSIS_CMD(X)  LS_RemoveFourierSharpnessAnalysis_t X = LS_RemoveFourierSharpnessAnalysisDefault;

/* ----------------------------------------------------------------------------------------------- */

/**
 * @ingroup SDKCoreDEFAULT_GRP
 * @brief LS_RegionOfInterest
 *
 * This const value represents an @ref LS_RegionOfInterest_t struct filled with default values.
 *
 * Please use the @ref LS_REGION_OF_INTEREST_CMD macro to define and initialize variables of type \a LS_RegionOfInterest_t.
 *
 */
 LS_IMPORT
 LS_RegionOfInterest_t LS_RegionOfInterestDefault;

/**
 * @ingroup SDKCoreMACROS_GRP
 * @brief LS_REGION_OF_INTEREST_CMD
 *
 * This macros can be used to define a variable of type \a LS_RegionOfInterest_t that
 * is initialized with the recommended default values.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_REGION_OF_INTEREST_CMD(cmd);
 *  // The variable cmd is of type LS_RegionOfInterest_t and is initialized
 *  // with the recommended defaults from LS_RegionOfInterestDefault
 *  ...
 * }
 * @endcode
 */
 #define LS_REGION_OF_INTEREST_CMD(X)  LS_RegionOfInterest_t X = LS_RegionOfInterestDefault;

/* ----------------------------------------------------------------------------------------------- */

/**
 * @ingroup SDKCoreDEFAULT_GRP
 * @brief DarkestBrightestSpot
 *
 * This const value represents an @ref DarkestBrightestSpot_t struct filled with default values.
 *
 * Please use the @ref DARKEST_BRIGHTEST_SPOT_CMD macro to define and initialize variables of type \a DarkestBrightestSpot_t.
 *
 */
 LS_IMPORT
 DarkestBrightestSpot_t DarkestBrightestSpotDefault;

/**
 * @ingroup SDKCoreMACROS_GRP
 * @brief DARKEST_BRIGHTEST_SPOT_CMD
 *
 * This macros can be used to define a variable of type \a DarkestBrightestSpot_t that
 * is initialized with the recommended default values.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  DARKEST_BRIGHTEST_SPOT_CMD(cmd);
 *  // The variable cmd is of type DarkestBrightestSpot_t and is initialized
 *  // with the recommended defaults from DarkestBrightestSpotDefault
 *  ...
 * }
 * @endcode
 */
 #define DARKEST_BRIGHTEST_SPOT_CMD(X)  DarkestBrightestSpot_t X = DarkestBrightestSpotDefault;

/* ----------------------------------------------------------------------------------------------- */

/**
 * @ingroup SDKCoreDEFAULT_GRP
 * @brief LS_LineProfileResult
 *
 * This const value represents an @ref LS_LineProfileResult_t struct filled with default values.
 *
 * Please use the @ref LS_LINE_PROFILE_RESULT_CMD macro to define and initialize variables of type \a LS_LineProfileResult_t.
 *
 */
 LS_IMPORT
 LS_LineProfileResult_t LS_LineProfileResultDefault;

/**
 * @ingroup SDKCoreMACROS_GRP
 * @brief LS_LINE_PROFILE_RESULT_CMD
 *
 * This macros can be used to define a variable of type \a LS_LineProfileResult_t that
 * is initialized with the recommended default values.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_LINE_PROFILE_RESULT_CMD(cmd);
 *  // The variable cmd is of type LS_LineProfileResult_t and is initialized
 *  // with the recommended defaults from LS_LineProfileResultDefault
 *  ...
 * }
 * @endcode
 */
 #define LS_LINE_PROFILE_RESULT_CMD(X)  LS_LineProfileResult_t X = LS_LineProfileResultDefault;

/* ----------------------------------------------------------------------------------------------- */

/**
 * @ingroup SDKCoreDEFAULT_GRP
 * @brief LS_SpotmeterResult
 *
 * This const value represents an @ref LS_SpotmeterResult_t struct filled with default values.
 *
 * Please use the @ref LS_SPOTMETER_RESULT_CMD macro to define and initialize variables of type \a LS_SpotmeterResult_t.
 *
 */
 LS_IMPORT
 LS_SpotmeterResult_t LS_SpotmeterResultDefault;

/**
 * @ingroup SDKCoreMACROS_GRP
 * @brief LS_SPOTMETER_RESULT_CMD
 *
 * This macros can be used to define a variable of type \a LS_SpotmeterResult_t that
 * is initialized with the recommended default values.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_SPOTMETER_RESULT_CMD(cmd);
 *  // The variable cmd is of type LS_SpotmeterResult_t and is initialized
 *  // with the recommended defaults from LS_SpotmeterResultDefault
 *  ...
 * }
 * @endcode
 */
 #define LS_SPOTMETER_RESULT_CMD(X)  LS_SpotmeterResult_t X = LS_SpotmeterResultDefault;

/* ----------------------------------------------------------------------------------------------- */

/**
 * @ingroup SDKCoreDEFAULT_GRP
 * @brief LS_BrightDark
 *
 * This const value represents an @ref LS_BrightDark_t struct filled with default values.
 *
 * Please use the @ref LS_BRIGHTDARK_CMD macro to define and initialize variables of type \a LS_BrightDark_t.
 *
 */
 LS_IMPORT
 LS_BrightDark_t LS_BrightDarkDefault;

/**
 * @ingroup SDKCoreMACROS_GRP
 * @brief LS_BRIGHTDARK_CMD
 *
 * This macros can be used to define a variable of type \a LS_BrightDark_t that
 * is initialized with the recommended default values.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  LS_BRIGHTDARK_CMD(cmd);
 *  // The variable cmd is of type LS_BrightDark_t and is initialized
 *  // with the recommended defaults from LS_BrightDarkDefault
 *  ...
 * }
 * @endcode
 */
 #define LS_BRIGHTDARK_CMD(X)  LS_BrightDark_t X = LS_BrightDarkDefault;

/* ----------------------------------------------------------------------------------------------- */

 /**
  * @ingroup SDKCoreDEFAULT_GRP
  * @brief LS_GridSpotmeter
  *
  * This const value represents an @ref LS_GridSpotmeter_t struct filled with default values.
  *
  * Please use the @ref LS_GRID_SPOTMETER_CMD macro to define and initialize variables of type \a LS_GridSpotmeter_t.
  *
  */
  LS_IMPORT
  LS_GridSpotmeter_t LS_GridSpotmeterDefault;

 /**
  * @ingroup SDKCoreMACROS_GRP
  * @brief LS_GRID_SPOTMETER_CMD
  *
  * This macros can be used to define a variable of type \a LS_GridSpotmeter_t that
  * is initialized with the recommended default values.
  *
  * @b Example:
  * @code{.c}
  * {
  *  ...
  *  LS_GRID_SPOTMETER_CMD(cmd);
  *  // The variable cmd is of type LS_GridSpotmeter_t and is initialized
  *  // with the recommended defaults from LS_GridSpotmeterDefault
  *  ...
  * }
  * @endcode
  */
  #define LS_GRID_SPOTMETER_CMD(X)  LS_GridSpotmeter_t X = LS_GridSpotmeterDefault;

 /* ----------------------------------------------------------------------------------------------- */

 /**
  * @ingroup SDKCoreDEFAULT_GRP
  * @brief LS_Quadrangle
  *
  * This const value represents an @ref LS_Quadrangle_t struct filled with default values.
  *
  * Please use the @ref LS_QUADRANGLE_CMD macro to define and initialize variables of type \a LS_Quadrangle_t.
  *
  */
  LS_IMPORT
  LS_Quadrangle_t LS_QuadrangleDefault;

 /**
  * @ingroup SDKCoreMACROS_GRP
  * @brief LS_QUADRANGLE_CMD
  *
  * This macros can be used to define a variable of type \a LS_Quadrangle_t that
  * is initialized with the recommended default values.
  *
  * @b Example:
  * @code{.c}
  * {
  *  ...
  *  LS_QUADRANGLE_CMD(cmd);
  *  // The variable cmd is of type LS_Quadrangle_t and is initialized
  *  // with the recommended defaults from LS_QuadrangleDefault
  *  ...
  * }
  * @endcode
  */
  #define LS_QUADRANGLE_CMD(X)  LS_Quadrangle_t X = LS_QuadrangleDefault;

 /* ----------------------------------------------------------------------------------------------- */

 /**
  * @ingroup SDKCoreDEFAULT_GRP
  * @brief LS_Margins
  *
  * This const value represents an @ref LS_Margins_t struct filled with default values.
  *
  * Please use the @ref LS_MARGINS_CMD macro to define and initialize variables of type \a LS_Margins_t.
  *
  */
  LS_IMPORT
  LS_Margins_t LS_MarginsDefault;

 /**
  * @ingroup SDKCoreMACROS_GRP
  * @brief LS_MARGINS_CMD
  *
  * This macros can be used to define a variable of type \a LS_Margins_t that
  * is initialized with the recommended default values.
  *
  * @b Example:
  * @code{.c}
  * {
  *  ...
  *  LS_MARGINS_CMD(cmd);
  *  // The variable cmd is of type LS_Margins_t and is initialized
  *  // with the recommended defaults from LS_MarginsDefault
  *  ...
  * }
  * @endcode
  */
  #define LS_MARGINS_CMD(X)  LS_Margins_t X = LS_MarginsDefault;

 /* ----------------------------------------------------------------------------------------------- */

 /**
  * @ingroup SDKCoreDEFAULT_GRP
  * @brief LS_PassFail_Float
  *
  * This const value represents an @ref LS_PassFail_Float_t struct filled with default values.
  *
  * Please use the @ref LS_PASS_FAIL_FLOAT_CMD macro to define and initialize variables of type \a LS_PassFail_Float_t.
  *
  */
  LS_IMPORT
  LS_PassFail_Float_t LS_PassFail_FloatDefault;

 /**
  * @ingroup SDKCoreMACROS_GRP
  * @brief LS_PASS_FAIL_FLOAT_CMD
  *
  * This macros can be used to define a variable of type \a LS_PassFail_Float_t that
  * is initialized with the recommended default values.
  *
  * @b Example:
  * @code{.c}
  * {
  *  ...
  *  LS_PASS_FAIL_FLOAT_CMD(cmd);
  *  // The variable cmd is of type LS_PassFail_Float_t and is initialized
  *  // with the recommended defaults from LS_PassFail_FloatDefault
  *  ...
  * }
  * @endcode
  */
  #define LS_PASS_FAIL_FLOAT_CMD(X)  LS_PassFail_Float_t X = LS_PassFail_FloatDefault;

 /* ----------------------------------------------------------------------------------------------- */


/* T E M P L A T E */
/**
 * @ingroup SDKCoreDEFAULT_GRP
 * @brief XXX
 *
 * This const value represents an @ref XXX_t struct filled with default values.
 *
 * Please use the @ref YYY_CMD macro to define and initialize variables of type \a XXX_t.
 *
 */
// LS_IMPORT
// XXX_t XXXDefault;

/**
 * @ingroup SDKCoreMACROS_GRP
 * @brief YYY_CMD
 *
 * This macros can be used to define a variable of type \a XXX_t that
 * is initialized with the recommended default values.
 *
 * @b Example:
 * @code{.c}
 * {
 *  ...
 *  YYY_CMD(cmd);
 *  // The variable cmd is of type XXX_t and is initialized
 *  // with the recommended defaults from XXXDefault
 *  ...
 * }
 * @endcode
 */
// #define YYY_CMD(X)  XXX_t X = XXXDefault;

/* ----------------------------------------------------------------------------------------------- */


#endif // LS_SDK_CORE_DEFAULTS_H
