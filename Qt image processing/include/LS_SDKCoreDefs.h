/**
 *
 *  @ingroup SDKCorePageDataStructs_GRP
 *  @file    LS_SDKCoreDefs.h
 *  @brief   This header files provides all defines, type definitions, data structures and makros
 *           that are required to use the SDKCore functions.
 *
 */

#ifndef LS_SDK_CORE_DEFS_H
#define LS_SDK_CORE_DEFS_H

// #include <stdint.h>

//-- the following is only required when generating the C# import classes
//-- for this the include to stdint.h needs to be commented out (due to parsing errors)
typedef int int32_t;
typedef unsigned uint32_t;
typedef unsigned char uint8_t;
typedef short int16_t;
typedef unsigned short uint16_t;

//----------------------------------------

/* -----------------------------------------------------------------------
 *
 * definitions
 *
 * -------------------------------------------------------------------- */

/**
 * @ingroup SDKCorePageDefinitions_GRP
 * @brief LS_NO_LOGGING
 */
#define LS_NO_LOGGING 0

/**
 * @ingroup SDKCorePageDefinitions_GRP
 * @brief LS_MAX_VERSION_LEN
 */
#define LS_MAX_VERSION_LEN 20

/**
 * @ingroup SDKCorePageDefinitions_GRP
 * @brief LS_MAX_FILENAME_LEN
 */
#define LS_MAX_FILENAME_LEN 1024

/**
 * @ingroup SDKCorePageDefinitions_GRP
 * @brief LS_MAX_IMAGE_HANDLES
 */
#define LS_MAX_IMAGE_HANDLES 256

/**
 * @ingroup SDKCorePageDefinitions_GRP
 * @brief LS_NO_SHAPES
 */
#define LS_NO_SHAPES 0

/**
 * @ingroup SDKCorePageDefinitions_GRP
 * @brief LS_WITH_SHAPES
 */
#define LS_WITH_SHAPES 1

/**
 * @ingroup SDKCorePageDefinitions_GRP
 * @brief LS_MAX_FORMAT_LEN
 */
#define LS_MAX_FORMAT_LEN 20

/**
 * @ingroup SDKCorePageDefinitions_GRP
 * @brief LS_MAX_RESULT_LEN
 */
#define LS_MAX_RESULT_LEN 1024

/**
 * @ingroup SDKCorePageDefinitions_GRP
 * @brief LS_MAX_CHANNELS
 */
#define LS_MAX_CHANNELS 16

/**
 * @ingroup SDKCorePageDefinitions_GRP
 * @brief LS_MAX_SPOTMETER_CHANNELS
 */
#define LS_MAX_SPOTMETER_CHANNELS 3

/**
 * @ingroup SDKCorePageDefinitions_GRP
 * @brief LS_MAX_CHANNEL_NAME_LEN
 */
#define LS_MAX_CHANNEL_NAME_LEN 8

/**
 * @ingroup SDKCorePageDefinitions_GRP
 * @brief LS_MAX_ANALYSIS
 */
#define LS_MAX_ANALYSIS 256

/**
 * @ingroup SDKCorePageDefinitions_GRP
 * @brief LS_MAX_CALIBRATION_NAME_LEN
 */
#define LS_MAX_CALIBRATION_NAME_LEN 32

/**
 * @ingroup SDKCorePageDefinitions_GRP
 * @brief LS_MAX_CALIBRATION_COMMENT_LEN
 */
#define LS_MAX_CALIBRATION_COMMENT_LEN 256

/**
 * @ingroup SDKCorePageDefinitions_GRP
 * @brief LS_MAX_USER_CALIBRATIONS
 */
#define LS_MAX_USER_CALIBRATIONS 32

/**
 * @ingroup SDKCorePageDefinitions_GRP
 * @brief LS_MAX_COMMAND_LEN
 */
#define LS_MAX_COMMAND_LEN 512

/**
 * @ingroup SDKCorePageDefinitions_GRP
 * @brief LS_MAX_COMMAND_RESULT_LEN
 */
#define LS_MAX_COMMAND_RESULT_LEN 4096

/**
 * @ingroup SDKCorePageDefinitions_GRP
 * @brief LS_MAX_SERIAL_NUMBER_LEN
 */
#define LS_MAX_SERIAL_NUMBER_LEN 32

/**
 * @ingroup SDKCorePageDefinitions_GRP
 * @brief LS_MAX_DEVICE_TYPE_LEN
 */
#define LS_MAX_DEVICE_TYPE_LEN 32

/**
 * @ingroup SDKCorePageDefinitions_GRP
 * @brief LS_MAX_NUMBER_DEVICES
 */
#define LS_MAX_NUMBER_DEVICES 50

/**
 * @ingroup SDKCorePageDefinitions_GRP
 * @brief LS_MAX_IMAGE_NAME_LEN
 */
#define LS_MAX_IMAGE_NAME_LEN 200

/**
 * @ingroup SDKCorePageDefinitions_GRP
 * @brief LS_MAX_NUMBER_LT_FLICKER_DATA
 */
#define LS_MAX_NUMBER_LT_FLICKER_DATA 2048

/**
 * @ingroup SDKCorePageDefinitions_GRP
 * @brief LS_MAX_IMAGE_CHANNELS
 */
#define LS_MAX_IMAGE_CHANNELS 10

/**
 * @ingroup SDKCorePageDefinitions_GRP
 * @brief LS_MAX_COLOR_COORDINATE_LEN
 */
#define LS_MAX_COLOR_COORDINATE_LEN 10

/**
 * @ingroup SDKCorePageDefinitions_GRP
 * @brief LS_STATUS_ERROR_TEXT_LEN
 */
#define LS_STATUS_ERROR_TEXT_LEN 1024


