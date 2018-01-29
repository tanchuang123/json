#include "JsonRead.h"
#include<QFile>
#include<QFileInfo>
#include<QDir>
#include<QJsonDocument>
#include<QtDebug>
JsonRead::JsonRead()
{

//    getJsonVarian("F:/work/WORK/123/JsonVar/RoPlugins.json");
//    QVariant var;
//    qDebug()<< var.toMap().value("pluginName").toString();

}
QVariant JsonRead::getJsonVariant(const QByteArray &json)
{
    // 1. 创建 QJsonParseError 对象，用来获取解析结果
    QJsonParseError error;//报告JSON过程中出现的错误
    QVariant var;    // 2. 使用静态函数获取 QJsonDocument 对象
    QJsonDocument jsonDocument = QJsonDocument::fromJson(json, &error);
    // 3. 根据解析结果进行处理
    if (error.error == QJsonParseError::NoError)
    {
        if (!(jsonDocument.isNull() || jsonDocument.isEmpty()))
        {
            if (jsonDocument.isObject())
            {
                var = jsonDocument.toVariant().toMap();
            }
            else if(jsonDocument.isArray())//数组
            {
                var = jsonDocument.toVariant().toList();
            }
        }
        else
        {
            //                   SCWarning<<"jsonDocument.isEmpty()";
            qWarning()<<"jsonDocument.isEmpty()";
        }
    }
    else
    {
        //       SCWarning<<error.errorString().toUtf8().constData();
        qWarning()<<"error:"<<error.errorString().toUtf8().constData();
    }
    return var;
}
//Json转成QVariant
QVariant JsonRead::getJsonVarian(const QString &filePath)
{
    QByteArray json;
    QFileInfo fileInfo(filePath);
    if(fileInfo.isFile()){
        QFile file(fileInfo.absoluteFilePath());
        if(file.open(QIODevice::ReadOnly)){
            json = file.readAll();
            file.close();
        }
    }else{
        qWarning()<<fileInfo.filePath()<<"is not a file";
    }
    return getJsonVariant(json);
}
void JsonRead::addFolderImages(QString path)
{
    //判断路径是否存在
    QDir dir(path);
    if(!dir.exists())//判断目录是否存在
    {
        return;
    }
    dir.setFilter(QDir::Files|QDir::NoSymLinks);//设置类型过滤器，只为文件格式
//    dir.setNameFilters(filters);  //设置文件名称过滤器，只为filters格式（后缀为.jpeg等图片格式
//    entryList()可以获得目录中的所有文件和目录的名称的字符串列表。
//    如果你希望得到QFileInfo指针的列表请使用entryInfoList()
    QFileInfoList list=dir.entryInfoList();//获取文件目录的指针列表
    int file_count=list.count();
    if(file_count<=0)
    {
        return;
    }
    QStringList string_list;
    for(int i=0;i<list.size();i++)
    {
        QFileInfo file_info=list.at(i);
        QString suffix=file_info.suffix();//判定文件的后缀、扩展名
        if(QString::compare(suffix,QString(""),Qt::CaseInsensitive)==0)//Qt::CaseInsensitive不区分大小写
        {
            QString absolute_file_path=file_info.absoluteFilePath();
            string_list.append(absolute_file_path);
        }

    }
}
//bool JsonRead::FindFile(const QString & path)
//{
//    QDir dir(path);
//     if (!dir.exists())
//     return false;
//     dir.setFilter(QDir::Dirs|QDir::Files);
//     dir.setSorting(QDir::DirsFirst);
//     QFileInfoList list = dir.entryInfoList();
//     int i=0;
//      do{

//               QFileInfo fileInfo = list.at(i);
//               if(fileInfo.fileName()=="."|fileInfo.fileName()=="..")
//               {
//                       i++;
//                       continue;
//               }
//               bool bisDir=fileInfo.isDir();
//               if(bisDir)
//               {
//                   nFiles++;
//                   std::cout << qPrintable(QString("%1 %2 %3").arg(fileInfo.size(), 10)
//                                                           .arg(fileInfo.fileName(),10).arg(fileInfo.path()))<<endl;

//                     FindFile(fileInfo.filePath());
//               }
//               else
//               {
//                   nFiles++;
//                   std::cout << qPrintable(QString("%1 %2 %3").arg(fileInfo.size(), 10)
//                                                              .arg(fileInfo.fileName(),10)
//                                                              .arg(fileInfo.path()))<<endl;
//               }
//              i++;
//         }
//       while(i<list.size());
//      return true;
//}
