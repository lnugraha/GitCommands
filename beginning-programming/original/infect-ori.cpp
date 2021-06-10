#include<stdio.h>
#include<stdlib.h>
float alpha=0.005, beta=1; // The rate of infection of recovery
float susceptible=5000, infected=1, recovered=0; // Three types of populations

// Here are the compartmental modeling functions
float slope_s(float, float, float); // Calculate dS/dt
float slope_i(float, float, float); // Calculate dI/dt
float slope_r(float, float); // Calculate dR/dt

int main(void){
  float t0=0.00, tf, t_counter; float s_pops, i_pops, r_pops;
  float k1, k2, k3, k4, q1, q2, q3, q4, p1, p2, p3, p4;
  float N;
  float h = 0.05; // The step size is already determined
  char sim_file[100];
  FILE *out_file;
  float *out_time, *susceptible_initial, *infected_initial, *recovered_initial;
  printf("Enter the final time for solution: "); 
  // Enter the amount of time elapsed
  scanf("%f", &tf);
  printf("Enter the output of the text file: "); 
  // Save the input file
  scanf("%s", sim_file);
  N = (tf-t0)/h; // Calculate the step size
  out_file = fopen(sim_file,"w");

  // DMA Part
  susceptible_initial = (float *) calloc(sizeof(float),N);
  infected_initial = (float *) calloc(sizeof(float),N);
  recovered_initial = (float *) calloc(sizeof(float),N);
  out_time = (float *) calloc(sizeof(float),N);

  // Set the initial values
  susceptible_initial[0] = susceptible;
  infected_initial[0] = infected;
  recovered_initial[0] = recovered;
  out_time[0] = 0;
 
  fprintf(out_file,"Time [week] \t Susceptible \t Infected \t Recovered \n");
 
  fprintf(out_file, "%.4f \t \t %.0f \t \t %.0f \t \t %.0f \n", out_time[0],
 susceptible_initial[0], infected_initial[0], recovered_initial[0]);
 
  // Here is the 4th Order Runge-Kutta Calculations
  for(int counter = 0; counter < N; counter++)
  {
    out_time[counter+1] = (counter+1)*h;
    k1 = h*slope_s(out_time[counter], susceptible_initial[counter], infected_initial[counter]);
    q1 = h*slope_i(out_time[counter], susceptible_initial[counter], infected_initial[counter]);
    p1 = h*slope_r(out_time[counter], infected_initial[counter]);
 
    k2 = h*slope_s(out_time[counter]+h/2, susceptible_initial[counter]+(k1)/2, infected_initial[counter]+(q1)/2);
    q2 = h*slope_i(out_time[counter]+h/2, susceptible_initial[counter]+(k1)/2, infected_initial[counter]+(q1)/2);
    p2 = h*slope_r(out_time[counter]+h/2, infected_initial[counter]+(q1)/2);
 
    k3 = h*slope_s(out_time[counter]+h/2, susceptible_initial[counter]+(k2)/2, infected_initial[counter]+(q2)/2);
    q3 = h*slope_i(out_time[counter]+h/2, susceptible_initial[counter]+(k2)/2, infected_initial[counter]+(q2)/2);
    p3 = h*slope_r(out_time[counter]+h/2, infected_initial[counter]+(q2)/2);
 
    k4 = h*slope_s(out_time[counter]+h/2, susceptible_initial[counter]+(k3)/2, infected_initial[counter]+(q3)/2);
    q4 = h*slope_i(out_time[counter]+h/2, susceptible_initial[counter]+(k3)/2, infected_initial[counter]+(q3)/2);
    p4 = h*slope_r(out_time[counter]+h/2, infected_initial[counter]+(q3)/2);
 
    susceptible_initial[counter+1] = susceptible_initial[counter] +
 (1.0/6.0)*(k1+2*k2+2*k3+k4);
 
    infected_initial[counter+1] = infected_initial[counter] + (1.0/6.0)*(q1+2*q2+2*q3+q4);
 
    recovered_initial[counter+1] = recovered_initial[counter] + (1.0/6.0)*(p1+2*p2+2*p3+p4);
 
    fprintf(out_file, "%.4f \t \t %.0f \t \t %.0f \t \t %.0f \n", 
    out_time[counter+1], susceptible_initial[counter+1], 
    infected_initial[counter+1], recovered_initial[counter+1]);
  } 
}

// All of the Three Coherent Functions
// Determine the rate of the susceptible population
float slope_s(float t, float suscept, float infect)
{
  float rate_s;
  rate_s = -0.005*suscept*infect;
  return rate_s;
}
 
// Determine the rate of the infected people
float slope_i(float t, float suscept, float infect)
{
  float rate_i;
  rate_i = 0.005*suscept*infect-1*infect;
  return rate_i;
}

// Dteermine the rate of the recovered people
float slope_r(float t, float infect)
{
  float rate_r;
  rate_r = 1*infect;
  return rate_r;
}

