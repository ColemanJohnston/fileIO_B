//Name: Coleman Johnston
//Date: 20 Oct. 2015
//Description: Programming Practice- File IO A
#include<iostream>//cout 
#include<fstream>//file IO
#include<string>//string processing
#include<iomanip>//setw();
using namespace std;



int main()
{
    ifstream fin; //declare input file stream
    ofstream fout;//declare output file stream
    fout.open("results.txt");//open output file stream    
    char fName[12];//file name specified by the user
    string firstName, lastName, bestName;//bestname is the name of the person with the highest average score
    double avgScore, score; 
    double highScore = 0;//highest average score
    
    //set up output formatting
    fout.setf(ios::fixed);
    fout.setf(ios::showpoint);
    fout.precision(1);
    fout.setf(ios::left);
    
    do
    {
        cout << "What is the name of the file that you\n"
         <<"want to read from?(example: scores.txt)\n";
        cin >> fName;
        fin.open(fName);//open input file stream with the name specified by the user
        if(fin.fail())
        {
            cout << "Sorry, the file you entered does not exist.\n";
        }
    }while(fin.fail());//ask again if the file stream fails to open
    
    while(fin >> firstName >> lastName)//take in the first and last name until file ends
    {       
        if((firstName + lastName) == "Highestscore:")//when you get to Highest score break the loop
        {
            break;
        }
        
        avgScore = 0;//set average score to 0 before starting the loop to take in and average the scores of a single person
        fout << setw(12) << firstName << setw(12) << lastName;//put first and last names before the scores
        for(int i = 0; i < 6; i++)//do six scores
        {
            if(i == 5)//change the precision on the last score to two digits past the decimal point
            {
                fout.precision(2);    
            }
            else
            {
                fout.precision(1);//change back for other scores
            }
            
            fin >> score;
            fout << setw(6) << score;
            avgScore += score;
        }
        avgScore = avgScore / 6;//take the average of six scores
        fout.precision(1);//show one digit past the decimal for the average.
        fout << setw(9) << "Average: " << avgScore << endl;      
        
        if(avgScore > highScore)//find and save the name of the person with the hightest average
        {
            
            highScore = avgScore;
            bestName = firstName + " " + lastName;           
        }  
    }
     
    fout << "\nHighest Average: " << bestName;  
    
    fin.close();//close input file stream
    fout.close();//close output file stream
    return 0;
}
