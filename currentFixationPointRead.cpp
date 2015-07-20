#include <iostream>
#include <yarp/os/all.h>
#include <geometry_msgs_Point.h>

using namespace yarp::os;

int main(int argc, char *argv[]) {
  Network yarp;

  BufferedPort<geometry_msgs_Point>  receiverBuff1Mux1;
  bool receiver1Mux1Ok = receiverBuff1Mux1.open("/my_other_port_in");
  BufferedPort<geometry_msgs_Point> outputPort;
  outputPort.setWriteOnly();
  bool outputOk_1 = outputPort.open("/my_x_out@/ros_tests");
  
  if(!outputOk_1)
  {
    printf("outputOk_1 failed to open\n");
    return -1;
  }

  bool connectSuccess = false;
  while(!connectSuccess)
  {
    printf("\nTrying to connect to /iKinGazeCtrl/x:o ... ");
    connectSuccess = yarp.connect("/iKinGazeCtrl/x:o", receiverBuff1Mux1.getName());
    yarp::os::Time::delay(1);
  }

  printf("Connection done!\n");

  while(true)
  {
    geometry_msgs_Point *reading1Mux1;
    reading1Mux1 = receiverBuff1Mux1.read();

    geometry_msgs_Point & out = outputPort.prepare();
    out = *reading1Mux1;
    outputPort.write();
 }
return 0;
}
