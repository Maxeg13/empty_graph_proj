#include "serialqobj.h"

serial_obj::serial_obj(QString qstr)
{

    std::string str1=qstr.toUtf8().constData();
    std::wstring str(str1.begin(),str1.end());

    hSerial.InitCOM(str.c_str());//was L"COM5"

}

void serial_obj::init(QString qstr)
{


    std::string str1=qstr.toUtf8().constData();;
    std::wstring str(str1.begin(),str1.end());

    hSerial.InitCOM(str.c_str());//was L"COM5"
    //    featureOut.resize(3);
}

void serial_obj::close()
{
    hSerial.close();
}
serial_obj::~serial_obj()
{};
void serial_obj::doWork()
{

    while(1)
    {

        bool readVarON;
        readVar=(int8_t)hSerial.ReadCOM(readVarON);
        if(readVarON)
            qDebug()<<(int8_t)readVar;
    }
}
