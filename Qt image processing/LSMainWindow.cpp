//#include "stdafx.h"
#include "LSMainWindow.h"
#include <QMessageBox>
#include <QInputDialog>
#include <QString>
#include <QLineEdit>
#include <QIcon>
#include <QTableWidget>
#include <QFileDialog>
#include <QDebug>
#include "ComboBoxDelegate.h"


//初始化全局变量
LS_LTOPD_CONNECT2DEVICE_CMD(GlobalVar::sensorConnectInfo)
LS_Handle_t GlobalVar::context = -1;
//LS_LTOPD_TAKE_IMAGE_CMD(GlobalVar::takeImgCmd);
QList<LS_LTOPD_2dMeasurement_Parameter_Struct> GlobalVar::LTOPDParmList = QList<LS_LTOPD_2dMeasurement_Parameter_Struct>();
QList<LS_LTOPD_Measurement_Parameter_CAS_Struct> GlobalVar::CASParmList = QList<LS_LTOPD_Measurement_Parameter_CAS_Struct>();
QList<ImageProcessAndAnalysisParmsStruct> GlobalVar::ImageProcessAndAnalysisParmList = QList<ImageProcessAndAnalysisParmsStruct>();

LSMainWindow::LSMainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->raise();                           //窗口默认显示在最顶层
//	this->setWindowFlags(this->windowFlags() | Qt::WindowStaysOnTopHint);    //设置窗口在最顶层
	this->setWindowIcon(QIcon(":/LSMainWindow/Resources/icon.png"));         //设置窗口图标
	this->resize(QSize(1180, 600));              //窗口初始大小
	ui.ModuleNamelineEdit->setReadOnly(true);             	//模组名为只读
	cMD = new copyModuleDialog(this);
	modEdit = new ModuleEdit(this);
	imageProcessing = new ImageProcessing(this);
	ui.informationBar->setWordWrapMode(QTextOption::NoWrap);
	initTableWidgetList();
	initTableView();
	ui.tableView->setModel(theModel);
	readSettings();                          //读取应用程序设置
	ui.CASDevice->setChecked(true);          //默认使用CAS设备
	connect(ui.tableWidgetList, &QTableWidget::cellChanged, this, &LSMainWindow::switchModule);     //生成新模组
	connect(ui.tableWidgetList, &QTableWidget::cellClicked, this, &LSMainWindow::switchModule);   //切换模组
}

//模组列表初始化
void LSMainWindow::initTableWidgetList()
{
	ui.tableWidgetList->setColumnCount(1);
	ui.tableWidgetList->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui.tableWidgetList->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(170,255,255);}");
	ui.tableWidgetList->horizontalHeader()->setMinimumHeight(30);
	ui.tableWidgetList->setEditTriggers(QAbstractItemView::NoEditTriggers);             //不可编辑																						//设定选择行为，按行选择
	ui.tableWidgetList->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.tableWidgetList->setStyleSheet("selection-background-color:rgb(80,0,255)");     	//设置选中行的背景色
}

//参数列表初始化
void LSMainWindow::initTableView()
{
	//初始化表头
	QStringList headList;
	headList << "Name" << "exposureMode" << "exposureTime" << "averageNum" << "integrationTime" << "gridX"
		<< "gridY" << "gridRow" << "gridColumn" << "densityFilter" << "acquisitionMode" << "maxAutoIntegrationTime"
		<< "spotmeterResultColorSpace" << "spotmeterWidth" << "spotmeterHeight";
	theModel = new QStandardItemModel(0, headList.size(), this);             //设置tableView的初始大小
	theSelection = new QItemSelectionModel(theModel);//Item选择模型
	theModel->setHorizontalHeaderLabels(headList);
	ui.tableView->setModel(theModel);
	ui.tableView->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(170,255,255);}");
	ui.tableView->horizontalHeader()->setMinimumHeight(30);
	QFont font("Microsoft YaHei", 8, 75);
	ui.tableView->horizontalHeader()->setFont(font);
	ui.tableView->setSelectionBehavior(QAbstractItemView::SelectRows); //整行选中
	ui.tableView->setStyleSheet("selection-background-color:rgb(80,0,255)");
	//为tableView设置自定义代理
	exposureModeComDelegate* eMCD = new exposureModeComDelegate(this);
	acquisitionModeComDelegate* aMCD = new acquisitionModeComDelegate(this);
	//	spotMeterShapeComDelegate* sMSCD = new spotMeterShapeComDelegate(this);
	spotMeterResultColorSpaceComDelegate* sMRCSCD = new spotMeterResultColorSpaceComDelegate(this);
	ui.tableView->setItemDelegateForColumn(ComboBoxDelegate::EXPOSUREMODE, eMCD);
	ui.tableView->setItemDelegateForColumn(ComboBoxDelegate::ACQUISITIONMODE, aMCD);
	//	ui.tableView->setItemDelegateForColumn(ComboBoxDelegate::SPOTMETERSHAPE, sMSCD);
	ui.tableView->setItemDelegateForColumn(ComboBoxDelegate::SPOTMETERRESULTCOLORSPACE, sMRCSCD);
	ui.tableView->setColumnWidth(ComboBoxDelegate::EXPOSUREMODE, 160);
	//	ui.tableView->setColumnWidth(ComboBoxDelegate::SPOTMETERSHAPE, 150);
	ui.tableView->setColumnWidth(ComboBoxDelegate::ACQUISITIONMODE, 180);
	ui.tableView->setColumnWidth(ComboBoxDelegate::ACQUISITIONMODE + 1, 155);
	ui.tableView->setColumnWidth(ComboBoxDelegate::SPOTMETERRESULTCOLORSPACE, 170);
}

