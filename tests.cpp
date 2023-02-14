// tests.cpp
//
//  Google Tests Framework has not been working on MAC
//  All tests are used by a Boolean functions
//  
//  Copyright © 2022 Mark Cirineo. All rights reserved.
// System: MacOSX, Visual Studio 
//
// Credits: Shannon Reckinger -PHD University of Illinois Chicago 
// and Adam T Koehler -PHD University of Illinois Chicago for myrandom.h 
// software

#include "mymap.h" 
#include "myrandom.h"   


//  
//Test 1: Empty Map 
//
bool emptyMap() {  
    cout << "TEST 1: EMPTY MAP TEST" << endl;

    mymap<int, int> map1; 

    int expectedSize = 0;  
    int actualSize = map1.Size();

    cout << "Expected Size: " << expectedSize << endl; 

    cout << "Actual Size: " << map1.Size() << endl; 

    if(actualSize != expectedSize) { 
        cout << "Empty Map Test Failed!" << endl; 
        return false;
    } 

    else { 
        cout << "Empty Map Test Succeeded!" << endl;
    } 

    return true;  

    cout << "\n";
    cout << "\n";

}  
//Test 2: Map Size 
bool mapAddition() {  
    cout << "TEST 2: MAP OF INT, INT" << endl;
    mymap<int, int> map1; 

    for(int i = 0; i < 5; i++) {  

        map1.put(i,i);

    }  

    int expectedSize = 5;  
    int actualSize = map1.Size();

    cout << "Expected Size: " << expectedSize << endl; 

    cout << "Actual Size: " << map1.Size() << endl; 

    if(actualSize != expectedSize) { 
        cout << "Addition Map Test Failed!" << endl; 
        return false;
    } 

    else { 
        cout << "Addition Map Test Succeeded!" << endl;
    } 

    return true;  

    cout << "\n";
    cout << "\n";

     
}   
//Test 3: Map Size 
bool mapAddition2() {  
        cout << "TEST 3: MAP OF INT, INT 2" << endl;

    
     

    mymap<int, int> map;
    int n = 10;
    int arr[] = {30, 15, 50, 8, 25, 70, 20, 28, 40, 60};
    
    for (int i = 0; i < n; i++) {
        map.put(arr[i], arr[i]);
    }


    int expectedSize = 10;  
    int actualSize = map.Size();

    cout << "Expected Size: " << expectedSize << endl; 

    cout << "Actual Size: " << map.Size() << endl; 

    if(actualSize != expectedSize) { 
        cout << "Addition Map Test 2 Failed!" << endl; 
        return false;
    } 

    else { 
        cout << "Addition Map Test 2 Succeeded!" << endl;
    } 

    return true;  

    cout << "\n";
    cout << "\n";

     
}   


//Test 4: Map of Key Int and Value String

bool mapOfIntString() { 
        cout << "TEST 4: MAP OF INT, STRING" << endl;


    mymap<int, string> map1;  

    int expectKey = 1; 
    string expectedValue = "Mark";

    map1.put(expectKey, "Mark");  


    cout << "Expected Key: "<< expectKey << " and Value: " << map1.get(1) << endl; 

    cout << "Actual: " << expectKey <<" "<< map1.get(1) << endl;  

    if(expectedValue != map1.get(1)) { 
        cout << "mapOfIntString Test Failed" << endl;
        return false;
    }
    cout << "mapOfIntString Test Succeeded!" << endl;
    return true;
} 

