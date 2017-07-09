<H2> Describe the effect each of the P, I, D components had in your implementation. </H2>

P - Proportional control is used to help the car goto the set point where CTE ( cross track error) is almost zero. if car is on left side of set point, it will change steering angle to the right. Similarly change steering to the left if car is on the right side of the set point.If Kp is set high (>1.0), it caused car to oscillate faster, changing steering angle between -25 and +25 deg constantly. If Ki and Kd are set to zero, oscillation's amplitude grew as the car traveled more and throwing the car off the track. I even tried with too high Kp (10.0) and it caused car to throw off the track and flip in couple of seconds. If Kp is set low (< 0.01) it increases the deadtime and car will eventually oscillate.

D - Derivative Control is used to counter balance the effect of Kp. It helps in reducing the amplitude of the oscillation 
and stabilizing the steering and bringing the car towards the set point. I observed if I kept Kd low then it worked fine on the straight road but it couldnt handle the curves. If I kept it high, it worked for the curves but made car oscillate on the straight road.

I - Integral control. It helps with the offset if car traveling straight and gets displaced because of speed hump, curve, 
pot holes, etc.  I noticed that on the straight road value of Ki didnt make much difference, it even could be zero. 
It played significant role in "resetting the car back to center" especially while handling the curve, for e.g., sharp curves after the bridge. Even entering and exiting the bridge displaced the car, but Ki along with Kd helped in stabilizing the car. I had to keep low to have optimized effect on reducing CTE. I tried experiemnting with higher .01 or 0.1 or 1.0, it caused more oscillations.

<H2>Describe how the final hyperparameters were chosen</H2>
 Kp = 0.085
 Ki = 0.001
 Kd = 0.48


Well I started with writing Twiddle algorithm but failed to get it working. Doing 200 steps, just like the lesson, was too long and increase/decrease in speed was not helping. I got tips from the forum like resetting the terminal and implementing delta time, you can see my coding attempts in the commented parts, but that didn't help. I did lot of parallel research and watched few youtube video related to PID controller and got the good understanding. I wanted to implement PID for throttle also but dont know how to find equivalent of CTE for throttle. Terminal was returning speed and angle but not throttle. So I implemented my own version of throttle increase and decrease. If absolute value of CTE was more than 1 then decrease the throttle else keep on increasing. Here my thinking is based on real-life driving, nobody goes at high speed on the curves, It's better to deaccelerate at the curve. I had to limit to 0.4 throttle because my mac is old and if I tried to use 0.5, 0.6 or 0.7 throttle code and simulator were not responding fast enough to stablize the car. I even looked at alternate method for the tuning called Ziegler-Nichols but couldnt figure out how to calculate K-critical. I even tried manual twiddling using Excel but too many iteration and I gave up. Finally I switched to manual tuning and step increments. I used Twiddle algorithm in the coding section of the lesson to get my starting points. I increased speed to 30 and decreased tolerance to 0.0001. 
After that I started with Kp and i did increment or decrease in plus minus 0.1 till I observed the car was stable on the straight road but did worse on the curves. Then I played with Kd to handle the curves. Tires will going off the track but then I played with Ki to bring the car within the track. Still you will see some spots where car tires going off the track but overall car stayed within the track. Car did oscillate after the coming out of curves but stablized quickly.  

Note: <b>These hyperparameters values worked for my older and slower mac. Maynot work for faster CPU. CPU response time makes a big impact on the PID controller.</b> During my testing I see overall good result but when I added Quicktime screen recording it impacted my code-simulator interactions and made care totally unstable. I had to record the video using my Iphone. <br>
<b>Here's the <a href="https://www.youtube.com/watch?v=e4WfsMrqu00">Youtube link</a> to the video.</b>

Overall this is an interesting project. Though coding was easy but tuning/optimization was the hardest. 
Here's the link
