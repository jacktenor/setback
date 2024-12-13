#ifndef IMAGEFILTERPROXYMODEL_H
#define IMAGEFILTERPROXYMODEL_H

#include <QSortFilterProxyModel>

class ImageFilterProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    explicit ImageFilterProxyModel(QObject *parent = nullptr);

protected:
    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const override;
};

#endif // IMAGEFILTERPROXYMODEL_H
