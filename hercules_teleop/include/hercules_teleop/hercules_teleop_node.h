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

#ifndef __HERCULES_TELEOP_H__
#define __HERCULES_TELEOP_H__

#include <ros/ros.h>
#include <ros/time.h>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/Joy.h>

#define _BETOP      0
#define JOY_TYPE    _BETOP

class HerculesTeleop{
public:
    HerculesTeleop(void);
    ~HerculesTeleop(void);

    bool init(void);
    bool update(void);

private:
    ros::NodeHandle nh;
    ros::Publisher teleop_pub;
    ros::Subscriber joy_sub;

    std::string pub_topic;
    std::string sub_topic;
    float linear_scale;
    float angular_scale;
    bool test_mode;

    geometry_msgs::Twist teleop;

    void teleop_cb(const sensor_msgs::JoyConstPtr& joy);

};


#endif // __HERCULES_TELEOP_H__