/**
 * @ingroup SDKCorePageDefinitions_GRP
 * @brief LS_MAX_PARAM_PAIRS_DC_CAL
 */
#define LS_MAX_PARAM_PAIRS_DC_CAL 50


/**
 * @ingroup SDKCorePageDefinitions_GRP
 * @brief SDK_CORE_STATUS_OK
 */
#define SDK_CORE_STATUS_OK 0

/**
 * @ingroup SDKCorePageDefinitions_GRP
 * @brief SDK_CORE_STATUS_FAILURE
 */
#define SDK_CORE_STATUS_FAILURE 1


/* -----------------------------------------------------------------------
 *
 * Type definitions
 *
 * -------------------------------------------------------------------- */

/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_Handle_t
 */
typedef int32_t LS_Handle_t;

/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_ImageId
 */
typedef int32_t LS_ImageId_t;

/* -----------------------------------------------------------------------------------------------
 */
/**
 * @ingroup SDKCoreDEFAULT_GRP
 * @brief LS_INVALID_HANDLE
 * This defines an const value for an invalid handle. Please use this const value to
 * verify connection or context handles.
 */
#define LS_INVALID_HANDLE -1

/* -----------------------------------------------------------------------------------------------
 */
/**
 * @ingroup SDKCoreDEFAULT_GRP
 * @brief LS_INVALID_IMAGE_ID
 * This defines an const value for an invalid image id. Please use this const value to
 * verify image ids.
 */
#define LS_INVALID_IMAGE_ID -1

/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_SDK_PassFail_t
 *
 * Types of pass/fail results
 *
 */
typedef enum {
    /// Calculation performed and passed criteria
    LS_SDK_Pass,

    /// Calculation performed and failed criteria
    LS_SDK_Fail,

    /// Calculation not performed
    LS_SDK_NotPerformed

} LS_SDK_PassFail_t;

/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_SDK_ExposureMode_t
 */
typedef enum {
    /// Fixed exposure time - set by user
    LS_SDK_Exposure_Fixed,

    /// Auto exposure
    LS_SDK_Exposure_Auto

} LS_SDK_ExposureMode_t;

/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_SDK_LEDMode_t
 */
typedef enum {
    /// Automatic mode: the LED is powered off during measurements
    LS_SDK_LED_Auto,

    /// Manual mode: LED is always on
    LS_SDK_LED_AllwaysOn,

    /// Manual mode: LED is always off
    LS_SDK_LED_AllwaysOff

} LS_SDK_LEDMode_t;

/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_SDK_AquisitionMode_t
 */
typedef enum {
    /// hybrid mode
    LS_SDK_AquMode_Hybrid,

    /// 2D Chroma mode
    LS_SDK_AquMode_Chroma,

} LS_SDK_AquisitionMode_t;

/**
 * @ingroup SDKLumiTOPPageDataStructs_GRP
 * @brief LS_SDK_CasInterfaceType_t
 */
typedef enum {
    /// PCI - CAS Interface
    LS_SDK_CAS_PCI = 0,

    /// USB - CAS Interface
    LS_SDK_CAS_USB,

    /// PCI Express - CAS Interface
    LS_SDK_CAS_PCIExpress,

    /// Ethernet - CAS Interface
    LS_SDK_CAS_Ethernet

} LS_SDK_CasInterfaceType_t;

/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_PassFail_Float_t
 */
typedef struct {
    /// result
    LS_SDK_PassFail_t _passFail;
    /// value
    float _value;
} LS_PassFail_Float_t;

/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_Margins_t
 */
typedef struct {
    /// top margin
    int _top;

    /// right margin
    int _right;

    /// bottom margin
    int _bottom;

    /// left margin
    int _left;
} LS_Margins_t;

/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_Quadrangle_t
 */
typedef struct {
    /// x coordinate of the first point (top left)
    float _x1;

    /// y coordinate of the first point (top left)
    float _y1;

    /// x coordinate of the second point (top right)
    float _x2;

    /// y coordinate of the second point (top right)
    float _y2;

    /// x coordinate of the third point (bottom right)
    float _x3;

    /// y coordinate of the third point (bottom right)
    float _y3;

    /// x coordinate of the fourth point (bottom left)
    float _x4;

    /// y coordinate of the fourth point (bottom left)
    float _y4;
} LS_Quadrangle_t;

/* -----------------------------------------------------------------------------------------------
 */
/**
 * @ingroup SDKCoreDEFAULT_GRP
 * @brief LS_INVALID_ANALYSIS_ID
 * This defines an const value for an invalid analysis id. Please use this const value to
 * verify spotmeter ids.
 */
#define LS_INVALID_ANALYSIS_ID -99

/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_SDK_AnalysisType_t
 */
typedef enum {
    /// unknown type
    LS_SDK_Analysis_Unknown,

    /// analysis spotmeter
    LS_SDK_Analysis_Spotmeter,

    /// analysis line profile
    LS_SDK_Analysis_LineProfile,

    /// analysis bright dark spot
    LS_SDK_Analysis_BrightDarkSpot,

    /// analysis slanted edge
    LS_SDK_Analysis_SlantedEdge,

    /// analysis rectangular spotmeter
    LS_SDK_Analysis_RectangularSpotmeter,

    /// analysis grid of spotmeters
    LS_SDK_Analysis_GridOfSpotmeters,

    /// analysis Fourier Sharpness
    LS_SDK_Analysis_FourierSharpness,


} LS_SDK_AnalysisType_t;

/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_SDK_Core_LogMsgType_t
 */
typedef enum {
    /// The log entry is an informational entry
    LS_SDK_LogInfo,

    /// The log entry is an error entry
    LS_SDK_LogError,

    /// The log entry is a critical error entry
    LS_SDK_LogCritical

} LS_SDK_Core_LogMsgType_t;