//Test 5: Map of Key Int and Value Char
bool mapOfIntChar() { 
        cout << "TEST 5: MAP OF INT, CHAR" << endl;


    mymap<int, char> map1;  

    int expectKey = 1; 
    char expectedValue = 'm';

    map1.put(expectKey, 'm');  


    cout << "Expected Key: "<< expectKey << " and Value: " << map1.get(1) << endl; 

    cout << "Actual: " << map1.toString() << endl;  

    if( map1.get(expectKey) != expectedValue) { 
        cout << "mapOfIntChar Test Failed" << endl;
        return false;
    }
    cout << "mapOfIntChar Test Succeeded!" << endl;
    return true;
}  
//Test 6: Map of Key String and Value String
bool mapOfStringString() { 
        cout << "TEST 6: MAP OF STRING, STRING" << endl;


    mymap<string, string> map1;  

    string expectKey = "1"; 
    string expectedValue = "m";

    map1.put(expectKey, "m");  


    cout << "Expected Key: "<< expectKey << " and Value: " << map1.get(expectKey) << endl; 

    cout << "Actual: " << map1.toString() << endl;  

    if(map1.get(expectKey) != expectedValue) { 
        cout << "mapOfStringString Test Failed" << endl;
        return false;
    }
    cout << "mapOfStringString Test Succeeded!" << endl;
    return true;
} 
//Test 7: Map of Key Char and Value Char 
bool mapOfCharChar() {  
        cout << "TEST 7: MAP OF CHAR, CHAR" << endl;

    

    mymap<char, char> map1;  

    char expectKey = 'A'; 
    char expectedValue = 'A';

    map1.put(expectKey, 'A');  


    cout << "Expected Key: "<< expectKey << " and Value: " << map1.get(expectKey) << endl; 

    cout << "Actual: " << map1.toString() << endl;  

    if(map1.get(expectKey) != expectedValue) { 
        cout << "mapOfCharChar Test Failed" << endl;
        return false;
    }
    cout << "mapOfCharChar Test Succeeded!" << endl;
    return true;
}  

//Test 8: Map of Double Key and Double Value 
bool mapOfDoubleDouble() { 
        cout << "TEST 8: MAP OF DOUBLE, DOUBLE" << endl;


    mymap<double, double> map1;  

    double expectKey = 12.13; 
    double expectedValue = 96.3;

    map1.put(expectKey, 96.3);  


    cout << "Expected Key: "<< expectKey << " and Value: " << map1.get(expectKey) << endl; 

    cout << "Actual: " << map1.toString() << endl;  

    if(expectKey != expectKey && map1.get(expectKey) != expectedValue) { 
        cout << "mapOfDoubleDouble Test Failed" << endl;
        return false;
    }
    cout << "mapOfDoubleDouble Test Succeeded!" << endl;
    return true;
}  
//Test 9: toString() Test
bool toStringTest() { 
        cout << "TEST 9: toString Test" << endl;

    mymap<int, string> map1; 

    map1.put(1, "Josh Allen");
    map1.put(2, "Tom Brady");
    map1.put(3, "Justin Fields");
    map1.put(4, "Kirk Cousins"); 

    cout << map1.toString() << endl; 

    cout << "key: 1 value: Josh Allen \nkey: 2 value: Tom Brady \nkey: 3 value: Justin Fields \nkey: 4 value: Kirk Cousins\n";

    if(map1.toString() != map1.toString())
    { 
        cout << "toStringTest() Failed!" << endl; 
        return false; 
    } 

    cout << "toStringTest() Succeded!" << endl; 
    return true;
} 

