#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

//finds slope of line
string findSlope(double x1, double y1, double x2, double y2);
//finds midpoint of line
string midpointFormula(double x1, double y1, double x2, double y2);
//finds distance between 2 points on a line
string distanceB2P(double x1, double y1, double x2, double y2);
//finds hypotenuse of right triangle
string pythTheorem(double a, double b);
//solves quadratic function using quadratic formula
string quadraticFormula(double a, double b, double c);
//calculates total principle + interest, compounded m times at rate of r for t time
string compoundInterest(double p, double r, double m, double t);

int main(){
    //menu for main screen
    string menu[] = {"Quit", "Find the slope of a line", "Find the midpoint of a line", "Find the distance between 2 points of a line",
    "Find the hypotenuse of a right triangle", "Solve a quadratic function using the quadratic formula", "Calculate amount of money compounded for n periods"};
    //prompts for index respective operation (when menu[1] is accessed it prompts list[1])
    string list[] = {" ", "enter the values of x1, y1, x2, and y2", "enter x1, y1, x2, and y2", "enter x1, y1, x2, and y2",
    "enter the value for sides a and b", "enter the coefficients of x^2, x, and the constant that is in standard form",
    "enter the principle, interest rate, number of periods compounded in a year, and how many years"};
    //array to store answers from functions
    string answer[6] = { "Error" };

    //termination flag
    bool end=false;
    //while haven't quit
    while (!end) {
        //index placeholder for both arrays
        int key=0;
        //input variables
        double x1=0,x2=0,y1=0,y2=0,a=0,b=0,c=0,m=0,r=0,p=0,t=0;

        cout << "What would you like to do?" << endl << endl;
        //menu loop
        for (int i=0; i < 7;i++){
            cout << i << ". " << menu[i] << endl;
        }
        cout << endl << "Choice: ", cin >> key;
        //check if quit
        if (key !=  0){
            //prompt for input for selection
            cout << "Separating with spaces, " << list[key] << ": " << endl;
            //handle each selection
            switch (key){ //extracting input to send to functions
                case 1: cin >> x1 >> y1 >> x2 >> y2;
                        answer[key] = findSlope(x1, y1, x2, y2);
                        break;
                case 2: cin >> x1 >> y1 >> x2 >> y2;
                        answer[key] = midpointFormula(x1, y1, x2, y2);
                        break;
                case 3: cin >> x1 >> y1 >> x2 >> y2;
                        answer[key] = distanceB2P(x1, y1, x2, y2);
                        break;
                case 4: cin >> a >> b;
                        answer[key] = pythTheorem(a,b);
                        break;
                case 5: cin >> a >> b >> c;
                        answer[key] = quadraticFormula(a, b, c);
                        break;
                case 6: cin >> p >> r >> m >> t;
                        answer[key] = compoundInterest(p, r, m, t);
                        break;
                default:end = true;  //quits if input not in range
                        break;
            };
            //ensures user hasn't quit, then prints answers
            if (end != true){
                //system("cls");     //optional screen clear
                cout << "The answer is: " << answer[key] << endl;
                cout << endl << "Proceeding to main menu" << endl << endl;
            }
        }
     else end = true; //quits per selection
    }
system("pause");
return 0;
}

string findSlope(double x1, double y1, double x2, double y2){
    //variable to round double and store as string
    stringstream mstream;
    double m=0;
    //calculate rise and run
    x2 -= x1;
    y2 -= y1;
    //if straight vertical line
    if (x2 == 0)
        return "The slope is undefined";
    //if straight horizontal line
    else if (y2 == 0)
        return "There is no slope";
    else {  //calculate slope
        m = (y2 / x2);
        //if whole number
        if (fmod(m,1) == 0)
            //drop the decimals and convert to string
            return to_string(static_cast<int>(m));
        else{  //otherwise round to 4 decimal places and convert to string
            mstream << setprecision(4) << m;
            return ("m = " + mstream.str());
        }
    }
//if somehow this fails
return "error";
}

string midpointFormula(double x1, double y1, double x2, double y2){
    //rounding and string variables
    stringstream xstream, ystream;
    //calculate midpoint of x and to string
    double m = ((x1 + x2) / 2);
    xstream << setprecision(2) << m;
    //midpoint for y and to string
    m = ((y1 + y2) / 2);
    ystream << setprecision(2) << m;
    return ("(" + xstream.str() + ", " + ystream.str() + ")");;
}


string distanceB2P(double x1, double y1, double x2, double y2){
    //round and cast variables
    stringstream mstream;
    //compute distance between 2 points
    double c = sqrt(pow((x2 - x1),2) + pow((y2 - y1),2));
    //round and to string
    mstream << setprecision(4) << c;
    return mstream.str();
}

string pythTheorem(double a, double b){
    stringstream mstream;
    //calculates hypotenuse
    double c = sqrt(((a * a) + (b * b)));
    //round to 4 decimal places
    mstream << setprecision(4) << c;
    return mstream.str();
}

string quadraticFormula(double a, double b, double c){
    //string variable to round doubles
    stringstream rtNeg, rtPos;
    //operating variables
    double div=0, neg=0, pos=0, det=0;
    //compute discriminant
    det = (pow(b,2) - (4 * a * c));
    //calculate divisor
    div = (2 * a);
    //-b
    b *= -1;
    //if discriminant leads to 2 real solutions
    if (det > 0){
        //calculate negative and positive
        neg = ((b - sqrt(det)) / div);
        pos = ((b + sqrt(det)) / div);
        //round and convert doubles to strings
        rtNeg << setprecision(4) << neg;
        rtPos << setprecision(4) << pos;
        //return solution
        return (rtNeg.str() + " or " + rtPos.str());
    }
    //if discriminant leaves 1 real solution
    else if (det == 0){
            //calculate and convert double to string
            rtPos << setprecision(4) << (b / div);
            return rtPos.str();
    }
    //discriminant leads to 2 imaginary solutions
    else {
        //string variable to assign and return
        string out;
        //get square root of discriminant
        pos = sqrt(abs(det));
        //if square root is not whole number
        if (fmod(pos,1) != 0){
           //collect strings then output
           out = (to_string(static_cast<int>(b)) + " + or - " + "sqrt(" + to_string(static_cast<int>(det)) + ") / " + to_string(static_cast<int>(div)) + "\n Unable to simplify");
           return out;
        }
        else {  //square of discriminant is whole number
           //if b and the square of discriminant are divisible, simplify
           if (fmod(pos,div) == 0 && fmod(b,div) == 0) {
                pos /= div;
                b /= div;
                //return simplified answer
                out = (to_string(static_cast<int>(b)) + " + or - " + to_string(static_cast<int>(pos)) + "i");
                return out;
           }
           else { //can't simplify so return equation with divisor
                out = (to_string(static_cast<int>(b)) + " + or - " + to_string(static_cast<int>(pos)) + "i) / " + to_string(static_cast<int>(div)));
                return out;
           }
        }
    }
return "error";
}

string compoundInterest(double p, double r, double m, double t){
    //string variable for rounding
    stringstream mstream;
    //convert rate to decimal
    r /= 100;
    //compute i for the equation
    double i = (r / m);
    //uses formula to solve
    double n = ((pow((1 + i), (m * t)) * p));
    //round to string
    mstream <<  fixed << setprecision(2) << n;
    return mstream.str();
}
