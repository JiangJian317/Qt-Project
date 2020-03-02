/**
 *
 *  @defgroup SDKCoreGettingStarted_GRP Getting started
 *  @brief     Getting started<br>&nbsp;&nbsp;&nbsp;
 */

/**
 *
 *  @defgroup SDKCorePage_GRP SDKCore
 *  @brief     LumiSuite (LS) SDKCore Interface
 *  @file      SDKCore.h
 *
 *  @brief     LumiSuite (LS) SDKCore Interface
 *  @details   The header files provides all methods that can be used from the LS SDKCore
 *  @author    The LumiSuite (LS) development team
 *  @version   1.0.0.1
 *  @date      2015, 2016, 2017, 2018, 2019
 *  @copyright Copyright © 2015,2016,2017,2018, 2019 Instrument Systems GmbH, Munich. All Rights Reserved.
 */

/**
 *
 *  @ingroup SDKCorePage_GRP
 *  @defgroup intro_sec2 Introduction
 *  @brief Introduction and overview
 *  @section intro_sec2 &nbsp;
 *
 *  The LumiSuite SDKCore is device independent and provides a collection of functions to deal with images and to measure and analyze. With the SDKCore
 *  you can load and save images from/to disk and crop, rotage or binning (2D) images. Additional the SDKCore allows to analyze and measure images.
 *
 *  In order to work with the LumiSuite SDKCore the SDK needs be be started first. This can be done with calling the @ref LS_start function. The LS_Start
 *  function initializes and starts all required recources. If LS_Start returns successfully it is required to create an execution context. The
 *  context provides a kind of session. All returned handles and/or ID's relate to only one context. It is possible to create several context.
 *  An context can be created with the function @ref LS_createContext which returns an handle the newly created context. This context handle
 *  is required for all SDKCore functions. In order to release resources @ref LS_destroyContext must be called. At last the function @ref LS_quit() must be
 *  called before shutdown the SDKCore.
 *
 * @b Example:
 * @code{.c}
 *
 *    LS_SDK_INIT_CMD(initCmd);
 *    LS_SDK_Status_t stat = LS_start( &initCmd );
 *
 *    LS_Handle_t ctxHandle  = LS_createContext();
 *
 *    ... // to ..... add analysis (e.g. spotmeter, line profile, ...), load image, execute evaluate results .....
 *
 *    stat = LS_destroyContext(ctxHandle);
 *
 *    stat = LS_quit();
 * }
 * @endcode
 *
 *  Please refer to @ref SDKCoreGettingStarted_GRP to get more details how to use the LumiSuite SDK.
 *  <br>Please refer to @ref SDKCoreFunctions_GRP "SDKCore Functions" for the list of available functions and more details.
 *  <br>Please refer to @ref SDKCorePageDataStructs_GRP "SDKCore Data Structures" for the list of available structures, types and enums.
 *  <br>Please refer to @ref SDKCoreErrors_GRP "SDKCore Error Codes" for the list of error codes.
 *
 */

/**
 *
 *  @ingroup SDKCorePage_GRP
 *  @defgroup SDKCoreFunctions_GRP Functions
 *  @brief List of available functions
 */

/**
 *
 *  @ingroup SDKCorePage_GRP
 *  @defgroup SDKCorePageDataStructs_GRP Data Structures
 *  @brief List of available types, data structures and enumerations
 */

/**
 *
 *  @ingroup SDKCorePage_GRP
 *  @defgroup SDKCorePageDefinitions_GRP Defines
 *  @brief List of available definitions
 */

/**
 *
 *  @ingroup SDKCorePage_GRP
 *  @defgroup SDKCoreErrors_GRP Error Codes
 *  @brief List of available error codes
 *
 */

/**
 *
 *  @ingroup SDKCorePage_GRP
 *  @defgroup SDKCoreMISC_GRP Miscellaneous
 *  @brief Miscellaneous
 *
 */

/**
 *
 *  @ingroup SDKCorePage_GRP
 *  @defgroup SDKCoreDEFAULT_GRP Defaults
 *  @brief List of available defaults
 *
 *  @brief List of default values that should be used to initialize variables that are used with SDKCore functions
 *  <br>It is highly recommended to use these values
 *  to initialize variables that are used with the LumiSuite SDKCore functions. This keeps shure the command structs are always properly
 *  initialized and according the SDK Core requirements.
 *
 */

/**
 *
 *  @ingroup SDKCorePage_GRP
 *  @defgroup SDKCoreMACROS_GRP Macros
 *  @brief List of macros<br>&nbsp;&nbsp;&nbsp;
 *
 */


#ifndef SDK_CORE_H
#define SDK_CORE_H

/**
  * @internal
  * @brief SDKCoreExport.h
  *
  */
#include "SDKCoreExport.h"