LS_Handle_t  LSMainWindow::getLSContext(LS_SDK_Status_t& stat, LS_Handle_t& ctxHandle)
{
	//Initialization and start of SDKCore

	// Setting of parametrs for initialization
	LS_SDK_INIT_CMD(initCmd);
	//for using of Logfile, default value is "false"
	initCmd._in_Logging = true;
	//to trace each function call in logfile, Default value is "false"
	initCmd._in_LogInterface = true;
	//to produce the next Logfile if the old one is "overloaded" >10MB. Default value  is "true"
	initCmd._in_LogRotation = true;
	initCmd._in_maxLogFileCount = 20;
    initCmd._in_log_Callback = Q_NULLPTR;
	QString systemLogPath = QDir::currentPath();
	systemLogPath = systemLogPath + "\\log\\Systemlog.txt";
	strncpy_s(initCmd._in_logFileName, systemLogPath.toStdString().c_str(), LS_MAX_FILENAME_LEN);

	stat = LS_start(&initCmd);
	if (stat != eLS_OK)
	{
		QString errorMsg = QString::asprintf("LS_start failed with error code %d", stat);
		ui.informationBar->append(errorMsg);
//		QMessageBox::critical(this, "fatal error", errorMsg);
		std::exit(1);
	}
	// Create context
	ctxHandle = LS_createContext();
	if (ctxHandle < 0)
	{
		QString errorMsg = QString::asprintf("LS_createContext failed with error code %d", stat);
		ui.informationBar->append(errorMsg);
//		QMessageBox::critical(this, "fatal error", errorMsg);
		std::exit(1);
	}
	return ctxHandle;
}

bool LSMainWindow::getLSDevice(LS_SDK_Status_t& stat, LS_LTOPD_discoverDevices_t& discoverDeviceCmd, bool& CAS_Device)
{
	//	LS_LTOPD_discoverDevices is used to detect the LumiTop Cameras, returns listed serial numbers,
	//	devices types and amount of detected devices. Status = OK, if the execution succeed without error
	//	Check if any device was found by asking for _out_deviceCount;

	stat = LS_LTOPD_discoverDevices(&discoverDeviceCmd);
	if (stat != eLS_OK)
	{
		QString errorMsg = QString::asprintf("LS_LTOPD_discoverDevices failed");
		ui.informationBar->append(errorMsg);
//		QMessageBox::critical(this, "fatal error", errorMsg);
		return false;
	}
	else
	{
		// if at least one LumiTop device is detected / discovered, get the number of devices
		int32_t devAmount = discoverDeviceCmd._out_deviceCount;

		//Declare data container for serial numbers and devices types
		char _out_serialNumbers[LS_MAX_NUMBER_DEVICES][LS_MAX_SERIAL_NUMBER_LEN];
		char _out_deviceTypes[LS_MAX_NUMBER_DEVICES][LS_MAX_DEVICE_TYPE_LEN];

		for (int i = 0; i < devAmount; i++)
		{
			// the serial number and type of device are corresponding to each other and have the same index
			strcpy_s(_out_serialNumbers[i], discoverDeviceCmd._out_serialNumbers[i]);
			strcpy_s(_out_deviceTypes[i], discoverDeviceCmd._out_deviceTypes[i]);
		}
		ui.informationBar->append("LS_LTOPD_discoverDevices successful");
//		QMessageBox::information(this, "通知", "LS_LTOPD_discoverDevices successful");
		ui.informationBar->append(QString::asprintf("The serial number of the first detected LumiTop device: %s", _out_serialNumbers[0]));
		ui.informationBar->append(QString::asprintf("The device type of the first detected LumiTop devic: %s ", _out_deviceTypes[0]));
	}
	// Check if CAS-Device is detected. To discover CAS device the CAS-Interface type should be known,
	//   because it will be neede as in_parameter for LS_LTOPD_discoverCASDevices-command
	// Search for CAS- Device under assumption that one exists
	//CAS_Device = true;
	//There are only 4 Types of CAS-Device.In the loop will be checked device of which type is present.
	LS_LTOPD_discoverCASDevices_t discoverDeviceCASCmd;
	for (int i = 0; i < 4; i++)
	{	//discovered device-type-value will be used as input parameter
		if (i == 0)
		{
			discoverDeviceCASCmd._in_interface_type = LS_SDK_CAS_PCI;
		}
		if (i == 1)
		{
			discoverDeviceCASCmd._in_interface_type = LS_SDK_CAS_USB;
		}
		if (i == 2)
		{
			discoverDeviceCASCmd._in_interface_type = LS_SDK_CAS_PCIExpress;
		}
		if (i == 3)
		{
			discoverDeviceCASCmd._in_interface_type = LS_SDK_CAS_Ethernet;
		}
		// discoverCAS-Devices
		//LS_SDK_CasInterfaceType_t typ = discoverDeviceCASCmd._in_interface_type;
		stat = LS_LTOPD_discoverCASDevices(&discoverDeviceCASCmd);
		if (stat == eLS_OK)
		{
			QString msg = QString("CAS device is detected typ: %1").arg(discoverDeviceCASCmd._in_interface_type);
			ui.informationBar->append(msg);
//			QMessageBox::information(this, "通知", msg);
			return true;
		}
	}
	//CAS四种类型如果都不匹配,说明没有CAS,输出错误消息
	QString errorMsg = QString::asprintf("LS_LTOPD_discoverCASDevices failed: %d", stat);
	ui.informationBar->append(errorMsg);
//	QMessageBox::warning(this, "警告", errorMsg);
	CAS_Device = false;
	return true;
}