//Test 10: contains(keyType key)   
bool containsTest(){  
    cout << "TEST 10: containsTest 1" << endl;

mymap<int,int> map1; 

map1.put(0,1);  

cout << "Expected result: " << 1 << endl; 
cout << "Actual result: " << map1.contains(0) << endl;

if(map1.contains(0) != 1) { 
    cout << "containsTest 1 Failed!" << endl; 
    return false; 
} 

cout << "containsTest 1 succeded!" << endl; 
return true; 

}
//Test 11: contains(keyType key)   
bool containsTest2(){  
cout << "TEST 11: containsTest 2" << endl;

mymap<string, int> map1; 

map1.put("Sean",1);  

cout << "Expected result: " << 1 << endl; 
cout << "Actual result: " << map1.contains("Sean") << endl;

if(map1.contains("Sean") != 1) { 
    cout << "containsTest 2 Failed!" << endl; 
    return false; 
} 

cout << "containsTest 2 succeded!" << endl; 
return true; 

}
//Test 12: contains(keyType key)   
bool containsTest3(){  
    cout << "TEST 12: containsTest 3" << endl;

mymap<double,int> map1; 

map1.put(12.1,1);  

cout << "Expected result: " << 1 << endl; 
cout << "Actual result: " << map1.contains(12.1) << endl;

if(map1.contains(12.1) != 1) { 
    cout << "containsTest 3 Failed!" << endl; 
    return false; 
} 

cout << "containsTest 3 succeded!" << endl; 
return true; 

}
//Test 13: contains(keyType key)   
bool containsTest4(){  
cout << "TEST 13: containsTest 4" << endl;

mymap<char,int> map1; 

map1.put('A',1);  

cout << "Expected result: " << 1 << endl; 
cout << "Actual result: " << map1.contains('A') << endl;

if(map1.contains('A') != 1) { 
    cout << "containsTest 4 Failed!" << endl; 
    return false; 
} 

cout << "containsTest 4 succeded!" << endl; 
return true; 

}
//Test 14: contains(keyType key)   
bool containsTest5(){  
cout << "TEST 14: containsTest 5" << endl;

mymap<int,int> map1; 

map1.put(122,1);  

cout << "Expected result: " << 1 << endl; 
cout << "Actual result: " << map1.contains(122) << endl;

if(map1.contains(122) != 1) { 
    cout << "containsTest 5 Failed!" << endl; 
    return false; 
} 

cout << "containsTest 5 succeded!" << endl; 
return true; 

}
//Test 15: contains(keyType key)   
bool containsTest6_PURPOSEFAIL(){ 
cout << "TEST 15: containsTest 6 (Meant to Fail) " << endl;
 
mymap<int,int> map1; 

map1.put(1,1);  

cout << "Expected result: " << 0 << endl; 
cout << "Actual result: " << map1.contains(0) << endl;

if(map1.contains(0) != 1) { 
    cout << "containsTest6 Succeded!" << endl; 
    return false; 
} 

cout << "containsTest6 Failed!" << endl; 
return true; 

}
  



// Test 16: get(keyType key)  
bool valueGrab1() { 
    cout << "TEST 16: valueGrab 1" << endl;

    mymap<int , int> map1;  

    int expectedValue = 2;

    map1.put(12,2); 

    cout << "Expected Value: " << 2 << endl;
    cout << "Actual Value: " << map1.get(12) << endl; 

    if(expectedValue != map1.get(12)) { 
        cout << "valueGrab Test 1 Failed!" << endl; 
        return false; 
    } 

    cout << "valueGrab Test 1 Succeded!" << endl; 
    return true; 
}
// Test 17: get(keyType key)  
bool valueGrab2() { 
     cout << "TEST 17: valueGrab 2" << endl;


    mymap<int , string> map1;  

    string expectedValue = "Tom Brady";

    map1.put(12,"Tom Brady"); 

    cout << "Expected Value: " << "Tom Brady" << endl;
    cout << "Actual Value: " << map1.get(12) << endl; 

    if(expectedValue != map1.get(12)) { 
        cout << "valueGrab Test 2 Failed!" << endl; 
        return false; 
    } 

    cout << "valueGrab Test 2 Succeded!" << endl; 
    return true; 
}
// Test 18: get(keyType key)  
bool valueGrab3() { 
    cout << "TEST 18: valueGrab 3" << endl;

    mymap<int , double> map1;  

    double expectedValue = 22.2;

    map1.put(122,22.2); 

    cout << "Expected Value: " << 22.2 << endl;
    cout << "Actual Value: " << map1.get(122) << endl; 

    if(expectedValue != map1.get(122)) { 
        cout << "valueGrab Test 3 Failed!" << endl; 
        return false; 
    } 

    cout << "valueGrab Test 3 Succeded!" << endl; 
    return true; 
}
// Test 19: get(keyType key)  
bool valueGrab4() { 
     cout << "TEST 19: valueGrab 4" << endl;
 
    mymap<int , char> map1;  

    char expectedValue = 'X';

    map1.put(32,'X'); 

    cout << "Expected Value: " << 'X' << endl;
    cout << "Actual Value: " << map1.get(32) << endl; 

    if(expectedValue != map1.get(32)) { 
        cout << "valueGrab Test 4 Failed!" << endl; 
        return false; 
    } 

    cout << "valueGrab Test 4 Succeded!" << endl; 
    return true; 
}
// Test 20: get(keyType key)  
bool valueGrab5_FAIL() {
     cout << "TEST 16: valueGrab 5" << endl;
 
    mymap<int , string> map1;  

    string expectedValue = "Himothy";

    map1.put(12,"Tom"); 

    cout << "Expected Value: " << 2 << endl;
    cout << "Actual Value: " << map1.get(12) << endl; 

    if(expectedValue != map1.get(12)) { 
        cout << "valueGrab Test 5 Failed!" << endl; 
        return false; 
    } 

    cout << "valueGrab Test 5 Succeded!" << endl; 
    return true; 
}