/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief The LoggingCallback function can be used to log all LumiSuite SDK activities. When set the
 * function is called every time the LumiSuite SDK writes an log entry. The logging callback is
 * optional and can be set when @ref LS_start is called.
 *
 * Example:
 * @code{.c}
 * void __cdecl MyLoggingCallback(LS_SDK_Core_LogMsgType_t logMsgType, const char * pLogMessage)
 * {
 *      // do something, e.g. write log entry to own logging file
 * }
 *
 * int32_t main( void )
 * {
 *    LS_SDK_Core_Status_t stat = LS_start( &MyLoggingCallback );
 *
 *    // do something
 *
 *    stat = LS_quit();
 *    QVERIFY2(stat== eLS_OK,"LS_quit failed");
 * }
 * @endcode
 */
typedef void(__cdecl *LoggingCallback)(LS_SDK_Core_LogMsgType_t logMsgType,
                                       const char *pLogMessage);

/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_SDK_ColorSpace_t
 *
 * Currently supported color spaces.
 *
 */
typedef enum {
    /// The default:  auto detection
    /// The use color space depends on the image color space and the recipe global color space
    LS_SDK_ColorSpace_Auto,

    /// Color space XYZ
    LS_SDK_ColorSpace_XYZ,

    /// Color space Lvxy
    LS_SDK_ColorSpace_Lvxy,
    // For future use

    //    /// color space Lvuv
    //    LS_SDK_ColorSpace_Lvuv,

    //    /// color space Yuv
    //    LS_SDK_ColorSpace_Yuv

} LS_SDK_ColorSpace_t;

/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_SDK_SaveFileType_t
 */
typedef enum {
    /// File type FITS (Flexible Image Transport System)
    LS_SDK_FileType_FITS,

    /// File type CSV
    LS_SDK_FileType_CSV,

    /// File type LSIMG
    LS_SDK_FileType_LSIMG

} LS_SDK_SaveFileType_t;

/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_SDK_LuminanceKernelSizeOfAveraging_t
 */
typedef enum {
    /// No averaging
    LS_SDK_Average_None,

    /// Average 3
    LS_SDK_Average_3,

    /// Average 5
    LS_SDK_Average_5,

    /// Average 7
    LS_SDK_Average_7,

    /// Average 9
    LS_SDK_Average_9,

    /// Average 11
    LS_SDK_Average_11,

    /// Average 13
    LS_SDK_Average_13

} LS_SDK_LuminanceKernelSizeOfAveraging_t;

/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_SaveFile_t
 *
 * Please refer also to @ref LS_saveFileDefault
 */
typedef struct {
    /// ID of the image to save
    LS_ImageId_t _in_imageId;

    /// The name of the target file, including full path
    /// Use UTF-8 encoding
    char _in_destFileName[LS_MAX_FILENAME_LEN];

    /// File type for the target file (only file type FITS, CSV and LSimg are supported)
    LS_SDK_SaveFileType_t _in_FileType;

} LS_SaveFile_t;

/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_LoadImage_t
 *
 * Please refer also to @ref LS_loadImageDefault and macro @ref LS_LOAD_IMAGE_CMD
 */
typedef struct {
    /// Full file name of the file to load.
    /// Use UTF-8 encoding
    char _in_fileName[LS_MAX_FILENAME_LEN];

    /// id of the loaded image
    LS_ImageId_t _out_imageId;

} LS_LoadImage_t;

/**
 * @ingroup SDKCorePageDataStructs_GRP
 *  @brief LS_GetVersion_t
 */
typedef struct {
    /// version info
    char _out_version[LS_MAX_VERSION_LEN];

} LS_GetVersion_t;

/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_GetImage_t
 */
typedef struct {
    /// ID of the image to apply
    LS_ImageId_t _in_imageId;

    /// ptr where to copy image data
    /// <br>On input \a _out_data must be a valid pointer to allocated memory where the image can be
    /// serialized into <br>On output \a _out_data itself is not changed and refers to memory where
    /// the image data has been copied into.
    float *_out_data;

    /// Color space of the image
    LS_SDK_ColorSpace_t _out_colorspace;

    /// Channel content of the image
    char _out_channelContent[LS_MAX_IMAGE_CHANNELS][LS_MAX_COLOR_COORDINATE_LEN];

} LS_GetImage_t;

/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_GetImageInfo_t
 *
 * Please refer also to @ref LS_getImageInfoDefault
 *
 * @remark Use the following formula to calculate the memory size that must be allocated for the
 * image: <br> <em>required_mem_size = _out_width * _out_height * _out_channels * sizeof(float)</em>
 */
typedef struct {
    /// ID of the image
    LS_ImageId_t _in_imageId;

    /// Image width
    int32_t _out_width;

    /// Image height
    int32_t _out_height;

    /// Number of channels
    int32_t _out_channels;

} LS_GetImageInfo_t;

/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_SDK_Shape_t
 */
typedef enum {
    /// circle shape
    LS_SDK_Shape_Circle,

    /// square shape
    LS_SDK_Shape_Square

} LS_SDK_Shape_t;

/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_Spotmeter_t
 *
 * Please initialize variables of this type with @ref LS_spotmeterDefault
 *
 */
typedef struct {
    /// x-Position (top left position)
    float _in_posX;

    /// y-Position (top left position)
    float _in_posY;

    /// Shape type (Circle or Square)
    LS_SDK_Shape_t _in_shape;

    /// radius or half square size
    float _in_size;

    /// Color space of results
    LS_SDK_ColorSpace_t _in_resultColorSpace;

} LS_Spotmeter_t;

