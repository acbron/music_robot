/*
 *\file QRobotController.h
 *
 *\brief 定义QRobotController类
 *
 *这个类为机器人的控制类，定义了其基本操作的接口
 *
 *
 */

#ifndef QROBOTCONTROLLER_H
#define QROBOTCONTROLLER_H

#include <libusb-1.0/libusb.h>
#include <cstdio>

class QRobotController
{
private:
     //!单例模式所使用的实例
     static QRobotController * controller;
     
     //!机器人电源状态
     bool powerState;

     //!机器人控制usb设备的句柄
     struct libusb_device_handle * command_device_handle;

     int transferred;
public:
    //！使用单例模式，生成一个控制类的实例
    static QRobotController * getInstance()
   {
     if(controller==NULL)
         controller=new QRobotController();
     return controller;
   }
   
   //!重置机器人的动作
   bool reset();

   //!控制左边翅膀的运动,方向向上
   /*!
    *
    *\param speed 运动速度挡位（1.2.3）
    *\param time 运动时间(0-100) 单位20ms
    *
    */
   bool leftWingUp(int speed,int time);
   
   //!控制左边翅膀回到原点
   /*!
    *
    *\param speed 运动速度挡位（1，2，3）
    *
    */
   bool leftWingOrg(int speed);
   
   //!控制左边翅膀运动，方向向下
   /*!
    *
    *\param speed 运动速度挡位（1，2，3）
    *\param time 运动时间（0-100）单位为20ms
    *
    */
   bool leftWingDown(int speed,int time);
  
   //!控制右边边翅膀的运动,方向向上
   /*!
    *
    *\param speed 运动速度挡位（1.2.3）
    *\param time 运动时间(0-100) 单位20ms
    *
    */
   bool rightWingUp(int speed,int time);

   //!控制右边翅膀回到原点
   /*!
    *
    *\param speed 运动速度挡位（1，2，3）
    *
    */
   bool rightWingOrg(int speed);

   //!控制右边翅膀运动，方向向下
   /*!
    *
    *\param speed 运动速度挡位（1，2，3）
    *\param time 运动时间（0-100）单位为20ms
    *
    */
   bool rightWingDown(int speed,int time);

   //!控制左右边翅膀运动，方向向下
   /*!
    *
    *\param speed 运动速度挡位（1，2，3）
    *\param time 运动时间（0-100）单位为20ms
    *
    */
   bool lrWingDown(int speed,int time);

   //!控制头部水平运动
   /*!
    *
    *\param speed 运动速度挡位（1，2，3）
    *\param range 运动角度（0~100）相对于原点
    *
    */
   bool horizontalHead(int speed,int range);
  
   //!控制头部水平运动回到原点
   /*!
    *
    *\param speed 运动速度挡位（1，2，3）
    *
    */
   bool horizontalHeadOrg(int speed);
   
   //!控制头部垂直运动
   /*!
    *
    *\param speed 运动速度挡位（1，2，3）
    *\param range 运动角度（0~40）相对于原点
    *
    */
    bool verticalHead(int speed,int range);
    
   //!控制头部垂直运动回到原点
   /*!
    *
    *\param speed 运动速度挡位（1，2，3）
    *
    */
    bool verticalHeadOrg(int speed);
    
    //!设置胸部显示颜色
    /*!
     *
     *\param red RGB值（0-255）
     *\param green RGB值（0-255）
     *\param blue RGB值（0-255）
     *
     */
    bool setHeartColor(int red,int green,int blue);
    
    //!设置眼睛表情
    /*!
     *
     *\param time 表情循环的次数
     *\param face 表情的编号（1-255）
     *
     */
    bool setEyePic(int time,int face);
   
    //!设置机器人电源状态
    /*!
     *
     *\param state true/false
     *
     */
     void setPowerState(bool state)
     {
        powerState=state;
     }
     
     //!读取机器人的头部角度信息(上下)
     /*!
      *
      *\return 机器人的上下角度
      *
      */
     int getHeadVertical();
     
     //!读取机器人头部角度信息（左右）
     /*!
      *
      *\return 机器人的左右角度
      *
      */
      int getHeadHorizontal();
      
      //!获取机器人的触摸信息
      /*!
       *
       *\retval 0x01 头部按下
       *\retval 0x02 头部按下松开
       *\retval 0x12 头部长按
       *\retval 0x04 嘴巴按下
       *\retval 0x08 嘴巴按下松开
       *
       */
      int getTouchInfo();
      

private:
     //!构造函数，完成初始化
    QRobotController();

    //！析构函数
    /*!
     *
     *释放usb设备句柄等操作
     *
     */
     virtual ~QRobotController()
     {
        if(controller!=NULL)
           delete controller;
        libusb_close(command_device_handle);
        libusb_exit(NULL);
     }
    
    //!复制构造函数
    QRobotController(const QRobotController &){}
    
    //!重载运算符=
    QRobotController & operator =(const QRobotController &)
    {
      return *this;
    }
    
    //!生成一个基本的指令字节数组
    void generateBuffer(unsigned char buffer[])
    {
       buffer[0]=0xF7;
       buffer[1]=0xF7;
       buffer[2]=0x00;
       buffer[3]=0x14;
       buffer[4]=0x00;
       buffer[5]=0x0F;
       buffer[6]=0x0F;
       for(int i=7;i<25;i++)
           buffer[i]=0x00;
    }

    //!生成数据包校验码
    void generateAudit(unsigned char buffer[])
   {
       int tmp;
       sscanf("0x00","%X",&tmp);
       tmp=buffer[0]^buffer[1];
       for(int i=2;i<24;i++)
          tmp^=buffer[i];
       buffer[24]=tmp;
   }
};
#endif