//Test 21: operator  
bool operator1() { 
     cout << "TEST 21: operator 1" << endl;
 
    mymap<int, int> map; 
    int arr[] = {1,2,3};
    for (int i = 0; i < 3; i++) { 
        map.put(arr[i], arr[i]);
    }  

    int expectedValue = 3; 
    int actualValue = map[3];

    cout << "Expected Value: " << 3 << endl;
    cout << "Actual Value: " << map[3] << endl;  

    if(expectedValue != actualValue) { 
        cout << "Operator1 Test Failed!" << endl; 
        return false;
    } 

    cout << "Operator1 Test Succeeded!" << endl; 
    return true;




}
//Test 22: operator  
bool operator2() {
     cout << "TEST 22: operator 2" << endl;  
    mymap<int, int> map; 
    int arr[] = {3,2,1}; 

    for (int i = 0; i < 3; i++) { 
        map.put(arr[i], arr[i]);
    }  

    int expectedValue = 1; 
    int actualValue = map[1];

    cout << "Expected Value: " << 1 << endl;
    cout << "Actual Value: " << actualValue << endl;  

    if(expectedValue != actualValue) { 
        cout << "Operator 2 Test Failed!" << endl; 
        return false;
    } 

    cout << "Operator 2 Test Succeeded!" << endl; 
    return true;




}
//Test 23: operator  
bool operator3() {
     cout << "TEST 23: operator 3" << endl;  
    mymap<int, int> map; 
    int arr[] = {1,2,3,4,5,6};
    for (int i = 0; i < 6; i++) { 
        map.put(arr[i], arr[i]);
    }  

    int expectedValue = 6; 
    int actualValue = map[6];

    cout << "Expected Value: " << expectedValue << endl;
    cout << "Actual Value: " << actualValue << endl;  

    if(expectedValue != actualValue) { 
        cout << "Operator 3 Test Failed!" << endl; 
        return false;
    } 

    cout << "Operator 3 Test Succeeded!" << endl; 
    return true;




}
//Test 24: operator  
bool operator4() {  
     cout << "TEST 24: operator 4" << endl;
    mymap<int, int> map; 
    int arr[] = {100,200,300};
    for (int i = 0; i < 3; i++) { 
        map.put(arr[i], arr[i]);
    }  

    int expectedValue = 200; 
    int actualValue = map[200];

    cout << "Expected Value: " << expectedValue << endl;
    cout << "Actual Value: " << actualValue << endl;  

    if(expectedValue != actualValue) { 
        cout << "Operator 4 Test Failed!" << endl; 
        return false;
    } 

    cout << "Operator 4 Test Succeeded!" << endl; 
    return true;




}
//Test 25: operator  
bool operator5() { 
     cout << "TEST 25: operator 5" << endl; 
    mymap<int, int> map; 
    int arr[] = {1000,2000,3000};
    for (int i = 0; i < 3; i++) { 
        map.put(arr[i], arr[i]);
    }  

    int expectedValue = 3000; 
    int actualValue = map[1000];

    cout << "Expected Value: " << expectedValue << endl;
    cout << "Actual Value: " << actualValue << endl;  

    if(expectedValue != actualValue) { 
        cout << "Operator 5 Test Failed!" << endl; 
        return false;
    } 

    cout << "Operator 5 Test Succeeded!" << endl; 
    return true;




}


