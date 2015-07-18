#include <iostream>
#include <yarp/os/all.h>

using namespace yarp::os;

int main(int argc, char *argv[]) {
  Network yarp;

  Port xd_inputPort;
  xd_inputPort.setReadOnly();
  bool outputOk = xd_inputPort.open("/my_xd_in@/ros_tests");
  Port receiverBuff1Mux1;
  bool receiver1Mux1Ok = receiverBuff1Mux1.open("/my_other_port_in");
  Port outputPort;
  outputPort.setWriteOnly();
  bool outputOk_1 = outputPort.open("/my_x_out@/ros_tests");
  Port xd_outputPort;
  bool outputOk_3 = xd_outputPort.open("/gaze_point");
  Time::delay(5);
  yarp.connect("/iKinGazeCtrl/x:o", receiverBuff1Mux1.getName());
  yarp.connect(xd_outputPort.getName(),"/iKinGazeCtrl/xd:i");
  while(true){
    Bottle message_in = Bottle();
    if (xd_inputPort.read(message_in)){
	xd_outputPort.write(message_in);
    }
    Bottle reading1Mux1 = Bottle();
    receiverBuff1Mux1.read(reading1Mux1);
    Bottle mux1;
    outputPort.write(reading1Mux1);
  }

  return 0;
}
