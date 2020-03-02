//#include "stdafx.h"
#include "ImageProcessing.h"
#include <LSMainWindow.h>
#include <QFileDialog>

ImageProcessing::ImageProcessing(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	Qt::WindowFlags flags = this->windowFlags();
	setWindowFlags(flags&~Qt::WindowContextHelpButtonHint);
	ui.informationBar->setReadOnly(true);
}

ImageProcessing::~ImageProcessing()
{
}

void ImageProcessing::InitMeasurementParameterLTOPD(LS_LTOPD_2dMeasurement_Parameter_t& dMeasurementParameter, LS_LTOPD_Connect2Device_t& sensorConnectInfo)
{
	//LS_LTOPD_setMeasurementParams(&temp);
	//LS_LTOPD_setMeasurementParams_CAS(&casTemp);
	LS_SDK_Status_t stat;
	dMeasurementParameter._in_deviceHandle = sensorConnectInfo._out_deviceHandle;
	stat = LS_LTOPD_setMeasurementParams(&dMeasurementParameter);
	if (stat != eLS_OK)
	{
		ui.informationBar->append("LTOPD参数初始化失败!");
//		QMessageBox::warning(this, "警告", "LTOPD参数初始化失败!");
		return;
	}
	else
		ui.informationBar->append("LTOPD参数初始化成功.");
//		QMessageBox::information(this, "通知", "LTOPD参数初始化成功.");
}

void ImageProcessing::InitMeasurementParameterCAS(LS_LTOPD_Measurement_Parameter_CAS_t& MeasurementParameterCAS, LS_LTOPD_Connect2Device_t& sensorConnectInfo)
{
	LS_SDK_Status_t stat;
	MeasurementParameterCAS._in_deviceHandle = sensorConnectInfo._out_deviceHandle;
	stat = LS_LTOPD_setMeasurementParams_CAS(&MeasurementParameterCAS);
	if (stat != eLS_OK)
	{
		ui.informationBar->append("CAS参数初始化失败!");
//		QMessageBox::warning(this, "警告", "CAS参数初始化失败!");
		return;
	}
	else
		ui.informationBar->append("CAS参数初始化成功.");
//		QMessageBox::information(this, "通知", "CAS参数初始化成功.");
}

void ImageProcessing::takeImage(LS_LTOPD_Connect2Device_t& sensorConnectInfo, LS_LTOPD_TakeImage_t& takeImgCmd)
{
	takeImgCmd._in_deviceHandle = sensorConnectInfo._out_deviceHandle;
	takeImgCmd._out_imageId = LS_INVALID_IMAGE_ID;
	LS_SDK_Status_t stat = LS_LTOPD_takeImage(&takeImgCmd);
	if (stat != eLS_OK)
	{
		QString msg = QString::asprintf("LS_LTOPD_takeImage failed: %d", stat);
//		QMessageBox::warning(this, "警告", msg);
		ui.informationBar->append(msg);
		return;
	}
	else
	{
		QString msg = QString::asprintf("LS_LTOPD_takeImage successful: %d", stat);
//		QMessageBox::information(this, "通知", msg);
		ui.informationBar->append(msg);
	}
}

void ImageProcessing::saveImagetoFile(LS_LTOPD_TakeImage_t& loadCmd, QString ModuleAndGrayName)
{
	LS_SaveFile_t saveCmd;
	LS_SDK_Status_t stat;
	QString curPath = QDir::currentPath();
	curPath = curPath + "\\Images\\" + ModuleAndGrayName;	          //要具体指定文件名
	QString imageType = ui.saveImageType->currentText();
	if (imageType == "LS_SDK_FileType_LSIMG")
	{
		saveCmd._in_FileType = LS_SDK_FileType_LSIMG; // The file type of the stored
		curPath += ".LSimg";
	}
	else if (imageType == "LS_SDK_FileType_CSV")
	{
		saveCmd._in_FileType = LS_SDK_FileType_CSV;
		curPath += ".csv";
	}
	else if (imageType == "LS_SDK_FileType_FITS")
	{
		saveCmd._in_FileType = LS_SDK_FileType_FITS;
		curPath += ".fits";
	}
	strncpy_s(saveCmd._in_destFileName, LS_MAX_FILENAME_LEN,curPath.toStdString().c_str(), LS_MAX_FILENAME_LEN);
	saveCmd._in_imageId = loadCmd._out_imageId; // The id of the image to be saved
	stat = LS_saveImageToFile(&saveCmd);
	if (stat != eLS_OK)
	{
		QString msg = QString::asprintf("LS_saveimagetofile failed: %d", stat);
//		QMessageBox::warning(this, "警告", msg);
		ui.informationBar->append(msg);
		return;
	}
	else
	{
		QString msg = QString::asprintf("LS_saveimagetofile successful: %d", stat);
//		QMessageBox::information(this, "通知", msg);
		ui.informationBar->append(msg);
	}
}