//Test 26: Size  
bool sizeTest() { 
    cout << "TEST 26: SIZE 1" << endl; 

    mymap<int, int> map;  
    int size = 0;  
    int n = 10000;
    int key = randomInteger(0, n); 
    int value = randomInteger(0, n);
    for(int i = 0; i < size; i++){ 
        map.put(key, value);
    } 

    cout << "Expected Map Size: " << size << endl; 
    cout << "Actual Map Size: " << map.Size() << endl;

    if(size != map.Size()) { 
        cout << "sizeTest1 Failed!" << endl; 
        return false;
    } 

    cout << "sizeTest1 Succeeded!" << endl; 
    return true;
}
//Test 27: Size  
bool sizeTest2(){
    cout << "TEST 27: SIZE 2" << endl; 
 
    mymap<int, int> map; 
    mymap<int, int> map2;  

    int size = 20;  
    
    
    for(int i = 0; i < size; i++){ 
        int key = randomInteger(0, 10000); 
        int value = randomInteger(0, 10000);
        map.put(key, value);
    }  

    map2 = map;

     cout << "Expected Map Size: " << map.Size() << endl; 
    cout << "Actual Map Size: " << map2.Size() << endl;

    if(map2.Size() != map.Size()) { 
        cout << "sizeTest2 Failed!" << endl; 
        return false;
    } 

    cout << "sizeTest2 Succeeded!" << endl; 
    return true;


}
//Test 28: Size  
bool sizeTest3(){ 
    cout << "TEST 28: SIZE 3" << endl; 

    mymap<double, double> map; 
    mymap<double, double> map2;  

    int size = 20;  
    
    
    for(int i = 0; i < size; i++){ 
        double key = randomInteger(0, 10000); 
        double value = randomInteger(0, 10000);
        map.put(key, value);
    }  

    map2 = map;

     cout << "Expected Map Size: " << map.Size() << endl; 
    cout << "Actual Map Size: " << map2.Size() << endl;

    if(map2.Size() != map.Size()) { 
        cout << "sizeTest3 Failed!" << endl; 
        return false;
    } 

    cout << "sizeTest3 Succeeded!" << endl; 
    return true;


}
//Test 29: Size  
bool sizeTest4(){
    cout << "TEST 29: SIZE 4" << endl; 
 
    mymap<int, int> map; 
    mymap<int, int> map2;  

    int size = 20;  
    
    
    for(int i = 0; i < size; i++){ 
        int key = randomInteger(0, 100); 
        int value = randomInteger(0, 100);
        map.put(value, key);
    }  

    map2 = map;

     cout << "Expected Map Size: " << map.Size() << endl; 
    cout << "Actual Map Size: " << map2.Size() << endl;

    if(map2.Size() != map.Size()) { 
        cout << "sizeTest2 Failed!" << endl; 
        return false;
    } 

    cout << "sizeTest2 Succeeded!" << endl; 
    return true;


}
//Test 30: Size  
bool sizeTest5(){ 
    cout << "TEST 30: SIZE 5" << endl; 

    mymap<int, int> map; 
    mymap<int, int> map2;  

    int size = 20;  
    
    
    for(int i = 0; i < size; i++){ 
        int key = randomInteger(0, 10000); 
        int value = randomInteger(0, 10000);
        map.put(key, value);
    }  

    map2 = map;

     cout << "Expected Map Size: " << map.Size() << endl; 
    cout << "Actual Map Size: " << map2.Size() << endl;

    if(map2.Size() != map.Size()) { 
        cout << "sizeTest5 Failed!" << endl; 
        return false;
    } 

    cout << "sizeTest5 Succeeded!" << endl; 
    return true;


}







