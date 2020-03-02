#pragma once

#include <QDialog>
#include "ui_copyModuleDialog.h"
#include <QLineEdit>
#include <QString>

class copyModuleDialog : public QDialog
{
	Q_OBJECT

public:
	copyModuleDialog(QWidget *parent = Q_NULLPTR);
	~copyModuleDialog();
	QLineEdit* getOldLineEdit() { return ui.oldNamelineEdit; }
	void clearNewLineEdit() { ui.newNamelineEdit->clear(); }
	QString Name() { return newModuleName; }

public slots:
void getNewModuleName();

private:
	Ui::copyModuleDialog ui;
	QString newModuleName;
};
