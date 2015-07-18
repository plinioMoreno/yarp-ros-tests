#include <iostream>
#include <yarp/os/all.h>

using namespace yarp::os;

int main(int argc, char *argv[]) {
  Network yarp;

  Port xd_inputPort;
  xd_inputPort.setReadOnly();
  bool outputOk = xd_inputPort.open("/my_xd_in@/ros_tests");
  Time::delay(2);
  Port xd_outputPort;
  bool outputOk_3 = xd_outputPort.open("/gaze_point");
  yarp.connect(xd_outputPort.getName(),"/iKinGazeCtrl/xd:i");

  int counter = 0;

  while(true){
    Bottle message_in = Bottle();
    if (xd_inputPort.read(message_in)){
	xd_outputPort.write(message_in);
    }
  }

  return 0;
}