//Test 31: toVector  
bool toVectorTest1() {  
    cout << "TEST 31: toVector Test 1" << endl;
    mymap<int, int> map;  
    int size = 0;  
    int key = randomInteger(0, 100); 
    int value = randomInteger(0, 100); 

    vector<pair<int,int>> solution;
    for(int i = 0; i < size; i++){ 
        map.put(key, value);  
        solution.emplace_back(key, value);
        
    } 

    

    
    if(map.toVector() != solution) { 
        cout << "toVector Test Failed!" << endl; 
        return false;
    } 

    cout << "toVectorTest 1 Succeeded!" << endl; 
    return true;
}
//Test 32: toVector  
bool toVectorTest2() {
    cout << "TEST 32: toVector Test 2" << endl;
 
    mymap<int, int> map;  
    int size = 0;  
    int key = randomInteger(0, 100); 
    int value = randomInteger(0, 100); 

    vector<pair<int,int>> solution;
    for(int i = 0; i < size; i++){ 
        map.put(key, value);  
        solution.emplace_back(key, value);
        
    } 

    

    
    if(map.toVector() != solution) { 
        cout << "toVector Test Failed!" << endl; 
        return false;
    } 

    cout << "toVectorTest 2 Succeeded!" << endl; 
    return true;
}
//Test 33: toVector  
bool toVectorTest3() {
    cout << "TEST 33: toVector Test 3" << endl;

    mymap<int, int> map;  
    int size = 0;  
    
    int key = randomInteger(0, 5); 
    int value = randomInteger(0, 5); 

    vector<pair<int,int>> solution;
    for(int i = 0; i < size; i++){ 
        map.put(key, value);  
        solution.emplace_back(key, value);
        
    } 

    if(map.toVector() != solution) { 
        cout << "toVector Test 3 Failed!" << endl; 
        return false;
    } 

    cout << "toVectorTest 3 Succeeded!" << endl; 
    return true;
}
//Test 34: toVector  
bool toVectorTest4() { 
    cout << "TEST 34: toVector Test 4" << endl;

    mymap<int, int> map;  
    int size = 0;  
    int key = randomInteger(0, 10000); 
    int value = randomInteger(0, 10000); 

    vector<pair<int,int>> solution;
    for(int i = 0; i < size; i++){ 
        map.put(key, value);  
        solution.emplace_back(key, value);
        
    } 

    

    
    if(map.toVector() != solution) { 
        cout << "toVector Test 4 Failed!" << endl; 
        return false;
    } 

    cout << "toVectorTest 4 Succeeded!" << endl; 
    return true;
}
//Test 35: toVector  
bool toVectorTest5() {
    cout << "TEST 35: toVector Test 5" << endl;
 
    mymap<int, int> map;  
    int size = 0;  
    int key = randomInteger(0, 1000); 
    int value = randomInteger(0, 1000); 

    vector<pair<int,int>> solution;
    for(int i = 0; i < size; i++){ 
        map.put(key, value);  
        solution.emplace_back(key, value);
        
    } 

    

    
    if(map.toVector() != solution) { 
        cout << "toVector Test 5 Failed!" << endl; 
        return false;
    } 

    cout << "toVectorTest5 Succeeded!" << endl; 
    return true;
}

// Test 36: checkBalance   
bool checkBalanceTest1(){
    cout << "TEST 36: checkBalance Test 1" << endl;
 
    mymap<int, int> map; 
    mymap<int, int> map2;  

    int size = 20;  
    
    
    for(int i = 0; i < size; i++){ 
        int key = randomInteger(0, 10000); 
        int value = randomInteger(0, 10000);
        map.put(key, value);
    }  

    map2 = map;

     cout << "Expected Map Balance: " << map.checkBalance() << endl; 
    cout << "Actual Map Balance: " << map2.checkBalance() << endl;

    if(map2.checkBalance() != map.checkBalance()) { 
        cout << "sizeTest5 Failed!" << endl; 
        return false;
    } 

    cout << "checkBalance Test 1 Succeeded!" << endl; 
    return true;


}

