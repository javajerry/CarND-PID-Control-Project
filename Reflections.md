<H2> Describe the effect each of the P, I, D components had in your implementation. </H2>

P - Proportional control is used to help the car goto the set point where is almost zero. if car is on left side of set point, 
it will change steering angle to the right. Similarly change steering to left if car is on the right side of the set point.
If Kp is set high (>1.0), it caused car to oscillate faster, changing steering angle between -25 and +25 deg constantly. 
If Ki and Kd are set to zero, oscillation's amplitude grew as the car traveled more and throwing the car off the track. 
I even tried with too high Kp (10.0) and it caused car to throw off the track and flip in couple of seconds. If Kp is set low
(< 0.01) it increases the deadtime and car will eventually oscillate.

D - Derivative Control is used to counter balance the effect of Kp. It helps in reducing the amplitude of the oscillation 
and stabilizing the steering and bringing the car towards the set point.

I - Integral control. It helps with the offset if car traveling straight and gets displaced because of speed hump, curve, 
pot holes, etc.  I noticed that on the straight road value of Ki didnt make much difference, it even could be zero. 
It played significant role in "resetting the car back to center" especially while handling the curve, for e.g., sharp curves after the bridge. Even entering and exiting the 
bridge displaced the car, but Ki along with Kd helped in stabilizing the car.

This is an interesting project. Though coding was easy but tuing the 
