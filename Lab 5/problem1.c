#include <stdio.h>

//global variables
int numMonths = 12;
char *months[] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

//Gets the data from the input file
//                 input nums have decimals
void readData(double data[]) {
    char filename[256];

    printf("Enter the name of the input file: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
//  for each line
    for (int i = 0; i < numMonths; i++) {
        //will save to data array
        fscanf(file, "%lf", &data[i]);
    }

    fclose(file);
}

//Prints the monthly sales report
void salesReport(double data[]) {
    printf("Monthly sales report for 2022:\n");
    printf("Month    Sales\n");
    for (int i = 0; i < numMonths; i++) {
        //     prints the double sales num
        printf("%s $%.2lf\n", months[i], data[i]);
    }
}

//Prints the min, max, avg
void salesSummary(double data[]) {
    double minSales, maxSales, avgSales;
    minSales = data[0];
    maxSales = data[0];
    avgSales = 0.0;

    for (int i = 0; i < numMonths; i++) {
        //smallest num found
        if (data[i] < minSales) {
            minSales = data[i];
        }
        //highest num found
        if (data[i] > maxSales) {
            maxSales = data[i];
        }
        avgSales += data[i];
    }
// just total/12 = avg
    avgSales /= numMonths;

    printf("\nSales summary:\n");
    printf("Minimum sales: $%.2lf (January)\n", minSales);
    printf("Maximum sales: $%.2lf (December)\n", maxSales);
    printf("Average sales: $%.2lf\n", avgSales);

}


//Prints the six-month moving averages report
void sixMovingAverages(double data[]) {
    double movingAverages[numMonths - 5];
    //for the first 6 months
    for (int i = 0; i < numMonths - 5; i++) {
        double sum = 0.0;
        //will look thru the next 6 months (inclusive)
        for (int j = i; j < i + 6; j++) {
            sum += data[j];
        }
        movingAverages[i] = sum / 6;
    }
    //prints the avg report
    printf("\nSix-Month Moving Average Report:\n");
    for (int i = 0; i < numMonths - 5; i++) {
        printf("%s - %s $%.2lf\n", months[i], months[i + 5], movingAverages[i]);
    }
}

//prints the sorted report
void sortedSalesReport(double data[]) {

    for (int i = 0; i < numMonths; i++) {

        for (int j = 0; j < numMonths - i; j++) {
            //if the current data it's look in at is less than the next
            if (data[j] < data[j + 1]) {
                //store current to temp
                double temp = data[j];
                //current is the next
                data[j] = data[j + 1];
                //the next is the temp
                data[j + 1] = temp;

                //temp month is current month
                char *tempMonth = months[j];
                //current is next
                months[j] = months[j + 1];
                //next is temp
                months[j + 1] = tempMonth;
            }
        }
    }

    printf("\nSales Report (Highest to Lowest):\n");
    printf("Month    Sales\n");
    for (int i = 0; i < numMonths; i++) {
        printf("%s $%.2lf\n", months[i], data[i]);
    }
}

//runs everything
int main() {
    double data[numMonths];

    readData(data);
    salesReport(data);
    salesSummary(data);
    sixMovingAverages(data);
    sortedSalesReport(data);

    return 0;
}