// Test 37: clear() 
bool clearTest() { 
     cout << "TEST 37: CLEAR" << endl; 

    mymap<int, int> map; 
    mymap<int, int> map2;  

    int size = 20;  
    
    
    for(int i = 0; i < size; i++){ 
        int key = randomInteger(0, 10000); 
        int value = randomInteger(0, 10000);
        map.put(key, value);
    }  

    map2 = map;

    map2.clear(); 
    map.clear();

     cout << "Expected Map Size: " << map.Size() << endl; 
    cout << "Actual Map Size: " << map2.Size() << endl;

    if(map2.Size() != map.Size()) { 
        cout << "clearTest Failed!" << endl; 
        return false;
    } 

    cout << "clearTest Succeeded!" << endl; 
    return true;

}


// TO DO: write lots of tests here.
int main() {  

  

   emptyMap();  //Test 1
   cout << "\n"; 
   cout << "\n";
   mapAddition();  //Test 2
   cout << "\n";
   cout << "\n";
   mapAddition2();  //Test 3
   cout << "\n";
   cout << "\n";

   mapOfIntString();  //Test 4

   cout << "\n";
   cout << "\n"; 

   mapOfIntChar();  // Test 5
   cout << "\n";
   cout << "\n"; 

   mapOfStringString();  //Test 6
   cout << "\n";
   cout << "\n"; 

   mapOfCharChar();  //Test 7
   cout << "\n";
   cout << "\n"; 

   mapOfDoubleDouble(); //Test 8 
   cout << "\n";
   cout << "\n"; 

   toStringTest(); //Test 9
    cout << "\n";
   cout << "\n"; 

   containsTest(); //Test 10 

   containsTest2(); //Test 11  
   cout << "\n";
   cout << "\n"; 
   containsTest3(); //Test 12 
   cout << "\n";
   cout << "\n";  
   containsTest4(); //Test 13  
   cout << "\n";
   cout << "\n"; 
   containsTest5(); //Test 14 
   cout << "\n";
   cout << "\n";  
   containsTest6_PURPOSEFAIL(); //Test 15  
   cout << "\n";
   cout << "\n";   

   valueGrab1(); //Test 16
   cout << "\n";
   cout << "\n";   

   valueGrab2(); //Test 17
   cout << "\n";
   cout << "\n";   

   valueGrab3(); //Test 18
   cout << "\n";
   cout << "\n";   

   valueGrab4(); //Test 19
   cout << "\n";
   cout << "\n";   

   valueGrab5_FAIL(); //Test 20 
   cout << "\n";
   cout << "\n";  

   operator1(); //Test 21
   cout << "\n";
   cout << "\n";  

   operator2(); //Test 22
   cout << "\n";
   cout << "\n";  

   operator3(); //Test 23
   cout << "\n";
   cout << "\n";  

   operator4(); //Test 24
   cout << "\n";
   cout << "\n";  

   operator5(); //Test 25 
   cout << "\n";
   cout << "\n";  

   sizeTest(); //Test 26 
   cout << "\n";
   cout << "\n";  

   sizeTest2(); //Test 27 
   cout << "\n";
   cout << "\n";  

   sizeTest3(); //Test 28
   cout << "\n";
   cout << "\n";   

   sizeTest4(); //Test 29 
   cout << "\n";
   cout << "\n";  

   sizeTest5(); //Test 30 

   cout << "\n";
   cout << "\n";   

   toVectorTest1(); //Test 31 
   cout << "\n";
   cout << "\n";   
   toVectorTest2(); //Test 32 
   cout << "\n";
   cout << "\n";   
   toVectorTest3(); //Test 33
   cout << "\n";
   cout << "\n";   
   toVectorTest4(); //Test 34 
   cout << "\n";
   cout << "\n";   
   toVectorTest5(); //Test 35  
   cout << "\n";
   cout << "\n";   
   checkBalanceTest1(); //Test 36 
   
   cout << "\n";
   cout << "\n";   
   clearTest(); //Test 37 

return 0; 

}