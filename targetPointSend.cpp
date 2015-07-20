#include <iostream>
#include <yarp/os/all.h>
#include <geometry_msgs_Point.h>

using namespace yarp::os;

int main(int argc, char *argv[]) {
  Network yarp;

  BufferedPort<geometry_msgs_Point> xd_inputPort;
  xd_inputPort.setReadOnly();
  bool outputOk = xd_inputPort.open("/my_xd_in@/ros_tests");
  BufferedPort<geometry_msgs_Point> xd_outputPort;
  bool outputOk_3 = xd_outputPort.open("/gaze_point");


 if(!outputOk_3)
  {
    printf("outputOk_3 failed to open\n");
    return -1;
  }

  bool connectSuccess = false;
  while(!connectSuccess)
  {
    printf("\nTrying to connect to /iKinGazeCtrl/xd:i ... ");
    connectSuccess = yarp.connect(xd_outputPort.getName(),"/iKinGazeCtrl/xd:i");
    yarp::os::Time::delay(1);
  }

  while(true){
    geometry_msgs_Point *reading1Mux1;
    reading1Mux1 = xd_inputPort.read();
    geometry_msgs_Point & out = xd_outputPort.prepare();
    out = *reading1Mux1;
    xd_outputPort.write();
  }
  return 0;
}
