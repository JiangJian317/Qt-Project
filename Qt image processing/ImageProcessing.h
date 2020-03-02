#pragma once

#include <QDialog>
#include "ui_ImageProcessing.h"
#include <SDKCore.h>
#include <SDKLumiTOPDevice.h>

class ImageProcessing : public QDialog
{
	Q_OBJECT
public:
	ImageProcessing(QWidget *parent = Q_NULLPTR);
	~ImageProcessing();
	void InitMeasurementParameterLTOPD(LS_LTOPD_2dMeasurement_Parameter_t& dMeasurementParameter, LS_LTOPD_Connect2Device_t& sensorConnectInfo);
	void InitMeasurementParameterCAS(LS_LTOPD_Measurement_Parameter_CAS_t& MeasurementParameterCAS, LS_LTOPD_Connect2Device_t& sensorConnectInfo);	
	QTextEdit* getTextEdit() { return ui.informationBar; }
	/*
	LS_SDK_Status_t LS_LTOPD_takeImage (LS_LTOPD_TakeImage_t  io_cmd );
	Remarks:
	The function LS_LTOPD_setMeasurementParams must be called before taking an image
	The function LS_LTOPD_Measurement_Parameter_CAS_t must be called before when doing a hybrid measurement
	The function operates synchronous, That means the functions does not return until the image has been taken.
	The amount of time until the function will return depends on the used measurement parameters. Thus,it may last several seconds to finish.
	*/
	void takeImage(LS_LTOPD_Connect2Device_t& sensorConnectInfo, LS_LTOPD_TakeImage_t& takeImgCmd);
	void saveImagetoFile(LS_LTOPD_TakeImage_t& loadCmd,QString ModuleAndGrayName);
	void LoadImageFromFile();
private slots:
//Í¼Ïñ´¦Àí²Ûº¯Êý
	void on_ImageAcquisition_clicked();
	void on_ImageLoad_clicked();
	void on_Preprocessing_clicked();
	void on_Analysis_clicked();
private:
	Ui::ImageProcessing ui;
	LS_LoadImage_t LoadedImage;
	QString ModuleAndGrayName;
	LS_CroppingAndFilling_t croppingParams;
	LS_AddGridOfSpotmeters_t gridCmd;
};
