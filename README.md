# Control and Trajectory Tracking for Autonomous Vehicles
Udacity Self Driving nanodegree: Project 4 on Control Trajectory and Tracking

## Proportional-Integral-Derivative
Given a trajectory as an array of locations, and a simulation environment, you will design and code a PID controller to perform vehicle trajectory tracking and test its efficiency on the CARLA simulator used in the industry.

## Implementation in CARLA simulator
Implemented the PID controls for steering the vehicle in proportion to the Cross Track Error, using derivatives to reduce the overshoots and the integral to compensate the CTE.
![Image1](https://github.com/Shruti-Bansal/Control_Trajectory_Tracking/blob/main/images/project4_img1.png)

### PID Controller for throttle
The last point of the vector v_points was used to calculate the velocity error. After some experimenting and fine tuning, the PID coefficients were set to:
kp = 0.2, ki = 0.001, kd = 0.3 and output limited to [-1, 1] 

### PID Controller for steering
The error between the actual steer and the desired steer was calculated and the coefficients for the PID controller were tuned. The final values were as below:
kp = 0.35, ki = 0.0012, kd = 0.9 and output limited to [-1.2, 1.2]

The car gave a decent performance in CARLA, here are some snaphots:
![Image2](https://github.com/Shruti-Bansal/Control_Trajectory_Tracking/blob/main/images/img2_pr4.png)
![Image3](https://github.com/Shruti-Bansal/Control_Trajectory_Tracking/blob/main/images/img3_pr4.png)
![Image4](https://github.com/Shruti-Bansal/Control_Trajectory_Tracking/blob/main/images/img4_pr4.png)

## Performance Plots
Evaluate the PID efficiency
![Image5](https://github.com/Shruti-Bansal/Control_Trajectory_Tracking/blob/main/images/plot1_proj_v2.png)
![Image6](https://github.com/Shruti-Bansal/Control_Trajectory_Tracking/blob/main/images/plot2_project_v2.png)

We see that the car oscillates a fair amount in its movement. Increase in the kp values increases the oscillations further, however, increasing the kd value controls the oscillations and ki helps bring the car back to the center of the lane more quickly. However, if ki is increased further, the car is unable to avoid obstacles efficiently and crashes.
If the kp value is decreased, the car crashes with the first obstacle and is unable to respond properly. The graphs indicate that the car steers much more than it should based on the steering angle calculations and the error is higher for a high steer angle.
Twiddle method can be used to automatically tune the PID parameters.
PID is a model free controller which makes it easier to implement. We don’t need much information of the control system model itself. On the other hand, the difficult part is tuning the parameters which needs a lot of effort and time. 



