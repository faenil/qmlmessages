#ifndef QMLCHATMODEL_H
#define QMLCHATMODEL_H

#include <CommHistory/ConversationModel>

class QmlChatModel : public CommHistory::ConversationModel
{
public:
    enum {
        DirectionRole = Qt::UserRole,
        StartTimeRole,
        StatusRole
    };

    QmlChatModel(int groupid, QObject *parent = 0);

    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
};

Q_DECLARE_METATYPE(QmlChatModel*);

#endif

