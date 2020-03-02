#pragma once

#include <QDialog>
#include "ui_ModuleEdit.h"
#include <QPlainTextEdit>

class ModuleEdit : public QDialog
{
	Q_OBJECT
public:
	ModuleEdit(QWidget *parent = Q_NULLPTR);
	~ModuleEdit();
	QTextEdit* getTextEdit(){return ui.moduleXml;}
	QLabel* getModuleLabel() { return ui.moduleLabel; }
private:
	Ui::ModuleEdit ui;
};