bool LSMainWindow::getConnection2LumiTOPD(LS_SDK_Status_t& stat, LS_LTOPD_discoverDevices_t& discoverDeviceCmd, LS_LTOPD_Connect2Device_t& sensorConnectInfo, bool& CAS_Device)
{
	sensorConnectInfo._in_connectToCAS = false;     //without CAS
	QString devType = discoverDeviceCmd._out_deviceTypes[0];    //Check the type LumiTOP camera device
	if (devType == "LumiTOP2700")
	{
		sensorConnectInfo._in_devType = LS_LTOPD_DeviceTypes_LumiTOP2700;
	}
	else if (devType == "LumiTOP4000")
	{
		sensorConnectInfo._in_devType = LS_LTOPD_DeviceTypes_LumiTOP4000;
	}
	else
	{
		ui.informationBar->append("No matching device type!");
//		QMessageBox::warning(this, "警告", "No matching device type!");
		return false;
	}

	if (stat == eLS_OK)
	{
		strncpy_s(&sensorConnectInfo._in_serialNumber[0], sizeof(discoverDeviceCmd._out_serialNumbers[0]) + 1, discoverDeviceCmd._out_serialNumbers[0], LS_MAX_SERIAL_NUMBER_LEN);
	}

	// Connection to CAS device: true - mit CAS,  false - ohne CAS
	sensorConnectInfo._in_connectToCAS = CAS_Device;

	// Connection of LumiTOP device.
	stat = LS_LTOPD_connect(&sensorConnectInfo);

	if (stat != eLS_OK)
	{
		QString errorMsg = QString::asprintf("LS_LTOPD_connect failed: %d", stat);
		ui.informationBar->append(errorMsg);
//		QMessageBox::warning(this, "警告", errorMsg);
		return false;
	}
	else
	{
		QString msg = QString::asprintf("LS_LTOPD_connect successful: %d", stat);
		ui.informationBar->append(msg);
//		QMessageBox::information(this, "通知", msg);
		return true;
	}
}

bool LSMainWindow::setupSDKAndLumiTOP(LS_Handle_t& context, LS_LTOPD_Connect2Device_t& sensorConnectInfo, bool CAS_Device)
{
	//1. SDK structs with scope in whole main-function
	LS_SDK_Status_t stat;
	//	LS_Handle_t ctxHandle;
	//2. Start SDKCore, creation of context and handle
	getLSContext(stat, context);
	//3. Create and initialize LumiTop device and CAS
	//Disccover device to get a serial number of LumiTop Camera for further connection with it
	LS_LTOPD_discoverDevices_t discoverDeviceCmd;
	bool flag = false;
	flag = getLSDevice(stat, discoverDeviceCmd, CAS_Device);
	if (flag == false)
		return false;
	//4. Connect to LumiTop
	//	LS_LTOPD_Connect2Device_t sensorConnectInfo;
	flag = getConnection2LumiTOPD(stat, discoverDeviceCmd, sensorConnectInfo, CAS_Device);
	if (flag == false)
		return false;
	return true;
}

bool LSMainWindow::disconnectLumiTop(LS_SDK_Status_t& stat, LS_LTOPD_Connect2Device_t& sensorConnectInfo)
{
	//Disconnect LumiTOP
	stat = LS_LTOPD_disconnect(sensorConnectInfo._out_deviceHandle);
	if (stat != eLS_OK) {
		QString msg = QString::asprintf("Disconnect LumiTop failed: %d", stat);
		ui.informationBar->append(msg);
//		QMessageBox::warning(this, "警告", msg);
		return false;
	}
	else
	{
		QString msg = QString::asprintf("Disconnect LumiTop successful: %d", stat);
		ui.informationBar->append(msg);
//		QMessageBox::information(this, "通知", msg);
		return true;
	}
}

bool LSMainWindow::destroyContext(LS_SDK_Status_t& stat, LS_Handle_t& ctxHandle)
{
	// destroy context
	stat = LS_destroyContext(ctxHandle);
	if (stat != eLS_OK)
	{
		QString msg = QString::asprintf("LS_destroy_context failed: %d", stat);
		ui.informationBar->append(msg);
//		QMessageBox::warning(this, "警告", msg);
		return false;
	}
	else
	{
		QString msg = QString::asprintf("LS_destroy_context successful: %d", stat);
		ui.informationBar->append(msg);
//		QMessageBox::information(this, "通知", msg);
		return true;
	}
}