void ImageProcessing::LoadImageFromFile()
{
	QString curPath = QDir::currentPath();
	curPath += "\\Images";
	QString ImagePath = QFileDialog::getOpenFileName(this, "选择图片", curPath);
	LS_LOAD_IMAGE_CMD(loadImgCmd)
	int index1 = ImagePath.lastIndexOf("/");
	int index2 = ImagePath.lastIndexOf(".");
	QString ModuleAndGrayName = ImagePath.mid(index1 + 1, index2-index1-1);
	if (!ImagePath.isEmpty())
	{
		LS_SDK_Status_t stat;
		strncpy_s(loadImgCmd._in_fileName, ImagePath.toStdString().c_str(), LS_MAX_FILENAME_LEN);
		stat = LS_loadImageFromFile(&loadImgCmd);
		if (stat != eLS_OK)
		{
			QString msg = QString::asprintf("Load image failed: %d", stat);
//			QMessageBox::warning(this, "警告", msg);
			ui.informationBar->append(msg);
			return;
		}
		else
		{
			QString msg = QString::asprintf("Load image successful: %d", stat);
//			QMessageBox::information(this, "通知", msg);
			ui.informationBar->append(msg);
		}
		this->LoadedImage = loadImgCmd;
		this->ModuleAndGrayName = ModuleAndGrayName;
	}
	this->LoadedImage = loadImgCmd;
}

void ImageProcessing::on_ImageAcquisition_clicked()
{
//The function LS_LTOPD_Measurement_Parameter_CAS_t must be called before when doing a hybrid measurement
//If we want to use CAS takeImage that startup CAS device before takeimage	
//	qDebug() << "LTOPD SIZE:" << GlobalVar::LTOPDParmList.size();
//	qDebug() << "CAS SIZE:" << GlobalVar::CASParmList.size();
	auto CASIter = GlobalVar::CASParmList.begin();
	for (auto LTOPDIter = GlobalVar::LTOPDParmList.begin(); LTOPDIter != GlobalVar::LTOPDParmList.end(); ++LTOPDIter, ++CASIter)
	{   
		LS_LTOPD_2dMeasurement_Parameter_t LTOPDParm = LTOPDIter->LumiTop2dParm;
		LS_LTOPD_Measurement_Parameter_CAS_t CASParm = CASIter->CASParm;
		QString ModuleAndGrayName = LTOPDIter->ModuleAndGrayName;
		InitMeasurementParameterLTOPD(LTOPDParm, GlobalVar::sensorConnectInfo);
		InitMeasurementParameterCAS(CASParm, GlobalVar::sensorConnectInfo);
		LS_LTOPD_TakeImage_t takeImgCmd;
		takeImage(GlobalVar::sensorConnectInfo, takeImgCmd);
		saveImagetoFile(takeImgCmd,ModuleAndGrayName);
		LS_deleteImage(takeImgCmd._out_imageId);
	}
}

void ImageProcessing::on_ImageLoad_clicked()
{
	LoadImageFromFile();
}