/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_RectangularSpotmeter_t
 *
 * Please initialize variables of this type with @ref LS_rectangularSpotmeterDefault
 *
 */
typedef struct {
    /// x-Position (top left position)
    float _in_posX;

    /// y-Position (top left position)
    float _in_posY;

    /// width of the rectangular spotmeter
    float _in_width;

    /// height of the rectangular spotmeter
    float _in_height;

    /// Color space of results
    LS_SDK_ColorSpace_t _in_resultColorSpace;

} LS_RectangularSpotmeter_t;


/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_GridSpotmeter_t
 *
 * Please initialize variables of this type with @ref LS_gridSpotmeterDefault
 *
 */
typedef struct {

    /// width of the spotmeter
    float _in_width;

    /// height of the spotmeter
    float _in_height;

    /// Color space of results
    LS_SDK_ColorSpace_t _in_resultColorSpace;

} LS_GridSpotmeter_t;

/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_BrightDark_t
 *
 */
typedef struct {
    /// x-Position (Start X position)
    float _in_posX;

    /// y-Position (Start Y position)
    float _in_posY;

    /// width size
    float _in_width;

    /// hight size
    float _in_height;

    /// Binning factor, min = 1, max = 9
    uint32_t _in_binning_factor;

    /// full image mode
    /// if the flag is true then position and size are
    /// ignored and the image size is used
    bool _in_full_image_mode;

} LS_BrightDark_t;

/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_LineProfile_t
 *
 * Please initialize variables of this type with @ref LS_lineProfileDefault
 *
 */
typedef struct {
    /// x1-Position (Start X position)
    /// Valus must be >= 0.0
    float _in_posX1;

    /// y1-Position (Start Y position)
    /// Value must be >= 0.0
    float _in_posY1;

    /// x2-Position (End X Position)
    /// Value must be <= image width
    float _in_posX2;

    /// y2-Position (End Y Position)
    /// Value must be <= image hight
    float _in_posY2;

    /// line width / thickness
    /// must be >= 1.0
    float _in_width;

    /// Color space of results
    LS_SDK_ColorSpace_t _in_resultColorSpace;

} LS_LineProfile_t;

/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_AddSpotmeter_t
 *
 *  * Please initialize variables of this type with @ref LS_addSpotmeterDefault
 */
typedef struct {
    /// Context handle
    LS_Handle_t _in_handle;

    /// Spotmeter
    LS_Spotmeter_t _in_spotmeter;

    ///  spotmeter id
    int32_t _out_spotmeterId;

} LS_AddSpotmeter_t;


/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_AddRectangularSpotmeter_t
 *
 *  * Please initialize variables of this type with @ref LS_addRectangularSpotmeterDefault
 */
typedef struct {
    /// Context handle
    LS_Handle_t _in_handle;

    /// Spotmeter
    LS_RectangularSpotmeter_t _in_spotmeter;

    ///  spotmeter id
    int32_t _out_spotmeterId;

} LS_AddRectangularSpotmeter_t;


/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_AddGridOfSpotmeters_t
 *
 *  * Please initialize variables of this type with @ref LS_addSpotmeterDefault
 */
  typedef struct {

    /// Data for the spotmeters in the grid.
    LS_GridSpotmeter_t _in_spotmeter;

    /// Handle of the context
    LS_Handle_t _in_handle;

    /// grid columns
    int _in_columns;

    /// grid rows
    int _in_rows;

    /// Spotmeter shape
    LS_SDK_Shape_t _in_shape;

    /// x-Position (top left position of grid)
    float _in_gridX;

    /// y-Position (top left position of grid)
    float _in_gridY;

    /// grid width
    float _in_gridWidth;

    /// grid height
    float _in_gridHeight;

    /// spotmeter grid id
    int32_t _out_spotmeterGridId;

} LS_AddGridOfSpotmeters_t;

/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_AddEllipticalSpotmeter_t
 *
 *  * Please initialize variables of this type with @ref LS_addRectangularSpotmeterDefault
 */

typedef LS_AddRectangularSpotmeter_t LS_AddEllipticalSpotmeter_t;

/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_RemoveSpotmeter_t
 */
typedef struct {
    /// Context handle
    LS_Handle_t _in_handle;

    /// id of the spotmeter to remove
    int32_t _in_spotmeterId;

} LS_RemoveSpotmeter_t;

/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_RemoveSpotmeterGrid_t
 */
typedef struct {
    /// Context handle
    LS_Handle_t _in_handle;

    /// id of the spotmeter grid to remove
    int32_t _in_spotmeterGridId;

} LS_RemoveSpotmeterGrid_t;

/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_SpotmeterResult_t
 * The measurement result details for one single spotmeter
 */
typedef struct {
    /// Minum
    double _out_min;

    /// Maximum
    double _out_max;

    /// Average
    double _out_mean;

    /// Std. Deviation
    double _out_stdDev;

} LS_SpotmeterResult_t;

/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_GetGridOfSpotmetersInfo_t
 * The measurement info for grid of spotmeter
 *
 * Please refer also to @ref LS_GetGridOfSpotmetersResult_t
 */
typedef struct {

    /// context handle
    LS_Handle_t _in_handle;

    /// id of the grid
    int32_t _in_spotmeterGridId;

    /// count of spotmeters contained in grid
    uint32_t _out_countOfSpotmeters;

} LS_GetGridOfSpotmetersInfo_t;

/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_GetSpotmeterResult_t
 *
 * Please refer also to @ref LS_getSpotmeterResultDefault
 *
 */
typedef struct {
    /// context
    LS_Handle_t _in_handle;

    /// spotmeter ID
    int32_t _in_spotmeterId;

    /// channel index
    int32_t _in_channelIdx;

    /// spotmeter result
    LS_SpotmeterResult_t _out_result;

} LS_GetSpotmeterResult_t;


