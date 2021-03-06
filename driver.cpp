//  Name: Daniel Calderon
//  Name: Angel Gonzalez
//  Name: Sandra Flores
//  Name: Miguel Fletes
//  Nov 1 ,2015
//  Mariela strength code

/* 
B.  The file that match most closely are standard deviation
C.  The number of zero crossings are the one that are most different
D.  Another measurement that i would recomend is get the wavelength
E.  The recordings from the two data files are not from the same person. This is due to the fact that the percentage difference  from  the zero crossings and magnitude are too great.
*/


#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

double avgMagnitude(ifstream& fin);
int zeroCross(ifstream& fin);
double mean(ifstream& fin);
double avgPower(ifstream& fin);
double var(ifstream& fin);
double stdDev(ifstream& fin);

int main()
{

    ifstream finA,finB;
    ofstream fout;
    finA.open("two_a.txt");
    finB.open("two_b.txt");
    fout.open("comparison.txt");
    double differenceMean ,differenceCross,differenceMagnitude,differencePower,differenceVar,differenceStd;
    
    differenceMean = (abs(mean(finA)-mean(finB))/ ((mean(finA)+mean(finB))/2)) * 100.0;
    differenceCross = (abs(zeroCross(finA)-zeroCross(finB))/ ((zeroCross(finA)+zeroCross(finB))/2)) * 100.0;
    differenceMagnitude = (abs(avgMagnitude(finA)-avgMagnitude(finB))/ ((avgMagnitude(finA)+avgMagnitude(finB))/2)) * 100.0;
    differencePower = (abs(avgPower(finA)-avgPower(finB))/ ((avgPower(finA)+avgPower(finB))/2)) * 100.0;
    differenceVar = (abs(var(finA)-var(finB))/ ((var(finA)+var(finB))/2)) * 100.0;
    differenceStd = (abs(stdDev(finA)-stdDev(finB))/ ((stdDev(finA)+stdDev(finB))/2)) * 100.0;
    cout.setf(ios::left);
    fout << setw(1) << "Team Members: Daniel Calderon,Miguel Fletes,Angel Gonzalez,Sandra Flores" << setw(5) << endl;
    fout << setw(30) << "two_a.txt" << setw(30) << "two_b.txt" << setw(30) << "%difference" << setw(10) << endl;
    fout << setw(1) << "Mean" << setw(27) << mean(finA) << setw(30) << mean(finB) << setw(25) << differenceMean << setw(10) << endl;
    fout << setw(1) << "Standard Deviation" << setw(11) << stdDev(finA) << setw(29) << stdDev(finB) << setw(28) << differenceStd << endl;
    fout << setw(1) << "Variance" << setw(21) << var(finA) << setw(30) << var(finB) << setw(27) <<differenceVar <<  setw(20) << endl;
    fout << setw(1) << "Average Power" << setw(16) << avgPower(finA) << setw(29) << avgPower(finB) <<setw(27) << differencePower << endl;
    fout << setw(1) << "Average Magnitude" << setw(12.5) <<avgMagnitude(finA) <<setw(30) << avgMagnitude(finB) <<setw(27) << differenceMagnitude << endl;
    fout << setw(1) << "Zerocross" << setw(15) << zeroCross(finA) << setw(29) << zeroCross(finB) << setw(33) << differenceCross << endl;
    
    finA.close();
    finB.close();
    fout.close();

return 0;
}
double stdDev(ifstream& fin)
{
    double ary[5000];
    int sizeAry = 0, ix = 0;; //need the size of the array :~
    double variance = var(fin);//need the variance
    double temp;
    string word;
    for(int i = 0; i < 1; i++) 
    {
        fin >> word;
    }
    while (fin >> temp)//eats values to find out the # of things
    {
        sizeAry++;
        ary[ix] = temp;
        ix++;
    }
    
    fin.clear();
    fin.seekg(0);  
    
    return sqrt(variance); //all stdDev does is return the square root of the variance divided by the number of values

}
//************************************************
double var(ifstream& fin)
{
   
    double ary[5000];
    int sizeAry = 0;
    double temp, sum = 0, average =0, variance=0;
    double squareSum = 0; //holds the square root sum of average - actual number in the array
    int ix = 0;
    
    while (fin >> temp)
    {
        sizeAry++;
        ary[ix] = temp;
        ix++;
    }
    for(int i = 0; i < sizeAry ; i++)
    {
        sum += ary[i];
    }
    average = sum/sizeAry;
    for(int i = 0; i < sizeAry ; i++)
    {
        squareSum += (ary[i] - average) * (ary[i] - average);
    }
    variance = squareSum/sizeAry;
    
    fin.clear();
    fin.seekg(0);  
    
    return variance; 
}
//************************************************
double avgPower(ifstream& fin)
{
    double ary[5000];
    int sizeAry = 0;
    double val,sum = 0;
    int ix =0;
    while(fin >> val)
    {
        sizeAry++;
        ary[ix] = val;
        ix++;
    }
    for(int i = 0; i < sizeAry ; i++)
    {
        sum = sum + pow(ary[i],2);
    }
fin.clear();
fin.seekg(0);   
return sum/sizeAry ;
}
//************************************************
double mean(ifstream& fin)
{
    double ary[5000];
    int sizeAry = 0;
    double val,sum = 0;
    int ix =0;
    while(fin >> val)
    {
        sizeAry++;
        ary[ix] = val;
        ix++;
    }
    for(int i = 0; i < sizeAry ; i++)
    {
        sum = sum + ary[i];
    }
    fin.clear();
    fin.seekg(0);
    return sum/sizeAry;
    
}
//************************************************
double avgMagnitude(ifstream& fin)
{
    double ary[5000];
    int sizeAry = 0;
    double val,sum = 0;
    int ix =0;
    while(fin >> val)
    {
        sizeAry++;
        ary[ix] = val;
        ix++;
    }
    for(int i = 0; i < sizeAry ; i++)
    {
        sum = sum + fabs(ary[i]);
    }
fin.clear();
fin.seekg(0);   
return sum/sizeAry ;
}
//***************************************************
int zeroCross(ifstream& fin)
{
    double ary[5000];
    int sizeAry = 0;
    int count = 0;
    int ix=0;
    double val;
    while(fin >> val)
    {
        sizeAry++;
        ary[ix] = val;
        ix++;
    }
    
    for(int i = 0; i < sizeAry; i++)
    {
        if(i > 0)
        {
        
            if( ary[i-1] > 0 && ary[i] < 0 )
            {
                count++;
            }
            else if( ary[i-1] < 0 && ary[i] > 0)
            {
                count ++;
            }
        }
    }
    fin.clear();
    fin.seekg(0);
    return count;
}

