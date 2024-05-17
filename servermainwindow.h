#ifndef SERVERMAINWINDOW_H
#define SERVERMAINWINDOW_H

#include <QMainWindow>
#include <memory>
#include "database.h"

namespace Ui {
class ServerMainWindow;
}

class ServerMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ServerMainWindow(std::shared_ptr<Database> dbPtr, QWidget *parent = nullptr);
    ~ServerMainWindow();

signals:
    void userDisconnected(const QString &username);
    void userBanned(const QString &username);

private:
    Ui::ServerMainWindow *ui;
    std::shared_ptr<Database> m_dbPtr;

private slots:
    void disconnectUser();
    void banUser();
    void updateUserList();
    void updateChatMessages();
};

#endif // SERVERMAINWINDOW_H

