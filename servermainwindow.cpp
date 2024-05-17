#include "servermainwindow.h"
#include "ui_servermainwindow.h"
#include <QMessageBox>

ServerMainWindow::ServerMainWindow(std::shared_ptr<Database> dbPtr, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ServerMainWindow),
    m_dbPtr(dbPtr)
{
    ui->setupUi(this);
    connect(ui->disconnectButton, &QPushButton::clicked, this, &ServerMainWindow::disconnectUser);
    connect(ui->banButton, &QPushButton::clicked, this, &ServerMainWindow::banUser);
    updateUserList();
    updateChatMessages();
}

ServerMainWindow::~ServerMainWindow()
{
    delete ui;
}

void ServerMainWindow::disconnectUser()
{
    QString selectedUser = ui->userList->currentItem()->text();

    emit userDisconnected(selectedUser);
}

void ServerMainWindow::banUser()
{

    QString selectedUser = ui->userList->currentItem()->text();

    emit userBanned(selectedUser);
}

void ServerMainWindow::updateUserList()
{
    ui->userList->clear();

    std::vector<std::string> users = m_dbPtr->getUserList();

    for (const auto& user : users) {
        ui->userList->addItem(QString::fromStdString(user));
    }
}

void ServerMainWindow::updateChatMessages()
{
    ui->chatMessages->clear();

    std::vector<std::string> messages = m_dbPtr->getChatMessages();

    for (const auto& message : messages) {
        ui->chatMessages->addItem(QString::fromStdString(message));
    }
}