/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_GetGridOfSpotmetersResult_t
 *
 * Please refer also to @ref LS_GetGridOfSpotmetersInfo_t
 *
 */
typedef struct {

    ///context handle
    LS_Handle_t _in_handle;

    ///id of the grid
    int32_t _in_gridId;

    //channel of the image
    int32_t _in_channel;

    //spotmeter data (sorted line by line starting left top)
    //_out_results needs to be an array of the correct size.
    //the sdk assumes that the array size is columns*rows
    LS_SpotmeterResult_t *_out_results;

}LS_GetGridOfSpotmetersResult_t;


/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_CalculateSpotmeter_t
 *
 * Please refer also to @ref LS_calculateSpotmeterDefault
 */
typedef struct {
    /// Context handle
    LS_Handle_t _in_handle;

    /// Image id of the image to analyse
    LS_ImageId_t _in_imageId;

    /// Spotmeter data
    LS_Spotmeter_t _in_spotmeter;

    /// number of channels
    int32_t _out_numChannels;

    /// array of spotmeter results per channel
    /// There is a maximum of @ref LS_MAX_SPOTMETER_CHANNELS channels are assumed.
    LS_SpotmeterResult_t _out_spotmeterResults[LS_MAX_SPOTMETER_CHANNELS];

} LS_CalculateSpotmeter_t;

/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_Execute_t
 *
 * Please initialize variables of this type with @ref LS_executeDefault;
 */
typedef struct {
    /// Context handle
    LS_Handle_t _in_handle;

    /// Image id of the image to analyse
    LS_ImageId_t _in_imageId;

    /// number of channels
    int32_t _out_numChannels;

    /// array with ids of all analysis applied
    /// to the given context
    /// Valid ID's are unequal to @ref LS_INVALID_ANALYSIS_ID
    int32_t _out_analysisID[LS_MAX_ANALYSIS];

} LS_Execute_t;

/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_GetAnalysisType_t
 *
 */
typedef struct {
    /// Context handle
    LS_Handle_t _in_handle;

    /// analysis id
    int32_t _in_analysisID;

    /// LS analysis type
    LS_SDK_AnalysisType_t _out_analysisType;

} LS_GetAnalysisType_t;

/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_ManualCropImage_t
 *
 * Please initialize variables of this type with @ref LS_manualCropImageDefault;
 */
typedef struct {
    /// Image id of the image to be cropped
    LS_ImageId_t _in_imageId;

    /// X-Pos where to start cropping (sub pix allowed)
    float _in_posX;

    /// Y-Pos where to start cropping   (sub pix allowed)
    float _in_posY;

    /// width for cropping
    int32_t _in_width;

    /// height for cropping
    int32_t _in_height;

    /// the image id of the cropped image
    /// use @ref LS_getImage or @ref LS_saveImageToFile to receive the cropped image
    int32_t _out_croppedImageId;

} LS_ManualCropImage_t;

/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_SDK_CroppingAndFilling_BackgroundFilling_t
 *
 */
typedef enum
{
    /// None
    LS_SDK_CroppingAndFilling_BackgroundFilling_None,
    /// sets background to zero
    LS_SDK_CroppingAndFilling_BackgroundFilling_BackgroundToZero,
    /// uses image content to fill background
    LS_SDK_CroppingAndFilling_BackgroundFilling_ImageContent,

} LS_SDK_CroppingAndFilling_BackgroundFilling_t;

/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_SDK_CroppingAndFilling_AverageSize_t
 *
 */
typedef enum
{
    /// One
    LS_SDK_CroppingAndFilling_Average_One = 1,
    /// Three
    LS_SDK_CroppingAndFilling_Average_Three = 3,
    /// Five
    LS_SDK_CroppingAndFilling_Average_Five = 5,
    /// Seven
    LS_SDK_CroppingAndFilling_Average_Seven = 7,
    /// Nine
    LS_SDK_CroppingAndFilling_Average_Nine = 9,
    /// Eleven
    LS_SDK_CroppingAndFilling_Average_Eleven = 11,
    /// Thirteen
    LS_SDK_CroppingAndFilling_Average_Thirteen = 13

} LS_SDK_CroppingAndFilling_AverageSize_t;


/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_CroppingAndFilling_t
 *
 * Please initialize variables of this type with @ref LS_CroppingAndFillingDefault;
 */
typedef struct
{
    /// Image id of the image to be cropped
    LS_ImageId_t _in_imageId;

    /// Cropping offset
    LS_Margins_t _in_croppingOffset;

    /// Filling background of image
    LS_SDK_CroppingAndFilling_BackgroundFilling_t _in_imageBackgroundFilling;

    /// Filling offset
    uint16_t _in_fillingOffset;

    /// Average
    LS_SDK_CroppingAndFilling_AverageSize_t _in_average;

    /// Moving Average
    LS_SDK_CroppingAndFilling_AverageSize_t _in_movingAverage;

    /// Adaptive contour
    bool _in_adaptiveContour;

    /// Adaptive contour strength
    float _in_adaptiveContourStrength;

    /// the image id of the cropped image
    /// use @ref LS_getImage or @ref LS_saveImageToFile to receive the cropped image
    int32_t _out_croppedImageId;

} LS_CroppingAndFilling_t;


/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_MoireFilterImage_t
 *
 * Please initialize variables of this type with @ref LS_moireFilterImageDefault;
 */