bool LSMainWindow::quit(LS_SDK_Status_t& stat)
{
	// Clean up: Quit LumiSuite SDKCore
	stat = LS_quit();
	if (stat != eLS_OK)
	{
		QString msg = QString::asprintf("LS_quit failed: %d\n", stat);
		ui.informationBar->append(msg);
//		QMessageBox::warning(this, "警告", msg);
		return false;
	}
	else
	{
		QString msg = QString::asprintf("LS_quit successful: %d\n", stat);
		ui.informationBar->append(msg);
//		QMessageBox::information(this, "通知", msg);
		return true;
	}
}

bool LSMainWindow::destroySDKAndLumiTop(LS_Handle_t context, LS_LTOPD_Connect2Device_t sensorConnectInfo)
{
	LS_SDK_Status_t stat;
	bool Flag = false;
	Flag = disconnectLumiTop(stat, sensorConnectInfo);    	//Disconnect LumiTop & CAS
	if (!Flag)   return false;
	Flag = destroyContext(stat, context);              // Destroy context
	if (!Flag)   return false;
	Flag = quit(stat);                                 //Quit SDKCore
	if (!Flag)   return false;
	return true;
}

void LSMainWindow::operateXmltoParameterList(QString moduleName)
{
	QDomDocument doc;         // 新建QDomDocument类对象，它代表一个XML文档
	QString xmlPath = QDir::currentPath();
	xmlPath = xmlPath + "\\ModuleXml\\" + moduleName + ".xml";
	QFile file(xmlPath);            //TestWHTianMa.xml
	if (!file.open(QIODevice::ReadOnly))
	{
		QMessageBox::warning(this, "警告", "打开xml配置文件失败!");
		return;
	}
    //int row = 0, col = 0;
	//	QString errorMsg;
	//	bool namespaceProcessing = false;
	if (!doc.setContent(&file/*,namespaceProcessing,&errorMsg,&row,&col*/))       //文件上锁会读取失败
	{
		QMessageBox::warning(this, "警告", "读取xml配置文件失败!");
		/*qDebug() << "namespaceProcessing:" << namespaceProcessing;
		qDebug() << "ErrorMsg::" << errorMsg;
		qDebug() << "Row:" << row;
		qDebug() << "Col:" << col;*/
		file.close();
		return;
	}
	file.close();
	QDomElement docElem = doc.documentElement();                 //获得XML根节点
	QDomNode subNode = docElem.firstChild();                   //根元素的第一个子节点,即Camera节点
															   //	int grayCount = subNode.childNodes().count();              //参数表格的行数
	subNode = subNode.firstChild();                            //config节点
	int t = 0;
	QStandardItem* item;
	while (!subNode.isNull())                                 //读取所有元素
	{
		if (subNode.isElement())
		{
			QDomNodeList domList = subNode.childNodes();          //获得Camera节点的所有子节点
			int parameterNum = domList.count();
			QList<QStandardItem*> aItemList;
			for (int i = 0; i < parameterNum; ++i)
			{
				QDomNode node = domList.at(i);
				item = new QStandardItem(node.toElement().text());
				aItemList << item;
			}
			for (int j = aItemList.size(); j < theModel->columnCount(); ++j)
			{
				item = new QStandardItem("NULL");
				aItemList << item;
			}
			theModel->insertRow(t++, aItemList);
		}
		subNode = subNode.nextSibling();                           //转到下一个兄弟节点
	}
	showCustomDelegate();                        //更新代理组件
}

void LSMainWindow::updateParmstoXml(QString Name)                	//测试多次点击"保存"按钮是否会追加内容"
{
	qDebug() << "updateParmstoXml()函数开始";
	QDomDocument doc;
	QDomProcessingInstruction instruction;      // 添加处理指令即XML说明
	instruction = doc.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"UTF-8\"");
	doc.appendChild(instruction);
	qDebug() << "添加处理指令即XML说明";
	QDomElement root = doc.createElement("MODULEDATA");      // 添加根元素
	doc.appendChild(root);
	QDomElement camera = doc.createElement("CAMERA");
	root.appendChild(camera);
	int row = theModel->rowCount();
	int column = theModel->columnCount();
	QList<QDomElement> elementNodeList;
	qDebug() << "函数进入到这里";
	for (int i = 0; i < row; ++i)
	{
		QList<QString> grayValue;
		QDomElement config = doc.createElement("config");
		for (int j = 0; j < column; ++j)
		{
			QString elementName = theModel->horizontalHeaderItem(j)->text();
			QDomElement temp = doc.createElement(elementName);
			QDomText text;
			QString value = theModel->item(i, j)->text();
			if (!value.isEmpty())
				text = doc.createTextNode(theModel->item(i, j)->text());
			else
				text = doc.createTextNode("NULL");
			temp.appendChild(text);
			config.appendChild(temp);
		}
		elementNodeList.push_back(config);
	}
	for (int i = 0; i < elementNodeList.size(); ++i)
		camera.appendChild(elementNodeList[i]);
	QString saveXmlPath = QDir::currentPath();
	saveXmlPath = saveXmlPath + "\\ModuleXml\\" + Name + ".xml";
	//	qDebug() << saveXmlPath;
	QFile xmlFile(saveXmlPath);
	if (!xmlFile.open(QIODevice::WriteOnly | QIODevice::Truncate))
	{
		QMessageBox::warning(this, "警告", "更新参数到XML失败");
		return;
	}
	QTextStream out(&xmlFile);
	doc.save(out, 4);
	xmlFile.close();
}

