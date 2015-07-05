/********************************************************************************
** Form generated from reading UI file 'qtRoboTester.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTROBOTESTER_H
#define UI_QTROBOTESTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtRoboTesterClass
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *ActivateBtn;
    QPushButton *DeactivateBtn;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton_Rad;
    QRadioButton *radioButton_Deg;
    QButtonGroup *buttonGroup;

    void setupUi(QMainWindow *QtRoboTesterClass)
    {
        if (QtRoboTesterClass->objectName().isEmpty())
            QtRoboTesterClass->setObjectName(QStringLiteral("QtRoboTesterClass"));
        QtRoboTesterClass->setWindowModality(Qt::NonModal);
        QtRoboTesterClass->resize(694, 380);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QtRoboTesterClass->sizePolicy().hasHeightForWidth());
        QtRoboTesterClass->setSizePolicy(sizePolicy);
        QtRoboTesterClass->setWindowOpacity(0.99);
        QtRoboTesterClass->setDocumentMode(false);
        centralWidget = new QWidget(QtRoboTesterClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 77, 83));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        ActivateBtn = new QPushButton(layoutWidget);
        ActivateBtn->setObjectName(QStringLiteral("ActivateBtn"));

        verticalLayout->addWidget(ActivateBtn);

        DeactivateBtn = new QPushButton(layoutWidget);
        DeactivateBtn->setObjectName(QStringLiteral("DeactivateBtn"));

        verticalLayout->addWidget(DeactivateBtn);

        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(100, 10, 581, 361));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        radioButton_Rad = new QRadioButton(centralWidget);
        buttonGroup = new QButtonGroup(QtRoboTesterClass);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(radioButton_Rad);
        radioButton_Rad->setObjectName(QStringLiteral("radioButton_Rad"));
        radioButton_Rad->setEnabled(true);
        radioButton_Rad->setGeometry(QRect(20, 130, 61, 17));
        radioButton_Rad->setChecked(true);
        radioButton_Deg = new QRadioButton(centralWidget);
        buttonGroup->addButton(radioButton_Deg);
        radioButton_Deg->setObjectName(QStringLiteral("radioButton_Deg"));
        radioButton_Deg->setGeometry(QRect(20, 150, 61, 17));
        QtRoboTesterClass->setCentralWidget(centralWidget);

        retranslateUi(QtRoboTesterClass);
        QObject::connect(ActivateBtn, SIGNAL(clicked()), QtRoboTesterClass, SLOT(Activate()));
        QObject::connect(DeactivateBtn, SIGNAL(clicked()), QtRoboTesterClass, SLOT(Deactivate()));
        QObject::connect(radioButton_Deg, SIGNAL(toggled(bool)), QtRoboTesterClass, SLOT(ToggleOutputType()));
        QObject::connect(radioButton_Rad, SIGNAL(toggled(bool)), QtRoboTesterClass, SLOT(ToggleOutputType()));

        QMetaObject::connectSlotsByName(QtRoboTesterClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtRoboTesterClass)
    {
        QtRoboTesterClass->setWindowTitle(QApplication::translate("QtRoboTesterClass", "QtRoboTester", 0));
        ActivateBtn->setText(QApplication::translate("QtRoboTesterClass", "Activate!", 0));
        DeactivateBtn->setText(QApplication::translate("QtRoboTesterClass", "Deactivate!", 0));
        radioButton_Rad->setText(QApplication::translate("QtRoboTesterClass", "Radians", 0));
        radioButton_Deg->setText(QApplication::translate("QtRoboTesterClass", "Degrees", 0));
    } // retranslateUi

};

namespace Ui {
    class QtRoboTesterClass: public Ui_QtRoboTesterClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTROBOTESTER_H