typedef struct {
    /// Image id of the image to be corrected
    LS_ImageId_t _in_imageId;

    /// size of windowing (in pixel) - valid range is between 5 and 100
    int32_t _in_windowingSize;

    /// size of peak eraser (in pixel) - valid range is between 10 and 50
    int32_t _in_peakEraserSize;

    /// size of center where peaks are not removed (in pixel) - valid range is between 15 and 300
    int32_t _in_centerSize;

    /// size of gaussian blur filter used by the peak finder (in pixel) - valid range is between 2
    /// and 6
    int32_t _in_blurringSize;

    /// the image id of the moire filtered image
    /// use @ref LS_getImage or @ref LS_saveImageToFile to receive the moire filtered image
    LS_ImageId_t _out_correctedImageId;

} LS_MoireFilterImage_t;

/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_2dBinning_t
 *
 * Please refer also to @ref LS_2dBinningDefault and
 * @ref LS_2DBINNING_CMD
 *
 */
typedef struct {
    /// ID of the image the 2d binning shall be performed
    LS_ImageId_t _in_imageId;

    /// binning factor horizontical direction
    /// value can range from 1 to half width of the image.
    int32_t _in_factorX;

    /// binning factor vertical direction
    /// value can range from 1 to half height of the image.
    int32_t _in_factorY;

    /// the image id of the binned image
    /// use @ref LS_getImage or @ref LS_saveImageToFile to receive the cropped image
    LS_ImageId_t _out_binnedImageId;

} LS_2dBinning_t;

/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_LineProfileResult_t
 * The measurement result details for one single line profile
 */
typedef struct {
    /// The name of the channel the analysis values belong to
    char _out_channelName[LS_MAX_CHANNEL_NAME_LEN];

    /// ptr where to copy the analysis result values
    /// <br>On input \a _out_values must be a valid pointer to allocated memory where the analysis
    /// result values can be copied <br>On output \a _out_values itself is not changed and refers to
    /// memory where the analysis result values have been copied into.
    float *_out_values;

} LS_LineProfileResult_t;

/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_GetLineProfileResult_t
 *
 * Please refer also to @ref LS_lineProfileResultDefault
 *
 */
typedef struct {
    /// context
    LS_Handle_t _in_handle;

    /// line profile ID
    int32_t _in_lineProfileID;

    /// channel index
    int32_t _in_channelIdx;

    /// line profile result for the _in_channelIdx
    LS_LineProfileResult_t _out_result;

} LS_GetLineProfileResult_t;

/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_GetLineProfileResultInfo_t
 *
 * Please refer also to @ref LS_lineProfileResultInfoDefault
 *
 * @remark Use the following formula to calculate the memory size that must be allocated
 * for the line profile result:
 *    <br> <em>required_mem_size = _out_resultCount * sizeof(float)</em>
 *
 */
typedef struct {
    /// context
    LS_Handle_t _in_handle;

    /// line profile ID
    int32_t _in_lineProfileID;

    /// Number of result elements
    int32_t _out_resultCount;

} LS_GetLineProfileResultInfo_t;

/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_AddLineProfile_t
 *
 * Please initialize variables of this type with @ref LS_addLineProfileDefault
 *
 */
typedef struct {
    /// Context handle
    LS_Handle_t _in_handle;

    /// Spotmeter
    LS_LineProfile_t _in_lineProfile;

    ///  line profile id
    int32_t _out_lineProfileId;

} LS_AddLineProfile_t;

/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_RemoveLineProfile_t
 */
typedef struct {
    /// Context handle
    LS_Handle_t _in_handle;

    /// id of the line profile to remove
    int32_t _in_lineProfileId;

} LS_RemoveLineProfile_t;

/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_AddBrightDarkAnalysis_t
 *
 */
typedef struct {
    /// Context handle
    LS_Handle_t _in_handle;

    /// Bright dark analysis
    LS_BrightDark_t _in_brightDark;

    /// Bridght dark analysis id
    int32_t _out_brightDarkId;

} LS_AddBrightDarkAnalysis_t;

/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_RemoveBrightDarkAnalysis_t
 */
typedef struct {
    /// Context handle
    LS_Handle_t _in_handle;

    /// Bridght dark analysis id to remove
    int32_t _in_brightDarkId;

} LS_RemoveBrightDarkAnalysis_t;

/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief DarkestBrightestSpot_t
 *
 * This struct defines an darkest or brightest spot
 */
typedef struct {
    /// X-Position of the spot
    int32_t _posX;

    /// Y-Position of the spot
    int32_t _posY;

    /// Value of the spot
    float _value;

} DarkestBrightestSpot_t;

/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_GetBrightDarkAnalysisResult_t
 *
 */
typedef struct {
    /// Context handle
    LS_Handle_t _in_handle;

    /// Bridght dark analysis id
    int32_t _in_brightDarkId;

    /// Pos an value of the darkest spot
    DarkestBrightestSpot_t _out_DarkestSpot;

    /// Pos an value of the brightest spot
    DarkestBrightestSpot_t _out_BrightestSpot;

} LS_GetBrightDarkAnalysisResult_t;

/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_RegionOfInterest_t
 *
 * @remark
 * -    The region of interest cannot be bigger
 * than the image size
 *
 */
typedef struct {
    /// x-Position (Start X position)
    float _in_posX;

    /// y-Position (Start Y position)
    float _in_posY;

    /// width size
    float _in_width;

    /// hight size
    float _in_height;

    /// full image mode
    /// if the flag is true then position and size are
    /// ignored and the image size is used
    bool _in_full_image_mode;

} LS_RegionOfInterest_t;

/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_AddSlantedEdgeAnalysis_t
 *
 */
typedef struct
{
    /// Context handle
    LS_Handle_t _in_handle;

    /// Region of interest for the Slanted Edge Analysis
    LS_RegionOfInterest_t _in_slantedEdge;

    /// Slanted Edge analysis id
    int32_t _out_slantedEdgeId;

} LS_AddSlantedEdgeAnalysis_t;

/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_RemoveSlantedEdgeAnalysis_t
 */
