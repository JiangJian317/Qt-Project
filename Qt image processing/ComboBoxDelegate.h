#pragma once

#include <QItemDelegate>

class ComboBoxDelegate : public QItemDelegate
{
	Q_OBJECT
public:
	enum { EXPOSUREMODE = 1, SPOTMETERSHAPE = 8, ACQUISITIONMODE = 10, SPOTMETERRESULTCOLORSPACE = 12 };
    ComboBoxDelegate(QObject *parent = Q_NULLPTR);
    ~ComboBoxDelegate()Q_DECL_OVERRIDE;
//	QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
//		const QModelIndex &index) const Q_DECL_OVERRIDE;
	void setEditorData(QWidget *editor, const QModelIndex &index) const Q_DECL_OVERRIDE;
	void setModelData(QWidget *editor, QAbstractItemModel *model,
		const QModelIndex &index) const Q_DECL_OVERRIDE;
	void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option,
		const QModelIndex &index) const Q_DECL_OVERRIDE;
};

//定义四个委托控件
class exposureModeComDelegate :public ComboBoxDelegate
{
public:
    exposureModeComDelegate(QWidget* parent = Q_NULLPTR):ComboBoxDelegate(parent){}
	QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
				const QModelIndex &index) const Q_DECL_OVERRIDE;
};

class acquisitionModeComDelegate :public ComboBoxDelegate
{
public:
    acquisitionModeComDelegate(QWidget* parent = Q_NULLPTR):ComboBoxDelegate(parent){}
	QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
		const QModelIndex &index) const Q_DECL_OVERRIDE;
};

class spotMeterShapeComDelegate :public ComboBoxDelegate
{
public:
    spotMeterShapeComDelegate(QWidget* parent = Q_NULLPTR):ComboBoxDelegate(parent){}
	QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
		const QModelIndex &index) const Q_DECL_OVERRIDE;
};

class spotMeterResultColorSpaceComDelegate : public ComboBoxDelegate
{
public:
    spotMeterResultColorSpaceComDelegate(QWidget* parent = Q_NULLPTR):ComboBoxDelegate(parent){}
	QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
		const QModelIndex &index) const Q_DECL_OVERRIDE;
};
