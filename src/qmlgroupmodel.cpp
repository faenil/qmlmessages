// XXX header

#include "qmlgroupmodel.h"

QmlGroupModel::QmlGroupModel(QObject *parent)
    : CommHistory::GroupModel(parent)
{
    QHash<int,QByteArray> roles;
    roles[Qt::DisplayRole] = "displayName";
    roles[LastMessageTextRole] = "messagePreview";
    roles[LastModifiedRole] = "messageDate";
    setRoleNames(roles);

    getGroups();
}

QVariant QmlGroupModel::data(const QModelIndex &index, int role) const
{
    int column = index.column();

    switch (role) {
        case Qt::DisplayRole: column = RemoteUids; break;
        case LastMessageTextRole: column = LastMessageText; break;
        case LastModifiedRole: column = LastModified; break;
    }

    QVariant re = CommHistory::GroupModel::data(this->index(index.row(), column, index.parent()), Qt::DisplayRole);
    if (role == Qt::DisplayRole) {
        re = re.value<QVariantList>()[0];
    }
    return re;
}