void LSMainWindow::showCustomDelegate()
{
	int rowCount = theModel->rowCount();
	for (int i = 0; i < rowCount; ++i)
	{
		ui.tableView->openPersistentEditor(theModel->index(i, ComboBoxDelegate::EXPOSUREMODE));
		ui.tableView->openPersistentEditor(theModel->index(i, ComboBoxDelegate::ACQUISITIONMODE));
		//		ui.tableView->openPersistentEditor(theModel->index(i, ComboBoxDelegate::SPOTMETERSHAPE));
		ui.tableView->openPersistentEditor(theModel->index(i, ComboBoxDelegate::SPOTMETERRESULTCOLORSPACE));
	}
}

void LSMainWindow::on_CreateBtn_clicked()          //创建新模组,必须要点击保存按钮才生效
{
	QString dlgTitle = "新建模组";
	QString txtLabel = "模组命名";
	QLineEdit::EchoMode echoMode = QLineEdit::Normal;
	bool ok = false;
	QString text = QInputDialog::getText(this, dlgTitle, txtLabel, echoMode, "", &ok);
	/*QInputDialog input(this);
	input.setTextEchoMode(echoMode);
	input.setTextValue("");
	input.setInputMode(QInputDialog::TextInput);
	input.setLabelText(dlgTitle);
	input.setCancelButtonText("取消");
	input.setOkButtonText("确定");
	input.setWindowTitle("新建模组");
	input.exec();
	QString text = input.textValue();*/

	if (!ok)
	{
		QMessageBox::warning(this, "警告", "命名失败");
	}
	else if (text.isEmpty())
	{
		QMessageBox::warning(this, "警告", "命名不能为空");
	}
	else
	{  //还需要复制模组文件
		ui.ModuleNamelineEdit->setText(text);
		if (theModel->rowCount() > 0)
		{
			QString curPath = QDir::currentPath();
			QString curModuleName = ui.tableWidgetList->currentItem()->text();
			QString curModuleFilePath = curPath + "\\ModuleXml\\" + curModuleName + ".xml";
			QString createModuleFilePath = curPath + "\\ModuleXml\\" + text + ".xml";
			QFile curModuleFile(curModuleFilePath);
			bool Result = curModuleFile.copy(createModuleFilePath);
			if (Result)
				QMessageBox::information(this, "通知", "Create " + text + " 模组成功,请点击保存按钮保存模组.");
			else
				QMessageBox::warning(this, "警告", "Create 模组失败!");
		}
	}
}

void LSMainWindow::on_SaveBtn_clicked()          //保存模组
{
	QString name = ui.ModuleNamelineEdit->text();
	if (name.isEmpty())
	{
		QMessageBox::warning(this, "警告", "模组名为空");
	}
	else if (modName.contains(name))          //模组已存在
	{
		QMessageBox::warning(this, "警告", "模组已存在");
	}
	else
	{
		QTableWidgetItem* item = new QTableWidgetItem(name);
		int rowCount = ui.tableWidgetList->rowCount();
		ui.tableWidgetList->insertRow(rowCount);
		ui.tableWidgetList->setItem(rowCount, 0, item);
		ui.tableWidgetList->selectRow(rowCount);                  //设置新添加的行为选中状态
		modName.push_back(name);                             //将模组名添加到容器中
	}
}

void LSMainWindow::on_DeleteBtn_clicked()                         //删除模组
{
	if (ui.tableWidgetList->rowCount() == 0)
	{
		QMessageBox::warning(this, "警告", "没有模组可以删除");
	}
	else
	{
		QMessageBox::StandardButton btn = QMessageBox::warning(this, "警告", "确定删除模组?", QMessageBox::Ok | QMessageBox::Cancel);
		if (btn == QMessageBox::Ok)
		{
			QList<QTableWidgetSelectionRange> list = ui.tableWidgetList->selectedRanges();
			QTableWidgetSelectionRange range = list.at(0);
			int len = range.rowCount();
			for (int i = 0; i < len; ++i)                                      //删除选中的行
			{
				int rIndex = ui.tableWidgetList->currentRow();                    //当前行下标
				ui.tableWidgetList->removeRow(rIndex);
				modName.removeAt(rIndex);
				clearTableView();
			}
			if (ui.tableWidgetList->rowCount() != 0)
			{
				QTableWidgetItem* item = ui.tableWidgetList->currentItem();
				ui.tableWidgetList->selectRow(item->row());
				operateXmltoParameterList(item->text());
			}
		}
	}
}

