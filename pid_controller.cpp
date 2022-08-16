/**********************************************
 * Self-Driving Car Nano-degree - Udacity
 *  Created on: December 11, 2020
 *      Author: Mathilde Badoual
 **********************************************/

#include "pid_controller.h"
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kpi, double Kii, double Kdi, double output_lim_maxi, double output_lim_mini) {
   /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   **/
  
  //coefficients
   kp = Kpi;
   kd = Kdi;
   ki = Kii;
  
   //errors
   cte_prev = 0.0;
   cte_deriv = 0.0;
   cte_integ = 0.0;
   
   //limits
   limit_max = output_lim_maxi;
   limit_min = output_lim_mini;
  
}


void PID::UpdateError(double cte) {
   /**
   * TODO: Update PID errors based on cte.
   **/
  
   cte_prev = cte;
   cte_deriv = (cte - cte_prev) / dt;
   cte_integ += cte * dt;
}

double PID::TotalError() {
   /**
   * TODO: Calculate and return the total error
    * The code should return a value in the interval [output_lim_mini, output_lim_maxi]
   */

  	double control = kp*cte_prev + kd*cte_deriv + ki*cte_integ;
    control = max(min(control, limit_max), limit_min);

    return control;
}

double PID::UpdateDeltaTime(double new_delta_time) {
   /**
   * TODO: Update the delta time with new value
   */
  
  if (new_delta_time ==0){
    cout<<"Delta time value is 0, using default value of 1"<<endl;
   }
   dt = new_delta_time > 0 ? new_delta_time : 1;
  
  return dt;
}