#include <QApplication>
#include <QTextCodec>
#include "jsoneditormain.h"
#include <QSettings>
#include "version.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    QTextCodec::setCodecForTr(QTextCodec::codecForName("gbk"));

    QSettings::setDefaultFormat(QSettings::IniFormat);//ini配置文件
    a.setApplicationName(VER_INTERNALNAME_STR);//设置公司名字
    a.setOrganizationName(VER_COMPANYNAME_STR);//设置程序名称
    JsonEditorMain w;
    w.show();
    return a.exec();
}