void LSMainWindow::on_ImportBtn_clicked()               //导入模组
{
	QString curPath = QDir::currentPath();
	curPath += "\\ModuleXml";
	QString filter = "ModuleFile(*.xml)";
	QString fileName = QFileDialog::getOpenFileName(this, "导入模组", curPath, filter);
	QStringList slist = fileName.split('/');
	QString completeName = slist.at(slist.size() - 1);
	QStringList list = completeName.split('.');
	QString moduleName = list.at(0);
	//	qDebug() << fileName;
	if (modName.contains(moduleName))
	{
		QMessageBox::warning(this, "警告", "模组已存在");
	}
	else
	{
		QTableWidgetItem* item = new QTableWidgetItem(moduleName);
		int rowCount = ui.tableWidgetList->rowCount();
		ui.tableWidgetList->insertRow(rowCount);                            //插入一个空行,触发cellChanged()信号
		ui.tableWidgetList->setItem(rowCount, 0, item);                     //填充内容
		modName.push_back(moduleName);
		ui.tableWidgetList->selectRow(rowCount);
		QMessageBox::information(this, "通知", "导入模组成功");
	}
}

void LSMainWindow::on_ExportBtn_clicked()
{
	QString curPath = QDir::currentPath();
	QString filter = "ModuleFile(*.xml)";
	if (ui.tableWidgetList->rowCount() > 0)
	{
		QTableWidgetItem* curItem = ui.tableWidgetList->currentItem();
		QString moduleName = curItem->text();
		QString fileName = QFileDialog::getSaveFileName(this, "导出模组文件", "./module/" + moduleName + ".xml", filter);
		//		qDebug() << "defauleName:" << fileName;
		if (fileName.isEmpty())
		{
			QMessageBox::warning(this, "警告", "模组未导出");
		}
		QFile file(curPath + "/ModuleXml/" + moduleName + ".xml");
		bool res = file.copy(fileName);
		if (res)
		{
			QMessageBox::information(this, "通知", "导出模组成功");
		}
	}
	else
	{
		QMessageBox::warning(this, "警告", "没有模组可以导出");
	}
}


void LSMainWindow::on_CopyBtn_clicked()
{
	if (ui.tableWidgetList->rowCount() == 0)
	{
		QMessageBox::warning(this, "警告", "没有模组可以复制");
		return;
	}
	else
	{
		QTableWidgetItem* curItem = ui.tableWidgetList->currentItem();
		this->cMD->getOldLineEdit()->setText(curItem->text());
		this->cMD->clearNewLineEdit();
		cMD->exec();
		QString newModuleName = cMD->Name();
		//		qDebug() << "新模块名:" << newModuleName;
		if (!newModuleName.isEmpty())
		{
			QString curPath = QDir::currentPath();
			QTableWidgetItem* item = new QTableWidgetItem(newModuleName);
			if (curItem->text() == newModuleName)
			{
				QMessageBox::warning(this, "警告", "命名重复");
			}
			QFile originFile(curPath + "/ModuleXml/" + curItem->text() + ".xml");
			QString copyFile = curPath + "/ModuleXml/" + newModuleName + ".xml";
			bool res = originFile.copy(copyFile);
			if (res)
			{
				int rowCount = ui.tableWidgetList->rowCount();
				ui.tableWidgetList->insertRow(rowCount);
				ui.tableWidgetList->setItem(rowCount, 0, item);
				ui.tableWidgetList->selectRow(rowCount);
				QMessageBox::information(this, "通知", "复制模组成功");
			}
			modName.push_back(newModuleName);
		}
	}
}


void LSMainWindow::switchModule(int row, int col)
{
	qDebug() << "信号被触发.";
	clearTableView();                    //切换模组之前清空原先的数据
	QTableWidgetItem* item = ui.tableWidgetList->item(row, col);
	QString ModuleName = item->text();
	ui.ModuleNamelineEdit->setText(ModuleName);
	operateXmltoParameterList(ModuleName);
	InitLumiTopAndCASparmList();                        //更新参数
	InitImageProcessAndAnalysisparmList();
}

void LSMainWindow::clearTableView()
{
	int row = theModel->rowCount();
	theModel->removeRows(0, row, QModelIndex());
}

void LSMainWindow::on_AddBtn_clicked()
{
	QModelIndex index = ui.tableView->currentIndex();
	int row = index.row();
	theModel->insertRow(row + 1, QModelIndex());
	ui.tableView->selectRow(row + 1);
	showCustomDelegate();
}

void LSMainWindow::on_DelBtn_clicked()
{
	QModelIndex index = ui.tableView->currentIndex();
	int row = index.row();
	theModel->removeRow(row, QModelIndex());
	QModelIndex index2 = ui.tableView->currentIndex();
	if (index2.isValid())
	{
		ui.tableView->selectRow(index2.row());
	}
}

void LSMainWindow::on_UpBtn_clicked()
{
	QModelIndex index = ui.tableView->currentIndex();
	int row = index.row();
	if (row >= 1 && theModel->rowCount() > 1)
	{
		QList<QStandardItem*> list = theModel->takeRow(row);
		theModel->insertRow(row - 1, list);
		ui.tableView->selectRow(row - 1);
		showCustomDelegate();
	}
}

