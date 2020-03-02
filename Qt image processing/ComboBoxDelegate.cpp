//#include "stdafx.h"
#include "ComboBoxDelegate.h"
#include <QComboBox>

ComboBoxDelegate::ComboBoxDelegate(QObject *parent)
	: QItemDelegate(parent)
{
}

ComboBoxDelegate::~ComboBoxDelegate()
{
}

void ComboBoxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
	QString str = index.model()->data(index, Qt::EditRole).toString();
	QComboBox *comboBox = static_cast<QComboBox*>(editor);
	comboBox->setCurrentText(str);
}

void ComboBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
	QComboBox *comboBox = static_cast<QComboBox*>(editor);

	QString str = comboBox->currentText();

	model->setData(index, str, Qt::EditRole);
}

void ComboBoxDelegate::updateEditorGeometry(QWidget *editor,
	const QStyleOptionViewItem &option, const QModelIndex &index) const
{
	editor->setGeometry(option.rect);
}

QWidget* exposureModeComDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index)const
{
	if (!index.isValid() || index.column() != EXPOSUREMODE)
		QItemDelegate::createEditor(parent, option, index);
	else
	{
		QComboBox *editor = new QComboBox(parent);
		editor->addItem("LS_SDK_Exposure_Fixed");
		editor->addItem("LS_SDK_Exposure_Auto");
		return editor;
	}
}

QWidget* acquisitionModeComDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index)const
{
	if (!index.isValid() || index.column() != ACQUISITIONMODE)
		QItemDelegate::createEditor(parent, option, index);
	else
	{
		QComboBox *editor = new QComboBox(parent);
		editor->addItem("LS_SDK_AquMode_Hybrid");
		editor->addItem("LS_SDK_AquMode_Chroma");
		return editor;
	}
}


QWidget* spotMeterShapeComDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index)const
{
	if (!index.isValid() || index.column() != SPOTMETERSHAPE)
		QItemDelegate::createEditor(parent, option, index);
	else
	{
		QComboBox *editor = new QComboBox(parent);
		editor->addItem("LS_SDK_Shape_Circle");
		editor->addItem("LS_SDK_Shape_Square");
		return editor;
	}
}


QWidget* spotMeterResultColorSpaceComDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index)const
{
	if (!index.isValid() || index.column() != SPOTMETERRESULTCOLORSPACE)
		QItemDelegate::createEditor(parent, option, index);
	else
	{
		QComboBox *editor = new QComboBox(parent);
		//editor->addItem("LS_SDK_ColorSpace_Auto");
		editor->addItem("LS_SDK_ColorSpace_XYZ");
		editor->addItem("LS_SDK_ColorSpace_Lvxy");
		return editor;
	}
}
