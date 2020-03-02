#pragma once

#include <QtWidgets/QMainWindow>
#include <QTableView>
#include "ui_LSMainWindow.h"
#include "copyModuleDialog.h"
#include <QStandardItemModel>
#include <QtXML>
#include <QCloseEvent>
#include <QSettings>
#include "ModuleEdit.h"
#include <SDKCore.h>
#include <SDKLumiTOPDevice.h>
#include "ImageProcessing.h"

typedef struct
{
	LS_LTOPD_2DMEASUREMENT_PARAMETER_CMD(LumiTop2dParm)
	QString ModuleAndGrayName;
}LS_LTOPD_2dMeasurement_Parameter_Struct;

typedef struct
{
	LS_LTOPD_MEASUREMENT_PARAMETER_CAS_CMD(CASParm)
	QString ModuleAndGrayName;
}LS_LTOPD_Measurement_Parameter_CAS_Struct;

typedef struct
{
	QString ModuleAndGrayName;           //ͨ��ModuleAndGrayName��ָ������Ļҽײ���
	int gridColumn = 0;
	int gridRow = 0;
	float gridSoptWidth = 0;
	float gridSpotHeight = 0;
	float gridX = 0;
	float gridY = 0;
	LS_SDK_ColorSpace_t resultColorSpace = LS_SDK_ColorSpace_t::LS_SDK_ColorSpace_Lvxy;
}ImageProcessAndAnalysisParmsStruct;


 namespace GlobalVar
{
	extern LS_LTOPD_Connect2Device_t sensorConnectInfo;
	extern LS_Handle_t context;
//	extern LS_LTOPD_TakeImage_t takeImgCmd;
	extern QList<LS_LTOPD_2dMeasurement_Parameter_Struct> LTOPDParmList;
	extern QList<LS_LTOPD_Measurement_Parameter_CAS_Struct> CASParmList;
	extern QList<ImageProcessAndAnalysisParmsStruct>ImageProcessAndAnalysisParmList;	
}

class LSMainWindow : public QMainWindow
{
	Q_OBJECT
public:
	//��ͼ��ʼ��
	LSMainWindow(QWidget *parent = Q_NULLPTR);
	void initTableView();
	void initTableWidgetList();
	void operateXmltoParameterList(QString moduleName);
	void updateParmstoXml(QString Name);
	void showCustomDelegate();
	void clearTableView();
	void InitLumiTopAndCASparmList();
	void InitImageProcessAndAnalysisparmList();
	QTableWidget* getTableWidgetList() { return ui.tableWidgetList; }
	QTableView* getTableView() { return ui.tableView; }
	//�豸��ʼ����Ͽ�
	LS_Handle_t getLSContext(LS_SDK_Status_t& stat, LS_Handle_t& ctxHandle);
	bool getLSDevice(LS_SDK_Status_t& stat, LS_LTOPD_discoverDevices_t& discoverDeviceCmd, bool& CAS_Device);
	bool getConnection2LumiTOPD(LS_SDK_Status_t& stat, LS_LTOPD_discoverDevices_t& discoverDeviceCmd, LS_LTOPD_Connect2Device_t& sensorConnectInfo, bool& CAS_Device);
	bool setupSDKAndLumiTOP(LS_Handle_t& context, LS_LTOPD_Connect2Device_t& sensorConnectInfo, bool CAS_Device);
	bool destroySDKAndLumiTop(LS_Handle_t context, LS_LTOPD_Connect2Device_t sensorConnectInfo);
	bool disconnectLumiTop(LS_SDK_Status_t& stat, LS_LTOPD_Connect2Device_t& sensorConnectInfo);
	bool destroyContext(LS_SDK_Status_t& stat, LS_Handle_t& ctxHandle);
	bool quit(LS_SDK_Status_t& stat);
protected:
	void closeEvent(QCloseEvent* veent)Q_DECL_OVERRIDE;
private slots:
//QTableWidgetList�ۺ���
	void on_CreateBtn_clicked();
	void on_SaveBtn_clicked();
	void on_DeleteBtn_clicked();
	void on_ImportBtn_clicked();
	void on_ExportBtn_clicked();
	void on_CopyBtn_clicked();
	void switchModule(int row, int col);
//QTableView�ۺ���
	void on_UpBtn_clicked();
	void on_DownBtn_clicked();
	void on_AddBtn_clicked();
	void on_DelBtn_clicked();
	void on_SaveParmsBtn_clicked();
//ģ��༭�Ի���ۺ���
	void on_moduleObjectFile_triggered();
//�豸�ۺ���
	void on_ConnectDevice_triggered();
	void on_DisconnectDevice_triggered();
//ͼ����ۺ���
	void on_ImageProcessing_triggered();
private:
	//����Ӧ�ó��������
	void readSettings();
	void writeSettings();
private:
	Ui::LSMainWindowClass ui;
	QVector<QString> modName;                //�洢ģ����
	copyModuleDialog* cMD;
	QStandardItemModel  *theModel;//����ģ��
	QItemSelectionModel *theSelection;//Itemѡ��ģ��
	ModuleEdit* modEdit;
	ImageProcessing* imageProcessing;	
};
