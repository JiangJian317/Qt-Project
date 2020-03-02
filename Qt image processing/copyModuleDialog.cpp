//#include "stdafx.h"
#include "copyModuleDialog.h"

copyModuleDialog::copyModuleDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	//去除对话框右上角的问号
	Qt::WindowFlags flags = this->windowFlags();
	setWindowFlags(flags&~Qt::WindowContextHelpButtonHint);
	//固定大小
	this->setFixedWidth(413);
	this->setFixedHeight(166);
	ui.oldNamelineEdit->setReadOnly(true);
	connect(ui.SaveBtn, &QPushButton::clicked, this, &copyModuleDialog::getNewModuleName);
	connect(ui.QuitBtn, &QPushButton::clicked, this, &copyModuleDialog::getNewModuleName);
}

copyModuleDialog::~copyModuleDialog()
{
}

void copyModuleDialog::getNewModuleName()
{
	QPushButton* btn = qobject_cast<QPushButton*>(sender());
	if (btn->objectName() == "SaveBtn")
	{
		this->close();
		newModuleName = ui.newNamelineEdit->text();
		return;
	}
	else if (btn->objectName() == "QuitBtn")
	{
		this->close();
		newModuleName = "";
		return;
	}
}
