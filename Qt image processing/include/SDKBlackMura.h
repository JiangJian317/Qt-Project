#ifndef SDK_BLACKMURA_H
#define SDK_BLACKMURA_H


/**
 *
 *  @defgroup SDKBlackMuraPage_GRP SDK Black Mura
 *  @brief     LumiSuite (LS) Black Mura SDK
 *
 *  @file      SDKBlackMura.h
 *
 *  @brief     LumiSuite (LS) Black Mura SDK
 *  @details   The header files provides all methods the can be used from the LumiSuite Black Mura SDK
 *  @author    The LumiSuite (LS) development team
 *  @version   1.6.1
 *  @date      2015, 2016, 2017
 *  @copyright Copyright © 2015,2016, 2017 Instrument Systems GmbH, Munich. All Rights Reserved.
 */

/**
 *
 *  @ingroup SDKBlackMuraPage_GRP
 *  @defgroup intro_sec5 Introduction
 *  @brief Introduction and overview
 *  @section intro_sec5 &nbsp;
 *  This documents describes the interfaces of the LumiSuite Black Mura SDK library
 *
 *  @note For the Black Mura SDK library a license file is required, this file has to be declared in SDK start!
 *
 *  @b Example:
 *  @code{.c}
 *
 *    LS_SDK_INIT_CMD(initCmd);
 *    const char *lic =  "... yourPath .../licensingKey.lic";
 *    strncpy_s( initCmd._in_licenseFileName, LS_MAX_FILENAME_LEN-1, lic, LS_MAX_FILENAME_LEN-1 );
 *    ..
 *
 *    LS_SDK_Status_t stat = LS_start( &initCmd );
 *    ..
 *  @endcode
 *
 *
 *  The <b>LumiSuite SDK Black Mura</b> is device independentand and allows the calculation of Black Mura. With this SDK you
 *  can test if the display is properly aligned and focused. You can also calculate the Black Mura values.
 *
 *  You can select between two types of Black Mura standards. @ref LS_BlackMura_StandardVersion_t and @ref LS_BlackMura_calculate .
 *  The latest version 1.2.0 is not restricted to rectangular displays.
 *
 *  Please refer to @ref SDKCoreGettingStarted_GRP to get more details how to use the LumiSuite SDK.
 *  <br>Please refer to @ref SDKBlackMuraFunctions_GRP "SDK Black Mura Functions" for the list of available functions and more details.
 *  <br>Please refer to @ref SDKBlackMuraPageDataStructs_GRP "SDK Black Mura Data Structures" for the list of available structures, types and enums.
 *
 *
 *
 */

/**
 *
 *  @ingroup SDKBlackMuraPage_GRP
 *  @defgroup SDKBlackMuraFunctions_GRP Functions
 *  @brief List of available functions
 *
 */

/**
 *
 *  @ingroup SDKBlackMuraPage_GRP
 *  @defgroup SDKBlackMuraPageDataStructs_GRP Data Structures
 *  @brief List of available types, data structures and enumerations
 */

/**
 *
 *  @ingroup SDKBlackMuraPage_GRP
 *  @defgroup SDKBlackMuraPageDefinitions_GRP Defines
 *  @brief List of available definitions
 */


/**
 *
 *  @ingroup SDKBlackMuraPage_GRP
 *  @defgroup SDKBlackMuraPageMISC_GRP Miscellaneous
 *  @brief Miscellaneous
 */

#include "SDKBlackMuraParams.h"
#include "SDKBlackMuraExport.h"
#include <SDKCore.h>

#ifdef LS_DOXYGEN_RUN
#  undef LSBM_CALLCONV
#  define LSBM_CALLCONV
#else
#   define LSBM_CALLCONV  SDKBLACKMURA_EXPORT __cdecl
#endif



#ifdef __cplusplus
extern "C" {
#endif

/*
 * Public programming interface for accessing the Black Mura SDK
 */

/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKBlackMuraFunctions_GRP
 * @brief   Determines if the display images are stable (example: no PWM backlight interference)
 * The method takes 3 images and verifies if the luminance variation between them is within 0.1%
 * If not, the number of averages on the device must be increased
 * @return @ref eLS_OK on success (method runs and display is stable) or any other error code from @ref SDKCoreErrors_GRP "SDKCore Error Codes".
 */
LS_SDK_Status_t LSBM_CALLCONV LS_BlackMura_verifyDUTStability( LS_BlackMura_VerifyDUTStability_t* io_cmd );

/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKBlackMuraFunctions_GRP
 * @brief   Use this function to verify the alignment of the display, using the Black Mura alignment/focus pattern
 *
 *
 * Please refer to @ref LS_BlackMura_VerifyAlignment_t for details about the input/output parameter properties.
 *
 * @param[in,out]  io_cmd  Ptr. to the command input/output data
 *
 * @return @ref eLS_OK on success or any other error code from @ref SDKCoreErrors_GRP "SDKCore Error Codes".
 *
 */
LS_SDK_Status_t LSBM_CALLCONV LS_BlackMura_verifyAlignment( LS_BlackMura_VerifyAlignment_t* io_cmd );

/**
 *
 * @ingroup SDKBlackMuraFunctions_GRP
 * @brief   Use this function to verify the focus of the display, using the Black Mura alignment/focus pattern
 *
 *
 * Please refer to @ref LS_BlackMura_VerifyFocus_t for details about the input/output parameter properties.
 *
 * @param[in,out]  io_cmd  Ptr. to the command input/output data
 *
 * @return @ref eLS_OK on success or any other error code from @ref SDKCoreErrors_GRP "SDKCore Error Codes".
 *
 */
LS_SDK_Status_t LSBM_CALLCONV LS_BlackMura_verifyFocus( LS_BlackMura_VerifyFocus_t* io_cmd );


/**
 *
 * @ingroup SDKBlackMuraFunctions_GRP
 * @brief   Use this function to calculate the Black Mura of a display
 *
 * See also @ref LS_findDisplay and @ref LS_autoCropImage (@remark Standard version 1.2.0 does not need both)
 *
 * @param[in,out]  io_cmd  Ptr. to the command input/output data
 *
 * @return @ref eLS_OK on success or any other error code from @ref SDKCoreErrors_GRP "SDKCore Error Codes".
 *
 */
LS_SDK_Status_t LSBM_CALLCONV LS_BlackMura_calculate( LS_BlackMura_Calculate_t* io_cmd );


/**
 *
 * @ingroup SDKBlackMuraFunctions_GRP
 * @brief   Use this function save the data of an image in a BlackMura specific text file format
 *
 * Please refer to @ref LS_BlackMura_CalculationImagesToTextFiles_t for details about the input parameter properties.
 *
 * @param[in,out]  io_cmd  Ptr. to the command input/output data
 *
 * @return @ref eLS_OK on success or any other error code from @ref SDKCoreErrors_GRP "SDKCore Error Codes".
 *
 * @remark
 *         - Please be sure the target drive has enough disk space and is writable.
 *         - The given \a in_cmd._in_absolutePath must be valid and exist.
 *         - In case file extension is missing (.txt) it will be added.
 *
 */
LS_SDK_Status_t LSBM_CALLCONV LS_BlackMura_saveImageAsTextFile( LS_BlackMura_ImageToTextFile_t* io_cmd );

#ifdef __cplusplus
}
#endif


#endif
