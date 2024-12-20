#include "imagefilterproxymodel.h"
#include <QFileSystemModel>

ImageFilterProxyModel::ImageFilterProxyModel(QObject *parent)
    : QSortFilterProxyModel(parent)
{
}

bool ImageFilterProxyModel::filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const
{
    QModelIndex index = sourceModel()->index(sourceRow, 0, sourceParent);

    QFileSystemModel *fsModel = qobject_cast<QFileSystemModel *>(sourceModel());
    if (!fsModel) {
        return false;  // If the source model isn't a QFileSystemModel, filter nothing
    }

    // Always allow directories
    if (fsModel->isDir(index)) {
        return true;
    }

    // Allow files that match the desired extensions
    QString fileName = fsModel->fileName(index).toLower();
    return fileName.endsWith(".jpg") ||
           fileName.endsWith(".jpeg") ||
           fileName.endsWith(".png") ||
           fileName.endsWith(".gif") ||
           fileName.endsWith(".bmp") ||
           fileName.endsWith(".webp");
}
