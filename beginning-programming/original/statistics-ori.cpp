#include <cstdio>
#include <cmath>

float mean(float data[], int n){
  float sum = 0.0; float mean_value;
  for (int x=0; x<n; x++){
    sum = sum + data[x];
  }
  mean_value = sum/(float)n;
  printf("Mean Value = %3.2f", mean_value);
  return mean_value;
}

float variance(float data[], int n, float mean_value){
  float sum = 0.0; float vrnc;
  for (int x=0; x<n; x++){
    sum = sum + (data[x]-mean_value)*(data[x]-mean_value);
  }
  vrnc = sum/(n-1);
  printf("Variance = %3.2f", vrnc);
  return vrnc;
}

float skewness(float data[], int n, float mean_value, float variance){
  float sum = 0.0; float screw;
  for (int x=0; x<n; x++){
    sum = sum + (data[x]-mean_value)*(data[x]-mean_value)*(data[x]-mean_value);
  }
  screw = sum/((n-1)*sqrt(variance*variance*variance));
  printf("Skewness = %3.2f", screw);
  return screw;
}

int main(void)
{
static float data[100]; char in_file[100], out_file[100];
int i; int j; float mean_pressure; float variance_pressure; float skewness_pressure;
char units[100];
// This section is used to import the text file
FILE *inputfile, *outfile;
printf("Enter input file name\n");
scanf("%s", in_file);
printf("Enter output file name\n");
scanf("%s", out_file);
inputfile = fopen (in_file, "r");
// This section is used to load how many data points
printf("Enter the number of data points in %s\n ",in_file);
scanf("%i", &i);
printf("Enter the Unit of the Data Points: ");
scanf("%s", &units);
printf("The Data Imported from the Text File: \n");
for(j=0; j<i; j++) 
  // This part is intended to list all of the data from the text file {
{
fscanf (inputfile, "%f", &data[j]);
printf("%3.2f %s \n", data[j], units);
}
// This part is intended to display the mean, variance, and skewness value
mean_pressure = mean(data,i);
printf(" %s \n", units);
variance_pressure = variance(data,i,mean_pressure);
printf(" %s^2 \n", units);
skewness_pressure = skewness(data,i,mean_pressure,variance_pressure);
printf("\n");
// This part is used to create a txt file which contains all info printed in the output
window
outfile=fopen(out_file,"w");
fprintf(outfile, "Mean Value = %3.2f %s \n", mean_pressure, units);
fprintf(outfile, "Variance Value = %3.2f %s^2 \n", variance_pressure, units);
fprintf(outfile, "Skewness Value = %3.2f \n", skewness_pressure);
return 0;
}