#ifdef __cplusplus
extern "C" {
#endif


/* ----------------------------------------------------------------------------------------------- */
/**
  *
  * @ingroup SDKCoreMISC_GRP
  * @brief This define describes the required calling convention definition that is used for all LumiSuite SDK
  * functions. It tells the compiler the rules that apply for setting up the stack, pushing arguments
  * and getting return values.
  *
  * The callingconvention for the LumiSuite SDK is set to <b>__cdecl</b>.
  */
#ifdef LS_DOXYGEN_RUN
#   define LS_EXPORT
#   define LS_CALLCONV
#else
#   define LS_EXPORT  C4LUMISUITE_EXPORT
#   define LS_CALLCONV  C4LUMISUITE_EXPORT __cdecl
#endif


/* Include SDK Core tyoe defintions */
#include "LS_SDKCoreDefs.h"

/* Include SDK Core default values and some macros */
#include "LS_SDKCoreDefaults.h"

/* Include SDK Core error definitions  */
#include "LS_SDKCoreErrors.h"


/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @example  LS_load_image_from_file.c
 * Example how to load an image from file.
 *
 * @example  LS_save_image_to_file.c
 * Example how to save an image to file.
 *
 * @example  LS_crop_image.c
 * Example how to crop an image.
 *
 * @example  LS_spotmeter.c
 * Example how to deal with spotmeters
 *
 * @example  LS_calculateSpotmeter.c
 * Example how to run measurement with one single spotmeter
 *
 * @example  LS_BlackMura_complete_workflow.c
 * Example how to run a complete Black Mura workflow
 *
 *  *  @note For the Black Mura SDK library a license file is required, this file has to be declared in SDK start!
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
 * @example  LS_BlackMura_optimized_workflow.c
 * Example how to run an optimized Black Mura workflow, where alignment and focusing is not required
 *
 *  *  @note For the Black Mura SDK library a license file is required, this file has to be declared in SDK start!
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
 */

/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKCoreFunctions_GRP
 * @brief Start the LumiSuite SDK framework
 *
 *        This function starts the LumiSuite framework and is mandatory to be called prior to any
 *        other LumiSuite SDK operation.
 *
 *        The @ref LoggingCallback "logging callback function" can be used to implement user specific logging. Thus, the
 *        LoggingCallback is called every time the LumiSuite SDK writes an log entry.
 *
 * @param[in] io_cmd        Pointer to the command input/output data.
 *
 * @return @ref eLS_OK on success or any other @ref SDKCoreErrors_GRP "error code" otherwise.
 *
 * @remark
 * - The LumiSuite SDK functions are not threadsafe. Thus, all SDK functions must be called in the same thread where @ref LS_start is called.
 * - Only one call of LS_start can be made per process. To call it again on the same process, a LS_quit must be called first to end the previous session
 * - In case the \a in_log_Callback parameter is set to nullptr the normal logging behaviour of the SDK framework is not affected.
 *
 * @b Example:
 * @code{.c}
 * void __cdecl MyLoggingCallback(LS_SDK_Core_LogMsgType_t logMsgType, const char * pLogMessage)
 * {
 *      // do something, e.g. write log entry to your own log file
 * }
 *
 * int32_t main( void )
 * {
 *    LS_SDK_INIT_CMD(initCmd);
 *    LS_SDK_Status_t stat = LS_start( &initCmd );
 *
 *    // do something
 *
 *    stat = LS_quit();
 *    QVERIFY2(stat== eLS_OK,"LS_quit failed");
 * }
 * @endcode
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_start( const LS_SDK_Init_t * io_cmd);


/* ----------------------------------------------------------------------------------------------- */
/**
 * @internal
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_startOLD( LoggingCallback in_log_Callback);


/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKCoreFunctions_GRP
 * @brief   Quit the LumiSuite SDK framework
 *
 *          Call this function if the LumiSuite SDK is no longer needed and you want to
 *          shut down all LumiSuite SDK components. It stops the LumiSuite SDK worker thread and cleans
 *          up all LumiSuite SDK resources (contexts and images)
 *
 * @return @ref eLS_OK on success or any other @ref SDKCoreErrors_GRP "error code" otherwise.
 *
 * @remark
 *       - If not shutting down properly undeterministic crashes may appear.
 *       - After calling this function all SDK functions will be blocked or return an error
 *          until @ref LS_start is called again.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_quit( void );


/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKCoreFunctions_GRP
 * @brief   Create SDKCore Context
 *
 *          This function creates and initializes a new instance of LumiSuite SDK and returns a handle
 *          to this instance - think of it as a context. Using the concept of handles allows for
 *          building complex applications where one can load and process several images in
 *          parallel or process images with different sets of evaluations.
 *
 * NOTICE: at the moment, only one color space is allowed per context
 *
 *          Please see also @ref LS_destroyContext.
 *
 * @return  handle >=0 on success or below 0 otherwise.
 *
 * @remark
 *          - Some LumiSuite SDK functions expect an context handle to work properly.
 *
 */
LS_Handle_t LS_CALLCONV LS_createContext( void );


/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKCoreFunctions_GRP
 * @brief   Destroy SDKCore Context
 *
 *          Destroy the context associated with given handle \a in_handle
 *
 *          Please see also @ref LS_createContext.
 *
 * @param[in] in_handle  The context handle that shall be destroyed.
 *
 * @return @ref eLS_OK on success or any other @ref SDKCoreErrors_GRP "error code" otherwise.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_destroyContext( LS_Handle_t in_handle );

/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKCoreFunctions_GRP
 * @brief   Serialize image to memory buffer
 *
 * This function can be used to serialize an image to memory buffer.
 *
 * The function \a LS_getImageSize must be called prior to get image information in order to calculate
 * the memory size for the target buffer where the image is serialized to.
 *
 * Please see also @ref LS_getImageSize.
 *
 * @param[in,out]   io_cmd  Pointer to the command input/output data.
 *
 * @return @ref eLS_OK on success or any other @ref SDKCoreErrors_GRP "error code" otherwise.
 *
 * @remark
 *          - The \a io_cmd._out_image_data must be a pointer to allocated memory where the image can be serialized into.
 *          - The caller must allocate the memory for the image and take care to delete as soon as the image is no
 *              longer needed.
 *          - The size of the allocated memory buffer must be sufficient to serialize
 *            the image, otherwise the application can crash.
 *          - Use the following formula to calculate the memory size that must be allocated for the image:
 *            <br> <em>required_mem_size = _out_width * _out_height * _out_channels * sizeof(float)</em>
 *            <br>Please see also @ref LS_getImageSize and @ref LS_GetImageInfo_t.
 *          - Regarding memory Layout of serialized image, each Pixel contains a specific number of channel values:
 *            Pix_1 { (Ch_1), (Ch_2) ... (Ch_n) }, Pix_2 { (Ch_1), (Ch_2) ... (Ch_n) }, ... Pix_n { (Ch_1), (Ch_2) ... (Ch_n) }
 *            Please see also _out_channelContent of @ref LS_GetImage_t to determine the channel assignment, this array
 *            contains the color coordinate for each channel. As an example, {Ch_1, Ch2, Ch3} could be {X, Y, Z}.
 *
 *          - as an example of memory layout for a 2x2 image with 3 channels:
 *            <br>[ Pix_1{ (Ch_1), (Ch_2), (Ch_3) }, Pix_2{ (Ch_1), (Ch_2), (Ch_3) }
 *            <br>  Pix_3{ (Ch_1), (Ch_2), (Ch_3) }, Pix_4{ (Ch_1), (Ch_2), (Ch_3) } ]
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_getImage(LS_GetImage_t* io_cmd );


/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKCoreFunctions_GRP
 * @brief   Get image size information
 *
 * This function returns some image information and must be used before calling
 * @ref LS_getImage in order to calculate the required memory buffer size.
 *
 * @param[in,out]   io_cmd  Pointer to the command input/output data.
 *
 * @return @ref eLS_OK on success or any other @ref SDKCoreErrors_GRP "error code" otherwise.
 *
 * @remark Use the following formula to calculate the memory size that must be allocated for the image:
 *         <br> <em>required_mem_size = _out_width * _out_height * _out_channels * sizeof(float)</em>
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_getImageSize(LS_GetImageInfo_t* io_cmd );


/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKCoreFunctions_GRP
 * @brief Save image to disk
 *
 * Use this function to save an image to disk. On return the image is serialized to disk.
 *
 * Please refer to @ref LS_SaveFile_t for details about the input parameters.
 *
 * @param[in] in_cmd  Pointer to the command input data struct.
 *
 * @return @ref eLS_OK on success or any other @ref SDKCoreErrors_GRP "error code" otherwise.
 *
 * @remark
 *         - Please be sure the target drive has enough disk space and is writable.
 *         - The given \a in_cmd._in_absoluteFilePath must be valid (not empty and must include file name).
 *         - In case file extension is missing it will be added according to the file type.
 *         - In case the target folder does not exist it will be created (may fail)
 */
LS_SDK_Status_t LS_CALLCONV LS_saveImageToFile (const LS_SaveFile_t * in_cmd);


/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKCoreFunctions_GRP
 * @brief Delete image
 *
 * This function deletes an image. On return the image has been deleted, removed from the
 * image pool and disassociated from all SDK contexts.
 *
 * @param[in] in_img_id  The image id of the image to delete.
 *
 * @return @ref eLS_OK on success or any other @ref SDKCoreErrors_GRP "error code" otherwise.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_deleteImage(LS_ImageId_t in_img_id);


/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKCoreFunctions_GRP
 * @brief Load image from disk
 *
 * Use this function to load an image file. On return the image is imported and an \a image_id is provided.
 *
 * Please refer to @ref LS_LoadImage_t for details about the input/output parameters.
 *
 * @param[in,out]   io_cmd      Pointer to the command input/output data.
 *
 * @return @ref eLS_OK on success or any other @ref SDKCoreErrors_GRP "error code" otherwise.
 *
 * @remark  Only files with the \a .LSimg file format are accepted.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_loadImageFromFile (LS_LoadImage_t * io_cmd);



/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKCoreFunctions_GRP
 * @brief Use this function to receive LumiSuite SDK version number
 *
 * Please refer to @ref LS_GetVersion_t for details about the input/output parameters.
 *
 * @param[in,out] io_cmd      Pointer to the command input/output data.
 *
 * @return @ref eLS_OK on success or any other @ref SDKCoreErrors_GRP "error code" otherwise.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_getVersion( LS_GetVersion_t* io_cmd );


/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKCoreFunctions_GRP
 * @brief Use this function to apply a moire filter to an image
 *
 * This function can be used to remove a moire pattern from an image. The original image is \a not changed but the function
 * returns an image id of an copied and corrected image.
 *
 * Please refer to @ref LS_MoireFilterImage_t for details about the input/output parameters.
 *
 * @param[in,out]  io_cmd      Pointer to the command input/output data.
 *
 * @return @ref eLS_OK on success or any other @ref SDKCoreErrors_GRP "error code" otherwise.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_applyMoireFilterToImage( LS_MoireFilterImage_t* io_cmd );

/* ----------------------------------------------------------------------------------------------- */

/**
 *
 * @ingroup SDKCoreFunctions_GRP
 * @brief Use this function to crop an image
 *
 * This function can be used to manual crop an image. The original image is \a not changed but the function
 * returns an image id of an copied and cropped image.
 *
 * Please refer to @ref LS_ManualCropImage_t for details about the input/output parameters.
 *
 * @param[in,out]  io_cmd      Pointer to the command input/output data.
 *
 * @return @ref eLS_OK on success or any other @ref SDKCoreErrors_GRP "error code" otherwise.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_manualCropImage( LS_ManualCropImage_t* io_cmd );


/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKCoreFunctions_GRP
 * @brief Use this function to crop an image showing a non-rectangular display
 *
 * This function can be used to crop an image showing a non-rectangular display and fill the background either with zeros
 * or with image content. The original image is \a not changed but the function
 * returns an image id of an copied and cropped image.
 *
 * Please refer to @ref LS_CropingAndFilling_t for details about the input/output parameters.
 *
 * @param[in,out]  io_cmd      Pointer to the command input/output data.
 *
 * @return @ref eLS_OK on success or any other @ref SDKCoreErrors_GRP "error code" otherwise.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_croppingAndFilling( LS_CroppingAndFilling_t* io_cmd);


/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKCoreFunctions_GRP
 * @brief Use this function to add an spotmeter
 *
 * Use this function to add spotmeter. On return the spotmeter is created/set and associated to the given context.
 *
 * Please refer to @ref LS_AddSpotmeter_t for details about the available spotmeter properties.
 *
 * @param[in,out]   io_cmd      Pointer to the command input/output data.
 *
 * @return @ref eLS_OK on success or any other @ref SDKCoreErrors_GRP "error code" otherwise.
 *
 * @remark
 * -   The returned <b>_out_spotmeterId</b> may be negative.
 * -   As soon as a spotmeter has been added it will evaluate and create results every time the "execute" method is called.
 * -   Only @ref LS_MAX_ANALYSIS analyses at the same time are supported
 * The results are available until the next execute is called or the spotmeter is removed.
 * To keep the memory consumption as low as possile be sure to remove all added spotmeter as soon as they are no longer needed.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_addSpotmeter(LS_AddSpotmeter_t* io_cmd );

/**
 *
 * @ingroup SDKCoreFunctions_GRP
 * @brief Use this function to add a group of spotmeters
 *
 * Use this function to add a group of spotmeters. On return the spotmeters are created/set and associated to the given context.
 *
 * Please refer to @ref LS_AddGridOfSpotmeters_t for details about the available spotmeter properties.
 *
 * @param[in,out]   io_cmd      Pointer to the command input/output data.
 *
 * @return @ref eLS_OK on success or any other @ref SDKCoreErrors_GRP "error code" otherwise.
 *
 * @remark
 * -   As soon as a spotmeter grid has been added it will evaluate and create results every time the "execute" method is called.
 * -   Only @ref LS_MAX_ANALYSIS analyses at the same time are supported
 * <br>Please see also @ref LS_GetGridOfSpotmetersInfo_t and @ref LS_GetGridOfSpotmetersResult_t.
 * The results are available until the next execute is called or the spotmeter is removed.
 * To keep the memory consumption as low as possile be sure to remove all added spotmeter as soon as they are no longer needed.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_addGridOfSpotmeters(LS_AddGridOfSpotmeters_t* io_cmd);


/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKCoreFunctions_GRP
 * @brief Use this function to add a rectangular spotmeter
 *
 * Use this function to add a rectangular spotmeter. On return the spotmeter is created/set and associated to the given context.
 *
 * Please refer to @ref LS_AddRectangularSpotmeter_t for details about the available spotmeter properties.
 *
 * @param[in,out]   io_cmd      Pointer to the command input/output data.
 *
 * @return @ref eLS_OK on success or any other @ref SDKCoreErrors_GRP "error code" otherwise.
 *
 * @remark
 * -   The returned <b>_out_spotmeterId</b> may be negative.
 * -   As soon as a spotmeter has been added it will evaluate and create results every time the "execute" method is called.
 * -   Only @ref LS_MAX_ANALYSIS analyses at the same time are supported
 * The results are available until the next execute is called or the spotmeter is removed.
 * To keep the memory consumption as low as possile be sure to remove all added spotmeter as soon as they are no longer needed.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_addRectangularSpotmeter(LS_AddRectangularSpotmeter_t* io_cmd );


/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKCoreFunctions_GRP
 * @brief Use this function to add a elliptical spotmeter
 *
 * Use this function to add a elliptical spotmeter. On return the spotmeter is created/set and associated to the given context.
 *
 * Please refer to @ref LS_AddEllipticalSpotmeter_t for details about the available spotmeter properties.
 *
 * @param[in,out]   io_cmd      Pointer to the command input/output data.
 *
 * @return @ref eLS_OK on success or any other @ref SDKCoreErrors_GRP "error code" otherwise.
 *
 * @remark
 * -   The returned <b>_out_spotmeterId</b> may be negative.
 * -   As soon as a spotmeter has been added it will evaluate and create results every time the "execute" method is called.
 * -   Only @ref LS_MAX_ANALYSIS analyses at the same time are supported
 * The results are available until the next execute is called or the spotmeter is removed.
 * To keep the memory consumption as low as possile be sure to remove all added spotmeter as soon as they are no longer needed.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_addEllipticalSpotmeter(LS_AddEllipticalSpotmeter_t* io_cmd);


/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKCoreFunctions_GRP
 * @brief Use this function to remove an previous added spotmeter / rectangular spotmeter
 *
 * Use this function to remove an spotmeter. On return the spotmeter data are deleted and
 * removed from the given context.
 *
 * Please refer to @ref LS_RemoveSpotmeter_t for details about the input parameters.
 *
 * @param[in]   in_cmd      Pointer to the command input/output data.
 *
 * @return @ref eLS_OK on success or any other @ref SDKCoreErrors_GRP "error code" otherwise.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_removeSpotmeter(const LS_RemoveSpotmeter_t* in_cmd );

/**
 * @ingroup SDKCoreFunctions_GRP
 * @brief Use this function to remove an previous added grid of spotmeters
 *
 * Use this function to remove an grid of spotmeters. On return the spotmeter data are deleted and
 * removed from the given context.
 *
 * Please refer to @ref LS_RemoveSpotmeter_t for details about the input parameters.
 *
 * @param[in]   in_cmd      Pointer to the command input/output data.
 *
 * @return @ref eLS_OK on success or any other @ref SDKCoreErrors_GRP "error code" otherwise.
 */
LS_SDK_Status_t LS_CALLCONV LS_removeSpotmeterGrid(const LS_RemoveSpotmeterGrid_t *io_cmd);


/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKCoreFunctions_GRP
 * @brief Use this function to add an line profile
 *
 * On return the line profile is created/set and associated to the given context.
 *
 * Please refer to @ref LS_LineProfile_t for details about the available line profile properties.
 *
 * @param[in,out]   io_cmd      Pointer to the command input/output data.
 *
 * @return @ref eLS_OK on success or any other @ref SDKCoreErrors_GRP "error code" otherwise.
 *
 * @remark
 * - The returned <b>_out_lineProfileId</b> may be negative.
 * - The given position values must be inside the image dimension
 * - Only @ref LS_MAX_ANALYSIS analyses at the same time are supported
 * - As soon as an line profile has been added it will evaluate and create results every time
 * the "execute" method is called. The results are available until the next execute is called or the line profile is removed.
 * To keep the memory consumption as low as possile be sure to remove all added line profile analysis as soon as they a
 * re no longer needed.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_addLineProfile(LS_AddLineProfile_t* io_cmd );


/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKCoreFunctions_GRP
 * @brief Use this function to remove an previous added line profile
 *
 * On return the line profile is deleted and removed from the given context.
 *
 * Please refer to @ref LS_RemoveLineProfile_t for details about the input parameters.
 *
 * @param[in]   in_cmd      Pointer to the command input/output data.
 *
 * @return @ref eLS_OK on success or any other @ref SDKCoreErrors_GRP "error code" otherwise.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_removeLineProfile(const LS_RemoveLineProfile_t* in_cmd );


/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKCoreFunctions_GRP
 * @brief Use this function to add an bright dark analysis
 *
 * On return the bright dark analysis is created/set and associated to the given context.
 *
 * Please refer to @ref LS_AddBrightDarkAnalysis_t for details about the available properties.
 *
 * @param[in,out]   io_cmd      Pointer to the command input/output data.
 *
 * @return @ref eLS_OK on success or any other @ref SDKCoreErrors_GRP "error code" otherwise.
 *
 * @remark
 * - The returned <b>_out_brightDarkId</b> may be negative
 * - The given position values must be inside the image dimension
 * - Only @ref LS_MAX_ANALYSIS analyses at the same time are supported
 * - As soon as an bright dark analysis has been added it will evaluate and create results every time
 * the "execute" method is called. The results are available until the next execute is called or the bright dark analysis is removed.
 * To keep the memory consumption as low as possile be sure to remove all added analyses as soon as they a
 * are no longer needed.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_addBrightDarkAnalysis(LS_AddBrightDarkAnalysis_t* io_cmd );


/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKCoreFunctions_GRP
 * @brief Use this function to remove an previous added bright dark analysis
 *
 * On return the bright dark analysis is deleted and removed from the given context.
 *
 * Please refer to @ref LS_RemoveBrightDarkAnalysis_t for details about the input parameters.
 *
 * @param[in]   in_cmd      Pointer to the command input/output data.
 *
 * @return @ref eLS_OK on success or any other @ref SDKCoreErrors_GRP "error code" otherwise.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_removeBrightDarkAnalysis(const LS_RemoveBrightDarkAnalysis_t* in_cmd );


/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKCoreFunctions_GRP
 * @brief Use this function to add an Slanted Edge analysis
 *
 * On return the Slanted Edge analysis is created/set and associated to the given context.
 *
 * Please refer to @ref LS_AddSlantedEdgeAnalysis_t for details about the available slanted edge
 * properties.
 *
 * @param[in,out]   io_cmd      Pointer to the command input/output data.
 *
 * @return @ref eLS_OK on success or any other @ref SDKCoreErrors_GRP "error code" otherwise.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_addSlantedEdgeAnalysis(LS_AddSlantedEdgeAnalysis_t *io_cmd);

/* -----------------------------------------------------------------------------------------------
 */
/**
 *
 * @ingroup SDKCoreFunctions_GRP
 * @brief Use this function to remove an previous added Slanted Edge analysis
 *
 * On return the slanted edge analysis is deleted and removed from the given context.
 *
 * Please refer to @ref LS_RemoveSlantedEdgeAnalysis_t for details about the input parameters.
 *
 * @param[in]   in_cmd      Pointer to the command input/output data.
 *
 * @return @ref eLS_OK on success or any other @ref SDKCoreErrors_GRP "error code" otherwise.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_removeSlantedEdgeAnalysis(const LS_RemoveSlantedEdgeAnalysis_t *in_cmd);

/* ----------------------------------------------------------------------------------------------- */
/**
 * @ingroup SDKCoreFunctions_GRP
 * @brief Use this function to receive some information about the expected slanted edge analysis
 * result.
 *
 * This function returns the number of the slanted edge analysis result values. This function must
 * be used prior to the @ref LS_GetSlantedEdgeResult in order to preallocate the required
 * memory for the results values.
 *
 * @param[in]   io_cmd      Pointer to the command input/output data.
 *
 * Please refer also to @ref LS_execute and @ref LS_getSlantedEdgeResult
 *
 * @return eLS_OK on success, eLS_Error otherwise.
 *
 *
 * @remark
 *      -   In case measurement failed for the related line profile (e.g. due to coordinates
 *          outside the image) then there are no result values.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_getSlantedEdgeResultInfo(LS_GetSlantedEdgeResultInfo_t *io_cmd);

/* ----------------------------------------------------------------------------------------------- */
/**
 * @ingroup SDKCoreFunctions_GRP
 * @brief Use this function to receive all slanted edge analysis result
 *
 * This function returns all analysis results values for the slanted edge analysis indentified by
 * the given \a _in_slantedEdgeId and \a _in_channelIdx.
 *
 * @param[in]   io_cmd      Pointer to the command input/output data.
 *
 * @ref LS_execute
 *
 * @return eLS_OK on success, eLS_Error otherwise.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_getSlantedEdgeResult(LS_GetSlantedEdgeResult_t *io_cmd);


/* ----------------------------------------------------------------------------------------------- */
/**
 * @internal
 * @ingroup SDKCoreFunctions_GRP
 * @brief Use this function to add an Fourier Sharpness asnalysis
 *
 * On return the Fourier Sharpness analysis is created/set and associated to the given context.
 *
 * Please refer to @ref LS_AddFourierSharpnessAnalysis_t for details about the available Fourier
 * Sharpness properties.
 *
 * @param[in,out]   io_cmd      Pointer to the command input/output data.
 *
 * @return @ref eLS_OK on success or any other @ref SDKCoreErrors_GRP "error code" otherwise.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_addFourierSharpnessAnalysis(LS_AddFourierSharpnessAnalysis_t *io_cmd);

/* -----------------------------------------------------------------------------------------------
 */
/**
 * @internal
 * @ingroup SDKCoreFunctions_GRP
 * @brief Use this function to receive Fourier Sharpness analysis result
 *
 * This function returns all analysis result values for the Fourier Sharpness analysis indentified by
 * the given _in_channelIdx.
 *
 * @param[in]   io_cmd      Pointer to the command input/output data.
 *
 * @ref LS_execute
 *
 * @return eLS_OK on success, eLS_Error otherwise.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_getFourierSharpnessResult(LS_GetFourierSharpnessResult_t *io_cmd);


/* -----------------------------------------------------------------------------------------------
 */
/**
 * @internal
 * @ingroup SDKCoreFunctions_GRP
 * @brief Use this function to remove an previous added Fourier Sharpness analysis
 *
 * On return the Fourier Sharpness analysis is deleted and removed from the given context.
 *
 * Please refer to @ref LS_RemoveFourierSharpnessAnalysis_t for details about the input parameters.
 *
 * @param[in]   in_cmd      Pointer to the command input/output data.
 *
 * @return @ref eLS_OK on success or any other @ref SDKCoreErrors_GRP "error code" otherwise.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_RemoveFourierSharpnessAnalysis(LS_RemoveFourierSharpnessAnalysis_t* in_cmd);


/* -----------------------------------------------------------------------------------------------
 */
/**
 * @ingroup SDKCoreFunctions_GRP
 * @brief Use this function to receive information about count of spotmeters contained in the spotemters grid
 *
 * This function returns count of spotmeters for the grid of spotmeters
 *
 * @param[in]   io_cmd      Pointer to the command input/output data.
 *
 * @ref LS_execute
 *
 * @return eLS_OK on success, eLS_Error otherwise.
 *
 * @remark Use the following formula to calculate the memory size that must be allocated for the grid
 *         of spotmeters values:
 *         <br> <em>required_mem_size = _out_countOfSpotmeters * sizeof(LS_SpotmeterResult_t) </em>
 *         <br>Please see also @ref LS_AddGridOfSpotmeters_t and @ref LS_GetGridOfSpotmetersResult_t.
 *
 * @b Example:
 * @code{.c}
 *
 *   ...
 *   LS_GetGridOfSpotmetersInfo_t gridInfo;
 *   gridInfo._in_handle = contextHandle;
 *   gridInfo._in_gridId = addGridParams._out_id;
 *   error = LS_getGridOfSpotmetersInfo(&gridInfo);
 *
 *   LS_GetGridOfSpotmetersResult_t gridParams;
 *   gridParams._in_handle = contextHandle;
 *   gridParams._in_gridId = addGridParams._out_id;
 *   gridParams._in_channel = 0;
 *
 *   size_t sz = gridInfo._out_countOfSpotmeters * sizeof(LS_SpotmeterResult_t);
 *   gridParams._out_results = (LS_SpotmeterResult_t*)malloc(sz);
 *   memset((void*)gridParams._out_results, 0, sz);
 *
 *   stat = LS_getGridOfSpotmetersResult(&gridParams);
 *   ...
 * }
 * @endcode
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_getGridOfSpotmetersInfo(LS_GetGridOfSpotmetersInfo_t *io_cmd);

/* -----------------------------------------------------------------------------------------------
 */
/**
 * @ingroup SDKCoreFunctions_GRP
 * @brief Use this function to receive grid of spotmeters  analysis result
 *
 * This function returns all analysis results values for the grid of spotmeters analysis indentified by
 * the given _in_channel.
 *
 * @param[in]   io_cmd      Pointer to the command input/output data.
 *
 * @ref LS_execute
 *
 * @return eLS_OK on success, eLS_Error otherwise.
 *
 *  @remark Use the following formula to calculate the memory size that must be allocated for the grid
 *         of spotmeters values:
 *         <br> <em>required_mem_size = _out_countOfSpotmeters * sizeof(LS_SpotmeterResult_t) </em>
 *         <br>Please see also @ref LS_AddGridOfSpotmeters_t and @ref LS_GetGridOfSpotmetersInfo_t.
 *
 * @b Example:
 * @code{.c}
 *
 *   ...
 *   LS_GetGridOfSpotmetersInfo_t gridInfo;
 *   gridInfo._in_handle = contextHandle;
 *   gridInfo._in_gridId = addGridParams._out_id;
 *   error = LS_getGridOfSpotmetersInfo(&gridInfo);
 *
 *   LS_GetGridOfSpotmetersResult_t gridParams;
 *   gridParams._in_handle = contextHandle;
 *   gridParams._in_gridId = addGridParams._out_id;
 *   gridParams._in_channel = 0;
 *
 *   size_t sz = gridInfo._out_countOfSpotmeters * sizeof(LS_SpotmeterResult_t);
 *   gridParams._out_results = (LS_SpotmeterResult_t*)malloc(sz);
 *   memset((void*)gridParams._out_results, 0, sz);
 *
 *   stat = LS_getGridOfSpotmetersResult(&gridParams);
 *   ...
 * }
 * @endcode
 */
LS_SDK_Status_t LS_CALLCONV LS_getGridOfSpotmetersResult(LS_GetGridOfSpotmetersResult_t *io_cmd);

/* ----------------------------------------------------------------------------------------------- */
/**
 * @ingroup SDKCoreFunctions_GRP
 * @brief Use this function to receive a single slanted edge analysis result
 *
 * This function returns a single analysis result values for the slanted edge analysis indentified
 * by the given \a _in_slantedEdgeId, the \a _in_channelIdx and \a _in_Index.
 *
 * @param[in]   io_cmd      Pointer to the command input/output data.
 *
 * @ref LS_execute
 *
 * @return eLS_OK on success, eLS_Error otherwise.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_getSingleSlantedEdgeResult(LS_GetSingleSlantedEdgeResult_t *io_cmd);


/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKCoreFunctions_GRP
 * @brief Use this function to execute measurement analysis
 *
 * This funtion executes (runs all measurements) for the given image \a in_img_id.
 * Execution here refers to running measurements, whereas measurements are
 * defined by spotmeters, line profiles or any other analysis being created
 * in the context earlier.
 *
 * On return this function returns the number of image channels and an array with all
 * active analysis IDs.
 * <br>For each of these IDs the function @ref LS_getAnalysisType has to be called to
 * figure out the analysis type the ID belongs. After that the appropriate
 * function to get the specific result can be called (e.g. @ref LS_getSpotmeterResult must
 * be called to get spotmeter results) in order to retrieve the analysis results.
 *
 * Please use @ref LS_getAnalysisType to receive the analysis type for each ID
 *
 * Please use @ref LS_getSpotmeterResult to receive measurement results for all active spotmeter
 * and for all channels.
 *
 * Please use @ref LS_getLineProfileResult to receive measurement results for all active line
 * profiles and for all channels.
 *
 * NOTICE: at the moment, only one color space is allowed per context
 *
 * @param[in,out]   io_cmd    Pointer to the command input/output data.
 *
 * @return @ref eLS_OK on success or any other @ref SDKCoreErrors_GRP "error code" otherwise.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_execute(LS_Execute_t* io_cmd );


/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKCoreFunctions_GRP
 * @brief Use this function to get the analysis type for an analysis ID
 *
 * With the returned @ref LS_AnalysisType_t the assoziated function can be used
 * to get the dedicated result (e.g. spotmeter or line profile result).
 *
 * Please refer to @ref LS_GetAnalysisType_t for details about the available input/output parameter properties.
 *
 * @param[in,out]   io_cmd    Pointer to the command input/output data.
 *
 * @return @ref eLS_OK on success or any other @ref SDKCoreErrors_GRP "error code" otherwise.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_getAnalysisType(LS_GetAnalysisType_t * io_cmd);


/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKCoreFunctions_GRP
 * @brief Use this function to perform 2D Binning on an image
 *
 * This function performs an 2D binning on an image.
 *  *
 * Please refer to @ref LS_2dBinning_t for details about the available input/output parameter properties.
 *
 * @param[in]   io_cmd      Ptr. to the command input/output data.
 *
 * @return @ref eLS_OK on success or any other error code from @ref SDKCoreErrors_GRP "SDKCore Error Codes" or @ref SDKLColPageErrors_GRP "SDKLumiColDevice Error Codes" otherwise.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_run2dBinning (LS_2dBinning_t * io_cmd);


/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKCoreFunctions_GRP
 * @brief Use this function to execute analysis for one single spotmeter
 *
 * This function runs measurement for the given image \a in_img_id, \a _in_handle and the
 * given spotmeter \a _in_spotmeter.
 *
 * On return this function returns the number of channels and the spotmeter id of the
 * temporary created spotmeter. With these two values the @ref LS_getSpotmeterResult must
 * be called to get the spotmeter results (for each channel).
 *
 * Please use @ref LS_getSpotmeterResult to receive the measurement results for all channels.
 *
 * @param[in,out]   io_cmd      Pointer to the command input/output data.
 *
 * @return eLS_OK on success, eLS_Error otherwise.
 *
 * @remark
 *      This function is a convenient function and does the some as when one would call \a LS_addSpotmeter and
 *      \a LS_EXPORT with two commands. Thus, calling \a LS_calculateSpotmeter is much simpler to use.

 *@b Example:
 * @code{.c}
 *
 * // Startup ....
 * // start LumiSuite SDK, create context and take or load image
 * // ....
 * // set spotmeter properties
 * LS_CALCULATE_SPOTMETER_CMD(calculateSpotmeterInfo);
 * calculateSpotmeterInfo._in_imageId = image_id;
 * calculateSpotmeterInfo._in_spotmeter._in_posX = 70;
 * calculateSpotmeterInfo._in_spotmeter._in_posY = 80;
 * calculateSpotmeterInfo._in_spotmeter._in_shape = Circle;
 * calculateSpotmeterInfo._in_spotmeter._in_size = 5;
 * calculateSpotmeterInfo._in_spotmeter._in_resultColorSpace = ColorSpace_XYZ;
 *
 * // call LS_calculateSpotmeter
 * LS_SDK_Core_Status_t stat = LS_calculateSpotmeter( &calculateSpotmeterInfo);
 *
 * // walk through the results
 * for(int32_t l=0; l < calculateSpotmeterInfo._out_numChannels; l++ )
 * {
 *
 * 	  LS_SpotmeterResult_t spotmeterResult = calculateSpotmeterInfo._out_spotmeterResults[l];
 *    // use the spotmeter results
 *
 * }
 *
 * //
 * // destroy context and quit LumiSuite SDK
 * //
 *
 * @endcode
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_calculateSpotmeter(LS_CalculateSpotmeter_t * io_cmd);


/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKCoreFunctions_GRP
 * @brief Use this function to receive spotmeter results
 *
 * This function returns the related spotmeter result item. The funtions @ref LS_execute and
 * @ref LS_calculateSpotmeter return result details which are required to use this methode.
 *
 * @param[in]   io_cmd      Pointer to the command input/output data.
 *
 * @ref LS_execute
 * @ref LS_calculateSpotmeter
 *
 * @return eLS_OK on success, eLS_Error otherwise.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_getSpotmeterResult(LS_GetSpotmeterResult_t * io_cmd );


/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKCoreFunctions_GRP
 * @brief Use this function to receive some information about the expected line profile result.
 *
 * This function returns the number of the line profile result values. This function must be used
 * prior to the @ref LS_getLineProfileResult in order to preallocate the required memory
 * for the results values.
 *
 * @param[in]   io_cmd      Pointer to the command input/output data.
 *
 * Please refer also to @ref LS_execute and @ref LS_getLineProfileResult
 *
 * @return eLS_OK on success, eLS_Error otherwise.
 *
 *
 * @remark
 *      -   In case measurement failed for the related line profile (e.g. due to coordinates
 *          outside the image) then there are no result values.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_getLineProfileResultInfo(LS_GetLineProfileResultInfo_t * io_cmd);


/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKCoreFunctions_GRP
 * @brief Use this function to receive line profile results
 *
 * This function returns analysis result values for the line profile indentified by the given \a _in_lineProfileID.
 *
 * @param[in]   io_cmd      Pointer to the command input/output data.
 *
 * @ref LS_execute
 *
 * @return eLS_OK on success, eLS_Error otherwise.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_getLineProfileResult(LS_GetLineProfileResult_t * io_cmd );


/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKCoreFunctions_GRP
 * @brief Use this function to receive bright dark analysis results
 *
 * This function returns analysis result values for the bright dark analysis indentified by the given \a _in_brightDarkId.
 *
 * @param[in]   io_cmd      Pointer to the command input/output data.
 *
 * @ref LS_execute
 *
 * @return eLS_OK on success, eLS_Error otherwise.
 *
 * @remark
 *      -   In case measurement failed for the related bright dark analysis (e.g. due to coordinates
 *          outside the image) then an error (e.g. eLS_AnalysisResultNotFound) is returned
 *          and there are no result values.
 */
LS_SDK_Status_t LS_CALLCONV LS_getBrightDarkAnalysisResult(LS_GetBrightDarkAnalysisResult_t* io_cmd );


/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKCoreFunctions_GRP
 * @brief Use this function to rotate an image in intervals of 90 degree
 *
 * This function can be used to rotate an image in 90 degree steps. The original image is \a not changed but the function
 * returns an image id of the rotated image.
 *
 * Please refer to @ref LS_RotateImage90DegreeSteps_t for details about the input/output parameters.
 *
 * @param[in,out]  io_cmd      Pointer to the command input/output data.
 *
 * @return @ref eLS_OK on success or any other @ref SDKCoreErrors_GRP "error code" otherwise.
 *
 * @remark
 *  -   Rotation works only clockwise in 90° intervals.
 *  -   Allowed values are 1 for 90°, 2 for 180° and 3 for 270° rotation
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_rotateImage90DegreeSteps(LS_RotateImage90DegreeSteps_t* io_cmd );


/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKCoreFunctions_GRP
 * @brief Use this function to rotate an image
 *
 * This function can be used to rotate an image. The original image is \a not changed but the function
 * returns an image id of the rotated image.
 *
 * Please refer to @ref LS_RotateImage_t for details about the input/output parameters.
 *
 * @param[in,out]  io_cmd      Pointer to the command input/output data.
 *
 * @return @ref eLS_OK on success or any other @ref SDKCoreErrors_GRP "error code" otherwise.
 *
 * @remark
 *  -   Rotation works for +- 360 degree range
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_rotateImage(LS_RotateImage_t* io_cmd );

/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKCoreFunctions_GRP
 * @brief Use this function to load an recipe
 *
 * When the recipe file was successfully loaded the @ref LS_execute must be used to run
 * all the measurements of the analysis.
 *
 * Please refer to @ref LS_LoadRecipe_t for details about the input/output parameters.
 *
 * Please refer also to @ref LS_execute
 *
 * @param[in,out]  io_cmd      Pointer to the command input/output data.
 *
 * @return @ref eLS_OK on success or any other @ref SDKCoreErrors_GRP "error code" otherwise.
 *
 * @remark
 *  -   Loading an recipe removes all existing/added measurement analysis items (spotmeter, line profiles, bright dark analysis ...).
 *      Any related analysis ID becomes invalid.
 *  -   Only one recipe can be loaded. In case there is already one recipe loaded then it is removed befor loading a new one.
 *  -   Recipe may contain measurement analysis that are not supported by the
 *      LumiSuite SDK. Thus, results are only available for those measurement analysis that are
 *      supported.
 *  -   Recipes are always loaded even they contain not supported analysis.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_loadRecipe(LS_LoadRecipe_t* io_cmd );


/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKCoreFunctions_GRP
 * @brief Use this function to load an LSProj
 *
 * Please refer to @ref LS_LoadProj_t for details about the input/output parameters.
 *
 * @param[in,out]  io_cmd      Pointer to the command input/output data.
 *
 * @return @ref eLS_OK on success or any other @ref SDKCoreErrors_GRP "error code" otherwise.
 *
 * @remark
 *  -   Only one Project can be loaded. In case there is already one Project loaded, then it is removed before loading a new one.
 *  -   Currently LS_loadProj enables access to all images included in the loaded Project. The LS_LoadProj_t _out_imageIds
 *      parameter is an array containing all image handles of the loaded Project. The LS_LoadProj_t _out_imageNames parameter is
 *      an array containing all image names.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_loadProj(LS_LoadProj_t * io_cmd);



/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKCoreFunctions_GRP
 * @brief Use this function to calculate the uniformity of an image.
 *
 * Please refer to @ref LS_CalculateUniformity_t for details about the input/output parameters.
 *
 * @param[in,out]  io_cmd      Pointer to the command input/output data.
 *
 * @return @ref eLS_OK on success or any other @ref SDKCoreErrors_GRP "error code" otherwise.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_calculateUniformity(LS_CalculateUniformity_t* io_cmd );


/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKCoreFunctions_GRP
 * @brief   Serialize image to memory buffer
 *
 * This function can be used to get the required information to display an LumiSuite SDK Image as Bitmap.
 *
 * The function \a LS_getBitmapInfo must be called prior to get bitmap info in order to calculate
 * the memory size for the target buffer where the bitmap is serialized to.
 *
 * Please see also @ref LS_getBitmapData.
 *
 * @param[in,out]   io_cmd  Pointer to the command input/output data.
 *
 * @return @ref eLS_OK on success or any other @ref SDKCoreErrors_GRP "error code" otherwise.
 *
 * @remark
 * - The returned information depend on the image format (e.g. RAW or XYZ)
 * - Please take a look at the description of the returned information.
 * - Take care of the _out_stride parameter, it has to be used for saving a bitmap file, to indicate the bitmap stride
 *
 * @b Example:
 * @code{.c}
 *
 * // Get the bitmap info
 * LS_GetBitmapInfo_t bitmapInfo;
 * bitmapInfo._in_imageId = image_id;
 * bitmapInfo._out_arraySize = 0;
 * bitmapInfo._out_bytesPerPixel = 0;
 * bitmapInfo._out_stride = 0;
 * LS_SDK_Status_t status = LS_getBitmapInfo(&bitmapInfoCmd_1);
 *
 * @endcode
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_getBitmapInfo(LS_GetBitmapInfo_t* io_cmd);


/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKCoreFunctions_GRP
 * @brief   Serialize image to memory buffer
 *
 * This function can be used to serialize an image into an Bitmap buffer. This data can then be
 * used to create an windows compatible Bitmap (e.g. to be displayed on screen).
 *
 * The function \a LS_getBitmapInfo must be called prior to get all required information
 * to calculate the memory size for the target buffer where the bitmap data is serialized into.
 *
 * The Bitmap data returned is either
 *  using a 24-bit RGB format (8-8-8)
 * or
 *  using a 8-bit indexed format (index into an gray scale color palette)
 *
 * Please see also @ref LS_getBitmapInfo.
 *
 * @param[in,out]   io_cmd  Pointer to the command input/output data.
 *
 * @return @ref eLS_OK on success or any other @ref SDKCoreErrors_GRP "error code" otherwise.
 *
 * @remark
 * - The \a io_cmd._out_image_data must be a pointer to allocated memory where the bitmap data can be serialized into.
 * - The caller must allocate the memory for the image and take care to delete as soon as the data are no longer needed.
 * - The size of the allocated memory buffer must be sufficient to serialize the image otherwise the application would crash
 *
 * @b Example:
 * @code{.c}
 *
 * // allocate memory and get the bitmap data
 * LS_GetBitmapData_t bitmapData;
 * bitmapData._in_imageId = image_id;
 * bitmapData._in_contrastLevel = None;
 * bitmapData._out_data = (BYTE*)calloc(bitmapInfo._out_arraySize, sizeof(BYTE));
 * memset(bitmapData._out_data, 0xFF, bitmapInfo._out_arraySize);
 * LS_SDK_Status_t status = LS_getBitmapData(&bitmapData);
 *
 * @endcode
 */
LS_SDK_Status_t LS_CALLCONV LS_getBitmapData(LS_GetBitmapData_t* io_cmd);


/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKCoreFunctions_GRP
 * @brief   Find display in image and return coordinates
 *
 * This function searches for display-like structure on a given image
 * and returns a set of four points enclosing the display found.
 *
 * @param[in,out]  io_cmd  Pointer to the command input/output data.
 *
 * @return @ref eLS_OK on success or @ref SDKCoreErrors_GRP "error code" otherwise.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_findDisplay( LS_FindDisplay_t* io_cmd );



/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKCoreFunctions_GRP
 * @brief   Crop given image and return a new cropped image
 *
 * This function creates a cropped copy of a given image and returns the
 * ID of the cropped image for later retrieval.
 * The cropped image will become part of the internal image pool
 * and must be deleted explicitely to free allocated resources.
 *
 * See also @ref LS_findDisplay
 *
 * @param[in,out]  io_cmd  Pointer to the command input/output data.
 *
 * @return @ref eLS_OK on success or @ref SDKCoreErrors_GRP "error code" otherwise.
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_autoCropImage(LS_AutoCropImage_t* io_cmd);

/* ----------------------------------------------------------------------------------------------- */
/**
 *
 * @ingroup SDKCoreFunctions_GRP
 * @brief   Applies multi point correction image to an specific image
 *
 * This function applies a multi point correction image to a specific image
 *
 *
 * @param[in,out]  io_cmd  Pointer to the command input/output data.
 *
 * @return @ref eLS_OK on success or @ref SDKCoreErrors_GRP "error code" otherwise.
 *
 * @remark
 *          - Use the following code sample to apply an correction image to an specific image:
 *            <br>Please see @ref LS_generateMultiPointCorrection.
 *
 *
 */
LS_SDK_Status_t LS_CALLCONV LS_applyMultiPointCorrection(LS_ApplyMultiPointCorrection_t* io_cmd);


#ifdef __cplusplus
}
#endif






#endif //SDK_CORE_H
