#include "pro.h"
#include "ui_pro.h"
#include "pop.h"
#include "QFile"
#include "QFileDialog"
#include "QString"
#include "QDebug"
#include "QFileDevice"
#include "pcap.h"
#include <stdio.h>
#include "pacet.h"
#include "QStandardItemModel"

Packet::Packet()
{
    data=NULL;
    heders.caplen=0;
    heders.len=0;

    qDebug() << "Constructor started!";
}
Packet::~Packet()
{

    qDebug() << "DEConstructor started!";
}
Packet::Packet(const Packet &p)
{
  heders=p.heders;
  data=p.data;
}
bool Packet::operator< (const Packet &p)
{
    if(heders.len<p.heders.len)
    {
        return true;
    }
    return true;
}
bool Packet::operator> (const Packet &p)
{
    if(heders.len>p.heders.len)
    {
        return true;
    }
    return true;
}
void Packet::operator= (const Packet &p)
{
    heders=p.heders;
    data=p.data;
}

Pro::Pro(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Pro)
{
    ui->setupUi(this);
}

Pro::~Pro()
{
    delete ui;
}

void Pro::on_actionreturn_triggered()
{
    pop *op = new pop(this);
    op->show();
}

void Pro::on_actionfile_triggered()
{

}
FilePacets pacdata;
void Pro::on_pushButton_clicked()
{
    int t=0;
    const u_char *pkt_data;
    struct tm *ltime;
    char timestr[16];
    time_t local_tv_sec;
    struct pcap_pkthdr* header;
    char error[PCAP_ERRBUF_SIZE];
    QString fName = QFileDialog::getOpenFileName(0, "Open file","","PCAP files (*.cap)");
    QFile file(fName);
    if (!file.open(QIODevice::ReadOnly))
    {
            qDebug() << "error open file";
            return ;
    }
    qDebug() << fName;
    if ( fName == "" )
        return;
    const char *cName = fName.toStdString().c_str();
    pcap_t *GOD=pcap_open_offline(cName,error);
    int res;
    int tempbit=40;
    file.read((char *)&pacdata.filehd,24);
    while((res = pcap_next_ex(GOD, &header,&pkt_data)) >= 0)
    {
        Packet temp;
        QByteArray data1;
        pcaprec_hdr_s tempH;
        temp.getheders();
        if(res == 0)
            continue;
        t++;
        local_tv_sec = header->ts.tv_sec;
        ltime=localtime(&local_tv_sec);
        strftime( timestr, sizeof timestr, "%H:%M:%S", ltime);
        file.seek(tempbit);
        data1 = file.read(header->caplen);
        tempbit=tempbit+header->caplen+16;
        tempH.caplen=header->caplen;
        tempH.len=header->len;
        for(int i=0;i<16;i++)
        {
        tempH.st[i]=timestr[i];
        }
        temp.setHeders(tempH);
        temp.setData(data1);
        pacdata.packets.append(temp);
    }
    QStandardItem *item;
    QStandardItemModel *model = new QStandardItemModel(t,3,this);
    model->setHorizontalHeaderItem(0, new QStandardItem(QString("Length")));
    model->setHorizontalHeaderItem(1, new QStandardItem(QString("PacLength")));
    model->setHorizontalHeaderItem(2, new QStandardItem(QString("Time")));
    int rop=0,mid=0;
    for(int i=0;i<t;i++)
    {
        int *temp=pacdata.packets[i].getLen();
        item = new QStandardItem(QString::number(*temp));
        model->setItem(i, 0, item);
        temp=pacdata.packets[i].getCaplen();
        item = new QStandardItem(QString::number(*temp));
        model->setItem(i, 1, item);
        item = new QStandardItem(pacdata.packets[i].getTS());
        model->setItem(i, 2, item);

        if(rop<*temp)
            rop=*temp;
        mid=mid+*temp;
        }
    mid=mid/t;
    ui->tableView->setModel(model);
    ui->lineEdit_2->setText(QString::number(rop));
    ui->lineEdit->setText(QString::number(mid));
    ui->lineEdit_3->setText(QString::number(t));
    file.close();
    return;
    system("pause");
}
void Pro::on_pushButton_2_clicked()
{

}