void ImageProcessing::on_Preprocessing_clicked()
{
	LS_SDK_Status_t stat;
	LS_CROPPING_AND_FILLING_CMD(croppingParams);
	croppingParams._in_imageId = LoadedImage._out_imageId;
	stat = LS_croppingAndFilling(&croppingParams);
	this->croppingParams = croppingParams;     //初始化参数
	if (stat != eLS_OK)
	{
		QString msg = QString::asprintf("Image cropping failed: %d", stat);
//		QMessageBox::warning(this, "警告", msg);
		ui.informationBar->append(msg);
		return;
	}
	else
	{
		QString msg = QString::asprintf("Image cropping successful: %d", stat);
//		QMessageBox::information(this, "通知", msg);
		ui.informationBar->append(msg);
	}

	LS_deleteImage(LoadedImage._out_imageId); 

	LS_GET_IMAGE_INFO_CMD(imgInfo);
	imgInfo._in_imageId = croppingParams._out_croppedImageId;
	stat = LS_getImageSize(&imgInfo);
	if (stat != eLS_OK)
	{
		QString msg = QString::asprintf("Getting image information failed: %d", stat);
//		QMessageBox::warning(this, "警告", msg);
		ui.informationBar->append(msg);
		return;
	}
	else
	{
		QString msg = QString::asprintf("Getting image information successful: %d", stat);
//		QMessageBox::information(this, "通知", msg);
		ui.informationBar->append(msg);
	}
	LS_ADD_GRID_OF_SPOTMETERS_CMD(gridCmd)
//		qDebug() << this->ModuleAndGrayName;
    //遍历图像灰阶的参数列表,选中与当前图像灰阶对应的参数列表
    for (auto Iter = GlobalVar::ImageProcessAndAnalysisParmList.begin(); Iter != GlobalVar::ImageProcessAndAnalysisParmList.end(); ++Iter)
	{
		if (this->ModuleAndGrayName == Iter->ModuleAndGrayName)
		{
			gridCmd._in_columns = Iter->gridColumn;
			gridCmd._in_rows = Iter->gridRow;
			gridCmd._in_spotmeter._in_height = Iter->gridSpotHeight;
			gridCmd._in_spotmeter._in_width = Iter->gridSoptWidth;
			gridCmd._in_gridX = Iter->gridX;
			gridCmd._in_gridY = Iter->gridY;
			gridCmd._in_gridHeight = imgInfo._out_height; 
			gridCmd._in_gridWidth = imgInfo._out_width;
			gridCmd._in_handle = GlobalVar::context;
			if (ui.ColorSpace->currentIndex() == 0)
				gridCmd._in_spotmeter._in_resultColorSpace = LS_SDK_ColorSpace_t::LS_SDK_ColorSpace_Lvxy;
			else if(ui.ColorSpace->currentIndex() == 1)
				gridCmd._in_spotmeter._in_resultColorSpace = LS_SDK_ColorSpace_t::LS_SDK_ColorSpace_XYZ;
			break;
		}
	}
	stat = LS_addGridOfSpotmeters(&gridCmd);
	this->gridCmd = gridCmd;
	if (stat != eLS_OK)
	{
		QString msg = QString::asprintf("add grid failed: %d", stat);
		ui.informationBar->append(msg);
//		QMessageBox::warning(this, "警告", msg);
		return;
	}
	else
	{

		QString msg = QString::asprintf("add grid successful : %d", stat);
		ui.informationBar->append(msg);
//		QMessageBox::information(this, "通知", msg);
	}   
}

