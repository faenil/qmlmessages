// XXX header

#include "qmlgroupmodel.h"
#include "qmlchatmodel.h"

QmlGroupModel::QmlGroupModel(QObject *parent)
    : CommHistory::GroupModel(parent)
{
    QHash<int,QByteArray> roles;
    roles[Qt::DisplayRole] = "displayName";
    roles[LastMessageTextRole] = "messagePreview";
    roles[LastModifiedRole] = "messageDate";
    roles[ConversationRole] = "conversation";
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
        case ConversationRole: {
            int groupid = CommHistory::GroupModel::data(this->index(index.row(), GroupId, index.parent())).toInt();
            QmlChatModel *model = new QmlChatModel(groupid);
            return QVariant::fromValue<QObject*>(model);
        }
    }

    QVariant re = CommHistory::GroupModel::data(this->index(index.row(), column, index.parent()), Qt::DisplayRole);
    if (role == Qt::DisplayRole) {
        re = re.value<QVariantList>()[0];
    }
    return re;
}

