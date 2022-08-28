//Developed to learn about apriori algorithm
//Resource: https://www.geeksforgeeks.org/apriori-algorithm/
#include <iostream>
#include <string>

using namespace std;

string t1[] = {"i1", "i2", "i5"};
string t2[] = {"i2", "i4"};
string t3[] = {"i2", "i3"};
string t4[] = {"i1", "i2", "i4"};
string t5[] = {"i1", "i3"};

float counter[5] = {0};
float counterPairs[6] = {0};
int support = 2;
int confidence = 60;
float finalConfidence[4] = {0};

//Step 1
//Count all items
void countItems(string name[], int size){
    for(int i = 0; i < size; i++){
        if (name[i] == "i1")
            counter[0]++;
        else if (name[i] == "i2")
            counter[1]++;
        else if (name[i] == "i3")
            counter[2]++;
        else if (name[i] == "i4")
            counter[3]++;
        else if (name[i] == "i5")
            counter[4]++;
    }
}

//Step 1.5
//Check if items are less than support
void supportCheck(){
    if (counter[0] < support){
        counter[0] = 0;
    }
    if (counter[1] < support){
        counter[1] = 0;
    }
    if (counter[2] < support){
        counter[2] = 0;
    }
    if (counter[3] < support){
        counter[3] = 0;
    }
    if (counter[4] < support){
        counter[4] = 0;
    }
}

//Step 2
//Count pairs of items
void countPairs(string name[], int size){
    bool i1Exist = false;
    bool i2Exist = false;
    bool i3Exist = false;
    bool i4Exist = false;
    bool i5Exist = false;

    for(int i = 0; i < size; i++){
        if (name[i] == "i1")
            i1Exist = true;
        else if (name[i] == "i2")
            i2Exist = true;
        else if (name[i] == "i3")
            i3Exist = true;
        else if (name[i] == "i4")
            i4Exist = true;
        else if (name[i] == "i5")
            i5Exist = true;
    }

    //true
    if (i1Exist == true && i2Exist == true)
        counterPairs[0]++;
    if (i1Exist == true && i3Exist == true)
        counterPairs[1]++;
    if (i1Exist == true && i4Exist == true)
        counterPairs[2]++;
    if (i2Exist == true && i3Exist == true)
        counterPairs[3]++;
    //true
    if (i2Exist == true && i4Exist == true)
        counterPairs[4]++;
    if (i3Exist == true && i4Exist == true)
        counterPairs[5]++;

    i1Exist = false;
    i2Exist = false;
    i3Exist = false;
    i4Exist = false;
    i5Exist = false;
}

//Step 2.5
//Check if pairs are less than support
void supportCheckPairs(){
    if (counterPairs[0] < support){
        counterPairs[0] = 0;
    }
    if (counterPairs[1] < support){
        counterPairs[1] = 0;
    }
    if (counterPairs[2] < support){
        counterPairs[2] = 0;
    }
    if (counterPairs[3] < support){
        counterPairs[3] = 0;
    }
    if (counterPairs[4] < support){
        counterPairs[4] = 0;
    }
    if (counterPairs[5] < support){
        counterPairs[5] = 0;
    }
}

//Step 3
//Find the highest confidence
//Formula: Whole support set / if set
void confidenceHigh(){
    // (i1,i2)(whole set)(counterPairs[0])
    // i1(if set) => i2
    // i2(if set) => i1
    finalConfidence[0] = (counterPairs[0] / counter[0])*100;
    finalConfidence[1] = (counterPairs[0] / counter[1])*100;

    // (i2,i4)(whole set)(counterPairs[4])
    // i2(if set) => i4
    // i4(if set) => i2
    finalConfidence[2] = (counterPairs[4] / counter[1])*100;
    finalConfidence[3] = (counterPairs[4] / counter[3])*100;
}

//Display all the data
void displayList(){
    cout << "-----------------------------------" << endl;
    cout << "Step 0: List the data" << endl;
    cout << "We will be using Apriori Algorithm to find the association for frequent pattern mining" << endl;
    cout << "This is a sample code that is hardcoded in most areas." << endl;
    cout << "Reference: https://www.geeksforgeeks.org/apriori-algorithm/" << endl;
    cout << "-----------------------------------" << endl;

    cout << "T1: ";
    for(int i = 0; i < 3; i++){
        cout << t1[i] << " ";
    }
    cout << endl;

    cout << "T2: ";
    for(int i = 0; i < 2; i++){
        cout << t2[i] << " ";
    }
    cout << endl;

    cout << "T3: ";
    for(int i = 0; i < 2; i++){
        cout << t3[i] << " ";
    }
    cout << endl;

    cout << "T4: ";
    for(int i = 0; i < 3; i++){
        cout << t4[i] << " ";
    }
    cout << endl;

    cout << "T5: ";
    for(int i = 0; i < 2; i++){
        cout << t5[i] << " ";
    }
    cout << endl;

    cout << "-----------------------------------" << endl;
}