void ImageProcessing::on_Analysis_clicked()
{
	LS_SDK_Status_t stat;
	LS_EXECUTE_CMD(execCMD);
	execCMD._in_handle = GlobalVar::context;
	execCMD._in_imageId = this->croppingParams._out_croppedImageId;
	stat = LS_execute(&execCMD);
	if (stat != eLS_OK)
	{
		QString msg = QString::asprintf("Execute measurement analysis failed: %d", stat);
		ui.informationBar->append(msg);
//		QMessageBox::warning(this, "警告", msg);
		return;
	}
	else
	{
		QString msg = QString::asprintf("Execute measurement analysis successful: %d", stat);
		ui.informationBar->append(msg);
//		QMessageBox::information(this, "通知", msg);
	}
	LS_GET_GRID_OF_SPOTMETERS_INFO_CMD(gridInfoCMD);
	gridInfoCMD._in_handle = GlobalVar::context;
	gridInfoCMD._in_spotmeterGridId = this->gridCmd._out_spotmeterGridId;
	stat = LS_getGridOfSpotmetersInfo(&gridInfoCMD);
	if (stat != eLS_OK)
	{
		QString msg = QString::asprintf("Get grid of Spotmeters information failed: %d", stat);
		ui.informationBar->append(msg);
//		QMessageBox::warning(this, "警告", msg);
		return;
	}
	else
	{
		QString msg = QString::asprintf("Get grid of Spotmeters information successful: %d", stat);
		ui.informationBar->append(msg);
//		QMessageBox::information(this, "通知", msg);
	}
	int spotCount = gridInfoCMD._out_countOfSpotmeters;
	LS_GET_GRID_OF_SPOTMETERS_RESULT_CMD(spotGridResult);
	spotGridResult._in_handle = GlobalVar::context;
	spotGridResult._in_gridId = this->gridCmd._out_spotmeterGridId;
	QString Result[3];
	for (int i = 0; i < 3; ++i)      //要求分别计算channel 0、channel 1、channel 2 分别代表lv-mean、x-mean、y-mean
	{
		spotGridResult._in_channel = i;           
		// calculate the required memory size
		size_t sz = spotCount * sizeof(LS_SpotmeterResult_t);
		spotGridResult._out_results = (LS_SpotmeterResult_t*)malloc(sz);
		memset((void*)spotGridResult._out_results, 0, sz);

		stat = LS_getGridOfSpotmetersResult(&spotGridResult);
		if (stat != eLS_OK)
		{
			QString msg = QString::asprintf("Get grid of Spotmeters result failed: %d", stat);
//			QMessageBox::warning(this, "警告", msg);
			ui.informationBar->append(msg);
			return;
		}
		else
		{
			QString msg = QString::asprintf("Get grid of Spotmeters result successful : %d", stat);
//			QMessageBox::information(this, "通知", msg);
			ui.informationBar->append(msg);
			LS_SPOTMETER_RESULT_CMD(spotmeterResult);
			//Get results over all spotmeters
			double result = 0;
			for (int j = 0; j < spotCount; j++)
			{
				spotmeterResult = spotGridResult._out_results[j];
				result += spotmeterResult._out_mean;
			}
			result /= spotCount;
			QString out_mean = QString::number(result, 'f', 1);
			Result[i] = out_mean;
//			qDebug() << "mean"<<i<<":"<< out_mean;
			free(spotGridResult._out_results);
		}
	}
	//remove Analysis 
	LS_REMOVE_SPOTMETER_GRID_CMD(removeGridCmd);
	removeGridCmd._in_handle = GlobalVar::context;
	removeGridCmd._in_spotmeterGridId = this->gridCmd._out_spotmeterGridId;
	stat = LS_removeSpotmeterGrid(&removeGridCmd);
	if (stat != eLS_OK)
	{
		QString msg = QString::asprintf("LS_removeSpotmeterGrid failed: %d", stat);
		ui.informationBar->append(msg);
//		QMessageBox::warning(this, "警告", msg);
		return;
	}
	else
	{
		QString msg = QString::asprintf("LS_removeSpotmeterGrid successful: %d", stat);
		ui.informationBar->append(msg);
//		QMessageBox::information(this, "通知", msg);
	}
	QString head;
	if (ui.ColorSpace->currentIndex() == 0)
		head = "Lv-mean\tX-mean\tY-mean";
	else if (ui.ColorSpace->currentIndex() == 1)
		head = "X-mean\tY-mean\tZ-mean";
	ui.informationBar->append(head);
	QString res = Result[0] + "\t" + Result[1] + "\t" + Result[2];
	ui.informationBar->append(res);
	QString curPath = QDir::currentPath();
	QFile ResFile(curPath + "\\MeanValue\\" + this->ModuleAndGrayName + ".txt");
	if(!ResFile.open(QIODevice::WriteOnly|QIODevice::Truncate|QIODevice::Text))
		ui.informationBar->append("打开写入结果文件失败");
	QTextStream out(&ResFile);
	out << head << '\n' << res;
}

