/*******************************************************************************
* Copyright 2017 CLNST CO., LTD.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

#include <hercules_teleop/hercules_teleop_node.h>


void HerculesTeleop::teleop_cb(const sensor_msgs::JoyConstPtr& joy)
{
    teleop.linear.x = joy->axes[1]*linear_scale;
    teleop.angular.z = joy->axes[0]*angular_scale;

    if(joy->buttons[4])
    {
        linear_scale += 0.1;
    }

    if(joy->buttons[5])
    {
        linear_scale -= 0.1;
    }
}

HerculesTeleop::HerculesTeleop(void)
{
    //Init node
    ROS_ASSERT(init());
}

HerculesTeleop::~HerculesTeleop(void)
{
}

bool HerculesTeleop::init(void)
{
    ros::param::get("~pub_topic", pub_topic);
    ros::param::get("~sub_topic", sub_topic);
    ros::param::get("~linear_scale", linear_scale);
    ros::param::get("~angular_scale", angular_scale);
    ros::param::get("~test_mode", test_mode);

    teleop_pub = nh.advertise<geometry_msgs::Twist>(pub_topic, 100);
    if(!test_mode)
    {
        joy_sub = nh.subscribe(sub_topic, 100, &HerculesTeleop::teleop_cb, this);
    }

    return true;
}

bool HerculesTeleop::update(void)
{
    if(test_mode)
    {
        teleop.linear.x = 1;
        teleop.angular.z = 1;
    }
    teleop_pub.publish(teleop);

    return true;
}

/*******************************************************************************
* Main function
*******************************************************************************/
int main(int argc, char* argv[])
{
    ros::init(argc, argv, "hercules_teleop");
    HerculesTeleop teleop;
    ros::Rate rate(20);

    while (ros::ok())
    {
        teleop.update();
        ros::spinOnce();
        rate.sleep();
    }

    return 0;
}