void displayItems(){

    cout << "Step 1: Count each item" << endl;
    cout << "-----------------------------------" << endl;
    cout << "We ignore any value below the support" << endl;
    cout << "Support: " << support << endl;
    cout << "Before Support Checks" << endl;
    cout << "Count all the items" << endl << endl;
    for(int i=0;i < 5; i++){
        cout << "i" << i+1 << ": " << counter[i] << endl;
    }

    cout << endl;
    supportCheck();

    cout << "After Support Checks" << endl << endl;
    for(int i=0;i < 5; i++){
        cout << "i" << i+1 << ": " << counter[i];
        if(counter[i] < support){
            cout << " (Ignore any value below support)";
        }
        cout << endl;
    }
    cout << "-----------------------------------" << endl;
}

void displayPairs(){

    cout << "Step 2: Count the pairs" << endl;
    cout << "-----------------------------------" << endl;
    cout << "We combine the remaining items into pairs(kinda like sets)" << endl;
    cout << "Support: " << support << endl;
    cout << "Before Support Checks" << endl;
    cout << "Count all the pairs of items" << endl;
    cout << "(Ignore i5 since it's below support)" << endl << endl;
    
    for(int i = 2; i <= 4; i++){
        cout << "i1" << " & " << "i" << i << ": " << counterPairs[i-2] << endl;
    }
    for(int i = 3; i <= 4; i++){
        cout << "i2" << " & " << "i" << i << ": " << counterPairs[i] << endl;
    }
    for(int i = 4; i <= 4; i++){
        cout << "i3" << " & " << "i" << i << ": " << counterPairs[i+1] << endl;
    }
    

    cout << endl;
    supportCheckPairs();

    cout << "After Support Checks" << endl << endl;
    for(int i = 2; i <= 4; i++){
        cout << "i1" << " & " << "i" << i << ": " << counterPairs[i-2];
        if(counterPairs[i-2] < support){
            cout << " (Ignore any value below support)";
        }
        cout << endl;
    }
    for(int i = 3; i <= 4; i++){
        cout << "i2" << " & " << "i" << i << ": " << counterPairs[i];
        if(counterPairs[i] < support){
            cout << " (Ignore any value below support)";
        }
        cout << endl;
    }
    for(int i = 4; i <= 4; i++){
        cout << "i3" << " & " << "i" << i << ": " << counterPairs[i+1];
        if(counterPairs[i+1] < support){
            cout << " (Ignore any value below support)";
        }
        cout << endl;
    }
    cout << "-----------------------------------" << endl;
}

void displayConfidence(){

    cout << "Step 3: Confidence" << endl;
    cout << "-----------------------------------" << endl;
    cout << "If we combine from the last step, i1 & i2 & i4." << endl;
    cout << "There is only 1 occurence which is less than support, so we ignore." << endl << endl;
    cout << "To find the confidence, each case must be calculated" << endl;
    cout << "Ensure the final confidence is greater than minimum confidence " << confidence << "%" << endl;
    cout << "Formula = (whole set/if set) * 100" << endl << endl;

    confidenceHigh();

    cout << "For i1 & i2(whole set = 2): " << endl;
    cout << "Case 1: i1(if set=3) => i2(i1 causes i2)" << endl;
    cout << "Case 2: i2(if set=4) => i1(i2 causes i1)" << endl << endl;
    
    cout << "For i2 & i4(whole set = 2): " << endl;
    cout << "Case 3: i2(if set=4) => i4(i2 causes i4)" << endl;
    cout << "Case 4: i4(if set=2) => i2(i4 causes i2)" << endl << endl;

    cout << "The math for all cases:" << endl;
    cout << "Case 1: " << "2/3 * 100 = " << finalConfidence[0] << "%" << " (greater than minimum confidence)" << endl;
    cout << "Case 2: " << "2/4 * 100 = " << finalConfidence[1] << "%" << endl;
    cout << "Case 3: " << "2/4 * 100 = " << finalConfidence[2] << "%" << endl;
    cout << "Case 4: " << "2/2 * 100 = " << finalConfidence[3] << "%" << " (greater than minimum confidence)" << endl << endl;

    cout << "Thus, case 1(i1 => i2) and case 4(i4 => i2) are the strongest association!" << endl;
    cout << "Note: The support and confidence can be set to any value(not just 2 and 60)" << endl;

    cout << "-----------------------------------" << endl;
}

int main(){
    displayList();

    countItems(t1, 3);
    countItems(t2, 2);
    countItems(t3, 2);
    countItems(t4, 3);
    countItems(t5, 2);

    displayItems();

    countPairs(t1, 3);
    countPairs(t2, 2);
    countPairs(t3, 2);
    countPairs(t4, 3);
    countPairs(t5, 2);

    displayPairs();

    displayConfidence();
    
}