typedef struct
{
    /// Context handle
    LS_Handle_t _in_handle;

    /// Bridght dark analysis id to remove
    int32_t _in_slantedEdgeId;

} LS_RemoveSlantedEdgeAnalysis_t;

/**
 * @brief LS_GetSlantedEdgeResultInfo_t
 *
 * @remark Use the following formula to calculate the memory size that must be allocated
 * for the slanted edge result:
 *    <br> <em>required_mem_size = _out_resultCount * sizeof(float)</em>
 *
 */
typedef struct
{
    /// context
    LS_Handle_t _in_handle;

    /// slanted edge analysis ID
    int32_t _in_slantedEdgeId;

    /// Number of result elements
    int32_t _out_resultCount;

} LS_GetSlantedEdgeResultInfo_t;

/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_GetSlantedEdgeResult_t
 *
 */
typedef struct
{
    /// context
    LS_Handle_t _in_handle;

    /// line profile ID
    int32_t _in_slantedEdgeId;

    /// channel index
    int32_t _in_channelIdx;

    /// all slanted edge results for the given \a _in_channelIdx
    /// ptr where to copy the analysis result values
    /// <br>On input \a _out_values must be a valid pointer to allocated memory where the analysis result values can be copied
    /// <br>On output \a _out_values itself is not changed and refers to memory where the analysis result values have been copied into.
    float * _out_values;

} LS_GetSlantedEdgeResult_t;

/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_GetSingleSlantedEdgeResult_t
 *
 */
typedef struct
{
    /// context
    LS_Handle_t _in_handle;

    /// slanted edge analysis ID
    int32_t _in_slantedEdgeId;

    /// channel index
    int32_t _in_channelIdx;

    /// index value
    /// This index must be in the interval 0 and below 1 (1.0 is excluded!)
    float _in_Index;

    /// slanted edge analysis result for the given \a _in_channelIdx and \a _in_Index
    float _out_value;

} LS_GetSingleSlantedEdgeResult_t;

/**
 * @internal
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_AddFourierSharpnessAnalysis_t
 *
 */
typedef struct
{
    /// Context handle
    LS_Handle_t _in_handle;

    /// x-Position (Start X position)
    float _in_posX;

    /// y-Position (Start Y position)
    float _in_posY;

    /// Square side length
    float _in_squareSideLength;

    /// Fourier Sharpness analysis id
    int32_t _out_fourierSharpnessId;

} LS_AddFourierSharpnessAnalysis_t;

/**
 * @internal
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_GetFourierSharpnessResult_t
 *
 */
typedef struct
{
    /// context
    LS_Handle_t _in_handle;

    /// line profile ID
    int32_t _in_fourierSharpnessId;

    /// channel index
    int32_t _in_channelIdx;

    /// relative Fourier power 1
    float _out_relativePower1;

    /// relative Fourier power 2
    float _out_relativePower2;


} LS_GetFourierSharpnessResult_t;


/**
 * @internal
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_RemoveFourierSharpnessAnalysis_t
 */
typedef struct {
    /// Context handle
    LS_Handle_t _in_handle;

    /// Fourier Sharpness analysis id to remove
    int32_t _in_fourierSharpnessId;

} LS_RemoveFourierSharpnessAnalysis_t;

/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_RotateImage90DegreeSteps_t
 *
 */
typedef struct {
    /// Image id of the image to be rotated
    LS_ImageId_t _in_imageId;

    /// Rotation flag
    /// Rotation works only clockwise in 90° intervals.
    /// Thus, allowed values are 1 for 90°, 2 for 180° and 3 for 270° rotation
    uint16_t _in_rotationFlag;

    /// the image id of the rotated image
    /// Use this Id for further operations with the rotated image. E.g.
    /// use @ref LS_getImage or @ref LS_saveImageToFile to receive or to save the rotated image
    int32_t _out_rotatedImageId;

} LS_RotateImage90DegreeSteps_t;

/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_RotateImage_t
 *
 */
typedef struct {
    /// Image id of the image to be rotated
    LS_ImageId_t _in_imageId;

    /// Rotation angle, allowed range: +- 360 degree
    float _in_rotationAngle;

    /// the image id of the rotated image
    /// Use this Id for further operations with the rotated image. E.g.
    /// use @ref LS_getImage or @ref LS_saveImageToFile to receive or to save the rotated image
    int32_t _out_rotatedImageId;

} LS_RotateImage_t;

/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_LoadRecipe_t
 *
 */
typedef struct {
    /// Context handle
    LS_Handle_t _in_handle;

    /// The name of the recipe file, including full path
    /// Use UTF-8 encoding
    char _in_recipeFileName[LS_MAX_FILENAME_LEN];

} LS_LoadRecipe_t;


/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_LoadProj_t
 *
 */
typedef struct {

    /// The name of the LSProj file, including full path
    /// Use UTF-8 encoding
    char _in_projFileName[LS_MAX_FILENAME_LEN];

    /// Number of detected images
    int32_t _out_imageCount;

    /// Array of image handles
    LS_ImageId_t _out_imageIds[LS_MAX_IMAGE_HANDLES];

    /// Array of image names
    char _out_imageNames[LS_MAX_IMAGE_HANDLES][LS_MAX_IMAGE_NAME_LEN];

} LS_LoadProj_t;

/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_calculateUniformity_t
 *
 */
typedef struct {
    /// Context handle
    LS_Handle_t _in_handle;

    /// ID of the image to evaluate
    LS_ImageId_t _in_imageId;

    /// Region of interest or full image mode
    /// that shall be used for the uniformity analysis
    /// Pos and size must not exceed the image size
    LS_RegionOfInterest_t _in_region;

    /// Kernel size of averaging
    /// Use \a eNoAveraging for no averaging
    LS_SDK_LuminanceKernelSizeOfAveraging_t _in_kernel_size_averaging;

    /// The uniformity value.
    /// It is a percentage value between 0 and 100
    float _out_uniformityValue;

} LS_CalculateUniformity_t;

