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

#include <hercules/hercules_node.h>


Hercules::Hercules(void)
{

}

Hercules::~Hercules(void)
{

}

/*******************************************************************************
* Main function
*******************************************************************************/
int main(int argc, char* argv[])
{
    ros::init(argc, argv, "hercules");
    ros::Time::init();
    ros::Rate rate(1);
    Hercules hcls;
    uint8_t i = 5;

    while (ros::ok())
    {
        if(i)
        {
            printf("[HERCULES II]:...%ds\r\n",i);
            i--;
            rate.sleep();
        }
        else
        {
            system("roslaunch hercules hercules_bringup.launch");
            exit(1);
        }
    }

    return 0;
}