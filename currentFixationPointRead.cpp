#include <iostream>
#include <yarp/os/all.h>

using namespace yarp::os;

int main(int argc, char *argv[]) {
  Network yarp;

  Port receiverBuff1Mux1;
  bool receiver1Mux1Ok = receiverBuff1Mux1.open("/my_other_port_in");
  Port outputPort;
  outputPort.setWriteOnly();
  bool outputOk_1 = outputPort.open("/my_x_out@/ros_tests");
  
  Time::delay(5);
  yarp.connect("/iKinGazeCtrl/x:o", receiverBuff1Mux1.getName());

  while(true){
    Bottle reading1Mux1 = Bottle();
    receiverBuff1Mux1.read(reading1Mux1);
    Bottle mux1;

    outputPort.write(reading1Mux1);
  }
  return 0;
}