/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_SDK_ContrastLevel_t
 *
 */
typedef enum {
    /// No additional contrast filter
    LS_SDK_ContrastLevel_None,

    /// Low contrast filter
    LS_SDK_ContrastLevel_Low,

    /// Medium contrast filter
    LS_SDK_ContrastLevel_Medium,

    /// High contrast filter
    LS_SDK_ContrastLevel_High,

    /// User mode, please @ref LS_GetBitmapData_t
    /// _in_min and _in_max have to be set for this mode
    LS_SDK_ContrastLevel_User

} LS_SDK_ContrastLevel_t;

/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_GetBitmapInfo_t
 *
 */
typedef struct {
    /// ID of the image
    LS_ImageId_t _in_imageId;

    /// The bytes per Pixel
    int32_t _out_bytesPerPixel;

    /// The stride (num of bytes per row)
    int32_t _out_stride;

    /// The size of the entire bitmap data. This is the number of bytes that needs to be allocated
    /// when calling @ref LS_getBitmapData
    int32_t _out_arraySize;

} LS_GetBitmapInfo_t;

typedef uint8_t BYTE;

/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_GetBitmapData_t
 */
typedef struct {
    /// ID of the image
    LS_ImageId_t _in_imageId;

    /// The contrast level that shall be applied to the
    /// bitmap data.
    LS_SDK_ContrastLevel_t _in_contrastLevel; 

    /// Min value, only used if _in_contrastLevel
    /// is set to LS_SDK_ContrastLevel_User
    double _in_min;

    /// Max value, only used if _in_contrastLevel
    /// is set to LS_SDK_ContrastLevel_User
    double _in_max;

    /// The bitmap data of the entire image
    /// Note: The memory must be allocated by the caller before calling @ref LS_getBitmapData.
    /// Please call @ref LS_getBitmapInfo first to get the required size information.
    BYTE *_out_data;

} LS_GetBitmapData_t;

/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_FindDisplay_t
 */
typedef struct {
    /// ID of the image
    LS_ImageId_t _in_image_id;

    /// Threshold for edge detection in percent
    float _in_threshold;

    /// Number of profiles to use per comb
    int _in_number_of_profiles;

    /// margins to be added after display has been found
    LS_Margins_t _in_margins;

    /// Set of four points describing the display found
    LS_Quadrangle_t _out_quad;
} LS_FindDisplay_t;

/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_FilterAutoCrop_t
 */
typedef struct {
    /// ID of the image
    LS_ImageId_t _in_image_id;

    /// Set of four points describing the quadrangle to crop
    /// @sa LS_FindDisplay_t for automatically obtaining a quadrangle
    LS_Quadrangle_t _in_quad;

    /// ID of the cropped image
    LS_ImageId_t _out_croppedImageId;
} LS_AutoCropImage_t;


/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_ApplyMultiPointCorrection_t
 */
typedef struct {
    /// ID of the correction image
    LS_ImageId_t _in_correction_image_id;

    /// ID of the input image
    LS_ImageId_t _in_image_id;

    /// ID of the output image
    LS_ImageId_t _out_image_id;

} LS_ApplyMultiPointCorrection_t;

/**
 * @ingroup SDKCorePageDataStructs_GRP
 * @brief LS_SDK_Init_t
 *
 * This struct allows to control the logging behavior of the SDK. The SDK
 * generally logs all SDK interface calls and some internal activities, warnings or errors. For
 * performance reasons logging should be turned "off" and only enabled for troubleshooting.
 *
 * Please refer also to @ref LS_SDK_InitDefault and macro @ref LS_SDK_INIT_CMD
 */
typedef struct {
    /// The name of the license file, including full path
    /// <br/>Use UTF-8 encoding
    char _in_licenseFileName[LS_MAX_FILENAME_LEN];

    /// Flag indicating whether logging shall be enabled or disabled.
    /// If this in turned OFF then nothing is logged.
    /// <br/>Recommended default is OFF.
    bool _in_Logging;

    /// Flag indicating whether all SDK interface calls are logged or not
    /// If _in_Logging is set to OFF then SDK interface calls are also not logged.
    /// <br/>Recommended default is OFF
    bool _in_LogInterface;

    /// Flag indicating whether there is only one logfile or _in_maxLogFileCount + 1 logfiles (each max. 10MB and
    /// rotating when full) Recommended default is ON
    bool _in_LogRotation;

    /// If _in_LogRotation is set to true, this is the maximum number of created logfiles.
    /// Logfile size is limited to 10 MB. Number of created logfiles is always _in_maxLogFileCount + 1.
    /// That means, if for example _in_maxLogFileCount is set to 3, than a maximum of 4 logfiles will be generated.
    uint8_t _in_maxLogFileCount;

    /// The name of the logfile, including full path
    /// When _in_LogRotation is enabled then all logfiles are stored within the same folder as the
    /// given logfile name <br/>Use UTF-8 encoding <br/>Recommended default is not to give an log
    /// file name. In that case all logfiles are stored within %ProgramData%/Instrument
    /// Systems/LumiSuite
    char _in_logFileName[LS_MAX_FILENAME_LEN];

    /// Function pointer to log LumiSuite SDK log events or nullptr when no further logging is
    /// required. <br/>This callback is only called when _in_Logging is ON <br/>Recommended default
    /// nullptr.
    LoggingCallback _in_log_Callback;

} LS_SDK_Init_t;

#endif // LS_SDK_CORE_DEFS_H