void  LSMainWindow::on_DownBtn_clicked()
{
	QModelIndex index = ui.tableView->currentIndex();
	int row = index.row();
	int rowCount = theModel->rowCount();
	if (row < rowCount - 1 && rowCount>1)
	{
		QList<QStandardItem*> list = theModel->takeRow(row);
		theModel->insertRow(row + 1, list);
		ui.tableView->selectRow(row + 1);
		showCustomDelegate();
	}
}


void LSMainWindow::on_SaveParmsBtn_clicked()
{
	QString moduleName = ui.tableWidgetList->currentItem()->text();
	updateParmstoXml(moduleName);
	InitLumiTopAndCASparmList();         //参数改变后需要更新设备的参数
	InitImageProcessAndAnalysisparmList();
}

void LSMainWindow::writeSettings()
{
	QSettings settings("JC", "LumiSuite");
	QTableWidgetItem* item = ui.tableWidgetList->currentItem();
	settings.setValue("curSelectItem", item->row());          //当前选中模组的行号
	settings.setValue("moduleNumber", modName.size());       //模组的数量
	for (int i = 0; i < modName.size(); ++i)
		settings.setValue("Module" + QString::number(i), modName[i]);
}

void LSMainWindow::readSettings()
{
	QSettings settings("JC", "LumiSuite");
	int curRow = settings.value("curSelectItem").toInt();
	int moduleNumber = settings.value("moduleNumber").toInt();
	for (int i = 0; i < moduleNumber; ++i)
	{
		QString moduleName = settings.value("Module" + QString::number(i)).toString();
		modName.push_back(moduleName);
		QTableWidgetItem* item = new QTableWidgetItem(moduleName);
		ui.tableWidgetList->insertRow(i);
		ui.tableWidgetList->setItem(i, 0, item);
	}
	if (moduleNumber > 0)
	{
		ui.tableWidgetList->selectRow(curRow);
		QString curModuleName = ui.tableWidgetList->currentItem()->text();
		ui.ModuleNamelineEdit->setText(curModuleName);
		operateXmltoParameterList(curModuleName);
	}
}

void LSMainWindow::closeEvent(QCloseEvent* event)
{
	//关闭窗口前写入应用程序设置
	writeSettings();
	event->accept();
}

void LSMainWindow::on_moduleObjectFile_triggered()
{
	modEdit->getTextEdit()->clear();           //清除先前的xml
	modEdit->getModuleLabel()->clear();            //清除先前的模组名
	QDomDocument doc;
	QString xmlPath = QDir::currentPath();
	QTableWidgetItem* item = ui.tableWidgetList->currentItem();
	QString moduleName = item->text();
	xmlPath = xmlPath + "\\ModuleXml\\" + moduleName + ".xml";
	QFile file(xmlPath);            //TestWHTianMa.xml
	if (!file.open(QIODevice::ReadOnly))
	{
		QMessageBox::warning(this, "警告", "打开xml配置文件失败!");
		return;
	}
	if (!doc.setContent(&file))
	{
		QMessageBox::warning(this, "警告", "读取xml配置文件失败!");
		file.close();
		return;
	}
	file.close();
	QFile showXml(xmlPath);
	if (!showXml.open(QIODevice::WriteOnly | QIODevice::Truncate))
	{
		QMessageBox::warning(this, "警告", "打开临时文件失败!");
	}

	QTextStream out(&showXml);
	doc.save(out, 4);
	showXml.close();
	if (!file.open(QIODevice::ReadOnly))
	{
		QMessageBox::warning(this, "警告", "打开xml配置文件失败!");
		return;
	}
	while (!file.atEnd())
	{
		QString	line = file.readAll();
		modEdit->getTextEdit()->append(line);
	}
	//	modEdit->getTextEdit()->setWordWrapMode(QTextOption::NoWrap);
	modEdit->show();
	QFont font("Microsoft YaHei", 8, 80);
	modEdit->getModuleLabel()->setFont(font);
	modEdit->getModuleLabel()->setText(moduleName);
	file.close();
}


