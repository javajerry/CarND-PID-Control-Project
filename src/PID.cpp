#include "PID.h"
#include <iostream>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {

	this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;
    p_error = 0.0;
    i_error = 0.0;
    d_error = 0.0;

    prev_cte = 0.0;
  
    iter = 1;
    index = 0; // 1-Kp, 2=Ki, 3=Kd
    steps = 1;
    eval_steps =1; // steps+eval_steps=2*N from the lesson
    dp = {1.0,1.0,1.0};
    tol = 0.01;
    err = 0;
    best_err = std::numeric_limits<double>::max(); // initialize to max double value
    wait_flag = false;
}

void PID::UpdateError(double cte) {

	if ( iter == 1) {
		prev_cte = cte;
	}

	double diff_cte = cte - prev_cte;
	p_error = cte;
	i_error += cte;
	d_error = diff_cte;

	prev_cte = cte;

	int eval_a = iter % steps;
	int eval_b = iter % (steps+eval_steps);

	if ( eval_b > steps) {
		err += cte * cte;
	}

	if ( (eval_a == 0) & ( iter > steps)) { // reset the error
		err = 0.0;
	}

/*	Twiddle attempt
	if ( eval_b == 0) {
		err = err/steps;

		cout << "set params of index " << index << endl;
		switch (index){
			case 0 : 
				Kp += dp[0];
				break;
			case 1 : 
				Kd += dp[1];
				break;
			case 2 : 
				Ki += dp[2];
				break;
		}

		double sum_dp = dp[0] + dp[1] + dp[2];

		cout << "best error: " << best_err << endl;
		if ( sum_dp > tol ) {

			if ( (err < best_err) & ! wait_flag ){
				best_err = err;
				dp[index] *= 1.1;
			}
			else {
				if ( ! wait_flag ){
					switch (index){
						case 0 : 
							Kp -= 2 * dp[0];
							break;
						case 1 : 
							Kd -= 2 * dp[1];
							break;
						case 2 : 
							Ki -= 2 * dp[2];
							break;
					}
					wait_flag = true;
				}
				else {
					if ( err < best_err ){
						best_err = err;
						dp[index] *= 1.1;
					}
					else {
						switch (index){
							case 0 : 
								Kp += dp[0];
								break;
							case 1 : 
								Kd += dp[1];
								break;
							case 2 : 
								Ki += dp[2];
								break;
						}
						dp[index] *= 0.9;
						wait_flag = false;		
					}
				}
			}
			index++;
		}

		if ( index == 3 )
		{
			index = 0; //reset back to Kp
		}
	}
*/
	cout <<  "iter: " << std::to_string(iter) << " Kp: " << Kp << " | Kd: " << Kd << " | Ki: " << Ki  << endl;

	iter++;
}

double PID::TotalError() {
	double totalErr = -Kp * p_error  -Kd * d_error -Ki * i_error;
	cout << "TotalError : " << totalErr << endl;
	return totalErr;
}

