//#include "stdafx.h"
#include "ModuleEdit.h"

ModuleEdit::ModuleEdit(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	//去除对话框右上角的问号
	Qt::WindowFlags flags = this->windowFlags();
	setWindowFlags(flags&~Qt::WindowContextHelpButtonHint);
	this->resize(QSize(900, 580));
	ui.moduleXml->setReadOnly(true);
}

ModuleEdit::~ModuleEdit()
{

}