void LSMainWindow::InitLumiTopAndCASparmList()
{
	GlobalVar::LTOPDParmList.clear();  //每次更新前需要清除上次的参数
	GlobalVar::CASParmList.clear();
	//不包含句柄初始化
	LS_LTOPD_2dMeasurement_Parameter_Struct LTOPD;
	LS_LTOPD_Measurement_Parameter_CAS_Struct CAS;
	int row = theModel->rowCount();
	QString moduleName = ui.tableWidgetList->currentItem()->text();
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < 12; ++j)
		{
			if (j == 0)
			{
				QString gray = theModel->item(i, j)->text();
				LTOPD.ModuleAndGrayName = moduleName + "_" + gray;
				CAS.ModuleAndGrayName = moduleName + "_" + gray;
			}
			else if (j == 1)
			{
				QString mode = theModel->item(i, j)->text();
				if (mode == "LS_SDK_Exposure_Fixed")
					LTOPD.LumiTop2dParm._in_exposureMode = CAS.CASParm._in_exposureMode = LS_SDK_ExposureMode_t::LS_SDK_Exposure_Fixed;
				else if (mode == "LS_SDK_Exposure_Auto")
					LTOPD.LumiTop2dParm._in_exposureMode = CAS.CASParm._in_exposureMode = LS_SDK_ExposureMode_t::LS_SDK_Exposure_Auto;
			}
			else if (j == 2)
				LTOPD.LumiTop2dParm._in_exposureTime = theModel->item(i, j)->text().toFloat();
			else if (j == 3)
				LTOPD.LumiTop2dParm._in_averageNumber = CAS.CASParm._in_averageNumber = theModel->item(i, j)->text().toInt();
			else if (j == 4)
				CAS.CASParm._in_integrationTime = theModel->item(i, j)->text().toFloat();
			else if (j == 9)
				CAS.CASParm._in_densityFilter = theModel->item(i, j)->text().toUInt();
			else if (j == 10)
			{
				QString mode = theModel->item(i, j)->text();
				if (mode == "LS_SDK_AquMode_Hybrid")
					LTOPD.LumiTop2dParm._in_acquisitionMode = LS_SDK_AquisitionMode_t::LS_SDK_AquMode_Hybrid;
				else
					LTOPD.LumiTop2dParm._in_acquisitionMode = LS_SDK_AquisitionMode_t::LS_SDK_AquMode_Chroma;
			}
			else if (j == 11)
				CAS.CASParm._in_maxAutoIntegrationTime = theModel->item(i, j)->text().toFloat();
		}
		GlobalVar::LTOPDParmList.push_back(LTOPD);
		GlobalVar::CASParmList.push_back(CAS);
	}
}

void LSMainWindow::InitImageProcessAndAnalysisparmList()
{
	GlobalVar::ImageProcessAndAnalysisParmList.clear();
	ImageProcessAndAnalysisParmsStruct IPAPS;
	int row = theModel->rowCount();
	int column = theModel->columnCount();
	QString moduleName = ui.tableWidgetList->currentItem()->text();
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < column; ++j)
		{
			if (j == 0)
			{
				QString gray = theModel->item(i, j)->text();
				IPAPS.ModuleAndGrayName = moduleName + "_" + gray;
			}
			else if (j == 5)
			{
				IPAPS.gridX = theModel->item(i, j)->text().toFloat();
			}
			else if (j == 6)
			{
				IPAPS.gridY = theModel->item(i, j)->text().toFloat();
			}
			else if (j == 7)
			{
				IPAPS.gridRow = theModel->item(i, j)->text().toInt();
			}
			else if (j == 8)
			{
				IPAPS.gridColumn = theModel->item(i, j)->text().toInt();
			}
			else if (j == 12)
			{
				QString colorSpace = theModel->item(i, j)->text();
				if (colorSpace == "LS_SDK_ColorSpace_Lvxy")
					IPAPS.resultColorSpace = LS_SDK_ColorSpace_t::LS_SDK_ColorSpace_Lvxy;
				else if (colorSpace == "LS_SDK_ColorSpace_XYZ")
					IPAPS.resultColorSpace = LS_SDK_ColorSpace_t::LS_SDK_ColorSpace_XYZ;
			}
			else if (j == 13)
			{
				IPAPS.gridSoptWidth = theModel->item(i, j)->text().toFloat();
			}
			else if (j == 14)
			{
				IPAPS.gridSpotHeight = theModel->item(i, j)->text().toFloat();
			}
		}
		GlobalVar::ImageProcessAndAnalysisParmList.push_back(IPAPS);
	}
}

void LSMainWindow::on_ConnectDevice_triggered()
{
	InitLumiTopAndCASparmList();                 //初始化参数
	InitImageProcessAndAnalysisparmList();
	bool Flag = setupSDKAndLumiTOP(GlobalVar::context, GlobalVar::sensorConnectInfo, ui.CASDevice->isChecked());
	if (!Flag)
	{
		ui.ConnectDevice->setIcon(QIcon(":/LSMainWindow/Resources/LC_3.png"));
		ui.informationBar->append("连接设备失败!");
//		QMessageBox::warning(this, "警告", "连接设备失败!");
	}
	else
	{
		ui.ConnectDevice->setIcon(QIcon(":/LSMainWindow/Resources/LC_2.png"));
		ui.informationBar->append("连接设备成功.");
//		QMessageBox::information(this, "通知", "连接设备成功.");
	}
}

void LSMainWindow::on_DisconnectDevice_triggered()
{
	bool Flag = destroySDKAndLumiTop(GlobalVar::context, GlobalVar::sensorConnectInfo);
	if (!Flag)
	{
		ui.DisconnectDevice->setIcon(QIcon(":/LSMainWindow/Resources/LC_3.png"));
		QMessageBox::warning(this, "警告", "断开设备失败");
	}
	else
	{
		//ui.DisconnectDevice->setIcon(QIcon(":/LSMainWindow/Resources/LC_2.png"));
		QMessageBox::information(this, "通知", "断开设备成功");
	}
}

void LSMainWindow::on_ImageProcessing_triggered()
{
	imageProcessing->getTextEdit()->clear();
	imageProcessing->show();
}
